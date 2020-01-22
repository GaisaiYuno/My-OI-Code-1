#include<fstream>
using namespace std;
int a[100001],f[100001];
bool cz[100001];
int main()
{
	ifstream fin("jump.in");
	ofstream fout("jump.out");
	int n,d,k,mad=-1;
	fin>>n>>d>>k;
	int xxx=0;
	for(int i=1;i<=n;i++)
	{
	  int ad;
	  fin>>ad;
	  mad=max(mad,ad);
	  fin>>a[ad];
	  cz[ad]=1;
	  if(a[ad]>0)
	   xxx+=a[ad];
	}
	if(xxx<k)
	{
	  fout<<-1;
	  return 0;
	}
	for(int g=0;g<=1e9;g++)
	{
	  for(int i=1;i<=mad;i++)
	   f[i]=-1e9;
	  int kk;
	  if(d-g>0) 
	   kk=d-g;
	  else
	   kk=d;
	  for(int j=0;j<=mad;j+=kk)
	   for(int ii=j;ii<=j+kk;ii++)
	   for(int i=kk;i<=d+g;i++)
	    if(cz[ii+i])
	   	 f[ii+i]=max(f[ii+i],f[ii]+a[ii+i]);
	   for(int i=1;i<=mad;i++)
	    if(f[i]>=k)
	    {
	      fout<<g;
	      fin.close();
	      fout.close();
	      return 0;
	    }
	}
}
