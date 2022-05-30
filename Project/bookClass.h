#ifndef BOOK_SYSTEM_BOOKCLASS_H
#define BOOK_SYSTEM_BOOKCLASS_H
#include <bits/stdc++.h>
using namespace std;

void separatedLine(string paragraph){
    int screen_width = 206;
    if(paragraph.size()){
        paragraph = ' ' + paragraph + ' ';
    }
    int part_width = screen_width/2 - paragraph.size()/2;
    cout << string(part_width,'-') << paragraph <<string(part_width,'-') << '\n';
}

bool isValidInput(int& input, int start, int end){
    if(input >= start && input <= end){
        return true;
    }
    cout << "Enter correct choice!\n";
    return false;
}

class book{
    string title, authorName;
    int price, amount;
public:
    void registerThisBook();
    void loadDetails(vector<string>tmp);
    string saveDetails();
    void getDetails();
    void buyThisBook(int& tar_amount);
    void editDetails();
};

map<string,int>books_title_stock;
map<int,map<string,book>>stocks;

void saveBooks(){
    fstream file;
    file.open("database.txt");
    for(auto& stock : stocks){
        for(auto& stock_book : stock.second){
            file << stock.first << ',' << stock_book.second.saveDetails() << '\n';
        }
    }
    file.close();
}

void loadBooks(){
    fstream file;
    file.open("database.txt");
    string line;
    vector<string>book_file_details;
    while (getline(file, line)){
        book_file_details.clear();
        istringstream all(line);
        string tmp;
        while (getline(all,tmp,',')){
            book_file_details.push_back(tmp);
        }
        book newBook;
        newBook.loadDetails(book_file_details);
    }
}
#endif //BOOK_SYSTEM_BOOKCLASS_H
