//treasure
#include<iostream>
#include<cstring>
#include<cstdio> 
#define maxn 10002
#define maxm 102
using namespace std;
long long ans=0;
int n,m,r;
struct room {
	int s;
	int x;
} a[maxn][maxm];
int stair[maxn]; //��¼ÿ����¥�ݵķ�����
int main() {
	//int i,j;
    freopen("treasure10.in","r",stdin);
	memset(stair,0,sizeof(stair));
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int u=1; u<=n; u++) {
		for(int v=1; v<=m; v++) {
			cin>>a[u][v-1].s>>a[u][v-1].x;
			if(a[u][v-1].s==1) stair[u]++;
		}
	}
	cin>>r;
	int j=r,i=1,k;
	while(i<=n) {
		ans=(ans+a[i][j].x)%20123;//������ȡģ����ֹ�м������
		int p=j;
		k=0;
		int t=a[i][j].x%stair[i];
		/*�ǳ���Ҫ��һ������,û�л�TLE
		  ������ÿһ��ת�Ĵ��� ���籾Ӧ�ҵ�10�����ò���3����¥�ݵķ��� ����ֱ���ҵ�1��
		 ������ʱ�临�Ӷȣ�������O��n*m�������Գ��ܡ�
		 */
		if(t==0) t=stair[i];
		while(k<t) {
			if(a[i][p].s==1) k++;
			if(p==m-1&&k!=t) p=0;//����ѭ��
			else if(k!=t) p++;
		}
		j=p;
		i++;
	}
	cout<<ans%20123<<endl;
	return 0;
}
