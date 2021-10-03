#include "Empresa.h"

Empresa::Empresa(){
	empNom = " ";
	empDir = " ";
	empTel = " ";
}
Empresa::Empresa(string empNomIn, string empDirIn, string empTelIn){
	empNom = empNomIn;
	empDir = empDirIn;
	empTel = empTelIn;
}
Empresa::~Empresa(){

}
string Empresa::getEmpNom() {
	return empNom;
}
string Empresa::getEmpDir() {
	return empDir;
}
string Empresa::getEmpTel() {
	return empTel;
}
void Empresa::setEmpNom(string empNomIn) {
	empNom = empNomIn;
}
void Empresa::setEmpDir(string empDirIn) {
	empDir = empDirIn;
}
void Empresa::setEmpTel(string empTelIn) {
	empTel = empTelIn;
}

string Empresa::toString(){
	stringstream s;
	s << "Nombre de la empresa: " << empNom << endl;
	s << "Direcion de la empresa: " << empDir << endl;
	s << "Telefono de la empresa: " << empTel << endl;
	return s.str();
}
