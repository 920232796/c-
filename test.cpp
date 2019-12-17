#include<iostream>

using namespace std;

void f(char *a) {
    for (int i = 0; i < 3; i ++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

class A {

    public:
        A(int x = 0) {
            cout<<"AAA"<<endl;
        }
        
};

class B : public A {
    private: 
        A a;
    public:
        B():A(10),a(5) {
            cout<<"BBB"<<endl;
        }  
};



int main() {

    B b;
    // char* p = "sds";
    // // cout<<p[3]<<endl;
    // printf("%d\n", p[3]);
    // printf("%c\n", p[0]);
    // cout<<"hello world"<<endl;
    // char a[] = {'a', 'b', 'c'};

    // f("10");

    // int x = 1;
    // int y = 2;
    // int z= 3;

    // x += y += z;

    // cout<<y<<endl;
    // cout<<x<<endl;

    return 0;
}