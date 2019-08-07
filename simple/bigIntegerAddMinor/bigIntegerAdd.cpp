#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main() {
	
	char a[200];
	char b[200];
	
	int aa[200] = {0};
	int bb[200] = {0};
	int c[201] = {0};
	int la, lb, lc = 0;
	
	gets(a);
	gets(b);
	
	la = strlen(a);
	lb = strlen(b);

	
	for (int i = 0; i < la; i ++) {
        // char 数组转换为int数组 并且倒序 下面for循环同理
		aa[la - i - 1] = a[i] - 48;
	}
	
	for (int i = 0; i < lb; i ++) {
		bb[lb - i - 1] = b[i] - 48;
		
	}
	
    int i = 0;//进位
	while (lc < la || lc < lb) {
        int flag = 0; //看最后一位有没有进位

		c[lc] = aa[lc] + bb[lc] + i;
        if (c[lc] >= 10) {
            i = 1;
            if (lc == max(la - 1, lb - 1)) {
                // cout<<"lc = " <<lc;
                //证明最后一位有进位
                c[lc + 1] = 1;
                flag = 1;
            }
        } else {
            i = 0;
        }
        c[lc] = c[lc] % 10;
        lc = lc + 1;
        if (flag == 1) {
            //证明最后一位有进位
            lc = lc + 1;
        }
	}
	
    int flag = 0;
	for (int i = 0; i < lc; i ++) {

        if (c[lc - i - 1] != 0) {
            flag = 1;
        }
        if (lc == 1 & c[lc - i - 1] == 0) {
            //证明结果为0
            cout<<0;
            break;
        }
        if (flag == 0 & c[lc - i - 1] == 0) {
            //证明开头都是0 不输出
            continue;
        }
        cout<<c[lc - i - 1];

    }

	return 0;
}



