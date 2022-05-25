/*
D. Required Length
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
You are given two integer numbers, n and x. You may perform several operations with the integer x.

Each operation you perform is the following one: choose any digit y that occurs in the decimal representation of x at least once, and replace x by x⋅y.

You want to make the length of decimal representation of x (without leading zeroes) equal to n. What is the minimum number of operations required to do that?

Input
The only line of the input contains two integers n and x (2≤n≤19; 1≤x<10n−1).

Output
Print one integer — the minimum number of operations required to make the length of decimal representation of x (without leading zeroes) equal to n, or −1 if it is impossible.

Examples
inputCopy
2 1
outputCopy
-1
inputCopy
3 2
outputCopy
4
inputCopy
13 42
outputCopy
12
Note
In the second example, the following sequence of operations achieves the goal:

multiply x by 2, so x=2⋅2=4;
multiply x by 4, so x=4⋅4=16;
multiply x by 6, so x=16⋅6=96;
multiply x by 9, so x=96⋅9=864.

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
const ll N = 1000001;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
// 	ll t; cin >> t;
// 	while (t--)
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
multiset<ll> Lis(vll a) {
	multiset<ll> S;
	multiset<ll>::iterator it;
	foi(a.size()) {
		S.insert(a[i]);
		it = S.lower_bound(a[i]);
		it++;
		if (it != S.end()) S.erase(it);
	}
	return S;
}
ll len(ll x) {
	ll s = 0;
	while (x) {
		s++, x /= 10;
	}
	return s;
}
void solve() {
	ll n, x;
	cin >> n >> x;
	ll cnt = 0;
	queue<ll>q;
	mll m;
	q.push(x);
	m[x]++;
	while (!q.empty()) {
		ll sz = q.size();
		foi(sz) {
			ll y = q.front();
			q.pop();
			ll t = y;
			set <ll>s, s1;
			while (t) {
				if (t % 10 > 1) {
					s.insert(t % 10);
				}
				t /= 10;
			}
			t = y;
			if (len(t) == n) {
				cout << cnt;
				return;
			}
			for (ll it : s) {
				s1.insert(it * t);
			}
			for (ll it : s1) {
				if (m.find(it) == m.end())
					q.push(it), m[it]++;;
			}
		}
		cnt++;
	}

	cout << -1;
}
