//班主任给小玉一个任务，到文具店里买尽量多的签字笔。
//已知一只签字笔的价格是1元9角，而班主任给小玉的钱是a元b角，小玉想知道，她最多能买多少只签字笔呢。
#include<iostream>
using namespace std;
int main(){
	int a,b,out;
	int sum=1;
	int pen=19;
	int total;
	cin>>a;
	cin>>b;
	total=b+10*a; 
	out=total/pen;
	cout<<out;
}
