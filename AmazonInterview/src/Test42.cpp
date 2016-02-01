/*
 * Test42.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: chintan
 */
/*
 * As bob said, use a min heap to cache the Jobs.
1. When new Job is added into the cache,
If Heap size is max cache size, remove root and replace with newly added Job.
 Use current timestamp as node value for comparison. With that new node will
 move down to leaf node.
2. When an item is accessed from the cache, update it's time stamp to the
current time and that will cause it to move down.

However this will not solve the problem of searching an element with O(1)
from cache. Therefore an additional Map might be required to point into
Heap for efficient retrieval

 *
 */



