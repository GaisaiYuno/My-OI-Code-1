#include<cstdio>
using namespace std;
int x[500000];
int s[500000];
int d,k,m;
int nw;

bool can(int n)
{
	int p,q;
	int sum=0;
	int up=n+d;
	int down=n-d;
	nw=0;
	if(down<1)
		down=1;
	
	while(nw<x[m-1]){
		for(int i=0;i<m;i++)
			if(x[i]>nw&&s[i]>0){
				p=x[i];
				q=s[i];
				break;
			}
		
		if(up>=(p-nw)&&(p-nw)>=down){
			nw=p;
			sum+=q;
			continue;
		}
	}
	
	return sum>=k?1:0;
}

int main(void)
{
	int sum=0;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&m,&d,&k);
	
	for(int i=0;i<m;i++){
		scanf("%d%d",&x[i],&s[i]);
		if(s[i]>0)
			sum+=s[i];
	}
	
	if(sum<k){
		printf("-1\n");
		return 0;
	}
	
	int l=0,r=1000000000-d+1000;
	while(l<r){
		int m=(l+r)/2;
		if(can(m))
			r=m;
		else
			l=m+1;
	}
	
	printf("%d\n",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
