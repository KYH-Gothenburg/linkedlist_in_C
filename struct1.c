#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    char email[100];
    int age;
};


int main() {
    struct Person person1;
    struct Person person2;
    strcpy(person1.name, "Pelle Karlsson");
    strcpy(person1.email, "pelle@email.com");
    person1.age = 34;
    strcpy(person2.name, "Anna Svensson");
    strcpy(person2.email, "anna@email.com");
    person2.age = 24;

    printf("Person 1\n");
    printf("%s\n", person1.name);
    printf("%s\n", person1.email);
    printf("%d\n", person1.age);

    printf("Person 2\n");
    printf("%s\n", person2.name);
    printf("%s\n", person2.email);
    printf("%d\n", person2.age);

    return 0;
}