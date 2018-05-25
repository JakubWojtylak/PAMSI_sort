#include "head.h"
#include <cstdlib>
#include "head.cpp"
#include "sort.cpp"
#include "intro.cpp"

int main()
{
  int p = 0;
  srand(time(NULL));
  char men;

  do
  {
    system("clear");
    p = wybierz_tablice();
  } while(p == 0);
  system("clear");
 // menu(p);
  while(1)
  {
    cout << endl << "Wybor: " << endl;
     menu(p);
		cin >> men;
    switch(men)
    {
    case 's':
      {
        system("clear");
        cout << "scalanie" << endl;

        zrob_testy('s',p);

        break;
      }
    case 'q':
      {
        system("clear");

        cout << "quicksort" << endl;
        zrob_testy('q',p);

        break;
      }
    case 'i':
      {
        system("clear");
                cout << "intorspektywne" << endl;
                zrob_testy('i',p);

        break;
      }
       case 'b':
      {
        system("clear");
            p = wybierz_tablice();

        break;
      }

    default:
      {
        system("CLS");
        cout << "Wprowadzono niepoprawny znak!" << endl;
        break;
      }
    }
  } ;

}
