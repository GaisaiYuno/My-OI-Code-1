//洛谷 路障
#include<iostream>
#include<cstring>
#define maxn 1005
using namespace std;
int f[maxn][maxn];
int p[maxn*maxn],q[maxn*maxn];
int bx[maxn*maxn],by[maxn*maxn];
int xx[4]= {1,0,-1,0},yy[4]= {0,1,0,-1};
int t,n,flag;
void  bfs()
{
		int head=0;
		int tail=0;
		int time=0;
		flag=0;
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		p[0]=1;
		q[0]=1;
		int x=1,y=1;
		f[1][1]=1;
		do {
			for(int a=0; a<4; a++) {
				f[bx[time]][by[time]]=1;
				//if(bx[time]==n&&by[time]==n)   return;
				x=p[head]+xx[a];
				y=q[head]+yy[a];
				if(x>0&&x<=n&&y>0&&y<=n&&f[x][y]==0) {
					tail++;//进队
					p[tail]=x;
					q[tail]=y;
					f[x][y]=1;
					if(/*f[n][n]==1*/x==n&&y==n) {
						flag=1;
						return;
					}
				}
			}
			time++;
		
			head++;//出队
		} while(head<=tail);
		return;
}


int main() {
	cin>>t;
	for(int u=0; u<t; u++) {

		cin>>n;
	
		for(int i=1; i<=2*n-2; i++)
			cin>>bx[i]>>by[i];
		bfs();

        if(flag||n==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
	}
	return 0;
}

