#include <iostream>
#include <fstream>
#include "BST.cpp"
using namespace std;

int main() {
    ifstream inputFile("in.txt");
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo 'in.txt'" << endl;
        return 1; // Sale del programa con un código de error
    }
    
    int n;
    inputFile >> n; // Lee la longitud del BST desde la primera línea
    
    BST a;

    for (int i = 0; i < n; i++) {
        int elemento;
        inputFile >> elemento;
        a.insertar(elemento);
    }

    inputFile.close();

    a.inorden();
    cout << endl;

    return 0; 
}