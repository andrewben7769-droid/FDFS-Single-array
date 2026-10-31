#include <stdio.h>
#define MAX 100

int arr[MAX];
int size = 0;

void display() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int value, int position) {
    if (size == MAX) {
        printf("Array is full\n");
        return;
    }

    if (position < 0 || position > size) {
        printf("Invalid position\n");
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    size++;

    printf("Element inserted successfully\n");
}

void deleteElement(int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position\n");
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    printf("Element deleted successfully\n");
}

int search(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Array ADT ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (0-based): ");
                scanf("%d", &position);
                insert(value, position);
                break;

            case 2:
                printf("Enter position (0-based): ");
                scanf("%d", &position);
                deleteElement(position);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                position = search(value);

                if (position == -1)
                    printf("Element not found\n");
                else
                    printf("Element found at position %d\n", position);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
