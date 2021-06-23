/*
D. Multiple Testcases
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
So you decided to hold a contest on Codeforces. You prepared the problems: statements, solutions, checkers, validators, tests... Suddenly, your coordinator asks you to change all your tests to multiple testcases in the easiest problem!

Initially, each test in that problem is just an array. The maximum size of an array is k. For simplicity, the contents of arrays don't matter. You have n tests — the i-th test is an array of size mi (1≤mi≤k).

Your coordinator asks you to distribute all of your arrays into multiple testcases. Each testcase can include multiple arrays. However, each testcase should include no more than c1 arrays of size greater than or equal to 1 (≥1), no more than c2 arrays of size greater than or equal to 2, …, no more than ck arrays of size greater than or equal to k. Also, c1≥c2≥⋯≥ck.

So now your goal is to create the new testcases in such a way that:

each of the initial arrays appears in exactly one testcase;
for each testcase the given conditions hold;
the number of testcases is minimum possible.
Print the minimum possible number of testcases you can achieve and the sizes of arrays included in each testcase.

Input
The first line contains two integers n and k (1≤n,k≤2⋅105) — the number of initial tests and the limit for the size of each array.

The second line contains n integers m1,m2,…,mn (1≤mi≤k) — the sizes of the arrays in the original tests.

The third line contains k integers c1,c2,…,ck (n≥c1≥c2≥⋯≥ck≥1); ci is the maximum number of arrays of size greater than or equal to i you can have in a single testcase.

Output
In the first line print a single integer ans (1≤ans≤n) — the minimum number of testcases you can achieve.

Each of the next ans lines should contain the description of a testcase in the following format:

t a1 a2 … at (1≤t≤n) — the testcase includes t arrays, ai is the size of the i-th array in that testcase.

Each of the initial arrays should appear in exactly one testcase. In particular, it implies that the sum of t over all ans testcases should be equal to n.

Note that the answer always exists due to ck≥1 (and therefore c1≥1).

If there are multiple answers, you can output any one of them.

Examples
inputCopy
4 3
1 2 2 3
4 1 1
outputCopy
3
1 2
2 1 3
1 2
inputCopy
6 10
5 8 1 10 8 7
6 6 4 4 3 2 2 2 1 1
outputCopy
2
3 8 5 7
3 10 8 1
inputCopy
5 1
1 1 1 1 1
5
outputCopy
1
5 1 1 1 1 1
inputCopy
5 1
1 1 1 1 1
1
outputCopy
5
1 1
1 1
1 1
1 1
1 1
Note
In the first example there is no way to distribute the tests into less than 3 testcases. The given answer satisfies the conditions: each of the testcases includes no more than 4 arrays of size greater than or equal to 1 and no more than 1 array of sizes greater than or equal to 2 and 3.

Note that there are multiple valid answers for this test. For example, testcases with sizes [[2],[1,2],[3]] would also be correct.

However, testcases with sizes [[1,2],[2,3]] would be incorrect because there are 2 arrays of size greater than or equal to 2 in the second testcase.

Note the difference between the third and the fourth examples. You can include up to 5 arrays of size greater than or equal to 1 in the third example, so you can put all arrays into a single testcase. And you can have only up to 1 array in the fourth example. Thus, every array should be included in a separate testcase.

*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <chrono>
#include <complex>
using namespace std;
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<ll>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
//	ll t ; cin >> t;
//	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;

}
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
bool COMP(pll l, pll r) {
	return l.ss < r.ss;
}
ll kadanesAlgo(vll a)
{
	ll n = a.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	foi(n)
	{
		currMax += a[i];

		if (currMax <= a[i])
		{
			currMax = a[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vll a(n, 0), b(k + 1, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	foi(k) {
		ll x;
		cin >> x;
		b[i + 1] = x;
	}
	sort(all(a), greater<ll>());
	ll cnt = 0;
	for (ll i = k, g = 0; i > 0; i--)
	{
		while (g < n and a[g] == i) g++;
		cnt = max(cnt, (g + b[i] - 1) / b[i]);
	}
	graph ans(cnt);
	foi(n)
	ans[i % cnt].pb(a[i]);
	cout << cnt << endl;
	foi(cnt) {
		cout << ans[i].size() << " ";
		foj(ans[i].size())
		cout << ans[i][j] << " ";
		cout << endl;
	}
}

