/*
 * WhenToCreateCopyConstructor.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: cvora
 */

/*
 * When should we write our own copy constructor?
 * Don’t write a copy constructor if shallow copies are ok: In C++, If an object has no pointers or
 * any run time allocation of resource like file handle, a network connection..etc,
 * a shallow copy is probably sufficient.
 * Therefore the default copy constructor, default assignment operator, and default destructor
 * are ok and you don’t need to write your own.
 */



