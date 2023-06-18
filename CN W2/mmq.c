#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define E exp(1.0)
#define MAX_POINTS 101 // Número máximo de pontos (t_i, y_i)
#define FILENAME "dados.txt"

void fillVectorsByFile(double *vet1, double *vet2);

//FUNÇÃO 1: Funções para aproximar por g(x) = a*e^(b*x)
//por a1 = lna, a2 = b, encontra-se a e b e tem-se a g(x).
double* getLnVector(double *vector);
void getAnswerOne(double *vector_t, double *vector_y);
void residualsSquaredOne(double *vector_t, double *vector_y);
void R2One(double *vector_t, double *vector_y);

//FUNÇÃO 2: Funções para aproximar por g(x) = a + bx
void getAnswer2(double *vector_t, double *vector_y);
void residualsSquaredTwo(double *vector_t, double *vector_y);
void R2Two(double *vector_t, double *vector_y);

int main() {
    double t[MAX_POINTS]; // Array para armazenar t_i
    double y[MAX_POINTS]; // Array para armazenar y_i

    fillVectorsByFile(t,y);

    //FUNÇÃO 1:
    printf("APROXIMACAO POR g(x) = a*e^(b*x)\n");
    getAnswerOne(t,y);
    residualsSquaredOne(t,y);
    R2One(t,y);

    //FUNÇÃO 2:
    printf("\n\nAPROXIMACAO POR g(x) = a + b*x\n");
    getAnswer2(t,y);
    residualsSquaredTwo(t,y);
    R2Two(t,y);

    return 0;
}
void fillVectorsByFile(double *vet1, double *vet2) {
    FILE *file;
    char *fileName = FILENAME; // Nome do arquivo de dados

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(0);
    }

    int i = 0;
    // Lendo os pontos do arquivo
    while (!feof(file) && i < MAX_POINTS) {
        fscanf(file, "%lf %lf", &vet1[i], &vet2[i]);
        i++;
    }
    fclose(file);
}
//FUNÇÃO 1: Funções para aproximar por g(x) = a*e^(b*x)
//por a1 = lna, a2 = b, encontra-se a e b e tem-se a g(x).
double* getLnVector(double *vector) {
    double* LnVector = (double*)malloc(MAX_POINTS * sizeof(double));
    for(int i = 0; i < MAX_POINTS; i++)
        LnVector[i] = log(vector[i]); 
    return LnVector;
}
void getAnswerOne(double *vector_t, double *vector_y) {
    //Realizando os somatórios necessários:
    double sum1 = MAX_POINTS;

    double sumXi = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        sumXi += vector_t[i];

    double sumXi2 = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        sumXi2 += vector_t[i] * vector_t[i];

    //getLnVector para encontrar F(Xi) = ln(f(xi)) = ln(vector_y[xi])
    double* LnVector = getLnVector(vector_y);
    double sumFi = 0;
    for(int i = 0; i < MAX_POINTS; i++) 
        sumFi += LnVector[i];

    double sumXiFi = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        sumXiFi += vector_t[i] * LnVector[i];
    
    double denominator = sum1 * sumXi2 - sumXi * sumXi;
    double a = (sumFi * sumXi2 - sumXi * sumXiFi)/denominator;
    double b = (sum1 * sumXiFi - sumXi * sumFi)/denominator;

    printf("A funcao encontrada e: %.8lf * e^(%.8lf * x)\n", exp(a), b);
    free(LnVector);
}
void residualsSquaredOne(double *vector_t, double *vector_y) {
    double* F = getLnVector(vector_y);

    double g[MAX_POINTS];
    for(int i = 0; i < MAX_POINTS; i++)
        g[i] = 0.92010736 * pow(E, 0.10551507 * vector_t[i]); //vem de getAnswerOne

    double* G = getLnVector(g);

    double result = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        result += pow(F[i] - G[i], 2);

    free(F);
    free(G);

    printf("A soma dos residuos ao quadrado de (F - G) e: %.8lf\n", result);
}
void R2One(double *vector_t, double *vector_y) {
    double SQRes = 0;
    double g[MAX_POINTS];
    for(int i = 0; i < MAX_POINTS; i++)
        g[i] = 0.92010736 * pow(E, 0.10551507 * vector_t[i]);
    for(int i = 0; i < MAX_POINTS; i++)
        SQRes += pow(vector_y[i] - g[i], 2);

    double fxiSum = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        fxiSum += vector_y[i];
    double y_ = fxiSum / MAX_POINTS;
    
    double SQtot = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        SQtot += pow(vector_y[i] - y_, 2);
    
    double R2 = 1 - SQRes / SQtot;
    printf("O coeficiente R2 para essa aproximacao e: %.8lf", R2);
}
//FUNÇÃO 2: Funções para aproximar por g(x) = a + bx
void getAnswer2(double *vector_t, double *vector_y) {
    //Realizando os somatórios necessários:
    double sum1 = MAX_POINTS;

    double sumXi = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        sumXi += vector_t[i];

    double sumXi2 = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        sumXi2 += vector_t[i] * vector_t[i];

    double sum_fi = 0;
    for(int i = 0; i < MAX_POINTS; i++) 
        sum_fi += vector_y[i];

    double sumXifi = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        sumXifi += vector_t[i] * vector_y[i];
    
    double denominator = sum1 * sumXi2 - sumXi * sumXi;
    double a = (sum_fi * sumXi2 - sumXi * sumXifi)/denominator;
    double b = (sum1 * sumXifi - sumXi * sum_fi)/denominator;

    printf("A funcao encontrada e: %.8lf + %.8lf * x\n", a, b);
}
void residualsSquaredTwo(double *vector_t, double *vector_y) {
    double g[MAX_POINTS]; 
    for(int i = 0; i < MAX_POINTS; i++)
        g[i] = -0.14386711 + 0.33974452 * vector_t[i]; //vem de getAnswerTwo
    
    double result = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        result += pow(vector_y[i] - g[i], 2);
    
    printf("A soma dos residuos ao quadrado de (f - g) e: %.8lf\n", result);
}
void R2Two(double *vector_t, double *vector_y) {
    double SQRes = 0;
    double g[MAX_POINTS]; 
    for(int i = 0; i < MAX_POINTS; i++)
        g[i] = -0.14386711 + 0.33974452 * vector_t[i]; 
    for(int i = 0; i < MAX_POINTS; i++)
        SQRes += pow(vector_y[i] - g[i], 2);

    double sum_fi = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        sum_fi += vector_y[i];
    double y_ = sum_fi / MAX_POINTS;

    double SQtot = 0;
    for(int i = 0; i < MAX_POINTS; i++)
        SQtot += pow(vector_y[i] - y_, 2);
    
    double R2 = 1 - SQRes / SQtot;
    printf("O coeficiente R2 para essa aproximacao e: %.8lf", R2);
}