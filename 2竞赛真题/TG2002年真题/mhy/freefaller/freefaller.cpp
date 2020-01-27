#include <iostream>
#include <cstdio>
#include <cmath>
#define G 10
#define Min 0.0001
using namespace std;
double H,S1,V,L,K,n;
long long total;
bool check(int i){
	bool leftok=i-Min<(S1-sqrt((H-K)/(G/2)))+L;
	bool rightok=i+Min>S1-sqrt(H/(G/2))*V;
	return (leftok&&rightok);
}
int main() {
	scanf("%lf%lf%lf%lf%lf%lf",&H,&S1,&V,&L,&K,&n);
	//�컨��ߣ�С����ԭ�㣬�ٶȣ���ȣ��߶ȣ�С��
	for (int i=0; i<n; i++) {
		if (check(i)) {
			total++;
		}
	}
	cout<<total<<endl;
}
