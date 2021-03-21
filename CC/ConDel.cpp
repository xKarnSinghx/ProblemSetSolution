/*
You are given a positive integer K and a sequence A1,A2,…,AN. Initially, each element of this sequence is 0 or 1; your goal is to make all elements equal to 0

.

In order to do that, you may perform the following operation any number of times:

    Choose a subarray (a contiguous subsequence) with length K

, i.e. choose two indices L and R such that 1≤L≤R≤N and R−L+1=K
.
Choose one element of that subarray and change it to 0
, i.e. choose an index P such that L≤P≤R and change AP to 0
.
The cost of this operation is the sum of this subarray AL+AL+1+…+AR
before AP

    is changed.

Find the minimum total cost (sum of costs of individual operations) of making all elements of A
equal to 0

.
Input

    The first line of the input contains a single integer T

denoting the number of test cases. The description of T
test cases follows.
The first line of each test case contains two space-separated integers N
and K
.
The second line contains N
space-separated integers A1,A2,…,AN

    .

Output

For each test case, print a single line containing one integer ― the minimum cost of turning all elements of A

into zeros.
Constraints

    1≤T≤200

1≤K≤N≤2⋅105
0≤Ai≤1
for each valid i
the sum of N
over all test cases does not exceed 4⋅105
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
	
	ll n, k;
	cin >> n >> k;
	ll a[n + 7], b[n + 7];
	ll d = 0, h = 0, l, i, j = 0, m;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		j += a[i];
	}

	if (k == 1) cout << j ;
	else if (k == n) cout << (j * (j + 1)) / 2 ;
	else {
		for (i = 1; i <= n; i++)
		{
			d += a[i];
			if (i == k)
			{
				b[h] = d;
				h++;
			}
			else if (i > k)
			{
				d -= a[i - k];
				b[h] = d;
				h++;
			}
		}
		sort(b, b + h);
		m = b[0];
		j -= m;
		l = m * (m + 1) / 2;
		cout << l + j ;
	}
}

