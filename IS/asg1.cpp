#include <iostream>
using namespace std;

int main() {
    const char* str = "Hello World";

    cout << "Original String: " << str << endl;

    cout << "\nAfter AND with 127:\n";
    for (int i = 0; str[i] != '\0'; ++i) {
        cout << (char)(str[i] & 127);
    }

    cout << "\n\nAfter XOR with 127:\n";
    for (int i = 0; str[i] != '\0'; ++i) {
        cout << (char)(str[i] ^ 127);
    }

    cout << endl;
    return 0;
}
