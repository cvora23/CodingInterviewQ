/*
 * BoggleTrie.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

/*
 * Boggle | Set 2 (Using Trie)
4.8
Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character.
Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of
8 adjacent characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};
      isWord(str): returns true if str is present in dictionary
                   else false.

Output:  Following words of dictionary are present
         GEEKS
         QUIZ

http://www.geeksforgeeks.org/wp-content/uploads/Boggle.png

Here we discus Trie based solution which is better then DFS base solution.

Given Dictionary dictionary[] = {“GEEKS”, “FOR”, “QUIZ”, “GO”}

1. Create an Empty trie and insert all words of given dictionary into trie

      After insertion Tre look like (leaf nodes are in RED )
                       root
                    /
                    G   F     Q
                 /  |   |     |
                O   E   O     U
                    |   |     |
                    E    R     I
                    |         |
                    K         Z
                    |
                    S
2. After that we have pick only those character in boggle[][] which are child of root of Trie
Let for above we pick ‘G’ boggle[0][0] , ‘Q’ boggle[2][0] (they both are present in boggle matrix)
3. search a word in a trie which start with character that we pick in step 2

1) Create bool visited boolean matrix (Visited[M][N] = false )
2) Call SearchWord() for every cell (i, j) which has one of the
   the first characters of dictionary words. In above example,
   we have 'G' and 'Q' as first characters.

SearchWord(Trie *root, i, j, visited[][N])
if root->leaf == true
   print word

if we seen this element first time then make it visited.
   visited[i][j] = true
   do
      traverse all child of current root
      k goes (0 to 26 ) [there are only 26 Alphabet]
      add current char and search for next character

      find next character which is adjacent to boggle[i][j]
      they are 8 adjacent cells of boggle[i][j] (i+1, j+1),
      (i+1, j) (i-1, j) and so on.

   make it unvisited visited[i][j] = false


 */


int main(){


	return 0;

}
