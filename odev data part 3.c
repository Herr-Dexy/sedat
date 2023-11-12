#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int number;
    char name[50];
    int age;
    struct student* next;
};

void add_student(struct student** head, int number, char* name, int age) {
    struct student* new_student = (struct student*)malloc(sizeof(struct student));
    new_student->number = number;
    strcpy(new_student->name, name);
    new_student->age = age;
    new_student->next = *head;
    *head = new_student;
}

void print_students(struct student* head) {
    int count = 0;
    while (head != NULL) {
        printf("%d- %s %d %d\n", ++count, head->name, head->age, head->number);
        head = head->next;
    }
}

int search_by_name(struct student* head, char* name) {
    int count = 0;
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("%d- %s %d %d\n", ++count, head->name, head->age, head->number);
        }
        head = head->next;
    }
    return count;
}

void delete_next_node(struct student* head, char* name) {
    while (head != NULL && head->next != NULL) {
        if (strcmp(head->name, name) == 0) {
            struct student* temp = head->next;
            head->next = temp->next;
            free(temp);
            return;
        }
        head = head->next;
    }
}

char* find_longest_name(struct student* head) {
    char* longest_name = NULL;
    int max_length = 0;

    while (head != NULL) {
        int current_length = strlen(head->name);
        if (current_length > max_length) {
            max_length = current_length;
            longest_name = head->name;
        }
        head = head->next;
    }

    return longest_name;
}

int main() {
    struct student* head = NULL;

    // Add students
    add_student(&head, 201, "Saliha", 27);
    add_student(&head, 203, "Ece", 19);
    add_student(&head, 204, "Ali", 22);
    add_student(&head, 205, "Mehmet", 21);
    add_student(&head, 206, "Ayse", 20);
    add_student(&head, 207, "Fatma", 23);
    add_student(&head, 208, "Ahmet", 24);
    add_student(&head, 209, "Merve", 25);
    add_student(&head, 210, "Kemal", 26);
    add_student(&head, 211, "Zeynep Yagmur", 28);
    // Print all students
    printf("All students:\n");
    print_students(head);

    // Search by name
    char search_name[50] = "Saliha";
    printf("\nStudents with name '%s':\n", search_name);
    int count = search_by_name(head, search_name);

    if (count == 0) {
        printf("No students found with name '%s'\n", search_name);
    } else {
        printf("Found %d students with name '%s'\n", count, search_name);
    }

    // Find the longest name
    char* longest_name = find_longest_name(head);
    printf("\nLongest name: %s\n", longest_name);

    // Delete next node
    char delete_name[50] = "Ece";
    printf("\nDeleting next node after '%s':\n", delete_name);
    delete_next_node(head, delete_name);

    // Print all students again
    printf("\nAll students after deletion:\n");
    print_students(head);

    return 0;
}
