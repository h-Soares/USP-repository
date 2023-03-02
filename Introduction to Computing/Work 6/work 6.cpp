#include <iostream>
#include <ctime>
using namespace std;

//-----------------MONTAGEM DA MATRIZ-----------------
float **alocaMatriz(int linhas, int colunas);
void desalocaMatriz(float **matriz, int linhas);
void preencheMatriz(float **matriz, int tamanho);
void imprimeMatrizNormal(float **matriz, int tamanho);
//----------------------------------------------------

//-------------------------FUNÇÕES PEDIDAS NA PRÁTICA-------------------------
void imprimeTransposta(float **matriz, int tamanho);
void multiplicaMatrizes(float **matrizA, float **matrizB, int tamanho);
float tracoMatriz(float **matrizB, int tamanho);

int main()
{
    float **matrizA;
    float **matrizB;
    int tamanho;

    cout << "Entre com o tamanho das matrizes: ";
    cin >> tamanho;
    cout << "\n";

    matrizA = alocaMatriz(tamanho, tamanho);
    matrizB = alocaMatriz(tamanho, tamanho);

    cout << "Entre com os valores da matriz A: \n";
    preencheMatriz(matrizA, tamanho);

    cout << "Entre com os valores da matriz B: \n";
    preencheMatriz(matrizB, tamanho);

    cout << "Transposta da matriz A: \n";
    imprimeTransposta(matrizA, tamanho);

    cout << "\nResultado de A * B: \n";
    multiplicaMatrizes(matrizA, matrizB, tamanho);

    float tracoB = tracoMatriz(matrizB, tamanho);
    cout << "\nTraco da matriz B: " << tracoB;

    desalocaMatriz(matrizB, tamanho);
    desalocaMatriz(matrizA, tamanho);

    return 0;
}
//----------------------FUNÇÕES PEDIDAS NA PRÁTICA----------------------
void imprimeTransposta(float **matriz, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            cout << matriz[j][i] << " ";
        }
        cout << "\n";
    }
}
void multiplicaMatrizes(float **matrizA, float **matrizB, int tamanho)
{
    float soma;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            soma = 0;
            for (int k = 0; k < tamanho; k++)
            {
                soma += matrizA[i][k] * matrizB[k][j];
            }
            cout << soma << " ";
        }
        cout << "\n";
    }
}
float tracoMatriz(float **matrizB, int tamanho)
{
    float traco = 0;

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (i == j)
                traco += matrizB[i][j];
        }
    }
    return traco;
}

//-----------------MONTAGEM DA MATRIZ-----------------
float **alocaMatriz(int linhas, int colunas)
{
    float **matriz;

    matriz = new float *[linhas];
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = new float[colunas];
    }
    if (!matriz)
    {
        cout << " Erro na alocacao! ";
        exit(1);
    }

    return matriz;
}
void desalocaMatriz(float **matriz, int linhas)
{

    for (int i = 0; i < linhas; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}
void preencheMatriz(float **matriz, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            cout << "Digite o valor do " << (j + 1) << " elemento da coluna " << (i + 1) << ": ";
            cin >> matriz[i][j];
        }
    }

    cout << "\n";
}

void imprimeMatrizNormal(float **matriz, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
