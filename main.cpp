#include <iostream>
#include <fstream>
#include "BST.cpp"
using namespace std;

/*
Este código lee un input de archivo de texto, los guarda en un árbol binario,
lo recorre en inorden y calcula el número mínimo de comparaciones a realizarse
tomando en cuenta que los números del archivo de texto son longitudes de listas a ordenarse.

Equipo:
Andrés Martínez, A00227463
Fernanda Granados, A01252895
Santiago Poblete, A01254609
Martín Tánori, A01252900

Fecha: 22 de octubre de 2023
*/


int main() {
    ifstream inputFile("in.txt");
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo 'in.txt'" << endl;
        return 1; // Sale del programa con un código de error
    }
    
    int longitudBST;
    inputFile >> longitudBST; // Lee la longitud del BST desde la primera línea
    
    BST arbolBinario;

    for (int i = 0; i < longitudBST; i++) {     // Inserta los elementos en el árbol
        int elemento;
        inputFile >> elemento;
        arbolBinario.insertar(elemento);
    }

    inputFile.close();

    vector<int> arbolOrd = arbolBinario.inorden();      
    int size = 0;
    size = arbolOrd.size();

    for(int i=0; i<size; i++){      // Muestra los elementos del árbol inorden
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