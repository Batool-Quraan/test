#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
#define NAMESIZE 50
void addBook( char[][NAMESIZE], int [], double [],int *);
void removeBook(char[][NAMESIZE], int [], double [], int *);
void searchForBook( char[][NAMESIZE], int[], double [], int);
void uploadDataFile( char[][NAMESIZE], int[], double[], int*);
void updateDataFile(char[][NAMESIZE], int[], double[], int);
void printBooks( char[][NAMESIZE], int[], double[], int);
void displayMainMenu();

int main()
/*Name:Batool Sammy Salem Quraan
            id #: 1242879
            lecture section: 3
            lab section: 10L */
{
    char names[50][NAMESIZE];
    int bins[MAXSIZE];
    double prices[MAXSIZE];
    int size=0;
    printf("Welcome to My BookStore Management: ");
    printf("\nUploading Data File...");
    uploadDataFile(names, bins, prices, &size);
    printf("\nData File Uploaded");
    int x;

    do
    {
        displayMainMenu();

        scanf("%d", &x);
        switch(x)
        {
            case 1 : addBook(names, bins, prices, &size);
                     break;


            case 2 : removeBook(names, bins, prices, &size);
                     break;

            case 3 : searchForBook(names, bins, prices, size);
                     break;

            case 4 : printBooks(names, bins, prices, size);
                     break;

            case 5 : updateDataFile(names, bins, prices, size);
                     printf("Exiting System...");
                     break;

            default : printf("invalid operation");
                      break;

        }
    }
    while(x != 5);
    return 0;
}

void uploadDataFile(char names[][NAMESIZE], int bins[], double prices[], int *size)
{
    FILE *in;
    in= fopen("books.txt", "r");
    *size=0;
    if(*size<MAXSIZE)
    {

    while(fscanf(in , "%s %d %lf",names[*size], &bins[*size], &prices[*size])!= EOF)
         {
            (*size)++;
         }
    }
    fclose(in);
}

void addBook(char names[][NAMESIZE], int bins[], double prices[],int *size)
{
    char new_name[MAXSIZE];
    int new_bin;
    double new_price;
    int new_index=0;
    int j;
    int i;
    if(*size >= MAXSIZE)
    {
        printf("There is no empty space for this book");
        return;
    }
    if(*size< MAXSIZE)
    {
        printf("please Enter Bin number(contains of 4 integers) to add : ");
        scanf("%d", &new_bin);

                for(i=0 ; i < *size ; i++)
        {
            if(new_bin== bins[i])
            {
                printf("this book is already exist, so we can't add it again");
                return;

            }
        }
         if(*size< MAXSIZE)
            {
        printf("\nPlease Enter the price of this book : ");
        scanf("%lf", &new_price);
        printf("\nPlease enter the name of the book : ");
        scanf("%s", new_name);
            }



                while(new_index< *size && new_bin >bins[new_index])
                {
                    new_index++;
                }
                for(j= (*size)-1 ; j >= new_index ; j--)
                {
                    bins[j+1]=bins[j];
                    prices[j+1]=prices[j];
                    strcpy(names[j+1] , names[j]);
                }
                    bins[new_index] = new_bin;
                    prices[new_index]= new_price;
                    strcpy(names[new_index], new_name);
                    (*size)++;
                    printf("The book has added successfully!");

    }

            }





void removeBook(char names[][NAMESIZE], int bins[], double prices[], int *size)
{
    if(*size==0)
    {
        printf("\nthere are no books in the store");
        return;
    }
    else
    {
        int exist_bin;
        printf("\nplease enter a bin number to remove : ");
        scanf("%d", &exist_bin);
        int i;
        for(i=0 ; i<*size ; i++)
        {
            if(exist_bin== bins[i])
            {
                int delete_index;
                for(delete_index=i ; delete_index< (*size)-1 ; delete_index++)
                {
                    bins[delete_index]=bins[delete_index+1];
                    prices[delete_index]= prices[delete_index+1];
                    strcpy(names[delete_index], names[delete_index+1]);
                }
                (*size)--;
                printf("the book has removed successfully");
                return;
            }

        }
        printf("This book does not exist in the book store");

    }
}

void searchForBook(char names[][NAMESIZE], int bins[], double prices[], int size)
{
    int i;
    int search_book;
    if(size>0)
    {
           printf("print the bin number for the book you are searching for : ");
           scanf("%d", &search_book);
           for(i=0 ; i<size ; i++)
    {
        if(search_book== bins[i])
        {
            printf("NAME= %-15s \t BIN#= %-10d \t PRICE= %-10.2f\n", names[i], bins[i] , prices[i]);
            return;

        }

    }
    printf("the book does not exist");
    }
    else if(size==0)
    {
        printf("there are no books in the store");
    }


}

void updateDataFile(char names[][NAMESIZE], int bins[], double prices[], int size)
{
    FILE *out;
    int i;
    out=fopen("books.txt" , "w");
    for(i=0 ; i<size ; i++)
    {
        fprintf(out, "%-15s %-10d %-10.2f\n" ,names[i], bins[i], prices[i]);
    }
    fclose(out);

}

void printBooks(char names[][NAMESIZE], int bins[], double prices[], int size)
{
    int i;
    int counter=0;
    for(i=0 ; i<size ; i++)
    {
        printf("NAME= %-15s \t BIN#= %-10d \t PRICE= %-10.2f\n",names[i], bins[i], prices[i]);
        counter++;
    }
}

void displayMainMenu()
{
        printf("\n\nPlease Select an Operation(1-4)");
        printf("\n1- Add A Book");
        printf("\n2- Remove A Book");
        printf("\n3- Search For A Book");
        printf("\n4- Print Book List");
        printf("\n5- Exit System");

}
