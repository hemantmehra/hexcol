#include <assert.h>
#include <stdio.h>
#include "writer.h"

void test_start(char *s) {
	printf("[Test Start] %s\n", s);
}

void test_end(char *s) {
	printf("[Test End] %s\n", s);
}

void get_datatype_test() {
	test_start("get_datatype()");
	assert(get_datatype("i") == 4);
	test_end("get_datatype()");
}

void writer_test() {
	test_start("writer_test()");
	writer("i", "data.txt");
	FILE *write_ptr;
	write_ptr = fopen("test.column","rb");
	assert(write_ptr != NULL);
	test_end("writer_test()");
}

int main(int argc, char const *argv[])
{
	get_datatype_test();
	writer_test();
	return 0;
}