#include<iostream>
#include<cstdio>
long long n_[1000],book[1000],ls[1000];
short long_[1000];
const long long LONG_LONG_MAXTH=9223372036854;
int pow10(short i)
{
	int j=1;
	for(int c=0;c<i;c++)
	    j*=10;
	return j;
}
int main()
{
	using namespace std;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	for(int i=0;i<1000;i++)
	    ls[i]=LONG_LONG_MAXTH;
	int n,q,ls_=0;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	    cin>>n_[i];
	for(int i=0;i<q;i++)
	    cin>>long_[i]>>book[i];
	for(int j=0;j<q;j++)
		for(int i=0;i<n;i++)
		{
		    if((n_[i]%pow10(long_[j]))==book[j])
		    	if(n_[i]<ls[j])
		    	    ls[j]=n_[i];
	    }
	for(int i=0;i<q;i++)
	    if(ls[i]!=LONG_LONG_MAXTH)
	        cout<<ls[i]<<endl;
	    else
	        cout<<"-1"<<endl;
	return 0;
}
