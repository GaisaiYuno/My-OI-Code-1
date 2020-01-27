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

int id[maxn+5];
int ans[maxn+5];
int main() {
	scanf("%d %lld %lld",&n,&A,&B);
	for(int i=1;i<=n;i++) id[i]=i;
	int l=1,r=n,top=1,minv=1,maxv=n;
	for(int deep=1;deep<=n;deep++){//模拟快排过程 
		int p=randint(l,r);
		if(id[p]==top){
			//如果前面的top个位置已经都确定,那么最大值就填在这里.让字典序最大 
			ans[id[p]]=maxv--;
			swap(id[p],id[l]);
			swap(id[l],id[r]);//最小值排到r的位置 
			r--;
		}else{
			//否则就填最小值，最大值填到前面的空位去 
			ans[id[p]]=minv++;
			swap(id[p],id[l]);//最小值排到l的位置 
			l++;
		}
		while(ans[top]) top++;//找到第一个还没被确定的位置 
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]); 
}

