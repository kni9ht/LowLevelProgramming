#include <stdio.h>
#define EXIT_SUCCESS 0

extern void print();

int main(int argc, char *argv[]) {
  int a = 12;
  printf("a = %i\n", a);
  print();
  return EXIT_SUCCESS;
}
