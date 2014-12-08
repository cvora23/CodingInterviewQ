/*
 * WhatAllInheritedFromParentClass.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: cvora
 */

/*
 * What all is inherited from parent class in C++?
Following are the things which a derived class inherits from its parent.
1) Every data member defined in the parent class (although such members may not always be
accessible in the derived class!)
2) Every ordinary member function of the parent class (although such members may not always be
accessible in the derived class!)
3) The same initial data layout as the base class.

Following are the things which a derived class doesn’t inherits from its parent :
1) The base class’s constructors and destructor.
2) The base class’s friends
 */


