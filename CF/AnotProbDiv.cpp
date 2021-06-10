/*
D. Another Problem About Dividing Numbers
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two integers a and b. In one turn, you can do one of the following operations:

Take an integer c (c>1 and a should be divisible by c) and replace a with ac;
Take an integer c (c>1 and b should be divisible by c) and replace b with bc.
Your goal is to make a equal to b using exactly k turns.

For example, the numbers a=36 and b=48 can be made equal in 4 moves:

c=6, divide b by c ⇒ a=36, b=8;
c=2, divide a by c ⇒ a=18, b=8;
c=9, divide a by c ⇒ a=2, b=8;
c=4, divide b by c ⇒ a=2, b=2.
For the given numbers a and b, determine whether it is possible to make them equal using exactly k turns.

Input
The first line contains one integer t (1≤t≤104). Then t test cases follow.

Each test case is contains three integers a, b and k (1≤a,b,k≤109).

Output
For each test case output:

"Yes", if it is possible to make the numbers a and b equal in exactly k turns;
"No" otherwise.
The strings "Yes" and "No" can be output in any case.

Example
inputCopy
8
36 48 2
36 48 3
36 48 4
2 8 1
2 8 2
1000000000 1000000000 1000000000
1 2 1
2 2 1
outputCopy
YES
YES
YES
YES
YES
NO
YES
NO

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
typedef map<pair<ll, ll>, ll>  mplll;
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
vll div1(100001, 1), ans;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	div1[0] = 0, div1[1] = 0;
	foi(100001) {
		if (div1[i] == 1) {
			ans.pb(i);
			for (ll j = i + i; j < 100001; j += i) {
				div1[j] = 0;
			}
		}
	}
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
	ll a, b, k;
	cin >> a >> b >> k;
	if (a != b and k == 0) {
		cout << "No";
		return;
	}
	if (a == b and k == 1) {
		cout << "No";
		return;
	}
	ll g = gcd(a, b), l = 0, r = 0;
	if (a / g == 1)
		l = l;
	else
		l++;
	if (b / g == 1)
		l = l;
	else
		l++;
	ll cnt = 0;
	foi(ans.size()) {
		while (a % ans[i] == 0) {
			a /= ans[i], cnt++;
		}
		while (b % ans[i] == 0) {
			b /= ans[i], cnt++;
		}
	}
	if (a != 1)
		cnt++;
	if (b != 1)
		cnt++;
	r = cnt;
	if (k >= l and k <= r) {
		cout << "Yes";
		return;
	}
	cout << "No";

}
