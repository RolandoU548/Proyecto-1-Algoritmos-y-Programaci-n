#include <iostream>
#include <math.h>
using namespace std;

// Formula para calcular si una entidad marina esta en el escaner
// (x0-xr)*(x0-xr) + (y0-yr)*(y0-yr) = r*r
// xr,yr= Posicion del radar; x0,y0 = Posicion de la entidad marina; r = Radio que cubre el radar

int main()
{
    // Linea de entrada 1 / Posicion del radar
    float x, y;
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
    int respaldoM = 0;
    for (int i = 1; i <= m; i++){
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
            cout << "Entidad Marina " << 1 << " detectada a " << pow((xi-x)*(xi-x) + (yi-y)*(yi-y), 1.0f/2.0f) << " unidades de distancia y con orientación ";
            if (xi == x && yi > y)
            {
                cout << "1 /Esta al norte" << endl;
            }
            else if (yi > y && xi > x)
            {
                cout << "2 /Esta al noreste" << endl;
            }
            else if (yi == y && xi > x)
            {
                cout << "3 /Esta al este" << endl;
            }
            else if (yi < y && xi > x)
            {
                cout << "4 /Esta al sureste" << endl;
            }
            else if (xi == x && yi < y)
            {
                cout << "5 /Esta al sur" << endl;
            }
            else if (yi < y && xi < x)
            {
                cout << "6 /Esta al suroeste" << endl;
            }
            else if (yi == y && xi < x)
            {
                cout << "7 /Esta al oeste" << endl;
            }
            else if (yi > y && xi < x)
            {
                cout << "8 /Esta al noroeste" << endl;
            }
            respaldoX = xi;
            respaldoY = yi;
            respaldoM = i;
        }
        else
        {
            cout << "Entidad Marina "<< 1 << " en posición desconocida, última posicion conocida en (" << respaldoX << "," << respaldoY << ")" << " en el turno " << respaldoM << endl;
        }
    }
}