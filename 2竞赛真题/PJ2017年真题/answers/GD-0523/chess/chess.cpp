#include<iostream>
#include<cstdio>
using namespace std;
int n,m,sh[101][101],a[101][101],pd[101][101],i,j,x,y,z,ans=0,minn=0x770789,
dx[5]={0,1,0,-1,0},dy[5]={0,0,-1,0,1},bo=0;
int search(int p,int q)
{
	pd[p][q]=1;int k=p;int l=q;int pdd=0,ppd=1;
	for(i=1;i<=4;i++)
	{
	 k+=dx[i];l+=dy[i];
	 if(k>0&&k<=m&&l>0&&l<=m)
	 if(!pd[k][l]&&(sh[k][l]!=0||!bo))
	 {
	   pd[k][l]=1;
	   if(sh[k][l]==0)
	   {
		for(j=1;j<=2;j++)
		{
		 ans+=2;bo=1;
         sh[k][l]=j;	  
         if(k!=m||l!=m)
         {
           pdd=1;
           search(k,l); 
		   sh[k][l]=a[k][l];
		   ans-=2;pd[k][l]=0;bo=0;k=p;l=q;
         }
         else
         {
           if(ans>minn)minn=ans;
         }
		
	    }
	   }
	   else
	   if(ppd)
	   {
	   	if(sh[k][l]==a[k][l]){
	   	  ans+=0;ppd=0;
	   	}
	   	else ans++;
	   	search(k,l);
	   	sh[k][l]=a[k][l];ans-=ppd;ppd=1;
	   	pd[k][l]=0;k=p;l=q;
	   } 
	 }
    }	
}
int main()
{
	freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
	  cin>>x>>y>>z;
	  if(z==0)a[x][y]=1;
	  if(z==1)a[x][y]=2;
	}
	for(i=1;i<=m;i++)
	 for(j=1;j<=m;j++)
	  sh[i][j]=a[i][j];
	search(1,1);
	if(minn>10000)cout<<"-1";
	else cout<<minn;     
	return 0;
}






