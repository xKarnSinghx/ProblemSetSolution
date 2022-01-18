/*
D. Generating Sets
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a set Y of n distinct positive integers y1, y2, ..., yn.

Set X of n distinct positive integers x1, x2, ..., xn is said to generate set Y if one can transform X to Y by applying some number of the following two operation to integers in X:

Take any integer xi and multiply it by two, i.e. replace xi with 2·xi.
Take any integer xi, multiply it by two and add one, i.e. replace xi with 2·xi + 1.
Note that integers in X are not required to be distinct after each operation.

Two sets of distinct integers X and Y are equal if they are equal as sets. In other words, if we write elements of the sets in the array in the increasing order, these arrays would be equal.

Note, that any set of integers (or its permutation) generates itself.

You are given a set Y and have to find a set X that generates Y and the maximum element of X is mininum possible.

Input
The first line of the input contains a single integer n (1 ≤ n ≤ 50 000) — the number of elements in Y.

The second line contains n integers y1, ..., yn (1 ≤ yi ≤ 109), that are guaranteed to be distinct.

Output
Print n integers — set of distinct integers that generate Y and the maximum element of which is minimum possible. If there are several such sets, print any of them.

Examples
inputCopy
5
1 2 3 4 5
outputCopy
4 5 2 3 1 
inputCopy
6
15 14 3 13 1 12
outputCopy
12 13 14 7 3 1 
inputCopy
6
9 7 13 17 5 11
outputCopy
4 5 2 6 3 1 

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
ll ask(ll x) {
	cout << "?" << " ";
	cout << x + 1 << endl;
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


/*
-------------------sparse----------------------
ll st[N][26];
ll good(int L, int R) {
	ll j = log2(R - L + 1);
	ll g = gcd(st[L][j], st[R - (1 << j) + 1][j]);
	return g ;
}

----------------------main-------------------------

foi(n - 1) {
	st[i][0] = abs(a[i + 1] - a[i]);
}
for (ll j = 1; j <= 25; j++) {
	for (ll i = 0; i + (1 << j) < n; i++) {
		st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
}
*/
void solve() {
	ll n;
	cin >> n;
	vll a(n);
	foi(n) {
		cin >> a[i];
	}
	set<ll>s;
	foi(n) {
		s.insert(a[i]);
	}
	ll x = 111111111111;
	while (x) {
		auto it = s.end();
		it--;
		x = *it;
		while (s.count(x))
			x /= 2;
		if (x) {
			s.erase(*it);
			s.insert(x);
		}
	}
	for (auto it : s) {
		cout << it << " ";
	}
}

 
