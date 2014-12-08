/*
 * TemplateMetaprogramming.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*

#include <iostream>
using namespace std;

template<int n> struct funStruct
{
    enum { val = 2*funStruct<n-1>::val };
};

template<> struct funStruct<0>
{
    enum { val = 1 };
};


int main()
{
    cout << funStruct<8>::val << endl;
    return 0;
}


Output:

256
The program calculates “2 raise to the power 8 (or 2^8)”. In fact, the structure funStruct can be
used to calculate 2^n for any known n (or constant n). The special thing about above program is:
calculation is done at compile time. So, it is compiler that calculates 2^8. To understand how
compiler does this, let us consider the following facts about templates and enums:

1) We can pass nontype parameters (parameters that are not data types) to class/function templates.
2) Like other const expressions, values of enumaration constants are evaluated at compile time.
3) When compiler sees a new argument to a template, compiler creates a new instance of the template.

Let us take a closer look at the original program. When compiler sees funStruct<8>::val, it tries to
create an instance of funStruct with parameter as 8, it turns out that funStruct<7> must also be
created as enumaration constant val must be evaluated at compile time. For funStruct<7>, compiler
need funStruct<6> and so on. Finally, compiler uses funStruct<1>::val and compile time recursion
terminates. So, using templates, we can write programs that do computation at compile time, such
programs are called template metaprograms. Template metaprogramming is in fact Turing-complete,
meaning that any computation expressible by a computer program can be computed, in some form, by a template metaprogram.
Template Metaprogramming is generally not used in practical programs, it is an interesting conecpt though.


*/
