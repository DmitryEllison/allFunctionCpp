#include <random>
#include <iostream>
#include <time.h>
#include <ctime>
#include <memory.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include<string>
#include <algorithm>
#include "unicorn.h"
using namespace std;

double get_exeution_time(double s,double e) {
	return (e - s) / double(CLOCKS_PER_SEC);
}

void swap(int& a, int& b) {
	a ^= b; b ^= a; a ^= b;
}

void fill_array(int* arr, size_t sz, int array_from, int array_to) {
	srand(time(NULL));
	for (int i = 0; i < sz; ++i) {
		arr[i] = rand() % (array_to - array_from) + array_from;
	}
}

void mix_array(int* arr, size_t sz) {
	for (int i = 0; i < sz; ++i) {
		int t = rand() % sz;
		if (arr[i] != arr[t]) {
			swap(arr[i], arr[t]);
		}
		else {
			swap(arr[i], arr[t + 1]);
		}
	}
}

template <typename T>
T arrayt(int* &mass, int num, T first,...) {

}

template <typename T>
void show_array(T* arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n" << endl;
}

void bubble_sort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) { swap(arr[j], arr[j + 1]); }
		}
	}
}

void quick_sort(int* arr, size_t sz) {
	int i = 0, j = sz - 1;
	int v = arr[sz >> 1];
	do {
		while (arr[i] < v) i++;
		while (arr[j] > v) j--;
		if (i <= j) {
			if (i < j && arr[i] != arr[j])
				swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) quick_sort(arr, j + 1);
	if (i < sz - 1) quick_sort(arr + i, sz - i);
}
template <typename T>
void create_matrix(T**& matr, int m, int n) {
	matr = new T*[m];
	for (int i = 0; i < m; ++i)
		matr[i] = new T[n];
}

template <typename T>
void fill_matrix(T** matr, int m, int n, int fill_type) {
	srand(time(NULL) + rand());
	for (int i = 0; i < m; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			switch (fill_type) {
				case 1:
					matr[i][j] = rand()%10;
					break;
				case 2:
					matr[i][j] = rand() % 1000;
					break;
				/*case 3:
					matr[i][j] = int(m * i + j);
					break;*/
				default: matr[i][j] = 0;
			}
		}
	}
}

template <typename T>
void show_matrix(T** matr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matr[i][j] << "\t";
		}
		cout << "\n";
	}
}

void show_matrix(double**& matr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matr[i][j] << " ";
		}
		cout << "\n";
	}
}
template <typename T>
void clear_matrix(T**& matr, int m){
	for (int i = 0; i < m; ++i) {
		delete[] matr[i];
	}
	delete[] matr;
	matr = nullptr;
}

int sum_diog(int**& matr, int m, int n, int ind_1, int ind_2) {
	int sum = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if ((i + j <= ind_1 + ind_2) and (i - j >= ind_1 - ind_2)) sum += matr[i][j];
	return sum;
}

void change_matrix(int**& matr, int m, int n) {
	// Копируем исходную матрицу
	int** matr_2 = nullptr;
	create_matrix(matr_2, m, n);
	for (int i = 0; i < m; i++) {
		memcpy_s(matr_2[i], n*sizeof(matr_2[0][0]), matr[i], n * sizeof(matr[0][0]));
	}
	// Изменяем матрицу скопированную матрицу с помощью исходной
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matr[i][j] = sum_diog(matr_2, m, n, i, j);
		}
	}
	clear_matrix(matr_2, m);
}

int counter(double** data, int n, double x1, double y1, double x2, double y2) {
	double kol; int count_neg = 0; int count_pos = 0; double x; double y;
	for (int i = 0; i < n; ++i) {
		x = data[i][0];
		y = data[i][1];
		if (!((x == x1 and y == y1) or (x == x2 and y == y2))) {
			kol = y * (x2 - x1) - x * (y2 - y1) + x1 * (y2 - y1) - y1 * (x2 - x1);;
			if (kol >= 0) { count_pos++; }
			if (kol <= 0) { count_neg++; }
		}
	}
	if (count_pos >= count_neg) { return count_pos; }
	else { return count_neg; }
}

int func_2(double** data, double** result, int n, int index, int last_index, int k) {
	int z = 0; int count = 0; int i = 0;
	for (int j = 0; j < n; ++j)
		if ((index != j) and (j != last_index)) {
			count = counter(data, n, data[index][0], data[index][1], data[j][0], data[j][1]);
			if (count == n - 2) {
				i = j;
				break;
			}
		}
	if ((data[i][0] == result[0][0]) and (data[i][1] == result[0][1])) {
		return k;
	}
	result[k][0] = data[i][0];
	result[k][1] = data[i][1];
	last_index = index;
	index = i;
	k = k + 1;
	k = func_2(data, result, n, index, last_index, k);
	return k;
}

void points_feild(int n) {
	double** data = new double* [n];
	create_matrix(data, n, 2);
	srand(time(NULL));
	double x_create, y_create;
	for (int i = 0; i < n; i++)
	{
		x_create = (rand() % 20001) / 100. - 100;
		y_create = (rand() % 20001) / 100. - 100;
		data[i][0] = x_create;
		data[i][1] = y_create;
	}
    show_matrix(data, n, 2);
	int max_arr = INT_MIN;
	int max_ind = 0;
	for (int i = 0; i < n; i++)
	{
		double x = data[i][0];
		double y = data[i][1];
		double len = sqrt(x * x + y * y);
		if (len > max_arr) {
			max_ind = i; max_arr = len;
		}
	}
	int last_ind = NULL;
	double** result = new double* [n];
	create_matrix(result, n, 2);
	fill_matrix(result, n, 2, 3);
	int k = 1;
	result[0][0] = data[max_ind][0];
	result[0][1] = data[max_ind][1];
	k = func_2(data, result, n, max_ind, last_ind, k);
	cout << "\n\t--------\n";
	show_matrix(result, k, 2);
	clear_matrix(data, n);
	clear_matrix(result, k);
}

void dz_2(int**& matr, int m, int n) {
	create_matrix(matr, m, n);
	fill_matrix(matr, m, n, 1);
	show_matrix(matr, m, n);
	cout << "\n-------------------\n\n";
	change_matrix(matr, m, n);
	show_matrix(matr, m, n);
	clear_matrix(matr, m);
}

void show_bits(int n) {
	for (int i = sizeof(n) * 8-1; i >= 0 ; i--) {
		if (n & (1 << i)) 
			cout << "1";
		else
			cout << "0";
	}
}

void spiral_matrix(int** matr, int n) {
	int a = 0;
	while (a <= n/2 )
	{
		for (int j = a; j < n - a; j++)
		{
			cout << matr[a][j] << " ";
		}
		cout << endl;

		for (int i = a + 1; i < n - a; i++)
		{
			cout << matr[i][n - a - 1] << " ";
		}
		cout << endl;

		for (int j = n - a - 2; j >= a; j--)
		{
			cout << matr[n - a - 1][j] << " ";
		}
		cout << endl;

		for (int i = n - a - 2; i > a; i--)
		{
			cout << matr[i][a] << " ";
		}
		cout << endl;
		a++;
	}
}

int convert_to_rim(char* str) {
	int x; int k = 0; 
	char* str2 = new char[255]; 
	int index = 0;
	sscanf_s(str, "%d", &x);
	if (x > 3999) {
		printf("The number is too big...\a");
		return 0;
	}
	while (x % 1000 != 0 and k <= 3) {
		k++; 
		str2[index] = 'M';
		index++;
		x -= 1000;
	}
	k = 0;
	if(x>=900){
		str2[index] = 'C';
		str2[index + 1] = 'M';
		index+=2;
		x -= 900;
	}
	k = 0;
	if (x - 500 > 0) {
		str2[index] = 'D';
		index++;
		x -= 500;
	}
	while (x % 100 != 0 and k <= 3) {
		k++;
		cout << "M";
		x -= 100;
	}
	k = 0;
}

void palindrom() {
	string words; int k = 0;
	cin >> words;
	std::transform(words.begin(), words.end(), words.begin(),[](unsigned char c) { return tolower(c); });
	//cout << words << endl;
	int i = 0;
	for (int i = 0, j = words.length()-1; i != j;) {
		if (! ((int(words[i]) >= 97 and int(words[i]) <= 122) or (int(words[i]) >= -96 and int(words[i]) <= -17))){
			++i;
			continue;
		}
		if (!((int(words[i]) >= 97 and int(words[i]) <= 122) or (int(words[i]) >= -96 and int(words[i]) <= -17))) {
			--j;
			continue;
			}
		if (words[i] != words[j])
			k++;
		if (i = j)
			break;
	}
	
	std::cout << (k == 0 ? "Это палиндром!" : "Это не палиндром!");
	
}

void exercize(int from, int to) {
	int s = 1, i;
	cout << "Enter 0 to exit from programm.\nGood luck!" << endl;
	cin >> i; int x, y, wrong;
	srand(time(nullptr) + rand());
	for (int j = 0; j < i; ++j) {
		if (s != 0) {
			x = (rand()*rand()) % (from - to) + from;
			y = (rand()*rand()) % (from - to) + from;
			cout << x << " + " << y << " =\n";
			cin >> s; 
			wrong = abs(s - x - y);
			if (s != 0)
				if (s == x + y) {
					printf("True\n");
				}
				else {
					printf("You made a mistake at %i\n", wrong);
					--j;
				}	
		}
	}
}

void show_file(string url) {
	ifstream data;
	data.open(url);
	if (data.is_open()) {
		char* s = new char[1023];
		while (!data.eof()) {
			//data.getline(s, 1024);
			data >> s;
			if (data.fail()) {
				data.clear();
				data.get();
			}
			else {
				cout << s << " \n";
			}
		}
	}
	else
		printf("Неудачная попытка отркыть файл!");
}

void show_split(string url) {

	fstream data;
	data.open(url);
	string s;

	vector <std::string> words;
	if (data.is_open()) {
		int i = 0;
		while (!data.eof()) {
			data >> s;
			if (data.fail()) {
				data.clear();
				data.get();
			}
			else {
				cout << s << " ";
				std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
				words.push_back(s);
			}
		}
	}
	else {
		printf("Error");
	}
	for (int i = 0; i < words.size(); ++i) {
		for (int j = i+1; j < words.size(); ++j) {
			if (words.at(i) == words.at(j)) {
				words[j] = "null";
			}
		}
	}
	printf("\n");
	sort(words.begin(), words.end());
	for (int i = 0; i < words.size(); ++i) {
		if (words.at(i) != "null")
			std::cout << words.at(i) << "\n";
	}
	data.close();
}

struct Data {
	int day;
	int month;
	int year;
	int tem;

};

void rand_data(string url, int year)
{
	Data someday;
	int month_count = 12;
	fstream fo;
	fo.open(url, ios_base::binary | ios::out);
	srand(time(nullptr) + rand());
	int n[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	double x = -50;
	if (fo.is_open()) {
		for (int i = 1; i <= month_count; ++i)
		{
			for (int j = 1; j <= n[i - 1]; ++j)
			{
				int tem = -abs(int(x)) + 25 + rand() % 15 - 7 + int(rand() % 11 / 10.);
				x += 100. / 365;
				someday = { j , i , year, tem};
				fo.write(reinterpret_cast<const char*>(&someday), sizeof(someday));
				
			}
		}
	}
	else {
		cout << "НЕ ЗАПИСАЛАСЬ" << endl;
	}
	fo.close();
}

void read_data(string url)
{
	fstream fi;
	fi.open(url, ios_base::binary| ios::in);
	if (fi.is_open()) {
		Data somedays;
		int x = 0;
		double stat[12] = { 0.,0,0,0,0,0,0,0,0,0,0,0 };
		int n[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		string mo[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "Octeber", "September", "November", "December" };
		while (!fi.eof() && x++ < 365) {
			fi.read(reinterpret_cast<char*>(&somedays), sizeof(somedays));
			if (!fi.fail()) {
				cout << somedays.day << "." << somedays.month << "." << somedays.year << " " << somedays.tem << "\n";
				stat[int(somedays.month) - 1] += int(somedays.tem);
			}
			else {
				cout << "fail()" << endl;
			}
		}
		for (int k = 0; k < 12; k++) {
			stat[k] =stat[k]*1./ n[k];
		}
		cout << endl;
		double max; 
		int ind = 0;
		for (int z = 0; z < 12; z++) {
			max = INT_MIN;
			for (int d = 0; d < 12; d++) {
				if (stat[d] > max) {
					max = stat[d];
					ind = d;
				}
			}
			stat[ind] = INT_MIN;
			cout << mo[ind] << " " << max << endl;
		}
	}
	fi.close();
}

struct Data_1 {
	char name[20];
	int ID;
	struct birthday { int day; int month; int year; }date;
	unsigned int salary;

};
struct Data_2 {
	int ID;
	struct time_i { int hour; int min; }time_in;
	struct time_o { int hour; int min; }time_out;
	struct data { int day;  int month; int year; }date;
};
auto strToChar(std::string& str, char* s) {
	for (int i = 0; i < 20; i++)
		s[i] = '\0';
	for (int i = 0; i < str.length(); i++) {
		s[i] = str.at(i);
	}
	//cout << str.length() << endl;
	return s;
}
void rand_data_2(string url1, std::string url2, int  quantity) {
	Data_1 workerList_1;
	Data_2 workerList_2;
	int dayinmonth = 28;
	fstream fo1;
	fstream fo2;
	char str[32]; int id;
	string s[10] = { "Jessica Anthony","Judith Patrick","Garry Potter", "Sandra Hopkins", "Felicia Spart", "Kenneth Jasmin","Caroline Grant","Roberta Sparks","Thomas Butler","Ronald Ellison" };
	int salary = 0;
	fo1.open(url1, ios_base::binary | ios::out);
	fo2.open(url2, ios_base::binary | ios::out);
	srand(time(nullptr) + rand());
	if (fo1.is_open() && fo2.is_open()) {
		for (int i = 0; i < quantity; i++) {
			id = i + 1;
			strToChar(s[i], workerList_1.name);
			workerList_1.ID = i + 1;
			workerList_1.salary = (rand() % 25 + 25) * 1000;
			workerList_1.date = { rand() % (dayinmonth - 1) + 1, rand() % 11 + 1, rand() % 37 + 1965 };
			fo1.write(reinterpret_cast<const char*>(&workerList_1), sizeof(workerList_1));
			for (int z = 0; z < 28; z++) {
				workerList_2.ID = i+1;
				workerList_2.time_in = { 8, rand() % 25 };
				workerList_2.time_out = { 17 + (rand() % 4 - 1), rand() % 15 };
				workerList_2.date = { z, 2, 2019 };
				fo2.write(reinterpret_cast<const char*>(&workerList_2), sizeof(workerList_2));
				//std::cout << workerList_1.ID << ": "<< workerList_2.time_out.hour << ":" << (workerList_2.time_out.min<10? "0":"")<<workerList_2.time_out.min << endl;
			}
			//cout << workerList_1.name << " ";
		}
	}
	else {
		cout << "WriteError" << endl;
	}
	fo1.close(); fo2.close();
}

void read_data_2(string url1, string url2, int quantity) {
	ifstream fi1; ifstream fi2;
	int fool[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int dayinmonth = 28;
	int hour = 0, min = 0;
	Data_1 workerList_1;
	Data_2 workerList_2;
	fi1.open(url1, ios_base::binary | ios::in); fi2.open(url2, ios_base::binary | ios::in);
	if (fi1.is_open() && fi2.is_open()) {
		for (int i = 0; i < quantity; i++) {
			fi1.read(reinterpret_cast<char*>(&workerList_1), sizeof(workerList_1));
			for (int j = 0; j < dayinmonth; j++) {
				fi2.read(reinterpret_cast<char*>(&workerList_2), sizeof(workerList_2));
				hour = workerList_2.time_out.hour - workerList_2.time_in.hour;
				min = workerList_2.time_out.min - workerList_2.time_in.min;
				cout << "\tID: " << (workerList_1.ID < 10 ? "0" : "") << workerList_1.ID << ":  ";
				std::cout << workerList_2.time_in.hour << ":" << (workerList_2.time_in.min < 10 ? "0" : "") << workerList_2.time_in.min << ",  ";
				std::cout << workerList_2.time_out.hour << ":" << (workerList_2.time_out.min < 10 ? "0" : "") << workerList_2.time_out.min << endl;
				fool[i] += (hour - 9) * 60 + min;
			}
			fool[i] /= dayinmonth;
			cout << workerList_1.name << ",  ";
			cout << "ID: " << (workerList_1.ID < 10 ? "0" : "") << workerList_1.ID << ",  ";
			cout << "birthday: " << (workerList_1.date.day < 10 ? "0" : "") << workerList_1.date.day;
			cout << "." << (workerList_1.date.month < 10 ? "0" : "") << workerList_1.date.month;
			cout << "." << workerList_1.date.year << ",  ";
			cout << "salary: " << workerList_1.salary << " RUB" << ",  ";
			cout << "working time - norm: " << fool[i] << ",  ";
			cout << "prize: ";
			cout << (fool[i] >= 30 ? workerList_1.salary * 0.5 : NULL) << "\n" << endl;
		}
	}
	fi1.close(); fi2.close();
}


//Функция, которая проверяет строка начинается с гласной буквы или нет
void GlasnueBykvi(string* str2, int size)
{
	string str;
	for (int i = 0; i < size; i++)
	{
		str = str2[i];
		if (str.find_first_of("A" || "E" || "O" || "Y" || "U" || "I" || "У" || "Е" || "Э" || "О" || "А" || "Ы" || "Я" || "И" || "Ю") == 0) {
			cout << str2[i] << endl;
		}
	}
}

//функция, которая читает массив строк из файла(построчно)
void ReadStringsInFile(ifstream& Filein, string* str2)
{
	string str;
	int i = 0;
	while (!Filein.eof())
	{
		str = "";
		Filein >> str;
		str2[i] = str;
		cout << endl;
		i++;
		std::cout << str;
	}
}

//функция, которая проверяет открыт ли файл
void CheckFile(ifstream& Filein)
{
	(Filein.is_open()) ? (cout << "Файл открыт" << endl) : (cout << "Файл не открыт");
}

//Приведение строки к одному регистру
void GeneralRegistr1(std::string& str) {
	std::transform(str.begin(), str.end(), str.begin(), toupper);
}

void Vivod(string* str2, int size) {
	for (int i = 0; i < size; i++) {
		if (int(str2[i].length()) >= 1) {
			cout << "str2[" << i << "] = " << str2[i] << endl;
		}
	}
}

void array_chek(size_t n, int mass[], int b) {
	srand(time(nullptr) + rand());
	for (int i = 0; i < n;++i) {
		for (int j = i+1; j < n; j++) {
			if (mass[i] == mass[j]) {
				mass[i] = rand() % b;
				--i;
			}
		}
	}

}

int fi(int k) {
	int val = 0;
	if (k < 1) return 0;
	if (k == 1) return 1;
	if (k > 1) return  fi(k - 1) + fi(k - 2);
}

void fi_opt(unsigned int n) {
	unsigned int fi[2] = { 1, 1 };
	int k = 0;
	while (k < n) {
		k = fi[0] + fi[1];
		fi[0] = fi[1];
		fi[1] = k;
		cout << k << endl;
		if (k == n) printf("\nFibonacci numbers contain %i", n);
	}
}

template <typename T>
void arrayt(int*& mass, int num, T first, ...) {
	T* ptr = &first;
	for (int i = 0; i < num; i++) {
		mass[i] = *ptr;
		ptr++;
	}
}

//Функция, которая сортирует по столбцам элементы в двумерном динамическом массиве
void SortDim2MassiveStolb(int sizeofarraystr, int sizeofarraystolb, int** g) {//???
	for (int i = 0; i < sizeofarraystolb; i++) {
		for (int j = 0; j < sizeofarraystr; j++) {
			//sortviborom(*(g + j), sizeofarraystr);
		}
	}
}


void SortLastStolb(int sizeofarraystr, int sizeofarraystolb, int** g) {
	//sortviborom(g[sizeofarraystolb - 1], sizeofarraystr);
}