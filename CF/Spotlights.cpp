/*
B. Spotlights
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Theater stage is a rectangular field of size n × m. The director gave you the stage's plan which actors will follow. For each cell it is stated in the plan if there would be an actor in this cell or not.

You are to place a spotlight on the stage in some good position. The spotlight will project light in one of the four directions (if you look at the stage from above) — left, right, up or down. Thus, the spotlight's position is a cell it is placed to and a direction it shines.

A position is good if two conditions hold:

there is no actor in the cell the spotlight is placed to;
there is at least one actor in the direction the spotlight projects.
Count the number of good positions for placing the spotlight. Two positions of spotlight are considered to be different if the location cells or projection direction differ.

Input
The first line contains two positive integers n and m (1 ≤ n, m ≤ 1000) — the number of rows and the number of columns in the plan.

The next n lines contain m integers, 0 or 1 each — the description of the plan. Integer 1, means there will be an actor in the corresponding cell, while 0 means the cell will remain empty. It is guaranteed that there is at least one actor in the plan.

Output
Print one integer — the number of good positions for placing the spotlight.

Examples
inputCopy
2 4
0 1 0 0
1 0 1 0
outputCopy
9
inputCopy
4 4
0 0 0 0
1 0 0 1
0 1 1 0
0 1 0 0
outputCopy
20
Note
In the first example the following positions are good:

the (1, 1) cell and right direction;
the (1, 1) cell and down direction;
the (1, 3) cell and left direction;
the (1, 3) cell and down direction;
the (1, 4) cell and left direction;
the (2, 2) cell and left direction;
the (2, 2) cell and up direction;
the (2, 2) and right direction;
the (2, 4) cell and left direction.
Therefore, there are 9 good positions in this example.
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


		solve();


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

void solve()

{

	ll n, m;
	cin >> n >> m;
	ll a[n][m];
	foi(n) {
		foj(m)
		cin >> a[i][j];
	}
	ll f = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		f = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
				f = 1;
			if (f == 1 && j != 0 && a[i][j] == 0)
				ans++;
		}
	}
	for (int i = n - 1; i >= 0  ; i--)
	{
		f = 0;
		for (int j = m - 1; j >= 0  ; j--)
		{
			if (a[i][j] == 1)
				f = 1;
			if (f == 1 && j != m - 1 && a[i][j] == 0)
				ans++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		f = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j][i] == 1)
				f = 1;
			if (f == 1 && j != 0 && a[j][i] == 0)
				ans++;
		}
	}
	for (int i = m - 1; i >= 0  ; i--)
	{
		f = 0;
		for (int j = n - 1; j >= 0  ; j--)
		{
			if (a[j][i] == 1)
				f = 1;
			if (f == 1 && j != n - 1 && a[j][i] == 0)
				ans++;
		}
	}
	cout << ans;

}

