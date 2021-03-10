
/* Name: Andrew Stade
Date: 10/24/2019
Section: 2 */

#include "book.h"

class Store
{
  public:
    Store();
    ~Store();
    
    void AddBook(const char* t, const char* a, Genre g, double p);
    int FindTitle(char* searchT);
    int FindAuthor(char* searchA);
    void Output(char* search) const;
    void Sell(int s);
    double ReturnMoney();
    void Sort();
    void GenreSum(int ge);
    void GDisplay();
    void Register(double c);
    int GetCurrentSize();

  private:
    int maxSize;
    int currentSize;
    double money;
    Book* bookInv;
    void Grow();
};