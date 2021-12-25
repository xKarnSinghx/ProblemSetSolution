/*
C. Menorah
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n candles on a Hanukkah menorah, and some of its candles are initially lit. We can describe which candles are lit with a binary string s, where the i-th candle is lit if and only if si=1.


Initially, the candle lights are described by a string a. In an operation, you select a candle that is currently lit. By doing so, the candle you selected will remain lit, and every other candle will change (if it was lit, it will become unlit and if it was unlit, it will become lit).

You would like to make the candles look the same as string b. Your task is to determine if it is possible, and if it is, find the minimum number of operations required.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases. Then t cases follow.

The first line of each test case contains a single integer n (1≤n≤105) — the number of candles.

The second line contains a string a of length n consisting of symbols 0 and 1 — the initial pattern of lights.

The third line contains a string b of length n consisting of symbols 0 and 1 — the desired pattern of lights.

It is guaranteed that the sum of n does not exceed 105.

Output
For each test case, output the minimum number of operations required to transform a to b, or −1 if it's impossible.

Example
inputCopy
5
5
11010
11010
2
01
11
3
000
101
9
100010111
101101100
9
001011011
011010101
outputCopy
0
1
-1
3
4
Note
In the first test case, the two strings are already equal, so we don't have to perform any operations.

In the second test case, we can perform a single operation selecting the second candle to transform 01 into 11.

In the third test case, it's impossible to perform any operations because there are no lit candles to select.

In the fourth test case, we can perform the following operations to transform a into b:

Select the 7-th candle: 100010111→011101100.
Select the 2-nd candle: 011101100→110010011.
Select the 1-st candle: 110010011→101101100.
In the fifth test case, we can perform the following operations to transform a into b:

Select the 6-th candle: 001011011→110101100
Select the 2-nd candle: 110101100→011010011
Select the 8-th candle: 011010011→100101110
Select the 7-th candle: 100101110→011010101
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
const ll modx = 998244353;
ld PI = 3.1415926535897;
const ll N = 1000100;
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
void solve() {
	ll n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0;
		return;
	}
	ll z = count(all(a), '0');
	if (z == n) {
		cout << -1;
		return;
	}
	ll c = 0, c1 = 0, z1 = 0, ans = MOD;
	foi(n) {
		if (a[i] == b[i]) {
			c++;
			if (a[i] == '1')
				c1++;
		}
		else {
			if (a[i] == '1')
				z1++;
		}
	}
	if (c % 2  and (c + 1) / 2 == c1) {
		ans = min(ans, c);
	}
	if ((n - c) % 2 == 0  and (n - c ) / 2 == z1) {
		ans = min(ans, n - c);
	}
	(ans == MOD) ? cout << -1 : cout << ans;
}
