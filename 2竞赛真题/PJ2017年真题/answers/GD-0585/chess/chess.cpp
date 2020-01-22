#include<iostream>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,co[110][110],cl[110][110];
void aa(int x,int y,int bom,bool usedd[][110])
{//cout<<x<<" "<<y<<" "<<bom<<" "<<co[x][y]<<endl;
	bool bo=0;
	if(x-1>0&&!usedd[x-1][y])
	{
		if(co[x-1][y]!=-1)
		{
			if(cl[x][y]&&cl[x][y]==cl[x-1][y]&&co[x-1][y]>co[x][y]||bom&&bom==cl[x-1][y]&&co[x-1][y]>co[x][y])
			{
				co[x-1][y]=co[x][y];
				usedd[x-1][y]=1;
				aa(x-1,y,0,usedd);
			}
			else if(cl[x][y]&&cl[x-1][y]&&cl[x][y]!=cl[x-1][y]&&co[x-1][y]>co[x][y]+1||bom&&cl[x-1][y]&&bom!=cl[x-1][y]&&co[x-1][y]>co[x][y]+1)
			{
				co[x-1][y]=co[x][y]+1;
				usedd[x-1][y]=1;
				aa(x-1,y,0,usedd);
			}
			else if(!cl[x-1][y]&&co[x-1][y]>co[x][y]+2&&!bom)
			{
				co[x-1][y]=co[x][y]+2;
				usedd[x-1][y]=1;
				aa(x-1,y,cl[x][y],usedd);
			}
		}	
		else
		{
			if(cl[x][y]&&cl[x][y]==cl[x-1][y]||bom&&bom==cl[x-1][y])
			{
				co[x-1][y]=co[x][y];
				usedd[x-1][y]=1;
				aa(x-1,y,0,usedd);
			}
			else if(cl[x][y]&&cl[x-1][y]&&cl[x][y]!=cl[x-1][y]||bom&&cl[x-1][y]&&bom!=cl[x-1][y])
			{
				co[x-1][y]=co[x][y]+1;
				usedd[x-1][y]=1;
				aa(x-1,y,0,usedd);
			}
			else if(!cl[x-1][y]&&!bom)
			{
				co[x-1][y]=co[x][y]+2;
				usedd[x-1][y]=1;
				aa(x-1,y,cl[x][y],usedd);
			}
		}
		usedd[x-1][y]=0;
	}
	if(x+1<=a&&!usedd[x+1][y])
	{
		if(co[x+1][y]!=-1)
		{
			if(cl[x][y]&&cl[x][y]==cl[x+1][y]&&co[x+1][y]>co[x][y]||bom&&bom==cl[x+1][y]&&co[x+1][y]>co[x][y])
			{
				co[x+1][y]=co[x][y];
				usedd[x+1][y]=1;
				aa(x+1,y,0,usedd);
			}
			else if(cl[x][y]&&cl[x+1][y]&&cl[x][y]!=cl[x+1][y]&&co[x+1][y]>co[x][y]+1||bom&&cl[x+1][y]&&bom!=cl[x+1][y]&&co[x+1][y]>co[x][y]+1)
			{
				co[x+1][y]=co[x][y]+1;
				usedd[x+1][y]=1;
				aa(x+1,y,0,usedd);
			}
			else if(!cl[x+1][y]&&co[x+1][y]>co[x][y]+2&&!bom)
			{
				co[x+1][y]=co[x][y]+2;
				usedd[x+1][y]=1;
				aa(x+1,y,cl[x][y],usedd);
			}
		}	
		else
		{
			if(cl[x][y]&&cl[x][y]==cl[x+1][y]||bom&&bom==cl[x+1][y])
			{
				co[x+1][y]=co[x][y];
				usedd[x+1][y]=1;
				aa(x+1,y,0,usedd);
			}
			else if(cl[x][y]&&cl[x+1][y]&&cl[x][y]!=cl[x+1][y]||bom&&cl[x+1][y]&&bom!=cl[x+1][y])
			{
				co[x+1][y]=co[x][y]+1;
				usedd[x+1][y]=1;
				aa(x+1,y,0,usedd);
			}
			else if(!cl[x+1][y]&&!bom)
			{
				co[x+1][y]=co[x][y]+2;
				usedd[x+1][y]=1;
				aa(x+1,y,cl[x][y],usedd);
			}
		}
		usedd[x+1][y]=0;
	}
	if(y-1>0&&!usedd[x][y-1])
	{
		if(co[x][y-1]!=-1)
		{
			if(cl[x][y]&&cl[x][y]==cl[x][y-1]&&co[x][y-1]>co[x][y]||bom&&bom==cl[x][y-1]&&co[x][y-1]>co[x][y])
			{
				co[x][y-1]=co[x][y];
				usedd[x][y-1]=1;
				aa(x,y-1,0,usedd);
			}
			else if(cl[x][y]&&cl[x][y-1]&&cl[x][y]!=cl[x][y-1]&&co[x][y-1]>co[x][y]+1||bom&&cl[x][y-1]&&bom!=cl[x][y-1]&&co[x][y-1]>co[x][y]+1)
			{
				co[x][y-1]=co[x][y]+1;
				usedd[x][y-1]=1;
				aa(x,y-1,0,usedd);
			}
			else if(!cl[x][y-1]&&co[x][y-1]>co[x][y]+2&&!bom)
			{
				co[x][y-1]=co[x][y]+2;
				usedd[x][y-1]=1;
				aa(x,y-1,cl[x][y],usedd);
			}
		}	
		else
		{
			if(cl[x][y]&&cl[x][y]==cl[x][y-1]||bom&&bom==cl[x][y-1])
			{
				co[x][y-1]=co[x][y];
				usedd[x][y-1]=1;
				aa(x,y-1,0,usedd);
			}
			else if(cl[x][y]&&cl[x][y-1]&&cl[x][y]!=cl[x][y-1]||bom&&cl[x][y-1]&&bom!=cl[x][y-1])
			{
				co[x][y-1]=co[x][y]+1;
				usedd[x][y-1]=1;
				aa(x,y-1,0,usedd);
			}
			else if(!cl[x][y-1]&&!bom)
			{
				co[x][y-1]=co[x][y]+2;
				usedd[x][y-1]=1;
				aa(x,y-1,cl[x][y],usedd);
			}
		}
		usedd[x][y-1]=0;
	}
	if(y+1<=a&&!usedd[x][y+1])
	{
		if(co[x][y+1]!=-1)
		{
			if(cl[x][y]&&cl[x][y]==cl[x][y+1]&&co[x][y+1]>co[x][y]||bom&&bom==cl[x][y+1]&&co[x][y+1]>co[x][y])
			{
				co[x][y+1]=co[x][y];
				usedd[x][y+1]=1;
				aa(x,y+1,0,usedd);
			}
			else if(cl[x][y]&&cl[x][y+1]&&cl[x][y]!=cl[x][y+1]&&co[x][y+1]>co[x][y]+1||bom&&cl[x][y+1]&&bom!=cl[x][y+1]&&co[x][y+1]>co[x][y]+1)
			{
				co[x][y+1]=co[x][y]+1;
				usedd[x][y+1]=1;
				aa(x,y+1,0,usedd);
			}
			else if(!cl[x][y+1]&&co[x][y+1]>co[x][y]+2&&!bom)
			{
				co[x][y+1]=co[x][y]+2;
				usedd[x][y+1]=1;
				aa(x,y+1,cl[x][y],usedd);
			}
		}	
		else
		{
			if(cl[x][y]&&cl[x][y]==cl[x][y+1]||bom&&bom==cl[x][y+1])
			{
				co[x][y+1]=co[x][y];
				usedd[x][y+1]=1;
				aa(x,y+1,0,usedd);
			}
			else if(cl[x][y]&&cl[x][y+1]&&cl[x][y]!=cl[x][y+1]||bom&&cl[x][y+1]&&bom!=cl[x][y+1])
			{
				co[x][y+1]=co[x][y]+1;
				usedd[x][y+1]=1;
				aa(x,y+1,0,usedd);
			}
			else if(!cl[x][y+1]&&!bom)
			{
				co[x][y+1]=co[x][y]+2;
				usedd[x][y+1]=1;
				aa(x,y+1,cl[x][y],usedd);
			}
		}
		usedd[x][y+1]=0;
	}
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int b,h,l,colo, x,y;
	bool usedd[110][110];
	cin>>a>>b;
	for(x=1;x<=a;++x)
	    for(y=1;y<=a;++y)
	    {
	    	cl[x][y]=0;
	    	co[x][y]=-1;
	    	usedd[x][y]=0;
	    }
	co[1][1]=0;
	usedd[1][1]=1;
	for(x=1;x<=b;++x)
	{
		cin>>h>>l>>colo;
		cl[h][l]=colo+1;
	}
	aa(1,1,0,usedd);
	/*for(x=1;x<=a;++x,cout<<endl)
	    for(y=1;y<=a;++y)
	        printf("%3d(%d)",co[x][y],cl[x][y]);*/
	cout<<co[a][a];
	return 0;
}
