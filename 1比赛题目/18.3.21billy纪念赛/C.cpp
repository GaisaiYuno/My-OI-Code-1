#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,n;
int x,y,z,p;
char cmd[20];
int getop(int dir){
	return (dir+3)%6; 
}
void move(int dir,int d){
	if(dir==0){
		x+=d;
	}
	if(dir==1){
		y+=d;
	}
	if(dir==2){
		z+=d;
	}
	if(dir==3){
		x-=d;
	}
	if(dir==4){
		y-=d;
	}
	if(dir==5){
		z-=d;
	}
}
int main(){
	int d=0;
	int forward=0,left=4,up=2;
	cin>>m;
	while(m--){
		cin>>n;
		x=y=z=forward=0;
		left=4;
		up=2;
		int tmp;
		for(int i=1;i<=n;i++){
			cin>>cmd>>d;
			if(cmd[0]=='f'){
				;
			}
			if(cmd[0]=='b'){
				forward=getop(forward);
				left=getop(left); 
			}
			if(cmd[0]=='l'){
				tmp=forward;
				forward=left;
				left=getop(tmp);
			}
			if(cmd[0]=='r'){
				tmp=forward;
				forward=getop(left);
				left=tmp;
			}
			if(cmd[0]=='u'){
				tmp=forward;
				forward=up;
				up=getop(tmp); 
			}
			if(cmd[0]=='d'){
				tmp=forward;
				forward=getop(up);
				up=tmp;
			}
			move(forward,d);
		}
		printf("%d %d %d %d\n",x,y,z,forward);
	}
	return 0;
}

