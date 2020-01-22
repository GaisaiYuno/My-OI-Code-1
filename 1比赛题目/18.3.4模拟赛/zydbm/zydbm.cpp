#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1005
#define ForMyLove return 0;
using namespace std;
struct maze{
	int d;
	int dv;
	int w;
}a[maxn];
int n,v;
inline int abs(int x){
	if(x>0) return x;
	else return -x;
}
inline int fastread(){
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
int cmp(maze a,maze b){
	double x1=a.w/abs(a.dv);
	double x2=b.w/abs(b.dv);	
	return x1>x2;
}
int main(){
	freopen("zydbm.in","r",stdin);
	freopen("zydbm.out","w",stdout);
	n=fastread();
	v=fastread();
	for(int i=1;i<=n;i++){
		a[i].d=fastread();
		a[i].w=fastread();
	}
	for(int i=1;i<=n;i++){
		a[i].dv=a[i].d-a[v].d;
	}
	swap(a[1],a[v]);
	sort(a+2,a+1+n,cmp);
	int t=0,ans=0,last=0;
	int maxd=0,mind=0;
	for(int i=2;i<=n;i++){
	    if(a[i].dv>0){ 
	        if(a[i].dv>maxd){ 
				t+=abs(a[i].d-a[i-1].d);
				ans+=t*a[i].w;
				maxd=a[i].d;
			}else{
				ans+=a[i].dv*a[i].w;
			}
	    }else{
	    	if(a[i].dv<mind){
	    		t+=abs(a[i].d-a[i-1].d);
	    	    ans+=t*a[i].w;
	    	    mind=a[i].dv;
			}else{
				ans+=a[i].dv*a[i].w; 
			}
	    	
		}
	}
	cout<<ans<<endl;
	ForMyLove
}
