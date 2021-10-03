#include"Contrato.h"

Contrato::Contrato() {
	ID = 0;
	empleadito = NULL;
	fechaIngreso = " ";
	fechaCesantia = " ";
}
Contrato::Contrato(int IDIn, bool quinIn, Empleado* eIn, string fIIn, string fCIn, Empresa* emps) {
	ID = IDIn;
	quincenal = quinIn;
	empleadito = eIn;
	fechaIngreso = fIIn;
	fechaCesantia = fCIn;
	empresita = emps;
}
Contrato::~Contrato() {}

int Contrato::getID() {
	return ID;
}
bool Contrato::getQuincenal() {
	return quincenal;
}
Empleado* Contrato::getEmpleado() {
	return empleadito;
}
string Contrato::getFechaIngreso() {
	return fechaIngreso;
}
string Contrato::getFechaCesantia() {
	return fechaCesantia;
}
Empresa* Contrato::getEmpresita(){
	return empresita;
}
double Contrato::getSalarioBase() {
	return 410000.00;
}
double Contrato::getCargaSocial() {
	return 0;
}
double Contrato::getAhorroOblig() {
	return 0;
}
double Contrato::getImpRenta() {
	return 0;
}
double Contrato::getSalEsc() {
	return 0;
}
double Contrato::getAhorroNavi() {
	return 0;
}

void Contrato::setID(int IDIn) {
	ID = IDIn;
}
void Contrato::setQuincenal(bool qIn) {
	quincenal = qIn;
}
void Contrato::setEmpleado(Empleado* empleadoIn) {
	empleadito = empleadoIn;
}
void Contrato::setFechaIngreso(string fechaIn) {
	fechaIngreso = fechaIn;
}
void Contrato::setFechaCesantia(string fechaIn) {
	fechaCesantia = fechaIn;
}

void Contrato::setEmpresita(Empresa* emps){
	empresita = emps;
}

bool Contrato::tengoPlaza() {
	return false;
}

string Contrato::toString() {
	stringstream s;
	s << "   ID: " << ID << endl;
	s << "   Pago quincenal: " << quincenal << endl;
	s << "   Empleado: " << empleadito->toString() << endl;
	s << "   Fecha de Ingreso: " << fechaIngreso << endl;
	s << "   Fecha de Cesantia: " << fechaCesantia << endl;
	return s.str();
}