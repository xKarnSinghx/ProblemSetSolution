/*
C. Factorials and Powers of Two
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A number is called powerful if it is a power of two or a factorial. In other words, the number m is powerful if there exists a non-negative integer d such that m=2d or m=d!, where d!=1⋅2⋅…⋅d (in particular, 0!=1). For example 1, 4, and 6 are powerful numbers, because 1=1!, 4=22, and 6=3! but 7, 10, or 18 are not.

You are given a positive integer n. Find the minimum number k such that n can be represented as the sum of k distinct powerful numbers, or say that there is no such k.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

A test case consists of only one line, containing one integer n (1≤n≤1012).

Output
For each test case print the answer on a separate line.

If n can not be represented as the sum of distinct powerful numbers, print −1.

Otherwise, print a single positive integer  — the minimum possible value of k.

Example
inputCopy
4
7
11
240
17179869184
outputCopy
2
3
4
1
Note
In the first test case, 7 can be represented as 7=1+6, where 1 and 6 are powerful numbers. Because 7 is not a powerful number, we know that the minimum possible value of k in this case is k=2.

In the second test case, a possible way to represent 11 as the sum of three powerful numbers is 11=1+4+6. We can show that there is no way to represent 11 as the sum of two or less powerful numbers.

In the third test case, 240 can be represented as 240=24+32+64+120. Observe that 240=120+120 is not a valid representation, because the powerful numbers have to be distinct.

In the fourth test case, 17179869184=234, so 17179869184 is a powerful number and the minimum k in this case is k=1.


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
int main() {
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
void solve() {
	ll n;
	cin >> n;
	ll ans = (ll)__builtin_popcountll(n);
	vll fact;
	ll p = 1;
	foi(15) {
		fact.pb(p * (i + 1));
		p *= (i + 1);
	}
	foi((1 << 15) + 1) {
		ll cnt = 0, nw = n;
		foj(15) {
			if ((i >> j) & 1) {
				nw -= fact[j];
				cnt++;
			}
		}
		if (nw < 0)
			continue;
		ans = min(ans, cnt + __builtin_popcountll(nw));
	}
	cout << ans;

}
