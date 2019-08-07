#include<iostream>

using namespace std;

struct Queue {
    int front = 0;
    int rear = 0;

    int data[16];

    void insert(int d) {
        if ((rear + 1) % 16 == front) {
            //队满
            cout<<"error! ";
            cout<<"队满"<<endl;
            return ;   
        }
        data[rear] = d;
        rear = (rear + 1) % 16;
    }

    int get_front() {
        if (front % 16 == rear) {
            cout<<"error! ";
            cout<<"队空"<<endl;
            return -1;   
        }
        int res = data[front];
        front = (front + 1) % 16;
        return res;
    }

};

int main() {

    Queue q;
    for (int i = 0; i < 10; i ++) {
        q.insert(i);
    }
    for (int i = 0; i < 10; i ++) {
        cout<<q.get_front()<<endl;
    }
    return 0;   
}