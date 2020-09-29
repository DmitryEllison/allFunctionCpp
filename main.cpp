#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

#include <algorithm>
#include <iostream>
#include "unicorn.h"
#include <ctime>
using namespace std;

double len_f(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2) *( x1 -x2) + (y1 - y2) *( y1 - y2));
}
struct dum {
	string x_y;
	double x_y_max[6];
	double per_max;
	int len;
};
auto number_2(ifstream& matr) {
	matr.open("File.txt", ios::in);
	double x = 0, y = 0;
	string x_y; int len = 0;
	double x_y_max[6] = {0,0,0,0,0,0};
	if (matr.is_open()) {
		while (!matr.eof()) {
			matr >> x;
			matr >> y;
			
			x_y.push_back(x);
			x_y.push_back(y);
			len = len + 2;
		}
	}
	else {
		cout << "Error, try again!\n";
	}
	x_y.erase(x_y.end()-2, x_y.end() - 1);
	len = len - 2;
	double maxx = INT_MIN;
	double perimetr = 0;
	double per_max = 0;
	// Cycle
	for (int i = 0; i < len; i = i + 2) {
		for (int j = 0; j < len; j = j + 2) {
			for (int k = 0; k < len; k = k + 2) {
				perimetr = len_f(x_y.at(i), x_y.at(i + 1), x_y.at(j), x_y.at(j + 1)) + len_f(x_y.at(j), x_y.at(j + 1), x_y.at(k), x_y.at(k + 1)) + len_f(x_y.at(k), x_y.at(k + 1), x_y.at(i), x_y.at(i + 1));
				if (perimetr > maxx && j != i && i != k && k != j) {
					x_y_max[0] = x_y.at(i);
					x_y_max[1] = x_y.at(i + 1);
					x_y_max[2] = x_y.at(j);
					x_y_max[3] = x_y.at(j + 1);
					x_y_max[4] = x_y.at(k);
					x_y_max[5] = x_y.at(k + 1);
					per_max = perimetr;
					maxx = perimetr;
				}
			}
		}
	}
	//dum inx = { x_y, x_y_max, per_max, len };
	//return inx;
}

void number_3(ifstream& num) {
	num.open("file_2.txt", ios::in);
	string name;
	string name_in;
	cin >> name_in;
	if (num.is_open()) {
		while (!num.eof()) {
			getline(num, name, '.');
			if (name.find(name_in) != -1) {
				cout << name << '\n';
			}
		}	
	}
	else {
		cout << "Error!" << endl;
	}
	num.close();
}
void output1(int len, string x_y) {
	for (int i = 0; i < int(len);) {
		cout << double(x_y.at(i)) << " " << double(x_y.at(i + 1)) << endl;
		i = i + 2;
	}
}
void output2(double per_max, double x_y_max[6]) {
	cout << per_max << endl;
	for (int i = 0; i < 6; i += 2) {
		cout << "x: " << x_y_max[i] << ", y: " << x_y_max[i + 1] << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	setlocale(1251, );
	ifstream matr;
	ifstream num_2;
	dum inx;
	//inx = number_2(matr);

	//output1(inx.len, inx.x_y);
	//output2(inx.per_max, &inx.x_y_max[6]);
	
	matr.close();
	number_3(num_2);
	

	/*int len = 0;
	int id = 0;
	int *mass = new int[9];
	if (matr.is_open()) {
		while (!matr.eof()) {
			matr >> id;
			mass[len] = id;
			len++;
		}
	}
	else {
		cout << "Error, try again!\n";
	}
	int len1 = sqrt(len);
	int* matrix = new int[];
	

	for (int i = 0; i < len; ++i) {
		cout << mass[i] << " ";
	}
	int n = 5;
	int* s = new int[5];
	//arrayt(s, 5, 1, 3, 3, 4, 4);
	fill_array(s, n, 1, 10);
	for (int i = 0; i < n; ++i) {
		cout << s[i] << " ";
	}
	cout << "\n" << endl;
	array_chek(n, s, 50);
	for (int i = 0; i < n; ++i) {
		cout << s[i] << " ";
	}
	delete []s
;

	/*ifstream Filein;
	Filein.open("File.txt", ios::out);
	CheckFile(Filein);
	int size;
	cout << "¬ведите размер	string str1;
 массива" << endl;
	cin >> size;
	string* str2 = new string[size];
	ReadStringsInFile(Filein, str2);
	Filein.close();
	cout << endl;
	for (int i = 0; i < size; i++) 
	{
		GeneralRegistr1(str2[i]);
	}
	Vivod(str2, size);
	return 0;*/
	}



