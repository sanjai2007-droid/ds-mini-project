#include <stdio.h>
#include <string.h>
#define SIZE 20

struct Student {
    int regNo;
    char name[30];
};

struct Student table[SIZE];

void init() {
    int i;
    for(i = 0; i < SIZE; i++)
        table[i].regNo = -1;
}

int hash(int key) {
    return key % SIZE;
}

void markAttendance() {
    int regNo;
    char name[30];

    printf("Enter Reg No: ");
    scanf("%d", &regNo);
    printf("Enter Name: ");
    scanf("%s", name);

    int index = hash(regNo);

    while(table[index].regNo != -1)
        index = (index + 1) % SIZE;

    table[index].regNo = regNo;
    strcpy(table[index].name, name);

    printf("Attendance Marked\n");
}

void display() {
    int i;
    for(i = 0; i < SIZE; i++) {
        if(table[i].regNo != -1)
            printf("%d %s Present\n", table[i].regNo, table[i].name);
    }
}

int main() {
    int choice;
    init();

    do {
        printf("1 Mark Attendance\n");
        printf("2 Display\n");
        printf("3 Exit\n");
        scanf("%d", &choice);

        if(choice == 1)
            markAttendance();
        else if(choice == 2)
            display();

    } while(choice != 3);

    return 0;
}


