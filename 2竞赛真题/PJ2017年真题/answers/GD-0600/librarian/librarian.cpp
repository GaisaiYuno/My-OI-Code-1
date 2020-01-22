#include<cstdio>
using namespace std;
FILE *fin=fopen("librarian.in","rb"),*fout=fopen("librarian.out","wb");
int q,n,a[1001],i,j,c,l,t,bj,ll,ss;
void qs(int l,int r)
{
	int i=l,j=r,mis=a[(l+r)/2];
	while (i<=j)
	{
		while(i<=r&&a[i]<mis) i++;
		while(j>=l&&a[j]>mis) j--;
		if (i<=j)
	    {
	    	c=a[i];
	    	a[i]=a[j];
	    	a[j]=c;
	    	i++;j--;
	    }
	}
	if (i<r) qs(i,r);
	if (j>l) qs(l,j);
}
int main()
{
	fscanf(fin,"%d%d",&q,&n);
	for(i=1;i<=q;i++)
		fscanf(fin,"%d",&a[i]);
	qs(1,q);
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%d%d",&l,&t);
		bj=0;
		for(j=1;j<=q;j++)
		{
			c=t;ll=l;ss=a[j];
			while(ss%10==c%10&&ll>0)
			{
				ss/=10;c/=10;ll--;
			}
			if (ll==0)
			{
				fprintf(fout,"%d\n",a[j]);
				bj=1;
				break;
			}
		}
		if (bj==0) fprintf(fout,"-1\n");
	}
	fclose(fin);fclose(fout);
	return 0;
}
