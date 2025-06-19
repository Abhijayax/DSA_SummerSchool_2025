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
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &ptr[i].id);
        printf("Name: ");
        scanf("%s", ptr[i].name);
        printf("Salary: ");
        scanf("%f", &ptr[i].salary);
    }
    struct Employee *highest = &ptr[0]; 
    for (int i = 1; i < 5; i++) {
        if (ptr[i].salary > highest->salary) {
            highest = &ptr[i];
        }
    }
    printf("\nEmployee with the highest salary:\n");
    printf("ID: %d\n", highest->id);
    printf("Name: %s\n", highest->name);
    printf("Salary: %.2f\n", highest->salary);
    return 0;
}
