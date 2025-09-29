
short trunc(int x) {
	return x;
}

struct A {
	int arr[10];
};

struct B
{
	A a;
};


int* getelementptr(B& b) {
	return &b.a.arr[1];
}

int srem(int a, int b) {
	return a % b;
}

unsigned lhsr(unsigned x) {
	return x >> 2;
}

unsigned long long zext(unsigned x) {
	return x;
}

float bitcast(int x) {
	return *((float*)&x);
}

float sitofp(int x) {
	return x;
}

int select(int x, int y) {
	int result;
	if (x > 0) {
		result = x;
	} else {
		result = y;
	}
	result *= 2;
	return result;
}

double fpext(float x) {
	return x;
}

int tailcall(int a, int b) {
	return a > b ? a : b;
}

int main() {
}
