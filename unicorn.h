#pragma once
#include <random>
#include <string>
#include <iostream>
#include <time.h>
#include <ctime>
#include <memory.h>
#include <stdio.h>
#include <vector>
#include <fstream>
double get_exeution_time(double s, double e);

// array
void swap(int&, int&);

void fill_array(int* arr, size_t sz, int array_from, int array_to);

void mix_array(int* arr, size_t sz);

template <typename T>
void show_array(T* arr, size_t size);
void bubble_sort(int* arr, int size);

void quick_sort(int* arr, size_t sz);

void points_feild(int n);

// matrix
template <typename T>
void show_matrix(T** matr, int m, int n);

template <typename T>
void create_matrix(T**& matr, int m, int n);

template <typename T>
void fill_matrix(T** matr, int m, int n, int fill_type);
template <typename T>
void clear_matrix(T**& matr, int m);

void change_matrix(int**& matr, int m, int n);

void dz_2(int**& matr, int m, int n);

void show_bits(int n);

void spiral_matrix(int** matr, int n);

//void convert_to_ch(char* str);

void palindrom();

void show_file(std::string url);

void show_split(std::string url);

void exercize(int from, int to);

void rand_data(std::string url, int year);

void read_data(std::string url);

auto strToChar(std::string& str, char* s);

void rand_data_2(std::string url1, std::string url2, int quntity);

void read_data_2(std::string url1, std::string url2, int quntity);

void GlasnueBykvi(std::string* str2, int size);

void ReadStringsInFile(std::ifstream& Filein, std::string* str2);

void CheckFile(std::ifstream& Filein);

void GeneralRegistr1(std::string& str);

void Vivod(std::string* str2, int size);

void array_chek(size_t n, int mass[], int b);