#include <iostream>
#include <fstream>
#include <stdlib.h>

typedef int TipoValue;
const char src[] = "C:/Users/Cnome/source/repos/fondamentiInformatica/prova_file/src.txt";
const char dest[] = "C:/Users/Cnome/source/repos/fondamentiInformatica/prova_file/dest.txt";
using namespace std;


int copy_file(ifstream &input, ofstream &output)
{
	char c;
	int i=0;

	while ((c = input.get()) != EOF)
	{
		output.put(c);
		i++;
	}

	return i;
}

void file2vec(ifstream& in, TipoValue v[], int& n)
{
	n = 0;
	while (in >> v[n])
		n++;
	return;
}

int vec2file(fstream& out, TipoValue v[], int n)
{
	int i;
	i = 0;
	while (i < n && out)
		out << v[i++] << " ";


	return i;
}




int main2()
{
	ifstream input;
	ofstream output;
	input.open(src, ios::in);
	output.open(dest, ios::out);

	if (!input)
	{
		cout << "Impossibile aprire il file " << src;
		return 0;
	}

	if (!output)
	{
		cout << "Impossibile aprire il file " << dest;
		return 0;
	}
	int i = copy_file(input, output);
	input.close();
	output.close();
	
	cout<<i;


	return 0;
	
}
