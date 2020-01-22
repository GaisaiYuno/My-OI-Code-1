#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn],b[maxn];
int pa,pb;
long long sa,sb;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	pa=n;
	pb=n;
	while(!(pa==0&&pb==0)){
		if(a[pa]>=b[pb]){
			sa+=a[pa];
			pa--;
		}else{
			pb--;
		}
		if(b[pb]>=a[pa]){
			sb+=b[pb];
			pb--;
		}else{
			pa--;
		}
	} 
	printf("%I64d",sa-sb);
}
