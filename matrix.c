#include <stdio.h>
#include <stdlib.h>

struct node {
  int row, column, value;
  struct node *row_link, *column_link;
};

int main(int argc, char **argv) {

  struct node *head, *middle, *tail;
  head = malloc(sizeof(struct node));
  middle = malloc(sizeof(struct node));
  tail = malloc(sizeof(struct node));
  head->row = 0;
  head->column = 1;
  head->value = 4;
  head->row_link = middle;

  printf("The value of the head node is %d\n", head->value);
  
}
