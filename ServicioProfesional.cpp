#include"ServicioProfesional.h"

ServicioProfesional::ServicioProfesional() {
	ID = 0;
	empleadito = NULL;
	fechaIngreso = " ";
	fechaCesantia = " ";
}
ServicioProfesional::ServicioProfesional(int IDIn, bool quinIn, Empleado* eIn, string fIIn, string fCIn, Empresa* emps) {
	ID = IDIn;
	quincenal = quinIn;
	empleadito = eIn;
	fechaIngreso = fIIn;
	fechaCesantia = fCIn;
	empresita = emps;
}
ServicioProfesional::~ServicioProfesional() {}

int ServicioProfesional::getID() {
	return ID;
}
Empleado* ServicioProfesional::getEmpleado() {
	return empleadito;
}
string ServicioProfesional::getFechaIngreso() {
	return fechaIngreso;
}
string ServicioProfesional::getFechaCesantia() {
	return fechaCesantia;
}
double ServicioProfesional::getCargaSocial() {
	return 0;
}
double ServicioProfesional::getAhorroOblig(){
	return 0;
}
double ServicioProfesional::getImpRenta(){
	return 0;
}
double ServicioProfesional::getSalEsc(){
	return 0;
}
double ServicioProfesional::getAhorroNavi(){
	return 0;
}

void ServicioProfesional::setID(int IDIn) {
	ID = IDIn;
}
void ServicioProfesional::setEmpleado(Empleado* empleadoIn) {
	empleadito = empleadoIn;
}
void ServicioProfesional::setFechaIngreso(string fechaIn) {
	fechaIngreso = fechaIn;
}
void ServicioProfesional::setFechaCesantia(string fechaIn) {
	fechaCesantia = fechaIn;
}

bool ServicioProfesional::tengoPlaza() {
	return false;
}

string ServicioProfesional::toString() {
	stringstream s;
	s << "{" << endl
		<< "   ID: " << ID << endl
		<< "   Pago quincenal: " << quincenal << endl
		<< "   Empleado: " << empleadito->toString() << endl
		<< "   Fecha de Ingreso: " << fechaIngreso << endl
		<< "   Fecha de Cesantia: " << fechaCesantia << endl
		<<     empresita->toString() << endl
		<< "}";
	return s.str();
}