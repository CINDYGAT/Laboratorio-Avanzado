/*
 * VecR3.cpp: Implementacion de la clase VecR3
 *
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 *
 * CIndy Gatica, febrero 2023
 *
 */

#include <iostream>
#include <cmath>

#include "VecR3.hpp"

bool VecR3::Polar = false;

VecR3::VecR3( )
{
    Xcor = 0;
    Ycor = 0;
    Zcor = 0;
}

VecR3::VecR3( float valor_x, float valor_y, float valor_z )
{
    Xcor = valor_x;
    Ycor = valor_y;
    Zcor = valor_z;
}

VecR3::~VecR3()
{}

void VecR3::Asignar_x( float valor_x )
{
    Xcor = valor_x;
}

void VecR3::Asignar_y( float valor_y )
{
    Ycor = valor_y;
}

void VecR3::Asignar_z( float valor_z )
{
    Zcor = valor_z;
}

void VecR3::Asignar_xyz( float valor_x, float valor_y, float valor_z )
{
    Xcor = valor_x;
    Ycor = valor_y;
    Zcor = valor_z;
}

float VecR3::Obtener_x( ) const
{
    return Xcor;
}

float VecR3::Obtener_y( ) const
{
    return Ycor;
}

float VecR3::Obtener_z( ) const
{
    return Zcor;
}

float VecR3::Magnitud() const
{
    return std::sqrt( Xcor*Xcor + Ycor*Ycor + Zcor*Zcor);
}

/* Sobrecarga de operadores */

/* Calcula la suma de dos vectores */
VecR3 VecR3::operator+( const VecR3 &avec) const
{
    /* Se declara un vector temporal para almacenar los resultados */
    VecR3 tmp;
    /* Uno de los vectores a sumar es el que llama el operador,
     * por lo que se accede a el por el puntero "this". El otro
     * es el que se pasa como argumento.
     * Como se esta dentro de las definiciones de clase, se puede
     * acceder a los atributos privados. */
    tmp.Xcor = this->Xcor + avec.Xcor;
    tmp.Ycor = this->Ycor + avec.Ycor;
    tmp.Zcor = this->Zcor + avec.Zcor;

    /* Se devuelve la suma de los vectores */
    return tmp;
}

/* Calcula la resta de dos vectores */
VecR3 VecR3::operator-( const VecR3 &avec) const
{
    /* Se declara un vector temporal para almacenar los resultados */
    VecR3 tmp;
    /* Uno de los vectores a sumar es el que llama el operador,
     * por lo que se accede a el por el puntero "this". El otro
     * es el que se pasa como argumento.
     * Como se esta dentro de las definiciones de clase, se puede
     * acceder a los atributos privados. */
    tmp.Xcor = this->Xcor - avec.Xcor;
    tmp.Ycor = this->Ycor - avec.Ycor;
    tmp.Zcor = this->Zcor - avec.Zcor;

    /* Se devuelve la suma de los vectores */
    return tmp;
}

/* Calcula el producto punto de dos vectores */
float VecR3::operator*( const VecR3 &avec ) const
{
    /* Ver los comentarios de operator+ */
    float tmp;

    tmp = this->Xcor * avec.Xcor + this->Ycor * avec.Ycor + this->Zcor * avec.Zcor;

    return tmp;
}

/* Calcula el producto entre un vector y un escalar  */
VecR3 VecR3::operator*( const float &aflt ) const
{
    /* Ver los comentarios de operator+ */
    VecR3 tmp;

    tmp.Xcor = this->Xcor * aflt;
    tmp.Ycor = this->Ycor * aflt;
    tmp.Zcor = this->Zcor * aflt;
    
    return tmp;
}

/* Calcula el la division entre un vector y un escalar  */
VecR3 VecR3::operator/( const float &aflt ) const
{
    /* Ver los comentarios de operator+ */
    VecR3 tmp;

    tmp.Xcor = this->Xcor / aflt;
    tmp.Ycor = this->Ycor / aflt;
    tmp.Zcor = this->Zcor / aflt;
    
    return tmp;
}

/* Calcula la suma de dos vectores */
VecR3 VecR3::operator%( const VecR3 &avec) const
{
    /* Se declara un vector temporal para almacenar los resultados */
    VecR3 tmp;
    /* Uno de los vectores a sumar es el que llama el operador,
     * por lo que se accede a el por el puntero "this". El otro
     * es el que se pasa como argumento.
     * Como se esta dentro de las definiciones de clase, se puede
     * acceder a los atributos privados. */
    tmp.Xcor = (this->Ycor * avec.Zcor) + (this->Zcor * avec.Ycor);
    tmp.Ycor = (this->Zcor * avec.Xcor) + (this->Xcor * avec.Zcor);
    tmp.Zcor = (this->Xcor * avec.Ycor) + (this->Ycor * avec.Xcor);

    /* Se devuelve la suma de los vectores */
    return tmp;
}

/* Operador de asignacion */
VecR3 VecR3::operator=( const VecR3 &avec)
{
    /* El vector que llama el operador es el que 
     * esta al lado izquierdo de este, y el que
     * esta al lado derecho se pasa como argumento
     * por lo que a "this" se le debe asignar el 
     * valor del argumento */
    this->Xcor = avec.Xcor;
    this->Ycor = avec.Ycor;
    this->Zcor = avec.Zcor;

    return (*this);
}

/* Operador de comparacion */
bool VecR3::operator==( const VecR3 &avec) const
{
    if (this->Xcor == avec.Xcor)
    {
        if (this->Ycor == avec.Ycor)
        {
            if (this->Zcor == avec.Zcor)
            {
                return true;    
            }
            
        }
        
    }
    

    return false;
}


/* Calcula la negacion de un vector  */
VecR3 VecR3::operator-() const
{
    /* Ver los comentarios de operator+ */
    VecR3 tmp;

    tmp.Xcor = this->Xcor * -1;
    tmp.Ycor = this->Ycor * -1;
    tmp.Zcor = this->Zcor * -1;
    
    return tmp;
}

/* Metodo de clase: Fija el valor del flag para que
 * el despliege del vector sea en polar (true) o
 * cartesiano (false) */
void VecR3::Mostar_Polar( bool valor )
{
    Polar = valor;
}

/* Funciones amigas. 
 * Estas funciones fueron declarada como amigas (friend) en la 
 * definicion de la clase. Las funciones amigas no son metodos 
 * de los objetos, pero pueden acceder a los atributos privados de
 * estos.*/

/* Despliega un vector con cout */
std::ostream &operator<<( std::ostream &salida, const VecR3 &avec )
{
    /* Se decide el tipo de salida en funcion del valor del atributo
     * de clase Polar. */
    if( VecR3::Polar )
    {
        /* Se calcula el angulo polar del vector. La magnitud
         * se obtiene del metodo ya implementado */
        float phi = std::atan2( avec.Ycor , avec.Xcor );
        float theta = std::atan2(std::sqrt(avec.Xcor*avec.Xcor + avec.Ycor*avec.Ycor),avec.Zcor);
        salida << "( " << avec.Magnitud() << " , " << theta << " , " << phi << " )";
    }
    else
        salida << "( " << avec.Xcor << ", " << avec.Ycor << ", " << avec.Zcor << " )";
    
    return salida;
}

/* Esta funcion sobrecarga el operador* para permitir
 * la multiplicacion de un escalar por un vector
 * de la forma aesc*avec. Es importante hacer notar
 * que el orden de la multiplicacion NO ES CONMUTATIVO,
 * es decir, esta funcion no es llamada si el orden
 * escalar * vector es invertido. */
VecR3 operator*( const float &aesc, const VecR3 &avec )
{
    VecR3 tmp;
    tmp.Xcor = aesc*avec.Xcor;
    tmp.Ycor = aesc*avec.Ycor;
    tmp.Zcor = aesc*avec.Zcor;

    return tmp;
}
