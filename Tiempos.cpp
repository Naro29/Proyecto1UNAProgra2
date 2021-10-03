#include"Tiempos.h"

Tiempos::Tiempos() {
	time_t t = time(NULL);//Creacion de objetos de tiempo
	tm* tiempito = new tm;
	localtime_s(tiempito, &t);//Obtiene la fecha actual
	fechaAct[0] = (tiempito->tm_year) + 1900;
	fechaAct[1] = tiempito->tm_mon + 1;
	fechaAct[2] = tiempito->tm_mday;
	fechaQuin = 0;
	fechaFMes = 0;
}
Tiempos::Tiempos(int fQIn, int fFMIn) {
	time_t t = time(NULL);
	tm* tiempito = new tm;
	localtime_s(tiempito, &t);
	fechaAct[0] = (tiempito->tm_year) + 1900;
	fechaAct[1] = tiempito->tm_mon + 1;
	fechaAct[2] = tiempito->tm_mday;
	fechaQuin = fQIn;
	fechaFMes = fFMIn;
}
Tiempos::~Tiempos() {}

int Tiempos::getFechaAct(int posIn) {
	return fechaAct[posIn];
}
int Tiempos::getFechaQuin() {
	return fechaQuin;
}
int Tiempos::getFechaFMes() {
	return fechaFMes;
}

void Tiempos::setFechaAct(int* fAIn) {
	for (int i = 0; i < 2; i++) {
		fechaAct[i] = fAIn[i];
	}
}
void Tiempos::setFechaQuin(int fqIn) {
	fechaQuin = fqIn;
}
void Tiempos::setFechaFMes(int fFMIn) {
	fechaFMes = fFMIn;
}

int Tiempos::diasTrabDesUltPag(string cedula) {
	int mes = 0, dias = 0;
	int* datoIn;
	RegistroSalarios consult;

	datoIn = consult.leerUltSalario(cedula); //Recibimos [mes] y [dia]

	mes = fechaAct[1] - datoIn[0];

	if (mes == 1) {//El ultimo pago fue el mes anterior
		if (datoIn[0] == 1 || datoIn[0] == 3 || datoIn[0] == 5 || datoIn[0] == 7 || datoIn[0] == 8 || datoIn[0] == 10 || datoIn[0] == 12) {//El mes tendra 31 dias?
			dias = dias + (31 - datoIn[1]);//Sumamos los dias del mes anterior
		}
		if (datoIn[0] == 2) {//El mes tendra 28 dias?
			dias = dias + (28 - datoIn[1]);//Sumamos los dias del mes anterior
		}
		if (datoIn[0] == 4 || datoIn[0] == 6 || datoIn[0] == 9 || datoIn[0] == 11) {//El mes tendra 30 dias?
			dias = dias + (30 - datoIn[1]);//Sumamos los dias del mes anterior
		}

		dias = dias + fechaAct[2];//Sumamos los dias del mes actual
	}

	if (mes == 0) {//El ultimo pago fue este mismo mes
		dias = dias + (fechaAct[2] - datoIn[1]);
	}
	return dias;
}
int Tiempos::mesesTrab(int entradita[3]) {
	int meses=0;
	bool vuelta = true;
	if ((fechaAct[0] - entradita[0]) != 0) {//Anos diferentes
		do {
			meses++;
			entradita[1]++;
			if (entradita[1] == 13) {// Si ya paso de diciembre, pasa a enero
				entradita[1] = 1;
				vuelta = false;// Paso el año, ya puede salirse del ciclo
			}
		} while (fechaAct[1] != entradita[1] || vuelta);
		if (entradita[2] > fechaAct[2])// Para saber si paso un mes completo o unos pocos dias menos
			meses--;//Entonces uno menos
	}
	else {//Mismo ano
		while (fechaAct[1] != entradita[1]) {//Mismo algoritmo solo que no debe de haber una verificacion de que paso un año
			meses++;
			entradita[1]++;
		}
		if (entradita[2] > fechaAct[2])
			meses--;
	}
	return meses;
}