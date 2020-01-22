#include <iostream>
#include <stdio.h>

namespace solution
{
	using namespace std;
	
	const int MAXSIZE=196609;
	
	inline char read(int &x)
	{
		x=0;char ch=getchar();bool f=0;
		while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
		while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
		if(f)x=-x;
		return ch;
	}
	
	inline void read(char &x)
	{
		x=getchar();
		while(x<=' ')x=getchar();
	}
	
	class program
	{
		public: struct
		{
			//-1:different 0:all zero 1:all one
			int l,r,flag;
			//表示一个区间的子区间是否需要取反 
			bool but;
		}tree[1048576];
		
		public: void build(int l,int r,int now=1)
		{
			tree[now].l=l;tree[now].r=r;
			tree[now].flag=0;tree[now].but=0;
			if(l==r)return;
			int mid=l+r>>1;
			build(l,mid,now<<1);
			build(mid+1,r,now<<1|1);
		}
		
		public: void pushdown(int now)
		{
			if(tree[now].but)
			{
				tree[now<<1].but^=1;
				tree[now<<1|1].but^=1;
				if(tree[now<<1].flag!=-1)tree[now<<1].flag^=1;
				if(tree[now<<1|1].flag!=-1)tree[now<<1|1].flag^=1;
				tree[now].but=false;
			}
			if(tree[now].flag==-1) return;
			tree[now<<1].flag=tree[now<<1|1].flag=tree[now].flag;
		}
		
		public: bool query(int p,int now=1)
		{
			if(tree[now].flag!=-1)
			{
				return tree[now].flag;
			}
			int mid=tree[now].l+tree[now].r>>1;
			pushdown(now);
			if(p<=mid)return query(p,now<<1);
			else return query(p,now<<1|1);
		}
		
		public: void updata(int l,int r,int x,int now=1)
		{
			if(r<l)return;
			if(tree[now].l==l&&tree[now].r==r)
			{
				tree[now].flag=x;
				tree[now].but=false;
				return;
			}
			int mid=tree[now].l+tree[now].r>>1;
			pushdown(now);
			if(r<=mid)
			{
				updata(l,r,x,now<<1);
			}
			else if(mid<l)
			{
				updata(l,r,x,now<<1|1);
			}
			else
			{
				updata(l,mid,x,now<<1);
				updata(mid+1,r,x,now<<1|1);
			}
			if(tree[now<<1].flag==tree[now<<1|1].flag)tree[now].flag=tree[now<<1].flag;
			else tree[now].flag=-1;
		}
		
		//取反 
		public: void notnum(int l,int r,int now=1)
		{
			if(r<l)return;
			if(tree[now].l==l&&tree[now].r==r)
			{
				tree[now].but^=1;
				if(tree[now].flag!=-1) tree[now].flag^=1;
				return;
			}
			int mid=tree[now].l+tree[now].r>>1;
			pushdown(now);
			if(r<=mid)
			{
				notnum(l,r,now<<1);
			}
			else if(mid<l)
			{
				notnum(l,r,now<<1|1);
			}
			else
			{
				notnum(l,mid,now<<1);
				notnum(mid+1,r,now<<1|1);
			}
			if(tree[now<<1].flag==tree[now<<1|1].flag)tree[now].flag=tree[now<<1].flag;
			else tree[now].flag=-1;
		}
		
		public: void opeu(int from,int to)
		{
			updata(from,to,1);
		}
		
		public: void opei(int from,int to)
		{
			updata(0,from-1,0);
			updata(to+1,MAXSIZE,0);
		}
		
		public: void oped(int from,int to)
		{
			updata(from,to,0);
		}
		
		public: void opec(int from,int to)
		{
			updata(0,from-1,0);
			notnum(from,to);
			updata(to+1,MAXSIZE,0);
		}
		
		public: void opes(int from,int to)
		{	
		//	cout<<from<<" "<<to<<endl;
			notnum(from,to);
		}
		
		public: int main(int argc,char **argv)
		{
			char ope,left,right;
			int from,to;
			build(0,MAXSIZE);
			while(cin>>ope)
			{
				read(left);read(from);right=read(to);;
				//cout<<left<<from<<","<<to<<right<<endl;
				from*=3;to*=3;
				if(left=='(') from++;
				if(right==')') to--;
				switch(ope)
				{
					case 'U':opeu(from,to);break;
					case 'I':opei(from,to);break;
					case 'D':oped(from,to);break;
					case 'C':opec(from,to);break;
					default :opes(from,to);
				}
			}
			bool isempty=true;
			bool last=query(0);
			if(last)
			{
				printf("[0");
				isempty=false;
			}
			for(int i=1;i<=MAXSIZE;i++)
			{
				int tmp=query(i);
				if(tmp)
				{
					if(!last)
					{
						if(i%3) putchar('(');
						else putchar('[');
						printf("%d",i/3);
						isempty=false;
					}
				}
				else
				{
					if(last)
					{
						printf(",%d",i/3);
						if((i-1)%3) putchar(')');
						else putchar(']');
						putchar(' ');
					}
				}
				last=tmp;
			}
			if(isempty) puts("empty set");
			return 0;
		}
	};
}

solution::program theApp;

int main(int argc,char **argv)
{
	return theApp.main(argc,argv); 
}

