#include<iostream>
#include<utility>
using namespace std;

#define MAX_N 1000

bool used[MAX_N][MAX_N];
char G[MAX_N][MAX_N];
int row;
int column;
pair<int, int> first_point;
int res = 0;

void dfs(int i, int j) {

    if (G[i][j] == '#') {
        return;
    }
    if (used[i][j]) {
        return;
    }
    if (i < 0 || j < 0 || i > row - 1 || j > column - 1) {
        return; 
    } 
    used[i][j] = true;
    res += 1;
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

int main() {

    while (true) {
   
    cin>>column;
    cin>>row;

    for (int i = 0; i < row; i ++) {
        fill(used[i], used[i] + column, false);
    }

    if (row != 0 && column != 0) {
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < column; j ++) {
                char a;
                cin>>a;
                G[i][j] = a;
                if (a == '@') {
                    //证明是初始点
                    first_point.first = i;
                    first_point.second = j;
                }
            }
        }

        dfs(first_point.first,first_point.second);
        cout<<res<<endl;
        res = 0;
    } else {
        break;
    }

    }
    return 0;
}