#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    int val;
    cin >> val;
    for (int i =0;i<val;i++){
        string input_line;
        getline(cin, input_line);  // reading a line from stdin

        // Convert the string to a C-string to use strtok
        vector<char> cstr(input_line.c_str(), input_line.c_str() + input_line.size() + 1);

        // Using strtok to tokenize the input based on space delimiter
        char* token = strtok(cstr.data(), " ");
        while (token != nullptr) {
            cout << token << endl;  // printing each token
            token = strtok(nullptr, " ");  // getting the next token
        }

    }

    return 0;
}

