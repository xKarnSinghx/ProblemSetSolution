/*
C. Success Rate
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are an experienced Codeforces user. Today you found out that during your activity on Codeforces you have made y submissions, out of which x have been successful. Thus, your current success rate on Codeforces is equal to x / y.

Your favorite rational number in the [0;1] range is p / q. Now you wonder: what is the smallest number of submissions you have to make if you want your success rate to be p / q?

Input
The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.

Each of the next t lines contains four integers x, y, p and q (0 ≤ x ≤ y ≤ 109; 0 ≤ p ≤ q ≤ 109; y > 0; q > 0).

It is guaranteed that p / q is an irreducible fraction.

Hacks. For hacks, an additional constraint of t ≤ 5 must be met.

Output
For each test case, output a single integer equal to the smallest number of submissions you have to make if you want your success rate to be equal to your favorite rational number, or -1 if this is impossible to achieve.

Example
inputCopy
4
3 10 1 2
7 14 3 8
20 70 2 7
5 6 1 1
outputCopy
4
10
0
-1
Note
In the first example, you have to make 4 successful submissions. Your success rate will be equal to 7 / 14, or 1 / 2.

In the second example, you have to make 2 successful and 8 unsuccessful submissions. Your success rate will be equal to 9 / 24, or 3 / 8.

In the third example, there is no need to make any new submissions. Your success rate is already equal to 20 / 70, or 2 / 7.

In the fourth example, the only unsuccessful submission breaks your hopes of having the success rate equal to 1.

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
	ll x, y, p, q;
	cin >> x >> y >> p >> q;
	if (p == 0 ) {
		if (x == 0) {
			cout << 0;
			return;
		}
		cout << -1;
		return;
	}
	if (p == q) {
		if (x == y) {
			cout << 0;
			return;
		}
		cout << -1;
		return;
	}
	ll ans = (y - x + q - p - 1) / (q - p);
	ans = max(ans, (x + p - 1) / p);
	cout << ans*q - y;

}
 
