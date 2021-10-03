#include"Controladora.h"
Controladora::Controladora(){}
Controladora::~Controladora() {}
//Control central
void Controladora::control0() {
	string empNom, empDir, empTel;
	int opc;
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
	Empleado* emp;
	string cedula,nombre,apellido1,apellido2,fechaNac,direccion;
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
	opc = Vista::menuOpc2();
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
	ahorroNa=Vista::opc2_2_1();
	salEsc=Vista::opc2_2_2();
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
	ahorroNa = Vista::opc2_2_1();
	salEsc = Vista::opc2_2_2();
	codP=Vista::opc2_2_3();
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
	emp = Vista::crearEmpleado();
	LC->setNodoByCedula(emp, emp->getCedula());
}
void Controladora::control4(Lista<Contrato>*LC){
	cout << LC->toStringEmpleados();
	system("pause");
}
void Controladora::control5(){

}
void Controladora::control6(Lista<Contrato>* LC, Lista<Plaza>* LP, Tiempos* Tiempitos, Empresa* emps) {
	while (LC->empMay3Mes(Tiempitos) != NULL) {
		Vista::opc6(LC, LP, Tiempitos, emps);
	}
}
void Controladora::control7(Lista<Plaza>*LP){
	system("CLS");
	Nodo < Plaza >* NP = NULL;
	int opc;
	opc=Vista::menuOpc7();
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
	Nodo < Plaza >* NP;
	plazita = Vista::crearPlaza();
	NP = new Nodo<Plaza>(plazita, NULL);
	LP->addNodo(NP);
}
void Controladora::control7_3(Lista<Plaza>* LP){
	system("CLS");
	Plaza* plazita;
	plazita = Vista::crearPlaza();
	LP->setNodoByID(plazita);
}
void Controladora::control7_4(Lista<Plaza>* LP){
	int cod;
	cod=Vista::opc7_4();
	LP->Borrar(cod);
}
void Controladora::control8(Lista<Contrato>*LC,Tiempos*Tiempitos){
	Vista::opc8(LC, Tiempitos);
	system("pause");
}
void Controladora::control9(){

}
void Controladora::control10(Tiempos*Tiempitos){
	std::system("cls");
	Tiempitos = Vista::generarTiempos();
}
void Controladora::control12(Lista<Plaza>*LP,Lista<Contrato>*LC,Tiempos*Tiempitos, Empresa* emps){
	std::system("cls");
	Nodo < Contrato >* NC = NULL;
	Nodo < Plaza >* NP = NULL;
	RegistroSalarios RS;
	RegistroContratos RC;
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
	RS.registrarSalario("101110111", true, Tiempitos->getFechaAct(0), Tiempitos->getFechaAct(1)-1, Tiempitos->getFechaAct(2)-1, 0, 0, 0);
	RC.registrarContratoIndef(0, true, plazita, emp, "03/01/2018", " ", 0.09, 0.02, 0.20, 0, 15000, emps);
	emp = new Empleado("104210111", "Matraco", "Codos", "Sucios", "07/03/1998", "40201", 23, "234567");
	PlanillaCP = new PlanillaCortoPlazo(1, true, emp, "26/09/2020", " ", 0.09, 0.02, 0.20, 0, 15000, emps);
	NC = new Nodo<Contrato>(PlanillaCP, NULL);
	LC->addNodo(NC);
	RS.registrarSalario("104210111", true, Tiempitos->getFechaAct(0), Tiempitos->getFechaAct(1)-1, Tiempitos->getFechaAct(2), 0, 0, 0);
	RC.registrarContratoCortoPlazo(0, true, emp, "03/01/2018", " ", 0.09, 0.02, 0.20, 0, 15000, emps);
	emp = new Empleado("104210112", "Carlos", "Corlas", "Colrac", "07/03/1997", "40201", 24, "345678");
	ServPro = new ServicioProfesional(1, true, emp, "26/09/2020", " ", emps);
	NC = new Nodo<Contrato>(ServPro, NULL);
	LC->addNodo(NC);
	RS.registrarSalario("104210112", true, Tiempitos->getFechaAct(0), Tiempitos->getFechaAct(1) - 1, Tiempitos->getFechaAct(2), 0, 0, 0);
	RC.registrarContratoCortoPlazo(0, true, emp, "03/01/2018", " ", 0.09, 0.02, 0.20, 0, 15000, emps);
}