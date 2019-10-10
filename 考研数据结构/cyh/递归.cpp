#include<iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

int a[30][30];
int r,c;
Point source;
Point target;
int mindis=1000;
int use[100][100];  //初始化路径数组

bool judgement(Point P)
{
    if(P.x<0||P.y<0||P.x>r-1||P.y>c-1)
    {
        return false;
    }

    else return true;
}

void travers(Point P,int distance)
{
    int dire[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0; i<4; i++)
    {   
        // cout<<"hello world"<<endl;
        P.x=P.x+dire[i][0];
        P.y=P.y+dire[i][1];

        bool judge=judgement(P);
        if(judge)
        {   
            if(a[P.x][P.y]==3)
            {   
                distance ++;
                if(distance<mindis)
                {
                    
                    mindis=distance;
                }
            return; 
            }
            if(a[P.x][P.y]==0&&use[P.x][P.y]==0)
            {
                use[P.x-dire[i][0]][P.y-dire[i][1]]=1;
                // cout<<distance<<" ";
                distance++;
                travers(P,distance);
                use[P.x-dire[i][0]][P.y-dire[i][1]]=0;
                distance --;
            }
          
        }
          //不管走不走 都要退回去
            P.x=P.x-dire[i][0];
            P.y=P.y-dire[i][1];
        
    }
}

int main()
{
    // cout<<"请输入二维数组的行数r："<<endl;
    cin>>r;
    // cout<<"请输入二维数组的列数c："<<endl;
    cin>>c;
    // cout<<"请输入二维数组："<<endl;
  
    int distance=0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            use[i][j]=0;
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(a[i][j]==2)
            {
                source.x=i;
                source.y=j;
            }
            if(a[i][j]==3)
            {
                target.x=i;
                target.y=j;
            }
        }
    }

    travers(source,distance);
    cout<<mindis<<endl;
    return 0;
}