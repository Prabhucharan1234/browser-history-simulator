#include <stdio.h>
#include <string.h>
char backStack[100][100];
char forwardStack[100][100];
char currentPage[100] = "Home";
int bt=-1;
int ft=-1;
void pushBack(char page[])
{
    strcpy(backStack[++backTop], page);
}

void pushForward(char page[])
{
    strcpy(forwardStack[++forwardTop], page);
}

char* popBack()
{
    return backStack[backTop--];
}

char* popForward()
{
    return forwardStack[forwardTop--];
}

void visitPage(char page[])
{
    pushBack(currentPage);

    strcpy(currentPage, page);

    forwardTop = -1;

    printf("Visited: %s\n", currentPage);
}

void goBack()
{
    if(backTop == -1)
    {
        printf("No previous page\n");
        return;
    }

    pushForward(currentPage);

    strcpy(currentPage, popBack());

    printf("Current Page: %s\n", currentPage);
}

void goForward()
{
    if(forwardTop == -1)
    {
        printf("No forward page\n");
        return;
    }

    pushBack(currentPage);

    strcpy(currentPage, popForward());

    printf("Current Page: %s\n", currentPage);
}

void displayCurrent()
{
    printf("Current Page: %s\n", currentPage);
}
int main()
{
int choice;
char s[100];
while(1)
{
printf("\n1. Visit\n");
printf("2. Back\n");
printf("3. Forward\n");
printf("4.Current\n");
printf("5. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1:
printf("Enter URL: ");
scanf("%99s", s);
visitPage(s);
break;
case 2:
goBack();
break;
case 3:
goForward();
break;
case 4:
displayCurrent();
break;
case 5:
return 0;
default:
printf("Invalid choice\n");
}
}}
