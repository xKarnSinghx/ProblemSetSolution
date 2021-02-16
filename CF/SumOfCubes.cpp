/*
C. Sum of Cubes
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a positive integer x. Check whether the number x is representable as the sum of the cubes of two positive integers.

Formally, you need to check if there are two integers a and b (1≤a,b) such that a3+b3=x.

For example, if x=35, then the numbers a=2 and b=3 are suitable (23+33=8+27=35). If x=4, then no pair of numbers a and b is suitable.

Input
The first line contains one integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

Each test case contains one integer x (1≤x≤1012).

Please note, that the input for some test cases won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language.

Output
For each test case, output on a separate line:

"YES" if x is representable as the sum of the cubes of two positive integers.
"NO" otherwise.
You can output "YES" and "NO" in any case (for example, the strings yEs, yes, Yes and YES will be recognized as positive).

Example
inputCopy
7
1
2
4
34
35
16
703657519796
outputCopy
NO
YES
NO
NO
YES
YES
YES
Note
The number 1 is not representable as the sum of two cubes.

The number 2 is represented as 13+13.

The number 4 is not representable as the sum of two cubes.

The number 34 is not representable as the sum of two cubes.

The number 35 is represented as 23+33.

The number 16 is represented as 23+23.

The number 703657519796 is represented as 57793+79933.
TAG:Brute Force,math*/
#include<bits/stdc++.h>
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
	ll n, i, j,
	p, q, r = 0, w, x, h;
	cin >> n;
	double k;
	k = cbrt(n);
	q = int(k);
	for (i = 1; i <= q; i++)
	{
		w = i * i * i;
		x = n - w;
		if (x == 1)
			p = 1;
		else
			p = cbrt(x);
		if (x == p * p * p)
		{
			h = p;
			i = q;
			r = 1;
		}
	}
	if (h == 0)
		cout << "NO";
	else if (r == 1)
		cout << "YES";
	else
		cout << "NO";


}


 
