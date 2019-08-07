#include<iostream>

using namespace std;

/* input
6
1 3 2 7 6 0
*/

//堆排序其实就是不断的构建堆，然后取最小 然后继续构建堆 取最小~

#define MAX_N 1000

int n;
int a[MAX_N];

int cur_n; //当前多少个没被排好序 - 1 是因为下标从0 开始

// 构建堆
void cons_heap() {
    if (cur_n % 2 == 0) {
        for (int i = cur_n / 2 - 1; i >= 0; i --) {
            int min_left_right = min(a[2 * i + 1], a[2 * i + 2]);
            if (a[i] > min_left_right) {
                if (a[2 * i + 1] > a[2 * i + 2]) {
                    swap(a[i], a[2 * i + 2]);
                } else {
                    swap(a[i], a[2 * i + 1]);
                }
            }
        }
    } else if (cur_n % 2 != 0) {
        for (int i = cur_n / 2; i >= 0; i --) {
            if (2 * i + 2 > cur_n) {
                if (a[i] > a[2 * i + 1]) {
                    swap(a[i], a[2 * i + 1]);
                }
            } else {
                int min_left_right = min(a[2 * i + 1], a[2 * i + 2]);
                if (a[i] > min_left_right) {
                    if (a[2 * i + 1] > a[2 * i + 2]) {
                        swap(a[i], a[2 * i + 2]);
                    } else {
                        swap(a[i], a[2 * i + 1]);
                    }
                }
            }
           
        }
    }

    //到这里一次建堆就结束啦，
    swap(a[0], a[cur_n]);
}

void heap_sort() {

    cur_n = n - 1;
    
    while (cur_n > 0) {
        cons_heap();
        cur_n = cur_n - 1;
    }

}

int main() {
    cin>>n;

    for (int j = 0; j < n; j ++) {
        cin>>a[j];
    }

    heap_sort();

    for (int i = 0; i < n; i ++) {
        cout<<a[i]<<" ";
    }
    return 0;
}