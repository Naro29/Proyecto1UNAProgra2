#pragma once
#include"Contrato.h"

class PlanillaCortoPlazo :public Contrato {
private:
	double cargaSocial;
	double ahorroOblig;
	double impRenta;
	double salEsc;
	double ahorroNavi;
public:
	PlanillaCortoPlazo();
	PlanillaCortoPlazo(int, bool, Empleado*, string, string, double, double, double, double, double, Empresa*);
	virtual ~PlanillaCortoPlazo();

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
	virtual void setCargaSocial(double);
	virtual void setAhorroOblig(double);
	virtual void setImpRenta(double);
	virtual void setSalEsc(double);
	virtual void setAhorroNavi(double);

	virtual bool tengoPlaza();

	virtual string toString();
};