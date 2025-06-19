#include <stdio.h>
struct Box {
    float l;
    float b;
    float h;
};
void swapBoxes(struct Box *b1, struct Box *b2) {
    struct Box temp = *b1;  
    *b1 = *b2;             
    *b2 = temp;            
}
int main() {
    struct Box box1 = {2.0, 3.0, 4.0};
    struct Box box2 = {5.0, 6.0, 7.0};
    printf("before swapping");
    printf("box 1: %.2f x %.2f x %.2f\n", box1.l, box1.b, box1.h);
    printf("box 2: %.2f x %.2f x %.2f\n", box2.l, box2.b, box2.h);
    swapBoxes(&box1, &box2);
    printf("\nafter swapping");
    printf("box 1: %.2f x %.2f x %.2f\n", box1.l, box1.b, box1.h);
    printf("box 2: %.2f x %.2f x %.2f\n", box2.l, box2.b, box2.h);
    return 0;
}
