/*
A. Minimum Difficulty
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Mike is trying rock climbing but he is awful at it.

There are n holds on the wall, i-th hold is at height ai off the ground. Besides, let the sequence ai increase, that is, ai < ai + 1 for all i from 1 to n - 1; we will call such sequence a track. Mike thinks that the track a1, ..., an has difficulty . In other words, difficulty equals the maximum distance between two holds that are adjacent in height.

Today Mike decided to cover the track with holds hanging on heights a1, ..., an. To make the problem harder, Mike decided to remove one hold, that is, remove one element of the sequence (for example, if we take the sequence (1, 2, 3, 4, 5) and remove the third element from it, we obtain the sequence (1, 2, 4, 5)). However, as Mike is awful at climbing, he wants the final difficulty (i.e. the maximum difference of heights between adjacent holds after removing the hold) to be as small as possible among all possible options of removing a hold. The first and last holds must stay at their positions.

Help Mike determine the minimum difficulty of the track after removing one hold.

Input
The first line contains a single integer n (3 ≤ n ≤ 100) — the number of holds.

The next line contains n space-separated integers ai (1 ≤ ai ≤ 1000), where ai is the height where the hold number i hangs. The sequence ai is increasing (i.e. each element except for the first one is strictly larger than the previous one).

Output
Print a single number — the minimum difficulty of the track after removing a single hold.

Examples
inputCopy
3
1 4 6
outputCopy
5
inputCopy
5
1 2 3 4 5
outputCopy
2
inputCopy
5
1 2 3 7 8
outputCopy
4
Note
In the first sample you can remove only the second hold, then the sequence looks like (1, 6), the maximum difference of the neighboring elements equals 5.

In the second test after removing every hold the difficulty equals 2.

In the third test you can obtain sequences (1, 3, 7, 8), (1, 2, 7, 8), (1, 2, 3, 8), for which the difficulty is 4, 5 and 5, respectively. Thus, after removing the second element we obtain the optimal answer — 4.
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




		solve();

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()

{


	ll n;
	cin>>n;
	ll a[n];
	foi(n)
	{	cin >> a[i];
	}
	ll mn = 1111111;
	for (ll i = 1; i < n-1; i++)
	{
		ll mx = -1111111;
		for (ll j = 1; j < n-1; j++)
		{
			if (j == i)
			{
				mx = max(mx, a[j + 1] - a[j - 1]);
			}
			else
			{
				mx = max(mx, a[j + 1] - a[j]);
			}
		}
		mn = min(mn, mx);
	}
	cout << mn;
}

 
