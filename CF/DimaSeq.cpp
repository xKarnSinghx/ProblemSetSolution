/*
\B. Dima and Sequence
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dima got into number sequences. Now he's got sequence a1, a2, ..., an, consisting of n positive integers. Also, Dima has got a function f(x), which can be defined with the following recurrence:

f(0) = 0;
f(2·x) = f(x);
f(2·x + 1) = f(x) + 1.
Dima wonders, how many pairs of indexes (i, j) (1 ≤ i < j ≤ n) are there, such that f(ai) = f(aj). Help him, count the number of such pairs.

Input
The first line contains integer n (1 ≤ n ≤ 105). The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).

The numbers in the lines are separated by single spaces.

Output
In a single line print the answer to the problem.

Please, don't use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

Examples
inputCopy
3
1 2 4
outputCopy
3
inputCopy
3
5 3 1
outputCopy
1
Note
In the first sample any pair (i, j) will do, so the answer is 3.

In the second sample only pair (1, 2) will do.

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
void solve()
{
	ll n;
	cin >> n ;
	ll a[n];
	foi(n) {
		ll x = 0;
		cin >> a[i];
		while (a[i] > 0) {
			if (a[i] % 2)
				x++;
			a[i] /= 2;
		}
		a[i] = x;
	}
	sort(a, a + n);
	ll s = 1;
	ll ans = 0;
	foi(n - 1) {
		if (a[i] == a[i + 1])
			s++;
		else {
			ans += s * (s - 1) / 2;
			s = 1;
		}
		if (i == n - 2)
			ans += s * (s - 1) / 2;

	}





	cout << ans ;

}
