#include <iostream>
using namespace std;

#define MAX_JOBS 100

class job_queue {
    int* arr;
    int front;
    int rare;

public:
    job_queue() {
        arr = new int[MAX_JOBS];
        front = -1;
        rare = -1;
    }

    void push(int x) {
        if (rare == MAX_JOBS - 1) {
            cout << "Queue is full" << endl;
            return;
        }

        rare++;
        arr[rare] = x;

        if (front == -1) {
            front++;
        }
    }

    void pop() {
        if (front == -1 || front > rare) {
            cout << "No elements in queue" << endl;
            return;
        }

        front++;
    }

    void display() {
        if (front == -1 || front > rare) {
            cout << "No elements in queue" << endl;
            return;
        }
        for (int i = front; i <= rare; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Queue" << endl;
    job_queue job;

    int ch, x;

    do {
        cout << "\n1.Insert Job\n2.Delete Job\n3.Display\n4.Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter data: ";
                cin >> x;
                job.push(x);
                break;

            case 2:
                job.pop();
                break;

            case 3:
                job.display();
                break;

            case 4:
                cout << "Exiting Program.....";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.";
        }

    } while (ch != 4);

    return 0;
}