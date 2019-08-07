#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

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

	string aaa = a;
	string bbb = b;//用来减法里面比较两数大小
	
	la = strlen(a);
	lb = strlen(b);
	
	for (int i = 0; i < la; i ++) {
		aa[la - i - 1] = a[i] - 48;
	}
	
	for (int i = 0; i < lb; i ++) {
		bb[lb - i - 1] = b[i] - 48;
		
	}
	
	int flag = 0;
	int t[100] = {0};
	if (la < lb) {
		//证明上面那个数短 因此换一下位置 都用大数减小数
		flag = 1;
		for (int i = 0; i < lb; i ++) {
			t[i] = aa[i];
			aa[i] = bb[i];
			bb[i] = t[i];
		}
	}
	else if (la == lb) {
		if (aaa < bbb) {
			//证明第二个数大
			flag = 1;
		for (int i = 0; i < lb; i ++) {
			t[i] = aa[i];
			aa[i] = bb[i];
			bb[i] = t[i];
		}
		}
	}
	
	
	while (lc < la || lc < lb) {
		
		if (aa[lc] < bb[lc]){
			aa[lc] = aa[lc] + 10;
			aa[lc + 1] = aa[lc + 1] - 1;
			c[lc] = aa[lc] - bb[lc];
			lc = lc + 1;
		}
		else{

			c[lc] = aa[lc] - bb[lc];

			lc += 1;
		
		}
	}
	
	if (flag == 1) {
		cout<<"-";
	}
	int flag1 = 0;
	for (int i = 0; i < lc; i ++) {

        if (c[lc - i - 1] != 0) {
            flag1 = 1;
        }
        if (lc == 1 & c[lc - i - 1] == 0) {
            //证明结果为0
            cout<<0;
            break;
        }
        if (flag1 == 0 & c[lc - i - 1] == 0) {
            //证明开头都是0 不输出
            continue;
        }
        cout<<c[lc - i - 1];

    }

	return 0;
}



