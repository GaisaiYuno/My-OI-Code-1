//书311 题9
//openjudge 7218 
#include<iostream>
#include<cstring>
using namespace std;
char mg[201][201];
int m,n;
int f[201][201];
int p[40001],q[40001];
int step[40001];
int ans[11];
int main() {
	int head,tail;
	int x1,y1,x2,y2;
	int xx[4]= {1,0,-1,0},yy[4]= {0,1,0,-1};
	int t;
	cin>>t;
for(int b=0;b<t;b++){ 
	cin>>m;
	cin>>n;
	for(int i=0; i<m; i++) {
		cin>>mg[i];
	}
	for(int j=0; j<m; j++) {
		for(int k=0; k<n; k++) {
			if(mg[j][k]=='#') f[j][k]=1;
			if(mg[j][k]=='.') f[j][k]=0;
			if(mg[j][k]=='S') {
				f[j][k]=0;
				x1=j;
				y1=k;
			}
			if(mg[j][k]=='E') {
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
	int used[201][201];
	int x,y; 
	memset(used,-1,sizeof(used));//存是否走过
	used[x1][y1]=1;
		ans[b]=-1;
	do {
			if(used[x2][y2]==1) {
				ans[b]=step[tail];					
			  	break;					
				}
		for(int a=0; a<4; a++) {
			 x=p[head]+xx[a];
			 y=q[head]+yy[a];
			if(x>=0&&x<m&&y>=0&&y<n&&used[x][y]==-1) {
				if(f[x][y]==0) {
					tail++;//进队
					p[tail]=x;
					q[tail]=y;
					step[tail]=step[head]+1;
					used[x][y]=1;
				}
			}
		}
		head++;//出队
	} while(head<=tail);
	//cout<<"NO";
//	ans[b]=-1;

	} 
	for(int b=0;b<t;b++){
		if(ans[b]==-1) cout<<"oop!"<<endl;
		else cout<<ans[b]<<endl;
	}
	return 0;
}
