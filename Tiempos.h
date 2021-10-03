#pragma once
#include<time.h>
#include"RegistroSalarios.h"

using namespace std;
class Tiempos {
private:
	int fechaAct[3];
	int fechaQuin;
	int fechaFMes;
public:
	Tiempos();
	Tiempos(int, int);
	virtual ~Tiempos();

	int getFechaAct(int);
	int getFechaQuin();
	int getFechaFMes();

	void setFechaAct(int*);
	void setFechaQuin(int);
	void setFechaFMes(int);

	int diasTrabDesUltPag(string);
	int mesesTrab(int*);
};