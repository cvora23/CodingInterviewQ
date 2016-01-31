/*
 * Test39.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: chintan
 */
/*
 * Given a N-ary Tree. Return true if it follows Sum Property otherwise false.
 */

/*
 * public class Node
{
	private int value;
	private ArrayList<Node> children;

}

public class CheckSumProperty
{

	public boolean hasSumProperty(Node n)
	{
		if(n==null)
		{
			return true;
		}
		Queue<Node> q=new Queue<Node>();
		q.enqueue(n);
		while(!q.isEmpty())
		{
			Node top=q.dequeue();
			ArrayList<Node> c=top.children();
			int sum=0;
			for(Node x: c)
			{
				sum+=x.value;
				q.enqueue(x);
			}
			if(sum!=top.value)
			{
				return false;
			}
		}
	return true;
	}
}
 */

