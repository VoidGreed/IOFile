#include <iostream>
#include <fstream>
using namespace std;
const int max_string = 10;
const int MAX_NAME = 256;
const int max_studenti = 100;

struct studente {
	char nome[max_string];
	char cognome[max_string];
	int matr;
	void input(); // input da utente
	bool input(fstream& in); // input da file
	void output(ofstream& out);
	// output su file/schermo
};

void studente::input()
{
	
}
bool studente::input(fstream& in)
{
	char str[max_string];
	if (in.getline(str, max_string, ','))
		strcpy_s(nome, str);
	else return false;
	if (in.getline(str, max_string, ','))
		strcpy_s(cognome, str);
	else return false;
	if (in.getline(str, max_string))
		matr = atoi(str);
	else return false;
	return true;
}

void studente::output(ofstream& out)
{
	out << endl;
	out << nome << ",";
	out << cognome << ",";
	out << matr;
	return;
}



int main45()
{
	studente elenco_studenti[max_studenti];
	char filename[MAX_NAME];
	char filename2[MAX_NAME];
	int count;
	studente s;
	fstream file;
	ofstream file2;

	cout << endl << "digitare il nome del file: " << endl;
	cin.getline(filename, MAX_NAME);


	cout << endl << "digitare il nome del file2: " << endl;
	cin.getline(filename2, MAX_NAME);

	file.open(filename);

	if (!file)
	{
		cout << "Impossibile aprire il file "<<filename;
		exit(EXIT_FAILURE);
	}
	
	count = 0;

	while (elenco_studenti[count].input(file))
		count++;

	cout << "sono stati caricati " << count << "studenti ";
	file2.open("ciao.txt");
	s.output(file2);
	file2.close();
	file.close();
	return 0;
}