#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int N;
string T = "";
string S = "";
string s = "";
int main() {
    cin>>N;
    for (int i = 0; i < N; i ++) {
        cin>>s;
        S.append(s);
    }
    // cout<<S<<endl;
    // cout<<strcmp("A", "B");
    // S.erase(S.size() - 1, S.size()); //删除string最后一个元素
    // cout<<S<<endl;
    // cout<<S<<endl;
   
    for (int j = 0; j < N; j ++) {
        //开始构造T
        if (S.substr(0, 1) < S.substr(S.size() - 1, 1)) {
            //证明第一个字符比末尾的小 因此要使用第一个
            T.append(S.substr(0, 1));
            S = S.substr(1);
        } else if (S.substr(0, 1) > S.substr(S.size() - 1, 1)){
            //证明第一个字符比末尾的大 使用最后一个
            T.append(S.substr(S.size() - 1, 1));
            S.erase(S.size() - 1, S.size());
        } else {
            string s_sub = "";
            //相等的情况
            for (int k = S.size() -1; k >= 0; k --) {
                s_sub.append(S.substr(k, 1));
                //这里是将S倒叙    
            }
            if (S >= s_sub) {
                //应该从S末尾取出元素
                T.append(S.substr(S.size() - 1, 1));
                S.erase(S.size() - 1, S.size());
            } else {
                T.append(S.substr(0, 1));
                S = S.substr(1);
            }
        }

    }
    
    // int n;
    // if (T.size() > 80) {
    //     n = int(T.size() / 80);
    //     for (int l = 0; l < n; l ++) {
    //         cout<<T.substr(l * 80, 80)<<endl;
    //     }
    // } else {
    //     cout<<T;
    // }
    int ans = 0;
    for (int i = 0; i < N; i ++) {
        cout<<T.substr(i, 1);
        ans = ans + 1;
        if (ans % 80 == 0) {
            cout<<"\n";
        }
    }
   
    return 0;
}