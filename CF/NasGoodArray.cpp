/*
B. Nastia and a Good Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Nastia has received an array of n positive integers as a gift.

She calls such an array a good that for all i (2≤i≤n) takes place gcd(ai−1,ai)=1, where gcd(u,v) denotes the greatest common divisor (GCD) of integers u and v.

You can perform the operation: select two different indices i,j (1≤i,j≤n, i≠j) and two integers x,y (1≤x,y≤2⋅109) so that min(ai,aj)=min(x,y). Then change ai to x and aj to y.

The girl asks you to make the array good using at most n operations.

It can be proven that this is always possible.

Input
The first line contains a single integer t (1≤t≤10000) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤105) — the length of the array.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the array which Nastia has received as a gift.

It's guaranteed that the sum of n in one test doesn't exceed 2⋅105.

Output
For each of t test cases print a single integer k (0≤k≤n) — the number of operations. You don't need to minimize this number.

In each of the next k lines print 4 integers i, j, x, y (1≤i≠j≤n, 1≤x,y≤2⋅109) so that min(ai,aj)=min(x,y) — in this manner you replace ai with x and aj with y.

If there are multiple answers, print any.

Example
inputCopy
2
5
9 6 3 11 15
3
7 5 13
outputCopy
2
1 5 11 9
2 5 7 6
0
Note
Consider the first test case.

Initially a=[9,6,3,11,15].

In the first operation replace a1 with 11 and a5 with 9. It's valid, because min(a1,a5)=min(11,9)=9.

After this a=[11,6,3,11,9].

In the second operation replace a2 with 7 and a5 with 6. It's valid, because min(a2,a5)=min(7,6)=6.

After this a=[11,7,3,11,6] — a good array.

In the second test case, the initial array is already good.

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
typedef pair< ll, pll>      plll;
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
typedef priority_queue <ll> pq;
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
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;

}
void solve() {
	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	cin >> a[i];
	if (n == 1) {
		cout << 0 ;
		return;
	}
	cout << ceils(n, 2) << endl;
	for (ll i = 0; i < n - 1; i += 2) {
		ll x = min(a[i], a[i + 1]);
		cout << i + 1 << " " << i + 2 << " " << MOD << " " << x << endl;
		a[i + 1] = x;
	}
	if (n % 2 == 1)
		cout << n - 1 << " " << n << " " << min(a[n - 1], a[n - 2])  << " " << MOD  ;


}
