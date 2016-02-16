/*
 * Test9.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: chintan
 */
/*
 * In year 2001 on October 2, 2001, the date in MMDDYYYY format was a palindrome
(same forwards as backwards), 10/02/2001 -> “10022001”
When was the last palindrome date before 10/02/2001?
 */

/*
 *One year can have only one palindrome as the year fixes the month
 *and date too, so the year has to be less than 2001 since we
 *already have the palindrome for 10/02. It can’t be any year in
 *1900 because that would result in a day of 91, same for 1800 down to 1400.
 *it could be a year in 1300 because that would be the 31st day.
 *So what’s the latest year in 1300 that would make a month?
When you first look at it, 12th month comes to mind as we have to
find the latest date, so it seems it would be 1321.
But we have to keep in mind that we want the maximum year in
1300 century with a valid date, so lets think about 1390 that
will give the date as 09/31, is this a valid date…?
No, because September has only 30 days, so last will be the 31st August.
 Which means the correct date would be 08/31/1380.
 */

