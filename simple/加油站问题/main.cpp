#include<bits/stdc++.h>

using namespace std;

int solve(int N, int L, int P, vector<int> A, vector<int> B) {

    priority_queue<int> que ;
    int curStation = 0;
    P += 1;
    for (int i = 1; i <= L; i++) {
        P = P - 1;//消耗一单位油
    
        if (A[curStation] + 1 == i) {
            //证明到加油站了
            que.push(B[curStation]);
            curStation += 1;
            if (curStation > A.size()) {
                curStation = 0;
            }
        }

        if (P == 0) {
            if (que.size() == 0) {
                //z证明没到加油站，而且没油了
                return -1;
            } else {
                int maxbi = que.top();
                que.pop();
                P = P + maxbi;
            }
        }
    }

    int res = N - que.size();
    return res;

}


int main() {

    int N; //加油站个数
    int L;//一共需要走多远
    int P;//刚开始有多少油

    vector<int> A;
    vector<int> B;

    cin>>N>>L>>P;

    for (int i = 0; i < N; i ++) {
        int aa;
        cin>>aa;
        A.push_back(aa);
    }

    for (int j = 0; j < N; j ++) {
        int bb;
        cin>>bb;
        B.push_back(bb);
    }

    int res = solve(N, L, P, A, B);

    printf("%d\n", res);

    return 0;

}