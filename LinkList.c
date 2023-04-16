#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *nxt;
};

int main (int argc, char *argv[])
{
  struct node* head=malloc(sizeof(struct node));
  struct node* tmp=head;
  int i=0;
  printf("Enter %d element\n>>>",i+1);
  scanf("%d", &head->data);
  for ( i = 1; i < 5; i++) {
    struct node* current=malloc(sizeof(struct node));
    printf("Enter %d element\n>>>",i+1);
    scanf("%d", &current->data);
    head->nxt=current;
    head=current;
  }
  head=tmp;
  for (i = 0; i < 5; i++) {
    printf("%d\n", head->data);
    head=head->nxt;
  }
  return 0;
}
