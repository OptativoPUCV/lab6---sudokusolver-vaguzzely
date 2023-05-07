#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){//importante
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int repetidosFila(int fila, Node *n)
{
  int numFila[10] = {0}, columna;

  for(columna = 0 ; columna < 9 ; columna++)
  {
    if(n -> sudo[fila][columna] != 0)
    {
      if (numFila[n -> sudo[fila][columna]] == 1) return 0;
      else numFila[n -> sudo[fila][columna]] = 1;
    }
  }
  
  return 1;
}

int repetidosColumna(int columna, Node *n)
{
  int numColumna[10] = {0}, fila;

  for(fila = 0 ; fila < 9 ; fila++)
  {
    if(n -> sudo[fila][columna] != 0)
    {
      if (numColumna[n -> sudo[fila][columna]] == 1) return 0;
      else numColumna[n -> sudo[fila][columna]] = 1;
    }
  }
  
  return 1;
}

int repetidosSubMatriz(int subMatriz, Node *n)
{
  int aux[10] = {0}, p;
  
  for(p = 0 ; p < 9 ; p++)
  {
    int i = 3 * (subMatriz/3) + (p/3);
    int j = 3 * (subMatriz%3) + (p%3);
    
    if(n -> sudo[i][j] != 0)
    {
      if (aux[n -> sudo[i][j]] == 1) return 0;
      else aux[n -> sudo[i][j]] = 1;
    }
  }
  
  return 1;
}

int is_valid(Node* n)
{
  int i;
  for (i = 0 ; i < 9 ; i++)
  {
    if(repetidosFila(i, n) == 0 || repetidosColumna(i, n) == 0 || repetidosSubMatriz(i, n) == 0) return 0;
  }
  
  return 1;
  
}



List* get_adj_nodes(Node* n)
{
  List* list = createList();
  int i, j;
    // Buscar la primera casilla vacía
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (n->sudo[i][j] == 0) {
                // Generar nodos adyacentes con valores posibles
        int k;
        for (k = 1; k <= 9; k++) {
          Node* adj_node = copy(n);
          adj_node->sudo[i][j] = k;
          pushBack(list, adj_node);
        }
        return list;
      }
    }
  }
  return list;
}







}


int is_final(Node* n)
{
  int i,j;
  for(i = 0 ; i < 9 ; i++)
  {
    for(j = 0 ; j < 9 ; j++)
    {
      if(n->sudo[i][j] == 0)
      {
        return 0;
      }
    }
    return 1;
  }
}

Node* DFS(Node* initial, int* cont)
{
  
  
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/