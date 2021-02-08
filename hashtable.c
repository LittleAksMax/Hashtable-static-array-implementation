#include "hashtable.h"

#define TRUE 1
#define FALSE 0

// this is an fnv hash, very good for shortish strings
unsigned int ht_hash(const char* name, unsigned int length)
{
    unsigned int hash = FNV_OFFSET_32;
    for (int i = 0; i < strlen(name); i++)
    {
        hash = hash ^ (name[i]); // xor next byte into the bottom of the hash
        hash = hash * FNV_PRIME_32; // Multiply by prime number found to work well
    }
    return hash % length;
}

int ht_insert(person_t** ht, person_t* p, unsigned int length)
{
    if (p == NULL) return FALSE;

    unsigned int hash = ht_hash(p->name, length);
    for (int try, i = 0; i < length; i++)
    {
        try = hash + i;
        if (try >= length) // reached end, go to beginning, this will only happen once
            try -= length; // could also % but it would take longer on large hashtables

        if (ht[try] != NULL && ht[try] != DELETED_NODE)
            continue;

        ht[try] = p;
        return TRUE;
    }
    return FALSE; // went through the entire hashtable, no empty spots
}

person_t* ht_search(person_t** ht, const char* name, unsigned int length)
{
    unsigned int hash = ht_hash(name, length);
    for (int try, i = 0; i < length; i++)
    {
        try = hash + i;
        if (try >= length) // reached end, go to beginning, this will only happen once
            try -= length; // could also % but it would take longer on large hashtables

        if (ht[try] == NULL) return NULL;
        
        if (ht[try] == DELETED_NODE) continue;

        if (strcmp(name, ht[try]->name) == 0) 
            return ht[try];
    }
    return NULL;
}

person_t* ht_remove(person_t** ht, const char* name, unsigned int length)
{
    unsigned int hash = ht_hash(name, length);
    for (int try, i = 0; i < length; i++)
    {
        try = hash + i;
        if (try >= length) // reached end, go to beginning, this will only happen once
            try -= length; // could also % but it would take longer on large hashtables

        if (ht[try] == NULL) return NULL;
        if (ht[try] == DELETED_NODE) continue;

        if (strcmp(name, ht[try]->name) == 0) // inverted if
        {
            person_t* tmp = ht[try];
            ht[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}
