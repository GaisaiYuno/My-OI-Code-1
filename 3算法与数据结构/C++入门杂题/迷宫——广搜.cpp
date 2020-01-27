#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char mg[21][21];
	int m,n;
	int f[21][21];
	int p[401],q[401];
	int step[401];
	int head,tail;
	int x1,y1,x2,y2;
	int xx[4]= {1,0,-1,0},yy[4]= {0,1,0,-1};
	cin>>m;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>mg[i];
	}
	for(int j=0; j<m; j++) {
		for(int k=0; k<n; k++) {
			if(mg[j][k]=='#') f[j][k]=1;
			if(mg[j][k]=='.') f[j][k]=0;
			if(mg[j][k]=='s') {
				f[j][k]=0;
				x1=j;
				y1=k;
			}
			if(mg[j][k]=='e') {
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
	int used[21][21];
	int x,y; 
	memset(used,-1,sizeof(used));//���Ƿ��߹�
	used[x1][y1]=1;
	do {
		for(int a=0; a<4; a++) {
			 x=p[head]+xx[a];
			 y=q[head]+yy[a];
			if(x>=0&&x<m&&y>=0&&y<n&&used[x][y]==-1) {
				if(f[x][y]==0) {
					tail++;//����
					p[tail]=x;
					q[tail]=y;
					//cout<<x<<' '<<y<<' ';
					step[tail]=step[head]+1;
					used[x][y]=1;
				}
				if(used[x2][y2]==1) {
					cout<<step[tail];
				return 0;
				}
			}
		}
		head++;//����
	} while(head<=tail);
	cout<<"NO";
	return 0;
}
