
#include<stdio.h>
#include<cstring>
using namespace std;
int x,y,z,f,l,r,u;
void Move(int dir,int d) {
	if(dir==0) {
		x+=d;
	} else if(dir==1) {
		y+=d;
	} else if(dir==2) {
		z+=d;
	} else if(dir==3) {
		x-=d;
	} else if(dir==4) {
		y-=d;
	} else {
		z-=d;
	}
}
int main() {
	int t,n,d,tmp;
	char op[11];
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		f=x=y=z=0;
		l=4,u=2;
		for(int i=1; i<=n; i++) {
			scanf("%s %d",op,&d);
			switch(op[0]) {
				case 'l':	tmp=f,f=l,l=(tmp+3)%6;break;
				case 'r':	tmp=f,f=(l+3)%6,l=tmp;break;
				case 'u':	tmp=f,f=u,u=(tmp+3)%6;break;
				case 'd':	tmp=f,f=(u+3)%6,u=tmp;break;
				case 'b':	f=(f+3)%6,l=(l+3)%6;break;
				default:	break;
			}
			Move(f,d);
		}
		printf("%d %d %d %d\n",x,y,z,f);
	}
	return 0;
}

