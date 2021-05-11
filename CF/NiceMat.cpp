/*
B. Nice Matrix
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A matrix of size n×m is called nice, if all rows and columns of the matrix are palindromes. A sequence of integers (a1,a2,…,ak) is a palindrome, if for any integer i (1≤i≤k) the equality ai=ak−i+1 holds.

Sasha owns a matrix a of size n×m. In one operation he can increase or decrease any number in the matrix by one. Sasha wants to make the matrix nice. He is interested what is the minimum number of operations he needs.

Help him!

Input
The first line contains a single integer t — the number of test cases (1≤t≤10). The t tests follow.

The first line of each test contains two integers n and m (1≤n,m≤100) — the size of the matrix.

Each of the next n lines contains m integers ai,j (0≤ai,j≤109) — the elements of the matrix.

Output
For each test output the smallest number of operations required to make the matrix nice.

Example
inputCopy
2
4 2
4 2
2 4
4 2
2 4
3 4
1 2 3 4
5 6 7 8
9 10 11 18
outputCopy
8
42
Note
In the first test case we can, for example, obtain the following nice matrix in 8 operations:


2 2
4 4
4 4
2 2
In the second test case we can, for example, obtain the following nice matrix in 42 operations:


5 6 6 5
6 6 6 6
5 6 6 5

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
	ll n, m;
	cin >> n >> m;
	vector<vll> v(n, vll(m));
	ll ans = 0;
	foi(n) {
		foj(m)
		cin >> v[i][j];

	}
	foi(n / 2) {
		foj(m / 2) {
			vll w = {
				v[i][j], v[i][m - 1 - j], v[n - 1 - i][j], v[n - 1 - i][m - 1 - j]
			};
			sort(w.begin(), w.end());
			for (ll x : w)
				ans += abs(x - w[1]);
		}
	}
	if (n % 2) {
		foi(m / 2)
		ans += abs(v[n / 2][i] - v[n / 2][m - 1 - i]);
	}
	if (m % 2) {
		foi(n / 2)
		ans += abs(v[i][m / 2] - v[n - 1 - i][m / 2]);
	}
	cout << ans;

}
