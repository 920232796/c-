#include<bits/stdc++.h>
using namespace std ;

//===========����ʵ�ֿ�ʼ========

const int N = 100005;

//ջ
string Stack[N];
int n,top;
//ѹ��ջ��
void push(string name){
    top++��
    Stack[top] = name;
}
//����ջ��
string pop{
    string ret = Stack[top];
    top = top-1;
    return ret;
}
//ѯ��ջ��ĳ��Ԫ�ص�λ��
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
