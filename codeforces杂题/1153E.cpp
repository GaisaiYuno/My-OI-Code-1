#include<iostream>
#include<cstdio>
#define maxn 1005
using namespace std;
int n;
int ask(int x1,int y1,int x2,int y2){
	int ans;
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	scanf("%d",&ans);
	if(ans==-1) exit(0);
	return ans;
}
void answer(int x1,int y1,int x2,int y2){
	printf("! %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
}

int find(int xx,int l,int r){
	int ans=0,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(ask(xx,1,xx,mid)%2){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}

int ansx[maxn]; 
int ansy[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ansx[i]=ask(i,1,i,n);
	}
	int cntodd=0;
	int hdx,tlx;
	int hdy,tly;
	for(int i=1;i<=n;i++){
		if(ansx[i]%2){
			cntodd++;
			if(cntodd==1) hdx=i;
			else tlx=i;
		}
	}
	if(cntodd==2){
		hdy=find(hdx,1,n);
		tly=find(tlx,1,n);
	}else{
		for(int i=1;i<=n;i++){
			ansy[i]=ask(1,i,n,i);
			
		} 
		tly=find(tlx,hdy+1,n);
	}
	answer(hdx,hdy,tlx,tly);
}

