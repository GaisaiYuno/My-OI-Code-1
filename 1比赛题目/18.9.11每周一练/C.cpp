#include<iostream>
#include<cstdio>
#define maxn 500005
#define maxv 1000005
using namespace std;
int n,k;
int a[maxn];
int cnt[maxv];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int l=1,r=0;
	int ansl=1,ansr=k;
	int nowk=0;
	//��ȡ�� 
	while(r<n){
		r++;//�̶���˵�,�Ҷ˵���ǰ�� 
		if(!cnt[a[r]]) nowk++;
		cnt[a[r]]++;
		while(nowk>k){//���ֲ��������������,��˵���ǰ 
			cnt[a[l]]--;
			if(!cnt[a[l]]) nowk--;
			l++; 
		}
		if(ansr-ansl+1<r-l+1){
			ansl=l;
			ansr=r;
		}
	}
	printf("%d %d\n",ansl,ansr);
} 
