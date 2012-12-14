#ifndef file_h_
#define file_h_
#include "qi/util.h"

class file {
private:
	int fd;

public:
	file(const char* filename);
	bytes read();
	void write(bytes s);
	void close();
};

#endif
