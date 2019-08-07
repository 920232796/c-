#include<bits/stdc++.h>

using namespace std;

string solve(string target, char from, char to) {

    for (int i = 0; i < target.size(); i ++) {
        if (target[i] == from) {
            target[i] = to;
        }
    }
    return target;
}

int main() {

    cout<<"hello world;"<<endl;

    string target = "hello-how-are-you";
    char from = 'o';
    char to = 'O';

    string res = solve(target, from, to);

    cout<<res<<endl;

}

