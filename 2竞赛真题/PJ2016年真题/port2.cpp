//��� ���� 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100050
using namespace std;
int n,ans,head;
struct boat {
	int t;
	int num;
} a[maxn];
int x[3*maxn]; 
int sum[maxn];
int nation[maxn];
int main() {
	int cnt=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].t>>a[i].num;
		for(int j=1; j<=a[i].num; j++) cin>>x[++cnt];
		sum[i]=sum[i-1]+a[i].num;//��¼���ô�ʱ��������
	}
	head=1;
	for(int i=1; i<=n; i++) {
		//�������24Сʱ���� 
		while(a[i].t-a[head].t>=86400) {
			for(int j=sum[head-1]+1; j<=sum[head]; j++) {
				nation[x[j]]--;
				if(nation[x[j]]==0) ans--;
			}
			head++;
		}
		//û�г���24Сʱ�����ϵ��˼���������ͳ�� 
		for(int j=sum[i-1]+1; j<=sum[i]; j++) { 
			nation[x[j]]++;
			if(nation[x[j]]==1)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

