/*
C. Three Bags
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given three bags. Each bag contains a non-empty multiset of numbers. You can perform a number of operations on these bags. In one operation, you can choose any two non-empty bags, and choose one number from each of the bags. Let's say that you choose number a from the first bag and number b from the second bag. Then, you remove b from the second bag and replace a with a−b in the first bag. Note that if there are multiple occurrences of these numbers, then you shall only remove/replace exactly one occurrence.

You have to perform these operations in such a way that you have exactly one number remaining in exactly one of the bags (the other two bags being empty). It can be shown that you can always apply these operations to receive such a configuration in the end. Among all these configurations, find the one which has the maximum number left in the end.

Input
The first line of the input contains three space-separated integers n1, n2 and n3 (1≤n1,n2,n3≤3⋅105, 1≤n1+n2+n3≤3⋅105) — the number of numbers in the three bags.

The i-th of the next three lines contain ni space-separated integers ai,1, ai,2, ..., ai,ni (1≤ai,j≤109) — the numbers in the i-th bag.

Output
Print a single integer — the maximum number which you can achieve in the end.

Examples
inputCopy
2 4 1
1 2
6 3 4 5
5
outputCopy
20
inputCopy
3 2 2
7 5 4
2 9
7 1
outputCopy
29
Note
In the first example input, let us perform the following operations:

[1,2],[6,3,4,5],[5]
[−5,2],[3,4,5],[5] (Applying an operation to (1,6))

[−10,2],[3,4],[5] (Applying an operation to (−5,5))

[2],[3,4],[15] (Applying an operation to (5,−10))

[−1],[4],[15] (Applying an operation to (2,3))

[−5],[],[15] (Applying an operation to (−1,4))

[],[],[20] (Applying an operation to (15,−5))

You can verify that you cannot achieve a bigger number. Hence, the answer is 20.


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
const ll MOD = 1000000007;
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
	ll n[3], f[3], s[3];
	foi(3) {
		cin >> n[i];
		f[i] = 11111111111111;
		s[i] = 0;
	}
	foi(3) {
		while (n[i]-- ) {
			ll x;
			cin >> x;
			s[i] += x, f[i] = min(f[i], x);
		}
	}
	sort(s , s + 3);
	sort(f , f + 3);
	cout << s[0] + s[1] + s[2] - 2 * min(s[0], f[0] + f[1]);
}
