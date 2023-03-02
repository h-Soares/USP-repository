#include <iostream>
#include <math.h>
using namespace std;

typedef struct
{
    int numeroUSP;
    float notaP1, notaP2, mediaFinal;
} Estudante;

void menu();
int main()
{
    int tamanho, flag = 0, respMenu, respDo; // A flag serve para não deixar escolher nenhuma opção sem ter lido os dados primeiro.
    do
    {
        cout << "Digite quantos alunos quer registrar: ";
        cin >> tamanho;
        if (tamanho > 100)
            cout << "NUMERO MAXIMO: 100 ESTUDANTES\n\n";
    } while (tamanho > 100);

    Estudante aluno[tamanho];

    do
    {
        menu();
        cout << "\n\nEscolha uma opcao do menu: ";
        cin >> respMenu;
        cout << "\n";

        switch (respMenu)
        {
        case 1:
        {
            for (int i = 0; i < tamanho; i++)
            {
                cout << "Digite o numero USP do aluno " << i + 1 << " : ";
                cin >> aluno[i].numeroUSP;

                cout << "Digite a nota da primeira prova do aluno " << i + 1 << " : ";
                cin >> aluno[i].notaP1;

                cout << "Digite a nota da segunda prova do aluno " << i + 1 << " : ";
                cin >> aluno[i].notaP2;

                aluno[i].mediaFinal = (aluno[i].notaP1 + aluno[i].notaP2) / 2;
                flag = 1;
                cout << "\n";
            }
            break;
        }

        case 2:
        {
            if (flag == 0)
            {
                cout << "Nenhum estudante cadastrado ainda!\n";
                break;
            }
            else if (flag == 1)
            {
                int numUSP;
                bool igual = false;
                cout << "Digite o numero USP do estudante que deseja saber os dados: ";
                cin >> numUSP;
                for (int i = 0; i < tamanho; i++)
                {
                    if (aluno[i].numeroUSP == numUSP)
                    {
                        igual = true;
                        cout << "\nDados do aluno " << numUSP << ": \n\n";
                        cout << "Nota da primeira prova: " << aluno[i].notaP1 << "\n";
                        cout << "Nota da segunda prova: " << aluno[i].notaP2 << "\n";
                        cout << "Media final: " << aluno[i].mediaFinal << "\n";
                    }
                }
                if (igual == false)
                    cout << "\nAluno nao encontrado.\n";
            }
            break;
        }

        case 3:
        {
            if (flag == 0)
            {
                cout << "Nenhum estudante cadastrado ainda!\n";
                break;
            }
            else if (flag == 1)
            {
                float mediaNotasFinais = 0;
                float somatorioDP = 0, DP;

                for (int i = 0; i < tamanho; i++)
                    mediaNotasFinais += aluno[i].mediaFinal;

                mediaNotasFinais /= tamanho;

                for (int i = 0; i < tamanho; i++)
                    somatorioDP += pow((aluno[i].mediaFinal - mediaNotasFinais), 2);

                DP = sqrt((somatorioDP / (tamanho - 1)));

                cout << "A media da media final de todos os alunos e: " << mediaNotasFinais << "\n";
                if (tamanho != 1)
                    cout << "O desvio padrao da media final de todos os alunos e: " << DP << "\n";
                break;
            }
        }

        case 4:
        {
            break;
        }

        default:
            cout << "Opcao invalida!";
        }

        if (respMenu != 4)
        {
            cout << "\nAperte qualquer numero.\n"; // Isso foi feito para pausar a tela e não perder os dados escritos.
            cin >> respDo;
        }

        system("cls || clear"); // Limpa a tela no windows OU no Linux
        if (respMenu == 4)
            cout << "Saindo...";
    } while (respMenu != 4);

    return 0;
}
void menu()
{
    cout << "\n- - - -  - - -   -   -   -   MENU - - - -  -  -  -   -   -   -\n\n";
    cout << "1 - Entrar com dados\t\t\t2 - Mostrar dados\n";
    cout << "3 - Mostrar media e desvio padrao\t4 - Sair";
}
