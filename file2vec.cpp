#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

const char src[] = "C:/Users/Cnome/source/repos/fondamentiInformatica/prova_file/prova_file/ciao.txt";
const char sium[] = "C:/Users/Cnome/source/repos/fondamentiInformatica/prova_file/prova_file/sium.txt";
const int MAX_NAME = 256;
const int MAX_LINE = 1000;

void file2vec(ifstream& in, int v[], int& n, char delim)
{
	char str[MAX_LINE];
	n = 0;
	while (in.getline(str, MAX_LINE, delim))
		v[n++] = atoi(str); //string -> int
}
void file2vec(fstream& in, float v[], int& n, char delim)
{
	char str[MAX_LINE];
	n = 0;
	while (in.getline(str, MAX_LINE, delim))
		v[n++] = atof(str); // string -> float
}
int main1()
{
	ifstream instream;

	char file_name[MAX_NAME], line[MAX_LINE], str[MAX_LINE];
	bool found;
	int v[10], n;
	char delim = '-';
	cout << endl << "digitare il nome del file: " << endl;
	cin.getline(file_name, MAX_NAME);



	instream.open(file_name); // Si apre il file in lettura
	if (!instream) {
		cout << endl << "impossibile aprire il file: " << file_name;
		exit(EXIT_FAILURE);
	}
	file2vec(instream, v, n, delim);

	for (int i = 0; i < 10; i++)
	{
		cout << v[i] <<"-";
	}

	instream.close();
	return 0;
}