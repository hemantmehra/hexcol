#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "writer.h"

#define HEADER_SIZE 4

int writer(char *d, char *file_name)
{
	unsigned char buffer[1024];
	unsigned char *buffer_ptr;
	unsigned int datatype;
	int data, c = 0;
	FILE *read_ptr, *write_ptr;

	if((read_ptr = fopen(file_name, "r")) != NULL) {
		
		write_ptr = fopen("test.column","wb");

		if((datatype = get_datatype(d)) == 0) {
			printf("Invalid Datatype\n");
			exit(1);
		}

		memcpy(buffer, (char*)&datatype, HEADER_SIZE);
		
		while(fscanf(read_ptr, "%i", &data) == 1) {
			buffer_ptr = &buffer[HEADER_SIZE + c * datatype];
			memcpy(buffer_ptr, (char*)&data, sizeof(data));
			c++;
		}
		fwrite(buffer, HEADER_SIZE + c * datatype, 1, write_ptr);
		fclose(read_ptr);
		fclose(write_ptr);	
		return 0;
	}
	else {
		printf("%s not found\n", file_name);
		exit(1);
	}
	return 1;
}