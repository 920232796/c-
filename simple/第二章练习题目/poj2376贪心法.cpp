#include<iostream>

using namespace std;

const int N = 25000;
int n;
int T;

int start_time[N];
int end_time[N];

int res;

void solve() {

    int cur = 1;
    res = 0;

    while (cur < T + 1) {

        int right = -1;
        int pos = -1;

        for (int i = 0; i < n; i ++) {
            if (start_time[i] <= cur) {
                if (right < end_time[i]) {
                    right = end_time[i];
                    pos = i;
                }
            }
        }

        if (pos == -1) {
            cout<<-1<<endl;
            return ;
        }

        res += 1;
        cur = end_time[pos] + 1;
        start_time[pos] = 1000001;
        end_time[pos] = 1000001;
    }
    
    cout<<res;
    return;
}

int main() {

    cin>>n;
    cin>>T;

    for (int i = 0; i < n; i ++) {
       
        cin>>start_time[i];
        cin>>end_time[i];
     
    }

    solve();
    return 0;
}