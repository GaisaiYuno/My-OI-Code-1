//openjudge 6044:鸣人和佐助 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[201][201],n,m,i,j,t;
int p[40001],q[40001],step[40001],k[40001],head,tail,mp[201][201];
int x1,x2,y1,y2;
int xx[4]= {1,0,-1,0},yy[4]= {0,1,0,-1};
int main() {
//	scanf("%d%d%d\n",&n,&m,&t);
	cin>>n;
	cin>>m;
	cin>>t;
	for (i=1; i<=n; i++) {
		char c[201];
		// gets(c);
		cin>>c;
		for (j=1; j<=m; j++) {
			if (c[j-1]=='#')  f[i][j]=1;
			if (c[j-1]=='*')  f[i][j]=0;
			if (c[j-1]=='@') {
				f[i][j]=0;
				x1=i;
				y1=j;
			}
			if (c[j-1]=='+') {
				f[i][j]=0;
				x2=i;
				y2=j;
			}
		}
	}
	head=0;
	tail=1;
	p[1]=x1;
	q[1]=y1;
	step[1]=0;
	k[1]=t;
	memset(mp,-1,sizeof(mp));
	mp[x1][y1]=t;
//	int ans=100000000;
	while (head<tail) {
		head++;
		for (i=0; i<4; i++) {
			int xl=p[head]+xx[i],yl=q[head]+yy[i];
			if (xl>0&&xl<=n&&yl>0&&yl<=m&&(mp[xl][yl]==-1||mp[xl][yl]<=k[head]-1)) {

				if (f[xl][yl]==0) {
					tail++;
					p[tail]=xl;
					q[tail]=yl;
					step[tail]=step[head]+1;
					k[tail]=k[head];
					mp[xl][yl]=k[head];
				} else if (k[head]>0) {
					tail++;
					p[tail]=xl;
					q[tail]=yl;
					step[tail]=step[head]+1;
					k[tail]=k[head]-1;
					mp[xl][yl]=k[head]-1;
				}
				if (mp[x2][y2]!=-1) {

					cout<<step[tail];
					return 0;
				}
			}


		}
	}

	cout<<"-1";
	return 0;
} //此题用广搜即可，需要特别注意的是每一个点不是经过了就不能经过，有可能两条路的时间一样，但是查克拉数不同，直接影响下面的走法
