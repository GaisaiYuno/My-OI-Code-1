#include<iostream>
#include<cstdio>
using namespace std;
struct data{
	int far,score;
};
int main()
{
	int n,m,b,s,x,sum;
	data a[50001];
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>m>>b;
	for (int i=1;i<=n;++i) cin>>a[i].far>>a[i].score;
	for (int i=0;i<=a[n].far/2;++i) 
	{
		s=m+i;
		x=0;
		sum=0;
		j=0;
        whlie (j<=n)
        {
        	++j
        	if ((a[j].far<=x+s)&&(a[j].score>=0)) {x=a[j].far; sum=sum+a[j].score;}
        	if ((a[j+1].far<=x+s)&&(a[j].score<0)) {x=a[j+1].far; sum=sum+a[j+1].score; ++j;}
        }
        if (sum>b) {cout<<sum; return 0;}
}
    cout<<-1;
	fclose(stdin);
	fclose(stdout);
}
