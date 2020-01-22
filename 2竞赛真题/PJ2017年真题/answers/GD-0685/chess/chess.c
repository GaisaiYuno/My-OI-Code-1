#include<stdio.h>
int movep(int **color)
{
	int p[2]={0},r=*((*color+1)),d=**(color+1),*i=p;
	if(**color==0)
	{
		switch(r<<3+d)
	{
		case 0:return -1;
		default:*i=0;i++;
	}
	}
	else
	{
		switch(r<<3+d)
	{
		case 0:*i=2;i++;
		case 1:
		case 5:*i=**color==0;i++;
		case 2:
		case 10:*i=**color==1;i++;
		case 6:
		case 9:*i=0;i++;
		default:return -1;
	}
	}
	return p[0]<p[1]?p[0]:p[1];
}
int navi(int **color,int m)
{
	int ans,x,y;
	for(x=y=0;x!=m||y!=m;)
	{
		x++;
		if(movep(*(color+y)+x)==-1)
		{
			x--;
			y++;
		}
		else
		{
			ans+=movep(*(color+y)+x);
			continue;
		}
		if(movep(*(color+y)+x)==-1)
		{
			return -1;
		}
		else
		{
			ans+=movep(*(color+y)+x);
		}
	}
	return ans;
}
int main()
{
	int m,n,x,y,color,i,board[100][100]={0};
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&color);
		board[x-1][y-1]=color+1;
	}
	printf("%d",navi(board,n));
	return 0;
}
