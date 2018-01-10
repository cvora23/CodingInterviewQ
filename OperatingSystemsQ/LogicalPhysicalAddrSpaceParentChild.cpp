/*
 * LogicalPhysicalAddrSpaceParentChild.cpp
 *
 *  Created on: Jan 2, 2018
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
 * what is different of Logical address and Physical address between father process and child process？
 */

/*
 * Initially both parent and child share the page(logically and physically) as long as they don't write to the page,
 * when one of the processes attempts to write something to the page, then an extra copy of the page will be allocated. That is copy-on-write.

Therefore, parent and child process could share same physical page as long as the page is read-only
(like pages in text segment or some shared-library segment. it is different when saying the page is marked as read-only in page table,
see reference below for more info) or no one attempts to write the page. When copy-on-write occurs, the logical and physical mappings
should be different in parent and child process.
 */

int main(){


	return 0;

}
