#include <stdio.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

typedef struct {
    int roll;
    char name[NAME_LEN];
    float marks;
} Student;

int main(void) {
    Student students[MAX_STUDENTS];
    int n;

    printf("Enter number of students (1-%d): ", MAX_STUDENTS);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_STUDENTS) {
        printf("Invalid count.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Roll: ");
        scanf("%d", &students[i].roll);

        printf("Name: ");
        // Read a full line (including spaces) up to NAME_LEN-1 chars
        scanf(" %49[^\n]", students[i].name);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < n; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               students[i].roll, students[i].name, students[i].marks);
    }

    return 0;
}
