/*
A. Bad Triangle
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a1,a2,…,an, which is sorted in non-decreasing order (ai≤ai+1).

Find three indices i, j, k such that 1≤i<j<k≤n and it is impossible to construct a non-degenerate triangle (a triangle with nonzero area) having sides equal to ai, aj and ak (for example it is possible to construct a non-degenerate triangle with sides 3, 4 and 5 but impossible with sides 3, 4 and 7). If it is impossible to find such triple, report it.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains one integer n (3≤n≤5⋅104) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109; ai−1≤ai) — the array a.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case print the answer to it in one line.

If there is a triple of indices i, j, k (i<j<k) such that it is impossible to construct a non-degenerate triangle having sides equal to ai, aj and ak, print that three indices in ascending order. If there are multiple answers, print any of them.

Otherwise, print -1.

Example
inputCopy
3
7
4 6 11 11 15 18 20
4
10 10 10 11
3
1 1 1000000000
outputCopy
2 3 6
-1
1 2 3
Note
In the first test case it is impossible with sides 6, 11 and 18. Note, that this is not the only correct answer.

In the second test case you always can construct a non-degenerate triangle.
*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
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

	int t ; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceil(ll x, ll y) {
	return x / y + ((x % y) != 0);
}


void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	{
		cin >> a[i];

	}
	sort(a, a + n);
	ll sum = a[0] + a[1], f = 0;
	foi(n) {
		if (a[i] >= sum) {
			cout << 1 << " " << 2 << " " << n;
			f = 1;
			break;
		}
	}
	if (f == 0)
		cout << -1;
}


 
