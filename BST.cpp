#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class NodoArbolBinario {
public:
    int info;
    NodoArbolBinario* hijoIzquierdo;
    NodoArbolBinario* hijoDerecho;

    NodoArbolBinario(int dato) {
        info = dato;
        hijoIzquierdo = nullptr;
        hijoDerecho = nullptr;
    }
};

class BST {
    
public:
    NodoArbolBinario* raiz;

    BST() {
        raiz = nullptr;
    }

    NodoArbolBinario* buscar(int dato) {
        return buscarRecursivo(raiz, dato);
    }
private:
    NodoArbolBinario* buscarRecursivo(NodoArbolBinario* p, int dato) {
        if(p == nullptr)
            return nullptr;
        else if(dato < p->info)
            return buscarRecursivo(p->hijoIzquierdo, dato);
        else if(dato > p->info)
            return buscarRecursivo(p->hijoDerecho, dato);
        else
            return p;
    }

public:
    void insertar(int dato) {
        raiz = insertarRecursivo(raiz, dato);
    }
private:
    NodoArbolBinario* insertarRecursivo(NodoArbolBinario* p, int dato) {
        if(p == nullptr)
            p = new NodoArbolBinario(dato);
        else if (dato < p->info)
            p->hijoIzquierdo = insertarRecursivo(p->hijoIzquierdo, dato);
        else if(dato > p->info)
            p->hijoDerecho = insertarRecursivo(p->hijoDerecho, dato);
        else
            cout << "El elemento ya existe y no se puede insertar" << endl;
        return p;
    }

public:
    void eliminar(int dato) {
        raiz = eliminarRecursivo(raiz, dato);
    }
private:
    NodoArbolBinario* eliminarRecursivo(NodoArbolBinario* p, int dato) {
        if(p == nullptr)
            cout << "No se encontró el dato" << endl;
        else if(dato < p->info)    // seguir buscando en su subárbol izquierdo
            p->hijoIzquierdo = eliminarRecursivo(p->hijoIzquierdo, dato);
        else if(dato > p->info)    // seguir buscando en su subárbol derecho
            p->hijoDerecho = eliminarRecursivo(p->hijoDerecho, dato);
        else {
            NodoArbolBinario* q = p; // nodo a eliminar del árbol
            if(q->hijoIzquierdo == nullptr)
                p = q->hijoDerecho;
            else if(q->hijoDerecho == nullptr)
                p = q->hijoIzquierdo;
            else    // tiene los dos hijos
                q = reemplazar(q);
            delete(q);
        }
        return p;
    }
    NodoArbolBinario* reemplazar(NodoArbolBinario* act) {
        NodoArbolBinario* elimina = act;
        NodoArbolBinario* reemplazo = act->hijoDerecho;

        while(reemplazo->hijoIzquierdo != nullptr) {
            elimina = reemplazo;
            reemplazo = reemplazo->hijoIzquierdo;
        }

        act->info = reemplazo->info;
        if(elimina == act)
            elimina->hijoDerecho = reemplazo->hijoDerecho;
        else
            elimina->hijoIzquierdo = reemplazo->hijoIzquierdo;

        return reemplazo;
    }

public:
    void levelByLevel() {
        if (raiz == nullptr) {
            return;
        }

        
        std::queue<NodoArbolBinario*> cola;


        cola.push(raiz);
        
        std::cout << "Level by level: ";

        while (!cola.empty()) {
            int nivelSize = cola.size();

            for (int i = 0; i < nivelSize; i++) {
                NodoArbolBinario* nodoActual = cola.front();
                cola.pop();

                std::cout << nodoActual->info << " ";

                if (nodoActual->hijoIzquierdo != nullptr) {
                    cola.push(nodoActual->hijoIzquierdo);
                }
                if (nodoActual->hijoDerecho != nullptr) {
                    cola.push(nodoActual->hijoDerecho);
                }
            }
        }
    }

public:
    void preorden() {
        std::cout << "Preorder: ";
        preordenRecursivo(raiz);
    }
private:
    void preordenRecursivo(NodoArbolBinario* p) {
        if(p != nullptr) {
            cout << p->info << " ";
            preordenRecursivo(p->hijoIzquierdo);
            preordenRecursivo(p->hijoDerecho);
        }
    }

public:
    vector<int> inorden() {
        vector<int> numOrdenados;
        inordenRecursivo(raiz, numOrdenados);
        return numOrdenados;
    }
private:
    void inordenRecursivo(NodoArbolBinario* p, vector<int>& vect) {
        if(p != nullptr) {
            inordenRecursivo(p->hijoIzquierdo, vect);
            vect.push_back(p->info);
            inordenRecursivo(p->hijoDerecho, vect);
        }
    }

public:
    void postorden() {
        std::cout << "Postorder: ";
        postordenRecursivo(raiz);
    }
private:
    void postordenRecursivo(NodoArbolBinario* p) {
        if(p != nullptr) {
            postordenRecursivo(p->hijoIzquierdo);
            postordenRecursivo(p->hijoDerecho);
            cout << p->info << " ";
        }
    }

public:
    int height(NodoArbolBinario* p) {
        if (p == nullptr) {
            return 0;
        }
        
        int heightIzq = height(p->hijoIzquierdo);
        int heightDer = height(p->hijoDerecho);

        return 1 + max(heightIzq, heightDer);
    }

    void visitar(int opcion) {
        while(opcion<1 || opcion>4) {
            cout << "ERROR. Vuelva a intentar." << endl;
            cin >> opcion;
        }
        if (opcion == 1) {
            preorden();
            cout << endl;
        } else if (opcion == 2) {
            inorden();
            cout << endl;
        } else if (opcion == 3) {
            postorden();
            cout << endl;
        } else if (opcion == 4) {
            levelByLevel();
            cout << endl;
        } else {
            cout << "ERROR. Vuelva a intentar." << endl;
        }
    }

public:
    void ancestors(int data) {
        ancestorsRecursivo(raiz, data);
    } 

private:
    void ancestorsRecursivo(NodoArbolBinario* p, int dato) {
        if (p == nullptr) {
            return;
        }
        if (p->info == dato) {
            return;
        }
        if (p->hijoIzquierdo != nullptr && p->hijoIzquierdo->info == dato) {
            cout << p->info << " ";
            return;
        }
        if (p->hijoDerecho != nullptr && p->hijoDerecho->info == dato) {
            cout << p->info << " ";
            return;
        }

        if (dato < p->info) {
            ancestorsRecursivo(p->hijoIzquierdo, dato);
        } else {
            ancestorsRecursivo(p->hijoDerecho, dato);
        }

        cout << p->info << " ";
        
    }

public:
    int whatlevelamI(int data) {
        return whatlevelamIRecursivo(raiz, data, 1) == 0 ? -1 : whatlevelamIRecursivo(raiz, data, 1);
    }

private:
    int whatlevelamIRecursivo(NodoArbolBinario* p, int dato, int nivel) {
        if (p == nullptr) {
            return 0;
        }
        if (p->info == dato) {
            return nivel;
        }

        int nivelBajo = whatlevelamIRecursivo(p->hijoIzquierdo, dato, nivel + 1);
        if (nivelBajo != 0) {
            return nivelBajo;
        }

        nivelBajo = whatlevelamIRecursivo(p->hijoDerecho, dato, nivel + 1);
        return nivelBajo;
    }
};

