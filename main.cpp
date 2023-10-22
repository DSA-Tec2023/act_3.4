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
    
    int longitudBST;
    inputFile >> longitudBST; // Lee la longitud del BST desde la primera línea
    
    BST arbolBinario;

    for (int i = 0; i < longitudBST; i++) {
        int elemento;
        inputFile >> elemento;
        arbolBinario.insertar(elemento);
    }

    inputFile.close();

    vector<int> arbolOrd = arbolBinario.inorden();
    int size = 0;
    size = arbolOrd.size();

    for(int i=0; i<size; i++){
        cout << arbolOrd[i] << " ";
    }
    cout << endl;
    
    int nOperaciones = 0; 
    int total = 0;

    nOperaciones = arbolOrd[0] + arbolOrd[1] - 1;
    total = nOperaciones;
    
    // cout << nOperaciones << endl; // para revisar que se haga bien la primera operacion

    for(int i=2; i<size; i++){
        nOperaciones = nOperaciones + arbolOrd[i] - 1;
        //cout << nOperaciones << endl; // para ver las operaciones
        total = total + nOperaciones;
    }

    cout << total << endl;

    return 0; 
}