#ifndef SKIPLIST_H
#define SKIPLIST_H

typedef long (*func_longcmp_f) (
        const void *k1,
        const void *k2,
        const void *udata);

typedef struct {
    void *k, *v;
} skiplist_entry_t;

typedef struct node_s node_t;

struct node_s
{
    skiplist_entry_t ety;

    /* array of pointers as this node could be on a higher express line level.
     * The current node's line level is determined by remembering the line
     * level of the node which points to this node. That's why we don't record
     * the line level in this struct */
    node_t **right;
};


typedef struct {
    func_longcmp_f cmp;

    const void* udata;

    /* population within data structure */
    int count;

    /* number of lines */
    int levels;

    node_t* nil;

    node_t* head;
} skiplist_t;

/**
 * @param udata User data passed to comparator */
skiplist_t *skiplist_new(func_longcmp_f cmp, const void* udata);

void *skiplist_get(skiplist_t * me, const void *key);

/**
 * @return smallest item */
void *skiplist_get_min(skiplist_t * me);

/**
 * @return largest item */
void *skiplist_get_max(skiplist_t * me);

int skiplist_contains_key(skiplist_t * me, const void *key);

void *skiplist_remove(skiplist_t * me, const void *key);

void *skiplist_put(skiplist_t * me, void *key, void *val);

/**
 * @return number of items */
int skiplist_count(const skiplist_t * me);

/**
 * Remove all items */
void skiplist_clear(skiplist_t * me);

void skiplist_free(skiplist_t * me);

void skiplist_freeall(skiplist_t * me);
/*--------------------------------------------------------------79-characters-*/

#endif /* SKIPLIST_H */
