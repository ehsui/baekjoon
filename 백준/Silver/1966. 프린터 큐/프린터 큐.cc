#include <iostream>
#define MAX_QSIZE 101

class CircleQueue {
    int front, rear;
    int queue[MAX_QSIZE];

public:
    CircleQueue() {
        front = rear = 0;
    }
    bool isEmpty() {
        return front == rear;
    }
    void enqueue(int item) {
        rear = (rear + 1) % MAX_QSIZE;
        queue[rear] = item;
    }
    int dequeue() {
        front = (front + 1) % MAX_QSIZE;
        return queue[front];
    }
    int peek() {
        return queue[(front + 1) % MAX_QSIZE];
    }
    bool hasHigher(int item) {
        int i = (front + 1) % MAX_QSIZE;
        while (i != (rear + 1) % MAX_QSIZE) {
            if (queue[i] > item) {
                return true;
            }
            i = (i + 1) % MAX_QSIZE;
        }
        return false;
    }
};

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N, M;
        std::cin >> N >> M;

        CircleQueue q;
        CircleQueue idxq;

        for (int i = 0; i < N; ++i) {
            int priority;
            std::cin >> priority;
            q.enqueue(priority);
            idxq.enqueue(i);
        }

        int answer = 0;

        while (!q.isEmpty()) {
            int currentItem = q.dequeue();
            int currentIndex = idxq.dequeue();

            if (q.hasHigher(currentItem)) {
                q.enqueue(currentItem);
                idxq.enqueue(currentIndex);
            }
            else {
                answer++;
                if (currentIndex == M) {
                    std::cout << answer << std::endl;
                    break;
                }
            }
        }
    }

    return 0;
}