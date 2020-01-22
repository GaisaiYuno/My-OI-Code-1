#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
#define ll long long
#define in(a) scanf("%d",&a)
#define out(a) printf("%d\n",a)
#define FOR(a,b,c) for(int a=b;a<=c;a++)
int bfs1[5001000],bfs2[5001000],bfs3[5001000],bfs4[5001000];
int f[1010][1010];
int a[1010][1010];
int q1[1010][1010],q2[1010][1010];
int fx[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n,m;
	in(n);in(m);
	FOR(i,1,m){
		int x,y;
		in(x);in(y);in(a[x][y]);a[x][y]++;
	}
	int l=1,r=2;
	memset(f,127,sizeof(f));
	int q=0;
	f[1][1]=0;
	bfs1[l]=1,bfs2[l]=1;bfs4[l]=a[1][1];
	while(l<r){
		int x=bfs1[l],y=bfs2[l];
		FOR(k,0,3){
			int c1=x+fx[k][0],c2=y+fx[k][1];
			if(c1>n||c1<0||c2>n||c2<0)continue;
			if(!bfs3[l]){
				if(a[c1][c2]){
					if(a[c1][c2]==bfs4[l]){
						if(f[c1][c2]>f[x][y]){
							f[c1][c2]=f[x][y];
							bfs1[r]=c1;
							bfs2[r]=c2;
							bfs3[r]=0;
							bfs4[r]=a[c1][c2];
							if(c1==n&&c2==n)q=1;
							r++;r=(r-1)%5000000+1;
						}
					}
					 else {
					 	if(f[c1][c2]>f[x][y]+1){
					 		f[c1][c2]=f[x][y]+1;
					 		bfs1[r]=c1;
					 		bfs2[r]=c2;
					 		bfs3[r]=0;
					 		bfs4[r]=a[c1][c2];
							if(c1==n&&c2==n)q=1;
					 		r++;r=(r-1)%5000000+1;
					 	}
					 		
					 }
				}
				 else {
				 	if(f[c1][c2]>f[x][y]+2){
				 		if(c1==n&&c2==n)q=1;
				 		f[c1][c2]=f[x][y]+2;
					 	q1[c1][c2]=x,q2[c1][c2]=y;
				 		bfs1[r]=c1;
				 		bfs2[r]=c2;
				 		bfs3[r]=1;
				 		bfs4[r]=0;
				 		r++;r=(r-1)%5000000+1;
				 	}
				 }
			}
			 else {
			 	if(a[c1][c2]){
			 		if(f[c1][c2]>f[x][y]+(a[q1[x][y]][q2[x][y]]!=a[c1][c2])){
			 			f[c1][c2]=f[x][y]+(a[q1[x][y]][q2[x][y]]!=a[c1][c2]);
			 			bfs1[r]=c1;
			 			bfs2[r]=c2;
			 			bfs3[r]=0;
			 			bfs4[r]=a[c1][c2];
						if(c1==n&&c2==n)q=1;
			 			r++;r=(r-1)%5000000+1;
			 		}
			 	}
			 }
		}
		l++;
		l=(l-1)%5000000+1;
	}
	q?out(f[n][n]):out(-1);
	fclose(stdin);fclose(stdout);
	return 0;
}
