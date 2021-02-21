/*
C. Minimum Ties
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A big football championship will occur soon! n teams will compete in it, and each pair of teams will play exactly one game against each other.

There are two possible outcomes of a game:

the game may result in a tie, then both teams get 1 point;
one team might win in a game, then the winning team gets 3 points and the losing team gets 0 points.
The score of a team is the number of points it gained during all games that it played.

You are interested in a hypothetical situation when all teams get the same score at the end of the championship. A simple example of that situation is when all games result in ties, but you want to minimize the number of ties as well.

Your task is to describe a situation (choose the result of each game) so that all teams get the same score, and the number of ties is the minimum possible.

Input
The first line contains one integer t (1≤t≤100) — the number of test cases.

Then the test cases follow. Each test case is described by one line containing one integer n (2≤n≤100) — the number of teams.

Output
For each test case, print n(n−1)2 integers describing the results of the games in the following order: the first integer should correspond to the match between team 1 and team 2, the second — between team 1 and team 3, then 1 and 4, ..., 1 and n, 2 and 3, 2 and 4, ..., 2 and n, and so on, until the game between the team n−1 and the team n.

The integer corresponding to the game between the team x and the team y should be 1 if x wins, −1 if y wins, or 0 if the game results in a tie.

All teams should get the same score, and the number of ties should be the minimum possible. If there are multiple optimal answers, print any of them. It can be shown that there always exists a way to make all teams have the same score.

Example
inputCopy
2
2
3
outputCopy
0 
1 -1 1 
Note
In the first test case of the example, both teams get 1 point since the game between them is a tie.

In the second test case of the example, team 1 defeats team 2 (team 1 gets 3 points), team 1 loses to team 3 (team 3 gets 3 points), and team 2 wins against team 3 (team 2 gets 3 points).
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
	if (n % 2 == 1)
	{
		for (ll i = 0; i < n; i++)
			for (ll j = i + 1; j < n; j++)
				if (j - i <= n / 2)
					cout << 1 << " ";
				else
					cout << -1 << " ";
	}
	else
	{
		for (ll i = 0; i < n; i++)
			for (ll j = i + 1; j < n; j++)
				if (j - i < n / 2)
					cout << 1 << " ";
				else if (j - i == n / 2)
					cout << 0 << " ";
				else
					cout << -1 << " ";
	}



}

