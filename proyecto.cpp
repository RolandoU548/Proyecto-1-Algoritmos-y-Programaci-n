#include <iostream>
#include <math.h>
using namespace std;

// Formula para calcular si una entidad marina esta en el escaner
// (x0-xr)*(x0-xr) + (y0-yr)*(y0-yr) = r*r
// xr,yr= Posicion del radar; x0,y0 = Posicion de la entidad marina; r = Radio que cubre el radar

void cambiarCoordenada(float &xi, float &yi, int &oi, float &ei)
{
    switch (oi)
    {
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
}

void escanearRadar(float &xi, float &yi, int &oi, float &ei, float &x, float &y, int &r, int &entidad, int &turno, float &respaldoX, float &respaldoY, int &respaldoM)
{
    if ((xi - x) * (xi - x) + (yi - y) * (yi - y) <= r * r)
    {
        if (xi == x && yi > y)
        {
            cout << "Entidad Marina " << entidad << " detectada a " << pow((xi - x) * (xi - x) + (yi - y) * (yi - y), 1.0f / 2.0f) << " unidades de distancia y con orientación 1" << endl;
        }
        else if (yi > y && xi > x)
        {
            cout << "Entidad Marina " << entidad << " detectada a " << pow((xi - x) * (xi - x) + (yi - y) * (yi - y), 1.0f / 2.0f) << " unidades de distancia y con orientación 2" << endl;
        }
        else if (yi == y && xi > x)
        {
            cout << "Entidad Marina " << entidad << " detectada a " << pow((xi - x) * (xi - x) + (yi - y) * (yi - y), 1.0f / 2.0f) << " unidades de distancia y con orientación 3" << endl;
        }
        else if (yi < y && xi > x)
        {
            cout << "Entidad Marina " << entidad << " detectada a " << pow((xi - x) * (xi - x) + (yi - y) * (yi - y), 1.0f / 2.0f) << " unidades de distancia y con orientación 4" << endl;
        }
        else if (xi == x && yi < y)
        {
            cout << "Entidad Marina " << entidad << " detectada a " << pow((xi - x) * (xi - x) + (yi - y) * (yi - y), 1.0f / 2.0f) << " unidades de distancia y con orientación 5" << endl;
        }
        else if (yi < y && xi < x)
        {
            cout << "Entidad Marina " << entidad << " detectada a " << pow((xi - x) * (xi - x) + (yi - y) * (yi - y), 1.0f / 2.0f) << " unidades de distancia y con orientación 6" << endl;
        }
        else if (yi == y && xi < x)
        {
            cout << "Entidad Marina " << entidad << " detectada a " << pow((xi - x) * (xi - x) + (yi - y) * (yi - y), 1.0f / 2.0f) << " unidades de distancia y con orientación 7" << endl;
        }
        else if (yi > y && xi < x)
        {
            cout << "Entidad Marina " << entidad << " detectada a " << pow((xi - x) * (xi - x) + (yi - y) * (yi - y), 1.0f / 2.0f) << " unidades de distancia y con orientación 8" << endl;
        }
        respaldoX = xi;
        respaldoY = yi;
        respaldoM = turno;
    }
    else if (respaldoM != 0)
    {
        cout << "Entidad Marina " << entidad << " en posición desconocida, última posicion conocida en (" << respaldoX << "," << respaldoY << ")"
             << " en el turno " << respaldoM << endl;
    }
}

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
    float x1, y1, x2, y2, x3, y3;
    for (int i = 1; i <= n; i++)
    {
        cout << "Ingrese la posicion inicial de la entidad marina " << i << ": ";
        switch (i)
        {
        case 1:
            cin >> x1 >> y1;
            break;
        case 2:
            cin >> x2 >> y2;
            break;
        case 3:
            cin >> x3 >> y3;
            break;
        }
    }
    // Lineas de entrada m / Movimiento de las entidades marinas
    float respaldoX1 = x1, respaldoX2 = x2, respaldoX3 = x3;
    float respaldoY1 = y1, respaldoY2 = y2, respaldoY3 = y3;
    int respaldoM1 = 0, respaldoM2 = 0, respaldoM3 = 0;
    for (int turno = 1; turno <= m; turno++)
    {
        for (int entidad = 1; entidad <= n; entidad++)
        {
            int oi;
            float ei;
            cout << "Ingrese la direccion y las unidades que se movera la entidad marina: ";
            cin >> oi >> ei;
            switch (entidad)
            {
            case 1:
                // Mover entidad marina
                cambiarCoordenada(x1, y1, oi, ei);
                // Escaneo del radar.
                escanearRadar(x1, y1, oi, ei, x, y, r, entidad, turno, respaldoX1, respaldoY1, respaldoM1);
                break;
            case 2:
                // Mover entidad marina
                cambiarCoordenada(x2, y2, oi, ei);
                // Escaneo del radar.
                escanearRadar(x2, y2, oi, ei, x, y, r, entidad, turno, respaldoX2, respaldoY2, respaldoM2);
                break;
            case 3:
                // Mover entidad marina
                cambiarCoordenada(x3, y3, oi, ei);
                // Escaneo del radar.
                escanearRadar(x3, y3, oi, ei, x, y, r, entidad, turno, respaldoX3, respaldoY3, respaldoM3);
                break;
            }
        }
    }
}