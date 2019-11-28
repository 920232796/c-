#include<iostream>
#include<queue>

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
    int distance;
};

int row; //行数
int column; //列数
int maze[100][100];//迷宫
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};//四个方向
bool used[100][100];//判断某个点是否已经走过
Point source;//从哪出发
Point target;//到哪去
queue<Point> q;

bool isSquare(Point p) {
    if (p.x >= 0 && p.x <= row - 1 && p.y >= 0 && p.y <= column - 1) {
        return true;
    } 
    return false;
}

void travers() {
    source.distance = 0;
    q.push(source);
    while (!q.empty()) {
        //取出来队列中一个点，这个点是一定可以走的，然后四个方向走，如果可以走，则把点加入到队列中！
        Point cur_point = q.front();
        q.pop();
        //取出来一个点，就把这个点直接标记为已经走过就ok了应该
        used[cur_point.x][cur_point.y] = true;

        //判断是不是终点
        if (cur_point.x == target.x && cur_point.y == target.y) {
            cout<<cur_point.distance<<endl;
            return;
        }
        for (int i = 0; i < 4; i ++) {
            Point new_point;
            new_point.x = cur_point.x + d[i][0];
            new_point.y = cur_point.y + d[i][1];
            if (isSquare(new_point) && maze[new_point.x][new_point.y] == 0 && used[new_point.x][new_point.y] == false) {
                //证明新的这个点是没问题的 可以加到队列中了！
                //首先把走到这个点所需距离 更新一下
                new_point.distance = cur_point.distance + 1;
                q.push(new_point);
                
            }

        } 
    }
    cout<<"不可能走到终点"<<endl;
  
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
   
    travers();

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