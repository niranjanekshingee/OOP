#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book
{
public:
    int bookID;
    string title;
    string author;
    string genre;
    bool available;

    Book(int id, string t, string a, string g)
    {
        bookID = id;
        title = t;
        author = a;
        genre = g;
        available = true;
    }

    void display()
    {
        cout << "\nBook ID : " << bookID;
        cout << "\nTitle   : " << title;
        cout << "\nAuthor  : " << author;
        cout << "\nGenre   : " << genre;
        cout << "\nStatus  : ";

        if (available)
            cout << "Available";
        else
            cout << "Issued";

        cout << "\n--------------------------";
    }
};

int main()
{
    vector<Book> books;

    // Sample books
    books.push_back(Book(101, "Harry Potter", "J.K. Rowling", "Fantasy"));
    books.push_back(Book(102, "Atomic Habits", "James Clear", "Self-Help"));
    books.push_back(Book(103, "The Alchemist", "Paulo Coelho", "Fiction"));
    books.push_back(Book(104, "Rich Dad Poor Dad", "Robert Kiyosaki", "Finance"));
    books.push_back(Book(105, "Percy Jackson", "Rick Riordan", "Fantasy"));

    int choice;

    do
    {
        cout << "\n\n===== BOOKSTORE MANAGEMENT SYSTEM =====";
        cout << "\n1. Show All Books";
        cout << "\n2. Search Books By Genre";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Check Book Availability";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n\nALL BOOKS\n";
            for (int i = 0; i < books.size(); i++)
            {
                books[i].display();
            }
            break;
        }

        case 2:
        {
            string genreSearch;

            cout << "\nEnter Genre: ";
            cin.ignore();
            getline(cin, genreSearch);

            bool found = false;

            cout << "\nBooks in " << genreSearch << " Genre:\n";

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].genre == genreSearch)
                {
                    books[i].display();
                    found = true;
                }
            }

            if (!found)
            {
                cout << "No books found in this genre.\n";
            }

            break;
        }

        case 3:
        {
            string bookName;

            cout << "\nEnter Book Name to Issue: ";
            cin.ignore();
            getline(cin, bookName);

            bool found = false;

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].title == bookName)
                {
                    found = true;

                    if (books[i].available)
                    {
                        books[i].available = false;
                        cout << "\nBook Issued Successfully!";
                    }
                    else
                    {
                        cout << "\nBook Already Issued!";
                    }

                    break;
                }
            }

            if (!found)
            {
                cout << "\nBook Not Available!";
            }

            break;
        }

        case 4:
        {
            string bookName;

            cout << "\nEnter Book Name to Return: ";
            cin.ignore();
            getline(cin, bookName);

            bool found = false;

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].title == bookName)
                {
                    found = true;

                    if (!books[i].available)
                    {
                        books[i].available = true;
                        cout << "\nBook Returned Successfully!";
                    }
                    else
                    {
                        cout << "\nThis Book Was Not Issued!";
                    }

                    break;
                }
            }

            if (!found)
            {
                cout << "\nBook Not Found!";
            }

            break;
        }

        case 5:
        {
            string bookName;

            cout << "\nEnter Book Name: ";
            cin.ignore();
            getline(cin, bookName);

            bool found = false;

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].title == bookName)
                {
                    found = true;

                    cout << "\nBook: " << books[i].title;

                    if (books[i].available)
                        cout << "\nStatus: Available";
                    else
                        cout << "\nStatus: Issued";

                    break;
                }
            }

            if (!found)
            {
                cout << "\nBook Not Found!";
            }

            break;
        }

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}