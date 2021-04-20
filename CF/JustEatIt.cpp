/*
B. Just Eat It!
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Today, Yasser and Adel are at the shop buying cupcakes. There are n cupcake types, arranged from 1 to n on the shelf, and there are infinitely many of each type. The tastiness of a cupcake of type i is an integer ai. There are both tasty and nasty cupcakes, so the tastiness can be positive, zero or negative.

Yasser, of course, wants to try them all, so he will buy exactly one cupcake of each type.

On the other hand, Adel will choose some segment [l,r] (1≤l≤r≤n) that does not include all of cupcakes (he can't choose [l,r]=[1,n]) and buy exactly one cupcake of each of types l,l+1,…,r.

After that they will compare the total tastiness of the cupcakes each of them have bought. Yasser will be happy if the total tastiness of cupcakes he buys is strictly greater than the total tastiness of cupcakes Adel buys regardless of Adel's choice.

For example, let the tastinesses of the cupcakes be [7,4,−1]. Yasser will buy all of them, the total tastiness will be 7+4−1=10. Adel can choose segments [7],[4],[−1],[7,4] or [4,−1], their total tastinesses are 7,4,−1,11 and 3, respectively. Adel can choose segment with tastiness 11, and as 10 is not strictly greater than 11, Yasser won't be happy :(

Find out if Yasser will be happy after visiting the shop.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains n (2≤n≤105).

The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109), where ai represents the tastiness of the i-th type of cupcake.

It is guaranteed that the sum of n over all test cases doesn't exceed 105.

Output
For each test case, print "YES", if the total tastiness of cupcakes Yasser buys will always be strictly greater than the total tastiness of cupcakes Adel buys regardless of Adel's choice. Otherwise, print "NO".

Example
inputCopy
3
4
1 2 3 4
3
7 4 -1
3
5 -5 5
outputCopy
YES
NO
NO
Note
In the first example, the total tastiness of any segment Adel can choose is less than the total tastiness of all cupcakes.

In the second example, Adel will choose the segment [1,2] with total tastiness 11, which is not less than the total tastiness of all cupcakes, which is 10.

In the third example, Adel can choose the segment [3,3] with total tastiness of 5. Note that Yasser's cupcakes' total tastiness is also 5, so in that case, the total tastiness of Yasser's cupcakes isn't strictly greater than the total tastiness of Adel's cupcakes.


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
typedef pair<pll, ll>      plll;
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
void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	ll s = 0;
	foi(n) {
		s += a[i];
		if (s <= 0) {
			cout << "NO";
			return;
		}
	}
	ll s1 = 0;
	for (ll i = n - 1; i > -1; i--) {
		s1 += a[i];
		if (s1 <= 0) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}

 
