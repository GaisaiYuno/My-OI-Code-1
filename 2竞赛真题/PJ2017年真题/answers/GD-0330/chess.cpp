#include <cstdio>
using namespace std;
int a[110][110],n,m,ans=3000000,x,y,c;
bool fl=1;

void dfs(int d1,int d2,int sum,int f,int now){
	if(d1==m&&d2==m){
		if(sum<ans)ans=sum;fl=0;
		return ;
	}
//	for(int i=1;i<=m;i++){
//		printf("\n");
//		for(int j=1;j<=m;j++)printf("%d ",a[i][j]);
//	}
//	printf("\n");
	if(f==3)f=0;
	//if(f==3)a[x][y]=f=0;
	if(d1+1<=m){
		if(a[d1+1][d2]!=0){
			//if(f==1){
			    if(a[d1+1][d2]==now)dfs(d1+1,d2,sum,3,a[d1+1][d2]);
		  	    else dfs(d1+1,d2,sum+1,3,a[d1+1][d2]);
//		    }
//		    else {
//		    	if(a[d1+1][d2]==now)dfs(d1+1,d2,sum,2,a[d1+1][d2],x,y);
//		  	    else dfs(d1+1,d2,sum+1,2,a[d1+1][d2],d1+1,d2);
//		    }
		}
	    else if(f!=1){
		    if(a[d1][d2]==1)dfs(d1+1,d2,sum+3,1,2);
		    else dfs(d1+1,d2,sum+2,1,2);
	        if(a[d1][d2]==2)dfs(d1+1,d2,sum+3,1,1);
	        else dfs(d1+1,d2,sum+2,1,1);
		}
	}
	if(d2+1<=m){
		if(a[d1][d2+1]!=0){
		//	if(f==1){
			    if(a[d1][d2+1]==now)dfs(d1,d2+1,sum,3,a[d1][d2+1]);
			    else dfs(d1,d2+1,sum+1,3,a[d1][d2+1]);
//			}
//			else {
//				if(a[d1][d2+1]==now)dfs(d1,d2+1,sum,2,a[d1][d2+1],x,y);
//			    else dfs(d1,d2+1,sum+1,2,a[d1][d2+1],x,y);
//			}
		}
		else if(f!=1){
		    if(a[d1][d2]==1)dfs(d1,d2+1,sum+2,1,1);
	        else dfs(d1,d2+1,sum+3,1,1);
	        if(a[d1][d2]==2)dfs(d1,d2+1,sum+2,1,2);
	        else dfs(d1,d2+1,sum+3,1,2);
		}
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
	dfs(1,1,0,2,a[1][1]);
	if(fl)printf("-1");
	else printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
