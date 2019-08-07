#include<iostream>

using namespace std;

struct Stack {

    int data[10000];
    int top = -1;// 栈顶指针

    int get_top() {
        return data[top];
    }

    void pop() {
        top --;
    }

    void push(int d) {
        top ++;
        data[top] = d;
    }
};

int main() {

    Stack stack;
    for (int i = 0; i < 10; i ++) {
        stack.push(i);
    }

    cout<<stack.get_top();
    stack.pop();
    cout<<stack.get_top();
    return 0;
}