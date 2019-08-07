#include<iostream>
#include<utility>

using namespace std; 

const int MAX_W = 20;
const int MAX_H = 20;

int G[MAX_W][MAX_H];

int d[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

int row, column;

int res;

pair<int, int> g;
pair<int, int> s;

bool inSquare(int x, int y){
    return 0 <= x && x < row && 0 <= y && y < column;
}

void dfs(int i, int j, int steep) {

    if(i == g.first && j == g.second){
        if(res > steep){
            //若有更小值
            res = steep;
        }
        return;
    }

    if (steep >= 10) {
        return ;
    }
    for (int k = 0; k < 4; k ++) {
        int i_i = i + d[k][0];
        int j_j = j + d[k][1];

        while (G[i_i][j_j] != 1 && inSquare(i_i, j_j)) {

            if (i_i == g.first && j_j == g.second) {
                //到达终点
                steep += 1;
                if (res > steep) {
                    res = steep;
                }
                return ;
            }
            i_i = i_i + d[k][0];
            j_j = j_j + d[k][1];
        }
        if ((i_i == i + d[k][0] && j_j == j + d[k][1]) || !inSquare(i_i, j_j) ) {
            continue;
        }
    
        //证明现在G[i][j] == 1 返回一下 继续四个方向走
        G[i_i][j_j] = 0;
        steep += 1;
        dfs(i_i - d[k][0], j_j - d[k][1], steep);
        steep -= 1;
        G[i_i][j_j] = 1;//还原G
    
    }
}

int main() {
    
    while (true) {

    cin>>column;
    cin>>row;
    if (row == 0 && column == 0) {
        return 0;
    }

    res = 11;
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < column; j ++) {
            int a;
            cin>>a;
            G[i][j] = a;

            if (a == 2) {
                s.first = i;
                s.second = j;
                G[i][j] = 0;
            }
            if (a == 3) {
                g.first = i;
                g.second = j;
            }
        }
    }
    dfs(s.first, s.second, 0);

    if (res == 11) {
        cout<<-1<<endl;
    } else {
        cout<<res<<endl;
    }

     }
    return 0;
}