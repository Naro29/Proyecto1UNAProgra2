#include"ListaContratos.h"

ListaContratos::ListaContratos() {
	raiz = NULL;
};
ListaContratos::~ListaContratos() {}

void ListaContratos::addContrato(Nodo<Contrato>* nodoIn) {
	Nodo<Contrato>* nodoAct = raiz;
	Contrato* contratito;
	int catAuto;
	while (nodoAct->getSiguiente() != NULL) {
		nodoAct = nodoAct->getSiguiente();
	}
	contratito = nodoAct->getItem();
	catAuto = contratito->getID() + 1;
	contratito = nodoIn->getItem();
	contratito->setID(catAuto);
	nodoAct->setSiguiente(nodoIn);
}
Nodo<Contrato>* ListaContratos::getNodo(int IDIn) {
	Nodo<Contrato>* nodoAct = raiz;
	Contrato* contratito;
	while (nodoAct->getSiguiente() != NULL) {
		contratito = nodoAct->getItem();
		if (contratito->getID() == IDIn) {
			return nodoAct;
		}
		nodoAct = nodoAct->getSiguiente();
	}
	return NULL;
}
void ListaContratos::Borrar(int catIn) {
	Nodo<Contrato>* nodoAct;
	Nodo<Contrato>* nodoAnt;
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
string ListaContratos::toString() {
	Nodo<Contrato>* nodoAct = raiz;
	Contrato* contratito;
	PlanillaCortoPlazo*planCP;
	PlanillaIndef*planI;
	ServicioProfesional*servP;
	stringstream s;
	if (nodoAct->getSiguiente() == NULL) {
		s << "No hay contratos." << endl;
	}
	else {
		while (nodoAct->getSiguiente() != NULL) {
			contratito = nodoAct->getItem();
			s << contratito->toString();
			nodoAct->getSiguiente();
		}
	}
	return s.str();
}