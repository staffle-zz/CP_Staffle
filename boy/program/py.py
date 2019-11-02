ll = lambda:list(map(int, input().split()))
testcases = 1
[testcases] = ll()
	# ll terms = n/m;
 #    ll sum = (m%mod)*(((terms%mod)*(terms+1)%mod)%mod)%mod;
 #    sum = (sum+n)%mod;
 #    cout << sum << endl;
for _ in range(testcases):
	[n,m] = ll()
	terms = n//m
	s = m*terms*(terms+1)
	s+=n
	mod = 10**9+7
	print(s%mod)

