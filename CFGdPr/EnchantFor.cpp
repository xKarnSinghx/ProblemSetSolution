/*
D. The Enchanted Forest
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The enchanted forest got its name from the magical mushrooms growing here. They may cause illusions and generally should not be approached.
—Perfect Memento in Strict Sense
Marisa comes to pick mushrooms in the Enchanted Forest.

The Enchanted forest can be represented by n points on the X-axis numbered 1 through n. Before Marisa started, her friend, Patchouli, used magic to detect the initial number of mushroom on each point, represented by a1,a2,…,an.

Marisa can start out at any point in the forest on minute 0. Each minute, the followings happen in order:

She moves from point x to y (|x−y|≤1, possibly y=x).
She collects all mushrooms on point y.
A new mushroom appears on each point in the forest.
Note that she cannot collect mushrooms on minute 0.

Now, Marisa wants to know the maximum number of mushrooms she can pick after k minutes.

Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n, k (1≤n≤2⋅105, 1≤k≤109) — the number of positions with mushrooms and the time Marisa has, respectively.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the initial number of mushrooms on point 1,2,…,n.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print the maximum number of mushrooms Marisa can pick after k minutes.

Example
inputCopy
4
5 2
5 6 1 2 3
5 7
5 6 1 2 3
1 2
999999
5 70000
1000000000 1000000000 1000000000 1000000000 1000000000
outputCopy
12
37
1000000
5000349985
Note
Test case 1:

Marisa can start at x=2. In the first minute, she moves to x=1 and collect 5 mushrooms. The number of mushrooms will be [1,7,2,3,4]. In the second minute, she moves to x=2 and collects 7 mushrooms. The numbers of mushrooms will be [2,1,3,4,5]. After 2 minutes, Marisa collects 12 mushrooms.

It can be shown that it is impossible to collect more than 12 mushrooms.

Test case 2:

This is one of her possible moving path:

2→3→2→1→2→3→4→5
It can be shown that it is impossible to collect more than 37 mushrooms.


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
bool isPrime(ll n) {
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
void solve() {
	ll n, k;
	cin >> n >> k;
	vll a(n + 1, 0);
	ll s = 0;
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x, s += x;
		if (i)
			a[i] += a[i - 1];
	}
	if (k > n) {
		cout << s + k*(k - 1) / 2 - (k - n)*(k - n - 1) / 2;
		return;
	}
	ll ans = 0;
	foi(n) {
		if (i >= k) {
			ans = max(ans, a[i] - a[i - k]);
		}
		else if (i == k - 1) {
			ans = max(ans, a[i]);
		}
	}
	cout << ans + k*(k - 1) / 2;

}
