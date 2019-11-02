ll = lambda: list(map(int,input().split()))
def calc(k,b):
	return (k*b + 1)*(b*(b-1)/2)
mod = 1000000007
[a,b] = ll()
ans = 0;
for k in range(1,a+1):
	ans = (ans + calc(k,b))
	ans%=mod
print(ans)
