#pragma once
#include<string>
#include<fstream>
#include"Tiempos.h"
using namespace std;

class RegistroSalarios {
public:
	void registrarSalario(string, bool, int, int, int, double, double, double);
	int* leerUltSalario(string);//Retorna [mes] y [dia] del ultimo pago
};