//书 p302 例8.4
#include<iostream>
using namespace std;
int  mg[21][21];
int p[401],q[401],last[401];
int m,n;
int x,y,x1,y1,x2,y2;
int xx[4]= {1,0,-1,0},yy[4]= {0,1,0,-1};
int head,tail;
void output(int l){
	//cout<<last[l]<<" ";
	if(last[l]!=-1) output(last[l]);//递归输出
	//cout<<last[l]<<" ";
	cout<<p[l]<<','<<q[l]<<endl;
	return;
} 
int main(){
	cin>>m;
	cin>>n;
	for(int i=1; i<=n; i++) {
		for(int j=1;j<=m;j++)
		 cin>>mg[i][j];
	}
	cin>>x1>>y1>>x2>>y2;
	head=0;
	tail=0;
	p[0]=x1;
	q[0]=y1;
	last[0]=-1;
	do {//此为模板 
		for(int a=0; a<4; a++) {
			 x=p[head]+xx[a];
			 y=q[head]+yy[a];
			if(x>0&&x<=m&&y>0&&y<=n&&mg[x][y]==0) {
				if(mg[x][y]==0) {
					tail++;//进队
					p[tail]=x;
					q[tail]=y;
					last[tail]=head;//存上一个x,y 在数组中的位置 
					mg[x][y]=-1;
				}
				if(x==x2&&y==y2) {
					output(tail);
					return 0;
				}
			}
		}
		head++;//出队
	} while(head<=tail);
	cout<<"no way."<<endl;
	return 0;
} 
