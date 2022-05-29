#include "bookClass.h"

void book::registerThisBook() {
    int n_stock;
    cout << "Enter stock position\n";
    cout << "-> ";
    cin >> n_stock;

    while (true){
        cout << "Enter book Title\n";
        cout << "-> ";
        cin.clear();
        cin.sync();
        getline(cin, title);
        if(books_title_stock.count(title)){
            separatedLine("This book already exist!");
        }else{
            break;
        }

    }
    cout << "Enter author name\n";
    cout << "-> ";
    cin.clear();
    cin.sync();
    getline(cin, authorName);

    cout << "Enter book price\n";
    cout << "-> ";
    cin >> price;

    cout << "Enter the amount of this book\n";
    cout << "-> ";
    cin >> amount;

    stocks[n_stock][title] = *this;
    books_title_stock[title] = n_stock;

    separatedLine("successfully, this book has been registered");
}

string book::saveDetails() {
    string tmp = title + ',' + authorName + ',' + to_string(price) + ',' + to_string(amount);
    return tmp;
}

void book::loadDetails(vector<string> tmp) {
    title = tmp[1];
    authorName = tmp[2];
    price = stoi(tmp[3]);
    amount = stoi(tmp[4]);
    stocks[stoi(tmp[0])][title] = *this;
    books_title_stock[title] = stoi(tmp[0]);
}

void book::getDetails() {
    cout << left;
    cout << setw(14) << "Book title: " << "( " <<  title << " )\n";
    cout << setw(14)<< "Author name: " << "( " << authorName << " )\n";
    cout << setw(14) << "Book price: " << "( " << price << " )\n";
    cout << setw(14) << "Book amount: " << "( " << amount << " )\n";
}

void book::buyThisBook(int& tar_amount) {
    if(tar_amount > amount){
        cout << "there are only " << amount << " books\n";
    }else{
        int final_price = tar_amount * price;
        amount -= tar_amount;
        separatedLine("Successfully buying, you bought ( " + to_string(tar_amount) + " ) with total price: ( " + to_string(tar_amount * price) + " )");
        separatedLine("now there are ( " + to_string(amount) + " ) of this book available");
    }
}

void book::editDetails() {
    int n_choice;
    separatedLine("What do you want to change");
    cout << "1- book title\n";
    cout << "2- author name\n";
    cout << "3- book price\n";
    cout << "4- book amount\n";
    while (true){
        cin >> n_choice;
        if(isValidInput(n_choice,1,4)){
            break;
        }else{
            separatedLine("Enter correct choice");
        }
    }
    if(n_choice == 1){
        string book_title;
        cout << "Enter the new Book title\n";
        cout << "-> ";
        cin.clear();
        cin.sync();
        getline(cin, book_title);
        title = book_title;
        separatedLine("Successfully, book title has been changed to: ( " + book_title + " )");
    }else if(n_choice == 2){
        string s_author;
        cout << "Enter the new author name\n";
        cout << "-> ";
        cin.clear();
        cin.sync();
        getline(cin, s_author);
        authorName = s_author;
        separatedLine("Successfully, author name has been changed to: ( " + s_author + " )");
    }else if(n_choice == 3){
        cout << "Enter book price\n";
        cout << "-> ";
        cin >> price;
        separatedLine("Successfully, book price has been changed to: ( " + to_string(price) + " )");
    }else{
        cout << "Enter the new amount\n";
        cout << "-> ";
        cin >> amount;
        separatedLine("Successfully, book amount have been changed to: ( " + to_string(amount) + " )");
    }

}