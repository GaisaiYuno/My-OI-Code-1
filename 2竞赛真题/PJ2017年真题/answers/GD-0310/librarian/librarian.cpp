#include<cstdio>
using namespace std;
int Pow10[11];
int N,Q;
int Book[1000];
int Len;
int Num;
int Min;

void _in(void)
{
	Pow10[0]=1;
	for(int i=1;i<=10;i++)
		Pow10[i]=10*Pow10[i-1];
	
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)
		scanf("%d",&Book[i]);
	return;
}

int main(void)
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	_in();
	
	for(int i=0;i<Q;i++){
		scanf("%d%d",&Len,&Num);
		Min=99999999;
		
		for(int i=0;i<N;i++)
			if(Book[i]<Min)
				if((Book[i]-Num)%Pow10[Len]==0)
					Min=Book[i];
		
		if(Min==99999999)
			Min=-1;
		printf("%d\n",Min);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
