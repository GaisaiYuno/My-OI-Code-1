//��� �������ĸ���
#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 1005
using namespace std;
char a[maxn];
char letter;
int len,lsum,rsum,lk,rk;
void find_letter() {
	for(int i=0; i<len; i++) {
		if(a[i]>='a'&&a[i]<='z') {
			letter=a[i];
			break;
		}
	}
}
void find_num() {
	int sign=1,i=0,x=0;
	int pos=0;//0Ϊ�Ⱥ���ߣ�1Ϊ�Ⱥ��ұ�
	while(i<len) {
		if(a[i]=='+'||a[i]=='-'||i==0||a[i-1]=='=') {
			if(a[i]=='-') sign=-1;
			if(a[i]<'0'||a[i]>'9')i++;
			x=0;
			while(a[i]>='0'&&a[i]<='9') { //��������
				x=x*10+a[i]-'0';
				i++;
			}
			x*=sign;
			if(a[i]>='a'&&a[i]<='z') { //�������ĸ����ϵ��
				if(pos==0) lk+=x;
				else rk+=x;
				i++;
			} else { //���������ĸ�����
				if(pos==0) lsum+=x;
				else rsum+=x;
				//i++;
			}
		} 
		if(a[i]=='=') {
			pos=1;
			i++;
		}
	}
}
int main() {
	cin>>a;
	len=strlen(a);
	find_letter();
	find_num();
	//cout<<rsum;
	//printf("%d %d %d %d\n",rsum,lsum,lk,rk);
	//cout<<(rsum-lsum)/(lk-rk);
	printf("%c=%.3f\n",letter,(double)(rsum-lsum)/(lk-rk));
	return 0;
}
