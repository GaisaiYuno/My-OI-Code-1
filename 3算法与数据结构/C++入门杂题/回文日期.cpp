#include<iostream>
#include<cstdio>
using namespace std;
int n,m,date,ans;
int daynum[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
//ʵ��ֻ��<=365���������ڣ�365���Ӧ365�������·����������365�������ڼ���
int main() {
	cin>>n>>m;
	for(int i=1; i<=12; i++) {
		for(int j=1; j<=daynum[i]; j++) {
			int t=1000*(j%10)+100*(j/10)+10*(i%10)+i/10;//�����·����� 10��23������2310
			date=t*10000+i*100+j;//ͨ���������ɻ����� 23101023,��ʱ�����жϺ���������Ƿ�Ϸ���ֻ����� 
			if(date>=n&&date<=m) {
			   	ans++;
			} 
		}
	}
	cout<<ans;
	return 0;
}
