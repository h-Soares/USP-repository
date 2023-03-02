#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

typedef struct
{
    string nome;
    int numInscricao;
} Registro;

void qsort(Registro *array, int L, int R);
void quickSort(Registro *array, int lenght);
void lerDados(Registro *array, int lenght);
void imprimeDados(Registro *array, int lenght);
//--------------------------------------------//
int compChaves = 0;
int movimentacoes = 0;
int chamadas = 0;
int main()
{
    cout << "Tamanho do vetor:";
    int tamanho;
    cin >> tamanho;
    Registro vetor[tamanho + 1];

    lerDados(vetor, tamanho);
    quickSort(vetor, tamanho);
    imprimeDados(vetor, tamanho);

    cout << "COMPARACOES: " << compChaves << "\n";
    cout << "MOVIMENTACOES: " << movimentacoes << "\n";
    cout << "CHAMADAS: " << chamadas << "\n";

    return 0;
}
// quickSort:
void qsort(Registro *array, int L, int R)
{
    chamadas++;
    int i = L;
    int j = R;
    int meio = floor((L + R) / 2);
    Registro pivot = array[meio];
    movimentacoes++;
    Registro aux; // para fazer uma cópia auxiliar do registro.

    do
    {
        compChaves++;
        while (array[i].numInscricao < pivot.numInscricao)
        {
            i++;
            compChaves++;
        }

        compChaves++;
        while (pivot.numInscricao < array[j].numInscricao)
        {
            j--;
            compChaves++;
        }

        if (i <= j)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            movimentacoes += 3;
            i++;
            j--;
        }
    } while (i <= j);

    if (L < j)
    {
        qsort(array, L, j);
    }

    if (i < R)
    {
        qsort(array, i, R);
    }
}
void quickSort(Registro *array, int lenght)
{
    qsort(array, 1, lenght);
}
// Funções auxiliares:
void lerDados(Registro *array, int lenght)
{
    for (int i = 1; i <= lenght; i++)
    {
        cout << "Digite o nome do " << i << " registro: ";
        cin >> array[i].nome;

        cout << "Digite o numero de inscricao do " << i << " registro:";
        cin >> array[i].numInscricao;

        cout << "\n";
    }
}
void imprimeDados(Registro *array, int lenght)
{
    for (int i = 1; i <= lenght; i++)
        cout << array[i].numInscricao << " ";

    cout << "\n";
}
