#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;


const int MAX_NAME = 256;
const int MAX_LINE = 1000;


int main3()
{
	ifstream instream;

	char file_name[MAX_NAME], line[MAX_LINE], str[MAX_LINE];
	bool found;
	int v[10], n;
	char delim='-';
	cout << endl << "digitare il nome del file: " << endl;
	cin.getline(file_name, MAX_NAME);
	
	
	
		instream.open(file_name); // Si apre il file in lettura
	if (!instream) {
		cout << endl << "impossibile aprire il file: " << file_name;
		exit(EXIT_FAILURE);
	}
	



	cout << endl << "inserisci la stringa da cercare: " << endl;
	cin.getline(str, MAX_LINE);																
	int i = 1;
		found = false;
	while (instream) {
		instream.getline(line, MAX_LINE);
		if (strstr(line, str) != 0) {
			cout << i << ":" << line << endl;
			found = true;
		}
		++i;
	} 
		
		if (!found)
			cout << endl << "la stringa: " << str << "è assente!" << endl;

	instream.close();
	return 0;
}