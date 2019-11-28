#include<iostream>

using namespace std;

class C {
    public:
        C() {
            cout<<"c construct"<<endl;
        }
        C(C &c) { // 拷贝构造函数
            cout<<"拷贝构造函数调用"<<endl;
        }
        ~C() {
            cout<<"c baibai"<<endl;
        }
};

class A {

    public:
        A() {
            cout<<"a construct"<<endl;
        }
        ~A() {
            cout<<"a baibai"<<endl; 
        }
    private:
        C cc;
};



class B : public A{

    public:
        B() {
            cout<<"b construct"<<endl;
            }
        ~B() {
            cout<<"b baibai"<<endl;
        }
    private: 
        C cc;

};




int main() {

    B bb;
    C cc;
    C cc1(cc);                                     
    return 0;
}


