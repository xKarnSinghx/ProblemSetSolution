/*
C. Balanced Stone Heaps
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n heaps of stone. The i-th heap has hi stones. You want to change the number of stones in the heap by performing the following process once:

You go through the heaps from the 3-rd heap to the n-th heap, in this order.
Let i be the number of the current heap.
You can choose a number d (0≤3⋅d≤hi), move d stones from the i-th heap to the (i−1)-th heap, and 2⋅d stones from the i-th heap to the (i−2)-th heap.
So after that hi is decreased by 3⋅d, hi−1 is increased by d, and hi−2 is increased by 2⋅d.
You can choose different or same d for different operations. Some heaps may become empty, but they still count as heaps.
What is the maximum number of stones in the smallest heap after the process?

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤2⋅105). Description of the test cases follows.

The first line of each test case contains a single integer n (3≤n≤2⋅105).

The second lines of each test case contains n integers h1,h2,h3,…,hn (1≤hi≤109).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print the maximum number of stones that the smallest heap can contain.

Example
inputCopy
4
4
1 2 10 100
4
100 100 100 1
5
5 1 1 1 8
6
1 2 3 4 5 6
outputCopy
7
1
1
3
Note
In the first test case, the initial heap sizes are [1,2,10,100]. We can move the stones as follows.

move 3 stones and 6 from the 3-rd heap to the 2-nd and 1 heap respectively. The heap sizes will be [7,5,1,100];
move 6 stones and 12 stones from the last heap to the 3-rd and 2-nd heap respectively. The heap sizes will be [7,17,7,82].
In the second test case, the last heap is 1, and we can not increase its size.

In the third test case, it is better not to move any stones.

In the last test case, the final achievable configuration of the heaps can be [3,5,3,4,3,3].


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
typedef vector<ld>          vld;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<vll, ll>             mvlll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 1000010;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t; cin >> t;
	while (t--)
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
ll ask(ll x, ll y) {
	cout << "?" << " ";
	cout << x << " " << y << endl;
	ll s;
	cin >> s;
	return s;
}
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
bool is_sorted(vector<ll>a) {
	ll x = 0;
	for (ll i = 0; i < a.size() - 1; i++) {
		if (a[i] < a[i + 1])
			x++;
	}
	return x == a.size() - 1;
}
bool check(string a, string b) {
	ll n = a.size(), m = b.size();
	if (a < b) {
		return true;
	}
	if (a > b) {
		return false;
	}
	foi(a.size()) {
		if (a[i] > b[i]) {
			return false;
		}
		else if (a[i] < b[i]) {
			return true;
		}
	}
	return false;
}
bool isSubSequence(string a, string b, ll m, ll n) {
	ll j = 0;
	for (ll i = 0; i < n and j < m; i++)
		if (a[j] == b[i])
			j++;
	return (j == m);
}
ll power(ll n, ll x) {
	ll ans = 1;
	foi(n) {
		ans *= x;
	}
	return ans;
}
ll n;
vll a(N / 5);
bool good(ll x) {
	vll b(n);
	foi(n) {
		b[i] = a[i];
	}
	for (ll i = n - 1; i > 1; i--) {
		if (b[i] >= x) {
			ll z = min(a[i], (b[i] - x)) / 3;
			b[i] -= 3 * z;
			b[i - 1] += z;
			b[i - 2] += 2 * z;
		}
		else if (b[i] < x)
			return false;
	}
	if (b[0] < x or b[1] < x)
		return false;
	return true;
}
void solve() {
	a.clear();
	cin >> n;
	foi(n) {
		cin >> a[i];
	}
	ll l = 0, r = 111111111111, ans = 0;
	while (l <= r) {
		ll m = (l + r) / 2;
		if (good(m))
			l = m + 1, ans = m;
		else
			r = m - 1;
	}
	cout << ans;

}
