#include<iostream>
#include<cstdio> 
using namespace std;
/*��8X8��Ĺ��������ϰڷŰ˸��ʺ�ʹ�䲻�ܻ��๥����
�����������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб���ϣ�
���ж����ְڷ�?
*/
int ans[100];//= {3,1,7,4,6,0,2,5};//һ��� 
int a=0,n;
bool check(int lie,int num) {//lie����������num��ÿ�еĵڼ��� 
	int res=1;
	for(int i=0; i<lie; i++) {
		if(num==ans[i]) res=0;
		if(lie-num==i-ans[i]) res=0;
		if(lie+num==i+ans[i]) res=0;
	}
	return res;
}
int dfs(int loc) {//loc��lieһ�� 
	if(loc==n) {
		for(int i=0; i<n; i++) cout<<ans[i]<<' ';
		a=a+1;
		cout<<endl;

	}
	for(int i=0; i<n; i++) {
		if(check(loc,i)) {
			ans[loc]=i;
			dfs(loc+1);
		}
	}
}
int main() {
	cin>>n;
	dfs(0);
	cout<<a;
}
