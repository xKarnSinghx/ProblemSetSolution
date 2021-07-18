/*
C. Kuroni and Impossible Calculation
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
To become the king of Codeforces, Kuroni has to solve the following problem.

He is given n numbers a1,a2,…,an. Help Kuroni to calculate ∏1≤i<j≤n|ai−aj|. As result can be very big, output it modulo m.

If you are not familiar with short notation, ∏1≤i<j≤n|ai−aj| is equal to |a1−a2|⋅|a1−a3|⋅ … ⋅|a1−an|⋅|a2−a3|⋅|a2−a4|⋅ … ⋅|a2−an|⋅ … ⋅|an−1−an|. In other words, this is the product of |ai−aj| for all 1≤i<j≤n.

Input
The first line contains two integers n, m (2≤n≤2⋅105, 1≤m≤1000) — number of numbers and modulo.

The second line contains n integers a1,a2,…,an (0≤ai≤109).

Output
Output the single number — ∏1≤i<j≤n|ai−aj|modm.

Examples
inputCopy
2 10
8 5
outputCopy
3
inputCopy
3 12
1 4 5
outputCopy
0
inputCopy
3 7
1 4 9
outputCopy
1
Note
In the first sample, |8−5|=3≡3mod10.

In the second sample, |1−4|⋅|1−5|⋅|4−5|=3⋅4⋅1=12≡0mod12.

In the third sample, |1−4|⋅|1−9|⋅|4−9|=3⋅8⋅5=120≡1mod7.


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
	vll a(m, -1);
	foi(n) {
		ll x;
		cin >> x;
		if (a[x % m] != -1) {
			cout << 0;
			return;
		}
		a[x % m] = x;
	}
	ll ans = 1;
	foi(m) {
		foj(i) {
			if (a[i] != -1 and a[j] != -1) {
				ans = ans * abs(a[i] - a[j]) % m;
			}
		}
	}
	cout << ans;
}
 
