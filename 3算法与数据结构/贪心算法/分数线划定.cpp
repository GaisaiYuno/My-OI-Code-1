//洛谷 分数线划定
#include<iostream>
#include<algorithm>
#define maxn 5005
using namespace std;
struct people {
	int score;
	int num;
}a[maxn];
int n,m;
int cmp(people x,people y) {
    if(x.score>y.score) return 1;
    else if(x.score<y.score) return 0;
    else{
    	if(x.num<=y.num) return 1;
    	else return 0;
	}
}
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].score;
	sort(a+1,a+n+1,cmp);
	m*=1.5;
	while(a[m].score==a[m+1].score) m++;
	cout<<a[m].score<<' '<<m<<endl;
	for(int i=1;i<=m;i++) 
	    cout<<a[i].num<<' '<<a[i].score<<endl;
	return 0;
}
