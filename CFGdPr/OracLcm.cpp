/*
C. Orac and LCM
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
For the multiset of positive integers s={s1,s2,…,sk}, define the Greatest Common Divisor (GCD) and Least Common Multiple (LCM) of s as follow:

gcd(s) is the maximum positive integer x, such that all integers in s are divisible on x.
lcm(s) is the minimum positive integer x, that divisible on all integers from s.
For example, gcd({8,12})=4,gcd({12,18,6})=6 and lcm({4,6})=12. Note that for any positive integer x, gcd({x})=lcm({x})=x.

Orac has a sequence a with length n. He come up with the multiset t={lcm({ai,aj}) | i<j}, and asked you to find the value of gcd(t) for him. In other words, you need to calculate the GCD of LCMs of all pairs of elements in the given sequence.

Input
The first line contains one integer n (2≤n≤100000).

The second line contains n integers, a1,a2,…,an (1≤ai≤200000).

Output
Print one integer: gcd({lcm({ai,aj}) | i<j}).

Examples
inputCopy
2
1 1
outputCopy
1
inputCopy
4
10 24 40 80
outputCopy
40
inputCopy
10
540 648 810 648 720 540 594 864 972 648
outputCopy
54
Note
For the first example, t={lcm({1,1})}={1}, so gcd(t)=1.

For the second example, t={120,40,80,120,240,80}, and it's not hard to see that gcd(t)=40.


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
	ll n;
	cin >> n;
	graph fact(200001);
	foi(n) {
		ll x;
		cin >> x;
		for (ll j = 2; j * j <= x; j++) {
			ll cnt = 0;
			if (x % j == 0) {
				while (x % j == 0) {
					x /= j;
					cnt++;
				}
				fact[j].pb(cnt);
			}
		}
		if (x > 1)
			fact[x].pb(1ll);
	}
	ll ans = 1;
	for (ll i = 2; i < 200001; i++) {
		sort(all(fact[i]));
		if (fact[i].size() == n) {
			foj(fact[i][1])
			ans *= i;
		}
		else if (fact[i].size() == n - 1) {
			foj(fact[i][0])
			ans *= i;
		}
	}
	cout << ans;
}
 
