#include <stdio.h>
#include <string.h>
struct Employee {
    int id;
    char name[100];
    float salary;
};
int main() {
    struct Employee e[5];
    struct Employee *ptr = e; 
    for (int i = 0; i < 5; i++) {
        printf("enter details for employee %d:\n", i + 1);
        printf("iD: ");
        scanf("%d", &ptr[i].id);
        printf("name: ");
        scanf("%s", ptr[i].name);
        printf("salary: ");
        scanf("%f", &ptr[i].salary);
    }
    struct Employee *highest = &ptr[0]; 
    for (int i = 1; i < 5; i++) {
        if (ptr[i].salary > highest->salary) { 
            highest = &ptr[i];
        }
    }
    printf("\nemployee with the highest salary:\n");
    printf("ID: %d\n", highest->id); 
    printf("name: %s\n", highest->name); 
    printf("salary: %.2f\n", highest->salary); 
    return 0;
