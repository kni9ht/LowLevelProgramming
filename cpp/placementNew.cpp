#include <iostream>
#include <memory>
using namespace std;

typedef struct _Node{
  int data;
  struct _Node *next;
} node;

int main (int argc, char *argv[])
{
  char* memory=new char[10*sizeof(node)];
  // delete[] memory;
  // node *a=new (&memory[0])node;
  // a->data=12;
  unique_ptr<node> a(new(&memory[0]) node);
  a->data=12;
  cout<<a->data<<endl;
  return 0;
}
