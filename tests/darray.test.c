#include "darray.h"
#include <criterion/criterion.h>
#define T Darray
Darray*d = NULL;
// static void setup(void) {
//   // puts("Runs before the test");
// }

static void teardown(void) { free(d); }

Test(darray, constructor, .fini = teardown) {
  Darray*d = darray_constructor(10);
  cr_expect_not_null(d, "d is null");
  cr_expect_not_null(d->destructor, "destructor is not implemented");
  cr_expect_not_null(d->get, "get is not implemented");
  // cr_expect_not_null(d->pop, "pop is not implemented");
  cr_expect_not_null(d->push, "push is not implemented");
  cr_expect_eq(d->length, 0);
}

Test(darray, push, .fini = teardown) {
  int size = 10;
  Darray*d = darray_constructor(size);
  for (int i = 0; i < size; i++) {
    int * value = malloc(sizeof(int));
    *value = i;
    d->push(d, value);
  }
  cr_expect_eq(d->length, 10);
}

Test(darray, get, .fini = teardown) {
  int size = 3;
  Darray*d = darray_constructor(size);
  for (int i = 0; i < size; i++) {
    int * value = malloc(sizeof(int));
    *value = i;
    d->push(d, value);
  }
  int value0 = *(int*)d->get(d,0);
  int value1 = *(int*)d->get(d,1);
  int value2 = *(int*)d->get(d,2);
  void* value3 = d->get(d,3);
  cr_expect_eq(d->length, 3);
  cr_expect_eq(value0, 0);
  cr_expect_eq(value1, 1);
  cr_expect_eq(value2, 2);
  cr_expect_null(value3);
}
