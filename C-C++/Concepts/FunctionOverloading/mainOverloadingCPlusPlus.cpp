/*
 * mainOverloadingCPlusPlus.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: cvora
 */

/*
 * Can main() be overloaded in C++?
Predict the output of following C++ program.

#include <iostream>
using namespace std;
int main(int a)
{
    cout << a << "\n";
    return 0;
}
int main(char *a)
{
    cout << a << endl;
    return 0;
}
int main(int a, int b)
{
    cout << a << " " << b;
    return 0;
}
int main()
{
    main(3);
    main("C++");
    main(9, 6);
    return 0;
}
The above program fails in compilation and produces warnings and errors (See this for produced warnings and errors).
You may get different errors on different compilers.

To overload main() function in C++, it is necessary to use class and declare the main as member function.
Note that main is not reserved word in programming languages like C, C++, Java and C#. For example,
we can declare a variable whose name is main, try below example:

#include <iostream>
int main()
{
    int main = 10;
    std::cout << main;
    return 0;
}
Ouput:

10
The following program shows overloading of main() function in a class.

#include <iostream>
using namespace std;
class Test
{
public:
    int main(int s)
    {
        cout << s << "\n";
        return 0;
    }
    int main(char *s)
    {
        cout << s << endl;
        return 0;
    }
    int main(int s ,int m)
    {
        cout << s << " " << m;
        return 0;
    }
};
int main()
{
    Test obj;
    obj.main(3);
    obj.main("I love C++");
    obj.main(9, 6);
    return 0;
}
The outcome of program is:

3
I love C++
9 6
 */


