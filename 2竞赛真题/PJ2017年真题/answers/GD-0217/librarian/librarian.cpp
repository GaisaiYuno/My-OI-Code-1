#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(string a,string b)
{
	if (a.length()==b.length()) return a<b;
	return a.length()<b.length();
}

int n,q,len,k,l,cs;
string bh[1005],st;
bool pd;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);

	cin>>n>>q;
	for (int i=1;i<=n;++i)
	 cin>>bh[i];
	sort(bh+1,bh+n+1,cmp);
	for (int i=1;i<=q;++i)
	 {
	 	cin>>len>>st;
	 	pd=true;
	 	for (int j=1;j<=n;++j)
	 	 {
	 	 	if (bh[j].length()<len) continue;
	 	 	k=bh[j].length()-1;
			l=len-1;
			cs=0;
			while (bh[j][k]==st[l]&&k>=0&&l>=0) ++cs,k--,l--;
			if (cs==len)
			 {
			 	cout<<bh[j]<<endl;
			 	pd=false;
			 	break;
			 }
	 	 }
	 	if (pd) cout<<-1<<endl;
	 }
	return 0;
}
