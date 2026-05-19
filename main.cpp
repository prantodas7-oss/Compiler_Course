#include <iostream>
#include <string>
using namespace std;

bool check(string s) {
    int i = 0;

    while (i < s.size() && s[i] == 'a')
        i++;


    if (i >= s.size() || s[i] != 'b')
        return false;


    while (i < s.size()) {
        if (s[i] != 'b')
            return false;
        i++;
    }

    return true;
}

int main() {
    string s[5];


    for (int i = 0; i < 5; i++) {
        cout << "Enter the " << i+1 << "th string: ";
        cin >> s[i];
    }


    cout << "\nResults:\n";
    for (int i = 0; i < 5; i++) {
        cout << "String " << i+1 << " (" << s[i] << ") : "
             << (check(s[i]) ? "Accepted the string" : "Rejected the string") << endl;
    }

    return 0;
}
