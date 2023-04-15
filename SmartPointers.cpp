#include <iostream>
#include <memory>
using namespace std;

class A{
    public:
        A(){
            printf("Object COnstructed\n");
        }
        ~A(){
            printf("Object Destructed\n");
        }
        void p()
        {
            printf("Hello\n");
        }
};

int main()
{
    int a=12;

    /*Smart Pointers*/
    // unique_ptr<int> ptr=make_unique<int>(a);
    // weak_ptr<int> wp;
    // {
    //     shared_ptr<int> shPtr=make_shared<int>(a);
    //     printf("%d\n",*shPtr);
    //     wp=shPtr;
    // }
    // printf("%d",wp.expired());

    // A* ptr=new A();
    unique_ptr<A> ptr=make_unique<A>();
    {
        // delete(ptr);
        ptr.reset();
    }
    ptr->p();
    // printf("%d",wp.expired());
    return 0;
}