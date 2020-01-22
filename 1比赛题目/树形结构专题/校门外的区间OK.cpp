#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 65536*2+5
#define INF 65536*2
using namespace std;
struct node {
	int l;
	int r;
	int mark;
	int xor_mark;
} tree[1048576];
int used[1048576];
void push_up(int pos) {
	if(tree[pos<<1].mark!=tree[pos<<1|1].mark) tree[pos].mark=-1;
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=0;
	tree[pos].xor_mark=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}
//void push_down(int pos) {
//	if(tree[pos].mark!=-1) {
//		tree[pos<<1].mark=tree[pos<<1|1].mark=tree[pos].mark;
//		tree[pos<<1].xor_mark=tree[pos<<1|1].xor_mark=0;//有覆盖标记直接把异或标记清空
//		tree[pos].mark=-1;
//	}
//	if(tree[pos].xor_mark!=0) {
//		if(tree[pos<<1].mark!=-1) tree[pos<<1].mark^=1;
//		else tree[pos<<1].xor_mark^=1;
//		if(tree[pos<<1|1].mark!=-1) tree[pos<<1|1].mark^=1;
//		else tree[pos<<1|1].xor_mark^=1;
//		tree[pos].xor_mark=0;
//	}
//}
//void update(int L,int R,int v,int pos) {
//	if(L<=tree[pos].l&&R>=tree[pos].r) {
//		if(v==-1) {
//			if(tree[pos].mark!=-1) tree[pos].mark^=1;
//			else tree[pos].xor_mark^=1;
//		} else {
//			tree[pos].mark=v;
//			tree[pos].xor_mark=0;
//		}
//		return;
//	}
//	push_down(pos);
//	int mid=(tree[pos].l+tree[pos].r)>>1;
//	if(L<=mid) update(L,R,v,pos<<1);
//	if(R>mid) update(L,R,v,pos<<1|1);
////	push_up(pos);
//}
void push_down(int pos) {
	if(tree[pos].mark!=-1) {
		tree[pos<<1].mark=tree[pos<<1|1].mark=tree[pos].mark;
		tree[pos<<1].xor_mark=tree[pos<<1|1].xor_mark=0;//有覆盖标记直接把异或标记清空
		tree[pos].mark=-1;
	}
	if(tree[pos].xor_mark!=0) {
		if(tree[pos<<1].mark!=-1) tree[pos<<1].mark^=1;
		else tree[pos<<1].xor_mark^=1;
		if(tree[pos<<1|1].mark!=-1) tree[pos<<1|1].mark^=1;
		else tree[pos<<1|1].xor_mark^=1;
		tree[pos].xor_mark=0;
	}
}
void update(int L,int R,int v,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		if(v==-1) {
			if(tree[pos].mark!=-1) tree[pos].mark^=1;
			else tree[pos].xor_mark^=1;
		} else {
			tree[pos].mark=v;
			tree[pos].xor_mark=0;
		}
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
}
void query(int L,int R,int pos) {
	if(tree[pos].mark==1) {
		for(int i=tree[pos].l; i<=tree[pos].r; i++) used[i]=1;
		return;
	} else if(tree[pos].mark==0) return;
	if(tree[pos].l==tree[pos].r) return;
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) query(L,R,pos<<1);
	if(R>mid) query(L,R,pos<<1|1);
}
void print() {
	memset(used,0,sizeof(used));
	query(0,INF,1);
	int s=-1,e=0,first=1;
	for(int i=0; i<=INF; i++) {
		if(used[i]==1) {
			if(s==-1) s=i;
			e=i;
		} else if(s!=-1) {
			if(first==1) {
				if(s&1) printf("(%d,",s>>1);
				else printf("[%d,",s>>1);
				if(e&1) printf("%d)",(e+1)>>1);
				else printf("%d]",(e+1)>>1);
				first=0;
			} else {
				if(s&1) printf("(%d,",s>>1);
				else printf("[%d,",s>>1);
				if(e&1) printf("%d)",(e+1)>>1);
				else printf("%d]",(e+1)>>1);
			}
			printf(" ");
			s=-1;
		}
	}
	if(first==1) printf("empty set");
//	printf("\n");
}
void work(int cmd,int l,int r) {
	switch(cmd) {
		case('U'): {
			update(l,r,1,1);
			break;
		}
		case('I'): {
			if(l>0) update(0,l-1,0,1);
			if(r<INF) update(r+1,INF,0,1);
			break;
		}
		case('D'): {
			update(l,r,0,1);
			break;
		}
		case('C'): {
			if(l>0) update(0,l-1,0,1);
//			print();
//			for(int i=0; i<=10; i++) printf("%d ",used[i]);
//			printf("\n");
			if(r<INF) update(r+1,INF,0,1);
//			print();
//			for(int i=0; i<=10; i++) printf("%d ",used[i]);
//			printf("\n");
			update(l,r,-1,1);
//			print();
//			for(int i=0; i<=10; i++) printf("%d ",used[i]);
//			printf("\n");
			break;
		}
		case('S'): {
			update(l,r,-1,1);
			break;
		}
	}
}
int main() {
	char cmd,lc,rc;
	int l,r;
	build(0,INF,1);
	while(scanf("%c %c%d,%d%c",&cmd,&lc,&l,&r,&rc)!=EOF) {
		getchar();
		l<<=1;
		r<<=1;
		if(lc=='(') l++;
		if(rc==')') r--;
		if(l>r) {
			if(cmd=='I'||cmd=='C') update(0,INF,0,1);
			continue;
		}
		work(cmd,l,r);
//		print();
//		for(int i=0;i<=10;i++) printf("%d ",used[i]);
//		printf("\n");
	}
	print();
}

