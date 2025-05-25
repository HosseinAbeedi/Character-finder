// last.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <tchar.h>
using namespace std;
#define F 10
#define P 10
void get(char*, int s);
void setfile(char*);
int main()
{
	char a[P + 1];
	for (int l = 0; l < P + 1; l++) {
		a[l] = NULL;
	}
	int d[F]{};
	int n = 0;
	get(a, n);
	setfile(a);
	return 0;
}
//________________________________________________
void get(char* x, int s) {
	cout << "your can enter jast>>>" << P << "<<<word" << endl;
	cin >> x;
	for (int i = 0; x[i] == NULL; i++) {
		if (x[i] == NULL) {


		}
	}
}
void setfile(char* x) {
	char y[F + 1];
	char* m = x;
	int l = 0;
	ifstream inputFile("fin2.txt");
	if (!inputFile.is_open()) {
		cout << "Error opening the file!" << endl;
		return;
	}
	string line;
	while (getline(inputFile, line)) {
		strcpy_s(y, line.c_str());
		l++;
		int p = 0;
		for (int i = 0; y[i] != NULL; i++) {
			int c = i;
			for (int j = 0; x[j] != NULL; j++) {
				if (y[c] == x[j]) {
					c++;
					if (x[j + 1] == NULL) {
						p = i;
					}
				}
				else {
					break;
				}
			}
			if (p != 0) {

				break;
			}
		}
		if (p !=0) {
			cout << "i find this line  " << l << "  after " << p << "  word";
			break;
		}

	}
	inputFile.close();
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
