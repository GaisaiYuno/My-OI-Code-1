//Êép312 Ìâ10 
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int used[301][301];
	int p[90601],q[90601];
	int x,y;
	int x1,y1,x2,y2;
	int n;
	cin>>n;
	cin>>x1>>y1>>x2>>y2;
	int step[90601];
	int head,tail;
	int a[8]={-1,1,2,2,1,-1,-2,-2},b[8]={-2,-2,-1,1,2,2,1,-1};
	head=0;
	tail=0;
	memset(used,-1,sizeof(used));
	used[x1][y1]=1;
	p[0]=x1;
	q[0]=y1;
	step[0]=0;
	do{
		for(int i=0;i<8;i++){
			x=p[head]+a[i];
			y=q[head]+b[i];
			if(x>=0&&x<n&&y>=0&&y<n&&used[x][y]==-1){
				tail++;
				p[tail]=x;
				q[tail]=y;
				step[tail]=step[head]+1;
				used[x][y]=1;
				if(used[x2][y2]==1){
					cout<<step[tail];
					return 0;
				}
			}
		}
		head++;
	}while(head<=tail);
	if(x1==x2&&y1==y2)cout<<"0";
	return 0;	
}


