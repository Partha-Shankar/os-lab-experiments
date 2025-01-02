#include <stdio.h>

int main() {
    int buffer[10], bufsize = 10, in = 0, out = 0, produce, consume, choice = 0;
    while (choice != 3) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if ((in + 1) % bufsize == out) printf("Buffer is Full\n");
            else {
                printf("Enter the value to produce: ");
                scanf("%d", &produce);
                buffer[in] = produce;
                in = (in + 1) % bufsize;
            }
        } else if (choice == 2) {
            if (in == out) printf("Buffer is Empty\n");
            else {
                consume = buffer[out];
                printf("Consumed value: %d\n", consume);
                out = (out + 1) % bufsize;
            }
        }
    }
    return 0;
}
