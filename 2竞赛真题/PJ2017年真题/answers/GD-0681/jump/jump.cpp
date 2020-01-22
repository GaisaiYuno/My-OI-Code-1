#include<iostream>
#include<cstdio>
using namespace std;
int n,d,K,X[1000001],P[1000001],sum,maxx;
int pd(int x)
{
	int lb=0,ub=n+1;
	while(lb+1<ub)
	{
		int mid=(lb+ub)/2;
		if(x>=X[mid]) lb=mid;
		else ub=mid;
	}
    if(X[lb]==x) return P[lb];
    return 0;
}
bool Check(int x)
{
	int Left,Right,wz=0,fs=0;
	if(x<d) Left=d-x;
	else Left=1;
	Right=d+x;
//	cout<<Left<<" "<<Right<<"   "<<x<<endl;
	while(wz<=maxx)
	{
		int j=wz,Point;
	//	cout<<j<<" ";
		bool a=0;
	    for(int i=j+Left;i<=j+Right;i++)
	    {
			int tmp=pd(i);
		//	cout<<i<<" ";
			if(tmp>0)
		    {
		  	//    cout<<tmp;
		  	    a=1;
				wz=i;
		  	    fs+=tmp;
		  	    break;
		    }
		    if(tmp<=0)
		    {
				wz=i;
		        Point=tmp;
		    }
	    }
		if(!a)
		{
			fs+=Point;
		//	cout<<Point<<" ";
		} 
	//	cout<<endl;
		if(wz==j)
		{
			break;
		//	cout<<j;
		} 
	}
//    cout<<endl<<"|"<<fs<<endl;
	if(fs<K) return true;
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(X,0,sizeof(X));
	memset(P,0,sizeof(P));
	sum=0;
	maxx=0;
	cin>>n>>d>>K;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&X[i],&P[i]);
		if(P[i]>0) sum+=P[i];
		if(X[i]>maxx) maxx=X[i];
	}
	if(K>sum)
	{
		cout<<-1;
		return 0;
	}
	int lb=0,ub=maxx+1;
	if(n<=500) while(Check(lb)) lb++;
	else
	while(lb+1<ub)
	{
	//	cout<<"   "<<lb<<" "<<ub<<endl;
		int mid=(lb+ub)/2;
		if(Check(mid)) lb=mid;
		else ub=mid;
	}
	cout<<lb;
	return 0;
}
