#include<cstdio>
#include<cstring>
using namespace std;
const int N=2020,P1=1000000007,P2=1000000009; 
int i,j,k,n,m,ans,fg;
int tm1[N],tm2[N],tm1_[N],tm2_[N];
int f[2][N][N];
struct dd
{
	int x,y;
	bool operator == (const dd &n) const
	{
		return x==n.x && y==n.y;
	}
} t1,t2,t3,t4;
struct cc
{
	char s[N];
	int len;
	int pre1[N],pre2[N],suf1[N],suf2[N];
	void read()
	{
		int i;
		scanf("%s",s+1);
		len=strlen(s+1);
		for (i=1;i<=len;i++)
		{
			pre1[i]=(1ll*tm1[i-1]*(s[i]-'a'+1)+pre1[i-1])%P1;
			pre2[i]=(1ll*tm2[i-1]*(s[i]-'a'+1)+pre2[i-1])%P2;
		}
		for (i=len;i;i--)
		{
			suf1[i]=(1ll*tm1[len-i]*(s[i]-'a'+1)+suf1[i+1])%P1;
			suf2[i]=(1ll*tm2[len-i]*(s[i]-'a'+1)+suf2[i+1])%P2;
		}
	}
	dd get_hash(int l,int r)
	{
		dd t;
		if (l<=r)
		{
			t.x=(1ll*tm1_[l-1]*(pre1[r]+P1-pre1[l-1]))%P1;
			t.y=(1ll*tm2_[l-1]*(pre2[r]+P2-pre2[l-1]))%P2;
			return t;
		}
		t.x=(1ll*tm1_[len-l]*(suf1[r]+P1-suf1[l+1]))%P1;
		t.y=(1ll*tm2_[len-l]*(suf2[r]+P2-suf2[l+1]))%P2;
		return t;
	}
} s1,s2,w;
int ksm(int x,int y,int P)
{
	int z=1;
	for (;y;y>>=1,x=1ll*x*x%P) if (y&1) z=1ll*z*x%P;
	return z;
}
void init()
{
	int i,n=2000;
	tm1[0]=tm2[0]=tm1_[0]=tm2_[0]=1;
	for (i=1;i<=n;i++) tm1[i]=31ll*tm1[i-1]%P1,tm2[i]=31ll*tm2[i-1]%P2;
	tm1_[n]=ksm(tm1[n],P1-2,P1);
	tm2_[n]=ksm(tm2[n],P2-2,P2);
	for (i=n-1;i;i--) tm1_[i]=31ll*tm1_[i+1]%P1,tm2_[i]=31ll*tm2_[i+1]%P2;
	s1.read();
	s2.read();
	w.read();
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	init();
	n=s1.len;
	m=w.len;
	f[0][n+1][0]=f[1][n+1][0]=1;
	for (i=n;i;i--)
	{
		f[0][i][0]=f[1][i][0]=1;
		for (k=2;k+k<=m && i+k-1<=n;k++)
		{
			t1=s1.get_hash(i,i+k-1);t2=s2.get_hash(i,i+k-1);
			t3=w.get_hash(m,m-k+1);t4=w.get_hash(m-k-k+1,m-k);
			if (t1==t3 && t2==t4) f[1][i][k+k]=1;
			if (t2==t3 && t1==t4) f[0][i][k+k]=1;
		}
	}
	for (i=n;i;i--)
		for (k=1;k<=m;k++)
		{
			if (s1.s[i]==w.s[m-k+1]) (f[0][i][k]+=f[0][i+1][k-1])%=P1;
			if (s2.s[i]==w.s[m-k+1]) (f[1][i][k]+=f[1][i+1][k-1])%=P1;
			if (k>1 && s1.s[i]==w.s[m-k+1] && s2.s[i]==w.s[m-k+2]) (f[0][i][k]+=f[1][i+1][k-2])%=P1;
			if (k>1 && s2.s[i]==w.s[m-k+1] && s1.s[i]==w.s[m-k+2]) (f[1][i][k]+=f[0][i+1][k-2])%=P1;
		}
	for (i=1;i<=n+1;i++)
	{
		(ans+=f[0][i][m])%=P1;
		(ans+=f[1][i][m])%=P1;
		for (k=2;k+k<=m && k<i;k++)
		{
			t1=s1.get_hash(i-k,i-1);t2=s2.get_hash(i-k,i-1);
			t3=w.get_hash(k,1);t4=w.get_hash(k+1,k+k);
			if (t1==t3 && t2==t4) (ans+=f[1][i][m-k-k])%=P1;
			if (t2==t3 && t1==t4) (ans+=f[0][i][m-k-k])%=P1;
		}
	}
	if (m==1) return printf("%d\n",ans),0;
	memset(f,0,sizeof f);
	f[0][n+1][0]=f[1][n+1][0]=1;
	for (i=n;i;i--)
	{
		f[0][i][0]=f[1][i][0]=1;
		for (k=2;k+k<m && i+k-1<=n;k++)
		{
			t1=s1.get_hash(i,i+k-1);t2=s2.get_hash(i,i+k-1);
			t3=w.get_hash(1,k);t4=w.get_hash(k+k,k+1);
			if (t1==t3 && t2==t4) f[1][i][k+k]=1;
			if (t2==t3 && t1==t4) f[0][i][k+k]=1;
		}
	}
	for (i=n;i;i--)
		for (k=1;k<=m;k++)
		{
			if (s1.s[i]==w.s[k]) (f[0][i][k]+=f[0][i+1][k-1])%=P1;
			if (s2.s[i]==w.s[k]) (f[1][i][k]+=f[1][i+1][k-1])%=P1;
			if (m>2 && k>1 && s1.s[i]==w.s[k] && s2.s[i]==w.s[k-1]) (f[0][i][k]+=f[1][i+1][k-2])%=P1;
			if (m>2 && k>1 && s2.s[i]==w.s[k] && s1.s[i]==w.s[k-1]) (f[1][i][k]+=f[0][i+1][k-2])%=P1;
		}
	for (i=1;i<=n+1;i++)
	{
		(ans+=f[0][i][m])%=P1;
		(ans+=f[1][i][m])%=P1;
		for (k=2;k+k<m && k<i;k++)
		{
			t1=s1.get_hash(i-k,i-1);t2=s2.get_hash(i-k,i-1);
			t3=w.get_hash(m-k+1,m);t4=w.get_hash(m-k,m-k-k+1);
			if (t1==t3 && t2==t4) (ans+=f[1][i][m-k-k])%=P1;
			if (t2==t3 && t1==t4) (ans+=f[0][i][m-k-k])%=P1;
		}
	}
	printf("%d\n",ans);
}
