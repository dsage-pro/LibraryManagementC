#include <iostream>
#include <string.h>
#include <vector>
#include "class.h"

using namespace std;

class Book
{
    int BookId;
    string BookTitle;
    string BookDescription;
    string BookAuthor;
    static vector<Book> booklist;
    bool Borrowed;
public:
    Book(int id, string title, string author, string description){
        BookId = id;
        BookTitle = title;
        BookDescription = description;
        BookAuthor = author;
        Borrowed = false;
    }
    static void addBook(){
        int id; string title, description, author;
        cout << "What is the Book id?";
        cin >> id;
        cout << "What is the Book title?";
        cin >> title;
        cout << "About the Book";
        cin >> description;
        cout << "Who is the Author?";
        cin >> author;
      //  booklist.push_back(Book(id, title, author, description));
    }
    static void updateBook(){
    }
    static void deleteBook(){
        int id; string title, description, author;
        cout << "What book do you want to delete?";
        cin >> id;
       // booklist.at(id);
    }
    static void listAllBooks(){
        //for(Book e : booklist){
         //  cout << " | " << e.BookId << " | " ;
         //  cout << " | " << e.BookTitle << " | " ;
          // cout << " | " << e.BookAuthor << " | " ;
          // cout << " | " << e.BookDescription << endl;
        //}
    }
    static void borrowBook(){
    }
    static void returnBook(){
    }
};


class Teacher
{
  char username[10];
  char password[10];
  bool loggedIn = false;
public:
    Teacher(){
       while(loggedIn == false){
        system("cls");
        cout << "\n -----------Teacher Login----------\n\n\n";
        cout << "\nEnter your Admin username:\n";
        cin >> username;
        cout << "\nEnter your Admin  password:\n";
        cin >> password;
        if(strcmp(username,ADMINUSER) == 0 && strcmp(password,ADMINPASSWORD) == 0){
            loggedIn == true;
            int ichoice = 0;
            while(ichoice != 9){
            system("cls");
            cout << "========Teacher Dashboard=======\n\n\n";
            cout << "\n 1. Add a new Book";
            cout << "\n 2. Update any Book";
            cout << "\n 3. Delete Book";
            cout << "\n 4. List all Books";
            cout << "\n 9. Exit\n\n";
            cout << "\n\n Enter your choice: ";
            cin >> ichoice;
            system("cls");
            switch(ichoice){
            case 1 : Book::addBook(); break;
            case 2 : Book::updateBook(); break;
            case 3 : Book::deleteBook(); break;
            case 4 : Book::listAllBooks(); break;
            default : cout << "Invalid choice, Please Enter a valid one"; break;
            }
          }
        }
      }
    }
};

class Student{
  char username[10];
  char password[10];
  bool loggedIn = false;
public:
    Student(){
       while(loggedIn == false){
        system("cls");
        cout << "\n -----------Student Login----------\n\n\n";
        cout << "\nEnter your Student username:\n";
        cin >> username;
        cout << "\nEnter your Student  password:\n";
        cin >> password;
        if(strcmp(username,USER) == 0 && strcmp(password,USERPASSWORD) == 0){
            loggedIn == true;
            int ichoice = 0;
            while(ichoice != 9){
            system("cls");
            cout << "========Student Dashboard=======\n\n\n";
            cout << "\n 1. Borrow a book";
            cout << "\n 2. Return a book";
            cout << "\n 3. List all Books";
            cout << "\n 9. Exit \n\n";
            cout << "\n\n Enter your choice: ";
            cin >> ichoice;
            system("cls");
            switch(ichoice){
            case 1 : Book::borrowBook(); break;
            case 2 : Book::returnBook(); break;
            case 3 : Book::listAllBooks(); break;
            default : cout << "Invalid choice, Please Enter a valid one"; break;
            }
          }
        }
      }
    }
};

class UserActivity
{
    int choice;
    enum UserType{student, teacher}usertype;
public:
    UserActivity(){
       //while(choice != 9){
        cout << "\n Library Management System\n\n";
        cout << "\n 1. Teacher";
        cout << "\n 2. Student";
        cout << "\n 9. Exit";
        cout << "\n\n Enter your choice: ";
        cin >> choice;
       // }
        if(choice == 1)
        usertype = teacher;
        else if(choice == 2)
        usertype = student;
        else if(choice == 9)
        exit(0);
    }
    void Login(){
        system("cls");
        if(usertype == student){
            new Student();
        }else{
            new Teacher();
        }
    }
};

int main()
{
   UserActivity user = UserActivity();
   user.Login();
}
