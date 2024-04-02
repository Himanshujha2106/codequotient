#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

stack<string> undoStack;
stack<string> redoStack;

void add2stack(const string& data, stack<string>& stack) {
    stack.push(data);
}

void Undo(stack<string>& source, stack<string>& dest) {
    if (source.empty()) {
        cout << "Cannot do undo more" << endl;
        return;
    }
    dest.push(source.top());
    source.pop();
}

void Redo(stack<string>& source, stack<string>& dest) {
    if (source.empty()) {
        cout << "Cannot redo more" << endl;
        return;
    }
    dest.push(source.top());
    source.pop();
}

void insert(string& text, const string& data) {
    add2stack(text, undoStack);
    text += data + "\n";
}

void update(string& text, int index, const string& data) {
    return ;
}

void printdata(const string& text) {
    cout << text;
}

void delt(string& text, int index) {
    string updatedText;
    int lineCount = 0;
    size_t pos = 0;
    while (pos != string::npos) {
        size_t newPos = text.find("\n", pos);
        if (lineCount != index) {
            updatedText += text.substr(pos, newPos - pos) + "\n";
        }
        if (newPos == string::npos) break;
        pos = newPos + 1;
        lineCount++;
    }
    add2stack(text, undoStack);
    text = updatedText;
}

void print() {
    cout << "\n\n";
    cout << "-------------- Text Editor Menu --------------" << endl;
    cout << "1. Insert Data" << endl;
    cout << "2. Update Data" << endl;
    cout << "3. Print Data" << endl;
    cout << "4. Delete a Line" << endl;
    cout << "5. Undo" << endl;
    cout << "6. Redo" << endl;
    cout << "7. Exit" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter your Choice: ";
}

int SwitchFunctionCall(string& text) {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Enter the value to data to be Inserted!\n" << endl;
            string data;
            getline(cin >> ws, data);
            insert(text, data);
            return 1;
        }
        case 2: {
            cout << "Enter the data " << endl;
            string data;
            getline(cin >> ws, data);
            cout << "Enter the index" << endl;
            int index;
            cin >> index;
            update(text, index, data);
            return 1;
        }
        case 3: {
            printdata(text);
            return 1;
        }
        case 4: {
            cout << "Enter the index you want to delete!" << endl;
            int index;
            cin >> index;
            delt(text, index);
            return 1;
        }
        case 5: {
            Undo(undoStack, redoStack);
            return 1;
        }
        case 6: {
            Redo(redoStack, undoStack);
            return 1;
        }
        case 7: {
            cout << "Thanks for using!!!" << endl;
            return 0;
        }
        default: {
            cout << "Enter a valid number" << endl;
            return 1;
        }
    }
}

int main() {
    string text;
    cout << "Heyyy Welcome to Text Editor!!!!!!!" << endl;
    int condition = 1;
    while (condition) {
        print();
        condition = SwitchFunctionCall(text);
    }
    return 0;
}
