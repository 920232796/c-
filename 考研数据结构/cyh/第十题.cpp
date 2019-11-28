#include<iostream>

using namespace std;

class Point {

    private:
        int x;
        int y;

    public:
        Point(int xx, int yy) {
            x = xx;
            y = yy;
        }
        Point(Point &p) {
            // cout<<x<<y<<endl;
            x = p.x;
            y = p.y;
            cout<<"Point 拷贝构造函数调用"<<endl;                                                            
        }
        int getx() {
            return x;
        }
};

class Distance {
    public:
        Distance(Point xp1, Point xp2):p1(xp1), p2(xp2) {

            cout<<"distance 构造函数调用"<<endl;
        }
        Point print() {
            return p1;
        }
    private:
        Point p1, p2;
};

int sum(int x, int y) {
    
    x = x + y;
    return x;
}

int main() {
    int x = 5;
    int y = 10;
    x = sum(x, y);
    cout<<x<<endl;

    //三种调用方式 拷贝构造函数
    Point p1(1, 1);
    Point p2 = p1; //赋值拷贝
    cout<<p2.getx()<<endl;

    cout<<"~~~~~~~"<<endl;

    Distance d1(p1, p2); //函数传参拷贝

    cout<<"~~~~~~~"<<endl;
    d1.print();
    return 0;
}