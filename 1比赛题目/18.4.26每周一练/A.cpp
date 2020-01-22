#include<iostream>
#include<cstdio>
using namespace std;
int x1,x2,y1,y2;
int x3,y3,x4,y4;
inline int abs(int x){
	return x>0?x:-x;
} 
int main(){
	while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2)!=EOF){
		int d=0; 
		if(x1==x2&&y1!=y2){
			d=abs(y1-y2);
			x3=x1+d;
			y3=y1;
			x4=x2+d;
			y4=y2;
		}else if(x1!=x2&&y1==y2){
			d=abs(x1-x2);
			x3=x1;
			y3=y1+d;
			x4=x2;
			y4=y2+d;
		}else if(x1!=x2&&y1!=y2){
			if(abs(x1-x2)!=abs(y1-y2)){
				 printf("-1\n");
				 continue;
			}
			x3=x1;
			y3=y2;
			x4=x2;
			y4=y1;
		}
		if(x3>1000||x3<-1000||y3>1000||y3<-1000||x4>1000||x4<-1000||y4>1000||y4<-1000) printf("-1\n");
		else printf("%d %d %d %d\n",x3,y3,x4,y4);
	}
} 
