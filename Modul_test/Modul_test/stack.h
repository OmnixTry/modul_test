#include <iostream>
using namespace std;

struct elem{
	char symbol;
	elem* next;
	elem(char s = '\0', elem *n = NULL) : symbol(s), next(n){};
};

struct stack{
	elem *top;
	stack(elem *t = NULL) : top(t){};
};

void push(stack &my_stack, char bar);
bool pop(stack &mystack, char &bar);
bool empty_or_not(stack &mystack);