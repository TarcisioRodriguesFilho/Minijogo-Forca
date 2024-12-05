#include <stdio.h>
#include <string.h>
#include <locale.h>

void forca(int estado){
    if(estado==0){
        printf("\n-------------");
        printf("\n|           |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if(estado==1){
        printf("\n-------------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if(estado==2){
        printf("\n-------------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|           |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if(estado==3){
        printf("\n-------------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|          -|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if(estado==4){
        printf("\n-------------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|          -|-");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if(estado==5){
        printf("\n-------------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|          -|-");
        printf("\n|          /");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if(estado==6){
        printf("\n-------------");
        printf("\n|           |");
        printf("\n|           0");
        printf("\n|          -|-");
        printf("\n|          / \\");
        printf("\n|");
        printf("\n|      Fim de jogo");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    }
}
int main(void){
    setlocale(LC_ALL, "Portuguese");
    char p_chave [100]; //palavra chave
    printf("Jogador 1!\n");
    printf("Informe a palavra chave?:\n");
    scanf("%s", &p_chave);
    //fgets(p_chave, 100, stdin); pode ser utilizado para ter o espaço entre palavras;
    printf("A palavra chave é: %s\n", p_chave);
    printf("A palavra tem %i caracteres.\n", strlen(p_chave));
    for(int i=0; i<100; i++){
        printf("\n");
    }
    char p_tela [100]; //Visão da tela
    strcpy(p_tela, p_chave); //Copia da p_chave
    //p_tela[scanf(p_tela)-1]='\0';
    for(int i=0; i<strlen(p_tela); i++){
        p_tela[i]='_';
    }

    int erros = 0;
    while(1){
    //Imprimir a forca
    forca(erros);
    //Imprimir underline '_' para cada letra usada na palavra chave
    printf("\nOBS: A palavra pode conter letras maiúsculas ou acento, caso não escreva corretamente será considerado um erro!");
    printf("\nAdivinhe: ");
    //printf(p_tela);
    for(int i=0; i<strlen(p_tela); i++){
        printf("%c ", p_tela[i]);
    }
    //Recebe a letra
    printf("\nLetra: ");
    char letra;
    scanf(" %c", &letra);//o espaço que possue no código é por causa de uma repetição que não descobri a causa
    //Se estiver correta atualiza a palavra na tela
    int sera_que_errou=1; //1=sim 0=não
    for(int i=0; i<strlen(p_tela); i++){
        if(letra==p_chave[i]){ //certo
            p_tela[i]=letra;
            sera_que_errou=0;
        }
    }
    //Senão, incrementa o erro
    if(sera_que_errou==1){
        erros++;
    }
    //Verifica se o jogo acabou
    if(strcmp(p_tela,p_chave)==0){
        printf("\nVocê Acertou: ");
        for(int i=0; i<strlen(p_tela); i++){
            printf("%c ", p_tela[i]);
        }
            printf("\n");
            printf("\nParabéns!!!");
            printf("\nParabéns!!!");
            printf("\nParabéns!!!");
        break;
    }
    if(erros==6){
        forca(erros);
            break;
        }
    }
    return 0;
}
