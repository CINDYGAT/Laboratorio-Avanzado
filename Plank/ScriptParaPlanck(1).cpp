#include <iostream>
#include <fstream>
#include <string>

#include "TROOT.h"
#include "TCanvas.h"
#include "TProfile.h"
#include "TF1.h"

/// source /home/mynorjrv/Downloads/Distros_and_apps/root/bin/thisroot.sh

//To "compile" in root run: .L nameofscript.c
//To run the function just call it with parameters

void ReadCVS(const char* FileName, const char* FileName2, unsigned bins, double Range_min, double Range_max)
{

    // * * * * * * * * Voltage and current profile * * * * * * * * * *

    std::ifstream CVSFile(FileName);

    std::string line;

    size_t pos = 0;
    bool NumericValue;

    double time, in1, in2;

    // TProfile *Time_Voltage_profile = new TProfile("tvp","Time - Voltage profile",100,-2.5,2.5);
    // TProfile *Time_Current_profile = new TProfile("tcp","Time - Current profile",100,-2.5,2.5);
    TProfile *Voltage_Current_profile = new TProfile("vcp","Voltage - Current profile",bins,Range_min, Range_max,"s");
    TProfile *Voltage_Current_profile_copy = new TProfile("vcp","Voltage - Current profile corrected",bins,Range_min, Range_max,"s");
    

    int lineNumber = 0;

    while( std::getline( CVSFile, line ) )
    {
        NumericValue = true;
        lineNumber++;

        if((pos = line.find(",")) != std::string::npos) {
            try
            {
                time = std::stod( line.substr(0, pos) );
                if( (lineNumber > 309) && (lineNumber < 719) )
                    time *= 0.001;
            }
            catch(const std::exception& e)
            {
                NumericValue = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
                continue;
            }
            
            line.erase(0, pos + 1);
        }
        if((pos = line.find(",")) != std::string::npos) {
            try
            {
                in1 = std::stod( line.substr(0, pos) );
            }
            catch(const std::exception& e)
            {
                NumericValue = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
                continue;
            }
            
            line.erase(0, pos + 1);
        }
        try
        {
            in2 = std::stod( line );
        }
        catch(const std::exception& e)
        {
            NumericValue = false;
            std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
            continue;
        }
        
        // if(NumericValue) std::cout << lineNumber << " " << time << " " << in1 << " " << in2 << std::endl;
        // if(NumericValue) Time_Voltage_profile->Fill(time,in1);
        // if(NumericValue) Time_Current_profile->Fill(time,in2);
        if(NumericValue) Voltage_Current_profile->Fill(in1,in2);
        
        //A copy of the profile to subtract the dark current
        if(NumericValue) Voltage_Current_profile_copy->Fill(in1,in2);
        
    }





    // * * * * * * * * Dark curretn profile * * * * * * * * * *

    std::ifstream CVSFile2(FileName2);

    std::string line2;

    size_t pos2 = 0;
    bool NumericValue2;

    double time2, in12, in22;

    // TProfile *Time_Voltage_profile = new TProfile("tvp","Time - Voltage profile",100,-2.5,2.5);
    // TProfile *Time_Current_profile = new TProfile("tcp","Time - Current profile",100,-2.5,2.5);
    TProfile *Dark_Current_Profile = new TProfile("dcp","Dark current profile",bins,Range_min, Range_max,"s");
    

    int lineNumber2 = 0;

    while( std::getline( CVSFile2, line2 ) )
    {
        NumericValue2 = true;
        lineNumber2++;

        if((pos2 = line2.find(",")) != std::string::npos) {
            try
            {
                time2 = std::stod( line2.substr(0, pos) );
                if( (lineNumber2 > 309) && (lineNumber2 < 719) )
                    time2 *= 0.001;
            }
            catch(const std::exception& e)
            {
                NumericValue2 = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber2 << '\n';
                continue;
            }
            
            line2.erase(0, pos2 + 1);
        }
        if((pos2 = line2.find(",")) != std::string::npos) {
            try
            {
                in12 = std::stod( line2.substr(0, pos2) );
            }
            catch(const std::exception& e)
            {
                NumericValue2 = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber2 << '\n';
                continue;
            }
            
            line2.erase(0, pos2 + 1);
        }
        try
        {
            in22 = std::stod( line2 );
        }
        catch(const std::exception& e)
        {
            NumericValue2 = false;
            std::cerr << "Non numeric value. Skipping line " << lineNumber2 << '\n';
            continue;
        }
        
        // if(NumericValue) std::cout << lineNumber << " " << time << " " << in1 << " " << in2 << std::endl;
        // if(NumericValue) Time_Voltage_profile->Fill(time,in1);
        // if(NumericValue) Time_Current_profile->Fill(time,in2);
        if(NumericValue2) Dark_Current_Profile->Fill(in12,in22);
        
    }




    //Trying to draw the three profiles
    TCanvas *aCanvas = new TCanvas("ac","Uncorrected data",1600,600);
    aCanvas->Divide(1);

    // aCanvas->cd(1);
    // Time_Voltage_profile->Draw();
    // aCanvas->cd(2);
    // Time_Current_profile->Draw();

    //aCanvas->cd(1);
   // Voltage_Current_profile->Draw();


   // aCanvas->cd(2);
   // Dark_Current_Profile->Draw();


    Voltage_Current_profile_copy->Add(Dark_Current_Profile, -1);

    aCanvas->cd(1);
    Voltage_Current_profile_copy->Draw();

 
    gStyle->SetOptFit(1);

    
    TF1 *lFunc1 = new TF1("line","[0]+[1]*x",0.2,0);
    lFunc1->SetParNames("b","m");

//para la linea recta
    TF1 *lFunc2 = new TF1("line","[0]+[1]*x", Range_min, Range_max);
    lFunc2->SetParNames("b1","m1");


    Voltage_Current_profile_copy->Fit(lFunc1,"R");
    Voltage_Current_profile_copy->Fit(lFunc2,"Rn");
    //Voltage_Current_profile_copy->Fit(lFunc2,"R+");



    CVSFile.close();
    CVSFile2.close();
    /*ReadCVS("/home/cindy/myPrograms/Plank/VerdePorFotoelectrico.csv","/home/cindy/myPrograms/Plank/FondoVerde.csv",50, -1.2,0.2,-0.36,0,-1.2,-0.35); */
}

