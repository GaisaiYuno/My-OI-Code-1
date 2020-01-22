#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
FILE *fin=fopen("jump.in","rb"),*fout=fopen("jump.out","wb");
int n,i,c,s,q,w,d,j,k;
int main()
{
	fscanf(fin,"%d%d%d%d%d",&n,&d,&c,&q,&k);
	w=q;j=max(j,abs(q-w-d));
	c-=k;
	for(i=2;i<=n;i++)
	{
		fscanf(fin,"%d%d",&q,&k);
		c-=(k>0)?k:0;
		j=max(j,abs(q-w-d));
		w=q;
	}
	if (c>0) fprintf(fout,"-1");
	else fprintf(fout,"%d",j);
	fclose(fin);fclose(fout);
	return 0;
}
