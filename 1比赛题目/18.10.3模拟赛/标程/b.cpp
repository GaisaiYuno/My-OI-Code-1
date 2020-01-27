#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	long long int sum;
	int v,num;
	int lvl;
};
long long int n,ans,minlen=1e11;
node a[200200];
bool cmp1(node x,node y){
	if(x.sum==y.sum) return x.v>y.v;
	return x.sum<y.sum; 
}
bool cmp2(node x,node y){
	if(x.num==y.num) return x.v>y.v;
	return x.num<y.num; 
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	
	//num����֮�������»�ԭ 
	for(int i=1;i<=n;i++){
		long long int tl,tr;
		scanf("%lld%lld",&tl,&tr);
		a[(i<<1)-1].sum=tl; a[(i<<1)-1].v=1;
		a[i<<1].sum=tr; a[i<<1].v=-1;
		a[(i<<1)-1].num=a[i<<1].num=i;
	}
	n<<=1;
	sort(a+1,a+n+1,cmp1);
	
	//���ò�����ҵ���̵����� 
	long long int now=0,lastp=0;
	for(int i=1;i<=n;i++){
		int temp=a[i].v;
		a[i].lvl=now; 
		while(a[i+1].sum==a[i].sum){
			i++;
			a[i].lvl=now;
			temp+=a[i].v;
		}
		if(now>=1) ans+=a[i].sum-lastp;
		if(now==1) minlen=min(minlen,a[i].sum-lastp);
		lastp=a[i].sum;
		now+=temp;
	}
	
	//�ж���û�б���ȫ����ס�ı� 
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i+=2){
		if(a[i].lvl>1 && a[i+1].lvl>1){
			cout<<ans<<endl;
			return 0;
		}
	}
	
	//cout<<ans<<ends<<minlen<<endl;
	if(minlen==1e11) cout<<ans<<endl;
	else cout<<ans-minlen<<endl;
	return 0;
}

/*

����1�����ִ�+���ö�٣�

 
����2������ֱ�Ӳ��...?

3
1 5
6 9
3 7

*/
