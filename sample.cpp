#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <stdexcept>
#include <errno.h>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
typedef unsigned char byte;

vector<byte> read_file(const char* filename) {
	vector<byte> l = vector<byte>();

	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		throw exception();
	}

	const int size = 1024;
	byte buf[size];
	int len = 0;
	while ((len = read(fd, buf, size)) != 0) {
		if (len == -1) {
			throw exception();
		}
		for (int i = 0; i < len; i++) {
			l.push_back(buf[i]);
		}
	}
	close(fd);
	return l;
}

int main() {
	vector<byte> l = read_file("a.txt");
	for (int i = 0; i < l.size(); i++) {
		cout << (char) l[i];
	}
	cout << endl;
} 
