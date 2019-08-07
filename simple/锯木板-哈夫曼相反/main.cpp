#include <bits/stdc++.h>

using namespace std;


//N 表示 最终锯成多少段
//L是每段的长度
int getAnswer(int N, priority_queue<int> L) {

    int Len = 21;//总长度21
    int remind = Len;//剩余长度
    int deep[N];//标记元素深度
    int element[N];
    for (int j = 0; j < N; j ++) {
        deep[j] = 0;//初始化深度为0
    }
    for (int i = 0; i < N - 1; i ++) {
        //每次拿出最大的一个元素出来
        int max_ele = L.top();
        element[i] = max_ele;
        L.pop();
        //标记这个最大元素的深度
        deep[i] = i + 1;
        remind = remind - max_ele;
    }
    if (N > 1) {
        element[N - 1] = remind;
        deep[N - 1] = deep[N - 2];
    }

    int loss = 0;
    for (int i = 0; i < N; i ++) {
        loss = loss + deep[i] * element[i];
    }


    return loss;
}

int main() {

    int N;
    priority_queue<int> q;
    cin>>N;
    for (int i = 0; i < N; i ++) {
        int input;
        cin>>input;
        q.push(input);
    }

    cout<<getAnswer(N, q);
    
    return 0;
}