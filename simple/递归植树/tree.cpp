#include<iostream>

using namespace std;


int n = 1;

int tree(int n, int tree_n) {
    if (n == 5) {
        return tree_n + 10;
    } 
    tree_n = tree_n + 2;
    tree(n + 1, tree_n);
}

int main() {
    cout<<tree(n, 0)<<endl;
    return 0;
}