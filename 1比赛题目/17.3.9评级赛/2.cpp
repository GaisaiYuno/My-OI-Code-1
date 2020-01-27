/*炎热的夏日，KC非常的不爽。他宁可忍受北极的寒冷，也不愿忍受厦门的夏天。最近，他开始研究天气的变化。他希望用研究的结果预测未来的天气。
经历千辛万苦，他收集了连续N（1<=N<=10^7）天的最高气温数据。
现在，他想知道最高气温一直上升的最长连续天数*/
#include<iostream>
using namespace std;
int main(){
	int N,in,out,max;
	max=0;
	cin>>N;
	int tem[N];
	for(int i=0;i<N;i++){
	   cin>>in;
	   tem[i]=in;
	}
	out=1;
   for(int i=0;i<N;i++){
     if(tem[i]<tem[i+1]) out=out+1;
     else out=1;
     if(out>max) max=out;
   }
   cout<<max;
   return 0;
}


 
