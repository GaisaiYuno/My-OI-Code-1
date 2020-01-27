#include<iostream>
#include<cstdio>
using namespace std;
int g,p,b;
int x,y,z;
bool judge(){
	if(x<=g){
		g-=x;
		if(y<=g+p){
			if(g+p+b-y>=z) return 1;
			else return 0;
		}else return 0;
	}else return 0;
}
int main(){
	scanf("%d %d %d %d %d %d",&x,&y,&z,&g,&p,&b);
	if(judge()) printf("YES\n");
	else printf("NO\n");
}

