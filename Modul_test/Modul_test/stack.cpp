#include <iostream>
#include "stack.h"
using namespace std;

void push(stack &my_stack, char bar){
	elem *celement = new elem(bar);
	if (my_stack.top == NULL){
		my_stack.top = celement;
		return;
	}
	celement->next = my_stack.top;
	my_stack.top = celement;
}

bool pop(stack &mystack, char &bar){
	if (mystack.top == NULL){
		cout << "Stack Is empty\n";
		return false;
	}
	else{
		bar = mystack.top->symbol;
		elem *help = mystack.top;
		mystack.top = mystack.top->next;
		delete help;
		return true;
	}
}

bool empty_or_not(stack &mystack){
	if (mystack.top == NULL) return true;
	else return false;
}