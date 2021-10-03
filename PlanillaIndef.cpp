#include"PlanillaIndef.h"

PlanillaIndef::PlanillaIndef() {
	ID = 0;
	plazita = NULL;
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
PlanillaIndef::PlanillaIndef(int IDIn, bool quinIn, Plaza* pIn, Empleado* eIn, string fIIn, string fCIn, double cSIn, double aOIn, double iRIn, double sEIn, double aNIn, Empresa* emps) {
	ID = IDIn;
	quincenal = quinIn;
	plazita = pIn;
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
PlanillaIndef::~PlanillaIndef() {}

int PlanillaIndef::getID() {
	return ID;
}
Plaza* PlanillaIndef::getPlaza() {
	return plazita;
}
Empleado* PlanillaIndef::getEmpleado() {
	return empleadito;
}
string PlanillaIndef::getFechaIngreso() {
	return fechaIngreso;
}
string PlanillaIndef::getFechaCesantia() {
	return fechaCesantia;
}
double PlanillaIndef::getCargaSocial() {
	return cargaSocial;
}
double PlanillaIndef::getAhorroOblig() {
	return ahorroOblig;
}
double PlanillaIndef::getImpRenta() {
	return impRenta;
}
double PlanillaIndef::getSalEsc() {
	return salEsc;
}
double PlanillaIndef::getAhorroNavi() {
	return ahorroNavi;
}
double PlanillaIndef::getSalarioBase() {
	return plazita->getSalarioBase();
}

void PlanillaIndef::setID(int IDIn) {
	ID = IDIn;
}
void PlanillaIndef::setPlaza(Plaza* plazaIn) {
	plazita = plazaIn;
}
void PlanillaIndef::setEmpleado(Empleado* empleadoIn) {
	empleadito = empleadoIn;
}
void PlanillaIndef::setFechaIngreso(string fechaIn) {
	fechaIngreso = fechaIn;
}
void PlanillaIndef::setFechaCesantia(string fechaIn) {
	fechaCesantia = fechaIn;
}
void PlanillaIndef::setCargaSocial(double cargaIn) {
	cargaSocial = cargaIn;
}
void PlanillaIndef::setAhorroOblig(double ahorroIn) {
	ahorroOblig = ahorroIn;
}
void PlanillaIndef::setImpRenta(double impIn) {
	impRenta = impIn;
}
void PlanillaIndef::setSalEsc(double salIn) {
	salEsc = salIn;
}
void PlanillaIndef::setAhorroNavi(double ahorroIn) {
	ahorroNavi = ahorroIn;
}

bool PlanillaIndef::tengoPlaza() {
	return true;
}

string PlanillaIndef::toString() {
	stringstream s;
	s << "{" << endl
		<< "   ID: " << ID << endl
		<< "   Pago quincenal: " << quincenal << endl
		<< "   Plaza: " << plazita->toString() << endl
		<< "   Empleado: " << empleadito->toString() << endl
		<< "   Fecha de Ingreso: " << fechaIngreso << endl
		<< "   Fecha de Cesantia: " << fechaCesantia << endl
		<< "   Carga Social: " << cargaSocial << endl
		<< "   Ahorro Obligatorio: " << ahorroOblig << endl
		<< "   Impuesto de Renta: " << impRenta << endl
		<< "   Salario Escolar: " << salEsc << endl
		<< "   Ahorro Navideno: " << ahorroNavi << endl
		<<     empresita->toString()<<endl
		<< "}";
	return s.str();
}