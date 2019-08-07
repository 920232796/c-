#include<iostream>
#include<string>

//字符环问题，这种问题 一看是环 就要想到取余.....
using namespace std;

int main() {
    string a;
    string b;
    cin>>a;
    cin>>b;
    int ans = 0; //b保存结果

    // string c = a + a;
    // string d = b + b;

    int len_a = a.size();
    int len_b = b.size();

    for (int i = 0; i < len_a; i ++) {

        for (int j = 0; j < len_b; j ++) {
            int k = i;
            int l = j;
            int nl = 0;
            while (a[k] == b[l] & nl < min(len_a, len_b)) {

                k += 1;
                l += 1;
                k = k % len_a;
                l = l % len_b;
                nl += 1;
            }
            if (nl > ans) {
                //证明有更优的解
                ans = nl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}