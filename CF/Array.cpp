/*
B. Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You've got an array a, consisting of n integers: a1, a2, ..., an. Your task is to find a minimal by inclusion segment [l, r] (1 ≤ l ≤ r ≤ n) such, that among numbers al,  al + 1,  ...,  ar there are exactly k distinct numbers.

Segment [l, r] (1 ≤ l ≤ r ≤ n; l, r are integers) of length m = r - l + 1, satisfying the given property, is called minimal by inclusion, if there is no segment [x, y] satisfying the property and less then m in length, such that 1 ≤ l ≤ x ≤ y ≤ r ≤ n. Note that the segment [l, r] doesn't have to be minimal in length among all segments, satisfying the given property.

Input
The first line contains two space-separated integers: n and k (1 ≤ n, k ≤ 105). The second line contains n space-separated integers a1, a2, ..., an — elements of the array a (1 ≤ ai ≤ 105).

Output
Print a space-separated pair of integers l and r (1 ≤ l ≤ r ≤ n) such, that the segment [l, r] is the answer to the problem. If the sought segment does not exist, print "-1 -1" without the quotes. If there are multiple correct answers, print any of them.

Examples
inputCopy
4 2
1 2 2 3
outputCopy
1 2
inputCopy
8 3
1 1 2 2 3 3 4 5
outputCopy
2 5
inputCopy
7 4
4 7 7 4 7 4 7
outputCopy
-1 -1
Note
In the first sample among numbers a1 and a2 there are exactly two distinct numbers.

In the second sample segment [2, 5] is a minimal by inclusion segment with three distinct numbers, but it is not minimal in length among such segments.

In the third sample there is no segment with four distinct numbers.

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
	ll n, k, p = 0, q = 0, f = 0;
	cin >> n >> k;
	ll a[n];
	set<ll>s, s1;
	foi(n) {
		cin >> a[i];
	}
	foi(n) {
		s.insert(a[i]);
		if (s.size() == k) {
			p = i; f = 1; break;
		}
	}
	forrr(i, p, 0) {
		s1.insert(a[i]);
		if (s1.size() == k) {
			q = i; break;
		}
	}
	if (f)
		cout << q + 1 << " " << p + 1 ;
	else
		cout << -1 << " " << -1;


}
