/*B. Shuffle
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array consisting of n integers a1, a2, ..., an. Initially ax=1, all other elements are equal to 0.

You have to perform m operations. During the i-th operation, you choose two indices c and d such that li≤c,d≤ri, and swap ac and ad.

Calculate the number of indices k such that it is possible to choose the operations so that ak=1 in the end.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases. Then the description of t testcases follow.

The first line of each test case contains three integers n, x and m (1≤n≤109; 1≤m≤100; 1≤x≤n).

Each of next m lines contains the descriptions of the operations; the i-th line contains two integers li and ri (1≤li≤ri≤n).

Output
For each test case print one integer — the number of indices k such that it is possible to choose the operations so that ak=1 in the end.

Example
inputCopy
3
6 4 3
1 6
2 3
5 5
4 1 2
2 4
1 2
3 3 2
2 3
1 2
outputCopy
6
2
3
Note
In the first test case, it is possible to achieve ak=1 for every k. To do so, you may use the following operations:

swap ak and a4;
swap a2 and a2;
swap a5 and a5.
In the second test case, only k=1 and k=2 are possible answers. To achieve a1=1, you have to swap a1 and a1 during the second operation. To achieve a2=1, you have to swap a1 and a2 during the second operation.
*
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


void solve()

{

	ll n, k, m;
	cin >> n >> k >> m;
	ll a[m], b[m];
	ll x = k;
	for (ll i = 1; i < m + 1; ++i)
	{
		cin >> a[i] >> b[i];
	}
	for (ll i = 1; i < m + 1; ++i)
	{

		if (k >= a[i] && k <= b[i] || x >= a[i] && x <= b[i])
		{
			k = min(k, a[i]);
			k = min(k, b[i]);
			x = max(x, b[i]);
			x = max(x, a[i]);

		}

	}

	cout <<  x - k + 1;
}



