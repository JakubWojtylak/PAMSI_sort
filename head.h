#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <fstream>

using namespace std;

void generowanie_tabeli(int *tablica, int ile, int proc, bool ros);
void menu(int i);
void test(int ile, char znak, int p, bool r, int t);
int wybierz_tablice();
void sprawdzenie(int *tab, int ile);
void zrob_testy(char z, int A);


void MergeSort(int poczatek, int koniec, int *tablica, int ile);
void QuickSort(int *tablica, int lewy, int prawy);

int Partition(int* data, int left, int right);
void QuickSortRecursive(int* data, int left, int right);
void MaxHeapify(int* data, int heapSize, int index);
void HeapSort(int* data, int c);
void InsertionSort(int* data, int c);
void IntroSort(int *data, int c);

