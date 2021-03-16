#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float function(int R) {
    float q;
    q = exp(-R * 0.05 / 10) * cos((sqrt(1 / 0.0005 - pow(R / 10, 2)))*0.05) - 0.01; // função retirada do problema passado    
    return q;
}

float CalcRaiz(float c, float f) { // Faz o ponto medio entre o intervalo passado
    float result;
    result = (c + f) / 2;
    return result;
}

float CalcErro(float rN, float rV) { // calcula o erro da aproximação do software  
    float e;
    e = fabs((rN - rV) / rN);
    return e;
}

float Biseccao(float comeco, float final, float precisao, int interacoes) {

    float erro = 1; // começar com um erro grande como parametro
    int cont = 0;
    float raiz;
    float aux = 0;
    float busca;

    while (erro > precisao && cont < interacoes) {
        raiz = CalcRaiz(comeco, final); // Calcula a Raiz     
        busca = (function(comeco) * function(raiz)); // calcula para testar aonde vai estar a raiz

        if (busca < 0) { // testa para que lado esta a o zero da raiz;   
            final = raiz;
        }
        if (busca > 0) {
            comeco = raiz;
        }
        if (busca == 0) {
            printf("A raiz é : %f", raiz);
            return 0;
        }

        erro = CalcErro(raiz, aux);

        aux = raiz;
        cont++;
    }
    return raiz;
}

int main() {
    float comeco, final, pre;
    int interacoes;
    float resultado;

    printf("Metodo da Bisseccao\n");

    printf("Digite o comeco do intervalo: ");
    scanf("%f", &comeco);

    printf("\nDigite o final do intervalo: ");
    scanf("%f", &final);

    printf("\nDigite a precisao requerida no metodo: ");
    scanf("%f", &pre);

    printf("\nDigite o numero maximo de interacoes: ");
    scanf("%d", &interacoes);

    if(function(comeco) * function(final) > 0) {
        printf("\nIntervalo invalido, tente outro ");

        printf("\nDigite o comeco do intervalo: ");
        scanf("%f", &comeco);

        printf("\nDigite o final do intervalo: ");
        scanf("%f", &final);

    }   

    resultado = Biseccao(comeco, final, pre, interacoes);

    printf("\nO resultado aproximado do metodo é : %f", resultado);
    return (EXIT_SUCCESS);
}

