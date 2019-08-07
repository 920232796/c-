#include<iostream>
#include<string>
#include<queue>

using namespace std;

int man_num;
int woman_num;
int n;

int main() {

    cin>>man_num;
    cin>>woman_num;
    cin>>n;
    queue<int> man;
    queue<int> woman;

    for (int i = 0; i < man_num; i ++) {
        man.push(i);
    }
    
    for (int j = 0; j < woman_num; j ++) {
        woman.push(j);
    }

    int len_man = man.size();
    int len_woman = woman.size();
    int c = 0;
    
    for (int k = 0; k < n; k ++) {
        while (c < len_man & c < len_woman) {
            cout<<man.front()<<"-"<<woman.front()<<endl;
            c += 1;
            man.push(man.front());
            woman.push(woman.front());

            man.pop();
            woman.pop();
            
        }
        c = 0;
    }

    return 0;
}