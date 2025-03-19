#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#define MAX 100


typedef int
    tp_item;

typedef struct{
int topo;
int item[MAX];
}tp_pilha;

void inicializaPilha(tp_pilha *p){
p->topo = -1;
}

int pilhaVazia(tp_pilha *p){
if(p->topo ==-1) return 1;
return 0;
}

int pilhaCheia(tp_pilha *p){
if(p->topo == MAX-1) return 1;
return 0;
}

int push(tp_pilha *p, tp_item e){
if(pilhaCheia(p)==1) return 0;
p->topo++;
p->item[p->topo]=e;
return 1;
}

int pop(tp_pilha *p, tp_item *e){
    if(pilhaVazia(p)==1)return 0;
    *e=p->item[p->topo];
    p->topo--;
    return 1;
}

int top(tp_pilha *p, tp_item *e){
    if(pilhaVazia(p)==1) return 0;
    *e=p->item[p->topo];
    return 1;
}

void imprimePilha(tp_pilha p){
    tp_item e;
    printf("\n");
    while(!pilhaVazia(&p)){
        pop(&p, &e);
        printf("%d ", e);
    }
}

int alturaPilha(tp_pilha *p){
    return p->topo+1;
}

void retiraImpares(tp_pilha *p){
    tp_pilha pAux;
    inicializaPilha(&pAux);
    tp_item e;
    while(!pilhaVazia(p)){
        pop(p, &e);
        if(e%2 == 0) //verifica se é par
        push(&pAux, e);
    }
    while(!pilhaVazia(&pAux)){
        pop(&pAux, &e);
        push(p, e);
    }
}

int comparaPilha(tp_pilha p1, tp_pilha p2){
    tp_item e1, e2;
    if(alturaPilha(&p1) != alturaPilha(&p2))
        return 0;
    while(!pilhaVazia(&p1)){
        pop(&p1, &e1);
        pop(&p2, &e2);
        if(e1 != e2)
            return 0;
    }
    return 1;
}
#endif

int main(){

     //Utilizando a função push e pop para adicionar e remover elementos da pilha:
     tp_pilha p1;
     tp_item e; //tipo item deve ser declarado para armazenar um elemento removido pela funcao pop
     inicializaPilha(&p1);
 
     push(&p1, 10);
     push(&p1, 20);
     push(&p1, 30);
     push(&p1, 40);
     push(&p1, 50);
 
     printf("Pilha antes de utilizar a funcao pop: ");
     imprimePilha(p1);
 
     pop(&p1, &e);
     pop(&p1, &e);
     printf("\nPilha apos a funcao pop ser utilizada removendo dois elementos do topo: ");
     imprimePilha(p1);
 
     printf("\n\n----------------------------------------");
     //Utilizando a funcao removeImpares
     tp_pilha p2;
     inicializaPilha(&p2);
     push(&p2, 1);
     push(&p2, 2);
     push(&p2, 3);
     push(&p2, 4);
     push(&p2, 5);
     push(&p2, 6);
     push(&p2, 7);
     printf("\n\nPilha antes de utilizar a funcao removeImpares: ");
     imprimePilha(p2);
     
     retiraImpares(&p2);
     printf("\nPilha apos usar funcao removeImpares: ");
     imprimePilha(p2);
     
     printf("\n\n-------------------------------------");
     //Utilzando a funcao para comparar duas pilhas
     tp_pilha p3, p4;
     inicializaPilha(&p3);
     inicializaPilha(&p4);
     char pilhasiguais;
     
     push(&p3, 10);
     push(&p3, 20);
     push(&p3, 30);
     push(&p3, 40);
     push(&p3, 50);
     
     push(&p4, 10);
     push(&p4, 20);
     push(&p4, 30);
     push(&p4, 40);
     push(&p4, 50);
     
     printf("\n");
     
     printf("Pilha1: ");
     imprimePilha(p3);
     printf("\nPilha2: ");
     imprimePilha(p4);
     printf("\n\n");
     pilhasiguais = comparaPilha(p3, p4);
     if(pilhasiguais == 1){
     printf("As pilhas sao iguais\n");
     }
     else{
         printf("As pilhas sao diferentes.\n");
     }
}