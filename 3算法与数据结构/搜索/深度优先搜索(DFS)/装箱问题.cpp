/*��һ����������ΪV����������0����V����20000����ͬʱ��n����Ʒ��0��n����30��ÿ����Ʒ��һ�����������������
��n����Ʒ�У���ȡ���ɸ�װ�����ڣ�ʹ���ӵ�ʣ��ռ�Ϊ��С��*/
#include<iostream>
#include<algorithm>
using namespace std;
int total,num,sum,last;
int v[30];
int used[30];
void dfs(int now,int last) {
	if(now<min) {
		min=now;
		for(int i=0;i<n;i++) cout<<used[i]<<' ';
        cout<<endl;
	}
	for(int i=last+1;i<num;i++){
        if(now>=v[i]){
            used[i]=1;
            dfs(rest-v[i],i);
            used[i]=0;
        }
    }
    

}
int main() {
	cout<<"�������������";
	cin>>total;
	int min=total;
	cout<<"���������������";
	cin>>num;
	cout<<"�������������:";
	for(int i=0; i<num; i++) {
		cin>>v[i];
	}
	sort(v,v+num);
	for(int i=0; i<num; i++) {
		cout<<v[i]<<' ';
	}
}

