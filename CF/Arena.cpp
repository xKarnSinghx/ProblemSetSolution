/*
A. Arena
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
n heroes fight against each other in the Arena. Initially, the i-th hero has level ai.

Each minute, a fight between two different heroes occurs. These heroes can be chosen arbitrarily (it's even possible that it is the same two heroes that were fighting during the last minute).

When two heroes of equal levels fight, nobody wins the fight. When two heroes of different levels fight, the one with the higher level wins, and his level increases by 1.

The winner of the tournament is the first hero that wins in at least 100500 fights (note that it's possible that the tournament lasts forever if no hero wins this number of fights, then there is no winner). A possible winner is a hero such that there exists a sequence of fights that this hero becomes the winner of the tournament.

Calculate the number of possible winners among n heroes.

Input
The first line contains one integer t (1≤t≤500) — the number of test cases.

Each test case consists of two lines. The first line contains one integer n (2≤n≤100) — the number of heroes. The second line contains n integers a1,a2,…,an (1≤ai≤100), where ai is the initial level of the i-th hero.

Output
For each test case, print one integer — the number of possible winners among the given n heroes.

Example
inputCopy
3
3
3 2 2
2
5 5
4
1 3 3 7
outputCopy
1
0
3
Note
In the first test case of the example, the only possible winner is the first hero.

In the second test case of the example, each fight between the heroes results in nobody winning it, so the tournament lasts forever and there is no winner.

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

	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	cin >> a[i];
	sort(a, a + n);
	ll c = 0;
	foi(n ) {
		if (a[i] == a[0])
			c++;
		else
			break;
	}

		cout << n - c;
}

 
