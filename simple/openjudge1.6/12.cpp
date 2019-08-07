#include<iostream>

using namespace std;

#define maxn 32

int n;//二的n次方

int main() {

    int a[maxn];
    a[0] = 1;//初始结果
    int cur = 0;//记录当前运算到第几位了
    cin>>n;
    for (int i = 0; i < n; i ++) {
        // int flag_end = 0;//表示最后一位有无进位
        int flag = 0;//进位
        for (int j = 0; j < cur + 1; j ++) {
            //这个循环就是 每次 * 2 都要从最低位开始， 每一位都 * 2 判断进位 加到下一位，一直算到最后一位。 cur刚开始为0 就证明只有一位，那么就循环一次 所以j < cur + 1
            a[j] = a[j] * 2 + flag;
            if (a[j] >= 10) {
                //证明！！ 有进位了。。如果是最后的一位有进位的话，cur要往后走一位，然后 最新的a[cur] = 1 赋值为1 才行。 若不是最后一位有进位 那么就不需要cur往后走一位
                flag = 1;
                a[j] = a[j] % 10;
                if (j == cur) {
                    //证明最后一位有进位！！ cur要往后走了
                    // flag_end = 1;
                    cur = cur + 1;
                    a[cur] = 1;
                    flag = 0;
                    break;
                }
            } else {
                flag = 0;
            }
        }
    }

    for (int j = 0; j < cur + 1; j ++) {
        cout<<a[cur - j];
    }
    
    return 0;
}