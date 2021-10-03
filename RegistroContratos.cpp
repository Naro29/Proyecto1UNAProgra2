#include"RegistroContratos.h"
#include"Plaza.h"
void RegistroContratos::registrarContrato(int IDIn, bool quinIn, Empleado* eIn, string fIIn, string fCIn, Empresa* emps) {
	ofstream f;
	f.open("RContratos.txt", std::ios_base::app);
	if (f.fail()) {
		exit(1);
	}
	else {//Este es el orden en que se guardan las variables
		f << endl;
		f << IDIn
			<< "," << quinIn
			<< "," << eIn->getCedula()
			<< "," << eIn->getNombre()
			<< "," << eIn->getApellido1()
			<< "," << eIn->getApellido2()
			<< "," << eIn->getFechNac()
			<< "," << eIn->getDireccion()
			<< "," << eIn->getEdad()
			<< "," << eIn->getTelefono()
			<< "," << fIIn
			<< "," << fCIn
			<< "," << emps->getEmpNom()
			<< "," << emps->getEmpDir()
			<< "," << emps->getEmpTel();
	}
	f.close();
}
void RegistroContratos::registrarContratoCortoPlazo(int IDIn, bool quinIn, Empleado* eIn, string fIIn, string fCIn, double cSIn, double aOIn, double iRIn, double sEIn, double aNIn, Empresa* emps){
	ofstream f;
	f.open("RContratos.txt", std::ios_base::app);
	if (f.fail()) {
		exit(1);
	}
	else {//Este es el orden en que se guardan las variables
		f << endl;
		f << IDIn
			<< "," << quinIn
			<< "," << eIn->getCedula()
			<< "," << eIn->getNombre()
			<< "," << eIn->getApellido1()
			<< "," << eIn->getApellido2()
			<< "," << eIn->getFechNac()
			<< "," << eIn->getDireccion()
			<< "," << eIn->getEdad()
			<< "," << eIn->getTelefono()
			<< "," << fIIn
			<< "," << fCIn
			<< "," << cSIn
			<< "," << aOIn
			<< "," << iRIn
			<< "," << sEIn
			<< "," << aNIn
			<< "," << emps->getEmpNom()
			<< "," << emps->getEmpDir()
			<< "," << emps->getEmpTel();
	}
	f.close();
}
void RegistroContratos::registrarContratoIndef(int IDIn, bool quinIn, Plaza* pIn, Empleado* eIn, string fIIn, string fCIn, double cSIn, double aOIn, double iRIn, double sEIn, double aNIn, Empresa* emps){
	ofstream f;
	f.open("RContratos.txt", std::ios_base::app);
	if (f.fail()) {
		exit(1);
	}
	else {//Este es el orden en que se guardan las variables
		f << endl;
		f << IDIn
			<< "," << quinIn
			<< "," <<pIn->getSalarioBase()
			<< "," << pIn->getID()
			<< "," << pIn->getDescripcion()
			<< "," << eIn->getCedula()
			<< "," << eIn->getNombre()
			<< "," << eIn->getApellido1()
			<< "," << eIn->getApellido2()
			<< "," << eIn->getFechNac()
			<< "," << eIn->getDireccion()
			<< "," << eIn->getEdad()
			<< "," << eIn->getTelefono()
			<< "," << fIIn
			<< "," << fCIn
			<< "," << cSIn
			<< "," << aOIn
			<< "," << iRIn
			<< "," << sEIn
			<< "," << aNIn
			<< "," << emps->getEmpNom()
			<< "," << emps->getEmpDir()
			<< "," << emps->getEmpTel();
	}
	f.close();
}
