#include"Controladora.h"
Controladora::Controladora(){}
Controladora::~Controladora() {}
//Control central
void Controladora::control0() {
	string empNom, empDir, empTel;
	int opc;
	int tM;
	int tQ;
	Tiempos* Tiempitos;
	Lista < Contrato >* LC = new Lista<Contrato>();
	Lista < Plaza >* LP = new Lista<Plaza>();
	Nodo < Contrato >* NC = NULL;
	Nodo < Plaza >* NP = NULL;
	Empresa* emps;
	emps = Vista::crearEmpresa();
	Tiempitos = Vista::generarTiempos();
	do {
		opc=Vista::menuPrincipal();
		switch (opc) {
		case 1:
			control1(emps);
			break;
		case 2: 
			control2(LC,LP,Tiempitos,emps);
			break;
		case 3: 
			control3(LC);
			break;
		case 4:
			control4(LC);
			break;
		case 5:

			break;
		case 6: 
			control6(LC, LP, Tiempitos,emps);
			break;
		case 7:
			control7(LP);
			break;
		case 8: 
			control8(LC, Tiempitos);
			break;
		case 9:

			break;
		case 10:
			control10(Tiempitos);
			break;
		case 12: 
			control12(LP, LC, Tiempitos,emps);
			break;
		}
		std::system("cls");
	} while (opc != 11);

	std::system("pause");
}
//Opciones
void Controladora::control1(Empresa*emps){
	string empNom, empDir, empTel;
	cout << "Direccion de la empresa (formato codigo postal): " << endl;
	cin>>empDir;
	cout << "Telefono de la empresa: " << endl;
	cin>>empTel;
	emps->setEmpDir(empDir);
	emps->setEmpTel(empTel);
}
void Controladora::control2(Lista<Contrato>* LC, Lista<Plaza>* LP,Tiempos*Tiempitos,Empresa* emps){
	std::system("cls");
	RegistroSalarios RS;
	RegistroContratos RC;
	Empleado* emp;
	string cedula,nombre,apellido1,apellido2,fechaNac,direccion;
	int edad;
	string telefono;
	bool quincenal;
	string fechaIngreso,fechaCesantia;
	int opc;

	cout << "Registrar contrato" << endl;
	emp=Vista::crearEmpleado();
	cout << "Requiere el pago quincenal o mensual: (true/false)";
	cin >> quincenal;
	cout << "Ingrese la fecha de ingreso(DD/MM/AAAA): ";
	cin >> fechaIngreso;
	cout << "Tipo de contrato: " << endl
		<< "1-Servicio profesional" << endl
		<< "2-Planilla de corto plazo" << endl
		<< "3- Planilla de tiempo indefinido" << endl;
	cin >> opc;
	switch (opc) {
	case 1:
		control2_1(LC, quincenal,emp,fechaIngreso,emps);
		break;
	case 2:
		control2_2(LC, quincenal,emp,  fechaIngreso,emps);
		break;
	case 3:
		control2_3(LC, LP, quincenal,emp,  fechaIngreso,emps);
		break;
	default:
		cout << "Opcion invalida.";
		break;
	}
	RS.registrarSalario(cedula, quincenal, Tiempitos->getFechaAct(0), Tiempitos->getFechaAct(1), Tiempitos->getFechaAct(2), 0, 0, 0);
}
void Controladora::control2_1(Lista<Contrato>*LC, bool quincenal, Empleado*emp,string fechaIngreso,Empresa*emps){
	Nodo < Contrato >* NC = NULL;
	ServicioProfesional* ServPro;
	ServPro = new ServicioProfesional(0, quincenal, emp, fechaIngreso, " ", emps);
	NC = new Nodo<Contrato>(ServPro, NULL);
	LC->addNodo(NC);
	RegistroContratos RC;
	RC.registrarContrato(0,quincenal,emp,fechaIngreso," ",emps);
}
void Controladora::control2_2(Lista<Contrato>* LC, bool quincenal, Empleado* emp, string fechaIngreso, Empresa* emps){
	Nodo < Contrato >* NC = NULL;
	PlanillaCortoPlazo* PlanillaCP;
	double salEsc, ahorroNa;
	cout << "Ingrese el monto que desea ahorrar: ";
	cin >> ahorroNa;
	cout << "Ingrese el salario escolar: ";
	cin >> salEsc;
	PlanillaCP = new PlanillaCortoPlazo(0, quincenal, emp, fechaIngreso, " ", 0.09, 0.02, 0.20, salEsc, ahorroNa, emps);//Su ID se aplica automaticamente en addNodo()
	NC = new Nodo<Contrato>(PlanillaCP, NULL);
	LC->addNodo(NC);
	RegistroContratos RCC;
	RCC.registrarContratoCortoPlazo(0,quincenal, emp, fechaIngreso, " ", 0.09, 0.02, 0.20, salEsc, ahorroNa, emps);
}
void Controladora::control2_3(Lista<Contrato>* LC, Lista<Plaza>* LP, bool quincenal, Empleado* emp, string fechaIngreso, Empresa* emps){
	Nodo < Contrato >* NC = NULL;
	Plaza* plazita;
	PlanillaIndef* PlanillaI;
	double salEsc, ahorroNa;
	int codP;
	cout << "Ingrese el monto que desea ahorrar: ";
	cin >> ahorroNa;
	cout << "Ingrese el salario escolar: ";
	cin >> salEsc;
	cout << "Ingrese el codigo de plaza: ";
	cin >> codP;
	plazita = LP->getNodo(codP)->getItem();
	PlanillaI = new PlanillaIndef(0, quincenal, plazita, emp, fechaIngreso, " ", 0.09, 0.02, 0.20, salEsc, ahorroNa, emps);//Su ID se aplica automaticamente en addNodo()
	NC = new Nodo<Contrato>(PlanillaI, NULL);
	LC->addNodo(NC);
	RegistroContratos RCI;
	RCI.registrarContratoIndef(0, quincenal, plazita, emp, fechaIngreso, " ", 0.09, 0.02, 0.20, salEsc, ahorroNa, emps);
}
void Controladora::control3(Lista<Contrato>*LC){
	std::system("cls");
	Empleado* emp;
	string cedula;
	string nombre;
	string apellido1;
	string apellido2;
	string fechaNac;
	string direccion;
	int edad;
	string telefono;

	cout << "Ingrese la cedula del empleado: ";
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
	LC->setNodoByCedula(emp, cedula);
}
void Controladora::control4(Lista<Contrato>*LC){
	cout << LC->toStringEmpleados();
	system("pause");
}
void Controladora::control5(){

}
void Controladora::control6(Lista<Contrato>*LC,Lista<Plaza>*LP,Tiempos*Tiempitos,Empresa*emps){
	Contrato* contratito;
	PlanillaIndef* PlanillaI;
	Plaza* plazita;
	int IDPlaza;
	double salEsc;
	double ahorroNa;
	while (LC->empMay3Mes(Tiempitos) != NULL) {
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
}
void Controladora::control7(Lista<Plaza>*LP){
	system("CLS");
	Nodo < Plaza >* NP = NULL;
	int opc;
	cout << "1 - Mostrar plazas." << endl
		<< "2 - Agregar plaza." << endl
		<< "3 - Editar plaza." << endl
		<< "4 - Eliminar plaza por ID." << endl;
	cin >> opc;
	switch (opc) {
	case 1:
		control7_1(LP);
		break;
	case 2: {
		control7_2(LP);
		break;
	}
	case 3:
		control7_3(LP);
		break;
	case 4: 
		control7_4(LP);
		break;
	}
}
void Controladora::control7_1(Lista<Plaza>* LP){
	system("CLS");
	cout << LP->toString() << endl;
	system("pause");
}
void Controladora::control7_2(Lista<Plaza>* LP){
	system("CLS");
	Plaza* plazita;
	Nodo < Plaza >* NP = NULL;
	double salBas;
	int cod;
	string desc;
	cout << "Digite la descripcion de la plaza:";
	cin >> desc;
	cout << "Digite el codigo de la plaza: ";
	cin >> cod;
	cout << "Digite el salario base de la plaza: ";
	cin >> salBas;
	plazita = new Plaza(salBas, cod, desc);
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);
}
void Controladora::control7_3(Lista<Plaza>* LP){
	system("CLS");
	Plaza* plazita;
	int cod;
	double salBas;
	string desc;
	cout << "Digite el codigo de la plaza a editar: ";
	cin >> cod;
	cout << "Digite la descripcion de la plaza:";
	cin >> desc;
	cout << "Digite el salario base de la plaza: ";
	cin >> salBas;
	plazita = new Plaza(salBas, cod, desc);
	LP->setNodoByID(plazita);
}
void Controladora::control7_4(Lista<Plaza>* LP){
	int cod;
	cout << "Digite el codigo de la plaza a eliminar: ";
	cin >> cod;
	LP->Borrar(cod);
}
void Controladora::control8(Lista<Contrato>*LC,Tiempos*Tiempitos){
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

	system("pause");
}
void Controladora::control9(){

}
void Controladora::control10(Tiempos*Tiempitos){
	int tM, tQ;
	std::system("cls");
	cout << "Dia de pago quincenal: " << endl;
	cin >> tQ;
	cout << "Dia de pago mensual: " << endl;
	cin >> tM;
	Tiempitos = new Tiempos(tQ, tM);
}
void Controladora::control12(Lista<Plaza>*LP,Lista<Contrato>*LC,Tiempos*Tiempitos, Empresa* emps){
	std::system("cls");
	Nodo < Contrato >* NC = NULL;
	Nodo < Plaza >* NP = NULL;
	RegistroSalarios RS;
	ServicioProfesional* ServPro;
	PlanillaCortoPlazo* PlanillaCP;
	PlanillaIndef* PlanillaI;
	Empleado* emp;
	Plaza* plazita;
	plazita = new Plaza(462200.00, 0, "Oficinista");
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);
	plazita = new Plaza(602683.38, 1, "Programador clase 1");
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);
	plazita = new Plaza(120625.23, 2, "Asistente de mantenimiento");
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);
	plazita = new Plaza(768135.53, 3, "Gerente de mantenimiento");
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);
	plazita = new Plaza(698326.38, 4, "Contador privado licenciado");
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);
	plazita = new Plaza(602683.03, 5, "Programador clase 2");
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);
	plazita = new Plaza(583624.68, 6, "Secretario");
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);
	plazita = new Plaza(368175.29, 7, "Monitor de camaras");
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);
	plazita = new Plaza(368175.29, 8, "Guarda");
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);

	emp = new Empleado("101110111", "Pedro", "Quijada", "Blaca", "05/03/1990", "50201", 31, "123456");
	PlanillaI = new PlanillaIndef(0, true, plazita, emp, "03/01/2018", " ", 0.09, 0.02, 0.20, 0, 15000, emps);
	NC = new Nodo<Contrato>(PlanillaI, NULL);
	LC->addNodo(NC);
	RS.registrarSalario("101110111", true, Tiempitos->getFechaAct(0), Tiempitos->getFechaAct(1), Tiempitos->getFechaAct(2), 0, 0, 0);
	emp = new Empleado("104210111", "Matraco", "Codos", "Sucios", "07/03/1998", "40201", 23, "234567");
	PlanillaCP = new PlanillaCortoPlazo(1, true, emp, "26/09/2020", " ", 0.09, 0.02, 0.20, 0, 15000, emps);
	NC = new Nodo<Contrato>(PlanillaCP, NULL);
	LC->addNodo(NC);
	RS.registrarSalario("104210111", true, Tiempitos->getFechaAct(0), Tiempitos->getFechaAct(1), Tiempitos->getFechaAct(2), 0, 0, 0);
}