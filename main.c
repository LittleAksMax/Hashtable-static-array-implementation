#include <stdio.h>
#include "hashtable.h"

#define HASHTABLE_LENGTH 20
#define CHECK_HT_SEARCH(temp, name) (((temp = ht_search(myht, name, HASHTABLE_LENGTH)) != NULL) ? (temp->age) : (-1))
// check if NULL so we don't dereference NULL pointer

person_t* myht[HASHTABLE_LENGTH];

void print_ht(person_t** ht)
{
    printf("Start\n");
    for (int i = 0; i < HASHTABLE_LENGTH; i++)
        printf("\t%d\t%s\n", i + 1, ht[i] == NULL ? "------" : (ht[i] == DELETED_NODE ? "--<del>" : ht[i]->name));
        // print "----" if NULL, "--<del>" if deleted, else print what is there
    printf("End\n");
}

int main()
{
    person_t clara = { .name="Clara", .age=13 };
    person_t timi = { .name="Timi", .age=12 };
    person_t szilvi = { .name="Szilvi", .age=15 };
    person_t eleanor = { .name="Eleanor", .age=3 };
    person_t david = { .name="David", .age=6 };
    person_t cara = { .name="Cara", .age=18 };
    person_t lara = { .name="Lara", .age=19 };
    person_t tbgo = { .name="Tbgo", .age=23 };
    person_t morweg = { .name="Morweg", .age=10 };
    person_t toby = { .name="Toby", .age=13 };
    person_t tbag = { .name="Tbag", .age=11 };
    person_t asdf = { .name="Asdf", .age=15 };
    person_t qwerty = { .name="Qwerty", .age=14 };
    person_t miklos = { .name="Miklos", .age=17 };
    person_t violet = { .name="Violet", .age=19 };
    person_t tahmid = { .name="Tahmid", .age=21 };
    person_t telep = { .name="Telep", .age=19 };
    person_t philip = { .name="Philip", .age=18 };
    person_t musaab = { .name="Musaab", .age=19 };
    person_t daniel = { .name="Daniel", .age=19 };
    person_t josh = { .name="Josh", .age=20 };

    printf("insertion of Clara: %d\n", ht_insert(myht, &clara, HASHTABLE_LENGTH));
    printf("insertion of Timi: %d\n", ht_insert(myht, &timi, HASHTABLE_LENGTH));
    printf("insertion of Szilvi: %d\n", ht_insert(myht, &szilvi, HASHTABLE_LENGTH));
    printf("insertion of Eleanor: %d\n", ht_insert(myht, &eleanor, HASHTABLE_LENGTH));
    printf("insertion of David: %d\n", ht_insert(myht, &david, HASHTABLE_LENGTH));
    printf("insertion of Cara: %d\n", ht_insert(myht, &cara, HASHTABLE_LENGTH));
    printf("insertion of Lara: %d\n", ht_insert(myht, &lara, HASHTABLE_LENGTH));
    printf("insertion of Tbgo: %d\n", ht_insert(myht, &tbgo, HASHTABLE_LENGTH));
    printf("insertion of Morweg: %d\n", ht_insert(myht, &morweg, HASHTABLE_LENGTH));
    printf("insertion of Toby: %d\n", ht_insert(myht, &toby, HASHTABLE_LENGTH));
    printf("insertion of Tbag: %d\n", ht_insert(myht, &tbag, HASHTABLE_LENGTH));
    printf("insertion of Asdf: %d\n", ht_insert(myht, &asdf, HASHTABLE_LENGTH));
    printf("insertion of Qwerty: %d\n", ht_insert(myht, &qwerty, HASHTABLE_LENGTH));
    printf("insertion of Miklos: %d\n", ht_insert(myht, &miklos, HASHTABLE_LENGTH));
    printf("insertion of Violet: %d\n", ht_insert(myht, &violet, HASHTABLE_LENGTH));
    printf("insertion of Telep: %d\n", ht_insert(myht, &telep, HASHTABLE_LENGTH));
    printf("insertion of Tahmid: %d\n", ht_insert(myht, &tahmid, HASHTABLE_LENGTH));
    printf("insertion of Philip: %d\n", ht_insert(myht, &philip, HASHTABLE_LENGTH));
    printf("insertion of Musaab: %d\n", ht_insert(myht, &musaab, HASHTABLE_LENGTH));
    printf("insertion of Daniel: %d\n", ht_insert(myht, &daniel, HASHTABLE_LENGTH));
    printf("insertion of Josh: %d\n", ht_insert(myht, &josh, HASHTABLE_LENGTH));

    ht_remove(myht, "Tbag", HASHTABLE_LENGTH);
    ht_remove(myht, "Cara", HASHTABLE_LENGTH);
    ht_remove(myht, "Asdf", HASHTABLE_LENGTH);
    ht_remove(myht, "Lara", HASHTABLE_LENGTH);
    ht_remove(myht, "Telep", HASHTABLE_LENGTH);
    ht_remove(myht, "zxcv", HASHTABLE_LENGTH); // nothing happens

    print_ht(myht);
    person_t* p;
    printf("Qwerty age: %d\n", CHECK_HT_SEARCH(p, "Qwerty")); // 14
    printf("Tahmid age: %d\n", CHECK_HT_SEARCH(p, "Tahmid")); // 21
    printf("Violet age: %d\n", CHECK_HT_SEARCH(p, "Violet")); // 19
    printf("Tbag age: %d\n", CHECK_HT_SEARCH(p, "Tbag")); // 11/-1 depending on if it was removed or not
    printf("Josh age: %d\n", CHECK_HT_SEARCH(p, "Josh")); // -1
    return 0;
}
