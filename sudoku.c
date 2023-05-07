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

int is_valid(Node * n) 
{
  int i;
  int j;
  int k;
  int p;
  int aux;
  int *array = (int*) calloc(10,sizeof(int));
  for(j = 0 ; j < 9 ; j++){
    for(i = 0; i < 9; i++){
      if(n->sudo[i][j] != 0)
      {
        aux = n->sudo[i][j];
        array[aux]++;
        if (array[aux] > 1)return 0;
      }
    }
    for(k = 0; k < 10;k++){
      array[k] = 0;
    }
  }
  
  for(k = 0; k < 10;k++){
    array[k] = 0;
  }
  
  for(i = 0 ; i < 9 ; i++){
    for(j = 0; j < 9; j++){
      if(n->sudo[i][j] != 0){
        aux = n->sudo[i][j];
        array[aux]++;
        if (array[aux] > 1)return 0;
      }
    }
    for(k = 0; k < 10;k++){
      array[k] = 0;
    }
  }

  for(k = 0; k < 10;k++){
      array[k] = 0;
    }
  
  for(k = 0; k < 9 ; k++){ 
    for(p=0;p<9;p++){
      i=3*(k/3) + (p/3) ;
      j=3*(k%3) + (p%3) ;
      if(n->sudo[i][j] != 0){
        aux = n->sudo[i][j];
        array[aux]++;
        if(array[aux] > 1)return 0; 
      }
    }
    for(k = 0; k < 10;k++)
    {
      array[k] = 0;
    }
  }
  return 1;

}

List* get_adj_nodes(Node* n)
{
  
  List *list = createList();

  for(int i = 0 ; i < 9 ; i++)
  {
    for(int j = 0 ; j < 9 ; j++)
    {
      if (n -> sudo[i][j] == 0)
      {
        for(int nuevo = 1 ; nuevo < 10 ; nuevo++)
        {
          n -> sudo[i][j] = nuevo;
          if(is_valid(n))
          { 
            Node *adjNode = copy(n);
            pushBack(list, adjNode);}
          }
      }
    }
  }
  return list;
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
  return 1;
}

Node* DFS(Node* initial, int* cont)
{
  Stack* s = createStack();
  push(s,initial);
  while(!is_empty(s)){
    (*cont)++;
    Node *n = top(s);
    pop(s);
    if(is_final(n)){
      print_node(n);
      return n;
    }
    List* adj=get_adj_nodes(n);
    Node* aux= first(adj);
    while(aux){
      push(s,aux);
      aux=next(adj);
    }
    free(n);
  }
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