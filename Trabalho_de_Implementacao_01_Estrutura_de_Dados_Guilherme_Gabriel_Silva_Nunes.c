#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define False 0
#define True 1
void MultMatrizAxB();
void TransMatrizA();
void MultAtransB();

int main(){
    int vEscolha;
    int lin_a = -3, lin_b = -3; // parâmetros de existência
    //Comeco while para true
    while(True){
        printf("\n\nMenu:\n1 - Ler Matriz A\n2 - ler Matriz B\n3 - Multiplicacao(AxB)\n4 - Transposta de A\n5 - Multiplicacao de A pela transposta de B\n6 - Sair\n\nOpcao:");
        while(True){
            if (scanf("%d", &vEscolha) != 0){//Antiletras Escolha
                break;
            } else{
                printf("Digite um numero: ");
                while(getchar() != '\n');}//limpando o stdin
        }
        //Imprimindo a saida da escolha do usuario
        switch(vEscolha){
            case 1:
                printf("O usuario escolheu ler a matriz A\n\n");
                int col_a; // Lado Matriz A

                printf("\nInsira parametros para matriz A\n");//Recebendo os valores das linhas e colunas
                printf("Numero de Linhas : ");
                while(True){
                    if (scanf("%d", &lin_a) !=0){//Antiletras linhaA
                        break;
                    } else{
                    printf("Digite um numero: ");
                    while(getchar() != '\n');}//limpando o stdin
                }
                printf("Numero de Colunas : ");
                while(True){
                    if (scanf("%d", &col_a) != 0){//Antiletras ColunaA
                        break;
                    } else{
                    printf("Digite um numero: ");
                    while(getchar() != '\n');}//limpando o stdin
                }

                float *MatrizA;// vetor Matriz A
                int i, j, k; //contadores
                if(lin_a> 0 && col_a>0){
                    MatrizA =(float *) malloc(sizeof(float)* lin_a * col_a);
                        if(MatrizA==NULL){
                            printf("\nErro na alocacao de memoria!");
                            exit(True);
                        }
                    for(i=0; i<lin_a; i++){//percorrendo a Matriz
                        for(j=0; j<col_a; j++){
                            k = i *col_a +j;
                            printf("Insira os valores da Matriz A[%d][%d]: ", i+1, j+1);
                            while (True){
                                if (scanf("%f", &MatrizA[k]) !=0){//Antiletras MatrizA
                                    break;
                                } else{
                                    printf("Digite um numero: ");
                                    while(getchar() != '\n');}//limpando o stdin
                            }
                            }
                        }
                        printf("\n\n");
                        for(i=0; i<lin_a; i++){//Imprimindo a Matriz
                            for(j=0; j<col_a; j++){
                                    k = i *col_a +j;
                                    printf("O valor da Matriz A[%d][%d] = %.1f \n", i+1, j+1, MatrizA[k]);
                            }
                        }
                    }
                else{
                    printf("Parametros de Matriz invalidos\n");
                }
                printf("\nDigite ENTER para continuar!");
                getch();

                break;
            case 2:
                printf("\nO usuario escolheu ler a matriz B\n\n");
                int col_b; //Lado Matriz B

                printf("\nInsira parametros para matriz B\n");//Recebendo os valores das linhas e colunas
                printf("Numero de Linhas : ");
                while(True){
                    if (scanf("%d", &lin_b) != 0){//Antiletras ColunaB
                        break;
                    }else{
                    printf("Digite um numero: ");
                    while(getchar() != '\n');} // limpando o stdin
                }
                printf("Numero de Colunas : ");
                while(True){
                    if (scanf("%d", &col_b) != 0){//Antiletras ColunaB
                        break;
                    }else{
                    printf("Digite um numero: ");
                    while(getchar() != '\n');}//limpando o stdin
                }
                float *MatrizB;//vetor Matriz B
                int l, x, y; //contadores
                if(lin_b > 0 && col_b >0){
                    MatrizB =(float *) malloc(sizeof(float)* lin_b * col_b);
                        if(MatrizB==NULL){
                            printf("\nErro na alocacao de memoria!");
                            exit(True);
                        }
                    for(l=0; l<lin_b; l++){//Percorrendo a matriz
                        for(x=0; x<col_b; x++){
                            y = l *col_b +x;
                            printf("Insira os valores da Matriz B[%d][%d]: ", l+1, x+1);
                            while(True){
                            if (scanf("%f", &MatrizB[y])!= 0){//Antiletras MatrizB
                                break;
                            } else{
                                printf("Digite um numero: ");
                                while(getchar() != '\n');}//limpando o stdin
                            }
                        }
                    }
                    printf("\n\n");
                    for(l=0; l<lin_b; l++){//Imprimindo a matriz
                        for(x=0; x<col_b; x++){
                            y = l *col_b +x;
                            printf("O valor da Matriz A[%d][%d] = %.1f \n", l+1, x+1, MatrizB[y]);
                        }
                    }
                }
                else{
                    printf("Parametros de Matriz invalidos\n");
                }
                printf("\nDigite ENTER para continuar!");
                getch();
                 break;
            case 3:
                printf("O usuario escolheu multiplicar a matriz A por B\n\n");
                float *vmc;// Vetor multiplicacao
                if( lin_a == -3 && lin_b == -3){//Parametros de existência
                    printf("Erro na leitura da Matriz A e Matriz B");}
                else if( lin_a == -3){
                    printf("Erro na leitura da Matriz A");}
                else if( lin_b == -3){
                    printf("Erro na leitura da Matriz B");}
                else{
                    MultMatrizAxB(vmc, MatrizA, MatrizB, lin_a, lin_b, col_a, col_b);}
                break;
            case 4:
                printf("O usuario escolheu calcular a transposta de A\n\n");
                float *vtma;// vetor matriz
                if( lin_a == -3){//Parametros de existência
                    printf("Erro na leitura da Matriz A");}
                else{
                    TransMatrizA(vtma, MatrizA, lin_a, col_a);}
                break;
            case 5:
                printf("O usuario escolheu calcular a multiplicacao da matriz A pela transposta de B\n\n");
                float *vmultatb;
                if( lin_a == -3 && lin_b == -3){//Parametros de existência
                    printf("Erro na leitura da Matriz A e Matriz B");}
                else if( lin_a == -3){
                    printf("Erro na leitura da Matriz A");}
                else if( lin_b == -3){
                    printf("Erro na leitura da Matriz B");}
                else{
                    MultAtransB (vmultatb, MatrizA, MatrizB, lin_a, lin_b, col_a, col_b);}
                break;
            case 6://Liberando as alocações
                free(MatrizA);
                free(MatrizB);
                free(vmc);
                free(vtma);
                free(vmultatb);
                exit(True);
                break;
                //Qualquer outra opcao sera invalida.
            default:
                printf("Voce digitou uma opcao invalida.\n\n");
                break;
        }
    }
    return False;
}

void MultMatrizAxB( float *MatrizAB, float *MatrizA, float *MatrizB, int LinhaA, int LinhaB, int ColunaA, int ColunaB){
	int i, j, k; //contadores

	MatrizAB = (float *)calloc((LinhaA) * (ColunaB),sizeof(float));
        if(MatrizAB==NULL){
            printf("\nErro na alocacao de memoria!");
            exit(True);
        }
    if (ColunaB == LinhaA){
        for(i =0; i < LinhaA; i++){//Realiza o calculo
            for(j=0; j < ColunaB; j++){
                for(k=0; k<ColunaA; k++){
                    MatrizAB[i * ColunaB +j] += MatrizA[i * ColunaA + k] * MatrizB[k * ColunaB + j];
                }
            }
        }
        printf("\n\n");
        for (i=0;i<LinhaA;i++){//Imprimindo a Matriz
            for(j =0;j < ColunaB; j++){
                k = i * ColunaB +j;
                printf("A multiplicacao da Matriz A x Matriz B [%d][%d]: %.1f \n", i+1, j+1, MatrizAB[k]);
            }
        }
    }
    else{
        printf("Não eh possivel realizar a multiplicacao");
    }
    printf("\nDigite ENTER para continuar!");
    getch();
    return;
}

void TransMatrizA( float *TransMA, float *MatrizA, int LinhaA, int ColunaA){
    int i, j, k;

    TransMA = (float *) malloc(sizeof(float)* ColunaA * LinhaA);
        if(TransMA==NULL){
            printf("\nErro na alocacao de memoria");
            exit(True);
        }
        for (i = 0; i <  LinhaA; i++){//Realiza o calculo
            for(j = 0; j < ColunaA; j++){
                TransMA[i * ColunaA + j] = MatrizA[j * ColunaA+ i];//Transpondo para outro vetor
            }
        }
        for (i = 0; i < ColunaA ; i++){//imprimindo a matriz
            for(j = 0; j <  LinhaA; j++){
                k = i * ColunaA + j;
                printf("A Matriz Transposta de A[%d][%d] = %.1f \n", i+1, j+1, TransMA[k]);
            }
        }
    printf("\nDigite ENTER para continuar!");
    getch();
    return;
}

void MultAtransB(float *MultAtransB, float *MatrizA, float *MatrizB, int LinhaA, int LinhaB, int ColunaA, int ColunaB){
	int i, j, k;

	MultAtransB = (float *)calloc((LinhaA) * (ColunaB),sizeof(float));
        if(MultAtransB==NULL){
            printf("\nErro na alocacao de memoria");
            exit(True);
        }
	if(LinhaA == ColunaB){//Realizando o calculo
        for( i=0; i<LinhaA; i++){
            for(j=0; j<ColunaB; j++){
                for(k=0; k < ColunaA;  k++){
                    MultAtransB[i * ColunaB +j] += MatrizA[i * ColunaA + k] * MatrizB[j * ColunaB + k];
                }
            }
        }
        for( i = 0; i < LinhaA; i++){//Imprimindo a Matriz
            for(j = 0; j < ColunaB; j++){
                k = i * ColunaB +j;
                printf("A multiplicacao da Matriz A pela Transposta da Matriz B eh [%d][%d]: %.1f \n", i+1, j+1, MultAtransB[k]);
            }
        }
    }
	else{
	  printf("\nNao eh possivel realizar a multiplicacao");
	}
    printf("\nDigite ENTER para continuar!");
    getch();
    return;
}
