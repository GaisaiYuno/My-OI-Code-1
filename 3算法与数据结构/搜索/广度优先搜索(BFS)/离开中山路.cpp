//洛谷  离开中山路 1746
#include<iostream>
#include<cstdio>
using namespace std;
int n,x1,y1,x2,y2;
int map[1000][1000];
int p[1000000],q[1000000],step[1000000];
int xx[4]={1,-1,0,0},yy[4]={0,0,1,-1}; 
int main(){
	cin>>n;
	int head,tail,x,y; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		  scanf("%1d",&map[i][j]);
	}
	cin>>x1>>y1>>x2>>y2;
    head=0;
    tail=0;
    p[0]=x1;
    q[0]=y1;
    map[x1][y1]=1;
    do{
    	for(int i=0;i<4;i++){
    		x=p[head]+xx[i];
    		y=q[head]+yy[i];
    		if(x<=n&&y<=n&&x>0&&y>0&&map[x][y]==0){
    			tail++;
    			p[tail]=x;
    			q[tail]=y;
    			step[tail]=step[head]+1;
    			map[x][y]=1;
    			if(map[x2][y2]==1){
    				cout<<step[tail];
    				return 0;
				}
			}
		}
		head++;
	}while(head<=tail);
	cout<<"no";
	return 0; 
} 
