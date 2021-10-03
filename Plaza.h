#pragma once
#include<string>
#include<sstream>
using namespace std;

class Plaza {
private:
	double salarioBase;
	int ID;
	string descripcion;
public:
	Plaza(double, int, string);
	virtual ~Plaza();

	double getSalarioBase();
	int getID();
	string getDescripcion();

	void setSalarioBase(double);
	void setID(int);
	void setDescripcion(string);

	string toString();
};