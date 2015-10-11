/*
 * ls339@njit.edu
 * CS435
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
  int row, column, value;
  struct node *row_link, *column_link;
};

struct node* addNode(int row, int column, int value) {

  struct node *head;
  head = malloc(sizeof(struct node));
  head->row = row;
  head->column = column;
  head->value = value;
  head->row_link = NULL;
  head->column_link=NULL;
  return head;
}

void printMatrix(struct node *row[], struct node *column[],int n) {
  for(int i=0;i<n;i++){
    struct node *current = row[i];
    for(int j=0;j<n;j++) {
      if(current->row == i && current->column == j) {
	printf(" %d ",current->value);
	current = current->row_link;
      }else{
	printf(" 0 ");
      }
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {

  int n = 4;

  /* Testing */
  struct node *row[n];
  struct node *column[n];
  /*
   * Matrix
   *   0 1 2 3 
   * 0 8 0 6 0
   * 1 0 7 5 0
   * 2 3 0 0 0
   * 3 0 0 0 9
   */
  struct node *node1 = addNode(0,0,8);
  struct node *node2 = addNode(0,2,6);
  struct node *node3 = addNode(1,1,7);
  struct node *node4 = addNode(1,2,5);
  struct node *node5 = addNode(2,0,3);
  struct node *node6 = addNode(3,3,9);

  /* Link them up */
  node1->row_link = node2;
  node1->column_link = node5;
  node2->row_link = node1;
  node2->column_link = node4;
  node3->row_link = node4;
  node3->column_link = node3;
  node4->row_link = node3;
  node4->column_link = node2;
  node5->row_link = node5;
  node5->column_link = node1;
  node6->row_link = node6;
  node6->column_link = node6;

  row[0] = node1;
  row[1] = node3;
  row[2] = node5;
  row[3] = node6;
  column[0] = node1;
  column[1] = node3;
  column[2] = node2;
  column[3] = node6;
  /*
  printf("Testing Matrix\n");
  printMatrix(row,column,n);
  */

  // Initialize by Formula
  struct node *b_row[n];
  struct node *b_column[n];
  for(int i=0;i<n;i++){
    //struct node *rcurrent = b_row[i];
    for(int j=0;j<n;j++){
      //struct node *ccurrent = b_column[j];
      if(i==j){
	struct node *nodei = addNode(i,j,i+1);
	b_row[i] = nodei;
	b_column[i] = nodei;
	b_row[i]->row_link = nodei;
	b_column[i]->column_link = nodei;
      }
    }
  }
  printf("Initialized by formula:\n");
  printf("\tbij = { i if i==j\n\t\t0 otherwise }\n");
  //printf("************\n");
  printf("* Matrix B *\n");
  //printf("************\n");
  printMatrix(b_row,b_column,n);
}
