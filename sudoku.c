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

int is_valid(Node * n) {
    int i, j;
    // Verificar las filas
    for (i = 0; i < 9; i++) {
        int used_nums[10] = {0}; // Inicializar arreglo para marcar números
        for (j = 0; j < 9; j++) {
            int num = n->sudo[i][j];
            if (used_nums[num] == 1) {
                return 0; // Número repetido en la fila
            } else {
                used_nums[num] = 1;
            }
        }
    }
    // Verificar las columnas
    for (j = 0; j < 9; j++) {
        int used_nums[10] = {0}; // Inicializar arreglo para marcar números
        for (i = 0; i < 9; i++) {
            int num = n->sudo[i][j];
            if (used_nums[num] == 1) {
                return 0; // Número repetido en la columna
            } else {
                used_nums[num] = 1;
            }
        }
    }
    // Verificar las submatrices de 3x3
    int sub_i, sub_j;
    for (sub_i = 0; sub_i < 3; sub_i++) {
        for (sub_j = 0; sub_j < 3; sub_j++) {
            int used_nums[10] = {0}; // Inicializar arreglo para marcar números
            for (i = sub_i * 3; i < sub_i * 3 + 3; i++) {
                for (j = sub_j * 3; j < sub_j * 3 + 3; j++) {
                    int num = n->sudo[i][j];
                    if (used_nums[num] == 1) {
                        return 0; // Número repetido en la submatriz
                    } else {
                        used_nums[num] = 1;
                    }
                }
            }
        }
    }
    // El estado es válido
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