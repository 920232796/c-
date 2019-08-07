#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

struct edge {
    int from;
    int cost;

    friend bool operator < (const edge &e1, const edge &e2) {
        return e1.cost < e2.cost;
    }
};

int main() {

    priority_queue<P, vector<P>, greater<P> > q;

    q.push(P(-100, 10));
    q.push(P(-200, 20));
    q.push(P(-50, 21));

    cout<<q.top().first;

    // edge e1;
    // e1.cost = 10;
    // e1.from = 20;

    // edge e2;
    // e2.cost = 20;
    // e2.from = 10;
    // q.push(e2);

    // cout<<q.top().cost<<endl;

    // q.push(P(0, 100));
    // q.push(P(1, 11));
    // q.push(P(2, 5));
    // q.push(P(6, 2));

    // printf("%d\n", q.top().first);
    // cout<<q.top().second<<endl;
    // q.pop();

    // P p(10, 1);

    // cout<<p.first<<endl;

    // int M[10][10];

    // for (int i = 0; i < 10; i ++) {
    //     fill(M[i], M[i] + 10, 2);
    // }

    // for (int i = 0; i < 10; i ++) {

    //     for (int j = 0; j < 10; j ++) {

    //         printf("%d", M[i][j]);
    //     }

    //     printf("\n");
    // }
    return 0;
}