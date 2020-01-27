//��֦��
//1.֪���ֺܷ��ܳ���������������б�����ʤ����ƽ��������ʱ�������ֵ�򷵻�0
//2.���仯����������ĳ���˵����г��κ�����������ж�ʣ�������С�����ųɵ������Ѿ��ѹ��ˣ���ô����ֱ�ӷ����ϴ��ѵ���ֵ���������Hash����100pts��
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define maxn 12
#define base 19260817
#define mod 1000000007
using namespace std;
map<unsigned long long,long long>used;
int n;
int sum3,sum1;//3�ĳ�����1�ĳ��� 
int a[maxn];//Ŀ�� 
int b[maxn];//��ǰÿ�к� 
int delta[maxn];//��ǰ����Ŀ��Ĳ� 
int cmp(int x,int y){
	return x>y;
}
long long dfs(int x,int y){
	if(x>=n) return 1;
	if(y>n){
		if(b[x]!=a[x]) return 0;//��֤ǰx��һ�������õ� 
		for(int i=1;i<=n;i++){
			delta[i]=a[i]-b[i];
		} 
		sort(delta+x+1,delta+n+1);
		unsigned long long hash=0;
		for(int i=x+1;i<=n;i++){//hash֮����� 
			hash=hash*base+delta[i];
		}
		if(used.count(hash)) return used[hash];
		else{
			used[hash]=dfs(x+1,x+2);
			return used[hash];
		}
	}
	long long ans=0;
	if(b[x]+3<=a[x]&&sum3){
		b[x]+=3;
		sum3--;
		ans+=dfs(x,y+1);
		b[x]-=3;
		sum3++;
	}
	if(b[y]+3<=a[y]&&sum3){
		b[y]+=3;
		sum3--;
		ans+=dfs(x,y+1);
		b[y]-=3;
		sum3++;
	}
	if(b[x]+1<=a[x]&&b[y]+1<=a[y]&&sum1){
		b[x]++;
		b[y]++;
		sum1--;
		ans+=dfs(x,y+1);
		b[x]--;
		b[y]--;
		sum1++;
	}
	return ans%mod;
}
int main(){
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	sum3=sum-n*(n-1);
	sum1=n*(n-1)/2-sum3;
	cout<<dfs(1,2)%mod;
}
