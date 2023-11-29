#include "var.h"
int main() {
	var a, b, c;
	a = 5;
	b = 5.5;
	c = "23";
	b = a + c;
	b.get_var();
	cout << endl;
	b = a;
	cout << (b == a) << " " << (b != c)<< " ";
	(b / a).get_var();
}