#include<bits/stdc++.h>
using namespace std;
int a[10]={1,0,-1,0,1,-1,-1,1};
int b[10]={0,-1,0,1,1,1,-1,-1};
int x[100],y[100],c[100],A[100][100],dep[100];
int ans=0;
int dfs(int c,int d,int h,int M){
	if(c==M&&d==M) return ans;
	else{
		int k=A[c][d],p=0;
	    for(int i=0;i<4;i++){
		    if(A[c+a[i]][d+b[i]]==k){
		    	c+=a[i],d+=b[i],p=0;
				break;
		    }
		    else if(A[c+a[i]][d+b[i]]!=0) {
		    	c+=a[i],d+=b[i],ans+=1,p=0;
				break;
		    }
		    else if(A[c+a[i]][d+b[i]]==0) p=1;
	    }
	    if(p==1) for(int j=4;j<8;j++){
		    if(A[c+a[j]][d+b[j]]==k){
		    	c+=a[j],d+=b[j],p=0,ans+=2;
				break;
		    }
		    else if(A[c+a[j]][d+b[j]]!=0){
		    	c+=a[j],d+=b[j],p=0,ans+=3;
				break;
		    }
	    	else if(A[c+a[j]][d+b[j]]==0) p=2;
    	}
    	if(p==2) cout<<"-1";
    	else{
	    	dep[h]=true;
     		dfs(c,d,h+1,M);
	     	dep[h]=false;
     	}
	}
	
}
int main(){
	int m,n;
	//freopen("score.in","r",stdin);
	//freopen("score.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>c[i];
		A[x[i]][y[i]]=c[i]+1;
	}
	if(A[m][m]==0&&n<m) cout<<"-1";
	else dfs(1,1,1,m);
}

/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
*/
