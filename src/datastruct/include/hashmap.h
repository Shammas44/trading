#ifndef MAP_H
#define MAP_H
#include <stddef.h>
#include <stdlib.h>
#define T Hashmap

typedef struct T T;

typedef void(Hashmap_push)(T *map, const char *key, void *value);
typedef void(Hashmap_destructor)(T *map);
typedef void *(Hashmap_get)(T *map, const char *key);

typedef struct {
  char *key;
  void *value;
} Hashmap_entry;

struct T {
  Hashmap_destructor *destructor;
  Hashmap_push *push;
  Hashmap_get *get;
  Hashmap_entry *entries;
  int capacity;
  int size;
};

T *hashmap_constructor(size_t initial_capacity);

#undef T
#endif