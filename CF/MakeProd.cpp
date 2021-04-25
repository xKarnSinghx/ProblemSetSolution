/*
B. Makes And The Product
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
After returning from the army Makes received a gift — an array a consisting of n positive integer numbers. He hadn't been solving problems for a long time, so he became interested to answer a particular question: how many triples of indices (i,  j,  k) (i < j < k), such that ai·aj·ak is minimum possible, are there in the array? Help him with it!

Input
The first line of input contains a positive integer number n (3 ≤ n ≤ 105) — the number of elements in array a. The second line contains n positive integer numbers ai (1 ≤ ai ≤ 109) — the elements of a given array.

Output
Print one number — the quantity of triples (i,  j,  k) such that i,  j and k are pairwise distinct and ai·aj·ak is minimum possible.

Examples
inputCopy
4
1 1 1 1
outputCopy
4
inputCopy
5
1 3 2 3 4
outputCopy
2
inputCopy
6
1 3 3 1 3 2
outputCopy
1
Note
In the first example Makes always chooses three ones out of four, and the number of ways to choose them is 4.

In the second example a triple of numbers (1, 2, 3) is chosen (numbers, not indices). Since there are two ways to choose an element 3, then the answer is 2.

In the third example a triple of numbers (1, 1, 2) is chosen, and there's only one way to choose indices.


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


	//ll tc ; cin >> tc;
	//while (tc--)
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
	ll a[n], s = 0;
	foi(n)
	cin >> a[i];
	sort(a, a + n);
	foi(n) {
		if (a[i] == a[2])
			s++;
	}
	if (a[0] == a[2])
		cout << s*(s - 2)*(s - 1) / 6;
	else if (a[1] == a[2])
		cout << s*(s - 1) / 2;
	else
		cout << s;
}


