#include <iostream>
#include <windows.h>
#include "Funcoes.cpp"

using namespace std;
int main()
{
    

    int opcaoMetodos;
    int opcaoInstancia = 0; 
    string nomeInstancia;              
    do
    {
        menuOrdenacao();
        cout << " ESCOLHA UM NUMERO: ";
        cin >> opcaoMetodos;

        if (opcaoMetodos > 0 && opcaoMetodos < 7)
        { 
            menuLista();
            cout << " ESCOLHA UM NUMERO: ";
            cin >> opcaoInstancia;
            system("cls");

            if (opcaoInstancia != 23)
            { 
                if (opcaoInstancia > 0 && opcaoInstancia <= 16)
                {
                    nomeInstancia = defineInstancia(opcaoMetodos, opcaoInstancia);
                    lerAquivoNumero(nomeInstancia);
                    ordenaVetoresString(opcaoMetodos);
                    system("pause");
                    system("cls");
                }
                else if (opcaoInstancia >= 17 && opcaoInstancia < 23)
                { 
                    nomeInstancia = defineInstancia(opcaoMetodos, opcaoInstancia);
                    lerArquivoPalavra(nomeInstancia);
                    ordenaVetoresInt(opcaoMetodos);
                    system("pause");
                    system("cls");
                }
                else
                {
                    cout << " INVALIDO " << endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (opcaoMetodos == 7)
        {
            break;
        }
        else
        {
            cout << " INVALIDA " << endl;
            system("pause");
            system("cls");
        }

    } while (opcaoMetodos != 7);

    return 0;
}