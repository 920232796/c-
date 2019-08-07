#include<iostream>
#include<algorithm>

using namespace std;
#define maxn 1000100

int L;
int antNum;
int ant[maxn];

int minLength[maxn];

int minTime() {

    for (int i = 0; i < antNum; i ++) {
        minLength[i] = min(ant[i], L - ant[i]);
    }

    int minTime = *max_element(minLength, minLength + antNum);
    return minTime;
}

int maxTime() {
    //��������Զ�ľ��룬������һ��
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
        //һ��n������
        cin>>L;
        cin>>antNum;
        for (int j = 0; j < antNum; j ++) {
            cin>>ant[j];
        }

        cout<<minTime()<<" ";
        cout<<maxTime()<<" "<<endl;
    }
    
    return 0;
}

