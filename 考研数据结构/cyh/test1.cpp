#include<iostream>
#include<stack>
using namespace std;

void solve(string a) {
    
    stack<int> s;

    for (int i = 0; i < a.size(); i ++) {
        if (a[i] == '[') {
            s.push(0);
        } else if (a[i] == '(') {
            s.push(1);
        } else if (a[i] == ']') {
            if (s.size() == 0 || s.top() != 0) {
                cout<<"NO"<<endl;
                return ;
            }
            s.pop();
        } else {
            if (s.size() == 0 || s.top() != 1 ) {
                cout<<"NO"<<endl;
                return ;
            }
            s.pop();
        }
    }
    if (s.size() != 0) {
        cout<<"NO"<<endl;
        return ;
    }

    cout<<"YES"<<endl;
}

int main() {

    string a = "[([][])]";
    solve(a);
    
    return 0;
}