#include<cstdio>
#include<stack>
#include<iostream>
#include<vector>

using namespace std;

#define maxn 20

int a[maxn];
int k;
int n;
vector<int> ans;

bool dfs(int i, int sum) {
    if (i == n) {
        return k == sum;
    }
    
    if (dfs(i + 1, sum)) {
        //不加ai的情况
        return true;
    }   

    ans.push_back(a[i]);
    if (dfs(i + 1, sum + a[i])) {
        //加ai的情况
        return true;
    }
    ans.pop_back();
    return false;
}

int main() {

    cin>>n;
    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }
    cin>>k;

    if (dfs(0, 0)) {
        cout<<"true"<<endl;
        cout<<"k = ";
        for (int i = 0; i < ans.size(); i ++) {
            cout<<ans[i]<<" ";
        }
    }
    else {
        cout<<"false";
    }
    return 0;
}