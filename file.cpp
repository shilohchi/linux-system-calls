#include "qi/util.h"
#include "qi/file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdexcept>

using namespace std;

file::file(const char* filename) {
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		throw exception();
	}
	this->fd = fd;
}

void file::close() {
	::close(this->fd);
}

bytes file::read() {
	bytes l = bytes(); 
	const int size = 1024;
	byte buf[size];
	int len = 0;
	while ((len = ::read(this->fd, buf, size)) != 0) {
		if (len == -1) {
			throw exception();
		}
		for (int i = 0; i < len; i++) {
			l.push_back(buf[i]);
		}
	}
	return l;
}

void file::write(bytes s) {
}
