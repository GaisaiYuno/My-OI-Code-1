#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d,k,x[500010]={0},s[500010],a[500010];
int rd(){
	char c=getchar();int fu=1,x=0;
	for(;c<'0'||c>'9';c=getchar())
		if(c=='-')
			fu=-1;
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-'0';
	return x*fu;
}
int f(int step){
	int fl=max(d-step,1),fr=d+step;
	memset(a,-0x3f,sizeof(a));
	a[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;~j;j--)
			if(x[i]-x[j]>=fl&&x[i]-x[j]<=fr)
				a[i]=max(a[i],a[j]+s[i]);
			else if(x[i]-x[j]<=fr)
				break;
		if(a[i]>=k)
			return true;
	}
	return false;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=rd();d=rd();k=rd();
	int check=0,mindist=0x3f3f3f3f,maxdist=0,minn=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		x[i]=rd();s[i]=rd();
		if(s[i]>0)
			check+=s[i];
		else
			minn=max(minn,s[i]);
		mindist=min(mindist,x[i]-x[i-1]);
		maxdist=max(maxdist,x[i]-x[i-1]);
	}
	if((check>0&&check<k)||(check==0&&minn<k)){
		puts("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int l=0,r=x[n];
	while(l<r){
		int mid=(l+r)>>1;
		if(f(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d\n",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
