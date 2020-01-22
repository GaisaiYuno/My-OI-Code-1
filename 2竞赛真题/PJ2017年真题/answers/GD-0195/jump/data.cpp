#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>

int n=1000,m=100,t=10000;

int main()
{
	freopen("jump.in","w",stdout);
	srand(time(0));
	int x=100,d=1;
	printf("%d %d\n",x,rand());
	while(d<n)
	{
		int tt=rand()*rand()%10000000-rand()*rand()%10000000;
		if(tt>x && tt-x<1000)
		{
			printf("%d %d\n",tt,rand());
			x=tt;
			d++;
		}
	}
}
