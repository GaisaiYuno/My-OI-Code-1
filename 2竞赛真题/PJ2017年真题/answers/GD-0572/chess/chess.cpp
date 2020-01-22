#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fin(x) freopen(x,"r",stdin)
#define fou(x) freopen(x,"w",stdout)
using namespace std;

inline int rd()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*f;
}

const int ch1[4]={0,1,0,-1};
const int ch2[4]={1,0,-1,0};

struct node{
	int x,y,t;
	node(){}
	node(int x,int y,int t):x(x),y(y),t(t){}
};

int m,n,mp[110][110],d[110][110],cha[110][110];
bool f[110][110];

bool check(node a){return (a.x<1||a.y<1||a.x>m||a.y>m)?0:1;}

void spfa()
{
	queue<node>q;
	memset(d,0x7f,sizeof d);
	f[1][1]=1;d[1][1]=0;
	q.push(node(1,1,0));
	while(!q.empty()){
		node u=q.front(),v;q.pop();
		fo(i,0,3){
			v.x=u.x+ch1[i];
			v.y=u.y+ch2[i];
			v.t=0;
			if(!check(v))continue;
			if(u.t==1&&mp[v.x][v.y]==-1)continue;
			if(mp[v.x][v.y]==-1){
				v.t=1;
				if(d[u.x][u.y]+2<d[v.x][v.y]){
					d[v.x][v.y]=d[u.x][u.y]+2;
					cha[v.x][v.y]=mp[u.x][u.y];
					if(!f[v.x][v.y]){
						f[v.x][v.y]=1;
						q.push(v);
					}
				}
			}
			else if(cha[v.x][v.y]==cha[u.x][u.y]){
				if(d[u.x][u.y]<d[v.x][v.y]){
					d[v.x][v.y]=d[u.x][u.y];
					if(!f[v.x][v.y]){
						f[v.x][v.y]=1;
						q.push(v);
					}
				}
			}
			else{
				if(d[u.x][u.y]+1<d[v.x][v.y]){
					d[v.x][v.y]=d[u.x][u.y]+1;
					if(!f[v.x][v.y]){
						f[v.x][v.y]=1;
						q.push(v);
					}
				}
			}
		}
		f[u.x][u.y]=0;
		cha[u.x][u.y]=mp[u.x][u.y];
	}
}

int main()
{
	fin("chess.in");fou("chess.out");
	memset(mp,-1,sizeof mp);
	memset(cha,-1,sizeof cha);
	m=rd();n=rd();
	fo(i,1,n){
		int x=rd(),y=rd();
		cha[x][y]=mp[x][y]=rd();
	}
	spfa();
	if(d[m][m]==2139062143)puts("-1");
	else printf("%d\n",d[m][m]);
}
