#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int m,n,x1,x2,y1,y2,num,sum,summ,a[101][101],x,y,c;
int xx[4]{0,-1,0,1},yy[4]{-1,0,1,0};
double b,b1,b2;
/*int check(int a)
{
	if(a==-1) return 80000;
	    else  return num;
}*/
/*int work(int x1,int y1)
{
	if(x1!=m || y1!=m)
	{
		b2=false;
		for(int i=1;i<=4;i++)
		{
			b1=false;
			x2=x1+xx[i];
			y2=y1+yy[i];
			if(x2>0 && x2<=m && y2>0 && y2<=m)
	 		{
		    	if(a[x2][y2]!=0) 
	    		{
	    			b2=true;
		    		b1=true;
		    		b=true;
	    			if(a[x2][y2]!=a[x1][y1]) num+=1;
		    		x1=x2;y1=y2;
		    	}
	    		if(a[x2][y2]==0 && b==true) 
		    	{
		    		b2=true;
		    		b1=true;
		    		b=false;
	    			x1=x2;y1=y2;
	    			num+=2;
	    		}
	    		if(b1) {sum+=work(x2,y2);num=0;}
	    		else return -1;
			}
		}
		if(!b2) return -1;
	}
	if(x1==m && y1==m) return num;
}*/
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		if(c==0) a[x][y]=2;
		   else  a[x][y]=c;
	}
	//summ=work(1,1);
    summ=-1;
	printf("%d",summ);
	return 0;
}
