all: Stack
	@Stack

Stack: stack.c
	@gcc -o Stack stack.c
