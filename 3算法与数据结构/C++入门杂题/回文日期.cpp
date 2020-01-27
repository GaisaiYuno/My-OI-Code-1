#include<iostream>
#include<cstdio>
using namespace std;
int n,m,date,ans;
int daynum[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
//实际只有<=365个回文日期，365天对应365个，从月份日期来算出365回文日期即可
int main() {
	cin>>n>>m;
	for(int i=1; i<=12; i++) {
		for(int j=1; j<=daynum[i]; j++) {
			int t=1000*(j%10)+100*(j/10)+10*(i%10)+i/10;//生成月份日期 10月23日生成2310
			date=t*10000+i*100+j;//通过日期生成回文数 23101023,此时不必判断后面的日期是否合法，只需年份 
			if(date>=n&&date<=m) {
			   	ans++;
			} 
		}
	}
	cout<<ans;
	return 0;
}
