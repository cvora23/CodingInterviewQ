/*
 * EmployeeRecordVertice.h
 *
 *  Created on: Jan 21, 2016
 *      Author: chintan
 */

#ifndef INCLUDE_EMPLOYEERECORDVERTICE_H_
#define INCLUDE_EMPLOYEERECORDVERTICE_H_

#include<iostream>
using namespace std;

class EmployeeRecordVertice{

public:
    friend std::ostream& operator<<(std::ostream& os, const EmployeeRecordVertice& ver);
    EmployeeRecordVertice(std::string empId,std::string firstName,
    		std::string lastName,std::string reportsTo){
    	this->empId = empId;
    	this->firstName = firstName;
    	this->lastName = lastName;
    	this->reportsTo = reportsTo;
    }

    std::string getEmpId()const{
    	return empId;
    }
    std::string getFirstName()const{
    	return firstName;
    }
    std::string getLastName()const{
    	return lastName;
    }
    std::string getReportsTo()const{
    	return reportsTo;
    }

private:
    std::string empId;
    std::string firstName;
    std::string lastName;
    std::string reportsTo;
};

std::ostream& operator<<(std::ostream& os, const EmployeeRecordVertice& ver)
{
    os << "{ "<<ver.getFirstName() << ',' << ver.getLastName() << " }";
    return os;
}

#endif /* INCLUDE_EMPLOYEERECORDVERTICE_H_ */
