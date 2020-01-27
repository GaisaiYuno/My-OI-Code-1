#include<iostream>
#include<cstdio>
using namespace std;
int x,y,z;
int flag;
int main(){
	scanf("%d %d %d",&x,&y,&z); 
	int a,b;
	for(int i=0;i<=z;i++){
		a=x+i;
		b=y+z-i;
		if(a>b) flag|=1;
		else if(a<b) flag|=2;
		else flag|=4;
	}
	if(flag==1) printf("+");
	else if(flag==2) printf("-");
	else if(flag==4) printf("0");
	else printf("?");
}

