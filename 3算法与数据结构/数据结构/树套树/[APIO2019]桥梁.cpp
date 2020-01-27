#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 500000
#define maxm 1000000
#define bsz 1000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar(x%10+'0');
	}
}

int n,m,q;
struct edge{
	int from;
	int to;
	int val;
	int id;
}E[maxm+5];

int fa[maxn+5];
int sz[maxn+5];
int find(int x){
//	printf("%d\n",x);
	if(fa[x]==x) return x;
	else return find(fa[x]);
}
void ini(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
}
int bel[maxn+5];
int lastx[maxm+5],lasty[maxm+5];//���ڼ�¼���鼯֮ǰ״̬���ع�ʱ�� 
void merge(int id){
	int x=E[id].from;
	int y=E[id].to;
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		if(sz[fx]>sz[fy]) swap(fx,fy);
		lastx[id]=fx;
		lasty[id]=fy;
		fa[fx]=fy;
		sz[fy]+=sz[fx];
	} 
}

struct oper{
	int type;
	int x;
	int val;
}in[maxn+5];
struct query{//ѯ�� 
	int id;
	int x;
	int val;
	query(){
		
	}
	query(int _id,int _x,int _val){
		id=_id;
		x=_x;
		val=_val;
	}
	friend bool operator < (query p,query q){
		return p.val>q.val;
	}
};
vector<query>Q;
struct update{//��Ҫ�ϲ��ı� 
	int id;
	int val;
	update(){
		
	}
	update(int _id,int _val){
		id=_id;
		val=_val;
	}
	friend bool operator < (update p,update q){
		return p.val>q.val;
	}
};
int ans[maxn+5];
bool vis[maxn+5];//�����Щ�ߵı�Ȩ��Ҫ�޸� 
bool tmp[maxn+5];//��ǵ�ǰ����Ҫ�޸ĵı� 
vector<update>U1;//����Ҫ�޸ģ�������Ҫ�ϲ��ı� 
vector<int>U2;//��Ҫ�޸ģ���Ҫ�ϲ��ı� 
vector<int>back;//�ع��� 
void rebuild(int last){
	for(int i=1;i<=m;i++){
		U1.push_back(update(i,E[i].val));
		lastx[i]=0;
	}
	ini(n);
	sort(U1.begin(),U1.end());
	sort(Q.begin(),Q.end());
	for(int i=0,j=0;i<Q.size();i++){////����ÿ��ѯ�� 
		back.clear();
		while(j<U1.size()&&U1[j].val>=Q[i].val){//˫ָ���ҳ����Ծ����ı� 
			if(!vis[U1[j].id]){
				merge(U1[j].id);
				lastx[U1[j].id]=0;//����Ҫ�ع� 
			}
			j++;
		}
		for(int p=last;p<Q[i].id;p++){
			if(in[p].type==1) tmp[in[p].x]=1; 
		} 
		for(int p=0;p<U2.size();p++){//�޸�ǰ��Ȩ�ȵ�ǰѯ��Ҫ��
		//�����ں��������漰�޸ģ���Ҫ���лع� 
			if(!tmp[U2[p]]&&Q[i].val<=E[U2[p]].val){
				merge(U2[p]);
				back.push_back(U2[p]); 
			}
		}
		for(int p=Q[i].id;p>=last;p--){
		//��ѯʱ��֮ǰ���޸��ˣ������޸ĺ��Ȩ�ȵ�ǰ��ѯ����Ҫ��
        //ע�⣺ֻ���޸ĺ��Ȩ�ȵ�ǰ��ѯ��ı߲Ż���кϲ�������ͨ��from[s[p]]=-1�ڻس�ʱ���˵�������Ҫ��ı� 
			if(in[p].type==1) tmp[in[p].x]=0;//�ع�tmp���� 
			if(in[p].type==2||lastx[in[p].x]) continue;//����query 
			lastx[in[p].x]=-1;
			back.push_back(in[p].x);
			if(in[p].val>=Q[i].val) merge(in[p].x);//����޸ĺ��öԴ���Ӱ�죬�ͺϲ� 
		}
		ans[Q[i].id]=sz[find(Q[i].x)];
		for(int p=back.size()-1;p>=0;p--){//�ع� 
			if(lastx[back[p]]!=-1){ 
				sz[lasty[back[p]]]-=sz[lastx[back[p]]];
				fa[lastx[back[p]]]=lastx[back[p]]; 
			} 
			lastx[back[p]]=0; 
		}
	}
}
int main(){
	qread(n);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(E[i].from);
		qread(E[i].to);
		qread(E[i].val);
		E[i].id=i;
	}
	qread(q);
	for(int i=1;i<=q;i++) bel[i]=i/bsz+1;
	int last=1;
	for(int i=1;i<=q;i++){
		qread(in[i].type);
		qread(in[i].x);
		qread(in[i].val);
		if(in[i].type==1){
			if(!vis[in[i].x]) U2.push_back(in[i].x);
			vis[in[i].x]=1;
		}else{
			Q.push_back(query(i,in[i].x,in[i].val));			
		}
		if(bel[i]!=bel[i+1]){
			///����һ���飬����һ�����߲���
			rebuild(last);
			while(last<=i){//last��¼�޸ĺͲ�ѯ������ 
				vis[in[last].x]=0; 
				if(in[last].type==1) E[in[last].x].val=in[last].val;
				else{
					qprint(ans[last]);
					putchar('\n');
				}
				last++;
			}
			U1.clear();
			U2.clear();
			Q.clear();
			back.clear();
		}
		
	}
} 
