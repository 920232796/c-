#include<iostream>
#include<stack>
#include<string>
#include<cstring>

using namespace std;

int main() {
    stack<string> left_stack;
    string str;
    cin>>str;
    int len_str = str.size();
    int flag = 0;
    
    for (int i = 0; i < len_str; i ++) {
        if (str.substr(i, 1) == "(") {
            //zh证明找到了左括号
            left_stack.push(str.substr(i, 1));
        }

        if (str.substr(i, 1) == ")") {
            if (left_stack.size() == 0) {
                cout<<"no"<<endl;
                flag = 1;
                break;
            } else {
                left_stack.pop();
            }
        }
    }

    if (flag == 0) {
        cout<<"yes"<<endl;
    }

    return 0;
}