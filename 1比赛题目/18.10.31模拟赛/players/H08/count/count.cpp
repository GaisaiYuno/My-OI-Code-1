#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define maxn 300005
void read(int &x){
	x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}
void read(long long &x){
	x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}
int n,m,t;
int a[maxn];
int st[maxn][25];
void pre_st(){
	for(int i=1;i<=n;i++)st[i][0]=a[i];
	for(int j=1;j<=20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int ask(int l,int r){
	int t=log(r-l+1)/log(2);
	return min(st[l][t],st[r-(1<<t)+1][t]);
}
int main(){
	freopen("count1.in","r",stdin);
	read(n);read(m);read(t);
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++){
		read(a[i]);
	}	
	pre_st();
	int x,y;
	int t1,t2;
	int ans=0;
	if(!t){
       for(int i=1;i<=m;i++){
       	   scanf("%d%d",&x,&y);
       	   ans=0;
       	   for(int j=x;j<=y;j++){
       	       for(int k=j+1;k<=y;k++){
       	       	   if(k==j+1)ans++;
       	       	   else{
       	       	   	if(ask(j+1,k-1)<min(a[j],a[k]))ans++;
				    }
				}  	
			}
			printf("%d\n",ans);
	   }
	}
	else{
       for(int i=1;i<=m;i++){
       	   scanf("%d%d",&x,&y);
       	   t1=(x+ans-1)%(n+1);
       	   t2=(y+ans-1)%(n+1);
       	   x=min(t1,t2);y=max(t1,t2);
       	   ans=0;
       	   for(int j=x;j<=y;j++){
       	       for(int k=j+1;k<=y;k++){
       	       	   if(k==j+1)ans++;
       	       	   else{
       	       	   	if(ask(j+1,k-1)<min(a[j],a[k]))ans++;
				    }
				}  	
			}
			printf("%d\n",ans);
	   }		
	}
} 
