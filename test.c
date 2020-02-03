#include <assert.h>
#include <stdio.h>
#include "writer.h"

void get_datatype_test() {
	assert(get_datatype("i") == 4);
}

int main(int argc, char const *argv[])
{
	get_datatype_test();
	return 0;
}