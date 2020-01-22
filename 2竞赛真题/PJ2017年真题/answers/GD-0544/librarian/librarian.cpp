#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,f,n2[1023],ne = 0;
	scanf( "%d%d",&n,&q );
	memset( n2,-1,sizeof(n2) );
	int n1[1023],a1[1023],a2[1023];
	for( i = 0;i < n;i++ )	scanf( "%d",&n1[i] );
	for( i = 0;i < n;i++ )	for( int k = 0;k < n;k++ )	if( n1[k] > n1[k+1] )	swap( n1[k],n1[k+1] );
	for( i = 0;i < q;i++ )	scanf( "%d%d",&a1[i],&a2[i] );
	for( i = 0;i < n;i++ )
	{
		for( int j = 0;j < q;j++ )
		{
			int z = 1;
			for( int m = 0;m < a1[j];m++ )	z *= 10;
			if( n1[i] % z == a2[j] )
			{
				n2[i] = n1[i];
				break;
			}
		}
	}
	for( i = 0;i < q;i++ )	cout << n2[i] << endl;
	return 0;
}
