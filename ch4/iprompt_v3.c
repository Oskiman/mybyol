// Including preprocessor code wrapped in
// #ifdef, #else, #endif to make the code
// more portable.  It should compile on Windows, Linux or Mac
#include <stdio.h>
#include <stdlib.h>

// If we are compiling on Windows, compile these functions
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// Fake readline function
char* readline(char* prompt)
{
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

// Fake add_history() function
void add_history(char* unused) {}

// otherwise include the editline headers
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv)
{
	puts("Lispy version 0.0.0.0.1");
	puts("Press Ctrl+c to exit");
	puts("Have fun\n");
	

	while(1)
	{
		// now in either case, readline will be correctly defined
		char* input = readline("input> ");
		add_history(input);

		printf("You input %s\n", input);
		free(input);
	}

	return 0;
}
