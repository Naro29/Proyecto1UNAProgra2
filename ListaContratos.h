#pragma once
#include"Nodo.h"
#include"Contrato.h"
#include"PlanillaCortoPlazo.h"
#include"PlanillaIndef.h"
#include"ServicioProfesional.h"
using namespace std;

class ListaContratos {
	Nodo<Contrato>* raiz;
public:
	ListaContratos();
	virtual ~ListaContratos();

	void addContrato(Nodo<Contrato>*);
	Nodo<Contrato>* getNodo(int);
	void Borrar(int);
	string toString();
};//