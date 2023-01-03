#include <string>
#include <map>

using namespace std;

struct Book
{
    string title;
    string isbn;
};

struct Price
{
    double amount;
};

auto cmp = [](const Book &a, const Book &b)
{
    return a.isbn > b.isbn;
};

template <typename VALUE>
using MapBookSortedByIsbn = map<Book, VALUE, decltype(cmp)>;
// using MapBookSortedByIsbn = map<Book, VALUE, decltype([](const Book &a, const Book &b)
//                                                       { return a.isbn > b.isbn; };)>;

const Book effectiveCPP{"Effective C++", "978-3-16-148410-0"};
const Book fpCPP{"Functional Programming in C++", "978-3-20-148410-0"};