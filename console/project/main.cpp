#include "bookClass.cpp"
void mainWindow(){
    separatedLine("what do you want to do?");
    cout << "1- Enter new book\n";
    cout << "2- Buy book\n";
    cout << "3- search in a stock\n";
    cout << "4- search for a book\n";
    cout << "5- Edit book details\n";
    cout << "6- Exit\n";
}

void buyBook(){
    int n_stock, amount;
    string book_title;

    while (true){
        cout << "Enter Book title\n";
        cout << "-> ";
        cin.clear();
        cin.sync();
        getline(cin, book_title);
        n_stock = books_title_stock[book_title];
        if(!stocks[n_stock].count(book_title)){
            separatedLine("this book does not exist!");
        }else{
            break;
        }
    }

    cout << "Enter the amount\n";
    cout << "-> ";
    cin >> amount;
    stocks[n_stock][book_title].buyThisBook(amount);
}

void searchInStock(){
    int n_stock;
    cout << "Enter stock position\n";
    cout << "-> ";
    cin >> n_stock;
    for(auto& stock_book : stocks[n_stock]){
        separatedLine("");
        stock_book.second.getDetails();
    }
}

void searchForBook(){
    string book_title;
    while (true){
        cout << "Enter Book title\n";
        cout << "-> ";
        cin.clear();
        cin.sync();
        getline(cin, book_title);
        if(!books_title_stock[book_title]){
            separatedLine("this book does not exist");
        }else{
            break;
        }
    }
    int n_stock = books_title_stock[book_title];
    separatedLine("This book in the stock position: " + to_string(n_stock));
    separatedLine("Book details");
    stocks[n_stock][book_title].getDetails();
}

void editBookDetails(){
    string book_title;
    int n_stock;
    while (true){
        cout << "Enter Book title\n";
        cout << "-> ";
        cin.clear();
        cin.sync();
        getline(cin, book_title);
        if(!books_title_stock[book_title]){
            separatedLine("this book does not exist");
        }else{
            break;
        }
    }
    n_stock = books_title_stock[book_title];;
    stocks[n_stock][book_title].editDetails();
}

void runSystem(){
    mainWindow();
    int n_choice;
    cout << "-> Enter choice: ";
    cin >> n_choice;
    if(!isValidInput(n_choice,1,6)){
        runSystem();
        return;
    }
    if(n_choice == 1){
        book new_book;
        new_book.registerThisBook();
    }else if(n_choice == 2){
        buyBook();

    }else if(n_choice == 3){
        searchInStock();

    }else if(n_choice == 4){
        searchForBook();

    }else if(n_choice == 5){
        editBookDetails();
    }else{
        return;
    }
    runSystem();
}
int main() {
    loadBooks();
    runSystem();
    saveBooks();
}
