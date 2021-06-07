#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


struct tabuleiro{
	int jogo[4][4];
}comp;

int i, j, linha, coluna, l, c, a, b, k, jkl = 0, s, t, g, soma;
char comando;

int comando_cima(){
    for(coluna = 0; coluna < 4; coluna++){
		s = 0;
		soma = 0;
		while(s < 3){
			for(linha = 0; linha < 3; linha++){
				if(comp.jogo[linha][coluna] == 0){
					k = comp.jogo[linha+1][coluna];
					comp.jogo[linha][coluna] = comp.jogo[linha][coluna] + k;
					comp.jogo[linha+1][coluna] = 0;
				}
				else if(comp.jogo[linha][coluna] == comp.jogo[linha+1][coluna] && soma == 0){
					k = comp.jogo[linha+1][coluna];
					comp.jogo[linha][coluna] = comp.jogo[linha][coluna] + k;
					comp.jogo[linha+1][coluna] = 0;
					soma++;
				}
			}
			s++;
		}
	}
    return 0;
}

int comando_baixo(){
    for(coluna = 0; coluna < 4; coluna++){
		s = 0;
		soma = 0;
		while(s < 3){
			for(linha = 3; linha > 0; linha--){
		    	if(comp.jogo[linha][coluna] == 0){
					k = comp.jogo[linha-1][coluna];
					comp.jogo[linha][coluna] = comp.jogo[linha][coluna] + k;
					comp.jogo[linha-1][coluna] = 0;
				}
				else if(comp.jogo[linha][coluna] == comp.jogo[linha-1][coluna] && soma == 0){
					k = comp.jogo[linha-1][coluna];
					comp.jogo[linha][coluna] = comp.jogo[linha][coluna] + k;
					comp.jogo[linha-1][coluna] = 0;
					soma++;
				}
			}
			s++;
		}
	}
	return 0;
}

int comando_direita(){
	for(linha = 0; linha < 4; linha++){
	    s = 0;
	    soma = 0;
	    while(s < 3){
		    for(coluna = 3; coluna > 0; coluna--){
		    	if(comp.jogo[linha][coluna] == 0){
		    		k = comp.jogo[linha][coluna-1];
		    		comp.jogo[linha][coluna] = comp.jogo[linha][coluna] + k;
		    		comp.jogo[linha][coluna-1] = 0;
		    	}
		    	else if(comp.jogo[linha][coluna] == comp.jogo[linha][coluna-1] && soma == 0){
		    		k = comp.jogo[linha][coluna-1];
		    		comp.jogo[linha][coluna] = comp.jogo[linha][coluna] + k;
			    	comp.jogo[linha][coluna-1] = 0;
			    	soma++;
		    	}
	    	}
		    s++;
	    }
	}
	return 0;
} 

int comando_esquerda(){
    for(linha = 0; linha < 4; linha++){
		s = 0;
		soma = 0;
		while(s < 3){
			for(coluna = 0; coluna < 3; coluna++){
		    	if(comp.jogo[linha][coluna] == 0){
					k = comp.jogo[linha][coluna+1];
					comp.jogo[linha][coluna] = comp.jogo[linha][coluna] + k;
					comp.jogo[linha][coluna+1] = 0;
				}
				else if(comp.jogo[linha][coluna] == comp.jogo[linha][coluna+1] && soma == 0){
					k = comp.jogo[linha][coluna+1];
					comp.jogo[linha][coluna] = comp.jogo[linha][coluna] + k;
					comp.jogo[linha][coluna+1] = 0;
					soma++;
				}	
		    }
			s++;
		}	
	}
	return 0;
}

int main(){
		
		srand(time(NULL));

	for(i=0; i<4; i++){
    	for(j=0; j<4; j++){
        	comp.jogo[i][j] = 0;
    	}
    }
	printf("Para mover pressione:\n");
	printf("\tw: para cima\na: para esquerda  d: para direita\n\ts: para baixo\n");
	printf("Para reiniciar o jogo pressione: r\n");
	printf("Para sair do jogo pressione: q\n");
		
    while(comando != 'q'){	
		jkl = 0;
		while(jkl != 1){
			l = rand() % 4;
			c = rand() % 4;
			b = rand() % 11;
			if(comp.jogo[l][c]==0 && b != 10){
				comp.jogo[l][c] = 2;
				jkl++;
				t++;
			}
			else if(comp.jogo[l][c]==0 && b == 10){
				comp.jogo[l][c] = 4;
				jkl++;
				t++;
			}
		}
		for(i=0; i<4; i++){
		    printf("|");
            for(j=0; j<4; j++){
                if(comp.jogo[i][j] == 0){
                    printf("      |");
                } 
            	else {
                	printf(" %4d |", comp.jogo[i][j]);
				}
			}
			printf("\n");
		}
		a = 0;
        while (a!=1){
			comando = 'p';
			scanf("%c", &comando);
           switch(comando){
                case 'a':
                    comando_esquerda();
                    a++;
                    break;
                case 'd':
                    comando_direita();
                    a++;
                    break;
                case 'w':
                    comando_cima();
                    a++;
                    break;
                case 's':
                    comando_baixo();
                    a++;
                    break;
                case 'r':
                    for(i=0; i<4; i++){
        				for(j=0; j<4; j++){
            				comp.jogo[i][j] = 0;
        				}
    				}
                    a++;
                    break;
				case 'q':
					exit(0);
		   }
			g = 0;
			for(i = 0; i < 4; i++){
				for (j = 0; j < 4; j++){
					if(comp.jogo[i][j] == 2048){
						printf("Parabens! Voce alcancou 2048!\n");
						exit(0);
					}
					else if(comp.jogo[i][j] != 0){
						g++;
						}
					}
				}
			if(g == 16){
				printf("\nGAME OVER\n\n");
				exit(0);
			}
        }
    }

    return 0;
}