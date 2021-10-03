#pragma once
#include<string>
#include<fstream>
#include"Tiempos.h"
#include"Empleado.h"
#include"Empresa.h"
#include"Plaza.h"
using namespace std;

class RegistroContratos{
public:
	void registrarContrato(int, bool, Empleado*, string, string, Empresa*);
	void registrarContratoCortoPlazo(int, bool, Empleado*, string, string, double, double, double, double, double, Empresa*);
	void registrarContratoIndef(int, bool, Plaza*, Empleado*, string, string, double, double, double, double, double, Empresa*);

};