#include<iostream>
#include<cstdio>
using namespace std;
int n,m,i,j,u;
int x,y,c,s,ans=200010;
long long a[110][110],f[110][110],gsx[100010],gsy[100010];
void dfs(int i,int j,int sum,int w)
{
	cout<<i<<" "<<j<<" "<<sum<<" "<<w<<endl;
	if(i==m&&j==m)
	{
		if(sum<ans)
			ans=sum;
		return;
	}
	for(u=1;u<=s;u++)
	{
		if(gsx[u]==i&&gsy[u]==j)
			break;
	}
	int kd=0;
	if(u<=s)
	{
		if(w!=1) if(i+1<=m) dfs(i+1,j,sum,3);
		if(w!=4) if(j+1<=m) dfs(i,j+1,sum,2);
		if(w!=3) if(i-1>0) dfs(i-1,j,sum,1);
		if(w!=2) if(j-1>0) dfs(i,j-1,sum,2);
		
	}
	else{
		if(w!=1)
		if(i+1<=m) {
			if(a[i+1][j]!=-1)
			{
			if(a[i+1][j]!=a[i][j])
				dfs(i-1,j,sum+1,3);
			dfs(i-1,j,sum,3);
			}
			else 
			{
				dfs(i+1,j,sum+2,3);
		    	s++;
		    	gsx[s]=i+1; gsy[s]=j;
			}
		}
		if(w!=4)
		if(j+1<=m)
		{
			if(a[i][j+1]!=-1){
			if(a[i][j+1]!=a[i][j])
				dfs(i,j+1,sum+1,2);
			dfs(i,j+1,sum,2);
			}
			else{
				dfs(i,j+1,sum+2,2);
		    	s++;
		    	gsx[s]=i; gsy[s]=j+1;
			}
		}
		if(w!=3) 
		if(i-1>0) {
			if(a[i-1][j]!=-1){
			if(a[i-1][j]!=a[i][j])
				dfs(i-1,j,sum+1,1);
			dfs(i-1,j,sum,1);
		    }
		    else {
		    	dfs(i-1,j,sum+2,1);
		    	s++;
		    	gsx[s]=i-1; gsy[s]=j;
		    }
		}
		if(w!=2)
		if(j-1>0)
		{
			if(a[i][j-1]!=-1){
			if(a[i][j-1]!=a[i][j])
				dfs(i,j-1,sum+1,4);
			dfs(i,j-1,sum,4);
			}
			else{
				dfs(i,j-1,sum+2,4);
		    	s++;
		    	gsx[s]=i; gsy[s]=j-1;
			}
		}
		
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	cin>>m>>n;
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++)
			a[i][j]=-1;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c;
	}
	
   
    cout<<-1<<endl;
	return 0;
}

