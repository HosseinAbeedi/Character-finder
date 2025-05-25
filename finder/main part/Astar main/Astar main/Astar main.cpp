// Astar main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <tchar.h>

#define F 10


using namespace std;
void set(char*, char**, int*);
void print(char*, char**, int*);
void sort(char**, int*);




int main()
{
    char x[F + 1];
    char w[4] = { 'M','N','A','T' };
    for (int i = 0; i < F; i++) {
        int a = rand() % 4;
        x[i] = w[a];
    }
    x[F] = 0;
    ofstream write("fin.txt");
    write << x;
    write.close();

    char y[F + 1];
    char* m[F];
    int n[F];

    ifstream inputFile("fin.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening the file!" << endl;
        return 1;
    }
    string line;
    while (getline(inputFile, line)) {
        strcpy_s(y, line.c_str());
    }
    inputFile.close();

    set(y, m, n);
    sort(m, n);
    print(y, m, n);

    _getch();
    return 0;
    
}
//______________________________________________________
void set(char* x, char** y, int* z) {
	int i = F;
	int j;
	int count = 0;
	while (i > 0) {
		z[count] = i;
		int u = 0;
		char* ptr;//= (char*)malloc(i* sizeof(char));
		if (!(ptr = (char*)malloc(i + 1 * sizeof(char))))
		{
			cout << "malloc failed";
			exit(1);
		}

		for (j = F - i; j <= F - 1; j++) {
			ptr[u] = x[j];
			u++;
		}
		ptr[i] = 0;
		y[count++] = ptr;
		i--;
	}

}
//________________________________________________________
void print(char* x, char** y, int* z) {
	ofstream write2("fin2.txt");

	for (int i = 0; i < F; i++) {
		char* ptr;
		if (!(ptr = (char*)malloc(z[i] + 1 * sizeof(char))))
		{
			cout << "malloc failed";
			exit(1);
		}
		ptr[z[i]] = 0;
		for (int j = 0; j < z[i]; ptr[j++] = y[i][j]);

		write2 << ptr;
		write2 << endl;
		free(ptr);
		free(y[i]);
	}
	write2.close();
}
//__________________________________________________________
void sort(char** x, int* y) {
	int s;
	char* d;
	for (int m = 0; m < F; m++) {
		int p = m;

		for (int i = m + 1; i < F; i++) {
			for (int j = 0; j < F; j++) {

				if (x[p][j] == 0) {
					//	p=i;
					break;
				}
				else if (x[i][j] == 0) {
					p = i;
					break;
				}
				else if (x[p][j] < x[i][j]) {
					break;
				}
				else if (x[i][j] < x[p][j]) {
					p = i;
					break;
				}
			}
		}
		d = x[p];
		x[p] = x[m];
		x[m] = d;
		s = y[p];
		y[p] = y[m];
		y[m] = s;

	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
