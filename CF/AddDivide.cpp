/*A. Add and Divide
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have two positive integers a and b.

You can perform two kinds of operations:

a=⌊ab⌋ (replace a with the integer part of the division between a and b)
b=b+1 (increase b by 1)
Find the minimum number of operations required to make a=0.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The only line of the description of each test case contains two integers a, b (1≤a,b≤109).

Output
For each test case, print a single integer: the minimum number of operations required to make a=0.

Example
inputCopy
6
9 2
1337 1
1 1
50000000 4
991026972 997
1234 5678
outputCopy
4
9
2
12
3
1
Note
In the first test case, one of the optimal solutions is:

Divide a by b. After this operation a=4 and b=2.
Divide a by b. After this operation a=2 and b=2.
Increase b. After this operation a=2 and b=3.
Divide a by b. After this operation a=0 and b=3
TAG:brute force    greedy    math
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
	ll a, b, c = 11111111, z;
	cin >> a >> b;
	z = a;


	for (ll i = b; ; i++) {
		ll x = i - b;
		a = z;
		if (i == 1)
		{
			i++;
			x++;
		}
		while (a) {
			a = a / i;
			x++;
		}
		if (x > c)
			break;
		if (b > 110) {
			while (a) {
				a = a / b;
				x++;
			}
		}

		c = min(c, x);
	}

	cout << c;

}



