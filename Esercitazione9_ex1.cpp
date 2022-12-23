#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int max_name = 256;

unsigned long long int read_memory(ifstream& in) {
   
    int count = 0;
    char c;
    while (in.get(c))
    {
        if (c=='\n')
            count++;

      
        count++;
    }
    return count;
}

//int read_memory(ifstream& in) {
//    int count = 0;
//    string line;
//    while (getline(in, line))
//    {
//        cout << line;
//        count += line.length()+1;
//    }
//    return count;
//}

int main4235256() {
    char filename[max_name];
    ifstream file;
    unsigned long long int dim=0;
    cout << "Inserisci nome file: ";
    cin >> filename;

    file.open(filename);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file." << endl;
        exit(EXIT_FAILURE);
    }

    dim = read_memory(file);
    
    if (dim < 1024)
        cout << "Dimensione: " << dim<<" B";     //dim in byte

    else if (dim > 1024 && dim < 1048576)
    {
        
        double D = dim * 0.0009765625;                       //dim in KB
        
       
        cout << fixed <<setprecision(1) << "Dimensione: " << D << " KB";
    }
    else if (dim > 1048576 && dim < 1073741824)
    {
        
        double D = dim * 0.00000095367432;           //dim in MB
        
        
        cout << fixed << setprecision(1) << "Dimensione: " << D << " MB";
    }
  
    file.close();

    return 0;
}