#pragma once
#include"Tiempos.h"
#include"RegistroSalarios.h"

template<class T>
class CalculoSalarioYVac {//Clase para calculo de cualquier tipo de salario, usa Tiempos.h para el calculo de salarios
public:
	CalculoSalarioYVac();
	virtual ~CalculoSalarioYVac();

	double cargaSocial(T*);
	double ahorroOblig(T*);
	double impRenta(T*, Tiempos*);

	double salEsc(T*);
	double ahorroNavi(T*);

	double calcSalBru(T*, Tiempos*);
	double calcSalNet(T*, Tiempos*);

	double liquidacion();

	string toString(T*, Tiempos*);
};

template<class T>
CalculoSalarioYVac<T>::CalculoSalarioYVac() {
}
template<class T>
CalculoSalarioYVac<T>:: ~CalculoSalarioYVac() {
}

template<class T>
double CalculoSalarioYVac<T>::cargaSocial(T* cosa) {
	return cosa->getCargaSocial() * cosa->getSalarioBase();
}
template<class T>
double CalculoSalarioYVac<T>::ahorroOblig(T* cosa) {
	return cosa->getAhorroOblig() * cosa->getSalarioBase();
}
template<class T>
double CalculoSalarioYVac<T>::impRenta(T* cosa, Tiempos*tiempito) {
	if (calcSalBru(cosa,tiempito) > 1200000) {
		return (cosa->getSalarioBase() - 1200000) * cosa->getImpRenta();
	}
	else {
		return 0;
	}
}

template<class T>
double CalculoSalarioYVac<T>::salEsc(T* cosa) {
	return cosa->getSalEsc();
}
template<class T>
double CalculoSalarioYVac<T>::ahorroNavi(T*cosa) {
	return cosa->getAhorroNavi();
}
template<class T>
double CalculoSalarioYVac<T>::calcSalBru(T* cosa, Tiempos* tiempito) {
	double salOut, salDiv;
	salDiv = (cosa->getSalarioBase()) / 30;
	salOut = salDiv * tiempito->diasTrabDesUltPag(cosa->getEmpleado()->getCedula());
	return salOut;
}
template<class T>
double CalculoSalarioYVac<T>::calcSalNet(T*cosa, Tiempos* tiempito) {
	return (calcSalBru(cosa,tiempito) - cargaSocial(cosa) - ahorroOblig(cosa) - impRenta(cosa,tiempito) - salEsc(cosa) - ahorroNavi(cosa));
}

template<class T>
string CalculoSalarioYVac<T>::toString(T* cosa, Tiempos* tiempito) {
	stringstream s;
	s << "Cedula: " << cosa->getEmpleado()->getCedula() << endl
		<< "El salario bruto es de: " << calcSalBru(cosa, tiempito) << endl
		<< "Deducciones obligatorias: " << endl
		<< "   Carga social:        " << cargaSocial(cosa) << endl
		<< "   Ahorro obligatorio:  " << ahorroOblig(cosa) << endl
		<< "   Impuesto de renta:   " << impRenta(cosa,tiempito) << endl
		<< "Deducciones opcionales:" << endl
		<< "   Salario Escolar:     " << salEsc(cosa) << endl
		<< "   Ahorro Navideno:     " << ahorroNavi(cosa) << endl
		<< "Salario neto: " << calcSalNet(cosa,tiempito) << endl;
	return s.str();
}