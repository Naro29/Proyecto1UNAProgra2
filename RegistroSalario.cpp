#include"RegistroSalarios.h"

void RegistroSalarios::registrarSalario(string cedIn, bool quinIn, int anoIn, int mesIn, int diaIn, double salBaIn, double salBrIn, double salNeIn) {
	ofstream f;
	f.open("RSalarios.txt", std::ios_base::app);
	if (f.fail()) {
		exit(1);
	}
	else {//Este es el orden en que se guardan las variables
		f << endl;
		f << cedIn
			<< "," << quinIn
			<< "," << anoIn
			<< "," << mesIn
			<< "," << diaIn
			<< "," << salBaIn
			<< "," << salBrIn
			<< "," << salNeIn;
	}
	f.close();
}

int* RegistroSalarios::leerUltSalario(string cedula) {
	string cedIn;
	string squinIn;
	string sanoIn;
	string smesIn;
	string sdiaIn;
	string ssalBaIn;
	string ssalBrIn;
	string ssalNeIn;
	int salida[2];
	for (int i = 0; i < 1; i++) {
		salida[i] = 0;
	}
	ifstream f;
	f.open("RSalarios.txt");
	while (f.eof() == false) {
		getline(f, cedIn, ',');
		getline(f, squinIn, ',');
		getline(f, sanoIn, ',');
		getline(f, smesIn, ',');
		getline(f, sdiaIn, ',');
		getline(f, ssalBaIn, ',');
		getline(f, ssalBrIn, ',');
		getline(f, ssalNeIn, '\n');
		if (cedIn == cedula) {//Si la persona que se esta leyendo tiene esta cedula, se guarda y retorna para su tratado
			salida[0] = stoi(smesIn);
			salida[1] = stoi(sdiaIn);
		}
	}
	f.close();
	return salida;
}