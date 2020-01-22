#include<cstdio>

using namespace std;

int marks[500005], n,d, k,maxmark[500005];
int index, mark, max, move;

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for (int i = 0 ; i < n ; i++)
	{
		scanf("%d %d",&index,&mark);
		marks[index] = mark;
		if (mark > 0) max += mark;
	}
	if (max < k) 
	{
		printf("-1");
		return 0;
	}
	move = 0;
	while (true)
	{
		for (int i = 0 ;i <= index;i++) maxmark[i]=0;
		
		for (int i = 0;i <= index;i++)
		 for (int j = i + d - move; j <= i +d+ move;j++)
		  if (j > 0 && j <= index && j > i)
		  {              
		  	 if (maxmark[i] + marks[j] > maxmark[j]) maxmark[j] = maxmark[i] + marks[j];
		  	 if (maxmark[j] >= k)
		  	 {
		  	 	printf("%d",move);
		  	 	return 0;
		  	 }
		  }
		move++;
	}
	return 0;
}
