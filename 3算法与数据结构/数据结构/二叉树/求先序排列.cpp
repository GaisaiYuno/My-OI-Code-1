//��� ����������
#include<iostream>
#include<cstring> 
#define maxn 1000
using namespace std;
char in[maxn],post[maxn]; 
int len;
//���ɣ������������һ��һ���Ǹ�
void dfs(int s,int e){
	int t=0;
	if(s>e) return;
    for(int i=len-1;i>=0;i--){
    	for(int j=s;j<=e;j++){
    		if(in[j]==post[i]){
    			t=j;
    			break;
			}
		}
		if(t) break; 
	}
	cout<<in[t];
	dfs(s,t-1);
	dfs(t+1,e);
	return;
}
int main(){
	scanf("%s%*c%s",in,post);//%*c����¼���У� 
	len=strlen(in);
	dfs(0,len-1);
	return 0;
} 

/*������������ͺ���������㷽��
������  BDACE
��  DBECA1.��
���������֪�����һ���ڵ�һ���Ǹ��ڵ�,������ΪA
2.�����ж�Ӧ�ĸ�����A,�Ƶ�AΪ��BDΪ������CEΪ������
3.������2�����������ҲΪ2��,��Ϊ�������������������˽������Ϊ������DB,��EC
4.��BD�ɺ������֪BΪ���ڵ㣬ȷ���������ĸ�ΪB,ͬ����������ΪC
5.�ڻص����������������� BD (BΪ��)��������ΪD  ���������� ��ΪC������ΪE
������Ͷ��ʱ���ж϶��������ݹ�ؽ���. 
*/ 
