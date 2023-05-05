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

    return 1;
}


List* get_adj_nodes(Node* n)
{
  List* list = createList();
  int i;
  int j;
  int idx[2] = {0, 0};
  int encuentra = 0;

  
  if (list == NULL)
  {
    return 0;
  }

  for (i = 0; i < 9; i++) 
  {
    for (j = 0; j < 9; j++)
    {
      if (n->sudo[i][j] == 0) 
      {
        idx[0] = i;
        idx[1] = j;
        encuentra = 1;
        break;
      }
    }
    if (n->sudo[idx[0]][idx[1]] == 0)
    {
      break;
    }
  }
  for (int k = 1; k <= 9; k++) 
  {
    Node* adj_node = copy(n);
    adj_node->sudo[idx[0]][idx[1]] = k; //asigna el valor k a la casilla indicada por idx en la matriz sudo del nodo adj_node
    if (is_valid(adj_node)) 
    {
      pushBack(list, adj_node);
    }
    else 
    {
      free(adj_node);
    }
  }
  return list;
}


int is_final(Node* n)
{
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
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