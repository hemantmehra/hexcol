#include <string.h>
#include "writer.h"
int get_datatype(char *d) {
	if(strlen(d) != 1) {
		return 0;
	}

	switch(d[0]) {
		case 'b': return 1;
		case 's': return 2;
		case 'i': return 4;
		case 'l': return 8;
		default: return 0;
	}
}