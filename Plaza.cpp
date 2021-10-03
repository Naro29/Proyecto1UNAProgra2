#include"Plaza.h"
using namespace std;

Plaza::Plaza(double salBasIn, int codIn, string descIn) {
	salarioBase = salBasIn;
	ID = codIn;
	descripcion = descIn;
}

Plaza::~Plaza() {
}

double Plaza::getSalarioBase() {
	return salarioBase;
}
int Plaza::getID() {
	return ID;
}
string Plaza::getDescripcion() {
	return descripcion;
}

void Plaza::setSalarioBase(double salBasIn) {
	salarioBase = salBasIn;
}
void Plaza::setID(int codIn) {
	ID = codIn;
}
void Plaza::setDescripcion(string descIn) {
	descripcion = descIn;
}

string Plaza::toString() {
	stringstream s;
	s << " {Codigo: " << ID << ", Descripcion: " << descripcion << ", Salario Base: " << salarioBase << "} ";
	return s.str();
}