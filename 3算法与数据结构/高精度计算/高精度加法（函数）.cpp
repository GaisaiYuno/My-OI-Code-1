#include<iostream>
using namespace std;
#define max 500

int add(int sum[],int d[],int b[],int num) {

	int i,k,x;
	k=0;
	x=0;

	while(num>k) {//�ӷ�����
		sum[k]=d[k]+b[k]+x;
		x=sum[k]/10;
		sum[k]%=10;
		k++;
	}
	sum[k]=x;
	if(sum[k]==0)
		k--;

	return k;
}
int main() {
	string a,c;
	int i,k,no,lenout;
	int add1[max];
	int add2[max];
	int result[max];
input:
	cout<<"����������С��500λ����������"<<'\n' ;
	cin>>a;
	cin>>c;

	for(i=0; i<max; i++) {//��ʼ�����������ɵ��������
		result[i]=0;
		add1[i]=0;
		add2[i]=0;
	}
	for(i=0; i<a.length(); i++) {//����������鵹������
		add1[a.length()-1-i]=a[i]-48;

	}
	cout<<'\n';
	for(i=0; i<c.length(); i++) {
		add2[c.length()-1-i]=c[i]-48;


	}
	no=(a.length()>=c.length())?a.length():c.length();
	lenout=add(result,add1,add2,no);
	cout<<"���ǵĺ��ǣ�" ;

	for(i=lenout; i>=0; i--) //���
		cout<<result[i];
	cout<<endl<<'\n';
	goto input;
	return 1;
}

