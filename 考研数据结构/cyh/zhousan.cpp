#include<iostream>

using namespace std;

class Student {
    private:
    int num;
    char name[20];
    char sex;

    public:
    Student(int n, char s) {
        num = n;
        this -> sex = s;
    }
    Student() {
        num = 0;
        sex = 'a';
    }
    ~Student() {
        cout<<"baibai"<<endl;
    }
    void display() {
        cout<<"num="<<this -> num<<endl;
        cout<<"name="<<name<<endl;
        cout<<"sex="<<sex<<endl;
    }
    static void display1() {
        cout<<"helloworld";
    }
    friend void show(Student s);
};

void show(Student s) {
    cout<<s.num<<endl;
} 

int main() {

    // Student stu1(10, 'm');
    Student stu1;
    Student::display1();
    // Student().display();
    // Student stu2(11, 's'); //定义了两个实例

    stu1.display();

    // stu1.display();
    
    // show(stu1);
    return 0;
}