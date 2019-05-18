/*----------------------------------------------------------------------------------------------------------------
-                                                                                                              - 
-  NOME:                                                                  MATRICULA:                                                                                                           -  
-  NOME:                                                                  MATRICULA:                           -
-  NOME:                                                                  MATRICULA:                           -
-                                                                                                              -
----------------------------------------------------------------------------------------------------------------
cada escola sera availada em 13 quesitos por 5 juizes, cada um desses quisitos vai ser ponderado por um valor de ponto
flutuante que varia de 7,0 a 10,0*, cada um desses juizes vai ser representado por uma posicao no array*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int contadordeEscolasCad=0;

typedef struct Squesito{
    char nomequesito;
    float avaliacaoJurados[5];
    float notaFinal;

}Quesito;

typedef struct SescolaSamba{
    Quesito quesito[1];
    char nomeEscola[20];
    char nomeResponsavelEscola[20];

}escolas;
//funcao mostra o tamanho de uma string
int stringSize(char * string){
    int contador=0;
    while(string[contador]!='\0')
        contador++;

    return contador;
}
void cadastrarEscola(escolas *escola, int cont){
    int tamanhoNome;
    if(contadordeEscolasCad<=9){
        do{
            printf("Digite o nome da Escola de Samba: \n");
            scanf("%s", escola[cont].nomeEscola);
            tamanhoNome=stringSize(escola[cont].nomeEscola);
        }while(tamanhoNome<8);
    
        printf("Digite o nome do Responsavel pela Escola de Samba: %s \n",escola[cont].nomeEscola);
        scanf("%s", escola[cont].nomeResponsavelEscola);
        contadordeEscolasCad++;
    }
    else{
        printf("\nnumero maximo de escolas ja cadastrado!");
    }
   
}
void AvaliarQuesito(escolas * es,int numeroEscola,int numeroquesito,int numeroJurado){
  
    float nota;
    printf("Digite a nota de avaliação para o quesito : %s",es->nomeEscola);
    scanf("%f", &nota);
    es[numeroEscola].quesito[numeroquesito].avaliacaoJurados[numeroJurado]=nota;

}
void exibirDadosEscola(escolas *es,int numeroescola){
    int qtdQuesitos=1,i=0;
    printf("\n Escola: %s",es[numeroescola].nomeEscola);
    printf("\n Responsavel: %s",es[numeroescola].nomeResponsavelEscola);

    for(i=0;i<qtdQuesitos;i++){
        printf("\n Nota do Quesito : %s",es[numeroescola].quesito[i].nomequesito);
        printf("\n Nota do Avaliador 1: %.2f",es[numeroescola].quesito[i].avaliacaoJurados[0]);
        printf("\n Nota do Avaliador 2: %.2f",es[numeroescola].quesito[i].avaliacaoJurados[1]);
        printf("\n Nota do Avaliador 3: %.2f",es[numeroescola].quesito[i].avaliacaoJurados[2]);
        printf("\n Nota do Avaliador 4: %.2f",es[numeroescola].quesito[i].avaliacaoJurados[3]);
        printf("\n Nota do Avaliador 5: %.2f",es[numeroescola].quesito[i].avaliacaoJurados[4]);
        printf("\n\n Nota Final de %s: %.2f\n\n",es[numeroescola].quesito[i].nomequesito,es[numeroescola].quesito[i].notaFinal);
    }



}

int  buscarEscolaSamba(char * nome, escolas * escolas){
   int numerodaEscola=0,i=0;
   for(i=0;i<10;i++){
       if(strcmp(nome,escolas[i].nomeEscola)==0){
           numerodaEscola=i;
           break;
       }

   }
   exibirDadosEscola(escolas,numerodaEscola);

    return numerodaEscola;
}

void listarEscolas(escolas *es){
    int i=0;
    for(i=0;i<10;i++){
        exibirDadosEscola(es,i);
        printf("\n-----------------------------------------------------------------------");
    }

}
void NotafinalQuesito(escolas * es,int numeroescola,int numeroquesito){
    int i;
    float nota=0,maior=es[numeroescola].quesito[numeroquesito].avaliacaoJurados[0],menor=es[numeroescola].quesito[numeroquesito].avaliacaoJurados[0];
    for(i=0;i<5;i++){
        if(maior<es[numeroescola].quesito[numeroquesito].avaliacaoJurados[i]){
            maior=es[numeroescola].quesito[numeroquesito].avaliacaoJurados[i];
        }
        if(menor<es[numeroescola].quesito[numeroquesito].avaliacaoJurados[i]){
            menor=es[numeroescola].quesito[numeroquesito].avaliacaoJurados[i];
        }
        nota+=es[numeroescola].quesito[numeroquesito].avaliacaoJurados[i];
    }
    nota-=(menor+maior);
    es[numeroescola].quesito[numeroquesito].notaFinal=nota/3; 


}

int main(){
    escolas  es[10];

    char nome[12];
   // scanf("%s", nome);
    //printf("%d",stringSize(nome));
    cadastrarEscola(es,contadordeEscolasCad);
    cadastrarEscola(es,contadordeEscolasCad);
    AvaliarQuesito(es,0,0,1);
    scanf("%s",nome);
    buscarEscolaSamba(nome,es);
    listarEscolas(es);
   

    
    return 0;
}