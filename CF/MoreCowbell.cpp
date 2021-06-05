/*
B. More Cowbell
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kevin Sun wants to move his precious collection of n cowbells from Naperthrill to Exeter, where there is actually grass instead of corn. Before moving, he must pack his cowbells into k boxes of a fixed size. In order to keep his collection safe during transportation, he won't place more than two cowbells into a single box. Since Kevin wishes to minimize expenses, he is curious about the smallest size box he can use to pack his entire collection.

Kevin is a meticulous cowbell collector and knows that the size of his i-th (1 ≤ i ≤ n) cowbell is an integer si. In fact, he keeps his cowbells sorted by size, so si - 1 ≤ si for any i > 1. Also an expert packer, Kevin can fit one or two cowbells into a box of size s if and only if the sum of their sizes does not exceed s. Given this information, help Kevin determine the smallest s for which it is possible to put all of his cowbells into k boxes of size s.

Input
The first line of the input contains two space-separated integers n and k (1 ≤ n ≤ 2·k ≤ 100 000), denoting the number of cowbells and the number of boxes, respectively.

The next line contains n space-separated integers s1, s2, ..., sn (1 ≤ s1 ≤ s2 ≤ ... ≤ sn ≤ 1 000 000), the sizes of Kevin's cowbells. It is guaranteed that the sizes si are given in non-decreasing order.

Output
Print a single integer, the smallest s for which it is possible for Kevin to put all of his cowbells into k boxes of size s.

Examples
inputCopy
2 1
2 5
outputCopy
7
inputCopy
4 3
2 3 5 9
outputCopy
9
inputCopy
3 2
3 5 7
outputCopy
8
Note
In the first sample, Kevin must pack his two cowbells into the same box.

In the second sample, Kevin can pack together the following sets of cowbells: {2, 3}, {5} and {9}.

In the third sample, the optimal solution is {3, 5} and {7}.


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
	vll s(n);
	foi(n) {
		ll x;
		cin >> x;
		s[i] = x;
	}
	ll ans = s[n - 1];
	if (k >= n) {
		cout << ans;
		return;
	}
	else {
		foi(n - k) {
			ans = max(ans, s[i] + s[2 * (n - k) - i - 1]);
		}
		cout << ans;
	}

}
