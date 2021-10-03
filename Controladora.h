#pragma once
#include<iostream>
#include"Contrato.h"
#include"ServicioProfesional.h"
#include"PlanillaCortoPlazo.h"
#include"PlanillaIndef.h"
#include"Empleado.h"
#include"Lista.h"
#include"Nodo.h"
#include"Tiempos.h"
#include"Vista.h"
#include "RegistroContratos.h"

class Controladora {
public:
	Controladora();
	~Controladora();
	//Control central
	void control0();
	//Opciones
	void control1(Empresa*);
	void control2(Lista<Contrato>*, Lista<Plaza>*, Tiempos*, Empresa*);
	void control2_1(Lista<Contrato>*, bool, Empleado* , string , Empresa* );
	void control2_2(Lista<Contrato>*, bool, Empleado*, string, Empresa*);
	void control2_3(Lista<Contrato>*, Lista<Plaza>*, bool, Empleado*, string, Empresa*);
	void control3(Lista<Contrato>*);
	void control4(Lista<Contrato>*);
	void control5();
	void control6(Lista<Contrato>*, Lista<Plaza>*, Tiempos*,Empresa*);
	void control7(Lista<Plaza>*);
	void control7_1(Lista<Plaza>*);
	void control7_2(Lista<Plaza>*);
	void control7_3(Lista<Plaza>*);
	void control7_4(Lista<Plaza>*);
	void control8(Lista<Contrato>*, Tiempos*);
	void control9();
	void control10(Tiempos*);
	void control12(Lista<Plaza>*, Lista<Contrato>*, Tiempos*,Empresa*);

};