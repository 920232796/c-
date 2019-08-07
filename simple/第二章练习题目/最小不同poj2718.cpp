#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>

using namespace std; 

char tar[10]; //输入数字的数组
int res = 10000;
int number;
// vector<int> result;


void solve(string a) {
    // int len = (a.length() + 1) / 2;//获取长度 y也就是数字的个数
    int len = number;
    int left = len / 2;
    int right = len - left;
    do {
        string left_digit = "";
        string right_digit = "";
        for (int i = 0; i < left; i ++) {
            left_digit += tar[i];
        }
        for (int j = left; j < len; j ++) {
            right_digit += tar[j];
        }

        if (left_digit[0] == '0' || right_digit[0] == '0') {
            continue;
        }

        stringstream aa; // 把 string转成int 进行相加减
        aa<<left_digit;

        int new_left;
        aa>>new_left;

        stringstream bb;
        bb<<right_digit;

        int new_right;
        bb>>new_right;

        res = min(res, abs(new_left - new_right));

    } while (next_permutation(tar, tar + len));

    cout<<res<<endl;
    // result.push_back(res);

}

int main() {    
    
    int n;
    cin>>n;
    // getchar();
    fflush(stdin); //清空缓冲区 不清空会导致下面的getline函数直接获取缓冲区的 回车 符号 导致输入错误
    for (int i = 0; i < n; i ++) {
        string a;
        getline(cin, a);//这样获取的a里面是包含空格的，所以接下来需要把数字提取出来
        number = 0;
        res = 10000;
        for (int j = 0; j < a.length(); j ++) {
            if (a[j] <= '9' && a[j] >= '0') {
                tar[number] = a[j];
                number ++;
            }
        }
        solve(a);
    }

    // for (int j = 0; j < result.size(); j ++) {
    //     cout<<result[j]<<endl;
    // }

    return 0;
}