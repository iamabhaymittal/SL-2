/*
//Implementing write
#include<unistd.h>
#include<stdlib.h>

int main()
{
    if((write(1,"Here is some data\n",18)) !=18)
    write(2,"A write error has occurred on file descriptor 1\n",46);

    exit(0);
}
*/
/*//Implementing read()
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char buffer[128];
    int nread;

    nread = read(0, buffer, 128);
    if (nread == -1)
        write(2, "A read error has occurred\n", 26);

    if ((write(1, buffer, nread)) != nread)
        write(2, "A write error has occurred\n", 27);

    exit(0);
}*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
struct student
{
    int id;
    char name[40], college[20];
};

void insert()
{
    int fd = open("database.txt", O_WRONLY | O_CREAT);
    struct student new;

    if (fd == -1)
    {
        printf("Error in creating file");
    }
    else
    {
        printf("\nInsert ID: ");
        scanf("%d", &new.id);

        printf("\nInsert name: ");
        scanf("%s", new.name);

        printf("\nInsert college: ");
        scanf("%s", new.college);
        write(fd, &new, sizeof(new));
    }
    close(fd);
}
void append()
{
    int fd = open("database.txt", O_WRONLY | O_APPEND);
    struct student new;

    if (fd == -1)
    {
        printf("Cannot append. File doesn't exist!");
    }
    else
    {
        printf("\nInsert ID: ");
        scanf("%d", &new.id);

        printf("\nInsert Name: ");
        scanf("%s", new.name);

        printf("\nInsert College: ");
        scanf("%s", new.college);
        write(fd, &new, sizeof(new));
    }
    close(fd);
}
void read1()
{
    int ret, fd;
    struct student new;

    if ((fd = open("database.txt", O_RDONLY)) > 0)
    {
        printf("\n\n \t ID\t Name\t College\n");
        while (read(fd, &new, sizeof(new)) != '\0')
        {
            printf("\n\n \t %d\t %s\t %s\n", new.id, new.name, new.college);
        }
        close(fd);
    }
}

void search()
{
    int ret, fd;
    struct student new;
    int id;
    printf("\n\nEnter ID: ");
    scanf("%d", &id);
    if ((fd = open("database.txt", O_RDONLY)) > 0)
    {
        while (read(fd, &new, sizeof(new)) != '\0')
        {
            if (id == new.id)
            {
                printf("\n\nRecord found\n\n");
                printf("\n\n \t ID\t Name\t College\n");
                printf("\n\n \t %d\t %s\t %s\n", new.id, new.name, new.college);
            }
        }
        close(fd);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n+=================+");
        printf("\n|      MENU       |");
        printf("\n+=================+");
        printf("\n| 1. Insert       |");
        printf("\n| 2. Append       |");
        printf("\n| 3. Search       |");
        printf("\n| 4. Read         |");
        printf("\n| 5. Delete DB    |");
        printf("\n| 0. Exit         |");
        printf("\n+=================+\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            append();
            break;
        case 3:
            search();
            break;
        case 4:
            read1();
            break;
        case 5:
            remove("database.txt");
            printf("\nDeleted database.txt successfully!");
            break;

        case 0:
            printf("\nBye!\n");
            return 0;

        default:
            printf("\nInvalid choice entered. Please re-enter!");
            break;
        }
    }
}