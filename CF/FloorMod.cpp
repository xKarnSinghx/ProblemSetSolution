/*
C. Floor and Mod
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A pair of positive integers (a,b) is called special if ⌊ab⌋=amodb. Here, ⌊ab⌋ is the result of the integer division between a and b, while amodb is its remainder.

You are given two integers x and y. Find the number of special pairs (a,b) such that 1≤a≤x and 1≤b≤y.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The only line of the description of each test case contains two integers x, y (1≤x,y≤109).

Output
For each test case print the answer on a single line.

Example
inputCopy
9
3 4
2 100
4 3
50 3
12 4
69 420
12345 6789
123456 789
12345678 9
outputCopy
1
0
2
3
5
141
53384
160909
36
Note
In the first test case, the only special pair is (3,2).

In the second test case, there are no special pairs.

In the third test case, there are two special pairs: (3,2) and (4,3).
*/
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

	ll x, y, s = 0;
	cin >> x >> y;
	for (ll i = 1; i * i <= x; i++)
		s += max(min(y, x / i - 1) - i, 0LL);;


	cout << s;

}



 
