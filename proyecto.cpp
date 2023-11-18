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
    float x, y;
    cin >> x >> y;
    // Línea de entrada 2 / Cantidad de elementos en el mapa / de 1 a 3
    int n;
    cin >> n;
    // Línea de entrada 3 / Turnos de la simulación
    int m;
    cin >> m;
    // Línea de entrada 4 / Radio de escaneo el radar
    int r;
    cin >> r;
    // Líneas de entrada n / Posición de las entidades marinas
    float xi, yi;
    cin >> xi >> yi;
    // CUAlquier cosa
}