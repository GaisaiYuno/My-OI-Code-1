#include<iostream>
#include<cstdio>
#define maxn 25
#define size 128
using namespace std;
struct node{
	int x;
	int y;
	int k;
}a[maxn];
int d,n;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign; 
}
inline int abs(int x){
	return x>=0?x:-x;
}
int main(){
	//freopen("wireless1.in","r",stdin);
	//freopen("wireless.out","w",stdout);
	long long sum=0;
	long long ans=0;
	int ans_cnt;
	cin>>d>>n;
	//printf("%d %d\n",d,n);
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].k;
	}
//	printf("%d %d\n",d,n);
	for(int i=0;i<=size;i++){
		for(int j=0;j<=size;j++){
			sum=0;
			for(int u=1;u<=n;u++){
				if(abs(a[u].x-i)<=d&&abs(a[u].y-j)<=d) sum+=a[u].k;
			}
			if(sum>ans){
				ans=sum;
				ans_cnt=1;
			}else if(sum==ans){
				ans_cnt++;
			}
		}
	}
	printf("%d %lld\n",ans_cnt,ans);
	return 0;
} 
/*
1
2
4 4 10
6 6 20
*/
