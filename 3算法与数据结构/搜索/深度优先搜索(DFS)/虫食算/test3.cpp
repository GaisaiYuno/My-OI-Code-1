#include<iostream>
using namespace std;
int n,x[26]= {0};//����
int m[26]= {0};//��λ
bool usednum[26]= {0};//��¼ĳ�������Ƿ��ù�
bool usedlet[26]= {0};//��¼ĳ����ĸ�Ƿ���ʹ�
int ans=0;
char s1[26],s2[26],s3[26],sums[78];
bool backok(int now) {//�ж�now֮��ÿһ�е����Ƿ�Ϸ�����Ҫ��֦��
	bool right=1;
	for(int i=3*n-1; i>now; i-=3) {
		if((usedlet[sums[i]-65]&&usedlet[sums[i-1]-65]&&usedlet[sums[i-2]-65])&&
		        (x[sums[i]-65]!=(x[sums[i-1]-65]+x[sums[i-2]-65])%n
		         &&x[sums[i]-65]!=(x[sums[i-1]-65]+x[sums[i-2]-65]+1)%n)) {
			/*���֮��ĳһ�е���ĸ���Ѿ������֪����ĸ��Ӧ��������   (usedlet[sums[i]-65]&&usedlet[sums[i-1]-65]&&usedlet[sums[i-2]-65])
			   �ж���һλ�ĺ��Ƿ���ȷ  x[sums[i]-65]!=(x[sums[i-1]-65]+x[sums[i-2]-65])%n ��������֮ǰ�н�λ��
			                        x[sums[i]-65]!=(x[sums[i-1]-65]+x[sums[i-2]-65]+1)%n ������֮ǰ�н�λ��
			*/
			right=0;
			break;//����ȷ��break
		}
	}
	return right;
}
bool ok(int now) {//�ж�now֮ǰÿһ�е����ּ������Ƿ�Ϸ�
	if(now%3!=2) return true;//���û������һ���У�ֱ�ӷ��أ�������
	int cons=now/3*3,sum=x[sums[cons]-65]+x[sums[cons+1]-65]+m[now/3];//���Ƹ߾��ȼӷ�
	int temp=sum;
	sum=sum%n;
	if(sum==x[sums[cons+2]-65]) {
		m[now/3+1]=temp/n;
		return true;
	} else return false;
}
void dfs(int now) { //nowΪĿǰsums�����±꣬��Ŀǰ��������� 
	if(ans) return;
	if(!ok(now-1)) return;//���now֮ǰ���� ���У����� 
	if(!backok(now-1)) return; //���now֮����� ���У����� 
	if(now==3*n) {
		ans=1;
		for(int i=0; i<n; i++) cout<<x[i]<<" ";
		return;
	}
	if(!usedlet[sums[now]-65]) {
		for(int i=n-1; i>=0; i--) {//ö��i 
			if(!usednum[i]) {
				int tempm=m[now/3];//��ֹ��λ״������һ��dfs�б��ı� 
				x[sums[now]-65]=i;
				usednum[i]=1;
				usedlet[sums[now]-65]=1;
				dfs(now+1);
				m[now/3]=tempm;//�ָ����� 
				usednum[i]=0;
				usedlet[sums[now]-65]=0;
			}
		}
	} else dfs(now+1);
	return;
}
int main() {
	cin>>n;
	//Ԥ����sums
	for(int i=0; i<n; i++) {
		cin>>s1[i];
		sums[3*(n-1-i)]=s1[i];
	}
	for(int i=0; i<n; i++) {
		cin>>s2[i];
		sums[3*(n-1-i)+1]=s2[i];
	}
	for(int i=0; i<n; i++) {
		cin>>s3[i];
		sums[3*(n-1-i)+2]=s3[i];
		/*
		4
		ABCD
		EFGH
		IJKL
		sums-->DHLCGKBFJAEI
		����sums[0~3*n-1]
		*/
	}
	dfs(0);
	return 0;
}
