/*
\
B. Let's Go Hiking
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
On a weekend, Qingshan suggests that she and her friend Daniel go hiking. Unfortunately, they are busy high school students, so they can only go hiking on scratch paper.

A permutation p is written from left to right on the paper. First Qingshan chooses an integer index x (1≤x≤n) and tells it to Daniel. After that, Daniel chooses another integer index y (1≤y≤n, y≠x).

The game progresses turn by turn and as usual, Qingshan moves first. The rules follow:

If it is Qingshan's turn, Qingshan must change x to such an index x′ that 1≤x′≤n, |x′−x|=1, x′≠y, and px′<px at the same time.
If it is Daniel's turn, Daniel must change y to such an index y′ that 1≤y′≤n, |y′−y|=1, y′≠x, and py′>py at the same time.
The person who can't make her or his move loses, and the other wins. You, as Qingshan's fan, are asked to calculate the number of possible x to make Qingshan win in the case both players play optimally.

Input
The first line contains a single integer n (2≤n≤105) — the length of the permutation.

The second line contains n distinct integers p1,p2,…,pn (1≤pi≤n) — the permutation.

Output
Print the number of possible values of x that Qingshan can choose to make her win.

Examples
inputCopy
5
1 2 5 4 3
outputCopy
1
inputCopy
7
1 2 4 6 5 3 7
outputCopy
0
Note
In the first test case, Qingshan can only choose x=3 to win, so the answer is 1.

In the second test case, if Qingshan will choose x=4, Daniel can choose y=1. In the first turn (Qingshan's) Qingshan chooses x′=3 and changes x to 3. In the second turn (Daniel's) Daniel chooses y′=2 and changes y to 2. Qingshan can't choose x′=2 because y=2 at this time. Then Qingshan loses.


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
	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	cin >> a[i];
	ll len = 0, l = 0, mid = 0 , r = 0 ;
	forr(i, 1, n) {
		if (i - mid > len)
			len = i - mid, r = i;
		if (i - mid == len)
			l = mid;
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			mid = i;
		if (a[i] < a[i - 1] && a[i] < a[i + 1])
			mid = i;
	}
	cout << ((l == r) && a[l] > a[l - 1] && a[l] > a[l + 1] && (len % 2 == 0) ? 1 : 0);
}
