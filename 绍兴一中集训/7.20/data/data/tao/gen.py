import random
import os

def gen(num,n):
	with open('tao%s.in'%(num),'w') as fp:
		Q=n-1
		fp.write('%s %s\n'%(n,Q))
		for i in range(n):
			fp.write('%s %s\n'%((random.choice(range(10**9))),random.choice(range(10**9))))
		for i in range(Q):
			fp.write('%s %s\n'%((random.choice(range(10**9))),random.choice(range(10**9))))

for i in range(1,6):gen(i,50)
for i in range(6,8):gen(i,3000)
for i in range(8,11):gen(i,200000)
for i in range(1,11):os.system('tao <tao%s.in >tao%s.out'%(i,i))



