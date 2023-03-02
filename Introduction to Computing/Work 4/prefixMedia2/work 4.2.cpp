#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

//                    prefixMedia2

void funcVet2(float *vet2, float *vetorA, int tamanho);
void preencheVetor(float *vetor, int tamanho);
void escreveVetor(float *vetor, int tamanho);
int main()
{
    int tamanhoVetor;
    clock_t tempoInicio, tempoFim;
    double tempoTotal;

    cout << "Digite o tamanho do vetor: ";
    cin >> tamanhoVetor;

    float *vetor2 = new float[tamanhoVetor];
    float *vetorA = new float[tamanhoVetor];

    tempoInicio = clock();
    preencheVetor(vetor2, tamanhoVetor);
    funcVet2(vetor2, vetorA, tamanhoVetor);
    // escreveVetor(vetorA, tamanhoVetor);
    tempoFim = clock();

    tempoTotal = difftime(tempoFim, tempoInicio) / CLOCKS_PER_SEC;

    cout << "TEMPO TOTAL : " << tempoTotal << " segundos.\n";

    delete[] vetor2;
    delete[] vetorA;

    return 0;
}
void funcVet2(float *vet2, float *vetorA, int tamanho)
{
    float s = 0;

    for (int i = 0; i < tamanho; i++)
    {
        s += vet2[i];
        vetorA[i] = s / (i + 1);
    }
}

void preencheVetor(float *vetor, int tamanho)
{
    unsigned seed = time(0);

    srand(seed);

    for (int i = 0; i < tamanho; i++)
        vetor[i] = rand() % 11;
}

void escreveVetor(float *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        cout << vetor[i] << " ";
}
