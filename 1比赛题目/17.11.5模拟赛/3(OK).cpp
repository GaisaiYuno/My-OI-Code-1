#include <iostream>
using namespace std;
int n,m,map[111][111];
struct node
{
    int num1,num2; //到达当前点状态，num1：耗完能量的最多次数，num2：满足num1的路线数
}ss[111][111];
void add(int x,int y,int xx,int yy,int k) //从（x，y）走到（xx，yy），k：标记此次移动能量是否耗完
{
    if(ss[xx][yy].num1==ss[x][y].num1+k) //相等则把路线数加上来
    ss[xx][yy].num2+=ss[x][y].num2;
    if(ss[xx][yy].num1<ss[x][y].num1+k) //如果当前走法得到的耗完能量最多次数更加多则更新耗完能量最多次数和路线数
    {
        ss[xx][yy].num1=ss[x][y].num1+k;
        ss[xx][yy].num2=ss[x][y].num2;
    }
}
int main (void)
{
    int t,i,j,k,l,x,y,xx,yy,v;
    cin>>t;
    while(t--&&cin>>n>>m)
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>map[i][j];
            ss[i][j].num1=ss[i][j].num2=0;
        }
        ss[1][1].num2=1;
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(!ss[i][j].num2)continue; //为了优化，只要对先前到达过的点进行移动处理
            l=i+j+map[i][j]; //判断当前点能走的最远距离
            if(!map[i][j]||i==n&&j==m)continue;  //如果当前点能量为0或者是终点，那么不用处理
            if(l>=n+m) //如果能走的最远距离大于或等于走到终点的距离，即能走到终点
            {
                add(i,j,n,m,(l==n+m)?1:0); //如果走到终点能量耗完，则标记1
                continue;
            }
            for(k=i;k<=l;k++) //遍历当前点右下方能走到的那些点
            {
                if(k<=n&&l-k<=m&&l-k>=j) //不出界
                {
                    add(i,j,k,l-k,1);
                }
            }
        }
        cout<<ss[n][m].num1<<" "<<ss[n][m].num2<<endl;
    }
    return 0;
}

