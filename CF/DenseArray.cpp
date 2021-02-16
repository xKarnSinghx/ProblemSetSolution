A. Dense Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp calls an array dense if the greater of any two adjacent elements is not more than twice bigger than the smaller. More formally, for any i (1≤i≤n−1), this condition must be satisfied:
max(a[i],a[i+1])min(a[i],a[i+1])≤2
For example, the arrays [1,2,3,4,3], [1,1,1] and [5,10] are dense. And the arrays [5,11], [1,4,2], [6,6,1] are not dense.

You are given an array a of n integers. What is the minimum number of numbers you need to add to an array to make it dense? You can insert numbers anywhere in the array. If the array is already dense, no numbers need to be added.

For example, if a=[4,2,10,1], then the answer is 5, and the array itself after inserting elements into it may look like this: a=[4,2,3––,5––,10,6––,4––,2––,1] (there are other ways to build such a).

Input
The first line contains one integer t (1≤t≤1000). Then t test cases follow.

The first line of each test case contains one integer n (2≤n≤50) — the length of the array a.

The next line contains n integers a1,a2,…,an (1≤ai≤50).

Output
For each test case, output one integer — the minimum number of numbers that must be added to the array to make it dense.

Example
inputCopy
6
4
4 2 10 1
2
1 3
2
6 1
3
1 4 2
5
1 2 3 4 3
12
4 31 25 50 30 20 34 46 42 16 15 16
outputCopy
5
1
2
1
0
3
Note
The first test case is explained in the statements.

In the second test case, you can insert one element, a=[1,2––,3].

In the third test case, you can insert two elements, a=[6,4––,2––,1].

In the fourth test case, you can insert one element, a=[1,2––,4,2].

In the fifth test case, the array a is already dense.
TAG:Greedy,math*/
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
	ll n;
	cin >> n;
	ll a[n], c = 0;
	foi(n)
	cin >> a[i];
	foi(n - 1) {
		ll x = min(a[i], a[i + 1]), y = max(a[i], a[i + 1]);
		if (y > 2 * x) {
			while (y > 2 * x) {
				c++;
				x = x * 2;
			}
		}
	}
	cout << c;
}


 
