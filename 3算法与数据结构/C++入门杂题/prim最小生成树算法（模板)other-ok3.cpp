#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAXN 5000+5 
const int INF=99999999;
int n,m;
int dis[MAXN+1];
bool book[MAXN+1];//标记一个点是否加入最小生成树 
int sum;//整条最小生成树的长度
int map[MAXN+1][MAXN+1],tot;
void Prim()
{
    int pos;//记录最小的边连向的点的编号 
    book[1]=true;//将1号顶点加入//用true比较好，因为初始化是false 
    tot++;
    while(tot<=n-1)//到n的时候就不能再进行加点操作了，因为都进入了
    {
        int min=INF;
        for(int i=1;i<=n;i++)
            if(book[i]==false && dis[i]<min){//注意对book的判断啊，加入最小生成树的就肯定不能再去判断 
                min=dis[i];
                pos=i;
            }
        book[pos]=true;//注意book的操作 
        tot++;
        sum+=dis[pos];
        for(int k=1;k<=n;k++)//枚举pos点的所有出边，进行松弛操作 
        {
            if(book[k]==false && dis[k]>map[pos][k])//如果pos不能到达k点也成立，因为那是INF不会小于的
                dis[k]=map[pos][k];
        }

}//怎么判断这个图不联通啊
    //要有的输出orz 
}
int main() 
{
    scanf("%d%d",&n,&m);
    //记得初始化
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)
                map[i][j]=0;
            else
                map[i][j]=INF;
    //注意初始化要在赋值之前 
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        /*if(edge[i].u==edge[i].v)
            continue;*///也可以这样去自环 
        if(w<map[u][v])//处理重边，按题目要求，求最小生成树，所以取最小 

{//所以之前的初始化更有必要了
            map[u][v]=w;
            map[v][u]=w;
        }
    }
    //初始化dis数组 
    //这里最开始默认为1号顶点为源点，开始是1号顶点到各个顶点的初始距离，因为开始最小生成树里只有1号 
    for(int i=1;i<=n;i++)
        map[i][i]=0;//去环操作——数据有毒，有一个点组成正环 
    for(int i=1;i<=n;i++)
        dis[i]=map[1][i];
    Prim();
    printf("%d",sum);
        return 0; 
}

