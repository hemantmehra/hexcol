#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEADER_SIZE 4

int main(int argc, char const *argv[])
{
	unsigned char buffer[1024];
	unsigned char *buffer_ptr;
	unsigned int datatype;
	int data, c = 0;
	FILE *read_ptr, *write_ptr;

	if(argc > 2) {
		if ((read_ptr = fopen(argv[2], "r")) == NULL) {
			printf("%s not found\n", argv[2]);
			exit(1);
		}
		write_ptr = fopen("test.column","wb");
		datatype = atoi(argv[1]);
		//memset(buffer, 0, HEADER_SIZE + datatype * (argc - 1));
		memcpy(buffer, (char*)&datatype, HEADER_SIZE);
		
		while(fscanf(read_ptr, "%i", &data) == 1) {
			buffer_ptr = &buffer[HEADER_SIZE + c * datatype];
			memcpy(buffer_ptr, (char*)&data, sizeof(data));
			printf("%i\n", data);
			c++;
		}
		fwrite(buffer, HEADER_SIZE + c * datatype, 1, write_ptr);
		fclose(read_ptr);
		fclose(write_ptr);	
		return 0;
	}
	else {
		printf("Usage: ./writer <datatype> <data...>\n");
	}
	return 1;
}