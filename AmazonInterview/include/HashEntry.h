/*
 * HashEntry.h
 *
 *  Created on: Jan 20, 2016
 *      Author: chintan
 */

#ifndef INCLUDE_HASHENTRY_H_
#define INCLUDE_HASHENTRY_H_


class HashEntry{
private:
      int key;
      int value;
public:
      HashEntry(int key, int value) {
            this->key = key;
            this->value = value;
      }

      int getKey() {
            return key;
      }

      int getValue() {
            return value;
      }
};


#endif /* INCLUDE_HASHENTRY_H_ */
