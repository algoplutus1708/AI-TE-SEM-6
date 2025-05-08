#include <bits/stdc++.h>

using namespace std;

// Convert string to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Basic chatbot function
void chatbot() {
    string userInput;

    cout << "🤖 ChatBot: Hello! Welcome to ShopEase Online Support.\n";
    cout << "🤖 ChatBot: How can I help you today?\n";
    cout << "🤖 ChatBot: (Type 'bye' to exit the chat)\n\n";

    while (true) {
        cout << "👤 You: ";
        getline(cin, userInput);

        string question = toLower(userInput);

        if (question == "bye") {
            cout << "🤖 ChatBot: Thank you for visiting! Have a great day!\n";
            break;
        } else if (question.find("order") != string::npos) {
            cout << "🤖 ChatBot: You can check your order status in the 'My Orders' section after logging in.\n";
        } else if (question.find("refund") != string::npos) {
            cout << "🤖 ChatBot: Refunds are processed within 5-7 business days after return pickup.\n";
        } else if (question.find("return") != string::npos) {
            cout << "🤖 ChatBot: You can place a return request from your order history within 10 days of delivery.\n";
        } else if (question.find("shipping") != string::npos || question.find("delivery") != string::npos) {
            cout << "🤖 ChatBot: Standard delivery takes 3-5 business days depending on your location.\n";
        } else if (question.find("help") != string::npos) {
            cout << "🤖 ChatBot: I can assist you with orders, returns, refunds, and delivery information.\n";
        } else {
            cout << "🤖 ChatBot: I'm sorry, I didn't understand that. Could you please rephrase?\n";
        }
    }
}

int main() {
    chatbot();
    return 0;
}
