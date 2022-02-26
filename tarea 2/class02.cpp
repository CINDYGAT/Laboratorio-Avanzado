/*
 * clase02.cpp: Programa para mostrar el uso de la
 * clase persona.
 *
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 *
 * Cindy Gatica, febrero 2022
 *
 */

#include <cstdlib>
#include <iostream>
#include "persona.hpp"
#include "persona.cpp"

using namespace std;

/* Programa para mostrar el uso de la clase persona.
 * Se crean instancia y llaman metodos para experimentar
 * que pasa. */
int main()
{
    persona Fulano;

    Fulano.Decir_Nombre();
    Fulano.Decir_origen();
    Fulano.Decir_edad();

    persona Juan("Juan Perez", 1980, 7, 2, "Capital");
    Juan.Decir_Nombre();
    Juan.Decir_origen();
    Juan.Decir_edad();

    Fulano.Asignar_Nombre("Cindy");
    Fulano.Decir_Nombre();
    Fulano.Asignar_Fecha_Nacimiento(1998,8,17);
    cout << "Anio de Nacimiento: " << Fulano.Obtener_Anio_Nacimiento() << endl;
    cout << "Mes de Nacimiento: " << Fulano.Obtener_Mes_Nacimiento() << endl;
    cout << "Dia de Nacimiento: " << Fulano.Obtener_Dia_Nacimiento() << endl;
    Fulano.Asignar_Lugar_Origen("Ciudad");
    Fulano.Decir_origen();
    Fulano.Decir_edad();

    persona* Maria = new persona("Maria Gomez", 1990, 12, 3, "Zacapa");

    persona::LLamar_Todos();

    delete Maria;

    persona::LLamar_Todos();

    return 0;
}
