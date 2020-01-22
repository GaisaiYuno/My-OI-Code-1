#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=19260817;
int n;
int map[10][10];
int used[19260817+5];
struct data{
	int a[10];
	data(){
		memset(a,0,sizeof(a));
	}
	void print(){
		for(int i=0;i<7;i++) printf("%d ",a[i]);
		printf("\n");
	}
	unsigned long long hash(){
		unsigned long long x=0;
		for(int i=0;i<7;i++){
			x=x*mod+a[i];
		}
		return x%mod;
	}
};
bool flag=false;
int is_empty(data x) {
	for(int i=0; i<7; i++) {
		if(x.a[i]!=0) return 0;
	}
	return 1;
}
data dis(data in){
	data x=in;
	int move_cnt=1;
	while(move_cnt!=0){
		move_cnt=0;
		int cnt=1;
		for(int i=1;i<7;i++){
			if(x.a[i]==x.a[i-1]&&x.a[i-1]!=0) cnt++;
			else cnt=1;
			if(cnt>=3&&x.a[i]!=x.a[i+1]){
				for(int k=0;k<=i;k++) x.a[k]=0;
				move_cnt++;
			}
		}
	}
	return x;
}
data move(data in,int i,int dir){
	data x=in;
	int j=i+dir;
	if(x.a[j]!=0){
		swap(x.a[i],x.a[j]);
	}else{
		x.a[j]=x.a[i];
		x.a[i]=0;
	}
	return dis(x);
}
void dfs(int d,data x){
	used[x.hash()]=1;
	if(used[0]==1){
		used[0]=1;
		x.hash();
	}
	x.print();
	if(d>5) return;
	if(is_empty(x)){
//		print();
		flag=true;
		return;
	}
	for(int i=0;i<7;i++){
		if(i==2&&d==0){
			i=2;
		}
		if(x.a[i]==0) continue;
		data t1=move(x,i,1);
		if(i!=7&&used[t1.hash()]==0) dfs(d+1,t1);
		if(flag) return;
		data t2=move(x,i,-1);
		if(i!=1&&used[t2.hash()]==0)dfs(d+1,t2);
		if(flag) return;
	}
}
int main(){
	freopen("mayan.in","r",stdin);
	freopen("mayan.out","w",stdout);
	scanf("%d",&n);
	int cnt=0;
	for(int i=0; i<7; i++) {
		for(int j=0; j<5; j++) {
			scanf("%d",&map[i][j]);
			if(map[i][j]==0){
				if(j<=1) cnt++;
				break;
			}
		}
	}
	data x;
	if(cnt==7){
		for(int i=0;i<7;i++){
			x.a[i]=map[i][0];	
		}
//		dfs(0,x);
//		if(flag) printf("yes\n");
		printf("-1\n");
	}else{
		printf("-1\n");
	}
}
