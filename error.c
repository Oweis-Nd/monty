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


    char line[100];
    int line_number = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        char* opcode = strtok(line, " \n");

        if (opcode != NULL) {
            if (strcmp(opcode, "push") == 0) {
                char* value_str = strtok(NULL, " \n");
                if (value_str == NULL) {
                    fprintf(stderr, "Error on line %d: usage: push integer.\n", line_number);
                    return EXIT_FAILURE;
                }

                int value = atoi(value_str);
                if (value == 0 && strcmp(value_str, "0") != 0) {
                    fprintf(stderr, "Error on line %d: usage: push integer.\n", line_number);
                    return EXIT_FAILURE;
                }

                push(value);
            } else if (strcmp(opcode, "pall") == 0) {
                pall();
            }
        }

        line_number++;
    }

    fclose(file);
    return 0;
}
