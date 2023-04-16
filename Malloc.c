#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
  int alpha;
  int beta;
}Node;

int main()
{
  Node* a=malloc(sizeof(Node));
  a->alpha=1;
  return 0;
}
