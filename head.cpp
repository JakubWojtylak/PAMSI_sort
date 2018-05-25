#include "head.h"



void generowanie_tabeli(int *tablica, int ile, int proc, bool ros)
{
  int x = ile * proc / 1000;
  for(int i=0; i<ile; i++)
  {
    if(ros == true && i < x)  tablica[i] = i;
    if(ros == true && i >= x) tablica[i] = rand() + x;
    if(ros == false)          tablica[i] = ile - i;
  }
}

void menu(int i)
{


  cout << "i - INTROSORT" << endl;
  cout << "s - SCALANIE" << endl;
  cout << "q - QUICKSORT" << endl;
  cout << "b - go back to size of the array"<<endl;

}

void test(int ile, char znak, int p, bool r, int t)
{
  clock_t start,stop;
  double czas;
  bool kom = true;
  int **tab = new int * [ile];
  for(int i=0; i<100; i++)  { tab[i] = new int [ile]; generowanie_tabeli(tab[i],ile,p,r);  }

  start = clock();
  for(int i=0; i<100; i++)
  {
    if(znak == 's') MergeSort(0,ile-1,tab[i],ile);
    if(znak == 'q') QuickSort(tab[i],0,ile-1);
    if(znak == 'i') IntroSort(tab[i],ile);

    try { sprawdzenie(tab[i],ile);  }
    catch(bool w) { kom = w;   }
  }
  stop = clock();
  czas = (double)(stop-start) / CLOCKS_PER_SEC;
  for(int i=0; i<100; i++) delete [] tab[i];
  delete [] tab;





  cout << "Czas: " << setprecision(10) << czas << " s" << endl;
  if(kom == true) cout << "sort sie udal" << endl;
  else cout << "sort sie nie udal" << endl;
  getchar();
}


int wybierz_tablice()
{
  char znak;

  cout << "a - 10k, b - 50k, c-100k, d-500k, e-1000k"<< endl << endl;
  cin >> znak;
  switch(znak)
  {
  case 'a': return 10000;
  case 'b': return 50000;
  case 'c': return 100000;
  case 'd': return 500000;
  case 'e': return 1000000;
  default: return 0;
  }
}




void sprawdzenie(int *tab, int ile)
{
  int x;
  bool w = false;
  for(int i=0; i<ile-1; i++)
  {
    x = tab[i+1];
    if(tab[i] > x)  throw w;
  }
}

void zrob_testy(char z, int ile)
{
  getchar();



  cout << "losowe elementy" << endl;
  test(ile,z,0,true,1);


  cout << endl << endl;
  cout << "25% posortowane" << endl;
  test(ile,z,250,true,2);


  cout << endl << endl;
  cout << "50% posortowane" << endl;
  test(ile,z,500,true,3);


  cout << endl << endl;
 cout <<  "75% posortowane" << endl;
  test(ile,z,750,true,4);


  cout << endl << endl;
  cout << "95% posortowane" << endl;
  test(ile,z,950,true,5);


  cout << endl << endl;
  cout << "99% posortowane" << endl;
  test(ile,z,990,true,6);


  cout << endl << endl;
  cout << "99.7% posortowano"<< endl;
  test(ile,z,997,true,7);

cout << endl << endl;
  cout <<  " odwrotnie " << endl;
  test(ile,z,1000,false,8);


}

