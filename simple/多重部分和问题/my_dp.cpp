#include<bits/stdc++.h>

using namespace std;

// 1 dp算法求解
int solve(int n, int K, vector<int> a, vector<int> m) {

    bool dp[n + 1][K + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for (int i = 0; i <= n; i ++) {
        dp[i][0] = true;
    }
 
    
    for (int j = 0; j < K + 1; j ++) {
        for (int k = 1; k <= m[0]; k ++) {
            if (j % (k * a[0]) == 0) {
                //z证明可以得到
                dp[1][j] = true;
            }
        }
    }

       
    for (int i = 0; i < n + 1; i ++) {
        for (int j = 0; j < K + 1; j ++) {
            cout<<dp[i][j];
        }
        cout<<endl;
    }

   
    for (int i = 2; i <= n; i ++) {

        for (int j = 1; j <= K; j ++) {

            for (int k = 0; k < m[i]; k ++) {
                if (j - a[i - 1] * k >= 0 && dp[i - 1][j - a[i - 1] * k] == true) {
                    //证明成立了
                    dp[i][j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n + 1; i ++) {
        for (int j = 0; j < K + 1; j ++) {
            cout<<dp[i][j];
        }
        cout<<endl;
    }

    // if (dp[n][K] == true) {
    //     return 1;
    // }
    // return 0;

    return 0;
}

int main() {
    int n;
    int K;
    vector<int> a;
    vector<int> m;
    cin>>n;
  
    for (int i = 0; i < n; i ++) {
        int aa;
        cin>>aa;
        a.push_back(aa);
    }

    for (int j = 0; j < n; j ++) {
        int mm;
        cin>>mm;
        m.push_back(mm);
    }

    cin>>K;
    cout<<solve(n, K, a, m)<<endl;

    return 0;
}