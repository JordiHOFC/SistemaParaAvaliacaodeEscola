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
    char nomequesito[50];
    float avaliacaoJurados[5];
    float notaFinal;

}Quesito;

typedef struct SescolaSamba{
    Quesito  quesito[13];
    char nomeEscola[20];
    char nomeResponsavelEscola[20];
    float notafinal;


}escolas;
//funcao mostra o tamanho de uma string
int stringSize(char * string){
    int contador=0;
    while(string[contador]!='\0')
        contador++;

    return contador;
}
int quantidade;

void cadastrarEscola(escolas *escola, int cont){
    int tamanhoNome;
    if(cont<=quantidade-1){
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
   for(i=0;i<quantidade;i++){
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

//funcao recursiva para fechar a notafinal de uma escola
void Notafinalescola(int numEscola, escolas *es,int i,float somatorio){
    
    if(i>=1){
       //printf("\nsomatorio: %f + %f = %f",somatorio,es[numEscola].quesito[i].notaFinal,somatorio+es[numEscola].quesito[i].notaFinal); 
       somatorio+=es[numEscola].quesito[i].notaFinal;
       
       return Notafinalescola(numEscola,es,i-1,somatorio);
    }
    if(i==0)
    {
        
        somatorio+=es[numEscola].quesito[i].notaFinal;
        es[numEscola].notafinal=somatorio/13;
        i--;
        
        printf("\nnotafinal fechada com sucesso");

    }
    
}
void avaliacaoFinal(escolas *es){
    int numEscola,i,j;
    char nome[30];
    float somatorio=0;
    for(i=0;i<quantidade;i++){
       Notafinalescola(i,es,12,0);
    }

}
void listarQuesitos(escolas *es,int numeroescola){
    int i=0;
    for(i=0;i<13;i++){
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf(" Nome do Quesito  : %s  ID: %d",es[numeroescola].quesito[i].nomequesito,i);
        printf("\n---------------------------------------------------------------------------------------------------\n");
    }

}

void listarEscolas(escolas *es){
    int i=0;
    for(i=0;i<quantidade;i++){
        exibirDadosEscola(es,i);
        //listarQuesitos(es,i);
        printf("\n---------------------------------------------------------------------------------------------------\n");
    }
  

}
void notaFinalQuesito(int numEscola, escolas *es,int numQuesito,int numJurado,float somatorio,float maior,float menor){
    
    if(numJurado==4){
        maior=es[numEscola].quesito[numQuesito].avaliacaoJurados[4];
        maior=es[numEscola].quesito[numQuesito].avaliacaoJurados[4];

    }
    if(numJurado>=0){
       //printf("\nsomatorio: %f + %f = %f",somatorio,es[numEscola].quesito[i].notaFinal,somatorio+es[numEscola].quesito[i].notaFinal); 
        if(maior<es[numEscola].quesito[numQuesito].avaliacaoJurados[numJurado]){
            maior=es[numEscola].quesito[numQuesito].avaliacaoJurados[numJurado];
        }
        if(menor>es[numEscola].quesito[numQuesito].avaliacaoJurados[numJurado]){
            menor=es[numEscola].quesito[numQuesito].avaliacaoJurados[numJurado];
        }
        somatorio+=es[numEscola].quesito[numQuesito].avaliacaoJurados[numJurado];
        printf("\n maior  : %f e menor: %f",maior,menor);
       return notaFinalQuesito(numEscola,es,numQuesito,numJurado-1,somatorio,maior,menor);
    }
    if(numJurado<0)
    {
        
        
        es[numEscola].quesito[numQuesito].notaFinal=(somatorio-(maior+menor))/3;
        //numJurado--;
        
        printf("\nnotafinal  do quesito:  %f ",es[numEscola].quesito[numQuesito].notaFinal);

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
    FILE *fp=fopen("nomequesito.txt","r");
    int i,j;
    
    arquivo=fopen("cadastroEscolas.txt","r");
    
    
    for(i=0;i<quantidade;i++){
        fscanf(arquivo,"%s %s\n",&es[i].nomeEscola,&es[i].nomeResponsavelEscola);
        for(j=0;j<13;j++){
            fscanf(fp,"%s\n",&es[i].quesito[j].nomequesito);

        }
        rewind(fp);
    }
    fclose(arquivo);
    printf("\n Dados carregados  com sucesso!");
    
   
    fclose(fp);
}
void carregarNotas(escolas *es){
    int i,j,k;
    float valor;
    FILE *arquivo=fopen("notas.txt","r");
    for(i=0;i<quantidade;i++){
        for(j=0;j<13;j++){
            fscanf(arquivo,"%f\n",&valor);
            es[i].quesito[j].avaliacaoJurados[0]=valor;
            es[i].quesito[j].avaliacaoJurados[1]=valor;
            es[i].quesito[j].avaliacaoJurados[2]=valor;
            es[i].quesito[j].avaliacaoJurados[3]=valor;
            es[i].quesito[j].avaliacaoJurados[4]=valor;
        }
    }
    printf("\n Dados carregados  com sucesso!");
    fclose(arquivo);
}
void escolasVencedores(escolas* es){
    float notasFinais[10],maior=0,Smaior=0;
    int i,maior1,maior2;
    maior1=es[0].notafinal;
    for(i=0;i<quantidade;i++){
        notasFinais[i]=es[i].notafinal;
        if(maior<notasFinais[i]){
            maior=notasFinais[i];
            maior1=i;
        }
    }
    Smaior=es[0].notafinal;
     for(i=0;i<quantidade;i++){   
        if(Smaior<notasFinais[i] && i!=maior1){
            Smaior=notasFinais[i];
            maior2=i;
        }
    }
    printf("\nEscola Campea : %s com %f\nEscola Vice-Campea: %s com %f\n",es[maior1].nomeEscola,es[maior1].notafinal,es[maior2].nomeEscola,es[maior2].notafinal);


}
void escolasRebaixadas(escolas* es){
    float notasFinais[10],menor=es[0].notafinal,Smenor=0;
    int i,menor1,menor2;
    menor1=es[0].notafinal;
    for(i=0;i<quantidade;i++){
        notasFinais[i]=es[i].notafinal;
        if(notasFinais[i]<menor){
            menor=notasFinais[i];
            menor1=i;
        }
    }
    Smenor=es[0].notafinal;
     for(i=0;i<quantidade;i++){   
        if(notasFinais[i]<Smenor && i!=menor1){
            Smenor=notasFinais[i];
            menor2=i;
        }
    }
    printf("\nEscola rebaixada : %s com %f\nEscola rebaixada: %s com %f\n",es[menor1].nomeEscola,es[menor1].notafinal,es[menor2].nomeEscola,es[menor2].notafinal);


}
void listarNotasFinais(escolas *es){
   int i;
   for(i=0;i<quantidade;i++){
       printf("\nEscola %s  -- Notafinal: %f\n",es[i].nomeEscola, es[i].notafinal);
   }
}
void menu(escolas *es){
    int op,numEscola,i,j;
    char nome[20];
    printf("\nSeja bem vindo\n");
    do{

        printf("\nMenu de opcoes: \n0-Sair do Programa\n1-Cadastrar Escola de Samba\n2-Buscar Escola de Samba\n3-Listar todas Escolas\n4-Avaliar Escola\n5-Calcular notaFinal de todos quesitode todas escolas\n6-Mostrar Escolas Vencedoras \n8-Salvar dados de escola de samba\n9-Carregar Dados de escolas\n10-CarregarNotas \n");
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
                for(i=0;i<10;i++){
                    for(j=0;j<13;j++){
                        notaFinalQuesito(i,es,j,4,0,-1,10);
                    }
                }
                avaliacaoFinal(es);   
                break;
            case 6:
                listarNotasFinais(es);
                escolasVencedores(es);    
                break;
            case 7:
                escolasRebaixadas(es);
                break;
            case 8:
                salvarCadastro(es);
                break;
            case 9:
                carregarDados(es);
                break;
            case 10:
                 carregarNotas(es);
                 break;
            


        }
    }while(op!=0);


}


int main(){
    int i;
    printf("Digite quantas escolas deseja cadastrar\n");
    scanf("%d",&quantidade);
    escolas *es=(escolas*)malloc(quantidade*sizeof(escolas));
   
   
   
    menu(es);

    return 0;
}