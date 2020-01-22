#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long read()
{
	long long f=1,s=0;char c;
	c=getchar();
	if(c=='-') f=-1;
	while(c=='-'||c>=48&&c<=57) {s*=10,s+=c-48;c=getchar();}
    return s*f;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int w,i,j,n,q,x[1100],y[1100]; string mins,z,s[1100];
	n=read();q=read();
	for(i=1;i<=n;i++) {getline(cin,s[i]);y[i]=s[i].size()-1;}
	int l,k1,k2,f;
	for(i=1;i<=q;i++)
	{
		w=read();
		getline(cin,z);
		mins="99999999";
		l=z.size()-1;
		for(j=1;j<=n;j++)
		{
			k1=y[j];k2=l;
			f=0;
			while(k2>=0)
		       if(s[j][k1]!=z[k2]) {f=1;break;}
		      else k1--,k2--;
		    if(f==0)
		    	if(mins.size()-1>y[j]) mins=s[j];
		    	else 
			    	if(mins.size()-1==y[j])
				       if(mins>s[j]) mins=s[j];
		}
		if(mins=="99999999") cout<<-1<<endl;
		else cout<<mins<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
