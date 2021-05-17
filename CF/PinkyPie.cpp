/*
C. Pinkie Pie Eats Patty-cakes
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Pinkie Pie has bought a bag of patty-cakes with different fillings! But it appeared that not all patty-cakes differ from one another with filling. In other words, the bag contains some patty-cakes with the same filling.

Pinkie Pie eats the patty-cakes one-by-one. She likes having fun so she decided not to simply eat the patty-cakes but to try not to eat the patty-cakes with the same filling way too often. To achieve this she wants the minimum distance between the eaten with the same filling to be the largest possible. Herein Pinkie Pie called the distance between two patty-cakes the number of eaten patty-cakes strictly between them.

Pinkie Pie can eat the patty-cakes in any order. She is impatient about eating all the patty-cakes up so she asks you to help her to count the greatest minimum distance between the eaten patty-cakes with the same filling amongst all possible orders of eating!

Pinkie Pie is going to buy more bags of patty-cakes so she asks you to solve this problem for several bags!

Input
The first line contains a single integer T (1≤T≤100): the number of bags for which you need to solve the problem.

The first line of each bag description contains a single integer n (2≤n≤105): the number of patty-cakes in it. The second line of the bag description contains n integers a1,a2,…,an (1≤ai≤n): the information of patty-cakes' fillings: same fillings are defined as same integers, different fillings are defined as different integers. It is guaranteed that each bag contains at least two patty-cakes with the same filling.

It is guaranteed that the sum of n over all bags does not exceed 105.

Output
For each bag print in separate line one single integer: the largest minimum distance between the eaten patty-cakes with the same filling amongst all possible orders of eating for that bag.

Example
inputCopy
4
7
1 7 1 6 4 4 6
8
1 1 4 6 4 6 4 7
3
3 3 3
6
2 5 2 3 1 4
outputCopy
3
2
0
4
Note
For the first bag Pinkie Pie can eat the patty-cakes in the following order (by fillings): 1, 6, 4, 7, 1, 6, 4 (in this way, the minimum distance is equal to 3).

For the second bag Pinkie Pie can eat the patty-cakes in the following order (by fillings): 1, 4, 6, 7, 4, 1, 6, 4 (in this way, the minimum distance is equal to 2)
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
	ll a[n] = {}, c = 0;
	foi(n) {
		ll x;
		cin >> x;
		a[x - 1]++;
	}
	sort(a, a + n);
	ll ans = n;
	for (ll i = n - 1; a[i] == a[n - 1];)
		i--, ans = i + 1;
	cout << ans / (a[n - 1] - 1) - 1;
}

