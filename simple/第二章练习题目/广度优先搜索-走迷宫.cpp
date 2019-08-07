/*
10 10
# S # # # # # # . #
. . . . . . # . . #
. # . # # . # # . #
. # . . . . . . . .
# # . # # . # # # #
. . . . # . . . . #
. # # # # # # # . #
. . . . # . . . . .
. # # # # . # # # .
. . . . # . . . G #
 */
#include<queue>
#include<iostream>
#include<utility>

using namespace std;

const int M = 100;
const int N = 100;

int m;
int n;

typedef pair<int, int> P;

int dd[M][N];//这个就表明了从 起点 到 m n 这个点的距离是多少步

queue<P> q;//关键的队列

char maze[M][N];

P start_point;
P end_point;

int d[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
}; //四个方向

bool used[M][N];//标记是否走过

bool isSquare(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

void solve(int i, int j) {

    for (int l = 0; l < m; l ++) {
        for (int s = 0; s < n; s ++) {
            //初始化
            used[l][s] = false;
        }
    }
    //首先把第起点放进去
    q.push(P(i, j));
    used[i][j] = true;
    dd[i][j] = 0;
   
    while (!q.empty()) {
        P cur_point = q.front();//先取出一个来
        q.pop();
        for (int k = 0; k < 4; k ++) {
            int nx = cur_point.first + d[k][0];
            int ny = cur_point.second + d[k][1];

            if (isSquare(nx, ny) && maze[nx][ny] == '.' && used[nx][ny] == false) {
                //没出界 并且可以走 所以加到q里面
                dd[nx][ny] = 1 + dd[cur_point.first][cur_point.second];
                if (nx == end_point.first && ny == end_point.second) {
                    //证明走到终点了
                    cout<<dd[nx][ny]<<endl;
                    return ;
                }
                q.push(P(nx, ny));
                used[cur_point.first][cur_point.second] = true;
            }
        }
    }
}

int main() {
    
    cin>>m;
    cin>>n;
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            char a;
            cin>>a;
            maze[i][j] = a;
            if (a == 'S') {
                //起点
                start_point.first = i;
                start_point.second = j;
            }
            else if (a == 'G') {
                //终点
                end_point.first = i;
                end_point.second = j;
                maze[i][j] = '.';
            }
        }
    }

    solve(start_point.first, start_point.second);
    return 0;
}