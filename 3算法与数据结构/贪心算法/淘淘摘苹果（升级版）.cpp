//Âå¹È  ÌÔÌÔÕªÆ»¹û£¨Éı¼¶°æ£©
#include<iostream>
#include<algorithm>
#define maxn 5000
using namespace std;
struct ap{
	int x;
	int y;
}apple[maxn];
int comp(ap p,ap q){
	return p.y<q.y;
}
int main(){
	int n,a,b,s,c,ans=0;
	cin>>n>>s;
	cin>>a>>b; 
	for(int i=0;i<n;i++){
		cin>>apple[i].x>>apple[i].y;
	}
    sort(apple,apple+n,comp);
    for(int j=0;j<n;j++){
    	if(apple[j].x<=a+b && s-apple[j].y>=0){
    		s=s-apple[j].y;
    		ans++;
		}
	}
	cout<<ans;
	return 0;
} 
