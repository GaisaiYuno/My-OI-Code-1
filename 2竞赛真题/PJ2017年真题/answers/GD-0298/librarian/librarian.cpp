#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>

using namespace std;

int const MAX=100000;
int m=0,p=0,n,q,ln[MAX]={0},nu[MAX]={0},nw[MAX]={0},a[MAX]={0},t=100000;

int size(int n)
{
	int x=0;
	if(n==0)
	  return 1;
	while(n)
	{
		n=n/10;
		x++;
	}
	
	return x;
}

int chu(int n)
{
	int x=1;
	while(n)
	{
		x*=10;
		n--;
	}
	return x;
}

int main(void)
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	long long min;
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>ln[i];
	for(int i=0;i<q;i++)
	    cin>>nu[i]>>nw[i];
	for(int i=0;i<q;i++)
	{
		m=0;
		t=0;
		p=0;
		for(int j=0;j<n;j++)
		{
		     m=size(nw[i]);
			 if(ln[j]%(chu(m))==nw[i])
			 {
			 	p=1;
			 	a[++t]=ln[j];
			 }
			   
		}
		min=1000000000000000000;
		if(p==1)
		{
			 while(t)
		    {
			    if(a[t]<min)
			       min=a[t];
			       t--;
			       
		     }
	
		    cout<<min<<endl;
		}
		if(p==0)
		  cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
