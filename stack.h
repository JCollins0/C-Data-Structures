#ifndef JC_STACK_H
#define JC_STACK_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct stack_node
{
  struct stack_node *prev;
  void *value;
} Stack_Node;

typedef struct stack
{
  Stack_Node *top;
  int size;
} Stack;

void stack_init(Stack *stack){
  stack->top = NULL;
  stack->size = 0;
}

void *
stack_push (Stack *stack, void *element, unsigned size_in_bytes)
{
  assert(stack != NULL);
  assert(element != NULL);
  assert(size_in_bytes > 0);

  Stack_Node *node = (Stack_Node *)calloc (1, sizeof(Stack_Node));
  void *ret = (void *)malloc (size_in_bytes);

  if (node == NULL || ret == NULL)
    {
      return NULL;
    }
  memcpy (ret, element, size_in_bytes);
  node->value = ret;
  if (stack->top)
    {
      node->prev = stack->top;
    }
  stack->top = node;
  stack->size++;
  return ret;
}

char *
stack_push_str(Stack *stack, char *element){
  assert(stack != NULL);
  assert(element != NULL);
  void *ret = stack_push(stack, element, strlen(element)+1);
  if(ret){
    return (char *)ret;
  }
  return NULL;
}

int *
stack_push_int(Stack *stack, int *element){
  assert(stack != NULL);
  assert(element != NULL);
  void *ret = stack_push(stack, element, sizeof(int));
  if(ret){
    return (int *)ret;
  }
  return NULL;
}

int stack_size(Stack *stack){
  assert(stack != NULL);
  return stack->size;
}

void *
stack_pop (Stack *stack)
{
  if(stack->top){
    Stack_Node *top = stack->top;
    void *ret = top->value;
    stack->top = top->prev;
    stack->size--;
    free(top);
    return ret;
  }
  return NULL;
}

char *
stack_pop_str(Stack *stack){
  assert(stack != NULL);
  void *ret = stack_pop(stack);
  if(ret){
    return (char *)ret;
  }
  return NULL;
}

int *
stack_pop_int(Stack *stack){
  assert(stack != NULL);
  void *ret = stack_pop(stack);
  if(ret){
    return (int *)ret;
  }
  return NULL;
}

void *stack_peek (Stack *stack){
  assert(stack != NULL);
  if(stack->top)
  {
    return stack->top->value;
  }
  return NULL;
}

void stack_destroy (Stack *stack){
  while(stack_pop(stack));
}

#endif
