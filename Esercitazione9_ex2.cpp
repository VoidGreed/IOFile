#include <iostream>
#include <string>
#include <fstream>

const int max_name = 256;
const int max_string = 1000;
using namespace std;

float** alloc_mat(int r, int c)
{
	int i = 0;
	float **mat=new float*[r];
	for (; i < r; i++)
	{
		mat[i] = new float[c];
	}
	return mat;
}
void ins_mat(ifstream& in, float** m, int r, int c)
{
	char str[max_string];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			in.getline(str, max_string,',');
			 m[i][j]= atof(str);
		}
	}
}

void show_mat(ostream& out, float** m, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			out << m[i][j]<<",";

		}
		out << '\n';
	}
}

void deallocate_matrix(float **m,int r,int c)
{
	for (int i = 0; i < r; i++)
	{
		delete[] m[i];
	}
	delete[]m;
}
int main()
{
	ofstream out;
	ifstream in;

	char filename[max_name];
	char filename2[max_name];
	int columns, rows;


	cout << "Inserisci nome file: ";
	cin >> filename;

	cout << "Inserisci nome file: ";
	cin >> filename2;

	cout << "Inserire numero colonne della matrice: ";
	cin >> columns;
	cout << "Inserire numero righe della matrice: ";
	cin >> rows;
	
	float** matrix = alloc_mat(rows, columns);
	
	in.open(filename);

	if (!filename)
	{
		cout << "ERRORE file "<<filename<<" non trovato ";
		exit(EXIT_FAILURE);
	}

	ins_mat(in, matrix, rows, columns);

	in.close();
	
	out.open(filename2);

	if (!filename2)
	{
		cout << "ERRORE file "<<filename2<<" non trovato ";
		exit(EXIT_FAILURE);
	}

	show_mat(out, matrix, rows, columns);
	out.close();


}