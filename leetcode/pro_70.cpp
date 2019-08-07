#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        cout<<"hello world;"<<endl;
        int dp[100];
        
        dp[1] = 1;
        dp[2] = 2;
        if (n <= 2) {
            return dp[n];
        }
        for (int i = 3; i <= n; i ++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    
    Solution solution;
    int res = solution.climbStairs(3);
    cout<<res<<endl;
    return 0;
}