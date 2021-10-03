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
Tiempos* Vista::generarTiempos(){
	int tM;
	int tQ;
	cout << "Dia de pago quincenal: " << endl;
	cin >> tQ;
	cout << "Dia de pago mensual: " << endl;
	cin >> tM;
	return new Tiempos(tQ, tM);;
}

Plaza* Vista::crearPlaza() {
	Plaza* plazita;
	int cod;
	double salBas;
	string desc;
	cout << "Digite el codigo de la plaza: ";
	cin >> cod;
	cout << "Digite la descripcion de la plaza:";
	cin >> desc;
	cout << "Digite el salario base de la plaza: ";
	cin >> salBas;
	plazita = new Plaza(salBas, cod, desc);
	return plazita;
}

int Vista::menuPrincipal(){
	system("cls");
	int opc;
	cout << "----------------- MENU -------------------" << endl
		<< "1 -Cambiar info de la empresa." << endl
		<< "2 -Registrar contrato." << endl
		<< "3 -Actualizacion de los empleados" << endl
		<< "4 -Consulta de la lista de empleados" << endl
		<< "5 -Cambio manual de la modalidad de contrato" << endl
		<< "6 -Cambio automatico de la modalidad de contratos" << endl
		<< "7 -Mantenimiento de plazas y salarios" << endl
		<< "8 -Calculo de salario neto para cada empleado" << endl
		<< "9 -Cese de empleado" << endl
		<< "10-Cambio de fecha de pago" << endl
		<< "11-Salir" << endl
		<< "12-Ingresar plazas y contratos predeterminados, ademas de crear un registro de pagos y contratos predeterminados desde cero." << endl;
	cin >> opc;
	system("cls");
    return opc;
}

int Vista::menuOpc2(){
	int opc;
	cout << "Tipo de contrato: " << endl
		<< "1-Servicio profesional" << endl
		<< "2-Planilla de corto plazo" << endl
		<< "3- Planilla de tiempo indefinido" << endl;
	cin >> opc;
	return opc;
}
double Vista::opc2_2_1() {
	double temp;
	cout << "Ingrese el monto que desea ahorrar: ";
	cin >> temp;
	return temp;
}
double Vista::opc2_2_2() {
	double temp;
	cout << "Ingrese el salario escolar: ";
	cin >> temp;
	return temp;
}
int Vista::opc2_2_3() {
	int temp;
	cout << "Ingrese el codigo de plaza: ";
	cin >> temp;
	return temp;
}

void Vista::opc6(Lista<Contrato>* LC, Lista<Plaza>* LP, Tiempos* Tiempitos, Empresa* emps) {
	Contrato* contratito;
	PlanillaIndef* PlanillaI;
	Plaza* plazita;
	int IDPlaza;
	double salEsc;
	double ahorroNa;
	contratito = LC->empMay3Mes(Tiempitos);
	cout << "Contrato a actualizar: " << endl;
	cout << contratito->toString();
	cout << "Ingrese el monto que desea ahorrar: ";
	cin >> ahorroNa;
	cout << "Ingrese el salario escolar: ";
	cin >> salEsc;
	cout << "Ingrese el codigo de plaza: ";
	cin >> IDPlaza;
	plazita = LP->getNodo(IDPlaza)->getItem();
	PlanillaI = new PlanillaIndef(contratito->getID(), contratito->getQuincenal(), plazita, contratito->getEmpleado(), contratito->getFechaIngreso(), " ", 0.09, 0.02, 0.20, salEsc, ahorroNa, emps);
	LC->setNodoByID(PlanillaI);
}

int Vista::menuOpc7() {
	int opc;
	cout << "1 - Mostrar plazas." << endl
		<< "2 - Agregar plaza." << endl
		<< "3 - Editar plaza." << endl
		<< "4 - Eliminar plaza por ID." << endl;
	cin >> opc;
	return opc;
}
int Vista::opc7_4() {
	int cod;
	cout << "Digite el codigo de la plaza a eliminar: ";
	cin >> cod;
	return cod;
}

void Vista::opc8(Lista<Contrato>* LC, Tiempos* Tiempitos) {
	if (Tiempitos->getFechaQuin() == Tiempitos->getFechaAct(2)) {
		cout << "Hoy es pago de quincena, se mostraran los empleados que tengan el pago por quincena: " << endl;
		cout << LC->toStringSalarios(Tiempitos);
	}
	else if (Tiempitos->getFechaFMes() == Tiempitos->getFechaAct(2)) {
		cout << "Hoy es pago de fin de mes, se mostraran los empleados que tengan el pago por fin de mes: " << endl;
		cout << LC->toStringSalarios(Tiempitos);
	}
	else {
		cout << "Hoy no es pago de quincena ni de fin de mes." << endl;
		cout << "No se procedera a hacer ningun pago." << endl;
	}

}