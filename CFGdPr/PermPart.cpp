/*
C. Permutation Partitions
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a permutation p1,p2,…,pn of integers from 1 to n and an integer k, such that 1≤k≤n. A permutation means that every number from 1 to n is contained in p exactly once.

Let's consider all partitions of this permutation into k disjoint segments. Formally, a partition is a set of segments {[l1,r1],[l2,r2],…,[lk,rk]}, such that:

1≤li≤ri≤n for all 1≤i≤k;
For all 1≤j≤n there exists exactly one segment [li,ri], such that li≤j≤ri.
Two partitions are different if there exists a segment that lies in one partition but not the other.

Let's calculate the partition value, defined as ∑i=1kmaxli≤j≤ripj, for all possible partitions of the permutation into k disjoint segments. Find the maximum possible partition value over all such partitions, and the number of partitions with this value. As the second value can be very large, you should find its remainder when divided by 998244353.

Input
The first line contains two integers, n and k (1≤k≤n≤200000) — the size of the given permutation and the number of segments in a partition.

The second line contains n different integers p1,p2,…,pn (1≤pi≤n) — the given permutation.

Output
Print two integers — the maximum possible partition value over all partitions of the permutation into k disjoint segments and the number of such partitions for which the partition value is equal to the maximum possible value, modulo 998244353.

Please note that you should only find the second value modulo 998244353.

Examples
inputCopy
3 2
2 1 3
outputCopy
5 2
inputCopy
5 5
2 1 5 3 4
outputCopy
15 1
inputCopy
7 3
2 7 3 1 5 4 6
outputCopy
18 6
Note
In the first test, for k=2, there exists only two valid partitions: {[1,1],[2,3]} and {[1,2],[3,3]}. For each partition, the partition value is equal to 2+3=5. So, the maximum possible value is 5 and the number of partitions is 2.

In the third test, for k=3, the partitions with the maximum possible partition value are {[1,2],[3,5],[6,7]}, {[1,3],[4,5],[6,7]}, {[1,4],[5,5],[6,7]}, {[1,2],[3,6],[7,7]}, {[1,3],[4,6],[7,7]}, {[1,4],[5,6],[7,7]}. For all of them, the partition value is equal to 7+5+6=18.

The partition {[1,2],[3,4],[5,7]}, however, has the partition value 7+3+6=16. This is not the maximum possible value, so we don't count it.


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
	ll n, k;
	cin >> n >> k;
	ll s = 0, ans = 1;
	vll id;
	foi(n) {
		ll x;
		cin >> x;
		if (x >= n - k + 1) {
			s += x;
			id.pb(i);
		}
	}
	sort(all(id));
	for (ll i = 1; i < id.size(); i++) {
		ans *= (id[i] - id[i - 1]);
		ans %= modx;
	}
	cout << s << " " << ans;
}
 
