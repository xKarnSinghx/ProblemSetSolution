/*
A. Polo the Penguin and Segments
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little penguin Polo adores integer segments, that is, pairs of integers [l; r] (l ≤ r).

He has a set that consists of n integer segments: [l1; r1], [l2; r2], ..., [ln; rn]. We know that no two segments of this set intersect. In one move Polo can either widen any segment of the set 1 unit to the left or 1 unit to the right, that is transform [l; r] to either segment [l - 1; r], or to segment [l; r + 1].

The value of a set of segments that consists of n segments [l1; r1], [l2; r2], ..., [ln; rn] is the number of integers x, such that there is integer j, for which the following inequality holds, lj ≤ x ≤ rj.

Find the minimum number of moves needed to make the value of the set of Polo's segments divisible by k.

Input
The first line contains two integers n and k (1 ≤ n, k ≤ 105). Each of the following n lines contain a segment as a pair of integers li and ri ( - 105 ≤ li ≤ ri ≤ 105), separated by a space.

It is guaranteed that no two segments intersect. In other words, for any two integers i, j (1 ≤ i < j ≤ n) the following inequality holds, min(ri, rj) < max(li, lj).

Output
In a single line print a single integer — the answer to the problem.

Examples
inputCopy
2 3
1 2
3 4
outputCopy
2
inputCopy
3 7
1 2
3 3
4 7
outputCopy
0
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
#define graph          vector<vector<int>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair<ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
#define MOD  1000000007;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


		solve();


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}
bool isPrime(ll n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
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
ll fac(ll n) {
	while (n % 4 == 0) {
		n /= 4;
	}
	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % (i * i) == 0) {
			n /= (i * i);
		}
	}
	return n;
}
void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n], b[n];
	foi(n)
	cin >> a[i] >> b[i];
	ll s = 0;
	foi(n)
	s += abs(a[i] - b[i]) + 1;
	if (s % k == 0)
		cout << 0;
	else
		cout << k - s % k;


}
