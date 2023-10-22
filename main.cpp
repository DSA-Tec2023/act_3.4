#include <iostream>
#include "BST.cpp"

int main() {
    BST a;

    std::ifstream inputFile("in.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo 'in.txt'" << std::endl;
        return 1; // Sale del programa con un código de error
    }
    
    int n;
    inputFile >> n; // Lee la longitud del vector desde la primera línea
    
    
    std::vector<int> miVector;
    

    for (int i = 0; i < n; i++) {
        int elemento;
        inputFile >> elemento;
        miVector.push_back(elemento);
    }


    std::cout << "Hello, world!" << std::endl;
    return 0; 
}