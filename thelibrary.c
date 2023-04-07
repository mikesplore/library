#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


struct Book {
    char title[100];
    char author[100];
    int id;
    int borrowed;
    int duration;
};

struct students {
    char admNo[14];
    char name[100];
};

int rando() {
    srand(time(NULL));
    return rand() % 9000 + 1000;
   
}
void borrowBook(struct Book books[], int id, struct students *student) {
    int i = 0;
    char admNo[14];
    
    printf("Enter Admission Number: ");
    scanf("%s", admNo);
       
    if (strcmp(admNo, student->admNo) != 0) {
        printf("Invalid admission number. Double check your admission number and try again.\n");
        return;
    }

    for (i = 0; i < 1000; i++) {
        if (books[i].id == id) {
            if (books[i].borrowed == 0) {
                printf("Enter return period. Not more than 14 days: ");
                scanf("%d",&books[i].duration);
                
                if(books[i].duration<=14){
                    books[i].borrowed = 1;
                    printf("Book borrowed successfully by %s!\n", student->name);
                } else {
                    printf("Please enter a period between 1 to 14 days.\n");
                }
            } else {
                printf("Sorry, this book is already borrowed. Please come back later.\n");
            }
            return;
        }
    }
    printf("Sorry, book not found.\n");
}


void displayAvailableBooks(struct Book books[],int numBooks) {
    int i,count=0;
    
    printf("Available books for borrowing:\n");
    
    for (i = 0; i < numBooks; i++) {
        if (books[i].borrowed == 0) {
            printf("%d. %s by %s\n", books[i].id, books[i].title, books[i].author);
            count++;
        }
    }
    if (count == 0) {
        printf("Sorry, no books are currently available for borrowing.\n");
    }
}

void BorrowedBooksReport(struct Book books[], int numBooks, struct students student) {
    int i,count=0;
    
    printf("Borrowed books report:\n");
    
    for (i = 0; i < numBooks; i++) {
        if (books[i].borrowed == 1) {
            printf("%d. %s by %s - Borrowed by %s due in %d days.\n", books[i].id, books[i].title, books[i].author, student.name,books);
            count++;
        }
    }
    if (count == 0) {
        printf("No books are currently borrowed by students.\n");
    }
}
void returnBook(struct Book books[], int id, struct students student) {
    int i;
    char admNo[14];
   
    
    printf("Enter student ID: ");
    scanf("%s", admNo);
           
    
    if (strcmp(admNo, student.admNo) != 0) {
        printf("Invalid student ID.\n");
        return;
    }

    for (i = 0; i < 100; i++) {
        if (books[i].id == id) {
            if (books[i].borrowed == 1) {
                books[i].borrowed = 0;
                printf("The book has been returned successfully by student %s!\n", student.name);
            } else {
                printf("Sorry, this book is not currently borrowed.\n");
            }
            return;
        }
    }
    printf("Sorry, book not found.\n");
}

int main() {
   struct students student;
    char usrname[50], passwd[50];
    char username[] = "admin";
    char password[] = "password";
    int otp;
    int randomnumber=rando();
    
    
    printf("----------------------------------------------------------STUDENTS LIBRARY MANAGEMENT SYSTEM--------------------------------------------\n");

   printf("                                                          Enter your creditentials to continue\n\n");
    printf("                                                              Enter your username: ");
    scanf("%s", usrname);

    printf("                                                              Enter password     : ");
    scanf("%s", passwd);
    
    if(strcmp(usrname, username) == 0 && strcmp(passwd, password) == 0) {
        printf("\n");
        printf("                                                        Login success! your 4 digit OTP is %d\n\n",randomnumber);
        printf("                                                         Enter your admission Number (bscs001j2023): ");
        scanf("%s", &student.admNo);
        printf("                                                         Enter your First Name: ");
        scanf("%*c");
        scanf(" %s",&student.name);
       
       
        struct Book books[1000];
        int numBooks = 0;
        int choice, bookID;
    

    do {
        printf(".\n\n-------------------------------------------Hello %s, Choose one of the options below.-------------------------------------------\n\n",student.name);
        printf("                                     1. Register new book                                    3. Return a book\n");
 
        printf("                                     2. Borrow a book                                        4. Display available books\n");
                 
        printf("                                     5. Display Borrowed books                               6. Exit\n");
        
        
       printf("                                                                Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
    case 1:
        if (numBooks >= 1000) {
            printf("Maximum number of books exceeded.\n");
            break;
        }
        printf("Enter book title: ");
        getchar();
        fgets(books[numBooks].title, 100, stdin);
        printf("Enter book author: ");
        fgets(books[numBooks].author, 100, stdin);
        printf("Enter book ID: ");
        scanf("%d", &books[numBooks].id);
        printf("Enter OTP: ");
        scanf("%d", &otp); 
        if (otp == randomnumber) {
            books[numBooks].borrowed = 0;
            printf("The book has been registered successfully!\n");
            numBooks++;
        } else {
            printf("OTP is incorrect\n");
        }
        break; 

    case 2:
    printf("Enter book ID to borrow: ");
    scanf("%d", &bookID);

    printf("Enter OTP: ");
    scanf("%d", &otp);

    if (otp == randomnumber) {
        borrowBook(books, bookID, &student);
    } else {
        printf("OTP is incorrect\n");
    }
    
    break;
case 3:
    printf("Enter book ID to return: ");
    scanf("%d", &bookID);

    printf("Enter OTP: ");
    scanf("%d", &otp);

    if (otp == randomnumber) {
        returnBook(books, bookID, student);
    } else {
        printf("OTP is incorrect\n");
    }
    
    break;


    case 4:
        displayAvailableBooks(books, numBooks);
        break;

    case 5:
        BorrowedBooksReport(books, numBooks, student);
        break;

    case 6:
        break;

    default:
        printf("Invalid choice.\n");
}

} while (choice != 6);

    } 
    else {
        printf("\n                                                          Invalid username or password. Try again");
    }
    
    return 0;
}