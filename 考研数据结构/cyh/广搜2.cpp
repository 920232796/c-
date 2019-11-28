#include<iostream>
using namespace std;


struct Point
{
    int x;
    int y;
    int distance;
};

Point source;
Point target;
int r,c;
int a[100][100]; //迷宫数组 ！(注意错解：定义为a[r][c])
int use[100][100]; //判断迷宫中的点是否入过队，初始化为0

typedef struct
{
    int front,rear;
    Point data[100];

    void InitSqueue()
    {
        front=rear=0;
    }

    bool IsFull()
    {
        if((rear+1)%100==front)
        {
            cout<<"队列已满";
            return false;
        }
        else return true;
    }
    bool IsEmpty()
    {
        if(front==rear)
        {
            cout<<"队列为空";
            return false;
        }
        else return true;
    }

    void EnSqueue(Point P)
    {
        bool b1=IsFull();
        if(b1)
        {
            data[rear]=P;
            rear=(rear+1)%100;
        }
        else cout<<"队列已满";
    }

    void OutSqueue()
    {
        bool b2=IsEmpty();
        if(b2)
        {
            front=(front+1)%100;
        }
    }

    Point GetFront()
    {
        Point q;
        if(IsEmpty())
        {
            q=data[front];
        }
        return q;
    }

} squeue;

squeue s; //全局变量队列 用于广度遍历

bool judgement(Point P)
{
    if(P.x<0||P.x>r-1||P.y<0||P.y>c-1)  //判断是否出界
    {
        return false;
    }
    else if(use[P.x][P.y]==1||a[P.x][P.y]==1) return false; //判断是否入过队和是否能走

    else return true;
}

void BFS()
{
    int dire[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};

    s.EnSqueue(source); //起点入队，修改use数组
    use[source.x][source.y]=1;

    while(s.IsEmpty())
    {
        Point P=s.GetFront();
        s.OutSqueue();
        for(int i=0; i<4; i++)
        {
            Point cur;
            cur.x=P.x+dire[i][0];
            cur.y=P.y+dire[i][1];
            cur.distance = P.distance + 1;
            if(judgement(cur))
            {
                if(cur.x==target.x&&cur.y==target.y)
                {
                    
                    cout<<cur.distance<<endl;
                    return;
                }
                else
                {
                    use[cur.x][cur.y]=1;
                    s.EnSqueue(cur);
                }

            }

        }
    }

}

int main()
{
    cout<<"请输入二维数组的行数r："<<endl;
    cin>>r;
    cout<<"请输入二维数组的列数c："<<endl;
    cin>>c;
    cout<<"请输入二维数组："<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>a[i][j];
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

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            use[i][j]=0;
        }
    }
    source.distance = 0;
    BFS();

    return 0;
}