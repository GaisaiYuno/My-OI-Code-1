#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int N,D,K,Ans1=0,Ans2=0,Jb=0,Jl=0;
struct fz
{
	int jl,f;
}FZ[500000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int k,z,x;
	scanf("%d%d%d",&N,&D,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&FZ[i].jl,&FZ[i].f);
		if(FZ[i].f>=0)
		Ans1+=FZ[i].f;
	}
	if(Ans1<K)
	{
		printf("-1");
		return 0;
	}
	while(Ans2<K)
	{
		
		Ans2=0;
		Jl=0;
		for(int i=0;i<N;i++)
		{k=0;
			if(Ans2>=K)
			break;
			if(Jb==0)
			{
				if(FZ[i].jl-Jl==D)
				{
					Ans2+=D;
					Jl+=D;
				}
				else
				break;
			}
			else
			{if(FZ[i].jl-Jl>=D-Jb&&FZ[i].jl-Jl<=D+Jb)
			{if(FZ[i].f>=0)
				{
					Ans2+=FZ[i].f;
					Jl=FZ[i].jl;
				}
				else
				{
					for(int j=i+1;j<N;j++)
					{
						if(FZ[j].f>0&&FZ[j].jl-Jl>=D-Jb&&FZ[j].jl-Jl<=D+Jb)
						{
							z=FZ[j].f;
							x=FZ[j].jl;
							k++;
							break;
						}
					}
					if(k!=0)
					{
						Ans2+=z;
						Jl=x;
					}
					else
					{
						Ans2+=FZ[i].f;
						Jl=FZ[i].jl;
					}
				}
			}
			else
			{
				if(FZ[i].jl-Jl>D+Jb)
				break;
			}	
			}
		}
		Jb++;
	}
	printf("%d",Jb-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
