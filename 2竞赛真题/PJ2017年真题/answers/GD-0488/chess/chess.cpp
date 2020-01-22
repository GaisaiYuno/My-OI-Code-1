#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int MAXN=1005,INF=1e8+5;
struct wyy
{
	int x,y,type,value;
}q2[50005];
queue<wyy>q;
int f[MAXN][MAXN][5],a[MAXN][MAXN];
int d1[4]={1,-1,0,0},d2[4]={0,0,1,-1};
int m,n,xx,yy,s,mm;
void init()
{
	cin>>m>>n;//m行m列,n为有色格子数量
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=2;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			f[i][j][0]=f[i][j][1]=f[i][j][3]=f[i][j][4]=INF;
	for(int i=1;i<=n;i++)	
	{
		cin>>xx>>yy>>s;
		a[xx][yy]=s;
	}		
}
int ok(int x,int y)
{
	if(x>=1&&x<=m&&y>=1&&y<=m)	return 1;
	return 0;
}
void spfa1()
{
	q.push((wyy){1,1,a[1][1],0});
	f[1][1][a[1][1]]=0;
	while(!q.empty())
	{
		wyy now=q.front();
		int nx=now.x,ny=now.y,ty=now.type,va=now.value;
		for(int i=0;i<4;i++)
		{
			int hx=nx+d1[i],hy=ny+d2[i];
			if(ok(hx,hy)==0)	continue;
			if(ty==0)
			{	//对目标进行分类讨论. 
				if(a[hx][hy]==0&&va<f[hx][hy][0])
				{
					f[hx][hy][0]=va;
					q.push((wyy){hx,hy,0,f[hx][hy][0]});
				}	
				if(a[hx][hy]==1&&(va+1)<f[hx][hy][1])
				{
					f[hx][hy][1]=va+1;
					q.push((wyy){hx,hy,1,f[hx][hy][1]});
				}
				if(a[hx][hy]==2&&(va+2)<f[hx][hy][3])
				{
					f[hx][hy][3]=va+2;
					q.push((wyy){hx,hy,3,f[hx][hy][3]});
				}
			}
			if(ty==1)
			{
				if(a[hx][hy]==1&&va<f[hx][hy][1])
				{
					f[hx][hy][1]=va;
					q.push((wyy){hx,hy,1,f[hx][hy][1]});
				}	
				if(a[hx][hy]==0&&(va+1)<f[hx][hy][0])
				{
					f[hx][hy][0]=va+1;
					q.push((wyy){hx,hy,0,f[hx][hy][0]});
				}
				if(a[hx][hy]==2&&(va+2)<f[hx][hy][4])
				{
					f[hx][hy][4]=va+2;
					q.push((wyy){hx,hy,4,f[hx][hy][4]});
				}
			}
			if(ty==3)
			{
				if(a[hx][hy]==0&&va<f[hx][hy][0])
				{
					f[hx][hy][0]=va;
					q.push((wyy){hx,hy,0,f[hx][hy][0]});
				}
				if(a[hx][hy]==1&&(va+1)<f[hx][hy][1])
				{
					f[hx][hy][1]=va+1;
					q.push((wyy){hx,hy,1,f[hx][hy][1]});
				}
			}
			if(ty==4)
			{
				if(a[hx][hy]==1&&va<f[hx][hy][1])
				{
					f[hx][hy][1]=va;
					q.push((wyy){hx,hy,1,f[hx][hy][1]});
				}
				if(a[hx][hy]==0&&(va+1)<f[hx][hy][0])
				{
					f[hx][hy][0]=va+1;
					q.push((wyy){hx,hy,0,f[hx][hy][0]});
				}
			}
		}
		q.pop();
	}
}
void spfa2()
{
	int head,tail;
	head=tail=0;
	q2[head]=(wyy){1,1,a[1][1],0};
	//q.push((wyy){1,1,a[1][1],0});
	f[1][1][a[1][1]]=0;
	while(head<=tail)
	{
		wyy now=q2[head];
		int nx=now.x,ny=now.y,ty=now.type,va=now.value;
		for(int i=0;i<4;i++)
		{
			int hx=nx+d1[i],hy=ny+d2[i];
			if(ok(hx,hy)==0)	continue;
			if(ty==0)
			{	
				//对目标进行分类讨论. 
				if(a[hx][hy]==0&&va<f[hx][hy][0])
				{
					f[hx][hy][0]=va;
				//	q.push((wyy){hx,hy,0,f[hx][hy][0]});
					tail=(tail+1)%(4*mm);
					q2[tail]=(wyy){hx,hy,0,f[hx][hy][0]};
					if(q2[tail].value<q2[(head+1)%(4*mm)].value)	swap(q2[tail],q2[(head+1)%(4*mm)]);
				}	
				if(a[hx][hy]==1&&(va+1)<f[hx][hy][1])
				{
					f[hx][hy][1]=va+1;
					//q.push((wyy){hx,hy,1,f[hx][hy][1]});
					tail=(tail+1)%(4*mm);
					q2[tail]=((wyy){hx,hy,1,f[hx][hy][1]});
					if(q2[tail].value<q2[(head+1)%(4*mm)].value)	swap(q2[tail],q2[(head+1)%(4*mm)]);
				}
				if(a[hx][hy]==2&&(va+2)<f[hx][hy][3])
				{
					f[hx][hy][3]=va+2;
				//	q.push((wyy){hx,hy,3,f[hx][hy][3]});
					tail=(tail+1)%(4*mm);
					q2[tail]=(wyy){hx,hy,3,f[hx][hy][3]};
					if(q2[tail].value<q2[(head+1)%(4*mm)].value)	swap(q2[tail],q2[(head+1)%(4*mm)]);
				}
			}
			if(ty==1)
			{
				if(a[hx][hy]==1&&va<f[hx][hy][1])
				{
					f[hx][hy][1]=va;
					tail=(tail+1)%(4*mm);
					q2[tail]=(wyy){hx,hy,1,f[hx][hy][1]};
					if(q2[tail].value<q2[(head+1)%(4*mm)].value)	swap(q2[tail],q2[(head+1)%(4*mm)]);
					//q.push((wyy){hx,hy,1,f[hx][hy][1]});
				}	
				if(a[hx][hy]==0&&(va+1)<f[hx][hy][0])
				{
					f[hx][hy][0]=va+1;
					tail=(tail+1)%(4*mm);
					q2[tail]=(wyy){hx,hy,0,f[hx][hy][0]};
					if(q2[tail].value<q2[(head+1)%(4*mm)].value)	swap(q2[tail],q2[(head+1)%(4*mm)]);
					//q.push((wyy){hx,hy,0,f[hx][hy][0]});
				}
				if(a[hx][hy]==2&&(va+2)<f[hx][hy][4])
				{
					f[hx][hy][4]=va+2;
					tail=(tail+1)%(4*mm);
					q2[tail]=(wyy){hx,hy,4,f[hx][hy][4]};
					if(q2[tail].value<q2[(head+1)%(4*mm)].value)	swap(q2[tail],q2[(head+1)%(4*mm)]);
					//q.push();
				}
			}
			if(ty==3)
			{
				if(a[hx][hy]==0&&va<f[hx][hy][0])
				{
					f[hx][hy][0]=va;
					tail=(tail+1)%(4*mm);
					q2[tail]=(wyy){hx,hy,0,f[hx][hy][0]};
					if(q2[tail].value<q2[(head+1)%(4*mm)].value)	swap(q2[tail],q2[(head+1)%(4*mm)]);
					//q.push((wyy){hx,hy,0,f[hx][hy][0]});
				}
				if(a[hx][hy]==1&&(va+1)<f[hx][hy][1])
				{
					f[hx][hy][1]=va+1;
					tail=(tail+1)%(4*mm);
					q2[tail]=(wyy){hx,hy,1,f[hx][hy][1]};
					if(q2[tail].value<q2[(head+1)%(4*mm)].value)	swap(q2[tail],q2[(head+1)%(4*mm)]);
					//q.push((wyy){hx,hy,1,f[hx][hy][1]});
				}
			}
			if(ty==4)
			{
				if(a[hx][hy]==1&&va<f[hx][hy][1])
				{
					f[hx][hy][1]=va;
					tail=(tail+1)%(4*mm);
					q2[tail]=(wyy){hx,hy,1,f[hx][hy][1]};
					if(q2[tail].value<q2[(head+1)%(4*mm)].value)	swap(q2[tail],q2[(head+1)%(4*mm)]);
				//	q.push((wyy){hx,hy,1,f[hx][hy][1]});
				}
				if(a[hx][hy]==0&&(va+1)<f[hx][hy][0])
				{
					f[hx][hy][0]=va+1;
					tail=(tail+1)%(4*mm);
					q2[tail]=(wyy){hx,hy,0,f[hx][hy][0]};
					if(q2[tail].value<q2[(head+1)%(4*mm)].value)	swap(q2[tail],q2[(head+1)%(4*mm)]);
				//	q.push((wyy){hx,hy,0,f[hx][hy][0]});
				}
			}
		}
		head=(head+1)%(4*mm);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	init();
	mm=m*m;
	if(m<=8000)	spfa1();
	else	spfa2();
	int ans;
	ans=min(f[m][m][0],f[m][m][1]);
	ans=min(ans,min(f[m][m][3],f[m][m][4]));
	if(ans==INF)	ans=-1;
	cout<<ans<<endl;
	return 0;
}
