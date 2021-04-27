#include <iostream>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
using namespace std;

struct no
{
    time_t inicio;
    time_t remover;
    struct no *prox;
};

void inserirfila(no **fila, no **fim)
{

    struct tm data;
    no *aux;
    aux = (no *)malloc(sizeof(no));

    if (aux != NULL)
    {
        aux->prox = NULL;
        aux->inicio = time(NULL);
        data = *localtime(&aux->inicio);
    }
    if ((*fila) == NULL)
    {
        (*fila) = aux;
        (*fim) = aux;
    }
    else
    {
        (*fim)->prox = aux;
        (*fim) = aux;
    }
}

int removerfila(no **fila, int *maiort, int *menort, int *soma)
{

    time_t horario;
    struct tm data;

    if ((*fila) == NULL)
    {
        return 0;
    }
    else
    {
        no *aux = (*fila);
        aux->remover = time(NULL);
        data = *localtime(&aux->remover);
        horario = (difftime(aux->remover, aux->inicio));
        if (*maiort < horario)
        {
            *maiort = horario;
        }
        if (*menort > horario)
        {
            *menort = horario;
        }
        (*soma) = (*soma) + horario;
        (*fila) = (*fila)->prox;
        free(aux);
    }
}

void imprimirfila(no *fila)
{
    struct tm data;
    time_t tempofila;
    while (fila != NULL)
    {
        cout << "\n----------------------------------";
        cout << "\n\nFila Comum 1 :";
        data = *localtime(&fila->inicio);
        tempofila = time(NULL);
        cout << " \n Pessoa inserida horario: " << data.tm_hour << ":" << data.tm_min << ":" << data.tm_sec << endl;
        cout << "\nTempo na fila: " << difftime(tempofila, fila->inicio) << " Segundos\n\n";
        fila = fila->prox;
    }
}

void imprimirfila2(no *fila2)
{
    struct tm data;
    time_t tempofila;
    while (fila2 != NULL)
    {
        cout << "\n----------------------------------";
        cout << "\nFila Comum 2 :";
        data = *localtime(&fila2->inicio);
        tempofila = time(NULL);
        cout << " \n Pessoa inserida horario: " << data.tm_hour << ":" << data.tm_min << ":" << data.tm_sec << endl;
        cout << "\nTempo na fila: " << difftime(tempofila, fila2->inicio) << " Segundos\n\n";
        fila2 = fila2->prox;
    }
}

void imprimirpreferencial(no *filapf)
{
    struct tm data;
    time_t tempofila;
    while (filapf != NULL)
    {
        cout << "\n----------------------------------";
        cout << "\n fila preferencial :";
        data = *localtime(&filapf->inicio);
        tempofila = time(NULL);
        cout << " \n Pessoa idosa horario: " << data.tm_hour << ":" << data.tm_min << ":" << data.tm_sec << endl;
        cout << "\nTempo na fila: " << difftime(tempofila, filapf->inicio) << " Segundos\n\n";
        filapf = filapf->prox;
    }
}

void cabechalo()
{
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "         ######## ########        ##" << endl;
    cout << "         #        #       #      #  #" << endl;
    cout << "         #        #       #     #    #" << endl;
    cout << "         ######## #       #    ########" << endl;
    cout << "         #        #       #   #        #" << endl;
    cout << "         #        #       #  #          #" << endl;
    cout << "         ######## ########  #            #" << endl;
    cout << "                                             " << endl;
    cout << "       ######## ##### #             ##" << endl;
    cout << "       #          #   #            #  #" << endl;
    cout << "       #          #   #           #    #" << endl;
    cout << "       #######    #   #          ########" << endl;
    cout << "       #          #   #         #        #" << endl;
    cout << "       #          #   #        #          #" << endl;
    cout << "       #        ##### ####### #            #" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "      Nomes:              |       RA:          " << endl;
    cout << "Lucas Lacerda Feliciano   |  RA: 20061859 " << endl;
    cout << "Matheus das Neves Camargo |  RA: 20156311" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "Opcionais Funcionando: " << endl;
    cout << "1- Tempo real aguardando na fila (2 Pontos)" << endl;
    cout << "2- Fila Preferencial (1 Ponto)" << endl;
    cout << "3- Tempo de remocao diferente para as filas (1 Ponto)" << endl;
    cout << "Valor total: 9 pontos" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

int main()
{
    //cabechalo();
    time_t start;
    time_t end1;
    struct tm hora;

    int maiort = 0, menort = 0;
    int maiort2 = 0, menort2 = 0;
    int quant = 0, quant2 = 0, soma = 0;
    int quant3 = 0, quant4 = 0, soma2 = 0;
    int quant5 = 0, quant6 = 0;
    int quantpf = 0, quantpf2 = 0, quantpf3 = 0;
    int temposimulacao, tempoinsercao, temporemocao;
    int temporemocao2;

    cabechalo();
    cout << "\n Qual sera o tempo da Simulacao: ";
    cin >> temposimulacao;
    cout << "\n Qual sera o tempo de Insercao: ";
    cin >> tempoinsercao;
    cout << "\n Qual sera o tempo de Remocao da fila 1: ";
    cin >> temporemocao;
    cout << "\n Qual sera o tempo de Remocao da fila 2: ";
    cin >> temporemocao2;

    no *fila = NULL;
    no *fila2 = NULL;
    no *fim = NULL;
    no *fim2 = NULL;
    no *filapf = NULL;
    no *fimpf = NULL;
    time(&start);
    time(&end1);

    while ((int)difftime(end1, start) <= temposimulacao)
    {
        cout << "\nTempo de simulacao: " << difftime(end1, start) << " Segundos";

        if ((int)difftime(end1, start) % tempoinsercao == 0 && (int)difftime(end1, start) != 0)
        {

            if (quant < quant2)
            {
                inserirfila(&fila, &fim);
                quant++;
                quant3++;
            }
            else if (quant2 < quant)
            {
                inserirfila(&fila2, &fim2);
                quant2++;
                quant4++;
            }
            else
            {
                inserirfila(&fila, &fim);
                quant++;
                quant3++;
                inserirfila(&fila2, &fim2);
                quant2++;
                quant4++;
            }
        }

        if (kbhit())
        {
            inserirfila(&filapf, &fimpf);
            cin.ignore();
            quantpf++;
            quantpf3++;
        }

        if ((int)difftime(end1, start) % temporemocao == 0 && (int)difftime(end1, start) != 0)
        {
            removerfila(&fila, &maiort, &menort, &soma);
            quant--;
            quant5++;
        }
        if ((int)difftime(end1, start) % temporemocao2 == 0 && (int)difftime(end1, start) != 0)
        {
            removerfila(&fila2, &maiort, &menort, &soma);
            quant2--;
            quant6++;
        }
        if ((int)difftime(end1, start) % temporemocao2 == 0 && (int)difftime(end1, start) != 0 && quantpf > 0)
        {
            removerfila(&filapf, &maiort, &menort, &soma);
            quantpf--;
            quantpf2++;
        }

        imprimirpreferencial(filapf);
        imprimirfila(fila);
        imprimirfila2(fila2);

        Sleep(900);
        system("cls");
        time(&end1);
    }
    cout << "\n *-*-*-*-* Resultado Fila Comum *-*-*-*-*-*";
    cout << "\n Quantidade de pessoas inseridas na fila 1: " << quant3;
    cout << "\n Quantidade de pessoas inseridas na fila  2: " << quant4;
    cout << "\n Quantidade de pessoas removidas da fila 1: " << quant5;
    cout << "\n Quantidade de pessoas removidas da fila 2: " << quant6;
    cout << "\n Quantidade de pessoas nao removidas fila 1: " << quant;
    cout << "\n Quantidade de pessoas nao removidas fila 2: " << quant2;
    cout << "\n Maior tempo de espera da fila : " << maiort;
    cout << "\n Menor tempo de espera da fila :" << menort;
    cout << "\n Tempo medio de pessoas na fila :" << soma / (quant + quant2);
    cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    cout << "\n\n\n *-*-*-*-* Resultado Fila preferencial*-*-*-*-*-*";
    cout << "\n Quantidade de pessoas preferenciais iseridas:" << quantpf3;
    cout << "\n Quantidade de pessoas preferenciais removidas:" << quantpf2;
    cout << "\n Quantidade de pessoas preferenciais nao removidas:" << quantpf;
    cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}
