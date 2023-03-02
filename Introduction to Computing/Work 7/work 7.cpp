#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

typedef struct
{
    float rendaMensal;
    int ocupantes;
    int ocupantesIdadeEscolar;
    string endereco;
} Domicilio;

void lerDados(Domicilio *array, int tamanho);
void insertionSort(Domicilio *array, int tamanho);
void menu();
void configuracaoMenu(Domicilio *array, int tamanho, int opcao);
int main()
{
    cout << "Digite quantos domicilios quer registrar: ";
    int quantidade;
    cin >> quantidade;
    quantidade++; // para ser usado como sentinela no Insertion Sort.

    Domicilio domicilio[quantidade];
    cout << "\n";

    lerDados(domicilio, quantidade);
    insertionSort(domicilio, quantidade);

    menu();
    cout << "Digite uma opcao: ";
    int num; // resposta do menu
    cin >> num;
    cout << "\n";
    configuracaoMenu(domicilio, quantidade, num); // seleciona uma das opções do menu.

    return 0;
}
void lerDados(Domicilio *array, int tamanho)
{
    for (int i = 1; i < tamanho; i++)
    {
        cout << "Digite a renda mensal do " << i << " domicilio: ";
        cin >> array[i].rendaMensal;

        cout << "Digite o numero de ocupantes do " << i << " domicilio: ";
        cin >> array[i].ocupantes;

        cout << "Digite o endereco do " << i << " domicilio: ";
        cin.ignore(); // Linhas 50 e 51 para limpar buffer.
        getline(cin, array[i].endereco);

        cout << "Digite o numero de ocupantes em idade escolar do " << i << " domicilio: ";
        cin >> array[i].ocupantesIdadeEscolar;

        cout << "\n";
    }
}
void insertionSort(Domicilio *array, int tamanho)
{
    Domicilio aux;
    for (int i = 2; i < tamanho; i++)
    {
        aux = array[i];
        array[0].endereco = aux.endereco;
        int j = i;

        while (aux.endereco < array[j - 1].endereco)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
}
void menu()
{
    cout << "- - - -  - - -   -   -   -   MENU - - - -  -  -  -   -   -   -\n\n";
    cout << "1. Listar domicilios e suas informacoes \n";
    cout << "2. Buscar dados de um determinado endereco de domicilio.\n";
    cout << "3. Sair\n\n";
}
void configuracaoMenu(Domicilio *array, int tamanho, int opcao)
{ // Realiza uma das opções do menu.
    switch (opcao)
    {
        case 1:
        {
            for (int i = 1; i < tamanho; i++)
            {
                cout << "Renda mensal do " << i << " domicilio: " << array[i].rendaMensal << "\n";

                cout << "Numero de ocupantes do " << i << " domicilio: " << array[i].ocupantes << "\n";

                cout << "Endereco do " << i << " domicilio: " << array[i].endereco << "\n";

                cout << "Numero de ocupantes em idade escolar do " << i << " domicilio: " << array[i].ocupantesIdadeEscolar << "\n";
                cout << "\n";
            }
            break;
        }
        case 2:
        {
            cout << "Digite um endereco: ";
            string endereco;
            cin.ignore();
            getline(cin, endereco);
            cout << "\n";

            int L = 1;
            int R = tamanho - 1;
            int m;

            while (L < R)
            {
                m = floor((L + R) / 2);
                if (array[m].endereco < endereco)
                    L = m + 1;
                else
                    R = m;
            }

            if (array[R].endereco.compare(endereco) == 0)
            {
                cout << "Renda mensal do domicilio: " << array[R].rendaMensal << "\n";
                cout << "Numero de ocupantes do domicilio: " << array[R].ocupantes << "\n";
                cout << "Endereco do domicilio: " << array[R].endereco << "\n";
                cout << "Numero de ocupantes em idade escolar do domicilio: " << array[R].ocupantesIdadeEscolar << "\n";
            }
            else
                cout << "Endereco nao encontrado.";
            break;
        }
        case 3:
        {
            cout << "Saindo...";
            break;
        }
    }
}
