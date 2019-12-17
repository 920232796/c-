#include<iostream>

using namespace std;

class A {

    public:
        A() {
            cout<<"aa"<<endl;
        }
};

int main() {

    A a[2];
    // a[0] = A();
    // a[1] = A();
    A *pa[2];

    // pa = a;
    pa[0] = &a[0];
    // pa = a;
    return 0;
}