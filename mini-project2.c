#include <stdio.h>

#define MAX_CONTACTS 100 

int contact_count = 0;

struct contact
{
char name[MAX_CONTACTS];
char email[MAX_CONTACTS];
char tel[MAX_CONTACTS];
};

struct contact contacts[MAX_CONTACTS];

void    addcontact()
{
    if(contact_count < MAX_CONTACTS)
    {
    printf("\ntype the details of contact you want to add\n");
    printf("type the name: ");
    scanf("%s", contacts[contact_count].name);
    printf("type the phone number of the contact: ");
    scanf("%s", &contacts[contact_count].tel);
    printf("type the email adress of the contact: ");
    scanf("%s", contacts[contact_count].email);
    contact_count++;
    }
    else 
    printf("operation failed, contacts full!!!");
}

int strcmp(const char str1[], const char str2[])
{
    int i;
    i = 0;
    while(str1[i] != '\0' && str2[i] != '\0')
    {
    if(str1[i] != str2[i])
    {
        return (str1[i] - str2[i]);
    }
    i++;
    }
    return (str1[i] - str2[i]);
}

char*    strcpy(char dest[], char src[])
{
    int i;

    i = 0;

    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}

void    updatecontact()
{
    int i;
    char    nameup[50];

    i = 0;
    printf("\nenter the name of the contact you want to update: ");
    scanf("%s", nameup);

    while(i < contact_count)
    {
        if(strcmp(nameup, contacts[i].name) == 0)
        {
            printf("update %s's phone number: ", nameup);
            scanf("%s", &contacts[i].tel);
            printf("update %s's email adress: ", nameup);
            scanf("%s", contacts[i].email);
            return;
        }
        i++;
    }
    printf("contact not found");

}

void    deletecontact()
{
    int i;
    int j;
    char namedelete[50];
    i = 0;
    printf("\nenter the name of the contact you want to remove: ");
    scanf("%s", namedelete);


    while(i < contact_count)
    {
    if(strcmp(namedelete, contacts[i].name) == 0)
    {
        j = i;
        while(j < contact_count - 1)
        {
            strcpy(contacts[j].name, contacts[j + 1].name);
            strcpy(contacts[j].email, contacts[j + 1].email);
            strcpy(contacts[j].tel, contacts[j + 1].tel);
            j++;
        }
        contact_count--;
        printf("contact removed successfully");
        return;
    }
    i++;
    }
    printf("contact not found");
}

void    displaycontacts()
{
    int i;

    i = 0;
    printf("\nall the contacts stored are as follow:\n");
    while(i < contact_count)
    {
        printf("name: %s\n", contacts[i].name);
        printf("email: %s\n", contacts[i].email);
        printf("phone: %s\n\n", contacts[i].tel);
        i++;
    }
}

void    findcontact()
{
    int i;
    char findname[50];

    i = 0;
    printf("\n enter the name of the contact you want info about: ");
    scanf("%s", findname);
    while(i < contact_count)
    {
        if(strcmp(findname, contacts[i].name) == 0)
        {
            printf("\nname: %s\n", contacts[i].name);
            printf("email: %s\n", contacts[i].email);
            printf("phone: %s\n", contacts[i].tel);
            return;
        }
        i++;
    }
    printf("contact not found");
}

int main()
{
    int options;

    options = 0;

    printf("welcome to our contact management software\n");
    while( options != 6)
    {
        printf("\nchoose an option from bellow and type the number: ");
    printf("\noption 1: add a contact");
    printf("\noption 2: display all the contacts availabe");
    printf("\noption 3: update a contact");
    printf("\noption 4: remove a contact");
    printf("\noption 5: display informations about a certain contact");
    printf("\noption 6: exit program\n");
    printf("option: "); 
    scanf("%d", &options);

    switch(options)
    {
        case 1:
        printf("\nadd a contact");
        addcontact();
        break;
        case 2:
        printf("\ndisplay all the contacts availabe");
        displaycontacts();
        break;
        case 3:
        printf("\nupdate stock");
        updatecontact();
        break;
        case 4:
        printf("\nremove stock");
        deletecontact();
        break;
        case 5:
        printf("\ndisplay the number of contacts availabe");
        findcontact();
        break;
    }
    }
    printf("program ended");
}