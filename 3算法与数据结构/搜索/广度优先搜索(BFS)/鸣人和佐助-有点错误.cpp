#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[201][201],n,m,i,j,t;
int p[40001],q[40001],step[40001],k[40001],head,tail,used[201][201];
int x1,x2,y1,y2;
int xx[4]= {1,0,-1,0},yy[4]= {0,1,0,-1};
int main() {
	char mg[201][201];
	cin>>n;
	cin>>m;
	cin>>t;

	for(int i=0; i<m; i++) {
		cin>>mg[i];
	}
	for(int j=0; j<n; j++) {
		for(int k=0; k<m; k++) {
			if(mg[j][k]=='#') f[j][k]=1;
			if(mg[j][k]=='*') f[j][k]=0;
			if (mg[j][k]=='@') {
				f[j][k]=0;
				x1=j;
				y1=k;
			}
			if (mg[j][k]=='+') {
				f[j][k]=0;
				x2=j;
				y2=k;
			}
		}
	}


	head=0;
	tail=0;
	p[0]=x1;
	q[0]=y1;
	step[0]=0;
	k[0]=t;
	memset(used,-1,sizeof(used));
	used[x1][y1]=t;

	do {

		for (int i=0; i<4; i++) {
			int x=p[head]+xx[i],y=q[head]+yy[i];
			if (x>=0&&x<n&&y>=0&&y<m&&(used[x][y]==-1||used[x][y]<k[head]-1)) {

				if (f[x][y]==0) {
					tail++;
					p[tail]=x;
					q[tail]=y;
					step[tail]=step[head]+1;
					k[tail]=k[head];
					used[x][y]=k[head];
				} else if (k[head]>0) {
					tail++;
					p[tail]=x;
					q[tail]=y;
					step[tail]=step[head]+1;
					k[tail]=k[head]-1;
					used[x][y]=k[head]-1;
				}
				if (used[x2][y2]!=-1) {

					cout<<step[tail];
					return 0;
				}
			}


		}
		head++;
	}	while (head<=tail);

	cout<<"-1";
	return 0;
}
