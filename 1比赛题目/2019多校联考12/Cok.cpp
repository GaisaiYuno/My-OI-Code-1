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
	for(int deep=1;deep<=n;deep++){//ģ����Ź��� 
		int p=randint(l,r);
		if(id[p]==top){
			//���ǰ���top��λ���Ѿ���ȷ��,��ô���ֵ����������.���ֵ������ 
			ans[id[p]]=maxv--;
			swap(id[p],id[l]);
			swap(id[l],id[r]);//��Сֵ�ŵ�r��λ�� 
			r--;
		}else{
			//���������Сֵ�����ֵ�ǰ��Ŀ�λȥ 
			ans[id[p]]=minv++;
			swap(id[p],id[l]);//��Сֵ�ŵ�l��λ�� 
			l++;
		}
		while(ans[top]) top++;//�ҵ���һ����û��ȷ����λ�� 
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]); 
}

