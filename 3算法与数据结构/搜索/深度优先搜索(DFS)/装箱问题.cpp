/*有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30，每个物品有一个体积（正整数）。
求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。*/
#include<iostream>
#include<algorithm>
using namespace std;
int total,num,sum,last;
int v[30];
int used[30];
void dfs(int now,int last) {
	if(now<min) {
		min=now;
		for(int i=0;i<n;i++) cout<<used[i]<<' ';
        cout<<endl;
	}
	for(int i=last+1;i<num;i++){
        if(now>=v[i]){
            used[i]=1;
            dfs(rest-v[i],i);
            used[i]=0;
        }
    }
    

}
int main() {
	cout<<"请输入总体积：";
	cin>>total;
	int min=total;
	cout<<"请输入物体个数：";
	cin>>num;
	cout<<"请输入物体体积:";
	for(int i=0; i<num; i++) {
		cin>>v[i];
	}
	sort(v,v+num);
	for(int i=0; i<num; i++) {
		cout<<v[i]<<' ';
	}
}

