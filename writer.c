#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEADER_SIZE 4

int main(int argc, char const *argv[])
{
	unsigned char buffer[1024];
	unsigned char *buffer_ptr;
	unsigned int datatype;
	int data;
	FILE *write_ptr;

	if(argc > 1) {
		write_ptr = fopen("test.column","wb");
		datatype = atoi(argv[1]);
		memset(buffer, 0, HEADER_SIZE + datatype * (argc - 1));
		memcpy(buffer, (char*)&datatype, HEADER_SIZE);
		
		for(int i=2; i<argc; i++) {
			data = atoi(argv[i]);
			buffer_ptr = &buffer[HEADER_SIZE + (i-2) * datatype];
			memcpy(buffer_ptr, (char*)&data, sizeof(data));
		}
		fwrite(buffer, HEADER_SIZE + datatype * (argc - 2), 1, write_ptr);		
		return 0;
	}
	else {
		printf("Usage: ./writer <datatype> <data...>\n");
	}
	return 1;
}