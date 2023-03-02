#include <iostream>
#include <cmath>
#include <ctime> //para gerar vetor aleatório.
using namespace std;
 
void insertionSort(int *array, int lenght);
void binaryInsertionSort(int *array, int lenght);
void selectionSort(int *array, int lenght);
void bubbleSort(int *array, int lenght);
//mergeSort:
void merge(int *array, int L, int h, int R, int *aux);
void mpass(int *array, int lenght, int p, int *aux);
void mergeSort(int *array, int lenght);
//heapSort:
void heapify(int *array, int L, int R); 
void heapSort(int *array, int lenght);
//quickSort:
void qsort(int *array, int L, int R);
void quickSort(int *array, int lenght);
//Funções auxiliares:
void menuVetor();
void menuAlgoritmo();
void mostrarVetor(int *array, int lenght);
void vetorCrescente(int *array, int lenght);
void vetorDecrescente(int *array, int lenght);
void vetorAleatorio(int *array, int lenght);
//Contadores:
int insertionComparacoes = 0;
int insertionMovimentacoes = 0;
int binaryInsertionComparacoes = 0;
int binaryInsertionMovimentacoes = 0;
int selectionComparacoes = 0;
int selectionMovimentacoes = 0;
int bubbleComparacoes = 0;
int bubbleMovimentacoes = 0;
int heapComparacoes = 0;
int heapMovimentacoes = 0;
int mergeComparacoes = 0;
int mergeMovimentacoes = 0;
int quickComparacoes = 0;
int quickMovimentacoes = 0;
int main()
{
    cout << "Tamanho do vetor:";
    int tamanho;
    cin >> tamanho;
    int vetor[tamanho + 1]; //para começar do 1.

    menuVetor();
    int respVetor;
    cin >> respVetor;

    switch(respVetor)
    {
        case 1:
        {
            vetorCrescente(vetor, tamanho);  
            break; 
        }
        case 2: 
        {
            vetorDecrescente(vetor, tamanho);  
            break;
        }
        case 3:
        {
            vetorAleatorio(vetor, tamanho);    
            break;
        }
        default:
        {
            cout << "Opcao invalida.";
        }
    }

    menuAlgoritmo();
    int respAlgoritmo;
    cin >> respAlgoritmo;

    switch(respAlgoritmo)
    {
        case 1:
        {
            insertionSort(vetor, tamanho);  
            break;  
        }
        case 2:
        {
            binaryInsertionSort(vetor, tamanho);
            break;
        }
        case 3:
        {
            selectionSort(vetor, tamanho);
            break;
        }
        case 4:
        {
            bubbleSort(vetor, tamanho); 
            break;
        }
        case 5:
        {
            heapSort(vetor, tamanho);
            break;
        }
        case 6:
        {
            mergeSort(vetor, tamanho);
            break;
        }
        case 7:
        {
            quickSort(vetor, tamanho);
            break;
        }
        default:
        {
            cout << "Opcao invalida.";
        }
    }

    cout << "\n";    
    mostrarVetor(vetor, tamanho);

    return 0;
}
void insertionSort(int *array, int lenght)
{

    for(int i = 2; i <= lenght; i++)
    {
        int key = array[i];
        array[0] = key;
        int j = i;

        insertionComparacoes++;
        while(key < array[j - 1])
        {
            insertionComparacoes++;
            array[j] = array[j - 1];
            insertionMovimentacoes++;
            j--;
        }
        array[j] = key;
        insertionMovimentacoes += 3;
    }
    cout << "\nCOMPARACOES: " << insertionComparacoes << "\n";
    cout << "MOVIMENTACOES: " << insertionMovimentacoes << "\n";
}
void binaryInsertionSort(int *array, int lenght)
{

    for(int i = 2; i <= lenght; i++)
    {
        int key = array[i];
        binaryInsertionMovimentacoes++;
        int L = 1;
        int R = i;

        while(L < R)
        {
            int middle = floor((L + R) / 2);

            binaryInsertionComparacoes++;
            if(array[middle] <= key)
                L = middle + 1;
            else
                R = middle;
        }

        int j = i;

        while(j > R)
        {
            array[j] = array[j - 1];
            binaryInsertionMovimentacoes++;
            j--;
        }
        array[R] = key;
        binaryInsertionMovimentacoes++;
    }
    cout << "\nCOMPARACOES: " << binaryInsertionComparacoes << "\n";
    cout << "MOVIMENTACOES: " << binaryInsertionMovimentacoes << "\n";
}
void selectionSort(int *array, int lenght)
{
    int indice_menor, aux;
    for(int i = 1; i <= (lenght - 1); i++)
    {
        indice_menor = i;
        for(int j = i + 1; j <= lenght; j++)
        {
            selectionComparacoes++;
            if(array[j] < array[indice_menor])
                indice_menor = j;
        }
        aux = array[i];
        array[i] = array[indice_menor];
        array[indice_menor] = aux;
        selectionMovimentacoes += 3;
    }
    cout << "\nCOMPARACOES: " << selectionComparacoes << "\n";
    cout << "MOVIMENTACOES: " << selectionMovimentacoes << "\n";
}
void bubbleSort(int *array, int lenght)
{
    int aux;
    for(int i = 2; i <= lenght; i++)
    {
        for(int j = lenght; j >= i; j--)
        {
            bubbleComparacoes++;
            if(array[j - 1] > array[j])
            {
                aux = array[j - 1];
                array[j - 1] = array[j];
                array[j] = aux;   
                bubbleMovimentacoes += 3; 
            }
        }
    }
    cout << "\nCOMPARACOES: " << bubbleComparacoes << "\n";
    cout << "MOVIMENTACOES: " << bubbleMovimentacoes << "\n";
}
//mergeSort:
void merge(int *array, int L, int h, int R, int *aux)
{
    int i = L, j = h + 1, k = L - 1;

    while(i <= h && j <= R)
    {
        k++;
        mergeComparacoes++;
        if(array[i] < array[j])
        {
            aux[k] = array[i];
            mergeMovimentacoes++;
            i++;
        }
        else
        {
            aux[k] = array[j];
            mergeMovimentacoes++;
            j++;
        }
    }

    while(i <= h)
    {
        k++;
        aux[k] = array[i];
        mergeMovimentacoes++;
        i++;
    }
    while(j <= R)
    {
        k++;
        aux[k] = array[j];
        mergeMovimentacoes++;
        j++;
    }
}
void mpass(int *array, int lenght, int p, int *aux)
{
    int i = 1;
    while(i <= (lenght - 2 * p + 1))
    {
        merge(array, i, i + p - 1,i + 2 * p - 1, aux);
        i = i + 2 * p; 
    }

    if((i + p - 1) < lenght)
        merge(array, i, i + p - 1, lenght, aux);
    else
    {
        for(int j = i; j <= lenght; j++)
        {
            aux[j] = array[j];
            mergeMovimentacoes++;
        }
    }
}
void mergeSort(int *array, int lenght) 
{
    int aux[lenght];
    int p = 1;

    while(p < lenght)
    {
        mpass(array, lenght, p, aux);
        p = 2 * p;
        mpass(aux, lenght, p, array);
        p = 2 * p;
    }
    cout << "\nCOMPARACOES: " << mergeComparacoes << "\n";
    cout << "MOVIMENTACOES: " << mergeMovimentacoes << "\n";
}
//heapSort:
void heapify(int *array, int L, int R)    
{
    int i = L, j = 2 * L, x = array[L];
    heapMovimentacoes++;

    heapComparacoes++;
    if((j < R) && (array[j] < array[j + 1]))
        j++;
    
    heapComparacoes++;
    while((j <= R) && (x < array[j]))
    {
        heapComparacoes++;
        array[i] = array[j];
        heapMovimentacoes++;
        i = j;
        j = 2 * j;
        
        heapComparacoes++;
        if((j < R) && (array[j] < array[j + 1]))
            j++;
    }
    array[i] = x;
    heapMovimentacoes++;
}
void heapSort(int *array, int lenght) 
{
    for(int L = (lenght / 2); L >= 1; L--)
        heapify(array, L, lenght);
    
    for(int R = lenght; R >= 2; R--)
    {
        int aux = array[1];
        array[1] = array[R];
        array[R] = aux;
        heapMovimentacoes += 3;
        heapify(array, 1, (R - 1));
    }
    cout << "\nCOMPARACOES: " << heapComparacoes << "\n"; //O && de heapify atrapalhou a precisão das comparações.
    cout << "MOVIMENTACOES: " << heapMovimentacoes << "\n";
}
//quickSort:
void qsort(int *array, int L, int R)
{
    int meio = floor((L + R) / 2);
    int i = L, j = R, pivot = array[meio];
    quickMovimentacoes++;

    do{
        quickComparacoes++;
        while(array[i] < pivot)
        {
            i++;  
            quickComparacoes++;
        }

        quickComparacoes++; 
        while(pivot < array[j])
        {
            j--;
            quickComparacoes++;
        }
            
        if(i <= j)
        {
            int aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
            quickMovimentacoes += 3;
        }
    }while(i <= j);

    if(L < j)
        qsort(array, L, j);
    
    if(i < R)
        qsort(array, i, R);
}
void quickSort(int *array, int lenght)
{
    qsort(array, 1, lenght);

    cout << "\nCOMPARACOES: " << quickComparacoes << "\n";
    cout << "MOVIMENTACOES: " << quickMovimentacoes << "\n";
}
//Funções auxiliares:
void vetorCrescente(int *array, int lenght)
{
    int num = 10;
    for(int i = 1; i <= lenght; i++)
    {
        array[i] = num;
        num += 10;
    }       
}
void vetorDecrescente(int *array, int lenght)
{
    int num = 500;
    for(int i = 1; i <= lenght; i++)
    {
        array[i] = num;
        num -= 10;
    }   
}
void vetorAleatorio(int *array, int lenght)
{
    unsigned seed = time(0);
    srand(seed);
    int random  = 0;

    for(int i = 1; i <= lenght; i++)
    {
        random = 1 + rand() % 100000;
        array[i] = random;
    }     
}
void mostrarVetor(int *array, int lenght)
{
    for(int i = 1; i <= lenght; i++)
       cout << array[i] << " ";
}
void menuVetor()
{
    cout << "\nPreencher o vetor de forma: \n";
    cout << "1 - Crescente\t2 - Decrescente\t3 - Aleatoria\n";
}
void menuAlgoritmo()
{
    cout << "\nSelecione um algoritmo de ordenacao: \n";
    cout << "1 - Insercao direta\t2 - Insercao binaria\t3 - Selecao\n";
    cout << "4 - Bubblesort\t5 - Heapsort\t6 - Fusao\t7 - QuickSort\n";
}
