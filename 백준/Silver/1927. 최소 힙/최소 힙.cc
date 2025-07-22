#include <iostream>
#define MAX 100000

using namespace std;

int prior_queue[MAX];
int queueSize = 0;
int pop();
void push(int value);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, input;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;

		if (input == 0) cout << pop() << "\n";
		else push(input);

	}
	return 0;
}

int pop() {
	
	// 비어 있는 상황
	if (queueSize == 0) return 0;

	// 선언
	int child = 2, parent = 1; 
	int item = prior_queue[parent];
	int temp = prior_queue[queueSize--];

	while (child <= queueSize) {
		// 더 작은 자식 노드 결정
		if (child + 1 <= queueSize && prior_queue[child] > prior_queue[child + 1]) child++;

		if (temp <= prior_queue[child]) break;
		else {
			prior_queue[parent] = prior_queue[child];
			parent = child;
			child *= 2;
		}
	}

	// 마지막 노드 값을 정해진 위치에 저장
	prior_queue[parent] = temp;
	return item;
}

void push(int value) {

	queueSize++;

	if (queueSize == 1) {
		prior_queue[1] = value;
		return;
	}

	// 선언
	int child = queueSize, parent = queueSize / 2;

	while (child > 1) {

		if (value >= prior_queue[parent]) {
			prior_queue[child] = value;
			break;
		}
		else {
			prior_queue[child] = prior_queue[parent];
			prior_queue[parent] = value;
			child = parent;
			parent /= 2;
		}
	}

}