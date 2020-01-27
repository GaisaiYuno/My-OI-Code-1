#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define maxn 300005
using namespace std;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
/*
	两眼一闭，N^3暴力
	暴力膜蛤不可取！ 
	    **       ***       ****  
	    **        **      ** 
	**********    **       ****
	    **        **     .    ** 
	    **      ******    *****
*/ 
int N,M,type; 
int arr[maxn];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read(N);read(M);read(type);
	int last;
	for(int i=1;i<=N;i++){
		read(arr[i]);
	}
	int l,r,u,v;
	while(M--){
		int ans=0;
		read(l);read(r);
		if(type){
			u=(l+last-1)%(N+1);
			v=(r+last-1)%(N+1);
			l=min(u,v);
			r=max(u,v);
		}
		for(int i=l;i<r;i++){
			for(int j=i+1;j<=r;j++){
				if(i==j-1)
					ans++;
				else{
					bool flag=1;
					int m=min(arr[i],arr[j]);
					for(int k=i+1;k<j;k++)
						if(arr[k]>=m){
							flag=0;break;
						}
					if(flag){
						ans++;
					}
				}	
			}
		}
		printf("%d\n",ans);	
	}
}
