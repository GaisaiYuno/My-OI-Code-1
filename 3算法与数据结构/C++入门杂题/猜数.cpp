#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<ctime> 
#define maxn 10
using namespace std;
int N;
string ans;
int a[maxn];
int b[maxn];
void input(){
   cout<<"������µ�����";
   cin>>ans;
   for(int i=0;i<N;i++) b[i]=ans[i]-48;
}
void judge() {
	for(int j=0; j<N; j++) {
		for(int k=0; k<N; k++) {
			if(a[j]==b[k]) {
				if(j==k) cout<<"A";
				else cout<<"B";
			}
		}
	}
	cout<<endl;
	return;
}
int comp(){
	int temp=0;
	for(int i=0;i<N;i++){
	  if(a[i]==b[i]) temp=1;
	  else temp=0;
	}
	return temp;
}
int main() {
	cout<<"��ӭʹ�ø���Ϸ:" ; 
	srand((unsigned)time(NULL));
	cout<<"������λ����";
	cin>>N;
	for(int i=0; i<N; i++) a[i]=rand()%10;
	input();
    while(!comp()){
    	 judge();
         input();
	}
    for(int q=0;q<N;q++) cout<<a[q]; 
    return 0;
}
