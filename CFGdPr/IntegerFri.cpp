/*
D. Integers Have Friends
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
British mathematician John Littlewood once said about Indian mathematician Srinivasa Ramanujan that "every positive integer was one of his personal friends."

It turns out that positive integers can also be friends with each other! You are given an array a of distinct positive integers.

Define a subarray ai,ai+1,…,aj to be a friend group if and only if there exists an integer m≥2 such that aimodm=ai+1modm=…=ajmodm, where xmody denotes the remainder when x is divided by y.

Your friend Gregor wants to know the size of the largest friend group in a.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤2⋅104).

Each test case begins with a line containing the integer n (1≤n≤2⋅105), the size of the array a.

The next line contains n positive integers a1,a2,…,an (1≤ai≤1018), representing the contents of the array a. It is guaranteed that all the numbers in a are distinct.

It is guaranteed that the sum of n over all test cases is less than 2⋅105.

Output
Your output should consist of t lines. Each line should consist of a single integer, the size of the largest friend group in a.

Example
inputCopy
4
5
1 5 2 4 6
4
8 2 5 10
2
1000 2000
8
465 55 3 54 234 12 45 78
outputCopy
3
3
2
6
Note
In the first test case, the array is [1,5,2,4,6]. The largest friend group is [2,4,6], since all those numbers are congruent to 0 modulo 2, so m=2.

In the second test case, the array is [8,2,5,10]. The largest friend group is [8,2,5], since all those numbers are congruent to 2 modulo 3, so m=3.

In the third case, the largest friend group is [1000,2000]. There are clearly many possible values of m that work.


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
ll st[N][26];
ll good(int L, int R) {
	ll j = log2(R - L + 1);
	ll g = gcd(st[L][j], st[R - (1 << j) + 1][j]);
	return g ;
}
void solve() {
	ll n;
	cin >> n;
	vll a(n);
	foi(n) {
		cin >> a[i];
	}
	foi(n - 1) {
		st[i][0] = abs(a[i + 1] - a[i]);
	}
	for (ll j = 1; j <= 25; j++) {
		for (ll i = 0; i + (1 << j) < n; i++) {
			st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	ll ans = 0;
	foi(n - 1) {
		ll l = 0, r = i, t = 1111111111;
		while (l <= r) {
			ll m = (l + r) >> 1;
			if (good(m, i) != 1) {
				t = m;
				r = m - 1;
			}
			else
				l = m + 1;
		}
		ans = max(ans, i - t + 1);
	}
	cout << ans + 1;
}


