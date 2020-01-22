#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#define maxn 105
#define cin fin
using namespace std;
int n,k;
int t[maxn],LIS1[maxn],LIS2[maxn];
int ans1,ans2,ans;
int answer;
ifstream fin,fans;
char a[]="chorus.in";
char b[]="chorus.ans";
int main() {
	int tot=0;
	for(int u=1; u<=10; u++) {
		//a[6]=u+'0';
		//b[6]=u+'0';
		fin.open(a);
		fans.open(b);
//		freopen("chorus2.in","r",stdin);
//		freopen("chorus.out","w",stdout);
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) cin>>t[i];
		memset(LIS1,0,sizeof(LIS1));
		memset(LIS2,0,sizeof(LIS2));
		for(int i=1; i<=n; i++) {
			LIS1[i]=1;
			for(int j=1; j<i; j++) {
				if(t[i]>t[j]) LIS1[i]=max(LIS1[i],LIS1[j]+1);
			}
		}
		for(int i=n; i>=1; i--) {
			LIS2[i]=1;
			for(int j=i+1; j<=n; j++) {
				if(t[i]>t[j]) LIS2[i]=max(LIS2[i],LIS2[j]+1);
			}
		}
		for(int top=1; top<=n; top++) {
			ans=max(ans,LIS1[top]+LIS2[top]-1);
		}
//		cout<<n-ans;
		
		fans>>answer;
		fin.close();
		fans.close();
		printf("for data #%d: [%s]\n",u,a);
		if(n-ans==answer) {
			tot+=10;
			cout<<"AC!"<<endl;
			printf("read %d,expected %d\n",n-ans,answer);
		} else {
			cout<<"WA!"<<endl;
			printf("read %d,expected %d\n",n-ans,answer);
			cout<<endl;
			printf("input data is:\n");
			cout<<n<<endl;
			for(int i=1; i<=n; i++) cout<<t[i]<<' ';
			cout<<endl;
		}
		cout<<"------------------------------------------------"<<endl;
		cout<<endl;
		cout<<endl;
	}
	printf("your score=%d\n",tot);

}
