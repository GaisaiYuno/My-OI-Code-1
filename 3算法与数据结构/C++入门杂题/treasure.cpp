//treasure
#include<iostream>
#include<cstring>
#define maxn 10001
#define maxm 101
using namespace std;
//long long ans=0;
int n,m,r;
struct room {
	int s;
	int x;
} a[maxn][maxm];
int stair[maxn]; //��¼ÿ����¥�ݵķ�����
int main() {
	//int i,j;
	memset(stair,0,sizeof(stair));
	cin>>n>>m;
	for(int u=1; u<=n; u++) {
		for(int v=1; v<=m; v++) {
			cin>>a[u][v-1].s>>a[u][v-1].x;
			if(a[u][v-1].s==1) stair[u]++;
		}
	}
	cin>>r;
	int jj=r,ii=1,ans=0,t;
	while(ii<=n) {
		ans=(ans+a[ii][jj].x)%20123;//������ȡģ����ֹ�м������
		int tt=jj;
		t=0;
		int c=a[ii][jj].x%stair[ii];
		/*�ǳ���Ҫ��һ������,û�л�TLE
		  ������ÿһ��ת�Ĵ��� ���籾Ӧ�ҵ�10�����ò���3����¥�ݵķ��� ����ֱ���ҵ�1��
		 ������ʱ�临�Ӷȣ�������O��n*m�������Գ��ܡ�
		 */
		if(c==0) c=stair[ii];
		while(t<c) {
			if(a[ii][tt].s==1) t++;
			if(tt==m-1&&t!=c) tt=0;//����ѭ��
			else if(t!=c) tt++;
		}
		jj=tt;
		ii++;
	}
	cout<<ans%20123<<endl;
	return 0;
}
