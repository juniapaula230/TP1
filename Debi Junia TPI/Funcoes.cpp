#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>

using namespace std;
using namespace chrono;

// FUNÇÕES PARA CHAMAR O MENU DESEJADO
void menuOrdenacao();
void menuLista();

// FUNÇÕES PARA LER ARQUIVOS DE NÚMEROS OU PALAVRAS
vector<int> lerAquivoNumero(string nomeInstancia);
vector<string> lerArquivoPalavra(string nomeInstancia);

// FUNÇÕES PARA DECLARAR VARIAVEIS GLOBAIS
vector<int> vetornumeros;
vector<string> vetorpalavras;

// FUNÇÕES PARA IMPRIMIR VETORES INTEIROS E STRTRING
void imprimirNumeros();
void imprimirPalavras();

// FUNÇÕES PARA ORDENAR VETORES INTEIROS E STRING
string defineInstancia(int opMetodos, int opInstancia);
void ordenaVetoresInt(int opMetodos);
void ordenaVetoresString(int opMetodos);

// FUNÇÕES PARA ORDENAR VETORES INTEIROS
void bubbleSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas);
void insertionSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas);
void selectionSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas);
void shellSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas);
void quickSortNumeros(int esquerda, int direita, unsigned long long *comparacoes, unsigned long long *trocas);

void mergeSortNumeros(int inicio, int fim, unsigned long long *comparacoes, unsigned long long int *trocas);
void IntercalaNumeros(int inicio, int meio, int fim, unsigned long long *comparacoes, unsigned long long *trocas);

// FUNÇÕES PARA ORDENAR VETORES STRING
void bubbleSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas);
void insertionSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas);
void selectionSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas);
void shellSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas);
void quickSortPalavras(int esquerda, int direita, unsigned long long *comparacoes, unsigned long long *trocas);
void mergeSortPalavras(int inicio, int fim, unsigned long long *comparacoes, unsigned long long int *trocas);

// MENU PARA A ESCOLHA DO TIPO DE ORDENACAO
void menuOrdenacao()
{

    cout << "*********************************" << endl;
    cout << "* 1 - BUBBLE SORT               *" << endl;
    cout << "* 2 - SELECTION SORT            *" << endl;
    cout << "* 3 - INSERTION SORT            *" << endl;
    cout << "* 4 - SHELL SORT                *" << endl;
    cout << "* 5 - QUICK SORT                *" << endl;
    cout << "* 6 - MERGE SORT                *" << endl;
    cout << "* 7 - SAIR                      *" << endl;
    cout << "*********************************" << endl;
    cout << endl;
}

// MENU PARA A ESCOLHA DO TIPO DE ORDENACAO
void menuLista()
{

    cout << "*******************************************************" << endl;
    cout << "* 1 - LISTA ALEATORIA COM 1000 NUMEROS                *" << endl;
    cout << "* 2 - LISTA ALEATORIA COM 10000 NUMEROS               *" << endl;
    cout << "* 3 - LISTA ALEATORIA COM 100000 NUMEROS              *" << endl;
    cout << "* 4 - LISTA ALEATORIA COM 1000000 NUMEROS             *" << endl;
    cout << "* 5 - LISTA INVERSAMENTE ORDENADA COM 1000 NUMEROS    *" << endl;
    cout << "* 6 - LISTA INVERSAMENTE ORDENADA COM 10000 NUMEROS   *" << endl;
    cout << "* 7 - LISTA INVERSAMENTE ORDENADA COM 100000 NUMEROS  *" << endl;
    cout << "* 8 - LISTA INVERSAMENTE ORDENADA COM 1000000 NUMEROS *" << endl;
    cout << "* 9 - LISTA ORDENADA COM 1000 NUMEROS                 *" << endl;
    cout << "* 10 - LISTA ORDENADA COM 10000 NUMEROS               *" << endl;
    cout << "* 11 - LISTA ORDENADA COM 100000 NUMEROS              *" << endl;
    cout << "* 12 - LISTA ORDENADA COM 1000000 NUMEROS             *" << endl;
    cout << "* 13 - LISTA QUASE ORDENADA COM 1000 NUMEROS          *" << endl;
    cout << "* 14 - LISTA QUASE ORDENADA COM 10000 NUMEROS         *" << endl;
    cout << "* 15 - LISTA QUASE ORDENADA COM 100000 NUMEROS        *" << endl;
    cout << "* 16 - LISTA QUASE ORDENADA COM 1000000 NUMEROS       *" << endl;
    cout << "* 17 - DICIONARIO ALEATORIO-29855                     *" << endl;
    cout << "* 18 - DICIONARIO ALEATORIO-261791                    *" << endl;
    cout << "* 19 - DICIONARIO INVERSAMENTE ORDENADO-29855         *" << endl;
    cout << "* 20 - DICIONARIO INVERSAMENTE ORDENADO-261791        *" << endl;
    cout << "* 21 - DICIONARIO ORDENADO-29855                      *" << endl;
    cout << "* 22 - DICIONARIO ORDENADO-261791                     *" << endl;
    cout << "*******************************************************" << endl;
}

// FUNÇÃO DE ORDENAÇÃO USANDO O BUBBLE SORT PARA INTEIROS
void bubbleSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int troca;
    for (int i = 0; i < vetornumeros.size() - 1; i++){
        troca = 0;
        for (int j = 1; j < vetornumeros.size() - i; j++)
        {
            if (vetornumeros[j] < vetornumeros[j - 1])
            {
                (*comparacoes)++;
                int aux = vetornumeros[j];
                vetornumeros[j] = vetornumeros[j - 1];
                vetornumeros[j - 1] = aux;
                troca = 1;
                (*trocas)++;
            }
            else
            {
                (*comparacoes)++;
            }
        }
        if (troca == 0)
        {
            break;
        }
    }
}

// FUNÇÃO DE ORDENAÇÃO USANDO O BUBBLE SORT PARA STRINGS
void bubbleSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int troca;
    for (int i = 0; i < vetorpalavras.size() - 1; i++)
    {
        troca = 0;
        for (int j = 1; j < vetorpalavras.size() - i; j++)
        {
            if (vetorpalavras[j] < vetorpalavras[j - 1])
            {
                (*comparacoes)++;
                auto aux = vetorpalavras[j];
                vetorpalavras[j] = vetorpalavras[j - 1];
                vetorpalavras[j - 1] = aux;
                troca = 1;
                (*trocas)++;
            }
            else
            {
                (*comparacoes)++;
            }
        }
        if (troca == 0)
        {
            break;
        }
    }
}

// FUNÇÃO DE ORDENAÇÃO USANDO O INSERTION SORT PARA INTEIROS
void insertionSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int chave, j;

    for (int i = 1; i < vetornumeros.size(); i++)
    {
        chave = vetornumeros[i];
        j = i - 1;

        (*comparacoes)++;

        while (j >= 0 && vetornumeros[j] > chave)
        {
            (*comparacoes)++;

            vetornumeros[j + 1] = vetornumeros[j];
            j--;

            (*trocas)++;
        }
        vetornumeros[j + 1] = chave;
    }
}

// FUNÇÃO DE ORDENAÇÃO USANDO O INSERTION SORT PARA STRINGS
void insertionSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas)
{
    string chave;
    int j;

    for (int i = 1; i < vetorpalavras.size(); i++)
    {
        chave = vetorpalavras[i];
        j = i - 1;

        (*comparacoes)++;

        while (j >= 0 && vetorpalavras[j] > chave)
        {
            (*comparacoes)++;

            vetorpalavras[j + 1] = vetorpalavras[j];
            j--;

            (*trocas)++;
        }
        vetorpalavras[j + 1] = chave;
    }
}

// FUNÇÃO DE ORDENAÇÃO USANDO O SELECTION SORT PARA INTEIROS
void selectionSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int min, i, j;

    for (i = 0; i < vetornumeros.size(); i++)
    {
        min = i;

        for (j = i + 1; j < vetornumeros.size(); j++)
        {
            if (vetornumeros[j] < vetornumeros[min])
            {
                (*comparacoes)++;
                min = j;
            }
            else
            {
                (*comparacoes)++;
            }
        }
        int aux = vetornumeros[i];
        vetornumeros[i] = vetornumeros[min];
        vetornumeros[min] = aux;

        (*trocas)++;
    }
}

// FUNÇÃO DE ORDENAÇÃO USANDO O SELECTION SORT PARA STRINGS
void selectionSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int min, i, j;

    for (i = 0; i < vetorpalavras.size(); i++)
    {
        min = i;

        for (j = i + 1; j < vetorpalavras.size(); j++)
        {
            if (vetorpalavras[j] < vetorpalavras[min])
            {
                (*comparacoes)++;
                min = j;
            }
            else
            {
                (*comparacoes)++;
            }
        }
        string aux = vetorpalavras[i];
        vetorpalavras[i] = vetorpalavras[min];
        vetorpalavras[min] = aux;

        (*trocas)++;
    }
}

// FUNÇÃO DE ORDENAÇÃO USANDO O SHELL SORT PARA INTEIROS
void shellSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int h, x, i, j;
    for (h = 1; h < vetornumeros.size(); h = 3 * h + 1)
        

    while (h > 1)
    {
        h = h / 3;
        (*comparacoes)++;
        for (i = h; i < vetornumeros.size(); i++)
        {
            x = vetornumeros[i];
            j = i;

            while (j >= h && vetornumeros[j - h] > x)
            {
                (*comparacoes)++;

                vetornumeros[j] = vetornumeros[j - h];
                j = j - h;

                (*trocas)++;
            }
            vetornumeros[j] = x;
            (*comparacoes)++;
        }
    }
}

// FUNÇÃO DE ORDENAÇÃO USANDO O SHELL SORT PARA STRINGS
void shellSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int h, i, j;
    string x;
    for (h = 1; h < vetorpalavras.size(); h = 3 * h + 1)
        

    while (h > 1)
    {
        h = h / 3;
        (*comparacoes)++;
        for (i = h; i < vetorpalavras.size(); i++)
        {
            x = vetorpalavras[i];
            j = i;

            while (j >= h && vetorpalavras[j - h] > x)
            {
                (*comparacoes)++;

                vetorpalavras[j] = vetorpalavras[j - h];
                j = j - h;

                (*trocas)++;
            }
            vetorpalavras[j] = x;
            (*comparacoes)++;
        }
    }
}

// FUNÇÃO DE ORDENAÇÃO USANDO O QUICK SORT PARA INTEIROS
void quickSortNumeros(int esquerda, int direita, unsigned long long *comparacoes, unsigned long long *trocas)
{
    int i = esquerda, j = direita;
    int pivot = vetornumeros[(esquerda + direita) / 2];

    while (i <= j)
    {
        while (vetornumeros[i] < pivot)
            i++;
        while (vetornumeros[j] > pivot)
            j--;

        (*comparacoes)++;
        if (i <= j)
        {
            auto temp = vetornumeros[i];
            vetornumeros[i] = vetornumeros[j];
            vetornumeros[j] = temp;
            i++;
            j--;

            (*trocas)++;
        }
    }

    (*comparacoes)++;
    if (esquerda < j)
        quickSortNumeros(esquerda, j, comparacoes, trocas);
    (*comparacoes)++;
    if (i < direita)
        quickSortNumeros(i, direita, comparacoes, trocas);
}

// FUNÇÃO DE ORDENAÇÃO USANDO O QUICK SORT PARA STRINGS
void quickSortPalavras(int esquerda, int direita, unsigned long long *comparacoes, unsigned long long *trocas)
{
    int i = esquerda, j = direita;
    string pivot = vetorpalavras[(esquerda + direita) / 2];

    while (i <= j)
    {
        while (vetorpalavras[i] < pivot)
            i++;
        while (vetorpalavras[j] > pivot)
            j--;

        (*comparacoes)++;
        if (i <= j)
        {
            auto temp = vetorpalavras[i];
            vetorpalavras[i] = vetorpalavras[j];
            vetorpalavras[j] = temp;
            i++;
            j--;

            (*trocas)++;
        }
    }

    (*comparacoes)++;
    if (esquerda < j)
        quickSortPalavras(esquerda, j, comparacoes, trocas);
    (*comparacoes)++;
    if (i < direita)
        quickSortPalavras(i, direita, comparacoes, trocas);
}

void IntercalaNumeros(int inicio, int meio, int fim, unsigned long long *comparacoes, unsigned long long *trocas)
{
    int *vetAux = (int *)malloc(sizeof(int) * (fim + 1));
    int i, j;

    for (i = inicio; i <= meio; i++)
    {
        vetAux[i] = vetornumeros[i];
    }

    for (j = meio + 1; j <= fim; j++)
    {
        vetAux[fim + meio + 1 - j] = vetornumeros[j];
    }

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++)
    {
        (*comparacoes)++;
        if (vetAux[i] <= vetAux[j])
        {
            vetornumeros[k] = vetAux[i];
            i++;
            (*trocas)++;
        }
        else
        {
            vetornumeros[k] = vetAux[j];
            j--;
            (*trocas)++;
        }
    }
    free(vetAux);
}

// FUNÇÃO DE ORDENAÇÃO USANDO O MERGE SORT PARA INTEIROS
void mergeSortNumeros(int inicio, int fim, unsigned long long *comparacoes, unsigned long long int *trocas)
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        mergeSortNumeros(inicio, meio, comparacoes, trocas);
        mergeSortNumeros(meio + 1, fim, comparacoes, trocas);
        IntercalaNumeros(inicio, meio, fim, comparacoes, trocas);
        (*comparacoes)++;
    }
}

void IntercalaPalavras(int inicio, int meio, int fim, unsigned long long *comparacoes, unsigned long long *trocas)
{
    string *vetAux = (string *)calloc(fim + 1, sizeof(string));

    int i, j;
    for (i = inicio; i <= meio; i++)
    {
        vetAux[i] = vetorpalavras[i];
    }

    for (j = meio + 1; j <= fim; j++)
    {
        vetAux[fim + meio + 1 - j] = vetorpalavras[j];
    }

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++)
    {
        (*comparacoes)++;
        if (vetAux[i] <= vetAux[j])
        {
            vetorpalavras[k] = vetAux[i];
            i++;
            (*trocas)++;
        }
        else
        {
            vetorpalavras[k] = vetAux[j];
            j--;
            (*trocas)++;
        }
    }
    free(vetAux);
}

// FUNÇÃO DE ORDENAÇÃO USANDO O MERGE SORT PARA STRINGS
void mergeSortPalavras(int inicio, int fim, unsigned long long *comparacoes, unsigned long long int *trocas)
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        mergeSortPalavras(inicio, meio, comparacoes, trocas);
        mergeSortPalavras(meio + 1, fim, comparacoes, trocas);
        IntercalaPalavras(inicio, meio, fim, comparacoes, trocas);
        (*comparacoes)++;
    }
}

// FUNÇÃO PARA IMPRIMIR INTEIROS
void imprimirNumeros()
{
    for (int i = 0; i < vetornumeros.size(); i++)
    {
        cout << vetornumeros[i] << endl;
    }
    vetornumeros.clear();
}

// FUNÇÃO PARA IMPRIMIR STRINGS
void imprimirPalavras()
{
    for (int i = 0; i < vetorpalavras.size(); i++)
    {
        cout << vetorpalavras[i] << endl;
    }
    vetorpalavras.clear();
}

// FUNÇÃO PARA ORDENAR VETORES INTEIROS
void ordenaVetoresInt(int opMetodos)
{
    unsigned long long comparacoes = 0;
    unsigned long long trocas = 0;

    if (opMetodos == 1)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        bubbleSortNumeros(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempoExecucao = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirNumeros();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas: " << trocas << endl;
        cout << "Tempo total: " << tempoExecucao.count() << endl;
    }
    else if (opMetodos == 2)
    {

        steady_clock::time_point tempoinicial = steady_clock::now();
        insertionSortNumeros(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempoExecucao = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirNumeros();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas: " << trocas << endl;
        cout << "Tempo total: " << tempoExecucao.count() << endl;
    }
    else if (opMetodos == 3)
    {

        steady_clock::time_point tempoinicial = steady_clock::now();
        selectionSortNumeros(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempoExecucao = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirNumeros();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas: " << trocas << endl;
        cout << "Tempo total: " << tempoExecucao.count() << endl;
    }
    else if (opMetodos == 4)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        shellSortNumeros(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempoExecucao = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirNumeros();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas: " << trocas << endl;
        cout << "Tempo total: " << tempoExecucao.count() << endl;
    }
    else if (opMetodos == 5)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        quickSortNumeros(0, vetornumeros.size() - 1, &comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempoExecucao = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirNumeros();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas: " << trocas << endl;
        cout << "Tempo total: " << tempoExecucao.count() << endl;
    }
    else if (opMetodos == 6)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        mergeSortNumeros(0, vetornumeros.size() - 1, &comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempoExecucao = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirNumeros();
        cout << "\nComparaçoes: " << comparacoes << endl;
        cout << "Trocas: " << trocas << endl;
        cout << "Tempo total: " << tempoExecucao.count() << endl;
    }
}

// FUNÇÃO PARA ORDENAR VETORES STRINGS
void ordenaVetoresString(int opMetodos)
{

    unsigned long long comparacoes = 0;
    unsigned long long trocas = 0;

    if (opMetodos == 1)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        bubbleSortPalavras(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirPalavras();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas:  " << trocas << endl;
        cout << "TTempo total: " << tempototal.count() << endl;
    }
    else if (opMetodos == 2)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        insertionSortPalavras(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirPalavras();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas: " << trocas << endl;
        cout << "Tempo total: " << tempototal.count() << endl;
    }
    else if (opMetodos == 3)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        selectionSortPalavras(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirPalavras();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas:  " << trocas << endl;
        cout << "Tempo total: " << tempototal.count() << endl;
    }
    else if (opMetodos == 4)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        shellSortPalavras(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirPalavras();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas:  " << trocas << endl;
        cout << "Tempo total: " << tempototal.count() << endl;
    }
    else if (opMetodos == 5)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        quickSortPalavras(0, vetorpalavras.size() - 1, &comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirPalavras();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas:  " << trocas << endl;
        cout << "Tempo total: " << tempototal.count() << endl;
    }
    else if (opMetodos == 6)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        mergeSortPalavras(0, vetorpalavras.size() - 1, &comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimirPalavras();
        cout << "\nComparacoes feitas: " << comparacoes << endl;
        cout << "Trocas feitas:  " << trocas << endl;
        cout << "Tempo total: " << tempototal.count() << endl;
    }
}

// FUNÇÃO PARA LER ARQUIVOS INTEIROS
vector<int> lerAquivoNumero(string nomeInstancia)
{
    ifstream arquivo(nomeInstancia);

    if (!arquivo.is_open())
    {
        cerr << "NAO FOI POSSIVEL ABRIR O ARQUIVO." << endl;
    }
    else
    {
        int valor;
        while (arquivo >> valor)
        {
            vetornumeros.push_back(valor);
        }
    }
    arquivo.close();
    return vetornumeros;
}

// FUNÇÃO PARA LER ARQUIVOS STRINGS
vector<string> lerArquivoPalavra(string nomeInstancia)
{
    ifstream arquivo(nomeInstancia);

    if (arquivo.is_open())
    {
        string valor;
        while (getline(arquivo, valor))
        {
            vetorpalavras.push_back(valor);
        }
        arquivo.close();
    }
    else
    {
        cerr << "NAO FOI POSSIVEL ABRIR O ARQUIVO." << endl;
    }

    return vetorpalavras;
}

string defineInstancia(int opMetodos, int opInstancia)
{

    string nomeInstancia;

    if (opInstancia == 1)
    {
        nomeInstancia = "../ListaAleatoria-1000.txt";
    }
    else if (opInstancia == 2)
    {
        nomeInstancia = "../ListaAleatoria-10000.txt";
    }
    else if (opInstancia == 3)
    {
        nomeInstancia = "../ListaAleatoria-100000.txt";
    }
    else if (opInstancia == 4)
    {
        nomeInstancia = "../ListaAleatoria-1000000.txt";
    }
    else if (opInstancia == 5)
    {
        nomeInstancia = "../ListaInversamenteOrdenada-1000.txt";
    }
    else if (opInstancia == 6)
    {
        nomeInstancia = "../ListaInversamenteOrdenada-10000.txt";
    }
    else if (opInstancia == 7)
    {
        nomeInstancia = "../ListaInversamenteOrdenada-100000";
    }
    else if (opInstancia == 8)
    {
        nomeInstancia = "../ListaInversamenteOrdenada-1000000";
    }
    else if (opInstancia == 9)
    {
        nomeInstancia = "../ListaOrdenada-1000.txt";
    }
    else if (opInstancia == 10)
    {
        nomeInstancia = "../ListaOrdenada-10000.txt";
    }
    else if (opInstancia == 11)
    {
        nomeInstancia = "../ListaOrdenada-100000.txt";
    }
    else if (opInstancia == 12)
    {
        nomeInstancia = "../ListaOrdenada-1000000.txt";
    }
    else if (opInstancia == 13)
    {
        nomeInstancia = "../ListaQuaseOrdenada-1000.txt";
    }
    else if (opInstancia == 14)
    {
        nomeInstancia = "../ListaQuaseOrdenada-10000.txt";
    }
    else if (opInstancia == 15)
    {
        nomeInstancia = "../ListaQuaseOrdenada-100000.txt";
    }
    else if (opInstancia == 16)
    {
        nomeInstancia = "../ListaQuaseOrdenada-1000000.txt";
    }
    else if (opInstancia == 17)
    {
        nomeInstancia = "../DicionarioAleatorio-29855.txt";
    }
    else if (opInstancia == 18)
    {
        nomeInstancia = "../DicionarioAleatorio-261791.txt";
    }
    else if (opInstancia == 19)
    {
        nomeInstancia = "../DicionarioInversamenteOrdenado-29855.txt";
    }
    else if (opInstancia == 20)
    {
        nomeInstancia = "../DicionarioInversamenteOrdenado-261791.txt";
    }
    else if (opInstancia == 21)
    {
        nomeInstancia = "../DicionarioOrdenado-29855.txt";
    }
    else if (opInstancia == 22)
    {
        nomeInstancia = "../DicionarioOrdenado-261791.txt";
    }
    return nomeInstancia;
}
