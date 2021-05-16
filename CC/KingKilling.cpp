/*
In a faraway kingdom there are N cities numbered 1 to N connected to each other in the form of a tree. The city numbered 1

is the kingdom where the king resides. A city is called a leaf if it is not the kingdom and it has exactly one adjacent city. Each leaf city has an assassin.

The enemies of the king have announced a huge reward for the assassination of the king. Each assassin starts moving from his current city following the shortest path to the kingdom. It takes exactly 1

day for an assassin to move to an adjacent city..

The assassins don’t want to split the reward, so if an assassin A
encounters any other assassin B ahead of him on the same path that A is supposed to follow (no matter how far ahead), then A uses his magical power to attack B

.

After all the magical powers were used, every assassin who was attacked dies. Suppose A
is a living assassin who attacked somebody. Now, A will move directly to the position of the assassin closest to the kingdom that A attacked, with the cost of 1

day. If there are multiple assassins in the same city simultaneously, they form a pact not to kill each other and start moving together. Once an assassin reaches the kingdom, he cannot be killed anymore, since he can kill the king, take the reward, and leave.

Your task is to find which assassin will reach the kingdom first and in how many days. If more than one assassin reaches the kingdom simultaneously, output all of them in sorted order. Each assassin is represented by the number of the city where they started from.
Input

    The first line contains an integer T

, the number of test cases
The first line of every test case contains a single integer N
, the number of cities.
Each of the next N−1
lines contains two integers u and v denoting that city u is connected to city v

    .

Output

    For every test case, the first line should contain K

and T
, the number of assassins who are first to reach and the number of days required.
In the next line print K

    space-separated integers denoting the assassins who are first to reach the kingdom in sorted order.

Constraints

    1≤T≤105

3≤N≤2⋅105
1≤u,v≤N
The sum of N
over all test cases does not exceed 106
The connections form a tree structure.
*/
