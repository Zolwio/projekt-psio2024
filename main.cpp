#include <iostream>

using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usun element tablicy"<<endl;
    cout<<"4. Wyświetl elementy tablicy"<<endl;
    cout<<"5. Zapisz do pliku"<<endl;
    cout<<"6. Wczytaj z pliku"<<endl;
    cout<<"7. Wyjscie z programu"<<endl;
    cin>>x;
    cout<<endl;
    return x;
}

int main()
{
    int m;
    int *p = NULL;
    int n = 0;
    while(true)
    {
        m = Menu();
        switch(m)
        {
        case 7:
            {
                return 0;
            }
        case 1:
            {
                int * tmp = NULL;
                tmp = new int[n+1]; //tworzenie nowej tablicy (o jeden większej niż poprzednia)
                if(p != NULL) //jeżeli istnieje poprzednia tablica to:
                {
                    for(int i=0;i<n;i++)
                    {//przekopiuj zawartość poprzedniej tablicy do nowej
                        tmp[i] = p[i];
                    }
                    //usuń poprzednią tablicę
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];  //wstaw nową wartość do tablicy (na koniec)
                p = tmp; //przekopiuj adres nowej tablicy do wskaźnika p
                n++; //zwiększ ilość elementów tablicy o 1
                break;
            }
        case 2:
            {
                int *tmp = NULL;
                tmp = new int[n+1];
                int indx;
                int liczba;
                cout<<"Wprowadz na ktory indeks wstawic liczbe: ";
                cin>>indx;
                if(indx>n){
                    cout << "Podany indeks jest wiekszy niz rozmiar tablicy." << endl;
                break;
                }
                cout <<"podaj liczbe do wstawienia: ";
                cin>>liczba;
                for (int i = n - 1; i >= indx; i--) {
                p[i + 1] = p[i];
            }
                p[indx] = liczba;
            n++;
            break;
            }
        case 3:
            {
                int ind;
                cout<<"Wprowadz indeks ktory chcesz zwolnic: ";
                cin>>ind;
                if (ind >= n) {
                
                cout << "Podana pozycja jest wieksza niz rozmiar tablicy." << endl;
                            }       
                for (int i = ind; i < n - 1; i++) {
                    p[i] = p[i + 1];
                }
                n--;
                break;
            }
        case 4:
            {
                cout<<"Zawartosc tablicy:"<<endl;
                for(int i=0;i<n;i++)
                {
                    cout<<p[i]<<", ";
                }
                cout<<endl;
                break;
            }
        case 5:
            {
                //zapis danych do pliku
                {
                cout << "Podaj sciezke dostepu do pliku: ";
                string sciezka;
                cin >> sciezka;
                ifstream fin(sciezka,ios::app);
                if (!fin.is_open()) {
                    cout << "Nie mozna otworzyc pliku." << endl;
                    break;  
                }
                int rozmiar;
                fin >> rozmiar;
                delete[] p;
                p = new int[rozmiar];
                for (int i = 0; i < rozmiar; i++) {
                    fin >> p[i];
                }
                n = rozmiar;
                cout << "Tablica zostala wczytana z pliku." << endl;
                fin.close();
            break;
            }
            }
        case 6:
            {
                {
            cout<<"Podaj sciezke pliku do ktorego chcesz zapisac tablice: "<<endl;
            string sciezka;
            cin>>sciezka;
            ofstream fout(sciezka,ios::out|ios::trunc);
            if(!fout.is_open())
            {
                cout << "Nie mozna otworzyc pliku." << endl;
                break; 
            }
            if(p==NULL)
            {
                cout<<"Nie mozna zapisac pustej tablicy.";
            }
            else
            {
                fout<<n<<endl;
                for(int i=0; i<n;i++)
                {
                    fout<<p[i]<<" ";
                }
                cout<<"Pomyslne zapisano tablice do pliku.";
            } 
            fout.close();
            break;
            }
            }
        default:
            {
                cout<<"Nieprawidlowa opcja"<<endl;
            }

        }
    }

    return 0;
}
