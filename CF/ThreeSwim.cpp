/*
A. Three swimmers
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Three swimmers decided to organize a party in the swimming pool! At noon, they started to swim from the left side of the pool.

It takes the first swimmer exactly a minutes to swim across the entire pool and come back, exactly b minutes for the second swimmer and c minutes for the third. Hence, the first swimmer will be on the left side of the pool after 0, a, 2a, 3a, ... minutes after the start time, the second one will be at 0, b, 2b, 3b, ... minutes, and the third one will be on the left side of the pool after 0, c, 2c, 3c, ... minutes.

You came to the left side of the pool exactly p minutes after they started swimming. Determine how long you have to wait before one of the swimmers arrives at the left side of the pool.

Input
The first line of the input contains a single integer t (1≤t≤1000) — the number of test cases. Next t lines contains test case descriptions, one per line.

Each line contains four integers p, a, b and c (1≤p,a,b,c≤1018), time in minutes after the start, when you came to the pool and times in minutes it take the swimmers to cross the entire pool and come back.

Output
For each test case, output one integer — how long you have to wait (in minutes) before one of the swimmers arrives at the left side of the pool.

Example
inputCopy
4
9 5 4 8
2 6 10 9
10 2 5 10
10 9 9 9
outputCopy
1
4
0
8
Note
In the first test case, the first swimmer is on the left side in 0,5,10,15,… minutes after the start time, the second swimmer is on the left side in 0,4,8,12,… minutes after the start time, and the third swimmer is on the left side in 0,8,16,24,… minutes after the start time. You arrived at the pool in 9 minutes after the start time and in a minute you will meet the first swimmer on the left side.

In the second test case, the first swimmer is on the left side in 0,6,12,18,… minutes after the start time, the second swimmer is on the left side in 0,10,20,30,… minutes after the start time, and the third swimmer is on the left side in 0,9,18,27,… minutes after the start time. You arrived at the pool 2 minutes after the start time and after 4 minutes meet the first swimmer on the left side.

In the third test case, you came to the pool 10 minutes after the start time. At the same time, all three swimmers are on the left side. A rare stroke of luck!

In the fourth test case, all swimmers are located on the left side in 0,9,18,27,… minutes after the start time. You arrived at the pool 10 minutes after the start time and after 8 minutes meet all three swimmers on the left side.


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

	ll p, a, b, c;
	cin >> p >> a >> b >> c; 
	cout << min(((p / a) + ((p % a) != 0))*a - p, min(((p / b) + ((p % b) != 0))*b - p, ((p / c) + ((p % c) != 0))*c - p));
}

 
