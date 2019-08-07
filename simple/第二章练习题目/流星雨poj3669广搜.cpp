#include<iostream>
#include<utility>
#include<vector>
#include<queue>

using namespace std;

int const M = 50008;

int m;

struct P{
    int x;
    int y;
    int t;
};

int G[305][305]; //表示i j 这个点最早被炸毁的时间

int d[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

bool used[305][305];

queue<P> q;

bool isSquare(int x, int y) {
    return (x >= 0 && y >= 0 && x < 305 && y < 305);
}

void solve() {
    P cur_point;
    cur_point.x = 0;
    cur_point.y = 0;
    cur_point.t = 0;
    q.push(cur_point);

    while (!q.empty()) {
        cur_point = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int nx = cur_point.x + d[i][0];
            int ny = cur_point.y + d[i][1];
            //这里只要走一步 那么时间就要 起点到当前点的时间就需要加1!

            if (isSquare(nx, ny) && !used[nx][ny]) {
                //证明可以走
                int tt = cur_point.t + 1;//起点到当前点的时间就需要加1
                used[nx][ny] = true;
                if (G[nx][ny] > tt) {
                    //证明走到这的时间小于最早爆炸时间 并且没出界 可以走;
                    if (G[nx][ny] == 10000) {
                        //说明安全了!
                        cout<<tt<<endl;
                        return ;
                    }
                    //接着把点加入队列
                    P point;
                    point.x = nx;
                    point.y = ny;
                    point.t = tt;
                    q.push(point);
                   
                }
               
            }
        }
    }
    cout<<-1<<endl;
}

int main() {    
    
    cin>>m;

    for (int i = 0; i < 305; i ++) {
        for (int j = 0; j < 305; j ++) {
            G[i][j] = 10000;//初始化 都可以走
            used[i][j] = false;
        }
    }
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        cin>>a;
        cin>>b;
        cin>>c;

        G[a][b] = min(G[a][b], c);//取最早的炸毁时间！

        for (int j = 0; j < 4; j ++) {
            int nx = a + d[j][0];
            int ny = b + d[j][1];
            if (isSquare(nx, ny)) {
                G[nx][ny] = min(G[nx][ny], c);
            }
        }
    }

    if (G[0][0] == 0) {
        cout<<-1<<endl;
        return 0;
    }

    solve();

    return 0;
}