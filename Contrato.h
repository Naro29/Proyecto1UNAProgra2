#pragma once
#include"Empleado.h"
#include"Plaza.h"
#include "Empresa.h"
class Contrato {//Agregar nombre y numero de empresa
protected:
	int ID;
	bool quincenal;
	Empleado* empleadito;
	string fechaIngreso;
	string fechaCesantia;
	Empresa* empresita;
public:
	Contrato();
	Contrato(int,bool , Empleado*, string, string, Empresa*);
	virtual ~Contrato();

	virtual int getID();
	virtual bool getQuincenal();
	virtual Empleado* getEmpleado();
	virtual string getFechaIngreso();
	virtual string getFechaCesantia();
	virtual Empresa* getEmpresita();
	virtual double getSalarioBase();
	virtual double getCargaSocial();
	virtual double getAhorroOblig();
	virtual double getImpRenta();
	virtual double getSalEsc();
	virtual double getAhorroNavi();

	virtual void setID(int);
	virtual void setQuincenal(bool);
	virtual void setEmpleado(Empleado*);
	virtual void setFechaIngreso(string);
	virtual void setFechaCesantia(string);
	virtual void setEmpresita(Empresa*);

	virtual bool tengoPlaza();

	virtual string toString();
};