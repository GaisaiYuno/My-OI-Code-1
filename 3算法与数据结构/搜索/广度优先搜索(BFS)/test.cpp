//书 p302 例8.4
#include<iostream>
#define max 21
using namespace std;
int  mg[max][max];
//int p[401],q[401],last[401];
int m,n;
int x,y,x1,y1,x2,y2;
int xx[4]= {1,0,-1,0},yy[4]= {0,1,0,-1};
int head,tail;
struct dot{
	int x;
	int y;
	int last;
}dot[max*max];
void output(int l){
	if(dot[l].last!=-1) output(dot[l].last);//递归输出
	cout<<dot[l].x<<','<<dot[l].y<<endl;
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
	dot[0].x=x1;
	dot[0].y=y1;
	dot[0].last=-1;
	do {//此为模板 
		for(int a=0; a<4; a++) {
			 x=dot[head].x+xx[a];
			 y=dot[head].y+yy[a];
			if(x>0&&x<=m&&y>0&&y<=n&&mg[x][y]==0) {
				if(mg[x][y]==0) {
					tail++;//进队
					dot[tail].x=x;
					dot[tail].y=y;
					dot[tail].last=head;//存上一个x,y 在数组中的位置 
					mg[x][y]=-1;
				}
				if(x==x2&&y==y2) {
					//cout<<x1<<','<<y1<<endl; 
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
