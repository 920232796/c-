#include<cstdio>
#include<stack> 
#include<cstring>
using namespace std;
//部分和问题：
const int maxn = 22;
stack<int>v;
int a[maxn];
int n,m,i,j,k;
bool dfs(int i = 0,int sum = 0)     //已经从前i项得到了和sum,然后对于i项之后的进行分支
{
    //停止条件 ：如果前n项都计算过了，则返回sum是否与k相等 
    if(i==n) return sum==k;
    //选择加或不加a[i]
        //不加a[i]的情况 
    if(dfs(i+1,sum)) return true;
        //加上a[i]的情况 
    if(dfs(i+1,sum+a[i])){
        //若执行该条件，就说明该a[i]符合条件 
        v.push(a[i]);//压栈 
        return true;
    } 
    return false;           //无论是否加上a[i]都不能凑成k就返回false;
}
int main(){
    while(~scanf("%d%d",&n,&k)){
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
        }if(dfs()){
            printf("YES\n");
            while(!v.empty()){
                int x = v.top();
                printf("%d ",x);
                v.pop();
            }
            printf("\n");
        }else
            printf("NO\n");        
    }
    return 0;
}