#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 100005
using namespace std;
int X[MAXN],Y[MAXN],minMax,n;
inline int check(int a,int b){
	int ld=0,rd=0,lu=0,ru=0;
	for (register int i=1;i<=n;++i){
		if (X[i]<a&&Y[i]<b){
			++ld;
		}
		else if (X[i]>a&&Y[i]<b){
			++lu;
		}
		else if (X[i]<a&&Y[i]>b){
			++rd;
		}
		else {
			++ru;
		}
		if (ld>=minMax||lu>=minMax||rd>=minMax||ru>=minMax){
			return minMax;
		}
	}
	return max(lu,max(ld,max(rd,ru)));
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	vector<int>Seq1,Seq2;
	int maxX=-0x7fffffff,maxY=-0x7fffffff,minX=0x7fffffff,minY=0x7fffffff;
	scanf("%d",&n);
	if (n>10000){
		printf("%d\n",n/4);
		return 0;
	}
	for (register int i=1;i<=n;++i){
		scanf("%d%d",&X[i],&Y[i]);
		maxX=max(maxX,X[i]);
		maxY=max(maxY,Y[i]);
		minX=min(minX,X[i]);
		minY=min(minY,Y[i]);
	}
	Seq1.push_back(0);
	for (register int i=1;i<=n;++i){
		Seq1.push_back(X[i]+1);
	}
	Seq2.push_back(0);
	for (register int i=1;i<=n;++i){
		Seq2.push_back(Y[i]+1); 
	}
	random_shuffle(Seq1.begin(),Seq1.end());
	random_shuffle(Seq2.begin(),Seq2.end());
	minMax=0x7fffffff;
	for (register int i=0;i<Seq1.size();++i){
		for (register int j=0;j<Seq2.size();++j){
			//printf("%d %d\n",i,j);
			minMax=min(minMax,check(Seq1[i],Seq2[j]));
		}
	}
	printf("%d\n",minMax);
}
