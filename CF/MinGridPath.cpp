/*
C. Minimum Grid Path
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's say you are standing on the XY-plane at point (0,0) and you want to reach point (n,n).

You can move only in two directions:

to the right, i. e. horizontally and in the direction that increase your x coordinate,
or up, i. e. vertically and in the direction that increase your y coordinate.
In other words, your path will have the following structure:

initially, you choose to go to the right or up;
then you go some positive integer distance in the chosen direction (distances can be chosen independently);
after that you change your direction (from right to up, or from up to right) and repeat the process.
You don't like to change your direction too much, so you will make no more than n−1 direction changes.

As a result, your path will be a polygonal chain from (0,0) to (n,n), consisting of at most n line segments where each segment has positive integer length and vertical and horizontal segments alternate.

Not all paths are equal. You have n integers c1,c2,…,cn where ci is the cost of the i-th segment.

Using these costs we can define the cost of the path as the sum of lengths of the segments of this path multiplied by their cost, i. e. if the path consists of k segments (k≤n), then the cost of the path is equal to ∑i=1kci⋅lengthi (segments are numbered from 1 to k in the order they are in the path).

Find the path of the minimum cost and print its cost.

Input
The first line contains the single integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains the single integer n (2≤n≤105).

The second line of each test case contains n integers c1,c2,…,cn (1≤ci≤109) — the costs of each segment.

It's guaranteed that the total sum of n doesn't exceed 105.

Output
For each test case, print the minimum possible cost of the path from (0,0) to (n,n) consisting of at most n alternating segments.

Example
inputCopy
3
2
13 88
3
2 3 1
5
4 3 2 1 4
outputCopy
202
13
19
Note
In the first test case, to reach (2,2) you need to make at least one turn, so your path will consist of exactly 2 segments: one horizontal of length 2 and one vertical of length 2. The cost of the path will be equal to 2⋅c1+2⋅c2=26+176=202.

In the second test case, one of the optimal paths consists of 3 segments: the first segment of length 1, the second segment of length 3 and the third segment of length 2.

The cost of the path is 1⋅2+3⋅3+2⋅1=13.

In the third test case, one of the optimal paths consists of 4 segments: the first segment of length 1, the second one — 1, the third one — 4, the fourth one — 4. The cost of the path is 1⋅4+1⋅3+4⋅2+4⋅1=19.
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
	ll a[n], mn = 1111111111111, mn1 = 111111111111111;
	foi(n) {
		cin >> a[i];

	}
	ll x = 0, y = 1;
	ll ans = (a[0] + a[1]) * n, cnt0 = 1, cnt1 = 1, sum0 = a[0], sum1 = a[1];
	mn = a[0], mn1 = a[1];
	for (ll i = 2; i < n; i++) {
		if (i % 2 == 0) {
			mn = min(mn, a[i]);
			cnt0++;
			sum0 += a[i];
			ans = min(ans, mn * (n - cnt0 + 1) + (sum0 - mn) + mn1 * (n - cnt1 + 1) + (sum1 -  mn1));
			cout << ans << " ";
		}
		else {
			mn1 = min(mn1, a[i]);
			sum1 += a[i];
			cnt1++;
			ans = min(ans, mn * (n - cnt0 + 1) + (sum0 - mn) + mn1 * (n - cnt1 + 1) + (sum1 -  mn1));
			cout << ans << " ";
		}
	}
	cout << ans;
}
