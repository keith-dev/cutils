#include "../src/ustring.h"

#include <assert.h>
#include <stdio.h>

int main() {
	s22h::cutils::ustring s1("®");
	s22h::cutils::ustring s2(s1);
	s22h::cutils::ustring s3, s4;
	s3 = s2;
	s4 = "Hello World!";
	assert(s1 == s2);
	assert(s2 == s3);
	
	printf("%s\n", s4.c_str());
	printf("\"%s\" has size %zu and length %zu.\n", s3.c_str(), s3.buffer_size(), s3.size());
}
