/*
E. Accidental Victory
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A championship is held in Berland, in which n players participate. The player with the number i has ai (ai≥1) tokens.

The championship consists of n−1 games, which are played according to the following rules:

in each game, two random players with non-zero tokens are selected;
the player with more tokens is considered the winner of the game (in case of a tie, the winner is chosen randomly);
the winning player takes all of the loser's tokens;
The last player with non-zero tokens is the winner of the championship.

All random decisions that are made during the championship are made equally probable and independently.

For example, if n=4, a=[1,2,4,3], then one of the options for the game (there could be other options) is:

during the first game, the first and fourth players were selected. The fourth player has more tokens, so he takes the first player's tokens. Now a=[0,2,4,4];
during the second game, the fourth and third players were selected. They have the same number of tokens, but in a random way, the third player is the winner. Now a=[0,2,8,0];
during the third game, the second and third players were selected. The third player has more tokens, so he takes the second player's tokens. Now a=[0,0,10,0];
the third player is declared the winner of the championship.
Championship winners will receive personalized prizes. Therefore, the judges want to know in advance which players have a chance of winning, i.e have a non-zero probability of winning the championship. You have been asked to find all such players.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The first line of each test case consists of one positive integer n (1≤n≤2⋅105) — the number of players in the championship.

The second line of each test case contains n positive integers a1,a2,…,an (1≤ai≤109) — the number of tokens the players have.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print the number of players who have a nonzero probability of winning the championship. On the next line print the numbers of these players in increasing order. Players are numbered starting from one in the order in which they appear in the input.

Example
inputCopy
2
4
1 2 4 3
5
1 1 1 1 1
outputCopy
3
2 3 4 
5
1 2 3 4 5 
TAG: binary search    data structures    greedy
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
	ll a[n], s = 0;
	foi(n)
	cin >> a[i];
	vpll xx(n);
	foi(n) {
		xx[i].ff = a[i] ;
		s += a[i];
		xx[i].ss = i + 1;
	}
	sort(xx.rbegin(), xx.rend());
	ll  s1 = 0;
	vll ans;
	foi(n )
	{
		ans.pb(xx[i].ss);
		s1++;
		s -= xx[i].ff;
		if (s < xx[i ].ff)
		{
			break;
		}
	}
	sort(ans.begin(), ans.end());
	cout << s1 << endl;
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << " ";


}

