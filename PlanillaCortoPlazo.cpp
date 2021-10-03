#include"PlanillaCortoPlazo.h"

PlanillaCortoPlazo::PlanillaCortoPlazo() {
	empleadito = NULL;
	fechaIngreso = " ";
	fechaCesantia = " ";
	cargaSocial = 0;
	ahorroOblig = 0;
	impRenta = 0;
	salEsc = 0;
	ahorroNavi = 0;
	empresita = NULL;
}
PlanillaCortoPlazo::PlanillaCortoPlazo(int IDIn, bool quinIn, Empleado* eIn, string fIIn, string fCIn, double cSIn, double aOIn, double iRIn, double sEIn, double aNIn, Empresa* emps) {
	ID = IDIn;
	quincenal = quinIn;
	empleadito = eIn;
	fechaIngreso = fIIn;
	fechaCesantia = fCIn;
	cargaSocial = cSIn;
	ahorroOblig = aOIn;
	impRenta = iRIn;
	salEsc = sEIn;
	ahorroNavi = aNIn;
	empresita = emps;
}
PlanillaCortoPlazo::~PlanillaCortoPlazo() {}

int PlanillaCortoPlazo::getID() {
	return ID;
}
Empleado* PlanillaCortoPlazo::getEmpleado() {
	return empleadito;
}
string PlanillaCortoPlazo::getFechaIngreso() {
	return fechaIngreso;
}
string PlanillaCortoPlazo::getFechaCesantia() {
	return fechaCesantia;
}
double PlanillaCortoPlazo::getCargaSocial() {
	return cargaSocial;
}
double PlanillaCortoPlazo::getAhorroOblig() {
	return ahorroOblig;
}
double PlanillaCortoPlazo::getImpRenta() {
	return impRenta;
}
double PlanillaCortoPlazo::getSalEsc() {
	return salEsc;
}
double PlanillaCortoPlazo::getAhorroNavi() {
	return ahorroNavi;
}

void PlanillaCortoPlazo::setID(int IDIn) {
	ID = IDIn;
}
void PlanillaCortoPlazo::setEmpleado(Empleado* empleadoIn) {
	empleadito = empleadoIn;
}
void PlanillaCortoPlazo::setFechaIngreso(string fechaIn) {
	fechaIngreso = fechaIn;
}
void PlanillaCortoPlazo::setFechaCesantia(string fechaIn) {
	fechaCesantia = fechaIn;
}
void PlanillaCortoPlazo::setCargaSocial(double cargaIn) {
	cargaSocial = cargaIn;
}
void PlanillaCortoPlazo::setAhorroOblig(double ahorroIn) {
	ahorroOblig = ahorroIn;
}
void PlanillaCortoPlazo::setImpRenta(double impIn) {
	impRenta = impIn;
}
void PlanillaCortoPlazo::setSalEsc(double salIn) {
	salEsc = salIn;
}
void PlanillaCortoPlazo::setAhorroNavi(double ahorroIn) {
	ahorroNavi = ahorroIn;
}

bool PlanillaCortoPlazo::tengoPlaza() {
	return false;
}

string PlanillaCortoPlazo::toString() {
	stringstream s;
	s << "{" << endl
		<< "   ID: " << ID << endl
		<< "   Pago quincenal: " << quincenal << endl
		<< "   Empleado: " << empleadito->toString() << endl
		<< "   Fecha de Ingreso: " << fechaIngreso << endl
		<< "   Fecha de Cesantia: " << fechaCesantia << endl
		<< "   Carga Social: " << cargaSocial << endl
		<< "   Ahorro Obligatorio: " << ahorroOblig << endl
		<< "   Impuesto de Renta: " << impRenta << endl
		<< "   Salario Escolar: " << salEsc << endl
		<< "   Ahorro Navideno: " << ahorroNavi << endl
		<< empresita->toString() << endl
		<< "}";
	return s.str();
}