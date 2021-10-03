#pragma once
#pragma once
#include "Lista.h"
#include "Contrato.h"

class Vista {
public:
	static Empresa* crearEmpresa();
	static Tiempos* generarTiempos();
	static int menuPrincipal();
	static Empleado* crearEmpleado();
};