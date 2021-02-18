/*
A. Shifting Stacks
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have  stacks of blocks. The -th stack contains  blocks and it's height is the number of blocks in it. In one move you can take a block from the -th stack (if there is at least one block) and put it to the -th stack. Can you make the sequence of heights strictly increasing?

Note that the number of stacks always remains : stacks don't disappear when they have  blocks.

Input
First line contains a single integer   — the number of test cases.

The first line of each test case contains a single integer  . The second line of each test case contains  integers   — starting heights of the stacks.

It's guaranteed that the sum of all  does not exceed .

Output
For each test case output YES if you can make the sequence of heights strictly increasing and NO otherwise.

You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer).

Example
inputCopy
6
2
1 2
2
1 0
3
4 4 4
2
0 0
3
0 1 0
4
1000000000 1000000000 1000000000 1000000000
outputCopy
YES
YES
YES
NO
NO
YES
Note
In the first test case there is no need to make any moves, the sequence of heights is already increasing.

In the second test case we need to move one block from the first stack to the second. Then the heights become  .

In the third test case we could move one block from the first stack to the second and then from the second to the third, which would make the heights   .

In the fourth test case we can't make a move, but the sequence is not increasing, so the answer is NO.

In the fifth test case we can only make one move (from the second to the third stack), which would make the heights   . Both    and    are not increasing sequences, so the answer is NO.

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
	{	cin >> a[i];
		s += a[i] - i;
	}
	ll s1 = 0, flag = 0;

	foi(n - 1) {

		if (a[i] >= i)
		{
			a[i + 1] += a[i] - i;
		}

		else
		{flag = 1; break;}
	}

	if (flag == 0 && s >= 0)
		cout << "YES";
	else
		cout << "NO";
	





}

 
