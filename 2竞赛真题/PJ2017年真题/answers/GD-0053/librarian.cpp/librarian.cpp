#include<cstdio>
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,max=0,p,o;
	scanf("%d%d",&n,&q);
	int a[1005]={},b[1005]={},c[1005]={};
	for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	    if(a[i]>max) max=a[i];
	}
	o=max;
	for(i=0;i<q;i++)
	{
	    scanf("%d",&b[i]);
	    scanf("%d",&c[i]);
	    p=1;
	    for(int j=0;j<b[i];j++)
	    	p*=10;
	    b[i]=p;
	}
	for(int j=0;j<q;j++)
	{
	    max=o;
	    for(i=0;i<n;i++)	
		    if(a[i]%b[j]==c[j]&&a[i]<max) 
			    max=a[i];
		if(max!=o) printf("%d\n",max);
		else
		{
		    if(o%b[j]==c[j]) printf("%d\n",o);
		    else printf("-1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
