#include <iostream>
#include "qi/util.h"
#include "qi/file.h"

using namespace std;

int main() {
	file f = file("test/a.txt");
	bytes s = f.read();
	for (int i = 0; i < s.size(); i++) {
		cout << (char) s[i];
	}
	f.close();
	return 0;
}
