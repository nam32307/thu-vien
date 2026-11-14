#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
// Dinh Nghia Lop Person
class Person{
	protected :
		string fullName, gender, phoneNumber;
    	int birthYear;
    public :
    	Person(string name = "", string gen = "", string phone = "", int birth = 0) {
        	fullName = name;
        	gender = gen;
       		phoneNumber = phone;
        	birthYear = birth;
    }
    string getFullName(){ return fullName;}
    string getGender(){ return gender;}
	string getPhone(){ return phoneNumber;}
	int getBirth(){ return birthYear;}
	void input() {
        cout << "Nhap ho ten: ";
        getline(cin, fullName);
        cout << "Nhap gioi tinh: ";
        getline(cin, gender);
        cout << "Nhap so dien thoai: ";
        getline(cin, phoneNumber);
        cout << "Nhap nam sinh: ";
        cin >> birthYear;
        cin.ignore();
    }
};
// Dinh Nghia Lop Reader
class Reader : public Person{ 
	private :
		int readerID;
	public :
		 Reader(string name = " ", string gen = " ", string phone = " ", int birth = 0, int id = 0)
        			: Person(name, gen, phone, birth) {
       			 readerID = id;
    }
    int getRederID(){ return readerID;}
    void input() {
        cout << "Nhap ma doc gia: ";
        cin >> readerID;
        cin.ignore();
        Person::input();
    }
    void display() {
        cout << "|" << left
             << " " << setw(11) << readerID
             << "|" << " " << setw(24) << getFullName()
             << "|" << " " << setw(11) << getGender()
             << "|" << " " << setw(14) << getPhone()
             << "|" << " " << setw(9) << getBirth() << "|\n";
        cout << "+" << string(12, '-')
             << "+" << string(25, '-')
             << "+" << string(12, '-')
             << "+" << string(15, '-')
             << "+" << string(10, '-') << "+\n";
    }
    string ToString() {
        stringstream ss;
        ss << readerID << "|"<< fullName << "|"<< gender << "|"
           << phoneNumber << "|"<< birthYear;
        return ss.str();
    }
};
// Dinh Nghia Lop Book 
class Book{
	protected :
		string bookID, title, author;
    	double price;
    public :
    	Book(string id = "", string t = "", string a = "", double p = 0) {
        	bookID = id;
       	 	title = t;
        	author = a;
        	price = p;
		}
		string getBookID(){ return bookID;}
		string getTitle(){ return title;}
		string getAuthor(){ return author;}
		double getPrice(){ return price;}
		void input() {
        	cout << "Nhap ma sach: ";
       		getline(cin, bookID);
        	cout << "Nhap ten sach: ";
        	getline(cin, title);
        	cout << "Nhap tac gia: ";
        	getline(cin, author);
        	cout << "Nhap gia: ";
        	cin >> price;
        	cin.ignore();
    }
    void display() {
        stringstream ss;
        ss << (int)price << " VND";
        cout << "|" << left
             << " " << setw(11) << bookID
             << "|" << " " << setw(24) << title
             << "|" << " " << setw(19) << author
             << "|" << " " << setw(13) << ss.str();
    }
      string ToString() {
        stringstream ss;
        ss << bookID << "|"<< title << "|"<< author << "|"<< price;
        return ss.str();
    }
};
// Dinh Nghia Lop Ebook
class Ebook : public Book{
	private :
   		double fileSize;
   	public :
   		Ebook(string id = "", string t = "", string a = "", double p = 0, double fs = 0)
    	: Book(id, t, a, p) {
        	fileSize = fs;
	}
	double getFileSize(){ return fileSize;}
	void input() {
        Book::input();
        cout << "Nhap dung luong file: ";
        cin >> fileSize;
        cin.ignore();
    }
     void display() {
        Book::display();
        stringstream ss;
        ss << fileSize << " MB";
        cout << "|" << " " << setw(11) << ss.str()
             << "|" << " " << setw(9) << "EBOOK" << "|\n";
        cout << "+" << string(12, '-')
             << "+" << string(25, '-')
             << "+" << string(20, '-')
             << "+" << string(14, '-')
             << "+" << string(12, '-')
             << "+" << string(10, '-') << "+\n";
    }
	string ToString() {
        stringstream ss;
        ss << Book::ToString() << "|"<< fileSize << "|EBOOK";
        return ss.str();
    }
};
// Dinh Nghia Lop PrintedBook
class PrintedBook : public Book{
	private :
		int pageCount;
	public :
		PrintedBook(string id = "", string t = "", string a = "", double p = 0, int pc = 0)
        : Book(id, t, a, p) {
        	pageCount = pc;
    }
    int getPageCount(){ return pageCount;}
    void input() {
        Book::input();
        cout << "Nhap so trang: ";
        cin >> pageCount;
        cin.ignore();
    }
    void display() {
        Book::display();
        stringstream ss;
        ss << pageCount << " tr";
        cout << "|" << " " << setw(11) << ss.str()
             << "|" << " " << setw(9) << "PRINTED" << "|\n";
        cout << "+" << string(12, '-')
             << "+" << string(25, '-')
             << "+" << string(20, '-')
             << "+" << string(14, '-')
             << "+" << string(12, '-')
             << "+" << string(10, '-') << "+\n";
    }
    string ToString() {
        stringstream ss;
        ss << Book::ToString() << "|"<< pageCount << "|PRINTED";
        return ss.str();
    }
};
// Dinh Nghia Lop BorrowTicket
class BorrowTicket{
	private:
    	string ticketID, readerID, bookID;
    	string borrowDate, dueDate, returnDate;
    public :
    	BorrowTicket(string tid = "", string rid = "", string bid = "",
						string bd = "", string dd = "", string rd = "") {
        	ticketID = tid;
        	readerID = rid;
        	bookID = bid;
        	borrowDate = bd;
        	dueDate = dd;
        	returnDate = rd;
    }
    string getBorrowDate(){ return borrowDate;}
    string getDueDate(){ return dueDate;}
    string getReturnDate(){ return returnDate;}
    void input() {
        cout << "Nhap ma phieu: ";
        getline(cin, ticketID);
        cout << "Nhap ma doc gia: ";
        getline(cin, readerID);
        cout << "Nhap ma sach: ";
        getline(cin, bookID);
        cout << "Nhap ngay muon : ";
        getline(cin, borrowDate);
        cout << "Nhap han tra : ";
        getline(cin, dueDate);
        cout << "Nhap ngay tra : ";
        getline(cin, returnDate);
    }
    int getDay(string date) {
        stringstream ss(date);
        string temp;
        getline(ss, temp, '/');
        int day;
        stringstream(temp) >> day;
        return day;
    }
     int calculateFine() {
        int due = getDay(dueDate);
        int ret = getDay(returnDate);
        if (ret > due) {
            return (ret - due) * 5000;}
        return 0;
    }
    void display() {
        stringstream ss;
        ss << calculateFine() << " VND";
        cout << "|" << left
             << " " << setw(11) << ticketID
             << "|" << " " << setw(11) << readerID
             << "|" << " " << setw(11) << bookID
             << "|" << " " << setw(15) << borrowDate
             << "|" << " " << setw(15) << dueDate
             << "|" << " " << setw(15) << returnDate
             << "|" << " " << setw(13) << ss.str() << "|\n";
        cout << "+" << string(12, '-')
             << "+" << string(12, '-')
             << "+" << string(12, '-')
             << "+" << string(16, '-')
             << "+" << string(16, '-')
             << "+" << string(16, '-')
             << "+" << string(14, '-') << "+\n";
    }
};
//Ham tao tep chua ton tai
void createFile() {
    ofstream f1("reader.txt", ios::app);
    ofstream f2("book.txt", ios::app);
    f1.close();
    f2.close();
}
// Ham Doc Tep
void loadReaders(Reader readers[], int &count) {
    ifstream file("reader.txt");
    string line;
    count = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, gen, phone, birthStr;
        getline(ss, idStr, '|');
        getline(ss, name, '|');
        getline(ss, gen, '|');
        getline(ss, phone, '|');
        getline(ss, birthStr);
        int id, birth;
        stringstream(idStr) >> id;
        stringstream(birthStr) >> birth;
        readers[count]=Reader(name, gen, phone, birth, id);
        count++;
    }
    file.close();
}
void loadBooks(PrintedBook pBooks[], int &pCount,
               Ebook eBooks[], int &eCount) {
    ifstream file("book.txt");
    string line;
    pCount = 0;
    eCount = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, title, author, priceStr, specStr, type;
        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, priceStr, '|');
        getline(ss, specStr, '|');
        getline(ss, type);
        double price;
        stringstream(priceStr) >> price;
        if (type == "PRINTED") {
            int pages;
            stringstream(specStr) >> pages;
            pBooks[pCount]=PrintedBook(id, title, author, price, pages);
            pCount++;
        }
        else if (type == "EBOOK") {
            double size;
            stringstream(specStr) >> size;
            eBooks[eCount]=Ebook(id, title, author, price, size);
            eCount++;
        }
    }
    file.close();
}
// Ham Luu Tep
void saveReaders(Reader readers[], int count) {
    ofstream file("reader.txt");
    for (int i = 0; i < count; i++) {
        file << readers[i].ToString() << endl;
    }
    file.close();
}
void saveBooks(PrintedBook pBooks[], int pCount,Ebook eBooks[], int eCount) {
    ofstream file("book.txt");
    for (int i = 0; i < pCount; i++) {
        file << pBooks[i].ToString() << endl;}
    for (int i = 0; i < eCount; i++) {
        file << eBooks[i].ToString() << endl;}
    file.close();
}
// Ham MeNu
void showMenu() {
    cout << "\n+------------------------------------+\n";
    cout << "|         QUAN LY THU VIEN           |\n";
    cout << "+------------------------------------+\n";
    cout << "|  1. Them doc gia                   |\n";
    cout << "|  2. Them sach in                   |\n";
    cout << "|  3. Them ebook                     |\n";
    cout << "|  4. Tao phieu muon                 |\n";
    cout << "|  5. Hien thi doc gia               |\n";
    cout << "|  6. Hien thi sach                  |\n";
    cout << "|  7. Hien thi phieu muon            |\n";
    cout << "|  0. Thoat va luu                   |\n";
    cout << "+------------------------------------+\n";
    cout << "Chon chuc nang: ";
}
// Ham chinh chon chuc nang trong menu
int main() {
    createFile();
    Reader readers[100];
    PrintedBook printedBooks[100];
    Ebook ebooks[100];
    BorrowTicket tickets[100];
    int readerCount = 0;
    int printedCount = 0;
    int ebookCount = 0;
    int ticketCount = 0;
    int choice;
    loadReaders(readers, readerCount);
    loadBooks(printedBooks, printedCount, ebooks, ebookCount);
    do {
        showMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            readers[readerCount++].input();
            break;
        case 2:
            printedBooks[printedCount++].input();
            break;
        case 3:
            ebooks[ebookCount++].input();
            break;
        case 4:
            tickets[ticketCount++].input();
            break;
        case 5:
            cout << "\n===== DANH SACH DOC GIA =====\n";
            cout << "+" << string(12, '-')
                 << "+" << string(25, '-')
                 << "+" << string(12, '-')
                 << "+" << string(15, '-')
                 << "+" << string(10, '-') << "+\n";
            cout << "|" << left << setw(12) << " Ma DG"
                 << "|" << setw(25) << " Ho ten"
                 << "|" << setw(12) << " Gioi tinh"
                 << "|" << setw(15) << " SDT"
                 << "|" << setw(10) << " Nam sinh" << "|\n";
            cout << "+" << string(12, '-')
                 << "+" << string(25, '-')
                 << "+" << string(12, '-')
                 << "+" << string(15, '-')
                 << "+" << string(10, '-') << "+\n";
            for (int i = 0; i < readerCount; i++) {
                readers[i].display();
            }
            break;
        case 6:
            cout << "\n========== DANH SACH SACH ==========\n";
            cout << "+" << string(12, '-')
                 << "+" << string(25, '-')
                 << "+" << string(20, '-')
                 << "+" << string(14, '-')
                 << "+" << string(12, '-')
                 << "+" << string(10, '-') << "+\n";
            cout << "|" << left << setw(12) << " Ma sach"
                 << "|" << setw(25) << " Ten sach"
                 << "|" << setw(20) << " Tac gia"
                 << "|" << setw(14) << " Gia"
                 << "|" << setw(12) << " Thong tin"
                 << "|" << setw(10) << " Loai" << "|\n";
            cout << "+" << string(12, '-')
                 << "+" << string(25, '-')
                 << "+" << string(20, '-')
                 << "+" << string(14, '-')
                 << "+" << string(12, '-')
                 << "+" << string(10, '-') << "+\n";
            for (int i = 0; i < printedCount; i++) {
                printedBooks[i].display();
            }
            for (int i = 0; i < ebookCount; i++) {
                ebooks[i].display();
            }
            break;
        case 7:
			cout << "\n============ DANH SACH PHIEU MUON ============\n";
			cout << "+" << string(12, '-')
    			 << "+" << string(12, '-')
    			 << "+" << string(12, '-')
    			 << "+" << string(16, '-')
    			 << "+" << string(16, '-')
    			 << "+" << string(16, '-')
    			 << "+" << string(14, '-') << "+\n";
			cout << "|" << left << setw(12) << " Ma phieu"
    			 << "|" << setw(12) << " Ma DG"
    			 << "|" << setw(12) << " Ma sach"
    			 << "|" << setw(16) << " Ngay muon"
    			 << "|" << setw(16) << " Han tra"
    			 << "|" << setw(16) << " Ngay tra"
    			 << "|" << setw(14) << " Tien phat" << "|\n";
			cout << "+" << string(12, '-')
    			 << "+" << string(12, '-')
    			 << "+" << string(12, '-')
    			 << "+" << string(16, '-')
    			 << "+" << string(16, '-')
    			 << "+" << string(16, '-')
    			 << "+" << string(14, '-') << "+\n";
            for (int i = 0; i < ticketCount; i++) {
                tickets[i].display();}
            break;
        case 0:
            saveReaders(readers, readerCount);
            saveBooks(printedBooks, printedCount, ebooks, ebookCount);
            cout << "Da luu file va thoat.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
    return 0;
}





















