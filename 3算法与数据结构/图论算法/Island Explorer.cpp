#include<iostream>
#include<cmath>
#include<cstring>
#define maxn 5005
using namespace std;
double key[maxn];
int used[maxn];
struct node{
	double x;
	double y;
};
node A,B,C,D;
node dot[maxn+maxn];
void input(node* a){
	scanf("%lf%lf",&(a->x),&(a->y)); 
}
double getdis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cnt,n,m;
double t;
double prim(){
    memset(key,0x7f,sizeof(key));	
    key[1]=0;
    memset(used,0,sizeof(used));
    for(int i=1;i<=n+m;i++){
        int k=0;
        for(int j=1;j<=n+m;j++){
            if(used[j]==0&&key[j]<key[k])
              k=j;
        } 
        used[k]=1;
        for(int j=1;j<=n+m;j++){
        	double tmp=getdis(dot[k],dot[j]);
        	if(used[j]==0&&tmp<key[j])
        	    key[j]=tmp;
        }
    }
    double sum=0;
    for(int u=1;u<=n+m;u++) sum+=key[u];
    return sum;
}
int main(){
	cin>>cnt;
	for(int k=1;k<=cnt;k++) { 
		cin>>n>>m;
		input(&A);
		input(&B);
		input(&C);
		input(&D);
		for(int i=1;i<=n;i++){
			cin>>t;
			dot[i].x=A.x*t+B.x*(1-t);
			dot[i].y=A.y*t+B.y*(1-t);
		}
		for(int i=n+1;i<=n+m;i++){
			cin>>t;
			dot[i].x=C.x*t+D.x*(1-t);
			dot[i].y=C.y*t+D.y*(1-t);
		}
		/*for(int i=1;i<=n+m;i++){
			for(int j=i;j<=n+m;j++){
				g[i][j]=g[j][i]=getdis(dot[i],dot[j]);
			}
		}
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
			    printf("%.3f ",g[i][j]);
		    }
		    cout<<endl;
		}*/ 
		printf("Case #%d: %.3f\n",k,prim());
	} 
}
