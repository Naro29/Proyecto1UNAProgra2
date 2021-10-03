#pragma once
#pragma once
#include "Lista.h"
#include "Contrato.h"
#include"PlanillaIndef.h"

class Vista {
public:
	static Empresa* crearEmpresa();
	static Empleado* crearEmpleado();
	static Tiempos* generarTiempos();
	static Plaza* crearPlaza();

	static int menuPrincipal();

	static int menuOpc2();
	static double opc2_2_1();
	static double opc2_2_2();
	static int opc2_2_3();

	static void opc6(Lista<Contrato>* , Lista<Plaza>* , Tiempos* , Empresa* );

	static int menuOpc7();
	static int opc7_4();

	static void opc8(Lista<Contrato>*, Tiempos*);
	
};