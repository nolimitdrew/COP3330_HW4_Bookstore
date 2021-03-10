
/* Name: Andrew Stade
Date: 10/24/2019
Section: 2 */

#include <iostream>
#include <iomanip>
#include "store.h"

using namespace std;


void MainMenu() // Main menu function
{
    cout << "\n\t " << "\t*** BOOK STORE MENU *** \n" ;
    cout << "\tA" << "\tAdd a Book to Inventory\n" ;
    cout << "\tF" << "\tFind a book from Inventory\n" ;  
    cout << "\tS" << "\tSell a book\n" ;
    cout << "\tD" << "\tDisplay the inventory list\n" ;
    cout << "\tG" << "\tGenre summary\n" ;
    cout << "\tO" << "\tSort inventory list\n" ;
    cout << "\tM" << "\tShow this Menu\n" ;
    cout << "\tX" << "\teXit Program" ;
}

int main()
{
    Store s;
    char choice;
    double cash;
    int numbooks = 0;
 
    cout << "*** Welcome to Bookstore Inventory Manager ***\n" ;
    cout << "Please input the starting money in the cash register: " ;
    cin >> cash;
    s.Register(cash);
    
    
    cout << "\n\n";
    MainMenu();
    
    
    do
    {
        cout << "\n> ";
        cin >> choice;
        
        if (choice == 'A' || choice == 'a') // Add book
        {
            char authorArr[21];
            char titleArr[31];
            char gen;
            char check1;
            double bookprice;
            Genre type;
            
            
            cout << "Enter title: ";
            cin.ignore();
            cin.getline(titleArr,31);
            cout << "Enter author: ";
            cin.getline(authorArr,21);
            do
            {
            cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
            cin >> gen;
                if (gen == 'F' || gen == 'f')
                {
                    type = FICTION;
                }
                else if (gen == 'M' || gen == 'm')
                {
                    type = MYSTERY;
                }
                else if (gen == 'S' || gen == 's')
                {
                    type = SCIFI;
                }
                else if (gen == 'C' || gen == 'c')
                {
                    type = COMPUTER;
                }
                else
                {
                cout << "\nInvalid Genre entry. Please re-enter" << endl;
                }      
            check1 = gen;
            } while (check1 != 'F' && check1 != 'f' && check1 != 'M' && check1 != 'm' && check1 != 'S' && check1 != 's' && check1 != 'C' && check1 != 'c');         
            do
            {
                cout << "Enter price: ";
                cin >> bookprice;
                if (bookprice <= 0)
                {
                cout << "Must enter a positive price. Please re-enter" << endl;
                }
                else
                {}
            } while (bookprice <= 0);
            s.AddBook(titleArr, authorArr, type, bookprice);
            numbooks = numbooks + 1;
        }
        else if (choice == 'F' || choice == 'f') // Find book
        {
            char Search[31];
            int result;
            int result2;
            
            cout << "Enter search string (title or author): ";
            cin.ignore();
            cin.getline(Search,31);

            result = s.FindTitle(Search);
            if (result != -1)
            {
                cout << "\nBook Found:\n";
                s.Output(Search);
            }            
            else
            {
                result2 = s.FindAuthor(Search);
                if (result2 != -1)
                {
                    cout << "\nBook Found:\n";
                    s.Output(Search);
                }    
                else
                {
                    cout << Search << ": Not Found\n";  
                }                
            }
        }
        else if (choice == 'S' || choice == 's') // Sell book
        {
            char Sell[31];
            int answer;
            
            cout << "Enter title to sell: ";
            cin.ignore();
            cin.getline(Sell,31);
            
            answer = s.FindTitle(Sell);
            if (answer != -1)
            {
                s.Sell(answer);
                
                numbooks = numbooks - 1;
                cout << "\nSale complete!" << endl;
            }
            else
            {
                cout << "\n";
                cout << Sell << " not found in the inventory" ;
                cout << "\n* No sale made *" ;
            }
        }
        else if (choice == 'D' || choice == 'd') // Display book(s)
        {
            if (s.GetCurrentSize() > 0)
            {
                cout.setf(ios::left);
                cout.width(35);
                cout << fixed << showpoint<< setprecision (2);
                cout << "\n**Title**";
                cout.width(25);
                cout << "**Author**";
                cout << "**Genre**    ";
                cout << "**Price**\n";
                s.GDisplay();
                
                cout << "\nNumber of books = " << numbooks;
                cout << "\nMoney in register = $ ";
                cout << fixed << showpoint<< setprecision (2);
                cout << s.ReturnMoney();
                cout << "\n";
                
            }
            else 
            {
                cout << "\nNo books currently in inventory\n";
                cout << "\nNumber of books = 0";
                cout << "\nMoney in register = $ ";
                cout << fixed << showpoint<< setprecision (2);
                cout << s.ReturnMoney();
                cout << "\n";
                
            }
        }
        else if (choice == 'G' || choice == 'g') // Display genre(s)
        {
            int temp;
            char input;
            char check2;
            Genre type;
            
            do
            {
            cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
            cin >> input;
                if (input == 'F' || input == 'f')
                {
                    temp = 0;
                    s.GenreSum(temp);
                }
                else if (input == 'M' || input == 'm')
                {
                    temp = 1;
                    s.GenreSum(temp);
                }
                else if (input == 'S' || input == 's')
                {
                    temp = 2;
                    s.GenreSum(temp);
                }
                else if (input == 'C' || input == 'c')
                {
                    temp = 3;
                    s.GenreSum(temp);
                }
                else
                {
                cout << "\nInvalid Genre entry. Please re-enter" << endl;
                }      
            check2 = input;
            } while (check2 != 'F' && check2 != 'f' && check2 != 'M' && check2 != 'm' && check2 != 'S' && check2 != 's' && check2 != 'C' && check2 != 'c');       
        }
        else if (choice == 'O' || choice == 'o') // Extra Credit
        {
            
            cout << "Sort by (T)itle or (A)uthor? > ";
            s.Sort();
            
            cout << "Sort complete"; 
            
        }
        else if (choice == 'M' || choice == 'm') // Main Menu
        {
            MainMenu();
        }
        else if (choice != 'X' && choice != 'x') // Exit Program
        {
            cout << "Invalid menu choice. Try again.";
        }
    } while (choice != 'X' && choice != 'x');
    
    cout << "\nGoodbye!" << endl;

    return 0;
}