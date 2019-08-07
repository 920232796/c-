#include<iostream>
#include<sstream>
#include<set>

using namespace std;

const int N = 5;

int G[N][N];

set<int> res;

bool isSquare(int x, int y) {
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}

void dfs(int x, int y, int current_res, int steep) {
    if (steep == 6) {
        //结束
        res.insert(current_res);
        return ;
    }

    //判断越界
    if (!isSquare(x, y)) {
        return ;
    }
    current_res = current_res * 10 + G[x][y];
    dfs(x + 1, y, current_res, steep + 1);
    dfs(x - 1, y, current_res, steep + 1);
    dfs(x, y + 1, current_res, steep + 1);
    dfs(x, y - 1, current_res, steep + 1);
}

int main() {

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin>>G[i][j];
        }
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            dfs(i, j, 0, 0);
        }
    }

    cout<<res.size()<<endl;
    return 0;
}