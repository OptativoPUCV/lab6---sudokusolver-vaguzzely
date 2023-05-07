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
    int rows[9][10] = {0}; // arreglo de enteros para marcar los números en cada fila
    int cols[9][10] = {0}; // arreglo de enteros para marcar los números en cada columna
    int boxes[9][10] = {0}; // arreglo de enteros para marcar los números en cada submatriz 3x3
    
    // recorrer las celdas del estado/nodo
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = n->board[i][j];
            if (num != 0) { // si la celda no está vacía
                // verificar si el número ya apareció en la fila
                if (rows[i][num] == 1) {
                    return 0; // no es válido
                } else {
                    rows[i][num] = 1; // marcar el número en la fila
                }
                
                // verificar si el número ya apareció en la columna
                if (cols[j][num] == 1) {
                    return 0; // no es válido
                } else {
                    cols[j][num] = 1; // marcar el número en la columna
                }
                
                // verificar si el número ya apareció en la submatriz 3x3
                int box_idx = (i / 3) * 3 + (j / 3); // índice de la submatriz
                if (boxes[box_idx][num] == 1) {
                    return 0; // no es válido
                } else {
                    boxes[box_idx][num] = 1; // marcar el número en la submatriz
                }
            }
        }
    }
    
    return 1; // es válido
}




List* get_adj_nodes(Node* n)
{
  List* list = createList();
  int i, j;
    // Buscar la primera casilla vacía
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (n->sudo[i][j] == 0) {
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