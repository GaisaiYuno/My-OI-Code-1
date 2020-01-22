#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct tn
{
	int x;
	int y;
};
struct queue
{
	int h,t;
	tn qe[11000];
	int push(tn a)
	{
		qe[t]=a;
		--t;
	}
	int pop()
	{
		--h;
	}
	tn head()
	{
		return qe[h];
	}
	tn tail()
	{
		return qe[t-1];
	}
	bool emp()
	{
		return h==t;
	}
};

int vcas(int a,int b);
int vcas(int a,int b)
{
	if((a==b&&a>=0&&a<2)||(a==0&&b==2)||(a==1&&b==3))return 0;
	else if(a!=b&&a<2&&(b==-1||b==2||b==3))return 2;
	else if((abs(a-b)==1&&a>=0&&b>=0&&a<2&&b<2)||(a==0&&b==3)||(a==1&&b==2))return 1;
	else return -1;
}

int min(int a,int b);
int min(int a,int b)
{
	return a>b?b:a;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	queue q;
	int b[110][110]={-1},v[110][110],m,n;	// 0:red
											// 1:yellow
											//-1:colorless
											// 2:colorless->red
											// 3:colorless->yellow
	tn l;
	bool z[110][110];
	cin>>m>>n;
	for(int i=0;i<n;++i)
	{
		int x,y,c;
		cin>>x>>y>>c;
		b[x-1][y-1]=c;
		v[x-1][y-1]=10000;
	}
	q.h=q.t=10100;
	v[0][0]=0;
	z[0][0]=true;
	l.x=0;l.y=0;
	q.push(l);
/*	while(!q.emp())
	{
		if(q.head().x<m-1)
		{
			l.x=q.head().x+1;
			l.y=q.head().y;
			if(vcas(b[q.head().x][q.head().y],b[l.x][l.y])>=0)
			{
				if(vcas(b[q.head().x][q.head().y],b[l.x][l.y])==2)b[l.x][l.y]=b[q.head().x][q.head().y]+2;
				v[l.x][l.y]=min(v[l.x][l.y],v[q.head().x][q.head().y]+vcas(b[q.head().x][q.head().y],b[l.x][l.y]));
			}
			if(!z[l.x][l.y])
			{
				q.push(l);
				z[l.x][l.y]=true;
			}
		}
		if(q.head().y<m-1)
		{
			l.x=q.head().x;
			l.y=q.head().y+1;
			if(vcas(b[q.head().x][q.head().y],b[l.x][l.y])>=0)
			{
				if(vcas(b[q.head().x][q.head().y],b[l.x][l.y])==2)b[l.x][l.y]=b[q.head().x][q.head().y]+2;
				v[l.x][l.y]=min(v[l.x][l.y],v[q.head().x][q.head().y]+vcas(b[q.head().x][q.head().y],b[l.x][l.y]));
			}
			if(!z[l.x][l.y])
			{
				q.push(l);
				z[l.x][l.y]=true;
			}
		}
		if(q.head().x>0)
		{
			l.x=q.head().x-1;
			l.y=q.head().y;
			if(vcas(b[q.head().x][q.head().y],b[l.x][l.y])>=0)
			{
				if(vcas(b[q.head().x][q.head().y],b[l.x][l.y])==2)b[l.x][l.y]=b[q.head().x][q.head().y]+2;
				v[l.x][l.y]=min(v[l.x][l.y],v[q.head().x][q.head().y]+vcas(b[q.head().x][q.head().y],b[l.x][l.y]));
			}
			if(!z[l.x][l.y])
			{
				q.push(l);
				z[l.x][l.y]=true;
			}
		}
		if(q.head().y>0)
		{
			l.x=q.head().x;
			l.y=q.head().y-1;
			if(vcas(b[q.head().x][q.head().y],b[l.x][l.y])>=0)
			{
				if(vcas(b[q.head().x][q.head().y],b[l.x][l.y])==2)b[l.x][l.y]=b[q.head().x][q.head().y]+2;
				v[l.x][l.y]=min(v[l.x][l.y],v[q.head().x][q.head().y]+vcas(b[q.head().x][q.head().y],b[l.x][l.y]));
			}
			if(!z[l.x][l.y])
			{
				q.push(l);
				z[l.x][l.y]=true;
			}
		}
		q.pop();
	}*/
	cout<<"-1";
	fclose(stdin);fclose(stdout);
	return 0;
}
