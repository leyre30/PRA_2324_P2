#ifndef DYV_H
#define DYV_H

#include <vector>
#include <iostream>
#include <algorithm>

// Búsqueda binaria (ascendente). Devuelve índice o -1 si no se encuentra.
template<typename T>
int BusquedaBinaria(const std::vector<T>& v, const T& x, int ini, int fin) {
    if (ini > fin) return -1;
    int medio = (ini + fin) / 2;
    if (v[medio] == x) return medio;
    if (v[medio] > x) return BusquedaBinaria(v, x, ini, medio - 1);
    return BusquedaBinaria(v, x, medio + 1, fin);
}

// Búsqueda binaria para vectores ordenados en orden descendente.
template<typename T>
int BusquedaBinaria_INV(const std::vector<T>& v, const T& x, int ini, int fin) {
    if (ini > fin) return -1;
    int medio = (ini + fin) / 2;
    if (v[medio] == x) return medio;
    if (v[medio] < x) return BusquedaBinaria_INV(v, x, ini, medio - 1); // invertido
    return BusquedaBinaria_INV(v, x, medio + 1, fin);
}

// Partition: usa el último elemento como pivote, devuelve índice del pivote final.
template<typename T>
int Partition(std::vector<T>& V, int ini, int fin) {
    T x = V[fin];
    int i = ini;
    for (int j = ini; j <= fin - 1; ++j) {
        if (V[j] <= x) {
            std::swap(V[i], V[j]);
            ++i;
        }
    }
    std::swap(V[i], V[fin]);
    return i;
}

// QuickSort recursivo.
template<typename T>
void QuickSort(std::vector<T>& V, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition(V, ini, fin);
        QuickSort(V, ini, pivot - 1);
        QuickSort(V, pivot + 1, fin);
    }
}

#endif
