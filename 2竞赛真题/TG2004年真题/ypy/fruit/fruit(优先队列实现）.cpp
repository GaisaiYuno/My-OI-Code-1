#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 10005 
using namespace std;
int n,ans;
struct node{
	int x;
	friend bool operator < (node a,node b){
		return a.x>b.x;
	}
};
node fruit[maxn];
priority_queue<node>q;
int main(){
	//freopen("fruit.in","r",stdin);
	//freopen("fruit.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>fruit[i].x;
	    q.push(fruit[i]);
    }
	for(int i=1;i<n;i++){
		node t1,t2,t3;
		t1=q.top();
		q.pop();
		t2=q.top();
		q.pop();
		t3.x=t2.x+t1.x;
		q.push(t3);
		ans=ans+t2.x+t1.x;
	}
	cout<<ans;
	return 0;
}
