#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Empresa {//Agregar nombre y numero de empresa
protected:
	string empNom;
	string empDir;
	string empTel;
public:
	Empresa();
	Empresa(string, string, string);
	virtual ~Empresa();
	virtual string getEmpNom();
	virtual string getEmpDir();
	virtual string getEmpTel();
	virtual void setEmpNom(string);
	virtual void setEmpDir(string);
	virtual void setEmpTel(string);
	string toString();
};