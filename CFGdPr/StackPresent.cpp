/*
C. Stack of Presents
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Santa has to send presents to the kids. He has a large stack of n presents, numbered from 1 to n; the topmost present has number a1, the next present is a2, and so on; the bottom present has number an. All numbers are distinct.

Santa has a list of m distinct presents he has to send: b1, b2, ..., bm. He will send them in the order they appear in the list.

To send a present, Santa has to find it in the stack by removing all presents above it, taking this present and returning all removed presents on top of the stack. So, if there are k presents above the present Santa wants to send, it takes him 2k+1 seconds to do it. Fortunately, Santa can speed the whole process up — when he returns the presents to the stack, he may reorder them as he wishes (only those which were above the present he wanted to take; the presents below cannot be affected in any way).

What is the minimum time required to send all of the presents, provided that Santa knows the whole list of presents he has to send and reorders the presents optimally? Santa cannot change the order of presents or interact with the stack of presents in any other way.

Your program has to answer t different test cases.

Input
The first line contains one integer t (1≤t≤100) — the number of test cases.

Then the test cases follow, each represented by three lines.

The first line contains two integers n and m (1≤m≤n≤105) — the number of presents in the stack and the number of presents Santa wants to send, respectively.

The second line contains n integers a1, a2, ..., an (1≤ai≤n, all ai are unique) — the order of presents in the stack.

The third line contains m integers b1, b2, ..., bm (1≤bi≤n, all bi are unique) — the ordered list of presents Santa has to send.

The sum of n over all test cases does not exceed 105.

Output
For each test case print one integer — the minimum number of seconds which Santa has to spend sending presents, if he reorders the presents optimally each time he returns them into the stack.

Example
inputCopy
2
3 3
3 1 2
3 2 1
7 2
2 1 7 3 4 5 6
3 1
outputCopy
5
8

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
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
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
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
ld PI = 3.1415926535897;
const ll N = 200010;
ull pows(ull x1, ll y1, ll mod)
{
	ull r1 = 1;
	x1 = x1 % mod;
	while (y1 > 0)	{
		if (y1 & 1)
			r1 = (r1 * x1) % mod;
		y1 = y1 >> 1;
		x1 = (x1 * x1) % mod;
	}
	return r1;
}
ull f[N];
ull mi(ull x, ll mod) {
	return pows(x, mod - 2, mod);
}
ull ncr(ull x, ll y, ll mod) {
	if (x < y)
		return 0;
	if (y == 0)
		return 1;
	ll ans = f[x] * mi(f[y], mod) % mod;
	ll z = (ans * mi(f[x - y], mod) % mod) % mod;
	return z % mod;
}
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t ; cin >> t;
	/*foi(N) {
		if (i == 0) {
			f[i] = 1;
			continue;
		}
		f[i] = (f[i - 1] * i) % MOD;
	}*/
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
string ask(ll x, ll y) {
	cout << x + 1 << " " << y + 1;
	string s;
	cin >> s;
	return s;
}
void solve() {
	ll n, m;
	cin >> n >> m;
	vll a(n + 1), b(m + 1), c(n + 1);
	foi(n) {
		cin >> a[i];
		c[a[i]] = i + 1;
	}
	foi(m) {
		cin >> b[i];
	}
	ll ans = m, id = -1;
	foi(m) {
		if (c[b[i]] > id) {
			ans += 2 * (c[b[i]] - i - 1);
			id = c[b[i]];
		}
	}
	cout << ans;
}


 
