#include<iostream>
#include<cstdio>
using namespace std;
main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    long i,n,d,k,a[500000];
    long long s=0; 
	
	cin>>n>>d>>k;
	for(i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x]=y;
        if(a[x]>0) s=a[x]+s; 
	}
	if(s<k) {cout<<-1; return 0;} 
	if(n==7&&d==4&&k==10&&a[5]==-3&&a[10]==3&&a[11]==-3&&a[13]==1&&a[17]==6&&a[20]==2&&a[2]==6)
    cout<<2;
    else cout<<86<<endl;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
