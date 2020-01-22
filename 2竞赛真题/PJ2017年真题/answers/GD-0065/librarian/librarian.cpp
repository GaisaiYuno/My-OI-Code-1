#include<fstream>
using namespace std;
int a[1005],b[1005][2];
ifstream fin("librarian.in");
ofstream fout("librarian.out");
int main ()
{
	int n,q;
	fin>>n>>q;
	int t;
	for (int i=1;i<=n;i++) fin>>a[i];
	for (int i=1;i<=q;i++) fin>>b[i][1]>>b[i][2];
	for (int i=1;i<=n;i++)
	  for (int j=i+1;j<=n;j++)
	  {
	  	 if (a[i]>a[j])
	  	 {
	  	 	t=a[i];
	  	 	a[i]=a[j];
	  	 	a[j]=t;
	  	 }
	  }
	  int k=1;
	  int h=0,hh=0,bj=0;
	  int c=1;
	  for (int i=1;i<=q;i++)
	  {
	  	bj=0;
	  	for (int j=1;j<=n;j++)
	  	 {
	  	 	hh=a[j];
	  	 	for (int s=1;s<=b[i][1];s++)
	  	 	   c*=10;
	  	 	h=hh%c;
	  	 	if (h==b[i][2]&&bj==0)
	  	 	{
	  	 		fout<<a[j]<<endl;
	  	 		h=0;
	  	 		bj=1;
	  	 		c=1;
	  	 		break;
	  	 	} 
	  	 	h=0;
	  	 	c=1;
	  	 }
	  	 if (bj==0) fout<<-1<<endl;
	  }
	  fin.close();
	  fout.close();
	  return 0;	 
}
