#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,a[1010];
int i,j,g,s,bai,q,w,sw,bw,qw,sum,qq;
struct data{
	int len;
	int xu;
};
bool ab(data a,data b)
{
	if (a.len>b.len) return false;
	if (a.len==b.len&&a.xu>b.xu) return false;
	return true;
}
data b[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=m;i++)
	 cin>>b[i].len>>b[i].xu;
	sort(a+1,a+n+1);
	//sort(b+1,b+m+1,ab);
	
	for (i=1;i<=m;i++)                          // 第i个读者 
	{
		int bb=false;
		  for (j=1;j<=n;j++)                   //第j本图书 
		  {
		  	  g=a[j]%10;                      //拆分 
		      s=a[j]%100/10;
		    bai=a[j]%1000/100;
		      q=a[j]%10000/1000;
		      w=a[j]%100000/10000;
		     sw=a[j]%1000000/100000;
		     bw=a[j]%10000000/1000000;
		     qw=a[j]/100000000;
		  	 
		  	 if (b[i].len==1) sum=g;
		     if (b[i].len==2) sum=s*10+g;
		     if (b[i].len==3) sum=bai*100+s*10+g;
		     if (b[i].len==4) sum=q*1000+bai*100+s*10+g;
		     if (b[i].len==5) sum=w*10000+q*1000*bai*100+s*10+g;
		     if (b[i].len==6) sum=sw*100000+w*10000+q*1000*bai*100+s*10+g;
		     if (b[i].len==7) sum=bw*1000000+sw*100000+w*10000+q*1000*bai*100+s*10+g;
		     if (b[i].len==8) sum=qw*10000000+bw*1000000+sw*100000+w*10000+q*1000*bai*100+s*10+g;
		  	 
		  	 if (sum==b[i].xu)
		  	 {
		  	 	cout<<a[j]<<endl;
		  	 	bb=true;
		  	 	break;
		  	 }
		  }
		  if (bb==false) cout<<-1<<endl;
	}
	
	
	return 0;
}
