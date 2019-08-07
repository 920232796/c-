#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

/*
2 5
-3 4
-6 3


4 5
-5 3
-3 5
2 3
3 3

20 8
-20 7
-18 6
-5 8
-21 8
-15 7
-17 5
-1 5
-2 3
-9 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 7
9 6
10 5
0 0

2 3
0 2
2 3

2 3
0 2
1 3

3 3
1 2
-3 2
2 4

8 5
2 4
-4 4
-3 3
-3 1
-3 0
-1 0
0 5
6 0

3 0
1 2
-3 1
2 1

3 2
1 2
-3 1
2 1

1 2
0 2


2 3
0 2
2 3

4 -5
4 3
4 3
2 3
6 -9



3 -3
1 2
-3 2
2 1

6 2
1 2
1 2
1 2
-3 1
2 1
0 0

1 2
0 2

2 3
0 2
1 3

3 10
1 10
2 3
4 5

3 5
1 10
2 3
4 5

4 7
1 10
2 3
4 5
0 0

3 9
1 10
2 3
4 5
0 0

================结果
Case 1: 1
Case 2: 2
Case 3: 4
Case 4: 1
Case 5: 1
Case 6: -1
Case 7: 3
Case 8: -1
Case 9: 2
Case 10: 1
Case 11: 1
Case 12: -1
Case 13: -1
Case 14: 2
Case 15: 1
Case 16: 1
Case 17: 1
Case 18: -1
Case 19: -1
Case 20: -1
 */

using namespace std;

#define MAX_N 1000

int n;
int d;

int res;

vector<int> res_v;

struct Island {
    int x;
    int y;
    float left;
    float right;
};

Island islands[MAX_N];

bool comp(Island island_1, Island island_2) {
    return island_1.right <= island_2.right;
}

void solve() {
    res = 0;

    for (int i = 0; i < n; i ++) {
        if (islands[i].y == -1) {
            continue;
        }

        res += 1;
    
        for (int j = i + 1; j < n; j ++) {
            if (islands[j].left <= islands[i].right) {
                islands[j].y = -1;
            }
        }
    }

    res_v.push_back(res);

}

int main() {

    while (true) {
        cin>>n;
        cin>>d;
        if (n == 0 && d == 0) {
            break;
        }
        int flag = 0;
        for (int i = 0; i < n; i ++) {
            int x;
            int y;
            cin>>x;
            cin>>y;
            islands[i].x = x;
            islands[i].y = y;
            islands[i].left = x - sqrt(d * d - y * y);
            islands[i].right = x + sqrt(d * d - y * y);
        }

        for (int i = 0; i < n; i ++) {
            if (islands[i].y > d) {
                res_v.push_back(-1);
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            continue;
        }

        sort(islands, islands + n, comp);

        solve();


    }
    for (int i = 0; i < res_v.size(); i ++) {
        cout<<"Case "<<i + 1<<":"<<" "<<res_v[i]<<endl;
    }
    
    
    return 0;
}