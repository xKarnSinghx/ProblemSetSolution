/*
D. Frog Traveler
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
Frog Gorf is traveling through Swamp kingdom. Unfortunately, after a poor jump, he fell into a well of n meters depth. Now Gorf is on the bottom of the well and has a long way up.

The surface of the well's walls vary in quality: somewhere they are slippery, but somewhere have convenient ledges. In other words, if Gorf is on x meters below ground level, then in one jump he can go up on any integer distance from 0 to ax meters inclusive. (Note that Gorf can't jump down, only up).

Unfortunately, Gorf has to take a break after each jump (including jump on 0 meters). And after jumping up to position x meters below ground level, he'll slip exactly bx meters down while resting.

Calculate the minimum number of jumps Gorf needs to reach ground level.

Input
The first line contains a single integer n (1≤n≤300000) — the depth of the well.

The second line contains n integers a1,a2,…,an (0≤ai≤i), where ai is the maximum height Gorf can jump from i meters below ground level.

The third line contains n integers b1,b2,…,bn (0≤bi≤n−i), where bi is the distance Gorf will slip down if he takes a break on i meters below ground level.

Output
If Gorf can't reach ground level, print −1. Otherwise, firstly print integer k — the minimum possible number of jumps.

Then print the sequence d1,d2,…,dk where dj is the depth Gorf'll reach after the j-th jump, but before he'll slip down during the break. Ground level is equal to 0.

If there are multiple answers, print any of them.

Examples
inputCopy
3
0 2 2
1 1 0
outputCopy
2
1 0 
inputCopy
2
1 1
1 0
outputCopy
-1
inputCopy
10
0 1 2 3 5 5 6 7 8 5
9 8 7 1 5 4 3 2 0 0
outputCopy
3
9 4 0 
Note
In the first example, Gorf is on the bottom of the well and jump to the height 1 meter below ground level. After that he slip down by meter and stays on height 2 meters below ground level. Now, from here, he can reach ground level in one jump.

In the second example, Gorf can jump to one meter below ground level, but will slip down back to the bottom of the well. That's why he can't reach ground level.

In the third example, Gorf can reach ground level only from the height 5 meters below the ground level. And Gorf can reach this height using a series of jumps 10⇒9⇢9⇒4⇢5 where ⇒ is the jump and ⇢ is slipping during breaks.


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
const ll N = 200010;
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
ll ask(ll x, ll y, ll n) {
	cout << "?" << " ";
	foi(n - 1) {
		cout << x << " ";
	}
	cout << y << endl;
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
void solve() {
	ll n;
	cin >> n;
	vll a(n, 0), b(n, 0), c(n + 1, 0);
	foi(n) {
		cin >> a[i];
	}
	foi(n) {
		cin >> b[i];
	}
	foi(n) {
		c[i + 1] = (i + 1 - a[i  +  b[i]] + b[i]);
		if (c[i + 1] < 0)
			c[i + 1] = 0;
	}
	ll cur = c[n], prev = n;
	vll ans;
	while (cur) {
		ll mn = prev;
		for (ll i = cur; i < prev; i++)
			if (c[i] < c[mn])
				mn = i;
		if (mn == prev)
			break;
		ans.pb(mn);
		prev = cur;
		cur = c[mn];
	}
	if (cur) {
		cout << -1;
		return ;
	}
	cout << ans.size() + 1 << endl;
	foi(ans.size()) {
		cout << ans[i] << " ";
	}
	cout << 0;
}



