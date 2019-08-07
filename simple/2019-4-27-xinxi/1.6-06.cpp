#include<bits/stdc++.h>

using namespace std;

int solve(int L, vector<vector<int>> input) {
    vector<int> res;
    for (int i = 0; i <= L; i ++) {
        res.push_back(1);
    }

    for (int j = 0; j < input.size(); j ++) {
        for (int k = input[j][0]; k <= input[j][1]; k ++) {
            res[k] = 0;
        }
    }

    int resNum = 0;

    for (int i = 0; i < res.size(); i ++) {
        if (res[i] == 1) {
            resNum += 1;
        }
    }

    return resNum;
}

int main() {

    cout<<"hello world;"<<endl;

    int L = 500;
    int M = 3;
    vector<vector<int>> input;

    for (int i = 0; i < M; i ++) {
        vector<int> input1;
        for (int j = 0; j < 2; j ++) {
            int aa;
            cin>>aa;
            input1.push_back(aa);
        }
        input.push_back(input1);
    }

    int res = solve(L, input);
    cout<<res<<endl;

    return 0;
}