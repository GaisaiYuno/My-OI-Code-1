#include <iostream>
#include <cstdio>
using namespace std;
int n,d,k,a[50000],fen[50000],g;
bool check(int mid)
{
	int sum=0;
	int o=0;
	for(int i=1;i<=n;i++)
	{
		if((a[o]+mid+d)>=a[i]&&a[i]>=0)
		{
			o=i;
			sum+=fen[i];
		}
		if(sum>=k) break;
	}
	if(sum>=k) return true;
	else return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    scanf("%d%d%d",&n,&d,&k);
    for(int i=1;i<=n;i++)
     scanf("%d%d",&a[i],&fen[i]);
     if(check(0)) 
	 {
     	cout<<"0"<<endl;
     	return 0;
     }
     int lb=1,ub=a[n]-a[0]+100,mid;
     while(lb+1<ub)
     {
     	mid=(lb+ub)/2;
     	if(check(mid)) ub=mid;
     	else lb=mid;
     }
     if(ub==a[n]-a[0]+100) cout<<"-1";
     else cout<<ub;
	return 0;
}
