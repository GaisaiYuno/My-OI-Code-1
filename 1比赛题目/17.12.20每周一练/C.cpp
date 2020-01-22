#include<iostream>
#include<cstdio>
#include<cstring>
#define size 55
using namespace std;
int a,b,c,k,maxt;
int head=0,tail=0;
int map[size][size][size];
int used[size][size][size];
const int walkx[6]= {1,-1,0,0,0,0};
const int walky[6]= {0,0,1,-1,0,0};
const int walkz[6]= {0,0,0,0,1,-1};
struct node {
	int x;
	int y;
	int z;
	int t;
};
node queue[size*size*size];
bool judge(int x,int y,int z,int t) {
	if(x<0||y<0||z<0||x>=a||y>=b||z>=c) return false;
	if(used[x][y][z]==1) return false;
	if(map[x][y][z]==1) return false;
	if(t>maxt) return false; 
	return true;
}
int bfs() {
	memset(used,0,sizeof(used));
	head=tail=0;
	node now,nex;
	queue[0].x=0;
	queue[0].y=0;
	queue[0].z=0;
	queue[0].t=0;
	used[0][0][0]=1;
	do {
		now=queue[head];
		if(now.x==a-1&&now.y==b-1&&now.z==c-1){//注意，终点可能为障碍物，而起点可以为障碍物 
		    if(now.t<=maxt) return now.t;
		    else return -1;
		} 
		for(int i=0; i<6; i++){
			nex.x=now.x+walkx[i];
			nex.y=now.y+walky[i];
			nex.z=now.z+walkz[i];
			nex.t=now.t;
			if(judge(nex.x,nex.y,nex.z,nex.t)) {
				used[nex.x][nex.y][nex.z]=1;
				tail++;
				queue[tail].x=nex.x;
				queue[tail].y=nex.y;
				queue[tail].z=nex.z;
				queue[tail].t=nex.t+1;
			}
		}
		head++;
	} while(head<=tail);
	return -1;
}
int main() {
	cin>>k;
	while(k--) {
		cin>>a>>b>>c>>maxt;
		for(int i=0; i<a; i++) {
			for(int j=0; j<b; j++) {
				for(int k=0; k<c; k++) {
					scanf("%d",&map[i][j][k]);
				}
			}
		}
		cout<<bfs()<<endl;
	}
}
