/* Problem Statement
There is a group of N people. Each person in the group has a first name and a last name: the names of person i are firstname[i] and lastname[i].

If A and B are two different people such that the last name of person A is the same as the first name of person B, the ordered pair (A, B) is called cool.

Please calculate and return the number of cool pairs for the given group of people.

Definition
Class: CoolPairsEasy
Method: count
Parameters: vector <string>, vector <string>
Returns: int
Method signature: int count(vector <string> firstname, vector <string> lastname)
(be sure your method is public)
Limits
Time limit (s): 2.000
Memory limit (MB): 256
Constraints
- N will be between 1 and 50, inclusive.
- firstname and lastname will contain exactly N elements each.
- Length of each element in firstname and lastname will have between 1 and 10, inclusive.
- Each element in firstname and lastname will only consist of lowercase English letters ('a'-'z'). */



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
typedef pair<int, pii>      piii;
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
class CoolPairsEasy{
public:
int count (vs firstname, vs lastname){
int c=0;
foi(firstname.size()){
	foj(lastname.size()){
        if(i==j)
            continue;
        else if(firstname[i]==lastname[j])
		c++;
	}
}
return c;
}
};
