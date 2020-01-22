#include<fstream>
#include<cmath>
using namespace std;
ifstream cin("chess.in");
ofstream cout("chess.out");
long a[101][101],n,m,f[2][2]={{1,0},{0,1}},min1=2147483647;
void dg(long x,long y,long ys,long value,bool b1)
{
	if((x!=m)||(y!=m))
	{
		for(long x1=0;x1<=1;x1++)
		{
			long nowx=x+f[x1][0],nowy=y+f[x1][1];
			if((nowx<=m)&&(nowy<=m))
			{
				if((a[nowx][nowy]==-1)&&(!b1))
				{
					dg(nowx,nowy,1,value+abs(ys-1)+2,true);
					dg(nowx,nowy,0,value+abs(ys)+2,true);
				}
				if(a[nowx][nowy]!=-1)
					dg(nowx,nowy,a[nowx][nowy],value+abs(ys-a[nowx][nowy]),false);
			}
		}
	}
	else
		min1=min(min1,value);
	
}
int main()
{
	cin>>m>>n;
	for(long x=1;x<=n;x++)
		for(long y=1;y<=n;y++)
			a[x][y]=-1;
	for(long x1,y1,c,x=1;x<=n;x++)
	{
		cin>>x1>>y1>>c;
		a[x1][y1]=c;
	}
	dg(1,1,a[1][1],0,false);
	if(min1!=2147483647)
		cout<<min1<<endl;
	else
		cout<<-1<<endl;
	return(0);
	cin.close();
	cout.close();
}
