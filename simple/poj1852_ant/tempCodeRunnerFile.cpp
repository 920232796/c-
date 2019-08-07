#include<iostream>
#include<algorithm>

using namespace std;
#define maxn 1000100

int L;
int antNum;
int ant[maxn];

int minLength[] = {0};

int minTime() {
    //就是让蚂蚁都朝向较近的那一端
    for (int i = 0; i < antNum; i ++) {
        minLength[i] = min(ant[i], L - ant[i]);
    }
    int minTime = *max_element(minLength, minLength + antNum);
    return minTime;
}

int maxTime() {
    //就是求最远的距离，距任意一端
    for (int i = 0; i < antNum; i ++) {
        minLength[i] = max(ant[i], L - ant[i]);
    }
    int maxTime = *max_element(minLength, minLength + antNum);
    return maxTime;
}

int main() {
    int n;
   
    cin>>n;
    for (int i = 0; i < n; i ++) {
        //一共n个案例
        cin>>L;
        cin>>antNum;
        for (int j = 0; j < antNum; j ++) {
            cin>>ant[j];
        }
        cout<<minTime()<<"  ";
        cout<<maxTime()<<"  "<<endl;
    }

   
    return 0;
}

