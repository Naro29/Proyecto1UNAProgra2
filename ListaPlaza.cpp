#include"ListaPlaza.h"

ListaPlaza::ListaPlaza() {
	raiz = NULL;
};
ListaPlaza::~ListaPlaza() {}

void ListaPlaza::addPlaza(Nodo<Plaza>* nodoIn) {
	Nodo<Plaza>* nodoAct = raiz;
	Plaza* plazita;
	int catAuto;
	while (nodoAct->getSiguiente() != NULL) {
		nodoAct = nodoAct->getSiguiente();
	}
	plazita = nodoAct->getItem();
	catAuto = plazita->getCodigo() + 1;
	plazita = nodoIn->getItem();
	plazita->setCodigo(catAuto);
	nodoAct->setSiguiente(nodoIn);
}
Nodo<Plaza>* ListaPlaza::getNodo(int catIn) {
	Nodo<Plaza>* nodoAct = raiz;
	Plaza* plazita;
	while (nodoAct->getSiguiente() != NULL) {
		plazita = nodoAct->getItem();
		if (plazita->getCodigo() == catIn) {
			return nodoAct;
		}
		nodoAct = nodoAct->getSiguiente();
	}
	return NULL;
}
void ListaPlaza::Borrar(int catIn) {
	Nodo<Plaza>* nodoAct;
	Nodo<Plaza>* nodoAnt;
	nodoAct = raiz;
	nodoAnt = nodoAct;
	for (int i = 1; i < catIn; i++)
	{
		nodoAnt = nodoAct;
		nodoAct = nodoAct->getSiguiente();
	}
	nodoAnt->setSiguiente(nodoAct->getSiguiente());
	delete(nodoAct);
}
string ListaPlaza::toString() {
	Nodo<Plaza>* nodoAct = raiz;
	Plaza* plazita;
	stringstream s;
	if (nodoAct->getSiguiente() == NULL) {
		s << "No hay plazas disponibles." << endl;
	}
	else {
		while (nodoAct->getSiguiente() != NULL) {
			plazita = nodoAct->getItem();
			s << plazita->toString();
			nodoAct->getSiguiente();
		}
	}
	return s.str();
}