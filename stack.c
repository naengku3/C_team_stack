#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

int Stack[STACK_SIZE]; 
int top = -1; //스택이 비었을때의 스택포인터

int push(int dat); // 함수 프로토타입
int pop(void);
int printstack(void);

int main(void) {
   int choice; // 선택지
    int value; // 스택의 데이터값

    while (1) { // 무한반복
        printf("Stack Program Menu:\n");
        printf("1. Push Value\n");
        printf("2. Pop Value\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) { // switch문으로 입력받은 choice에 따른 메뉴로 이동
            case 1:
                printf("Enter a value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printstack();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid menu option.\n");
        }
    }

    return 0;
}

int push(int dat) {
    if (top >= STACK_SIZE - 1) { // 스택 오버플로우 방지
        printf("Stack Overflow. Cannot push more elements.\n");
    } else {
        Stack[++top] = dat; // 스택 포인터를 증가시켜주고 거기에 데이터 저장
        printf("Pushed %d onto the stack.\n", dat);
    }
    return 0;
}

int pop(void) {
    if (top <= -1) { // 스택이 비었을때
        printf("Stack Underflow. Cannot pop from an empty stack.\n");
    } else {
        int popped = Stack[top];
        Stack[top] = 0; // 데이터를 꺼내고 스택 포인터를 감소
        top--;
        printf("Popped %d from the stack.\n", popped);
    }
    return 0;
}

int printstack(void) {
    if (top == -1) { // 스택이 비었을 때
        printf("The stack is empty.\n");
    } else {
        printf("Stack contents:\n");
        for (int i = top; i >= 0; i--) { // 스택 데이터를 현재 포인터부터 역순으로 출력
            printf("%d\n", Stack[i]);
        }
    }
    return 0;
}