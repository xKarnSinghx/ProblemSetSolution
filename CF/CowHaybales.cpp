/*
A. Cow and Haybales
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The USA Construction Operation (USACO) recently ordered Farmer John to arrange a row of n haybale piles on the farm. The i-th pile contains ai haybales.

However, Farmer John has just left for vacation, leaving Bessie all on her own. Every day, Bessie the naughty cow can choose to move one haybale in any pile to an adjacent pile. Formally, in one day she can choose any two indices i and j (1≤i,j≤n) such that |i−j|=1 and ai>0 and apply ai=ai−1, aj=aj+1. She may also decide to not do anything on some days because she is lazy.

Bessie wants to maximize the number of haybales in pile 1 (i.e. to maximize a1), and she only has d days to do so before Farmer John returns. Help her find the maximum number of haybales that may be in pile 1 if she acts optimally!

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100)  — the number of test cases. Next 2t lines contain a description of test cases  — two lines per test case.

The first line of each test case contains integers n and d (1≤n,d≤100) — the number of haybale piles and the number of days, respectively.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤100)  — the number of haybales in each pile.

Output
For each test case, output one integer: the maximum number of haybales that may be in pile 1 after d days if Bessie acts optimally.

Example
inputCopy
3
4 5
1 0 3 2
2 2
100 1
1 8
0
outputCopy
3
101
0
Note
In the first test case of the sample, this is one possible way Bessie can end up with 3 haybales in pile 1:

On day one, move a haybale from pile 3 to pile 2
On day two, move a haybale from pile 3 to pile 2
On day three, move a haybale from pile 2 to pile 1
On day four, move a haybale from pile 2 to pile 1
On day five, do nothing
In the second test case of the sample, Bessie can do nothing on the first day and move a haybale from pile 2 to pile 1 on the second day.


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
ll TT = 1;
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
ll sod(ll n) {
	ll s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}
void solve()
{
	ll n, d;
	cin >> n >> d;
	ll a[n];
	foi(n)cin >> a[i];
	ll sum = a[0];
	for (ll i = 1; i < n; i++) {
		while (a[i] > 0 and a[i] * i > d)
			a[i]--;
		d -= a[i] * i; sum += a[i];
	}

	cout << sum;
}


