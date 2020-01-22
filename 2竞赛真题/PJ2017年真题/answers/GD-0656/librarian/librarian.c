#include <stdio.h>

int a(int n)
{
	int i;
	int ans = 1;
	for(i = 0;i<n;++i)ans*=10;
	return ans;
}

int main(void)
{
	FILE* pin = fopen("librarian.in","r");
	FILE* pout = fopen("librarian.out","w");
	int n,q;
	fscanf(pin,"%d%d",&n,&q);
	
	int books[1000];

	int i,j;
	for(i = 0;i < n;++i)
	{
		fscanf(pin,"%d",&books[i]);
	}
	
	
	int reader[1000];
	int size[1000];
	for(i=0;i< q;++i)
	{
		fscanf(pin,"%d%d",&size[i],&reader[i]);
		size[i] = a(size[i]);
	}
	
	
	int min[1000];for(i = 0;i< 1000;++i)min[i] = 10000001;
	for(j = 0;j< q;++j)
	{
		for(i = 0;i<n;++i)
		{
			if(reader[j] == books[i] % size[j] && 
			   books[i] < min[j])
			{
				min[j] = books[i];
			}
		}
	}
				
	for(i = 0;i< q;++i)
	{
		fprintf(pout,"%d\n",min[i] != 10000001 ? min[i] : -1);
	}		
	
	return 0;
}


