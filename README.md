# C_team_stack

1.스택의 정의
후입선출 (LIFO) 원칙에 따라 데이터를 저장하는 자료구조, 한쪽 끝에서만 자료를 넣거나 뺄 수 있는 선형 구조로 되어 있다.


2.스택의 응용
함수 호출 관리
```c
#include <stdio.h>

void func2() {
    printf("함수 func2 시작\n");
}

void func1() {
    printf("함수 func1 시작\n");
    func2();
    printf("함수 func1 끝\n");
}

int main() {
    printf("메인 함수 시작\n");
    func1();
    printf("메인 함수 끝\n");
    return 0;
}
```
위의 c언어 예시처럼 main 함수가 호출되면 "메인 함수 시작"이 출력되고, main 함수의 호출은 함수 호출 스택에 저장됩니다.
main 함수에서 func1 함수가 호출됩니다. "함수 func1 시작"이 출력되고, 이 호출 역시 스택에 저장됩니다.
func1 함수에서 func2 함수가 호출됩니다. "함수 func2 시작"이 출력되고, 이 호출 역시 스택에 저장됩니다.
func2 함수가 실행을 마치고 반환됩니다. 이에 따라 func2 함수의 호출은 스택에서 제거됩니다.
func1 함수에서 "함수 func1 끝"이 출력되고, func1 함수의 호출도 스택에서 제거됩니다.
main 함수에서 "메인 함수 끝"이 출력되고, main 함수의 호출도 스택에서 제거됩니다.

이 과정에서 함수 호출 스택은 함수 호출 및 반환의 순서를 추적하고, 스택에는 각 함수 호출에 필요한 정보가 저장된다. 
함수가 반환되면 해당 함수 호출 정보가 스택에서 제거되므로 호출 스택은 현재 실행 중인 함수를 추적하는 데 사용된다.

이 외에도 아래와 같은 곳에 응용이 됩니다.
괄호 검사: 스택은 괄호 ( (), {}, [])의 올바른 쌍을 검사하는 데 사용됩니다. 여는 괄호를 스택에 푸시하고 닫는 괄호를 만날 때마다 스택에서 팝하여 괄호가 올바른 순서로 열리고 닫히는지 확인할 수 있습니다.

뒤로 가기 기능: 웹 브라우저에서 뒤로 가기 버튼을 누를 때 이전 페이지로 돌아가는 것도 스택을 사용한 예입니다. 방문한 페이지의 URL을 스택에 저장하고 뒤로 가기 버튼을 누르면 스택에서 URL을 팝하여 이전 페이지로 이동합니다.

뒷면 돌리기: 그래픽 애플리케이션에서 물체의 이전 상태를 저장하고 되돌리기 (undo)를 지원하는 데 스택을 사용할 수 있습니다. 현재 상태를 스택에 푸시하고 되돌리기를 수행할 때 스택에서 상태를 팝하여 이전 상태로 돌아갈 수 있습니다.

후위 표기법 계산: 스택을 사용하여 수식을 후위 표기법으로 변환하고 후위 표기법 수식을 계산하는 데 활용할 수 있습니다. 후위 표기법은 연산자가 피연산자 뒤에 오는 형식으로 수식을 표현합니다.

미로 탐색: 스택을 사용하여 미로에서 경로를 찾아가는 데 활용할 수 있습니다. 현재 위치에서 가능한 모든 방향을 스택에 저장하고 갈 수 있는 방향으로 이동하며 미로를 탐색합니다.

역순 출력: 스택을 사용하여 입력된 데이터를 역순으로 출력하거나 처리할 수 있습니다. 데이터를 스택에 저장한 후 스택에서 팝하여 역순으로 처리하거나 출력합니다.


3.스택의 구현
```c
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
```
설명은 주석에 달아 두었습니다.
