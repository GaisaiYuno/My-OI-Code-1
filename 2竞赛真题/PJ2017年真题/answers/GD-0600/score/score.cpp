#include<cstdio>
using namespace std;
FILE *fin=fopen("score.in","rb"),*fout=fopen("score.out","wb");
int a,b,c;
int main()
{
	fscanf(fin,"%d%d%d",&a,&b,&c);
	fprintf(fout,"%d",a*2/10+b*3/10+c*5/10);
	fclose(fin);fclose(fout);
	return 0;
}
