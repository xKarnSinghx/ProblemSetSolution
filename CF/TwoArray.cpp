/*
B. Two Arrays
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
RedDreamer has an array a consisting of n non-negative integers, and an unlucky integer T.

Let's denote the misfortune of array b having length m as f(b) — the number of pairs of integers (i,j) such that 1≤i<j≤m and bi+bj=T. RedDreamer has to paint each element of a into one of two colors, white and black (for each element, the color is chosen independently), and then create two arrays c and d so that all white elements belong to c, and all black elements belong to d (it is possible that one of these two arrays becomes empty). RedDreamer wants to paint the elements in such a way that f(c)+f(d) is minimum possible.

For example:

if n=6, T=7 and a=[1,2,3,4,5,6], it is possible to paint the 1-st, the 4-th and the 5-th elements white, and all other elements black. So c=[1,4,5], d=[2,3,6], and f(c)+f(d)=0+0=0;
if n=3, T=6 and a=[3,3,3], it is possible to paint the 1-st element white, and all other elements black. So c=[3], d=[3,3], and f(c)+f(d)=0+1=1.
Help RedDreamer to paint the array optimally!

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

The first line of each test case contains two integers n and T (1≤n≤105, 0≤T≤109) — the number of elements in the array and the unlucky integer, respectively.

The second line contains n integers a1, a2, ..., an (0≤ai≤109) — the elements of the array.

The sum of n over all test cases does not exceed 105.

Output
For each test case print n integers: p1, p2, ..., pn (each pi is either 0 or 1) denoting the colors. If pi is 0, then ai is white and belongs to the array c, otherwise it is black and belongs to the array d.

If there are multiple answers that minimize the value of f(c)+f(d), print any of them.

Example
inputCopy
2
6 7
1 2 3 4 5 6
3 6
3 3 3
outputCopy
1 0 0 1 1 0 
1 0 0
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
vector<int> G[100005];
ll b[100005], f;
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

void solve()
{

	ll n, k;
	cin >> n >> k;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	ll f = 0;
	foi(n) {
		if (k % 2 == 0 and a[i] == k / 2) {
		cout << (f++) % 2 << " ";
		}

		else	if (a[i] > k/2 ) {
			cout << 1 << " " ;
		}
		else  {
			cout << 0 << " " ;
		}

	}
}
 
