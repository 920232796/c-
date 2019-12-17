#include<iostream>

using namespace std;

class point {

   public: 
    static int number;
    point() {
        number++;
    }
    ~point() {
        number--;
    }

};

int point::number = 0;


int main() {

    point *ptr;
    point A, B;
    {
        point *ptr_point = new point[3];
        // point D;
        ptr = ptr_point;
        delete []ptr_point;
    }
    point C;
    // delete []ptr;
    cout<<point::number<<endl;
    
    return 0;
}