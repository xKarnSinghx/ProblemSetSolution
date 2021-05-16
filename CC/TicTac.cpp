/*
Tic-tac-toe is a game played between two players on a 3×3 grid. In a turn, a player chooses an empty cell and places their symbol on the cell. The players take alternating turns, where the player with the first turn uses the symbol X and the other player uses the symbol O. The game continues until there is a row, column, or diagonal containing three of the same symbol (X or O

), and the player with that token is declared the winner. Otherwise if every cell of the grid contains a symbol and nobody won, then the game ends and it is considered a draw.

You are given a tic-tac-toe board A
after a certain number of moves, consisting of symbols O, X, and underscore(_

). Underscore signifies an empty cell.

Print

    1

: if the position is reachable, and the game has drawn or one of the players won.
2
: if the position is reachable, and the game will continue for at least one more move.
3

    : if the position is not reachable.

Note:

    Starting from an empty board, reachable position means that the grid is possible after a finite number of moves in the game where the players may or may not be playing optimally.
    The answer for each testcase should be with respect to the present position and independent of the results in the further successive moves.

Input

    The first line contains an integer T

, the number of test cases. Then the test cases follow.
Each test case contains 3
lines of input where each line contains a string describing the state of the game in ith row.
*/
