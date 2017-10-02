#include <iostream>
using namespace std;

int main() {

	long N;
	long M;

	cin >> N >> M;

	typedef long * LongPtr;
	LongPtr delays = new long[N];
	LongPtr combination = new long[N];
	long currentCombination = 0;
	long cumulativeDelay = 0;
	long max = 0;

	for (long n = 0; n < N; n++) {
		cin >> delays[n];
		if (delays[n] > max)
			max = delays[n];
	}

	for (long n = 0; n < N; n++) {
		if (delays[n] + cumulativeDelay <= max) {
			cumulativeDelay += delays[n];
			combination[n] = currentCombination;
		} else {
			cumulativeDelay = delays[n];
			currentCombination++;
		}
	}
	cout << (currentCombination + 1) << endl;
	
	return 0;
}
