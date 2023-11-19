#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

// Fórmula para calcular si una entidad marina está en el escáner
// (x0-xr)*(x0-xr) + (y0-yr)*(y0-yr) = r*r
// xr,yr= Posición del radar; x0,y0 = Posición de la entidad marina; r = Radio que cubre el radar

int main()
{
    SetConsoleOutputCP(CP_UTF8); // Salidas en utf-8

    // método para obtener strings con caracteres en blanco
    // string oracion;
    // getline(cin, oracion);
    // cout << oracion;

    // Línea de entrada 1 / Posición del radar
    float x = 3, y = -5;
    cout << "Ingrese la posición del radar: ";
    cin >> x >> y;
    // Línea de entrada 2 / Cantidad de elementos en el mapa / de 1 a 3
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    // Línea de entrada 3 / Turnos de la simulación
    int m;
    cout << "Ingrese los turnos de la simulación: ";
    cin >> m;
    // Línea de entrada 4 / Radio de escaneo el radar
    int r = 3;
    cout << "Ingrese el radio de escaneo del radar: ";
    cin >> r;
    // Líneas de entrada n / Posición inicial de las entidades marinas
    for (int i = 0; i < n; i++)
    {
        float xi, yi;
        cout << "Ingrese la posición inicial de la entidad marina " << i + 1 << ": ";
        cin >> xi >> yi;
        if ((xi - x) * (xi - x) + (yi - y) * (yi - y) <= r * r)
        {
            cout << "Está en el radar" << endl;
            if (xi == x && yi > y)
            {
                cout << "Está al norte";
            }
            else if (xi == x && yi < y)
            {
                cout << "Está al sur" << endl;
            }
            else if (yi == y && xi > x)
            {
                cout << "Está al este" << endl;
            }
            else if (yi == y && xi < x)
            {
                cout << "Está al oeste" << endl;
            }
            else if (yi > y && xi > x)
            {
                cout << "Está al noreste" << endl;
            }
            else if (yi > y && xi < x)
            {
                cout << "Está al noroeste" << endl;
            }
            else if (yi < y && xi > x)
            {
                cout << "Está al sureste" << endl;
            }
            else if (yi < y && xi < x)
            {
                cout << "Está al suroeste" << endl;
            }
        }
        else
        {
            cout << "No está en el radar" << endl;
        }
    }
}