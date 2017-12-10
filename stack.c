#include <stdio.h>
#include "stack.h"

int main(int argc, char const *argv[]) {
  Stack stack;
  stack_init(&stack);
  char *a = "test";
  stack_push_str(&stack, a);
  stack_push_str(&stack, a);
  stack_push_str(&stack, a);
  while(stack_size(&stack) > 0){
    printf("item: %s\n",stack_pop_str(&stack));
  }
  stack_destroy(&stack);
  return 0;
}
