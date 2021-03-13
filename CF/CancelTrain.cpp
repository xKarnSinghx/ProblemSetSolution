/*
A. Cancel the Trains
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Gildong's town has a train system that has 100 trains that travel from the bottom end to the top end and 100 trains that travel from the left end to the right end. The trains starting from each side are numbered from 1 to 100, respectively, and all trains have the same speed. Let's take a look at the picture below.


The train system can be represented as coordinates on a 2D plane. The i-th train starting at the bottom end is initially at (i,0) and will be at (i,T) after T minutes, and the i-th train starting at the left end is initially at (0,i) and will be at (T,i) after T minutes. All trains arrive at their destinations after 101 minutes.

However, Gildong found that some trains scheduled to depart at a specific time, simultaneously, are very dangerous. At this time, n trains are scheduled to depart from the bottom end and m trains are scheduled to depart from the left end. If two trains are both at (x,y) at the same time for some x and y, they will crash into each other. Therefore, he is asking you to find the minimum number of trains that should be cancelled to prevent all such crashes.

Input
Each test contains one or more test cases. The first line contains the number of test cases t (1≤t≤100).

Each test case contains three lines. The first line of each test case consists of two integers n and m (1≤n,m≤100) — the number of trains scheduled to depart from the bottom end, and the number of trains scheduled to depart from the left end, respectively.

The second line of each test case contains n integers. Each integer is a train number that is scheduled to start from the bottom end. The numbers are given in strictly increasing order, and are between 1 and 100, inclusive.

The third line of each test case contains m integers. Each integer is a train number that is scheduled to start from the left end. The numbers are given in strictly increasing order, and are between 1 and 100, inclusive.

Output
For each test case, print a single integer: the minimum number of trains that should be canceled in order to prevent all crashes.

Example
inputCopy
3
1 2
1
3 4
3 2
1 3 4
2 4
9 14
2 7 16 28 33 57 59 86 99
3 9 14 19 25 26 28 35 41 59 85 87 99 100
outputCopy
0
1
3
Note
In the first case, we can show that there will be no crashes if the current schedule is followed. Therefore, the answer is zero.

In the second case, at T=4, there will be a crash, as can be seen in the picture below. We can prove that after canceling one of these trains, the remaining trains will not crash. Therefore, the answer is one.
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

	int t ; cin >> t;
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
void findPairs(int arr[], int n)
{


}
void solve()
{
	ll n, m;
	cin >> n >> m;
	set<ll>s;
	foi(n + m) {
		ll x;
		cin >> x;
		s.insert(x);
	}
	cout << n + m - s.size();

}
