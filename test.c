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

int main(int argc, char const *argv[])
{
	get_datatype_test();
	return 0;
}