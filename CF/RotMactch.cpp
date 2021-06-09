/*
\C. Rotation Matching
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
After the mysterious disappearance of Ashish, his two favourite disciples Ishika and Hriday, were each left with one half of a secret message. These messages can each be represented by a permutation of size n. Let's call them a and b.

Note that a permutation of n elements is a sequence of numbers a1,a2,…,an, in which every number from 1 to n appears exactly once.

The message can be decoded by an arrangement of sequence a and b, such that the number of matching pairs of elements between them is maximum. A pair of elements ai and bj is said to match if:

i=j, that is, they are at the same index.
ai=bj
His two disciples are allowed to perform the following operation any number of times:

choose a number k and cyclically shift one of the permutations to the left or right k times.
A single cyclic shift to the left on any permutation c is an operation that sets c1:=c2,c2:=c3,…,cn:=c1 simultaneously. Likewise, a single cyclic shift to the right on any permutation c is an operation that sets c1:=cn,c2:=c1,…,cn:=cn−1 simultaneously.

Help Ishika and Hriday find the maximum number of pairs of elements that match after performing the operation any (possibly zero) number of times.

Input
The first line of the input contains a single integer n (1≤n≤2⋅105) — the size of the arrays.

The second line contains n integers a1, a2, ..., an (1≤ai≤n) — the elements of the first permutation.

The third line contains n integers b1, b2, ..., bn (1≤bi≤n) — the elements of the second permutation.

Output
Print the maximum number of matching pairs of elements after performing the above operations some (possibly zero) times.

Examples
inputCopy
5
1 2 3 4 5
2 3 4 5 1
outputCopy
5
inputCopy
5
5 4 3 2 1
1 2 3 4 5
outputCopy
1
inputCopy
4
1 3 2 4
4 2 3 1
outputCopy
2
Note
For the first case: b can be shifted to the right by k=1. The resulting permutations will be {1,2,3,4,5} and {1,2,3,4,5}.

For the second case: The operation is not required. For all possible rotations of a and b, the number of matching pairs won't exceed 1.

For the third case: b can be shifted to the left by k=1. The resulting permutations will be {1,3,2,4} and {2,3,1,4}. Positions 2 and 4 have matching pairs of elements. For all possible rotations of a and b, the number of matching pairs won't exceed 2.


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
	vll a(n, 0);
	mll m;
	foi(n) {
		ll x;
		cin >> x;
		x--;
		a[x] = i;
	}
	foi(n) {
		ll x;
		cin >> x;
		x--;
		x = a[x] - i;
		if (x < 0)
			x += n;
		m[x]++;
	}
	ll ans = 0;
	for (auto it : m) {
		ans = max(ans, it.ss);
	}
	cout << ans;
}
