//luogu 3657 
//������Ȼ���Կ����Ǳ��ֵ�LCS
//dp[i][j]��ʾ����aǰi��������bǰj����������
//dp[i][j]=max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1](abs(a[i]-b[j])<=4))
//����LISתLCS��ԭ���ķ����Ǽ�¼a[i]��ÿ��ֵ��λ��pos,��b[i]ת��Ϊpos[b[i]] 
//��Ȼ (abs(a[i]-b[j])<=4���ɱ���������ȡ�
//�����Ƕ���ÿ��b[i]��j (0<=j<=4),��pos[b[i]��j]��������c,��c��LIS��Ϊ��
//��ע�⵽ÿ����ֻ����һ���ߣ�Ҳ���Ƕ���ÿ��b[i]��9��b[i]��j��ֻ��ѡһ������LIS
//���Խ�9��һ��Ӵ�С������ƴ����������ÿ������������һ������ѡ��LIS������ѡ��������c[i]>c[i+1],ì�ܣ�   
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100005
using namespace std;
int n;
int a[maxn],b[maxn];
int pos[maxn];
vector<int>tmp;
vector<int>c;
int s[maxn*9];
int m;
int cmp(int x,int y) {
	return x>y;
}
int solve() {
	for(int i=1;i<=n;i++){
		tmp.clear();
		for(int j=0;j<=4;j++){
			if(b[i]+j<=n) tmp.push_back(pos[b[i]+j]);
			if(b[i]-j>=1) tmp.push_back(pos[b[i]-j]);
		}
		sort(tmp.begin(),tmp.end(),cmp);
		int t=tmp.size();
		for(int j=0;j<t;j++){
			c.push_back(tmp[j]);
		}
	}
	int m=c.size();
//	for(int i=0;i<m;i++) printf("%d ",c[i]);
//	printf("\n");
	int top=0;
	for(int i=0; i<m; i++) {
		if(c[i]>s[top]) {
			s[++top]=c[i];
		} else {
			int tmp=lower_bound(s+1,s+1+top,c[i])-s;
			s[tmp]=c[i];
		}
	}
	return top;
}

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&b[i]);
	}
	printf("%d\n",solve());
}
