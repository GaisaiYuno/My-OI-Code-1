#include<iostream>
using namespace std;
#define max 500
int main() {
	string a,c;
	int i,k,x,num;
	int b[max];
	int d[max];
	int sum[max];
	//while(1) {
		//cout<<"����������С��500λ����������"<<'\n' ;
		cin>>a;
		cin>>c;

		for(i=0; i<max; i++) {//��ʼ�����������ɵ��������
			sum[i]=0;
			b[i]=0;
			d[i]=0;
		}
		for(i=0; i<a.length(); i++) {//����������鵹������
			b[a.length()-1-i]=a[i]-48;
			//cout<<b[a.length()-1-i];
		}
		//cout<<'\n';
		for(i=0; i<c.length(); i++) {
			d[c.length()-1-i]=c[i]-48;
			//cout<<d[c.length()-1-i];

		}
		k=0;
		x=0;
		num=(a.length()>=c.length())?a.length():c.length();
		while(num>k) {//�ӷ�����
			sum[k]=d[k]+b[k]+x;
			x=sum[k]/10;
			sum[k]%=10;
			k++;
		}
		sum[k]=x;
		if(sum[k]==0)
			k--;
		//cout<<"���ǵĺ��ǣ�" ;
		for(i=k; i>=0; i--)//���
			cout<<sum[i];
		//cout<<endl<<'\n';
	//}
	return 0;
}

