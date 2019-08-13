#include<iostream>
#include<stack>

using namespace std;

stack<char> s;

void solve(string a) {

    for (int i = 0; i < a.length(); i ++) {
        switch(a[i]) {
            case '(': s.push('(');   break;
            case '[': s.push('[');   break;
            case '{': s.push('{');   break;

           

            case ')': {
                char top = s.top();
                s.pop();
                if (top != '(') {
                    cout<<"No"<<endl;
                    return ;
                }
                break;
            }

            case ']': {
                char top = s.top();
                s.pop();
                if (top != '[') {
                    cout<<"No"<<endl;
                    return ;
                }
                break;
            }

            case '}': {
                char top = s.top();
                s.pop();
                if (top != '{') {
                    cout<<"No"<<endl;
                    return ;
                }
                break;
            }

        }

    }

    if (s.size() != 0) {
        cout<<"No"<<endl;
        return ;
    }

    cout<<"YES"<<endl;

}


int main() {

    string a = "([[{}{()}]])";

    solve(a);


    return 0;
}