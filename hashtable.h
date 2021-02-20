#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <string.h>

#define DELETED_NODE (person_t*)(0xFFFFFFFFFFFFFFFFUL) // an address that will never be used in hashtable

#define MAX_NAME 20

#define FNV_PRIME_32 16777619
#define FNV_OFFSET_32 2166136261U

typedef struct {
    char name[MAX_NAME];
    int age;
} person_t;

// find index 
unsigned int ht_hash(const char*, unsigned int);

// insert certain value into hashtable
int ht_insert(person_t**, person_t*, unsigned int);

person_t* ht_search(person_t**, const char*, unsigned int);

// remove certain value from hashtable, return pointer so it can be freed if allocated on heap
person_t* ht_remove(person_t**, const char*, unsigned int);

#endif
