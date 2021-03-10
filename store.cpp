
/* Name: Andrew Stade
Date: 10/24/2019
Section: 2 */

#include <iostream>
#include <cstring>
#include "book.h"
#include "store.h"

using namespace std;

Store::Store()
// Default Constructor
{  
    currentSize = 0;
    maxSize = 5;  
    money = 0;
    bookInv = new Book[maxSize];    
}

Store::~Store()
{
    delete [] bookInv;
}

void Store::AddBook(const char* t, const char* a, Genre g, double p)
// Takes in title, author, genre, and price and creates a new book object
{
    if (currentSize == maxSize)
    {
       Grow();
       cout << "Array being resized to " << maxSize << " allocated slots";
    }
    Book b1;
    b1.Set(t,a,g,p);
    bookInv[currentSize++] = b1; 
}

int Store::FindTitle(char* searchT)
// Finds title and returns index value of book, else returns -1
{   
    for (int i = 0; i < currentSize; i++)
    {
        if (strcmp(bookInv[i].GetTitle(), searchT) == 0)
        {
            return i; 
        } 
    }
    return -1;
} 

int Store::FindAuthor(char* searchA)
// Finds author and returns index value of book, else returns -1
{
    for (int i = 0; i < currentSize; i++) 
    {
        if (strcmp(bookInv[i].GetAuthor(), searchA) == 0)
        {
             return i;
        }
    }   
    return -1;
}

void Store::Output(char* search) const
// Displays output from the search function
{
    for (int i = 0; i < currentSize; i++)
        if (strcmp(bookInv[i].GetTitle(), search) == 0)
        {
            bookInv[i].Display();
        }  
        else if (strcmp(bookInv[i].GetAuthor(), search) == 0)
        {
            bookInv[i].Display();            
        }
}

void Store::Sell(int s)
// Removes a book, adds the money, shrinks array
{   
    double temp;

    for (int i = s; i < currentSize; i++)
    {
        temp = bookInv[i].GetPrice();
    }
    money = money + temp;
    for (int i = s+1; i < currentSize; i++)
    {
       bookInv[i-1] = bookInv[i];
    }
    currentSize--;
}

void Store::Sort()
// Extra Credit
{
    /*Book temp[maxSize];
    
    for (int i = 0; i < currentSize; i++)
    {
        for (int j = i+1; i < maxSize; j++)
        {
            if (strcmp(bookInv[i].GetTitle(),bookInv[j].GetTitle()))
            {
                temp = new Book[maxSize];
                temp[i] = bookInv[i];
                bookInv[i] = bookInv[j];
                bookInv[j] = temp[i];
            } 
            cout << "Test4" << endl;            
        }
        cout << "Test5" << endl;
    } */
}

void Store::GenreSum(int ge) 
// Displays the books for each specific genre
{
    double gcash;
    int counter = 0;
    
    for (int i = 0; i < currentSize; i++)
    {
        if (bookInv[i].GetGenre() == ge)
        {
           counter++;
           gcash = gcash + bookInv[i].GetPrice();
           bookInv[i].Display();
        }
    }
    cout << "\nTotal books in this genre = " << counter;
    cout << "\nTotal price of books in this genre = $" << gcash;
}

void Store::GDisplay()
// Display func
{ 
    for (int i = 0; i < currentSize; i++)
            bookInv[i].Display();
}

double Store::ReturnMoney()
// Returns private member data money
{
    return money;
}

void Store::Register(double c)
// Takes in input from start of program
{
    money = money + c;
}

int Store::GetCurrentSize()
// Returns the current size
{
    return currentSize;
}

void Store::Grow()
// Increases the array if needed
{
    maxSize = currentSize + 5;
    Book* newList = new Book[maxSize];
    
    for (int i = 0; i < currentSize; i++)
        newList[i] = bookInv[i];
    
    
    delete [] bookInv;
    bookInv = newList;
}


