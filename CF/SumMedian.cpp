/*
B. Sum of Medians
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A median of an array of integers of length n is the number standing on the ⌈n2⌉ (rounding up) position in the non-decreasing ordering of its elements. Positions are numbered starting with 1. For example, a median of the array [2,6,4,1,3,5] is equal to 3. There exist some other definitions of the median, but in this problem, we will use the described one.

Given two integers n and k and non-decreasing array of nk integers. Divide all numbers into k arrays of size n, such that each number belongs to exactly one array.

You want the sum of medians of all k arrays to be the maximum possible. Find this maximum possible sum.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases. The next 2t lines contain descriptions of test cases.

The first line of the description of each test case contains two integers n, k (1≤n,k≤1000).

The second line of the description of each test case contains nk integers a1,a2,…,ank (0≤ai≤109) — given array. It is guaranteed that the array is non-decreasing: a1≤a2≤…≤ank.

It is guaranteed that the sum of nk for all test cases does not exceed 2⋅105.

Output
For each test case print a single integer — the maximum possible sum of medians of all k arrays.

Example
inputCopy
6
2 4
0 24 34 58 62 64 69 78
2 2
27 61 81 91
4 3
2 4 16 18 21 27 36 53 82 91 92 95
3 4
3 11 12 22 33 35 38 67 69 71 94 99
2 1
11 41
3 3
1 1 1 1 1 1 1 1 1
outputCopy
165
108
145
234
11
3
Note
The examples of possible divisions into arrays for all test cases of the first test:

Test case 1: [0,24],[34,58],[62,64],[69,78]. The medians are 0,34,62,69. Their sum is 165.

Test case 2: [27,61],[81,91]. The medians are 27,81. Their sum is 108.

Test case 3: [2,91,92,95],[4,36,53,82],[16,18,21,27]. The medians are 91,36,18. Their sum is 145.

Test case 4: [3,33,35],[11,94,99],[12,38,67],[22,69,71]. The medians are 33,94,38,69. Their sum is 234.

Test case 5: [11,41]. The median is 11. The sum of the only median is 11.

Test case 6: [1,1,1],[1,1,1],[1,1,1]. The medians are 1,1,1. Their sum is 3.
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
	ll a[n * k];
	forr(i, 1, n * k + 1)
	cin >> a[i];
	ll ans = 0;
	reverse(a + 1, a + 1 + n * k);
	for (ll  i = n / 2 + 1, j = 1; j <= k; i += n / 2 + 1, j++) {
		ans += a[i];
	}
	cout << ans;
}
