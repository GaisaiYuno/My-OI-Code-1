#include<iostream>
#include<cstring>
#include<map>
#define maxn 3005
using namespace std;
long long a[maxn];
map<long long,int>m;
inline long long fastread(){
	long long x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n;
int main(){
	while(cin>>n){
		m.clear();
		for(int i=1;i<=n;i++){
		    a[i]=fastread();
		    m[a[i]]++; 
		}
		std::map<long long,int>::iterator it;
		int ans=0;
		for(it=m.begin();it!=m.end();it++){
			ans=max(ans,it->second);
		}
		cout<<ans<<endl;
	}
}
