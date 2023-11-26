#include <iostream>
#include <stdlib.h>
#include <math.h>
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
    float x, y;
    cout << "Ingrese la posicion del radar: ";
    cin >> x >> y;
    // Linea de entrada 2 / Cantidad de elementos en el mapa / de 1 a 3
    // int n;
    // cout << "Ingrese la cantidad de elementos: ";
    // cin >> n;
    // Linea de entrada 3 / Turnos de la simulacion
    int m;
    cout << "Ingrese los turnos de la simulacion: ";
    cin >> m;
    // Linea de entrada 4 / Radio de escaneo el radar
    int r;
    cout << "Ingrese el radio de escaneo del radar: ";
    cin >> r;
    // Lineas de entrada n / Posicion inicial de las entidades marinas
    float xi, yi;
    cout << "Ingrese la posicion inicial de la entidad marina: ";
    cin >> xi >> yi;
    // Lineas de entrada m / Movimiento de las entidades marinas
    float respaldoX = xi;
    float respaldoY = yi;
    for (int i = 0; i < m; i++){
        int oi;
        float ei;
        cout << "Ingrese la direccion y las unidades que se movera la entidad marina: ";
        cin >> oi >> ei;
        //Mover entidad marina
        switch (oi){
            case 1:
                yi += ei;
                break;
            case 2:
                yi += ei;
                xi += ei;
                break;
            case 3:
                xi += ei;
                break;
            case 4:
                yi -= ei;
                xi += ei;
                break;
            case 5:
                yi -= ei;
                break;
            case 6:
                yi -= ei;
                xi -= ei;
                break;
            case 7:
                xi -= ei;
                break;
            case 8:
                yi += ei;
                xi -= ei;
                break;
        }
        // Escaneo del radar.
        if ((xi - x) * (xi - x) + (yi - y) * (yi - y) <= r * r)
        {
            cout << "A " << pow((xi-x)*(xi-x) + (yi-y)*(yi-y), 1.0f/2.0f) << " unidades de distancia" << endl;
            if (xi == x && yi > y)
            {
                cout << "Esta al norte / 1" << endl;
            }
            else if (yi > y && xi > x)
            {
                cout << "Esta al noreste / 2" << endl;
            }
            else if (yi == y && xi > x)
            {
                cout << "Esta al este / 3" << endl;
            }
            else if (yi < y && xi > x)
            {
                cout << "Esta al sureste / 4" << endl;
            }
            else if (xi == x && yi < y)
            {
                cout << "Esta al sur / 5" << endl;
            }
            else if (yi < y && xi < x)
            {
                cout << "Esta al suroeste / 6" << endl;
            }
            else if (yi == y && xi < x)
            {
                cout << "Esta al oeste / 7" << endl;
            }
            else if (yi > y && xi < x)
            {
                cout << "Esta al noroeste / 8" << endl;
            }
            respaldoX = xi;
            respaldoY = yi;
        }
        else
        {
            cout << "No esta en el radar" << endl;
            cout << "Ultima posicion conocida en (" << respaldoX << "," << respaldoY << ")" << endl;
        }
    }
}