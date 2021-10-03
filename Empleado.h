#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Empleado {
private:
	string cedula;
	string nombre;
	string apellido1;
	string apellido2;
	string fechaNac;
	string direccion;
	int edad;
	string telefono;
public:
	Empleado();
	Empleado(string, string, string, string, string, string, int, string);
	virtual ~Empleado();

	string getCedula();
	string getNombre();
	string getApellido1();
	string getApellido2();
	string getFechNac();
	string getDireccion();
	int getEdad();
	string getTelefono();

	void setCedula(string);
	void setNombre(string);
	void setApellido1(string);
	void setApellido2(string);
	void setfechNac(string);
	void setDireccion(string);
	void setEdad(int);
	void setTelefono(string);

	string toString();
};