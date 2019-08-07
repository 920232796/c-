#include<bits/stdc++.h>

using namespace std;

const int N = 500 * 2, M = N * N;

struct E {
    
    //next 下一条邻接边
    //to   本条边所指向的终点
    int next, to;
} e[M];

//ihead 邻接表的头
//cnt 邻接表的大小00
//mc 表示每个点所匹配到的另一个点 mc[1] = 10 表示 第一个节点跟第十个节点匹配
//vis Y集元素是否被访问过
int cnt, ihead[N], mc[N];
bool vis[N];

//邻接表连边 表示x 到y 的一条有向边
//x 起点
//y 终点
void add(int x, int y) {
    ++cnt;
    e[cnt].next = ihead[x];
    e[cnt].to = y;
    ihead[x] = cnt; 
}

//匈牙利算法
//x ： x集上的点 从当前点出发找增广路
//返回值 若找到增广路则返回true 否则返回false
bool dfs(int x) {
    for (int i = ihead[x]; i != 0; i = e[i].next) {
        int y = e[i].to;
        if (!vis[y]) {//如果找到Y集上一点没有被标记
            vis[y] = true;//标记该点
            if (mc[y] == 0 || dfs(mc[y])) { //如果y是没有匹配点的，说明找到了一条路， 或者说递归查找y的匹配点，得到了一条增广路
                //找到了增广路，应该怎么样更新mc数组？？
                mc[x] = y;
                mc[y] = x;
                return true;
            }
        }
    }

    return false;
}

//求解棋盘上能放多少车 棋盘大小为n * n
// board 所给的棋盘，为一的位置上可以放车
//返回能放的车的最大的个数
int getAnswer(int n, vector<vector<int>> board) {
    //我们将行看作n个点 列看作另外n个点 标号分别为1 到n 和 n + 1 到 2n

    //初始化
    cnt = 0;
    for (int i = 1; i <= 2 * n; i ++) {
        ihead[i] = 0;
        mc[i] = 0;
    }

    //连边
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (board[i - 1][j - 1] == 1) {
                add(i, j + n);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= n; i ++) {
        if (mc[i]) {
            //如果X集中第i个点没有匹配到y集中的点，则从这个点出发找增广路
            memset(vis, 0, sizeof(bool) * (n * 2 + 1));
            if (dfs(i)) {
                //如果找到 答案直接 ＋ 1 
                ++ans;
            }
        }
    }

}

int main() {

    return 0;
}

