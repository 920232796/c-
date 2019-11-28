#include<iostream>
#include<queue>

using namespace std;
/*
8 7
1 5
1 7
5 2
5 3
3 6
7 4
4 8
    
*/

int N, E;
int graph[100][100];//定义一个图
queue<int> q; //定义一个存放顶点的队列～
bool used[100][100];

void bfs() {

    //可以从顶点0开始bfs

    q.push(0);

    graph[0][0] = 2;//定义初始颜色为2

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        //获取当前颜色
        int cur_color = graph[node][node];
        //染色周围的点
        //先查看可不可以走
        for (int i = 0; i < N; i ++) {
            if (i == node) {
                continue;
            }
            if (graph[node][i] != 0 && !used[node][i]) {
                //证明可以走
                //查看一下颜色
                used[node][i] = true;
                used[i][node] = true;
                if (graph[i][i] == cur_color) {
                    cout<<i+1<<endl;
                    //颜色跟当前此点颜色一样了！证明不是二分图
                    cout<<"no!"<<endl;
                    return ;
                } else {
                    //可能没颜色 ，也可能跟此点颜色不一样，就统一染一下色把
                    graph[i][i] = - cur_color;
                    //染完色还要加入队列！
                    q.push(i);
                }
            }
        }
    }
    //走到这说明是二分图 没问题了
    cout<<"yes!"<<endl;

}


int main() {

    cin>>N>>E;//输入顶点，边数

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            graph[i][j] = 0;//0 表示不通
            used[i][j] = false; // 表示都没走过
        }
    }

    for (int i = 0; i < E; i ++) {
        int from;
        int to;
        cin>>from>>to;
        graph[from - 1][to - 1] = 1;//1 表示相通
        graph[to - 1][from - 1] = 1;
    }

    bfs();

    return 0;

}