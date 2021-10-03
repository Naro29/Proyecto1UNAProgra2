#include"Empleado.h"

Empleado::Empleado() {
	cedula = " ";
	nombre = " ";
	apellido1 = " ";
	apellido2 = " ";
	fechaNac = " ";
	direccion = " ";
	edad = 0;
	telefono = " ";
}
Empleado::Empleado(string cIn, string nIn, string a1In, string a2In, string fNIn, string dIn, int eIn, string tIn) {
	cedula = cIn;
	nombre = nIn;
	apellido1 = a1In;
	apellido2 = a2In;
	fechaNac = fNIn;
	direccion = dIn;
	edad = eIn;
	telefono = tIn;
}
Empleado::~Empleado() {}

string Empleado::getCedula() {
	return cedula;
}
string Empleado::getNombre() {
	return nombre;
}
string Empleado::getApellido1() {
	return apellido1;
}
string Empleado::getApellido2() {
	return apellido2;
}
string Empleado::getFechNac() {
	return fechaNac;
}
string Empleado::getDireccion() {
	return direccion;
}
int Empleado::getEdad() {
	return edad;
}
string Empleado::getTelefono() {
	return telefono;
}

void Empleado::setCedula(string cIn) {
	cedula = cIn;
}
void Empleado::setNombre(string nIn) {
	nombre = nIn;
}
void Empleado::setApellido1(string a1In) {
	apellido1 = a1In;
}
void Empleado::setApellido2(string a2In) {
	apellido2 = a2In;
}
void Empleado::setfechNac(string fNIn) {
	fechaNac = fNIn;
}
void Empleado::setDireccion(string dIn) {
	direccion = dIn;
}
void Empleado::setEdad(int eIn) {
	edad = eIn;
}
void Empleado::setTelefono(string tIn) {
	telefono = tIn;
}

string Empleado::toString() {
	stringstream s;
	s << " {Cedula: " << cedula << ", Nombre: " << nombre << ",  " << apellido1 << ",  " << apellido2 << ", Fecha de nacimiento: " << fechaNac << ", Direccion: " << direccion << ", Edad: " << edad << ", Telefono: " << telefono << "} ";
	return s.str();
}