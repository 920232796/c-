#include<bits/stdc++.h>

using namespace std;

int main() {
    // string a, b;

    // getline(cin, a);
    // getline(cin, b);

    // int on = 0, down = 0,f = 0;

    // while(on <= a.length() && down <= b.length()) {
    //     if (a[on] == ' ') {
    //         on ++;
    //         continue;
    //     }
    //     if (b[down] == ' ') {
    //         down ++;
    //         continue;
    //     }

    //     if (tolower(a[on]) != tolower(b[down])) {
    //         f = 1;
    //         break;
    //     }
    //     on ++;
    //     down ++;

    // }

    // if (f == 1) {
    //     cout<<"NO";
    // } else {
    //     cout<<"YES";
    // }

    string a;
    getline(cin, a);

    int q = 0;
    for (int i = 0; i < a.length(); i ++) {
        if (a[i] == ' ') {
            cout<<q<<",";
            q = 0;
        } else {
            q ++;
        }
    }
    cout<<q;


    // string a = "im student am";

    // reverse(a.substr(1, 10).begin(), a.substr(1, 10).end());
    // // cout<<a.begin()<<endl;

    // cout<<a;

    // cout<<a;

    // // char a[4] = {'a', 'b', 'c', 'd'};
    // string a = "Hello    World ni hao";

    // int flag = 0;
    // for (int i = 0; i < a.length(); i ++) {
    //     if (a[i] == ' ') {
    //         flag += 1;
    //     } else {
    //         flag = 0;
    //     }

    //     if (flag > 1) {
    //         a.erase(i, 1);
    //         i --;
    //     }

    // }

    // cout<<a;
    // cout<<a[:2];
    // string str1 = "Hello, World";
    // string str2 = "hello, world";

    // for (int i = 0; i < str1.length(); i ++) {
    //     str1[i] = tolower(str1[i]);
    // }

    // for (int i = 0; i < str2.length(); i ++) {
    //     str2[i] = tolower(str2[i]);
    // }

    // if (str1 < str2) {
    //     cout<<"<";
    // } else if (str1 > str2) {
    //     cout<<">";
    // } else {
    //     cout<<"=";
    // }
    return 0;
}