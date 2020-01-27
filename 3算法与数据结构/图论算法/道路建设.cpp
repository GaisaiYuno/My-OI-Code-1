//洛谷 道路建设
//prim无优化 O(n^2) 
#include<iostream>
#include<cstring> 
#include<cmath> 
#define maxn 1000
#define INF 999999
int n,m;
double ans;
struct dot{
	int x;
	int y;
}a[maxn];
double g[maxn][maxn];
double key[maxn];
int used[maxn];
using namespace std;
double dis(int x1,int y1,int x2,int y2){
	return sqrt(pow((double)(x1-x2),2)+pow((double)(y1-y2),2));
}
void prim(){
	memset(key,INF,sizeof(key));
	key[1]=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=1;j<=n;j++){
			if(used[j]==0&&key[j]<key[k])
			  k=j;
		} 
		used[k]=1;
	    for(int j=1;j<=n;j++){
	    	if(used[j]==0&&g[k][j]<key[j])
	    	    key[j]=g[k][j];
		}
	}
	ans=0;
	for(int u=1;u<=n;u++) ans+=key[u];
}
int main(){
	int h,l;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
   	    cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=n;i++){
    	for(int j=i+1;j<=n;j++)
   	       g[i][j]=g[j][i]=dis(a[i].x,a[i].y,a[j].x,a[j].y);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>h>>l;
        g[h][l]=g[l][h]=0;
    }

    prim();
    cout<<ans<<endl; 
    return 0;
} 
