#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

// Formula para calcular si una entidad marina esta en el escaner
// (x0-xr)*(x0-xr) + (y0-yr)*(y0-yr) = r*r
// xr,yr= Posicion del radar; x0,y0 = Posicion de la entidad marina; r = Radio que cubre el radar

int main()
{
    SetConsoleOutputCP(CP_UTF8); // Salidas en utf-8

    // metodo para obtener strings con caracteres en blanco
    // string oracion;
    // getline(cin, oracion);
    // cout << oracion;

    // Linea de entrada 1 / Posicion del radar
    float x = 3, y = -5;
    cout << "Ingrese la posicion del radar: ";
    cin >> x >> y;
    // Linea de entrada 2 / Cantidad de elementos en el mapa / de 1 a 3
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    // Linea de entrada 3 / Turnos de la simulacion
    int m;
    cout << "Ingrese los turnos de la simulacion: ";
    cin >> m;
    // Linea de entrada 4 / Radio de escaneo el radar
    int r = 3;
    cout << "Ingrese el radio de escaneo del radar: ";
    cin >> r;
    // Lineas de entrada n / Posicion inicial de las entidades marinas
    for (int i = 0; i < n; i++)
    {
        float xi, yi;
        cout << "Ingrese la posicion inicial de la entidad marina " << i + 1 << ": ";
        cin >> xi >> yi;
        if ((xi - x) * (xi - x) + (yi - y) * (yi - y) <= r * r)
        {
            cout << "Esta en el radar" << endl;
            if (xi == x && yi > y)
            {
                cout << "Esta al norte";
            }
            else if (xi == x && yi < y)
            {
                cout << "Esta al sur" << endl;
            }
            else if (yi == y && xi > x)
            {
                cout << "Esta al este" << endl;
            }
            else if (yi == y && xi < x)
            {
                cout << "Esta al oeste" << endl;
            }
            else if (yi > y && xi > x)
            {
                cout << "Esta al noreste" << endl;
            }
            else if (yi > y && xi < x)
            {
                cout << "Esta al noroeste" << endl;
            }
            else if (yi < y && xi > x)
            {
                cout << "Esta al sureste" << endl;
            }
            else if (yi < y && xi < x)
            {
                cout << "Esta al suroeste" << endl;
            }
        }
        else
        {
            cout << "No esta en el radar" << endl;
        }
    }
}