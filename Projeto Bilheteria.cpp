#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#define LIN 15
#define COL 40

void limpaSala(char **x)
{
    for(int i=0; i<LIN; ++i)
    {
        for(int j=0; j<COL; ++j)
        {
            x[i][j] = '.';
        }
    }
}

void mostraSala(char **x)
{
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for(int i=0; i<LIN; ++i)
	{
		cout << "| ";
		for(int j=0; j<COL; ++j)
		{
			cout << setw(1) << x[i][j] << " | ";
		}
		cout << endl;
	}
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void ocupaLugar(char **x)
{
    int i;
    int j;
    
    cout << "Digite o numero da fileira:" << endl;
    cin >> i;
    cout << endl;
    cout << "Digite o numero da coluna:" << endl;
    cin >> j;
    cout << endl;
    if(x[i - 1][j - 1] == '#')
    {
        cout << "----------------------" << endl << "Lugar reservado!" << endl << "----------------------" << endl;
    }
    else
    {
        x[i - 1][j - 1] = '#';
        cout << "----------------------------" << endl << "Lugar reservado com sucesso!" << endl << "----------------------------" << endl;
    }
}

int contaLugar(char **x)
{
	int k = 0;
	
	for(int i=0; i<LIN; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			if(x[i][j] == '#')
			{
				k++;
			}
		}
	}
	return k;
}

float faturamento(char **x)
{
	float receita = 0;	

	//percorre fileira 1 a 5
	for(int i=0; i<5; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			if(x[i][j] == '#')
			{
				receita += 50;
			}
		}
	}
	//percorre fileira 6 a 10
	for(int i=5; i<10; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			if(x[i][j] == '#')
			{
				receita += 30;
			}
		}
	}
	//percorre fileira 11 a 15
	for(int i=10; i<15; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			if(x[i][j] == '#')
			{
				receita += 15;
			}
		}
	}
	return receita;
}

int main(int argc, char** argv)
{
    char **sala;
    int escolha;
    
    sala = new char*[LIN];
    for(int i=0; i<LIN; ++i)
    {
        sala[i] = new char[COL];
    
    }
    limpaSala(sala);
    do
    {
    	// Interface do menu
        cout << "----------------------" << endl << "0. Finalizar" << endl << "1. Reservar poltrona" << endl << "2. Mapa de ocupacao" << endl << "3. Faturamento" << endl << "----------------------" << endl;
        cin >> escolha;
        switch(escolha)
        {
            case 0:
                cout << "----------------------" << endl << "Programa finalizado!" << endl << "----------------------" << endl;
                break;
            case 1:
                ocupaLugar(sala);
                break;
            case 2:
                mostraSala(sala);
                break;
            case 3:
            	cout << "----------------------------------" << endl << "Quantidade de lugares ocupados: " << contaLugar(sala) << endl;
            	cout << "Valor de bilheteria: " << faturamento(sala) << endl << "----------------------------------" << endl ;
            	break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    }while(escolha != 0);
    return 0;
}