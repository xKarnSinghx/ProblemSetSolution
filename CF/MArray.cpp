/*
B. M-arrays
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a1,a2,…,an consisting of n positive integers and a positive integer m.

You should divide elements of this array into some arrays. You can order the elements in the new arrays as you want.

Let's call an array m-divisible if for each two adjacent numbers in the array (two numbers on the positions i and i+1 are called adjacent for each i) their sum is divisible by m. An array of one element is m-divisible.

Find the smallest number of m-divisible arrays that a1,a2,…,an is possible to divide into.

Input
The first line contains a single integer t (1≤t≤1000)  — the number of test cases.

The first line of each test case contains two integers n, m (1≤n≤105,1≤m≤105).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109).

It is guaranteed that the sum of n and the sum of m over all test cases do not exceed 105.

Output
For each test case print the answer to the problem.

Example
inputCopy
4
6 4
2 2 8 6 9 4
10 8
1 1 1 5 2 4 4 8 6 7
1 1
666
2 2
2 4
outputCopy
3
6
1
1
Note
In the first test case we can divide the elements as follows:

[4,8]. It is a 4-divisible array because 4+8 is divisible by 4.
[2,6,2]. It is a 4-divisible array because 2+6 and 6+2 are divisible by 4.
[9]. It is a 4-divisible array because it consists of one element.
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
void solve()
{
	ll n, k, ans = 0;
	cin >> n >> k;
	ll a[n], b[k];
	foi(k)
	b[i] = 0;
	foi(n) {
		cin >> a[i];
		b[a[i] % k]++;
	}
	if (b[0] > 0)
		ans = 1;
	for (ll i = 1, j = k - 1; i < k; i++, j--) {
		if (i > j)
			break;
		if (b[i] != b[j])
			ans += max(0ll, abs(b[i] - b[j]) );
		else if (b[i] and i != j)
			ans++;
		if (i == j and b[i] != 0)
			ans++;
	}
	cout << ans;


}
