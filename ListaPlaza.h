#pragma once
#include"Nodo.h"
#include"Plaza.h"
using namespace std;

class ListaPlaza {
	Nodo<Plaza>* raiz;
public:
	ListaPlaza();
	virtual ~ListaPlaza();

	void addPlaza(Nodo<Plaza>*);
	Nodo<Plaza>* getNodo(int);
	void Borrar(int);
	string toString();
};
