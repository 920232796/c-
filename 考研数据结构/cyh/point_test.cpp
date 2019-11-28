
#include<iostream>

using namespace std;

class Animal {
    private:
        int sleep;
    
    public:
         virtual void show();

        Animal() {
            sleep = 100;
        }
};

void Animal::show(){
            cout<<"sleep: "<<this -> sleep<<endl;
        }

class Pig : public Animal {
    private:
        int eat;

    public:
        void show() {
            cout<<"eat: "<<this -> eat<<endl;
            eat = 100;
        }
        Pig() {
            eat = 2000;
        }
};

int main() {

    // // 1. 
    // Animal an1;
    // an1.show();

    // Pig pig1;
    // pig1.show();

    // cout<<"~~~~~~~~"<<endl;

    // // 2. 
    // Animal* an2 = &pig1;
    // // an2 = &pig1;//改变基类指针的指向。
    // an2 -> show(); //发现输出依然是基类的show函数 而不是所指向的派生类的show函数

    // //3. 如何解决？？  用虚函数

    int a[4] = {1, 2, 3, 4};

    int* p = a;

    cout<<*(p+5)<<endl;


    return 0;
}