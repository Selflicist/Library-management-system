#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book {
  string title;
  string ISSN;
  string publisher;
  float cost;
};

void input(int a){
	ofstream libraryFile("library.txt", ios::app);
	Book newBook;
        cout << "Enter book title: ";
        cin >> newBook.title;
        cout << "Enter book ISSN: ";
        cin >> newBook.ISSN;
        cout << "Enter book publisher: ";
        cin >> newBook.publisher;
        cout << "Enter book cost: ";
        cin >> newBook.cost;
        // Write new book to file
        libraryFile << newBook.title << "," << newBook.ISSN << "," << newBook.publisher << "," << newBook.cost << endl;
        libraryFile.close();
        
        cout<<"\nBook successfully saved!\n\n";
}


void output(int a){
	        string title;
        cout << "Enter book title: ";
        cin >> title;
        bool found = false;
        ifstream libraryFile("library.txt");
        string line;
        while (getline(libraryFile, line)) {
          int pos = line.find(",");
          string fileTitle = line.substr(0, pos);
          if (fileTitle == title) {
            cout << line << endl<<"\nBook successfully retrieve!\n"<<endl;
            found = true;
                    
        if (!found) {
          cout << "Book not found." << endl;
        }
        break;
}
}
}

	void issue(int a){
		    string title;
        cout << "Enter book title: ";
        cin >> title;
        bool found = false;
        ifstream libraryFile("library.txt");
        ofstream tempFile("temp.txt");
        string line;
        while (getline(libraryFile, line)) {
          int pos = line.find(",");
          string fileTitle = line.substr(0, pos);
          if (fileTitle == title) {
            found = true;
            // check if student has returned last book
            // code to check student record goes here
            cout << "Book issued to student." << endl;
          } else {
            tempFile << line << endl;
          }
        }
        libraryFile.close();
        tempFile.close();
        remove("library.txt");
        rename("temp.txt", "library.txt");
        if (!found) {
          cout << "\n\tBook already issued.\n" << endl;
}
	}
	
	void display(int a){
		string all;
		
		ifstream readall("library.txt");
		cout<<endl;
		while(getline(readall,all)){
			cout<<endl<<all<<endl;
		}
		cout<<endl<<endl;
	}

	int main() 
{
  // Open file to store library records
  
  // Menu loop
  while (true) {
    cout << "Library Book Records" << endl;
    cout << "1. Enter new book" << endl;
    cout << "2. Retrieve book details" << endl;
    cout << "3. Issue book to student" << endl;
    cout << "4. All Books" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
      case 1: {
        // Enter new book
        input(choice);
        break;
      }
  
      case 2: {
        // Retrieve book details
		output(choice);
            break;
          }
        

      
      case 3: {
        // Issue book to student
		issue(choice);
break;
}
case 4: {
// Exit
	display(choice);
	break;
}
case 5: {
	
	return 0;
	
}
default: {
cout << "Invalid choice. Try again." << endl;
break;
}

}

}
return 0;
}