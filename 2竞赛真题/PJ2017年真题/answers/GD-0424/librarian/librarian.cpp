#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
int n,q,i,j,k,l,le[1001],a1[1001];
string a[1001],s;
bool b;
void qs(int l,int h)
{
	int i=l,j=h;
	int mid1=a1[(l+h)/2],t1;
	string t;
	if (l>=h) return;
	do
	{
		while (a1[i]<mid1) i++;
		while (a1[j]>mid1) j--;
		if (i<=j)
		{
			t1=a1[i];a1[i]=a1[j];a1[j]=t1;
			t1=le[i];le[i]=le[j];le[j]=t1;
			t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}
	while (i<=j);
	qs(i,h);
	qs(l,j);
}
int main()
{
	ifstream fin("librarian.in");
	ofstream fout("librarian.out");
	fin>>n>>q;
	for (i=1;i<=n;i++)
	{
		fin>>a[i];
		a1[i]=atoi(a[i].c_str());
		le[i]=a[i].length()-1;
	}
	qs(1,n);
	for (i=1;i<=q;i++)
	{
		fin>>l>>s;
		for (j=1;j<=n;j++)
		{
			b=0;
			for (k=le[j]-l+1;k<=le[j];k++)
			if (k<0||a[j][k]!=s[k-le[j]+l-1])
			{
				b=1;
				break;
			}
			if (!b)
			{
				fout<<a[j]<<endl;
				break;
			}
		}
		if (b)
		fout<<-1<<endl;
	}
	return 0;
	//RP++
}
