#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=305,mo=1e9+7;
int n,m,k,i,x,j,a[N],la,ans;
int C[N][N],fact[N];
void init(){
	for (i=0;i<=n;i++) for (C[i][0]=1,j=1;j<=i;j++)
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	for (fact[0]=1,i=1;i<=n;i++)
		fact[i]=(ll)fact[i-1]*i%mo;
}
int main(){
	freopen("shit.in","r",stdin);
	freopen("shit.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);init();
	for (i=1;i<=n;i++) for (x=1,la=0;x<=n;x++){
		m=min(n,x+k-1);int sum=0;
		for (j=m-x;j<m;j++)
			sum=(sum+(ll)C[n-i][j]*C[i-1][m-1-j])%mo;
		/*
		����i��ʱ��i+k-1����
		��ȡ��ǰiС����
		����˵ǰiС����һ���ᱻȡ��
		��ʽ��
		mΪ��ǰ��x�ֵ�������
		������i�����������ڵ���m-xʱ
		i��ǰxС��
		�ó���sumΪi��ǰx�ֱ�ȡ�ߵ������ 
		*/
		sum=(ll)sum*fact[m]%mo*fact[n-m]%mo;
		ans=(ans+(ll)(sum-la+mo)*(n+1-x)*a[i])%mo;la=sum;
	}
	printf("%d",ans);
}
