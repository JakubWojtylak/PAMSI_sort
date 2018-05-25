#include "head.h"

// Sortowanie przez scalanie - MergeSort
// Parametry:
// poczatek - numer pierwszego elementu tablicy
// koniec - numer ostatniego elementu tablicy
// tablica - tablica dynamiczna z elementami do posortowania
// ile - ilosc elementow w tablicy

void MergeSort(int poczatek, int koniec, int *tablica, int ile)
{
  int s,i1,i2,i;
  int *pom = new int [ile]; // tabela pomocnicza

  s = (poczatek + koniec +1 ) / 2;  // punkt odniesienia
  if(s - poczatek > 1) MergeSort(poczatek, s - 1, tablica, ile);
  if(koniec - s > 0) MergeSort(s, koniec, tablica, ile);
  i1 = poczatek;
  i2 = s;
  for(i = poczatek; i <= koniec; i++)
    pom[i] = ((i1 == s) || ((i2 <= koniec) && (tablica[i1] > tablica[i2]))) ? tablica[i2++] : tablica[i1++];
  for(i = poczatek; i <= koniec; i++) tablica[i] = pom[i];
  delete [] pom;
}

// Sortowanie Szybkie - QuickSort
// Parametry:
// tablica - tablica dynamiczna z elementami do posortowania
// poczatek - numer pierwszego tablicy
// koniec - numer ostatniego numeru tablicy
void QuickSort(int *tablica, int poczatek, int koniec)
{
  int l = poczatek;
  int p = koniec;
  int s = tablica[(poczatek + koniec) / 2];  // obieramy punkt odniesienia - w tym wypadku element srodkowy
  do
  {
    while(tablica[l] < s) l++;  // szukanie elementu mniejszego niz punkt odniesienia po jego lewej stronie
    while(tablica[p] > s) p--;  // szukanie elementu wiekszego niz punkt odniesienia po jego prawej stronie
    if(l <= p)  { swap(tablica[l], tablica[p]); l++; p--; } // jesli liczniki sie nie minely to zmieniamy elementy ze soba stojace po niewlasciwej stronie punktu odniesienia
  } while(l <= p);
  if(poczatek < p)  QuickSort(tablica, poczatek, p);
  if(koniec > l) QuickSort(tablica, l, koniec);
}


