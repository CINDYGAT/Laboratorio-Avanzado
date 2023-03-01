/*
 * class03.cpp: Programa para mostrar el uso de la
 * clase VecInt3R.
 *
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 *
 * Cindy Gatica, febrero 2023
 *
 */


#include <cstdlib>
#include <iostream>

#include "VecR3.hpp"

using namespace std;

/* Inicio del programa, se crean instancias de VecR3
 * y se llaman los metodos. */
int main()
{
    VecR3 v1(1,0,1);
    VecR3 v2(0,1,0);

    cout<<  "v1 = " <<  v1 << endl;
    cout<<  "Magnitud de v1: " << v1.Magnitud() << endl;

    cout<<  "v2 = " <<  v2 << endl;
    cout<<  "Magnitud de v2: " << v2.Magnitud() << endl;


    VecR3 v3;

    v3 = v1 + v2;

    cout << "v3 = v1 + v2 = " << v3 << endl;

    VecR3 v4;

    v4 = v1 + 2*v2;

    VecR3 v5;

    v5 = v1 + v2/2;

    cout << "Operaciones de suma y multiplicacion/division por un flotante" << endl;
    cout << "v4 = v1 + 2*v2 = " << v4 << endl;
    cout << "v5 = v1 + v2/2 = " << v5 << endl;

    // cout << "Producto punto" << endl;
    cout << "Producto punto" << endl;
    cout << "v1*v2 = " << v1*v2 << endl;
    cout << "v3*v4 = " << v3*v4 << endl;
    cout << "Resta de vectores" << endl;
    cout << "v1-v5 = " << v1-v5 << endl;
    cout << "Multiplicacion por un flotante" << endl;
    cout << "v1*6 = " << v1*6 << endl;
    cout << "4*v4 = " << 4*v4 << endl;
    cout << "Division por un flotante" << endl;
    cout << "v5/2 = " << v5/2 << endl;
    cout << "Producto cruz" << endl;
    cout << "v1%v2 = " << v1%v2 << endl;
    cout << "Operador de comparacion" << endl;
    cout << "v3==v3 = " << (v3==v3) << endl;
    cout << "v3==v4 = " << (v3==v4) << endl;
    cout << "negacion de vector" << endl;
    cout << "-v5 = " << -v5 << endl;


    VecR3::Mostar_Polar(true);
    cout<< "Mostar en notacion esferica activada" << endl;
    cout<<  "v1 = " <<  v1 << endl;
    cout<<  "v2 = " <<  v2 << endl;
    cout << "v3 = " <<  v3 << endl;
    cout << "v4 = " <<  v4 << endl;
    cout << "v5 = " <<  v5 << endl;


    return 0;
}
