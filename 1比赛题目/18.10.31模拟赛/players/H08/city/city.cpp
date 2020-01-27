#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map> 
#include<set>
#include<vector>
#include<stack>
using namespace std;
#define maxn 1000005
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
int n,m;
int a[maxn];
bool vis[maxn];
struct node{
	int l;
	int r;
}q[maxn],q1[maxn];
int num[maxn];
bool cmp(node a,node b){
	return a.l<b.l;
}
int cnt;
int mx;
int s,d; 
int tot;
int cf[maxn];
int cf1[maxn];
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=m;i++){
		read(q[i].l);read(q[i].r); 
	}
	sort(q+1,q+m+1,cmp);
//	for(int i=1;i<=m;i++){
//		cout<<q[i].l<<" "<<q[i].r<<endl; 
//	}
	for(int i=1;i<=m;i++){
		if(vis[i])continue;
		vis[i]=true;
		mx=q[i].r;
		for(int j=i+1;j<=m;j++){
			if(mx>=q[j].l){//ÖÂÃü´íÎó 
				vis[j]=true;
				mx=max(mx,q[j].r);
			}
		}
		q1[++tot].l=q[i].l;
		q1[tot].r=mx;
	}
//	cout<<q1[tot].l<<" "<<q1[tot].r<<endl;
	s=0;
	int temp=0;
    for(int i=1;i<=tot;i++){
    	for(int j=1;j<=n;j++){
    		if(a[j]<q1[i].l){
    			temp++;
    			cf[q1[i].l-a[j]]++;
    			cf[q1[i].r-a[j]+1]--;
    		//	cout<<"check"<<endl;
			}
			else if(a[j]>q1[i].r){
//				temp++;
				cf1[a[j]-q1[i].r]++;
				cf1[a[j]-q1[i].l+1]--;
			}
			else{
	//			temp++;
				cf[0]++;cf1[0]++;
				cf[q1[i].r-a[j]+1]--;
//				cout<<"check"<<endl;
				cf1[a[j]-q1[i].l+1]--;
			}
		}
	}
//	cout<<temp<<endl;
//	cout<<cf[0]<<" "<<cf1[0]<<endl;
	int sum=0;
	sum=cf[0];
	if(sum>s){
		s=sum;
		d=0;
	}
	for(int i=1;i<=maxn;i++){
		sum+=cf[i];
	//	cout<<sum<<endl;
		if(sum>s){
			s=sum;
			d=i;
		}
	}
	sum=cf1[0];
	if(cf1[0]>s){
		s=sum;
		d=0;
	}
	if(cf1[0]==s){
		d=0;
	}
	for(int i=1;i<=maxn;i++){
		sum+=cf1[i];
		if(sum>s){
			s=sum;
			d=i;
		}
		else if(sum==s){
			d=min(d,i);
		}
	}
	cout<<d<<" "<<s<<endl;
}
