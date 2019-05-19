/*--------------------------------------------------------------------------------------------------------------
-  Projeto de SIN 110                                                     TURMA:1                              - 
-  NOME: Gabriel Nogueira                                                 MATRICULA:4839                       -                                                                                   -  
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
    Quesito  quesito[13];
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
    if(cont<=9){
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
  
    printf("\nDigite a nota de avaliação para o quesito  %s :\n",es[numeroEscola].quesito[numeroquesito].nomequesito);
    scanf("%f", &es[numeroEscola].quesito[numeroquesito].avaliacaoJurados[numeroJurado]);
   

}
void exibirDadosEscola(escolas *es,int numeroescola){
    int qtdQuesitos=13,i=0;
    printf("\n Escola: %s",es[numeroescola].nomeEscola);
    printf("\n Responsavel: %s",es[numeroescola].nomeResponsavelEscola);

    for(i=0;i<qtdQuesitos;i++){
        printf("\n Nota do Quesito %s : ",es[numeroescola].quesito[i].nomequesito);
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
   for(i=0;i<2;i++){
       if(strcmp(nome,escolas[i].nomeEscola)==0){
           numerodaEscola=i;
           break;
       }

   }
   

    return numerodaEscola;
}
void AvaliarEscolaSamba(escolas *es){
    char nome[20];
    int escola=0,i=0,jurado=0;
    printf("\nDigite o nome da Escola de Samba que deseja avaliar\n");
    scanf("%s",nome);
    
    escola=buscarEscolaSamba(nome,es);
    printf("\nDigite o Numero do jurado,\n1- Avaliador(a) Joao\n2- Avaliador(a) Matheus\n3- Avaliador(a) Pablo\n4- Avaliador(a) Raquel\n5- Avaliador(a) Larissa\n");
    scanf("%d",&jurado);
    for(i=0;i<13;i++){
        printf("\n----------------------------------------------------------------------------------------------\n");
        AvaliarQuesito(es,escola,i,jurado-1);

    }
    
}
void listarQuesitos(escolas *es,int numeroescola){
    int i=0;
    for(i=0;i<13;i++){
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf(" Nome do Quesito %s :  ID: %d",es[numeroescola].quesito[i].nomequesito,i);
        printf("\n---------------------------------------------------------------------------------------------------\n");
    }

}

void listarEscolas(escolas *es){
    int i=0;
    for(i=0;i<10;i++){
        exibirDadosEscola(es,i);
        printf("\n---------------------------------------------------------------------------------------------------\n");
    }

}
float NotafinalQuesito(escolas * es,int numeroescola,int numeroquesito){
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
    return nota/3;
}
void salvarCadastro(escolas *es){
    FILE * arquivo;
    int i;
    arquivo=fopen("cadastroEscolas.txt","w+");
    for(i=0;i<10;i++){
        fprintf(arquivo,"%s %s\n",es[i].nomeEscola,es[i].nomeResponsavelEscola);
    }
    fclose(arquivo);
    printf("\n Cadastro salvo com sucesso!");
}
void carregarDados(escolas * es){
    FILE * arquivo;
    int i;
    arquivo=fopen("cadastroEscolas.txt","r");
    for(i=0;i<10;i++){
        fscanf(arquivo,"%s %s\n",&es[i].nomeEscola,&es[i].nomeResponsavelEscola);
    }
    fclose(arquivo);
    printf("\n Dados carregados  com sucesso!");
}

void menu(escolas *es){
    int op,numEscola;
    char nome[20];
    printf("\nSeja bem vindo\n");
    do{
        printf("\nMenu de opcoes: \n0-Sair do Programa\n1-Cadastrar Escola de Samba\n2-Buscar Escola de Samba\n3-Listar todas Escolas\n4-Avaliar Escola\n5-Calcular notaFinal de algum quesito\n8-Salvar dados de escola de samba\n9-Carregar Dados de escolas \n");
        scanf("%d",&op);
        switch(op){
            case 0:
                break;
            case 1:
                cadastrarEscola(es,contadordeEscolasCad);
                break;
            case 2:
                printf("\n Digite o nome da escola:\n");
                scanf("%s",nome);
                numEscola=buscarEscolaSamba(nome,es);
                exibirDadosEscola(es,numEscola);
                break;
            case 3:
                listarEscolas(es);
                break;
            case 4:
                AvaliarEscolaSamba(es);
                break;
            case 5:
                printf("\n Digite o nome da escola:\n");
                scanf("%s",nome);
                numEscola=buscarEscolaSamba(nome,es);
                listarQuesitos(es,numEscola);
                printf("\n Digite o ID do quesito que deseja fechar a nota final\n");
                int quesito;
                scanf("%d",&quesito);
                NotafinalQuesito(es,numEscola,quesito);
                printf("A nota final do quesito %s e: %f",es[numEscola].quesito[quesito].nomequesito,es[numEscola].quesito[quesito].notaFinal);
                break;
            case 8:
                salvarCadastro(es);
                break;
            case 9:
                carregarDados(es);
                break;


        }
    }while(op!=0);


}


int main(){
    escolas es[10];
    int i;
    char nome[12];
   // scanf("%s", nome);
    //printf("%d",stringSize(nome));
   /* cadastrarEscola(es,contadordeEscolasCad);
    
    AvaliarEscolaSamba(es);
    listarEscolas(es);*/
    menu(es);
    /*
    cadastrarEscola(es,contadordeEscolasCad);
    cadastrarEscola(es,contadordeEscolasCad);
    es[0].quesito[0].nomequesito='paidrinks';
    for(i=0;i<2;i++){
        printf("\n%s",es[i].nomeEscola);
        printf("\n%s",es[i].quesito[i].nomequesito);

    }
   */
    /*es[0].quesito[0].notaFinal=3.5;
    es[1].quesito[1].notaFinal=3.3;
    printf("%f",es[0].quesito[0].notaFinal);
    printf("%f",es[1].quesito[1].notaFinal);*/

    
    return 0;
}