#include<iostream>
#include<cstdio>
using namespace std;
char cmd[10],ans[10];
int query(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout); 
	scanf("%s",ans+1);
	if(ans[1]=='x') return 1;
	else return 0;
}
int work(){
	int l=1<<29,r=(1<<30)+1;
	if(query(0,1)==1) return 1; 
	for(int i=1;i<=29;i++){
		if(query(1<<(i-1),1<<i)==1){
			l=1<<(i-1);
			r=(1<<i)+1;
			break;
		}
	}
	while(l<r){
		int mid=(l+r)>>1;
		if(query(r,mid)==0) l=mid+1;
		else r=mid;
	}
	return r;
}

int main(){
	while(scanf("%s",cmd+1)!=EOF){
		if(cmd[1]=='s'){
			printf("! %d\n",work());
			fflush(stdout);
		}else break;
	}
}

