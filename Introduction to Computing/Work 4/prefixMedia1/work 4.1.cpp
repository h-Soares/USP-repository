#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//                      prefixMedia1

void funcVet1(float *vet1, float *vetorA, int tamanho);
void umNoVetor(float *vetor, int tamanho);
void escreveVetor(float *vetor, int tamanho);
int main()
{ 

    int tamanhoVetor;
    clock_t tempoInicio, tempoFim;
    double tempoTotal;

    cout << "Digite o tamanho do vetor: ";
    cin >> tamanhoVetor;

    float *vetor1 = new float[tamanhoVetor];
    float *vetorA = new float[tamanhoVetor];

    tempoInicio = clock();
    umNoVetor(vetor1, tamanhoVetor);
    funcVet1(vetor1, vetorA, tamanhoVetor);
    // escreveVetor(vetorA, tamanhoVetor);
    tempoFim = clock();

    tempoTotal = difftime(tempoFim, tempoInicio) / CLOCKS_PER_SEC;

    cout << "TEMPO TOTAL : " << tempoTotal << " segundos.\n";

    delete[] vetor1;
    delete[] vetorA;

    return 0;
}
void funcVet1(float *vet1, float *vetorA, int tamanho)
{
    float a;
    for (int i = 0; i < tamanho; i++)
    {
        a = 0;
        for (int j = 0; j < i; j++)
        {
            a += vet1[j];
        }
        vetorA[i] = a / (i + 1);
    }
}

void umNoVetor(float *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        vetor[i] = 1;
}

void escreveVetor(float *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        cout << vetor[i] << " ";
}
