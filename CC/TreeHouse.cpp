/*
There is a large tree house in an unknown world. It is ruled by the great emperor KZS. It consists of N nodes numbered from 1 to N in which the people of that world reside. The nodes are organized in a tree structure rooted at node 1

. You need to assign values to the nodes according to the wishes of emperor KZS which are as follows :-

    The value of node 1

is X
.
All immediate children of any node have pairwise distinct values.
For every node with at least one immediate child, the gcd

    of the values of all immediate children is equal to the value of the node.
    The total sum of the values of all nodes should be minimum.

The greatest common divisor gcd(a,b)
of two positive integers a and b is equal to the largest integer d such that both integers a and b are divisible by d

.

Print the sum of all values, modulo 109+7

.
Input

    The first line contains an integer T

, the number of test cases. T
testcases follow.
The first line of each test contains two integers N
and X
.
Each of the following N−1
lines contains two integers u and v, denoting an edge between nodes u and v

    .

Output

    For each test case, print the sum of values, modulo 109+7

    .

Constraints

    1≤T≤15

2≤N≤3⋅105
1≤X≤109
1≤u,v≤N
and u≠v
The given edges form a tree
The sum of N
over all test cases doesn't exceed 3⋅105. 
*/
