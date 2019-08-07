#include<bits/stdc++.h>

using namespace std;

#define MAX_N 10000000

bool is_prime[MAX_N];

int solve(int n) {
    int p = 0;
    fill(is_prime, is_prime + n + 1, true);

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= n; i ++) {
        if (is_prime[i]) {
            p = p + 1;
            //把所有这个数字的倍数划掉
            for (int j = 2; j <= n / i; j ++) {
                is_prime[i * j] = false;
            }
        }
    }

    return p;

}

int main() {
    int n;
    cin>>n;
    cout<<solve(n)<<endl;

    return 0;
}