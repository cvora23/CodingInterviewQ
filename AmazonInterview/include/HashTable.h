/*
 * HashTable.h
 *
 *  Created on: Jan 20, 2016
 *      Author: chintan
 */

#ifndef INCLUDE_HASHTABLE_H_
#define INCLUDE_HASHTABLE_H_

#include <stddef.h>
#include "HashEntry.h"

/*
 * The very simple hash table example

In the current article we show the very simple hash table example.
It uses simple hash function, collisions are resolved using
linear probing (open addressing strategy) and hash table has constant size.
This example clearly shows the basics of hashing technique.

Hash table

Underlying array has constant size to store 128 elements and each slot
contains key-value pair. Key is stored to distinguish between key-value pairs,
 which have the same hash.

Hash function

Table allows only integers as values. Hash function to be used is the
remainder of division by 128. In the view of implementation,
this hash function can be encoded using remainder operator or
using bitwise AND with 127.

Note. Power of two sized tables are often used in practice
(for instance in Java). When used, there is a special hash function,
which is applied in addition to the main one. This measure prevents
collisions occuring for hash codes that do not differ in lower bits.

Collision resolution strategy

Linear probing is applied to resolve collisions. In case the slot,
indicated by hash function, has already been occupied, algorithm
tries to find an empty one by probing consequent slots in the array.

Note. Linear probing is not the best techique to be used when table
is of a constant size. When load factor exceeds particular value (appr. 0.7),
 hash table performance will decrease nonlinearly.
 Also, the number of stored key-value pairs is limited to the size of the table (128).

Code snippets

This implementation suffers one bug. When there is no more place in the
table, the loop, searching for empty slot, will run infinitely.
It won't happen in real hash table based on open addressing,
because it is most likely dynamic-sized.
Also the removal's implementation is omitted to maintain simplicity.
 See open addressing strategy for full implementation.
*/

const int TABLE_SIZE = 128;

class HashMap {
private:
      HashEntry **table;
public:
      HashMap() {
            table = new HashEntry*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }

      int get(int key) {
            int hash = (key % TABLE_SIZE);
            while (table[hash] != NULL && table[hash]->getKey() != key)
                  hash = (hash + 1) % TABLE_SIZE;
            if (table[hash] == NULL)
                  return -1;
            else
                  return table[hash]->getValue();
      }

      void put(int key, int value) {
            int hash = (key % TABLE_SIZE);
            while (table[hash] != NULL && table[hash]->getKey() != key)
                  hash = (hash + 1) % TABLE_SIZE;
            if (table[hash] != NULL)
                  delete table[hash];
            table[hash] = new HashEntry(key, value);
      }

      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL)
                        delete table[i];
            delete[] table;
      }
};



#endif /* INCLUDE_HASHTABLE_H_ */
