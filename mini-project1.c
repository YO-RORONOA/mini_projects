#include <stdio.h>

#define MAX_BOOKS 100 
int bookcount = 0; // counter to increment for arrays(number of books)

    char bookname[MAX_BOOKS][50];   //variables in global scope to 
    char bookauthor[MAX_BOOKS][50]; //be used by each function
    float bookprice[MAX_BOOKS];
    int bookstock[MAX_BOOKS];

void    addbook()
{
    if(bookcount < MAX_BOOKS) // check if there is enough stock
    {
    printf("\nnote: use _ instead of space");
    printf("\ntype the name of the book you want to add: ");
        scanf("%s", &bookname[bookcount]);
    
    printf("\ntype the author's name of the book: ");
        scanf("%s", &bookauthor[bookcount]);
    
    printf("\ntype the price of the book you want to add: ");
        scanf("%f", &bookprice[bookcount]);
    
    printf("\ntype the quantity availabe of the book you want to add: ");
        scanf("%d", &bookstock[bookcount]);
        bookcount++;
    }
    else
    printf("full stock, cant add more.");
}

void    displaybooks()
{
    int i;

    i= 0;
     if (bookcount == 0) // case if the stock is empty
    {
        printf("\nno books in stock");
        return;
    }
    while(i < bookcount)
    {
        printf("\nbook name: %s\n", bookname[i]);
        printf("book author: %s\n", bookauthor[i]);
        printf("book bookprice: %.2f\n", bookprice[i]);
        printf("book bookstock: %d\n", bookstock[i]);
        i++;
    }
}

int strcmp(const char name[], const char stock[]) //function to find books to update in the array
{
    int i;

    i = 0;
    while(name[i] != '\0' && stock[i] != '\0') // null charchter remember ''
    {
        if(name[i] != stock[i])
        {
            return 1;
        }
        i++;
    }
     return (name[i] == stock[i]) ? 0 : 1; // Return 0 if equal, -1 if not
}

char* strcpy(char dest[], char src[])
{
    int i;

    i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void    updatestock()
{
    char name[50];
    int newq;
    int i;
    int found; // counter to check if book is found (for the if statment)

    i = 0;
    found = 0;
    printf("\nenter the name of the book you want to update: ");
    scanf("%s", name);

    printf("\nenter the new quantity: ");
    scanf("%d", &newq);

    while(i < bookcount)
    {
        if(strcmp(name, bookname[i]) == 0) // if match found update the stock
        {
            bookstock[i] = newq;
            printf("Quantity updated successfully.\n");
            found++;
            return; // Exit the loop
        }
        i++;
    }
    if (found == 0) // if match not found
    {
        printf("book not found\n");
    }
}

void    removestock()
{
    int i;
    char rem[50];

    i = 0;
    printf("\nenter the name of the book you want to remove: ");
    scanf("%s", rem);

    while (i < bookcount)
    {
        int j;   // remember to test i instead of j !!!!
        if(strcmp(rem, bookname[i]) == 0)
        {
            j = i;
            while(j < bookcount - 1) // - 1 to ensure we dont go out of bound 
            {                          // if the book to remove is the last one
                strcpy(bookname[j], bookname[j + 1]); // if that is the case, we dont loop and 
                strcpy(bookauthor[j], bookauthor[j + 1]); // remove it directly by decreminting 
                bookprice[j] = bookprice[j + 1];           // bookcount
                bookstock[j] = bookstock[j + 1];
                j++;
            }
            bookcount--;
            printf("\nbook removed sucessfully\n");
            return;
        }
        i++;
    }
    printf("\nbook not found\n");
    
}

void    displaynbook()
{
    int total;
    int i;

    total = 0;
    i = 0;

    while(i < bookcount)
    {
        total += bookstock[i];
        i++;
    }
    printf("\nthe number of books available in stock is %d\n", total);
}

void    bookdetails()
{
    char details[50];
    int i;

    printf("\nenter the book's name you want details about: ");
    scanf("%s", details);
    while(i < bookcount)
    {
        if(strcmp(details, bookname[i]) == 0)
        {
            printf("book name: %s\n", details);
            printf("book author: %s\n", bookauthor[i]);
            printf("book price: %.2f DH\n", bookprice[i]);
            printf("book stock: %d\n", bookstock[i]);
            return;
        }
        i++;
    }
    printf("\n book not found");

}

int main()
{
    int options;

    printf("welcome to out library stock management software\n");
    while( options != 7)
    {

    
    printf("\nchoose an option from bellow and type the number: ");
    printf("\noption 1: add a book");
    printf("\noption 2: display all the books availabe");
    printf("\noption 3: update stock");
    printf("\noption 4: remove stock");
    printf("\noption 5: display the number of books availabe");
    printf("\noption 6: display informations about a certain book");
    printf("\noption 7: exit program\n");
    printf("option: "); 
    scanf("%d", &options);

    switch (options)
    {
        case 1:
        printf("\nadd a book");
        addbook();
        break;
        case 2:
        printf("\ndisplay all the books availabe");
        displaybooks();
        break;
        case 3:
        printf("\nupdate stock");
        updatestock();
        break;
        case 4:
        printf("\nremove stock");
        removestock();
        break;
        case 5:
        printf("\ndisplay the number of books availabe");
        displaynbook();
        break;
        case 6:
        printf("\ndisplay the a book's information");
        bookdetails();
        break;
    }
    }
    printf("program ended\n");
}