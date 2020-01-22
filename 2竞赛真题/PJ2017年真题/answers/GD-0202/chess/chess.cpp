#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int m,n,a[1000][1000],x[1010],y[1010],b[1010],min1=90000000;
bool c[1010][1010],d[1010][1010];
int x1[5]={0,+1,0,-1,0},y1[5]={0,0,+1,0,-1};
int i,j,p=0;
void ab(int xx,int yy,int sum)
{
	int q;
	bool bb=false;
	if (xx>m||yy>m||xx<=0||yy<=0||a[xx][yy]==0||c[xx][yy]==true) return;
	if (bb==true&&a[xx][yy]!=0) return;
	
	if (p!=0&&p!=a[xx][yy]) sum++;
	
	if (xx==m&&yy==m)                         //到达（m，m）点 
	{
		if (sum<min1)
		{
			min1=sum;                        //取最小coin 
			return;
		}
	}
	
	p=a[xx][yy];
	for (q=1;q<=4;q++)
	{
		
		c[xx][yy]=true;
		ab(xx+x1[q],yy+y1[q],sum);           //上下左右碰运气地瞎走 
		c[xx][yy]=false;
	}
	
	//for (q=1;q<=4;q++)                      算了选择放弃。。 
	//{
		//if (a[xx+x1[q]][yy+y1[q]]==0&&d[xx+x1[q]][yy+y1[q]]==false)
		//{
			//d[xx+x1[q]][yy+y1[q]]=true;
			//c[xx+x1[q]][yy+y1[q]]=true;
			//a[xx+x1[q]][yy+y1[q]]=p;
			//ab(xx+x1[q],yy+y1[q],sum+2);          //哈哈哈机智地用魔法变变变 
			//a[xx+x1[q]][yy+y1[q]]=0;
			//d[xx+x1[q]][yy+y1[q]]=false;
			//c[xx+x1[q]][yy+y1[q]]=false;
		//}
		
	//}
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>b[i];
		if (b[i]==0) a[x[i]][y[i]]=1;      //假设原b数组的0为1-- 红 
		if (b[i]==1) a[x[i]][y[i]]=2;      //假设原b数组的1为2-- 黄 
	}
	
	ab(1,1,0);
	
	if (min1!=90000000) cout<<min1;
	else cout<<-1;
	
	return 0;
}
