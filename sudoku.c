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

int is_valid(Node* n){
  int i,j,k,l,p;
  int aux;
  int *arreglo = (int*) calloc(10,sizeof(int));
  
  // Validación de filas
  for(j = 0 ; j < 9 ; j++){
    for(i = 0; i < 9; i++){
      if(n->sudo[i][j] != 0){
        aux = n->sudo[i][j];
        arreglo[aux]++;
        if (arreglo[aux] > 1) return 0;
      }
    }
    for(k = 0; k < 10; k++){
      arreglo[k] = 0;
    }
  }
  
  // Validación de columnas
  for(i = 0 ; i < 9 ; i++){
    for(j = 0; j < 9; j++){
      if(n->sudo[i][j] != 0){
        aux = n->sudo[i][j];
        arreglo[aux]++;
        if (arreglo[aux] > 1) return 0;
      }
    }
    for(k = 0; k < 10; k++){
      arreglo[k] = 0;
    }
  }

  // Validación de submatrices
  for(k = 0; k < 3; k++){ 
    for(l = 0; l < 3; l++){
      for(p = 0; p < 9; p++){
        i = 3*k + (p/3);
        j = 3*l + (p%3);
        if(n->sudo[i][j] != 0){
          aux = n->sudo[i][j];
          arreglo[aux]++;
          if (arreglo[aux] > 1) return 0; 
        }
      }
      for(k = 0; k < 10; k++){
        arreglo[k] = 0;
      }
    }
  }
  
  return n;
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