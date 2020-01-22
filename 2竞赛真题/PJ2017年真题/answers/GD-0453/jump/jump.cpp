#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
struct gezi{
	int ju,fen;
};
gezi feiji[1000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,s=0;
	scanf("%d %d %d",&n,&d,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&feiji[i].ju,&feiji[i].fen);
		if(feiji[i].fen>0) s+=feiji[i].fen;
	}
	if(s<k) cout<<"-1";
	else cout<<k;
	return 0;
}
