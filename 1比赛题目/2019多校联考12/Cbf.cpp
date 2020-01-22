#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000 
#define mod 99824353
using namespace std;


int n;
long long A,B;
long long X=1;
int randint(int L,int R) {
	X=(X*X+A*X+B)%99824353LL;
	return X%(R-L+1)+L;
}
int maxd=0;
void Qsort(int A[],int L,int R,int deep) {
	maxd=max(maxd,deep);
	if(L>=R)return ;
	int l=L;
	int r=R;
	int index=randint(L,R);
	int key=A[index];
	std::swap(A[l],A[index]);
	while(l<r) {
		while(l<r&&A[r]>=key)--r;
		A[l]=A[r];
		while(l<r&&A[l]<=key)++l;
		A[r]=A[l];
	}
	A[l]=key;
	Qsort(A,L,l-1,deep+1);
	Qsort(A,l+1,R,deep+1);
}

int id[maxn+5];
int tmp[maxn+5];
int ans[maxn+5]; 
int main() {
	scanf("%d %lld %lld",&n,&A,&B);
	if(n>20){
		for(int i=n;i>=1;i--) printf("%d ",i);
		return 0;
	}
	for(int i=1;i<=n;i++) id[i]=i;
	int res=0;
	do{
		maxd=0;
		X=1;
		for(int i=1;i<=n;i++) tmp[i]=id[i];
		Qsort(tmp,1,n,1);
		if(maxd>=res){
			for(int i=1;i<=n;i++) ans[i]=id[i];
			res=maxd;
		}
	}while(next_permutation(id+1,id+1+n));
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}

