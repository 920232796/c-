#include<bits/stdc++.h>
using namespace std ;

//===========代码实现开始========

const int N = 100005;

//栈
string Stack[N];
int n,top;
//压入栈顶
void push(string name){
    top++；
    Stack[top] = name;
}
//弹出栈顶
string pop{
    string ret = Stack[top];
    top = top-1;
    return ret;
}
//询问栈中某个元素的位置
string query(int pos){
    return Stack[pos];
}
int main(){
    int n;
    scanf("%d",&n);
    char name[20];
    for(; n--; ){
        int op;
        scanf("%d",&op);
        if(op == 1){
            scanf("%s",name);
            push(name);
        }else if(op == 2){
            printf("%s\n",pop().c_str());
        }else {
            int pos;
            scanf("%d",&pos);
            printf("%s\n",query(pos).c_str());
        }
    }
    return 0;
}
