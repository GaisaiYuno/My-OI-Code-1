#include<iostream>
#include<cstdio>
#define maxn 200005
using namespace std;
int n;
int a[maxn];
int b[maxn];
int t[maxn];
//void solve(int a,int b,int &x,int &y){
//	if(a==3){
//		if(b==0){
//			x=2;
//			y=1;
//		} 
//		if(b==1){
//			x=3;
//			y=1;
//		}
//		if(b==2){
//			x=3;
//			y=1;
//		}
//		if(b==3){
//			x=3;
//			y=3;
//		}
//	}else if(a==2){
//		if(b==0){
//			x=2;
//			y=0;
//		}else if(b==1){
//			x=2;
//		}else if(b==2){
//			x=2;
//			y=2;
//		}
//	}
//}
int main(){
	bool flag=true;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++) scanf("%d",&b[i]);
	for(int i=0;i<=3;i++){
		t[1]=i;
		int j=2;
		for(j=2;j<=n;j++){
			t[j]=-1;
			for(int k=0;k<=3;k++){
				if((t[j-1]|k)==a[j-1]&&(t[j-1]&k)==b[j-1]){
					t[j]=k;
					break;
				}
			}
			if(t[j]==-1){
				flag=false;
				break;
			}
		}
		if(j>n){
			flag=true;
			break;
		}
	}
	if(flag){
		printf("YES\n");
		for(int i=1;i<=n;i++){
			printf("%d ",t[i]);
		}
	}else{
		printf("NO\n");
	} 
}

