#include <stdio.h>
#include <string.h>

int main(int agrc, char* argv[]) {
	char buffer[1024];
	
	while(1) {
		printf("> ");
		scanf("%s", buffer);

		if(strcmp(buffer, "exit") == 0) break;
		else {
			printf("Invalid command\n");
		}
	}
	return 0;
}
