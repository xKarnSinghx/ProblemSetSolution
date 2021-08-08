/*
D. Fill The Bag
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a bag of size n. Also you have m boxes. The size of i-th box is ai, where each ai is an integer non-negative power of two.

You can divide boxes into two parts of equal size. Your goal is to fill the bag completely.

For example, if n=10 and a=[1,1,32] then you have to divide the box of size 32 into two parts of size 16, and then divide the box of size 16. So you can fill the bag with boxes of size 1, 1 and 8.

Calculate the minimum number of divisions required to fill the bag of size n.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains two integers n and m (1≤n≤1018,1≤m≤105) — the size of bag and the number of boxes, respectively.

The second line of each test case contains m integers a1,a2,…,am (1≤ai≤109) — the sizes of boxes. It is guaranteed that each ai is a power of two.

It is also guaranteed that sum of all m over all test cases does not exceed 105.

Output
For each test case print one integer — the minimum number of divisions required to fill the bag of size n (or −1, if it is impossible).

Example
inputCopy
3
10 3
1 32 1
23 4
16 1 4 1
20 5
2 1 16 1 8
outputCopy
2
-1
0
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
void solve() {
	ll n, m;
	cin >> n >> m;
	multiset<ll, greater<ll>> s;
	ll s1 = 0;
	foi(m) {
		ll x;
		cin >> x;
		s.insert(x);
		s1 += x;
	}
	if (s1 < n) {
		cout << -1;
		return;
	}
	ll ans = 0;
	while (!s.empty()) {
		ll b = *s.begin();
		s.erase(s.begin());
		if (b <= n) {
			n -= b, s1 -= b;
		} else if (s1 - b < n) {
			s.insert(b / 2);
			s.insert(b / 2);
			ans++;
		} else {
			s1 -= b;
		}
	}
	cout << ans;
}



