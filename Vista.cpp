#include "Vista.h"

Empresa* Vista::crearEmpresa()
{
	string empNom, empDir, empTel;
	cout << "Nombre de la empresa: " << endl;
	getline(cin, empNom);
	cout << "Direccion de la empresa: " << endl;
	getline(cin, empDir);
	cout << "Telefono de la empresa: " << endl;
	getline(cin, empTel);
	cin.ignore();
	return new Empresa(empNom, empDir, empTel);
}

Tiempos* Vista::generarTiempos(){
	int tM;
	int tQ;
	cout << "Dia de pago quincenal: " << endl;
	cin >> tQ;
	cout << "Dia de pago mensual: " << endl;
	cin >> tM;
	return new Tiempos(tQ, tM);;
}

int Vista::menuPrincipal(){
	system("cls");
	int opc;
	cout << "----------------- MENU -------------------" << endl
		<< "1 -Cambiar info de la empresa." << endl						//Hecho
		<< "2 -Registrar contrato." << endl								//Hecho
		<< "3 -Actualizar datos de la empresa" << endl					//Hecho
		<< "4 -Actualizacion de los empleados" << endl
		<< "5 -Consulta de la lista de empleados" << endl				//Hecho
		<< "6 -Cambio manual de la modalidad de contrato" << endl
		<< "7 -Cambio automatico de la modalidad de contratos" << endl
		<< "8 -Mantenimiento de plazas" << endl
		<< "9 -Modificacion de salarios" << endl
		<< "10-Calculo de salario neto para cada empleado" << endl
		<< "11-Cese de empleado" << endl
		<< "12-Cambio de fecha de pago" << endl							//Hecho
		<< "13-Salir" << endl											//Hecho
		<< "14-Ingresar plazas y contratos predeterminados, ademas de crear un registro de pagos y contratos predeterminados desde cero." << endl; //Hecho
	cin >> opc;
	system("cls");
    return opc;
}

Empleado* Vista::crearEmpleado() {
	Empleado* emp;
	string cedula, nombre, apellido1, apellido2, fechaNac, direccion;
	int edad;
	string telefono;
	cout << "Datos del empleado" << endl;
	cout << "Ingrese la cedula: ";
	cin >> cedula;
	cout << "Ingrese el nombre: ";
	cin >> nombre;
	cout << "Ingrese el primer apellido: ";
	cin >> apellido1;
	cout << "Ingrese el segundo apellido: ";
	cin >> apellido2;
	cout << "Ingrese la fecha de nacimiento(DD/MM/AAAA): ";
	cin >> fechaNac;
	cout << "Ingrese el codigo postal de donde vive: ";
	cin >> direccion;
	cout << "Ingrese la edad: ";
	cin >> edad;
	cout << "Ingrese el numero de telefono: ";
	cin >> telefono;
	emp = new Empleado(cedula, nombre, apellido1, apellido2, fechaNac, direccion, edad, telefono);
	return emp;
}