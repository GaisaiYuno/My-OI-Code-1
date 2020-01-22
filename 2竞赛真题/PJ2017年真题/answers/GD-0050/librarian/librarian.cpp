#include<fstream>
#include<string>
using namespace std;
int main()
{
   	ifstream fin("librarian.in");
	ofstream fout("librarian.out");
	long int a[1010],b[1010],c[1010];
    int n,q,maxx=100000000,cs=0,dd[1010],cc=1;
	fin>>n>>q;
	for(int i=1;i<=n;i++)
	 fin>>a[i];
	 for(int i=1;i<=q;i++)
	 fin>>c[i]>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q;j++)
	  {
	  	if(b[i]==a[j])
	  	{
	  	 dd[cc++]=a[j];
	  	  maxx=10000000;
	  	  cs=1;
	  	  break;
	  	}
	  	 int ss=1;
	  	for(int k=1;k<=c[j];k++)
	  	ss*=10;
	  	if(b[i]==a[j]%ss)
	  	{
	  		if(a[j]<maxx)
	  		{
	  			maxx=a[j];
	  		    cs=1;
	  		} 
	  	}		 
		     if(cs==1&&j==q)
		  {
		  	dd[cc++]=maxx;
		  	maxx=10000000;
		  	cs=0;
		  	break;
		  }
		  
	  	if(j==q&&cs==0)
	  	{
	  	   dd[cc++]=-1;
	  	}
	  }
	}
	for(int i=1;i<=q;i++)
	fout<<dd[i]<<endl;
}
