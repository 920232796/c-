#include<iostream>

using namespace std;

string p;
string t;

int my_next[100];

void get_next() {

    my_next[0] = -1;
    //等于 -1 很重要 证明j 要回退到 -1 的位置，然后match函数里面会进行 j ++ 所以相当于j 从 0 的 位置重新跟t[i]匹配 

    int k = -1; 
    int j = 0;
    while (j < p.size() - 1) { //这里注意是 减 1 因为 下面循环是对未来一个状态填写 my_next[j + 1] = k + 1;  所以这里减 1 就ok 
        
        if (k < 0 || p[j] == p[k]) {
            my_next[j + 1] = k + 1; 
            k ++;
            j ++;
        } else if (p[j] != p[k]) {
            k = my_next[k];
        }
    }

}

int match() {

    get_next(); //获取next数组

    int j = 0;
    int i = 0;
    cout<<t.size()<<endl;
    cout<<p.size()<<endl;
    int len_p = p.size();
    int len_t = t.size();
    while (i < len_t && j < len_p) {
        if (i == 10) {
            cout<<"helloworld"<<endl;
        }
        
        // cout<<"j = "<<j<<endl;
        if (j < 0 || t[i] == p[j]) {
            i ++;
            j ++;
        } else {
            j = my_next[j];
        }

    }

    cout<<"i = "<<i<<endl;
    cout<<"j = "<<j<<endl;
    
    if (j == p.size()) {
        //说明匹配成功了
        return i - j;
    } 

    return -1;
}

int main() {

    t = "SADFASDGRGMAMAMMIASDASDWF";
    p = "MAMAMMIA";
    cout<<match()<<endl;
    
    for (int i = 0; i < p.size(); i ++) {
        cout<<my_next[i]<<" ";
    }
    return 0;
}