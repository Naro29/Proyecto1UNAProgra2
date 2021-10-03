#pragma once
#include<iostream>
#include<sstream>
#include"Contrato.h"
using namespace std;

class ServicioProfesional :public Contrato {
public:
	ServicioProfesional();
	ServicioProfesional(int, bool, Empleado*, string, string, Empresa*);
	virtual ~ServicioProfesional();

	virtual int getID();
	virtual Empleado* getEmpleado();
	virtual string getFechaIngreso();
	virtual string getFechaCesantia();
	virtual double getCargaSocial();
	virtual double getAhorroOblig();
	virtual double getImpRenta();
	virtual double getSalEsc();
	virtual double getAhorroNavi();

	virtual void setID(int);
	virtual void setEmpleado(Empleado*);
	virtual void setFechaIngreso(string);
	virtual void setFechaCesantia(string);

	virtual bool tengoPlaza();

	virtual string toString();
};