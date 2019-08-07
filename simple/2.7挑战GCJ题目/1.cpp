#include<bits/stdc++.h>

using namespace std;

int main() {
    
    priority_queue<int, vector<int>, greater<int>> v1;
    priority_queue<int, vector<int>, less<int>> v2;
    int n;
    cin>>n;

    for (int i = 0; i < n; i ++) {
        int a;
        cin>>a;
        v1.push(a);
    }
    for (int j = 0; j < n; j ++) {
        int b;
        cin>>b;
        v2.push(b);
    }
    int res = 0;
    while (!v1.empty()) {
        res += v1.top() * v2.top();
        v1.pop();
        v2.pop();
    }

    cout<<res<<endl;
    return 0;
}