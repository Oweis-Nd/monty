#include "mon.h"

#define LIMIT_SIZE 100

int stack[LIMIT_SIZE];
int top = -1


void push(int value)
{
	if (top == LIMIT -1){
	fprint(stderr,"Stack overflow: Cannot push element, stack is full.\n");
	exit(EXIT_FAILURE);
}
stack[++top] = value;
}
 void pall(){
	 int i;
	 for (i = top;  i >= 0; i--){
		 printf("%d\n", stack[i]);
	 }
 }
int main() {
    FILE* file = fopen("error.c", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return EXIT_FAILURE;
    }
