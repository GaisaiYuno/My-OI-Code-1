#include<iostream>
#include<cstdio>
#include<algorithm> 
#define maxn 1005
using namespace std;
int n,k,sum;
int a[maxn];
int is_good[maxn];
struct judge{
	int cnt;
	int id;
}b[maxn];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	int m=0,ptr=0;;
	for(int i=0;i<=sum;i++){
//		if(i==49){
//			i=49;
//		}
		for(int j=1;j<=k;j++){
			if(b[j].cnt==1) m++;
			if(b[j].cnt) b[j].cnt--;
			if(b[j].cnt==0&&ptr+1<=n){
				ptr++;
				b[j].id=ptr;
				b[j].cnt=a[ptr];
			}
		}
		double rate=100.0*m/n;
		int cnt=round(rate);
		for(int j=1;j<=k;j++){
			if(b[j].cnt&&a[b[j].id]-b[j].cnt+1==cnt){
				is_good[b[j].id]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(is_good[i]) ans++;
	}
	printf("%d\n",ans);
}

