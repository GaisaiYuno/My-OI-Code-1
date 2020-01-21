#include<iostream>
using namespace std;
#define MAX 100
int a[MAX][MAX],m,n,k,sum,w[4]= {1,-1,0,0},u[4]= {0,0,-1,1},s;
void find(int p,int q) {
	int x,y,h[MAX*MAX+1][2],t=0,z=1,i;
	h[1][0]=p;
	h[1][1]=q;
	do {
		t++;
		for(i=0; i<4; i++) {
			x=h[t][0]+w[i];
			y=h[t][1]+u[i];
			if(x>=1&&x<m*2+1 && y>=1&&y<n*2+1 &&a[x][y]!=-1&&x+w[i]>=1  &&x+w[i]<m*2+1&&y+u[i]>=1&&y+u[i]<n*2+1&&a[x+w[i]][y+u[i]]!=-1) {
				z++;
				h[z][0]=x+w[i];
				h[z][1]=y+u[i];
				a[h[z][0]][h[z][1]]=-1;
				s++;
			}
		}
	} while(t<z);
	sum++;
	return;
}
int main() {
	int i,j,p;
	for(i=0; i<MAX; i+=2)
		for(j=0; j<MAX; j+=2)
			a[i][j]=-1;


	cin>>m>>n;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++) {

			cin>>p;
			if(p>=8) {
				a[i*2+1+1][j*2+1]=-1;
				p-=8;
			}
			if(p>=4) {
				a[i*2+1][j*2+1+1]=-1;
				p-=4;
			}
			if(p>=2) {
				a[i*2+1-1][j*2+1]=-1;
				p-=2;
			}
			if(p>=1) {
				a[i*2+1][j*2+1-1]=-1;
				p-=1;
			}
		}
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			if(a[i*2+1][j*2+1]!=-1) {
				find(i*2+1,j*2+1);
				if(s>k)
					k=s;
				s=0;
			}

	cout<<sum<<endl;
	cout<<k<<endl;
}
