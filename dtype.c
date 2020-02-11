#include <string.h>
#include "writer.h"

int get_datatype(char *d) {
	if(strlen(d) != 1) {
		return ZERO;
	}

	switch(d[0]) {
		case 'b': return BYTE;
		case 's': return SHORT;
		case 'i': return INT;
		case 'l': return LONG;
		default: return ZERO;
	}
}