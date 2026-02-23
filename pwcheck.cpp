#include <iostream>
#include <cctype>
using namespace std;

class pwcheck {
public:
    bool check(string pw) {
        bool upper = false, lower = false, digit = false, special = false;

        for (char c : pw) {
            if (isupper(c)) upper = true;
            else if (islower(c)) lower = true;
            else if (isdigit(c)) digit = true;
            else special = true;
        }

        if (pw.length() >= 8 && upper && lower && digit && special) {
            cout << "Password is STRONG\n";
            return true;
        }
        else if (pw.length() >= 6 && upper && lower && digit || pw.length() >= 6&& lower && digit || pw.length() >= 6&& upper && digit)
            cout << "Password is MEDIUM\n";

        else
            cout << "Password is WEAK\n";

        cout << "Suggestions:\n";

        if (!upper) cout << "- Add uppercase letters\n";
        if (!lower) cout << "- Add lowercase letters\n";
        if (!digit) cout << "- Add numbers\n";
        if (!special) cout << "- Add special characters\n";
        if (pw.length() < 8) cout << "- Make password at least 8 characters long\n";

        cout << endl;
        return false;
    }
};

int main() {
    pwcheck obj;
    string password;

    do {
        cout << "Enter password: ";
        cin >> password;
    } while (!obj.check(password));

    return 0;
}