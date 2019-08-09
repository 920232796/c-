#include<iostream>

using namespace std; 

int n;
int a[100];

int quick_sort(int i, int j) {

    int pivot = a[i];
    
    while (i < j) {
        
        while( i < j && a[j] >= pivot) {
            j --;
        }
        //说明找到一个 比 pivot小的元素了 要进行赋值
        a[i] = a[j];
   

        while(i < j && a[i] <= pivot) {
            i ++;
        }
        //说明找到了一个比 pivot 大的元素了 
        a[j] = a[i];
 
    }
    
    a[i] = pivot;

    // cout<<i<<endl;
    return i;
    

}

void solve(int i, int j) {

    if (i >= j) {
        return ;
    }
    int temp = quick_sort(i, j);
    // cout<<temp<<endl;
    solve(i, temp - 1);
    solve(temp + 1, j);


}

int main() {

    cin>>n;
    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }

    solve(0, n - 1);
    // quick_sort(0, n - 1);

    // quick_sort(0, 3);
    // quick_sort(5, 8);
    // quick_sort(5, 8);

    for (int i = 0; i < n; i ++) {
        cout<<a[i]<<" ";
    }
    return 0;
}