#pragma once
#include"Nodo.h"
#include"Contrato.h"
#include"CalculoSalarioYVac.h"
#include"RegistroSalarios.h"
#include"Tiempos.h"
using namespace std;

template<class T>
class Lista {
	Nodo<T>* raiz;
public:
	Lista();
	virtual ~Lista();
	Lista& operator = (const Lista&);

	Nodo<T>* getRaiz();

	void addNodo(Nodo<T>*);
	Nodo<T>* getNodo(int);
	bool setNodoByCedula(Empleado*, string);
	bool setNodoByID(T*);
	void Borrar(int);
	bool cambAuto(string,Plaza*);
	bool cambAuto(string,Plaza*,double,double,double,double,double);
	T* empMay3Mes(Tiempos*);

	string toString();
	string toStringSalarios(Tiempos*);
	string toStringEmpleados();

};

template<class T>
Lista<T>::Lista() {
	raiz = NULL;
};
template<class T>
Lista<T>::~Lista() {}

template<class T>
Lista<T>& Lista<T>::operator = (const Lista&L2) {
	raiz = NULL;
	raiz = L2.getRaiz();
	return *this;
}
template<class T>
Nodo<T>* Lista<T>::getRaiz() {
	return raiz;
}

template<class T>
void Lista<T>::addNodo(Nodo<T>* nodoIn) {
	Nodo<T>* nodoAct = raiz;
	T* cosita;
	int catAuto;
	if (raiz != NULL) {//Lista no vacia?
		while (nodoAct->getSiguiente() != NULL) {//Corremos hasta el ultimo nodo
			nodoAct = nodoAct->getSiguiente();
		}
	}
	//Este algoritmo a continuacion es para aplicar un ID automatico unico. Si un Item se elimina, su ID tambien
	if (raiz == NULL) {//Si la lista esta vacia empieza con el ID 0
		cosita = nodoIn->getItem();
		catAuto = 0;
		cosita->setID(catAuto);
		nodoIn->setItem(cosita);
		raiz = nodoIn;
	}
	else {
		cosita = nodoAct->getItem();
		catAuto = cosita->getID() + 1;
		cosita = nodoIn->getItem();
		cosita->setID(catAuto);
		nodoIn->setItem(cosita);
		nodoAct->setSiguiente(nodoIn);
	}
}
template<class T>
Nodo<T>* Lista<T>::getNodo(int IDIn) {
	Nodo<T>* nodoAct = raiz;
	T* cosita;
	while (nodoAct != NULL) {
		cosita = nodoAct->getItem();
		if (cosita->getID() == IDIn) {
			return nodoAct;
		}
		nodoAct = nodoAct->getSiguiente();
	}
	return NULL;
}
template<class T>
bool Lista<T>::setNodoByCedula(Empleado* empIn, string cedIn) {
	Nodo<T>* nodoAct = raiz;
	T* cosita;
	while (nodoAct != NULL) {
		cosita = nodoAct->getItem();
		if (cosita->getEmpleado()->getCedula() == cedIn) {
			cosita->setEmpleado(empIn);
			nodoAct->setItem(cosita);
			return true;
		}
		nodoAct = nodoAct->getSiguiente();
	}
	return false;
}
template<class T>
bool Lista<T>::setNodoByID(T*cosaIn) {
	Nodo<T>* nodoAct = raiz;
	T* cosita;
	while (nodoAct != NULL) {
		cosita = nodoAct->getItem();
		if (cosita->getID() == cosaIn->getID()) {
			nodoAct->setItem(cosaIn);
			return true;
		}
		nodoAct = nodoAct->getSiguiente();
	}
	return false;
}
template<class T>
void Lista<T>::Borrar(int catIn) {
	Nodo<T>* nodoAct;
	Nodo<T>* nodoAnt;
	nodoAct = raiz;
	nodoAnt = nodoAct;
	for (int i = 1; i < catIn; i++){
		nodoAnt = nodoAct;
		nodoAct = nodoAct->getSiguiente();
	}
	nodoAnt->setSiguiente(nodoAct->getSiguiente());
	delete(nodoAct);
}

template<class T>
T* Lista<T>::empMay3Mes(Tiempos* Tiempito) {
	Nodo<T>* nodoAct = raiz;
	T* cosita;
	int mes;
	int salida[3];
	if (raiz == NULL) {
		return NULL;
	}
	else {
		while (nodoAct != NULL) {
			cosita = nodoAct->getItem();
			salida[2] = stoi(cosita->getFechaIngreso().substr(0, 2));//Consigue las fechas y las divide
			salida[1] = stoi(cosita->getFechaIngreso().substr(3, 2));
			salida[0] = stoi(cosita->getFechaIngreso().substr(6, 4));
			mes = Tiempito->mesesTrab(salida);//consigue los meses
			if (mes >= 3 && cosita->getFechaCesantia() == " " && cosita->tengoPlaza() == false) {//Verifica si de verdad tiene los requerimentos
				return cosita;
			}
			nodoAct = nodoAct->getSiguiente();
		}
	}
	return NULL;
}

template<class T>
string Lista<T>::toString() {
	Nodo<T>* nodoAct = raiz;
	T* cosita;
	stringstream s;
	if (raiz == NULL) {
		s << "Lista vacia." << endl;
	}
	else {
		while (nodoAct != NULL) {
			cosita = nodoAct->getItem();
			s << cosita->toString() << endl;
			nodoAct = nodoAct->getSiguiente();
		}
	}
	return s.str();
}
template<class T>
string Lista<T>::toStringSalarios(Tiempos*tiempito) {
	Nodo<T>* nodoAct = raiz;
	T* cosita;
	CalculoSalarioYVac<Contrato> calculatron;
	RegistroSalarios registradora;
	stringstream s;
	if (raiz == NULL) {
		s << "Lista vacia." << endl;
	}
	else {
		while (nodoAct != NULL) {
			cosita = nodoAct->getItem();
			if (cosita->getFechaCesantia() == " ") {
				if (tiempito->getFechaQuin() == tiempito->getFechaAct(2) && cosita->getQuincenal()) {//Verificar datos para ver si le toca el pago quincenal o no
					s << calculatron.toString(cosita, tiempito) << endl;
					registradora.registrarSalario(cosita->getEmpleado()->getCedula(), cosita->getQuincenal(), tiempito->getFechaAct(0), tiempito->getFechaAct(1), tiempito->getFechaAct(2), cosita->getSalarioBase(),calculatron.calcSalBru(cosita,tiempito),calculatron.calcSalNet(cosita,tiempito)); //Se registra inmediatamente en el txt
				}
				if (tiempito->getFechaFMes() == tiempito->getFechaAct(2)) {//Verificar datos para ver si le toca el pago de fin de mes o no
					s << calculatron.toString(cosita, tiempito) << endl;
					registradora.registrarSalario(cosita->getEmpleado()->getCedula(), cosita->getQuincenal(), tiempito->getFechaAct(0), tiempito->getFechaAct(1), tiempito->getFechaAct(2), cosita->getSalarioBase(), calculatron.calcSalBru(cosita, tiempito), calculatron.calcSalNet(cosita, tiempito)); //Se registra inmediatamente en el txt
				}
			}
			nodoAct = nodoAct->getSiguiente();
		}
	}
	return s.str();
}
template<class T>
string Lista<T>::toStringEmpleados() {//Imprime el atributo empleado del contrato
	Nodo<T>* nodoAct = raiz;
	T* cosita;
	stringstream s;
	if (raiz == NULL) {
		s << "Lista vacia." << endl;
	}
	else {
		while (nodoAct != NULL) {
			cosita = nodoAct->getItem();
			s << cosita->getEmpleado()->toString() << endl;
			nodoAct = nodoAct->getSiguiente();
		}
	}
	return s.str();
}
