
/* Name: Andrew Stade
Date: 10/24/2019
Section: 2 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "book.h"

using namespace std; 

Book::Book()
//
{
    enum Genre{F,M,S,C};
    
    strcpy(title, " ");
    strcpy(author, " ");
    type == 'F';
    price = 0;
}

void Book::Set(const char* t, const char* a, Genre g, double p)
//
{
    strcpy(title, t);
    strcpy(author, a);
    type = g;
    price = p;
}

const char* Book::GetTitle() const
//
{
    return title;
}

const char* Book::GetAuthor() const
//
{
    return author;
}

double Book::GetPrice() const
//
{
    return price;
}

Genre Book::GetGenre() const
{
    return type;
}

void Book::Display() const
//
{
    cout.setf(ios::left);
    cout.width(35);
    cout << fixed << showpoint<< setprecision (2);
    cout << title;
    cout.width(25);
    cout << author;
    if (type == FICTION)
    {
        cout << "Fiction";
    }
    else if (type == MYSTERY)
    {
        cout << "Mystery";
    }
    else if (type == SCIFI)
    {
        cout << "Sci-Fi";
    }
    else if (type == COMPUTER)
    {
        cout << "Computer";
    }
    
    if (price >= 10.00)
    {
        cout << "\t$  " << price << endl;
    }
    else 
    {
        cout << "\t$   " << price << endl;
    }
}


