#include<iostream>

using namespace std; 


struct Queue {
    // const int length = 10;
    int data[16];
    int front = 0;
    int rear = 0;
    int cur_length = 0;//队列长度
    int tag = 0; //区分队满还是队空

    void insert(int d) {
        if (front == rear && tag == 1) {
            //说明队满了！
            cout<<"queue is full"<<endl;
            return ;
        }
        data[rear] = d;
        tag = 1;
        rear = (rear + 1) % 16;
        cur_length --;
        return ;
    }

    int get_front() {
        if (front == rear && tag == 0) {
            //队空
            cout<<"queue is empty"<<endl;
            return -1;
        }
        tag = 0;
        int res = data[front];
        front = (front + 1) % 16;
        cur_length --;
        return res;
    }
};

int main() {

    Queue q;
    cout<<q.cur_length<<endl;
    q.get_front();
    q.insert(1);
    q.insert(2);
    cout<<q.get_front()<<endl;
    cout<<q.get_front()<<endl;
    q.get_front();

    for (int i = 0; i < 17; i ++) {
        q.insert(i);
    }
    
    return 0;
}