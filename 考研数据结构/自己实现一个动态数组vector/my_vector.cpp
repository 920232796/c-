#include<iostream>

using namespace std;

// int 
struct Vector {
    int cur_length = 1;
    int max_length = 10;
    int * data = (int *) malloc(sizeof(int) * 10);

    void push_back(int d) {
        if (cur_length <= max_length) {
            data[cur_length - 1] = d;
            cur_length += 1;
        } else {
            int *new_data = (int *) malloc(sizeof(int) * max_length * 2);
            max_length = max_length * 2;
            for (int i = 0; i < cur_length - 1; i ++) {
                    new_data[i] = data[i];
            }
            data = new_data;
            data[cur_length - 1] = d;
            cur_length += 1;
            free(new_data);
        }
    }
} ;

int main() {
    Vector vector;
    // vector.push_back(10);
    for (int i = 0; i < 20; i ++) {
          vector.push_back(i);
    }
    for (int i = 0; i < 20; i ++) {
          cout<<vector.data[i]<<endl;
    }
    return 0;
}