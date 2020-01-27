//Âå¹È ½øÖÆ×ª»»
#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int num,base;
void work(int x){
	int ans;
	ans=x%base;
	x/=base;
	if(ans<0){
		ans-=base;
		x++;
	}
	if(x!=0) work(x);
	if(ans>9) printf("%c",ans-10+'A');
	else printf("%d",ans);  
}
int main(){
	cin>>num>>base;
	printf("%d=",num);
	work(num);
	printf("(base%d)",base);
	return 0;
} 
