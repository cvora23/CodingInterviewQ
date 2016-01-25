/*
 * Test21.cpp
 *
 *  Created on: Jan 22, 2016
 *      Author: chintan
 */

/*
 * An employee class has id, name and a vector of employees who reports him.
 * Given two employees find the common manager of them.CEO pointer is provided.
 */

/*
Pretty much the same as LCA of a BST, we just need to traverse all children.


Node LCA(Node a, Node b, Node root)
	{
		if(a == root || b == root)
			return root;

		int count = 0;
		Node temp = null;

		for(Node iter : root.children)
		{
			Node res = LCA(a, b, iter);
			if(res != null)
			{
				count++;
				temp = res;
			}
		}

		if(count == 2)
			return root;

		return temp;
	}
*/
