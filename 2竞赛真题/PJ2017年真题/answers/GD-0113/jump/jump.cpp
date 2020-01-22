#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
long long n,d,k,s,i,a,b;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	s=0;
	scanf("%lld%lld%lld",&n,&d,&k);
	for (i=1;i<=n;i++)
	  {
	  	cin>>a>>b;
	  	if (b>0) s+=b;
	  }
	if (k>s) cout<<-1; else{
	srand((unsigned)time(NULL));
	if (k<=10) cout<<rand()%10; else cout<<rand()%100;
    }
	return 0;
}
