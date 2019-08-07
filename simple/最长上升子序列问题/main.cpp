#include<bits/stdc++.h>

using namespace std;


int solve(int n, vector<int> a) {

    int dp[n + 1];

    for (int i = 1; i <= n; i ++) {

        dp[i] = 1;

        for (int j = 1; j < i; j ++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            
        }
    }

    for (int k = 1; k <= n; k ++) {
        cout<<dp[k]<<" ";
    }
    //输出dp中最大的那个就是结果了

    int res = 1;
    for (int i = 1; i <= n; i ++) {
        res = max(res, dp[i]);
    }

    return res;
}

int main() {

    int n;
    cin>>n;

    vector<int> a;
    for (int i = 0; i < n; i ++) {
        int aa;
        cin>>aa;
        a.push_back(aa);
    }

    int res = solve(n, a);
    
    cout<<"res = "<<res<<endl;
    return 0;

}