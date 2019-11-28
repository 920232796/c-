#include<iostream>
using namespace std;

void print(int i, int j=0 ) {
    cout<<i<<j<<endl;
}

class Student {
    int age;
    int sex;
    
    public:
    void set(int a, int s) {
        this -> age = a;
        sex = s;
    }
    Student() {
        age = 0;
        sex = 0;
    }
    void display() {
        cout<<"age"<<age<<endl;
        cout<<"sex"<<sex<<endl;
    }
};
class Student1 : public Student {
    int score;

    public:
    void display1() {
        cout<<"score="<<score<<endl;
    
    }
};
int main() {
    Student1 stu1;
    stu1.display();
    stu1.set(10, '1');
    stu1.display();
    // print(3);

    return 0;

}