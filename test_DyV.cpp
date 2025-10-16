#include <iostream>
#include <vector>
#include "DyV.h"

int main() {
    // Test búsqueda binaria ascendente
    std::vector<int> a{1,2,3,4,5,8,13,21};
    int x = 8;
    int idx = BusquedaBinaria<int>(a, x, 0, (int)a.size()-1);
    std::cout << "BusquedaBinaria: valor " << x << " -> indice " << idx << std::endl;

    // Test búsqueda binaria descendente
    std::vector<int> b{20,15,10,9,3,1};
    int y = 9;
    int idx2 = BusquedaBinaria_INV<int>(b, y, 0, (int)b.size()-1);
    std::cout << "BusquedaBinaria_INV: valor " << y << " -> indice " << idx2 << std::endl;

    // Test QuickSort para int
    std::vector<int> u{9,3,5,1,8,7,2,4};
    QuickSort<int>(u, 0, (int)u.size()-1);
    std::cout << "QuickSort (int):";
    for (auto v : u) std::cout << " " << v;
    std::cout << std::endl;

    // Test QuickSort para float
    std::vector<float> f{3.2f, 1.1f, 5.5f, 2.0f};
    QuickSort<float>(f, 0, (int)f.size()-1);
    std::cout << "QuickSort (float):";
    for (auto v : f) std::cout << " " << v;
    std::cout << std::endl;

    // Test QuickSort para char
    std::vector<char> c{'z','a','q','b'};
    QuickSort<char>(c, 0, (int)c.size()-1);
    std::cout << "QuickSort (char):";
    for (auto ch : c) std::cout << " " << ch;
    std::cout << std::endl;

    return 0;
}

