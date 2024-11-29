#include <iostream>
#include <cstdlib> // for malloc and free
using namespace std;
#define MAX 10

struct node {
    int data;
    struct node* link;
};

struct node* push(int n, struct node* top) {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == nullptr) {// Check if memory is allocated or not
        std::cout << "Stack Overflow\n";// If memory is not allocated for temp then print error message "Stack Overflow"
        return top;
    }
    temp->data = n;
    temp->link = top;
    top = temp; // Update the top pointer
    return top; // Return the updated top pointer
}

int pop(struct node*& top) { // Pass top pointer by reference
    struct node* temp = top;
    int item = temp->data;
    top = top->link;
    free(temp);
    temp = nullptr;
    return item;
}

void print(struct node* top) { // Pass top pointer
    struct node* temp = top;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->link;
    }
}

int isempty(struct node* top) { // Pass top pointer
    if (top == nullptr) {
        return 1;
    } else {
        return 0;
    }
}

int peek(struct node* top) { // Pass top pointer
    if (!isempty(top)) {
        return top->data;
    } else {
        std::cout << "Stack is empty\n";
        return -1;
    }
}

int main() {
    struct node* top = nullptr;

    top = push(10, top);
    top = push(20, top);
    top = push(30, top);
    top = push(40, top);
    top = push(50, top);
    top = push(60, top);
    top = push(70, top);
    top = push(80, top);
    top = push(90, top);
    top = push(100, top);
    top = push(110, top);
    print(top);
    cout<<endl;
    std::cout << "Popped element is " << pop(top) << std::endl;
    std::cout << "Popped element is " << pop(top) << std::endl;
    print(top);
    cout<<endl;
    std::cout << "Top element is " << peek(top) << std::endl;
    top = push(120, top);
    print(top);

    // Free memory for remaining elements
    while (!isempty(top)) {
        pop(top);
    }

    return 0;
}
