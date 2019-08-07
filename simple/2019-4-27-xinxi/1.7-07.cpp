#include<bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> solve(int N, int i, int j) {

    vector<vector<vector<int>>> res;

    vector<vector<int>> res1;

    vector<int> res2;

    for (int i = 0; i < N; i ++) {
        // res[0][i].push_back(i + 1);
        // res[0][i].push_back(j);
        res2.push_back(i + 1);
        res2.push_back(j);
        res1.push_back(res2);
    }

    res.push_back(res1);

    for (int j = 0; j < N; j ++) {
        res[1][j].push_back(i);
        res[1][j].push_back(j + 1);
    }

    for (int l = 0; l < N; l ++) {
        if (i - l != 0 && j + l != N + 1) {
            //证明有效
            res[2][l].push_back(i - l);
            res[2][l].push_back(j + l);
        } else {
            break;
        }
    }

    for (int k = 0; k < N; k ++) {
        if (i + k != N + 1 && j - k != 0) {
            res[3][k].push_back(i + k);
            res[3][k].push_back(j - k);
        } else {
            break;
        }
    }
    return res;
}

int main() {

    vector<vector<vector<int>>> res = solve(4, 2, 3);

    for (int i = 0; i < res.size(); i ++) {
        for (int j = 0; j < res[0].size(); j ++) {
            for (int k = 0; k < 2; k ++) {
                cout<<res[i][j][k];
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}