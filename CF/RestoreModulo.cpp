/*
B. Restore Modulo
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
For the first place at the competition, Alex won many arrays of integers and was assured that these arrays are very expensive. After the award ceremony Alex decided to sell them. There is a rule in arrays pawnshop: you can sell array only if it can be compressed to a generator.

This generator takes four non-negative numbers n, m, c, s. n and m must be positive, s non-negative and for c it must be true that 0≤c<m. The array a of length n is created according to the following rules:

a1=smodm, here xmody denotes remainder of the division of x by y;
ai=(ai−1+c)modm for all i such that 1<i≤n.
For example, if n=5, m=7, c=4, and s=10, then a=[3,0,4,1,5].

Price of such an array is the value of m in this generator.

Alex has a question: how much money he can get for each of the arrays. Please, help him to understand for every array whether there exist four numbers n, m, c, s that generate this array. If yes, then maximize m.

Input
The first line contains a single integer t (1≤t≤105) — the number of arrays.

The first line of array description contains a single integer n (1≤n≤105) — the size of this array.

The second line of array description contains n integers a1,a2,…,an (0≤ai≤109 ) — elements of the array.

It is guaranteed that the sum of array sizes does not exceed 105.

Output
For every array print:

−1, if there are no such four numbers that generate this array;
0, if m can be arbitrary large;
the maximum value m and any appropriate c (0≤c<m) in other cases.
Example
inputCopy
6
6
1 9 17 6 14 3
3
4 2 2
3
7 3 4
3
2 2 4
5
0 1000000000 0 1000000000 0
2
1 1
outputCopy
19 8
-1
-1
-1
2000000000 1000000000
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
	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	cin >> a[i];
	ll c = a[1] - a[0];
	ll k = 0, ans = 0, m = 0;
	for (ll i = 1; i < n - 1; i++) {
		if (a[i] + c != a[i + 1]) {
			k = abs(a[i] + c - a[i + 1]);
			ans = 1;
			if (m % k)
			{ans = -1;}
			else m = k;
		}
	}
	foi(n) {
		if (a[i] >= m && m)
			ans = -1;

	}
	if (c <= 0)
		c += m ;
	if (m) {
		foi(n - 1)
		if ((a[i] + c) % m != a[i + 1])
			ans = -1;
	}
	if (ans <= 0)
		cout << ans;
	else
		cout << m << " " << c;


}
