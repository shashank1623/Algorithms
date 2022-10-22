#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
struct Stack {
    int top;
    int array[MAXSIZE];
} st;
void initialize() {
 st.top = -1;
}
int isFull() {   
    if(st.top >= MAXSIZE-1)
        return TRUE;
    else
        return FALSE;
}
int isEmpty() {
 if(st.top == -1)
     return TRUE;
 else
     return FALSE;
}
void push(int num) {
    if (isFull())
        printf("Stack is Full...\n");
    else {
        st.array[st.top + 1] = num;
        st.top++;
    }
}
int pop() {
    if (isEmpty())
        printf("Stack is Empty...\n");
    else {
     st.top = st.top - 1;
        return st.array[st.top+1];
    }
}
int main() {
    char inputString[100], c;
    int i, length;
    initialize();
    printf("Enter a string of paranthesis\n");
    gets(inputString);
    length = strlen(inputString);
    for(i = 0; i < length; i++){
        if(inputString[i] == '{')
            push(inputString[i]);
        else if(inputString[i] == '}')
            pop();
        else {
            printf("Error : Invalid Character !! \n");
            return 0;
        }
    }
    if(isEmpty())
        printf("Valid Paranthesis Expression\n");
    else
        printf("InValid Paranthesis Expression\n");
         
    return 0;
}
