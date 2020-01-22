#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int fac(int);
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n[2000],q[2000],n_len,q_len,m,min[2000],x[2000],real[2000],s;
	cin>>n_len>>q_len;
	for(int i=0;i<2000;++i)
	{
		 min[i]=1000000;
		 x[i]=0;
		 real[i]=0;
	}
	for(int i=0;i<n_len;++i) 
	    cin>>n[i];
	for(int i=0;i<q_len;++i)
	{
		cin>>q[i]>>m;
		for(int j=0;j<n_len;j++){
		s=fac(q[j]);
		if(m==n[j]%s)
		if(n[j]<=min[j])
		if(x[j]==0){
		if(real[j]==0){
			 x[j]=1;
			 real[i]=j;
			 min[j]=n[j];
			 continue;
		}
		else{x[real[i]]=0;
		min[j]=n[j];
		real[i]=j;
		continue;
		 }
		}
		}
	}
	for(int i=0;i<q_len-1;++i)
	{
		if(min[i]==1000000) cout<<"-1"<<endl;
		else cout<<min[i]<<endl;
	}
	if(min[n_len-1]!=1000000) cout<<min[n_len-1];
	else cout<<"-1";
	fclose(stdin);
	fclose(stdout);
	return 0;  
}


int fac(int a)
{
	int sum=1;
	for(int i=0;i<a;++i)
	    sum*=10;
	    return sum;
}
