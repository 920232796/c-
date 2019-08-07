#include<iostream>
#include<stack>
#include<sstream>

using namespace std;

int main() {
    stack<float> s;
    string a[1000];
    int n = 9;

    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }
    
    for (int j = 0; j < n; j ++) {
        if (a[j] != "*" && a[j] != "/" && a[j] != "+" && a[j] != "-") {
            //说明是数字
            // s.push(a[j])
            stringstream ss;
            ss<<a[j];
            float num;
            ss>>num;

            s.push(num);

        } else {
            float first_num = s.top();
            s.pop();
            float second_num = s.top();
            s.pop();

            float res;

            if (a[j] == "*") {
                res = first_num * second_num;
                s.push(res);
            } else if (a[j] == "/") {
                res = second_num / first_num;
                s.push(res);
            } else if (a[j] == "+") {
                res = first_num + second_num;
                s.push(res);
            } else {
                res = second_num - first_num;
                s.push(res);
            }
        }
    }

    cout<<s.top()<<endl;
    return 0;
}