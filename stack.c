#include <stdio.h>
#include "stack.h"

int main(int argc, char const *argv[]) {
  Stack stack;
  stack_init(&stack);
  long long a = 20000004;
  stack_push_long_long(&stack, a++);
  stack_push_long_long(&stack, a++);
  stack_push_long_long(&stack, a);
  while(stack_size(&stack) > 0){
    printf("item: %lld\n",stack_pop_long_long(&stack));
  }
  stack_destroy(&stack);
  return 0;
}
