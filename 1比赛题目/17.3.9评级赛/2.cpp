/*���ȵ����գ�KC�ǳ��Ĳ�ˬ�����������ܱ����ĺ��䣬Ҳ��Ը�������ŵ����졣���������ʼ�о������ı仯����ϣ�����о��Ľ��Ԥ��δ����������
����ǧ����࣬���ռ�������N��1<=N<=10^7���������������ݡ�
���ڣ�����֪���������һֱ���������������*/
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


 
