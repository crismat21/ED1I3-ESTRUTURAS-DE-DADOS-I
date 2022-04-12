#include <iostream>
#include <string>
#include <stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    int baralho[4][26];
    int naipes[4] = {26,26,26,26};
    int baralhoAtual, cartaAtual;
    bool cartaRep = false;
    
    srand(time(NULL));
    
    //zerando a matriz
    for(int i = 0; i < 4; i++) {
		for(int x = 0; x < 26; x++){
			baralho[i][x] = 0;	
		}
	}
    
    //distribuindo as cartas
    for(int i = 0; i < 4; i++) {
		for(int x = 0; x < 11; x++){
			
			do {
				cartaRep = false;
				baralhoAtual = rand() % (4+1-1)+1;
				
				if(naipes[baralhoAtual-1] == 0) {
					cartaRep = true;
				}else {
				
					cartaAtual = rand() % (26+1-1)+1;
					
					if(baralho[baralhoAtual-1][cartaAtual-1] != 0) {
						cartaRep = true;
					}else {
						baralho[baralhoAtual-1][cartaAtual-1] = i+1;
						naipes[baralhoAtual-1]--;
					}
				}

			}while(cartaRep);
			
		}
	}
	
	//mostrando as cartas
	for(int i = 0; i < 4; i++) {
		cout << "Jogador " << i+1 << endl;
		for(int y = 0; y < 4; y++){
			for(int x = 0; x < 26; x++){
				if(baralho[y][x] == i+1) {
					
					//cout << traduzCarta(y+1, x+1);
					if(x > 13) {
						if(x-12 >= 10){
							cout << y+1 << "-" << x-12 << "-2 | ";
						}else{
							cout << y+1 << "-" << "0" << x-12 << "-2 | ";
						}
					}else {
						if(x+1 >= 10){
							cout << y+1 << "-" << x+1 << "-1 | ";
						}else{
							cout << y+1 << "-" << "0" << x+1 << "-1 | ";
						}
					}
				}
			}
		}
		cout << endl;
		cout << endl;
	}
    	
    return 0;       
}