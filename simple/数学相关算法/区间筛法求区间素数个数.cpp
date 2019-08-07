#include<bits/stdc++.h>

using namespace std;

#define MAX_N 1000000000000

bool is_prime[MAX_N];
bool a_b_prime[MAX_N];

int solve(int a, int b) {
    int p = 0;
    int bb = 0;
    fill(is_prime, is_prime + b + 1, true);
    fill(a_b_prime, a_b_prime + b + 1, true);

    is_prime[0] = false;
    is_prime[1] = false;

    a_b_prime[0] = false;
    a_b_prime[1] = false;
    int bb_end = -1;
    for (int i = 2; i < b; i ++) {
     
        if (i > a) {
            bb_end = bb;
        }
        if (is_prime[i]) {
            p = p + 1;
            if (bb != bb_end) {
                bb = bb + 1;
            }
            //把所有这个数字的倍数划掉
            for (int j = 2; j <= b / i; j ++) {
                is_prime[i * j] = false;
            }
        }
    }

    return p - bb_end;

}

int main() {
   
    cout<<solve(22801763489, 22801787297)<<endl;

    return 0;
}