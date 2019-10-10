#include<iostream>
#include<vector>

using namespace std;

/*
10 10
1 2 1 1 1 1 1 1 0 1
0 0 0 0 0 0 1 0 0 1
0 1 0 1 1 0 1 1 0 0
0 1 0 0 0 0 0 0 0 0
1 1 0 1 1 0 1 1 1 1
0 0 0 0 1 0 0 0 0 1
0 1 1 1 1 1 1 1 0 1
0 0 0 0 1 0 0 0 0 0
0 1 1 1 1 0 1 1 1 0
0 0 0 0 1 0 0 0 3 1
 
*/

struct Point {
    int x;
    int y;
};

int row; //行数
int column; //列数
int maze[100][100];//迷宫
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};//四个方向
bool used[100][100];//判断某个点是否已经走过
Point source;//从哪出发
Point target;//到哪去
int res;//保存最后结果用
Point res_trace[100];

bool isSquare(Point p) {
    if (p.x >= 0 && p.x <= row - 1 && p.y >= 0 && p.y <= column - 1) {
        return true;
    } 
    return false;
}

void travers(Point cur, int distance, Point trace[]) {
    //对四个方向进行循环
    for (int i = 0; i < 4; i ++) {
        int cur_distance = distance;
        cur.x = cur.x + d[i][0];
        cur.y = cur.y + d[i][1];
        if (isSquare(cur) && !used[cur.x][cur.y] && maze[cur.x][cur.y] == 0) {
            //证明可以走
            // cout<<cur_distance<<" ";
            
            cur_distance += 1;
            trace[cur_distance].x = cur.x;
            trace[cur_distance].y = cur.y;
            //这里把刚才走过的那个坐标标记为true
            used[cur.x - d[i][0]][cur.y - d[i][1]] = true;
            if (cur.x == target.x && cur.y == target.y) {
                //证明走到终点了！可以终止了！ 
                
                if (res > cur_distance) {
                    //证明找到了一个更小的距离 保存一下
                    res = cur_distance;
                    for (int i = 0; i <= res; i ++) {
                        res_trace[i] = trace[i];
                    }
                }
                return;
            }
            //继续深度优先搜索
            travers(cur, cur_distance, trace);
            //这里一定记得还原used矩阵！ 坑
            used[cur.x - d[i][0]][cur.y - d[i][1]] = false;
        }
        //因为要换方向走了，还原一下当前的位置
        cur.x = cur.x - d[i][0];
        cur.y = cur.y - d[i][1];
    }
}

void solve() {
    //进行一些初始化工作
    Point trace[100];
    trace[0].x = source.x;
    trace[0].y = source.y;
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < column; j ++) {
            used[i][j] = false;
        }
    }
    res = 1000000;//初始化一个很大的距离
    travers(source, 0, trace);

    cout<<res<<endl;//输出最后结果

    for (int i = 0; i <= res; i ++) {
        cout<<"("<<res_trace[i].x<<","<<res_trace[i].y<<")"<<"  ";
    }

    cout<<endl;

}

int main() {

    cin>>row;
    cin>>column;
  
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < column; j ++) {
            cin>>maze[i][j];
            if (maze[i][j] == 2) {
                source.x = i;
                source.y = j;
            } else if (maze[i][j] == 3) {
                //终点
                maze[i][j] = 0;
                target.x = i;
                target.y = j;
            }
        }
    }
    cout<<endl;
    solve();

    return 0;
}