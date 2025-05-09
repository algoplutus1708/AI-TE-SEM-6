#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to encrypt using columnar transposition
string encrypt(string message, string key) {
    int cols = key.length();
    int rows = (message.length() + cols - 1) / cols; // Round up
    vector<vector<char>> matrix(rows, vector<char>(cols, 'X')); // Fill with 'X'

    // Fill matrix row-wise
    int k = 0;
    for (int i = 0; i < rows && k < message.length(); i++) {
        for (int j = 0; j < cols && k < message.length(); j++) {
            matrix[i][j] = message[k++];
        }
    }

    // Create key order
    string sorted_key = key;
    sort(sorted_key.begin(), sorted_key.end());

    string ciphertext = "";
    for (int i = 0; i < cols; i++) {
        int col = key.find(sorted_key[i]);
        for (int row = 0; row < rows; row++) {
            ciphertext += matrix[row][col];
        }
        key[col] = '_'; // Avoid using duplicate characters
    }
    return ciphertext;
}

// Function to decrypt the ciphertext
string decrypt(string ciphertext, string key) {
    int cols = key.length();
    int rows = (ciphertext.length() + cols - 1) / cols;
    vector<vector<char>> matrix(rows, vector<char>(cols, 'X'));

    string sorted_key = key;
    sort(sorted_key.begin(), sorted_key.end());

    int k = 0;
    for (int i = 0; i < cols; i++) {
        int col = key.find(sorted_key[i]);
        for (int row = 0; row < rows; row++) {
            if (k < ciphertext.length())
                matrix[row][col] = ciphertext[k++];
        }
        key[col] = '_'; // Avoid repeating
    }

    string decrypted = "";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            decrypted += matrix[i][j];
        }
    }

    // Remove padding 'X's if any
    while (!decrypted.empty() && decrypted.back() == 'X')
        decrypted.pop_back();

    return decrypted;
}

// Main function
int main() {
    string message, key;

    cout << "Enter message: ";
    getline(cin, message);

    cout << "Enter key (e.g., ZEBRAS): ";
    cin >> key;

    string encrypted = encrypt(message, key);
    cout << "\nEncrypted Text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}

/*
### **Explanation of the C++ Program for Transposition Cipher**

#### **Program Overview:**

The program implements the **Transposition Cipher**, a simple encryption and decryption technique where the positions of characters in the plaintext are rearranged according to a key. This program uses the **Columnar Transposition Cipher** method.

### **Key Concepts:**

1. **Encryption:**

   * The message is written into a grid (matrix) row-by-row.
   * The **columns** of the matrix are then rearranged based on the order of the characters in the **sorted key**.
   * The encrypted text is formed by reading the columns in this new order.

2. **Decryption:**

   * The process is reversed to recover the original message.
   * The encrypted message is placed back into the grid by reading the columns in the order of the key.
   * Finally, the matrix is read row-by-row to get the decrypted text.

---

### **Detailed Steps:**

#### **1. Encryption:**

* **Step 1**: First, the matrix is constructed using the input message. The characters are written into the matrix row-wise.

  * For example, for the message `"HELLO WORLD"` and key `"ZEBRAS"`, the message is arranged in a matrix with rows and columns.

* **Step 2**: After the message is arranged in the matrix, we read the columns in the order determined by sorting the key. This gives us the encrypted message.

#### **2. Decryption:**

* **Step 1**: To decrypt, the matrix is filled column-wise based on the order of the sorted key.

  * The ciphertext is inserted into the columns according to this new order.

* **Step 2**: Finally, the characters are read row-by-row to reconstruct the original message.

---

### **Code Breakdown:**

1. **Encryption Function:**

   * **Matrix Construction:** The message is split and written into a matrix of size `(rows x cols)`.
   * **Key Sorting:** The key is sorted alphabetically to get the order of columns.
   * **Reading Columns in Sorted Order:** The ciphertext is obtained by reading the matrix in the order of the sorted key.

2. **Decryption Function:**

   * **Matrix Construction:** The matrix is built similarly, but columns are filled based on the sorted key's order.
   * **Reconstructing the Message:** The characters are read row-by-row from the matrix to form the decrypted message.

---

### **Viva-Oriented Questions and Answers:**

#### **Q1: What is a transposition cipher?**

**Answer:**
A transposition cipher is a method of encryption where the positions of characters in the plaintext are rearranged according to a fixed system. It doesn't alter the characters themselves but changes their order in the message.

---

#### **Q2: Explain the columnar transposition cipher used in the program.**

**Answer:**
In the columnar transposition cipher, the plaintext is written into a grid or matrix row by row. The order of the columns is determined by a key. After writing the message into the matrix, the ciphertext is formed by reading the columns in the order specified by the sorted key.

---

#### **Q3: What is the purpose of the key in the transposition cipher?**

**Answer:**
The key determines the order in which the columns of the matrix are read during encryption and decryption. The key is sorted alphabetically to create a mapping of column positions for the ciphertext. In decryption, the reverse order is used to reconstruct the original message.

---

#### **Q4: How is the message arranged in the matrix during encryption?**

**Answer:**
The message is written into the matrix row by row, starting from the first row. If the message doesn't fit perfectly into the matrix (i.e., not enough characters to fill the last row), empty spaces are filled with a padding character, like `'X'`.

---

#### **Q5: How do we perform the actual encryption process in this program?**

**Answer:**

1. The message is placed into a matrix row by row.
2. The key is sorted alphabetically, and the columns are read in the order of the sorted key.
3. The characters are concatenated to form the ciphertext.

---

#### **Q6: What happens during decryption?**

**Answer:**

1. The ciphertext is placed into a matrix column by column according to the order derived from the sorted key.
2. The matrix is read row by row to reconstruct the original message.

---

#### **Q7: What are padding characters, and why are they used?**

**Answer:**
Padding characters (like `'X'`) are used when the message length isn't a perfect multiple of the number of columns. These extra characters are added to fill the last row of the matrix so that the columns can be properly read during encryption and decryption.

---

#### **Q8: How is the key used to determine the order of the columns?**

**Answer:**
The key is sorted alphabetically. The columns of the matrix are then read according to the order of the sorted key. For example, if the key is `"ZEBRAS"`, the sorted order would be `"ABERSZ"`, and the columns would be read in this new order.

---

#### **Q9: Why does the key need to be sorted?**

**Answer:**
The key is sorted alphabetically to assign each column a numerical order. This order is then used to determine how the columns of the matrix are read during encryption and decryption.

---

#### **Q10: What will happen if two or more characters in the key are the same?**

**Answer:**
In the case of duplicate characters in the key, the program replaces them with an underscore (`'_'`) to ensure each column has a unique position for reading. This avoids ambiguity in column ordering.

---

#### **Q11: Can the transposition cipher be considered secure?**

**Answer:**
The transposition cipher is not very secure by itself because it only rearranges the letters and doesn't alter them. It is vulnerable to frequency analysis and other cryptanalysis methods. However, when combined with other techniques, such as substitution ciphers, it can be more effective.

---

#### **Q12: What happens if the message length is not divisible by the number of columns?**

**Answer:**
If the message length is not divisible by the number of columns, the matrix is padded with extra characters (such as `'X'`) to complete the last row. These padding characters are removed during decryption.

---

#### **Q13: How is the original message recovered during decryption?**

**Answer:**
The columns are filled in the matrix using the ciphertext based on the sorted key's order. Then, the matrix is read row by row to reconstruct the original message. Padding characters added during encryption are discarded at the end.

---

### **Summary:**

The program implements the **Columnar Transposition Cipher**, where encryption involves placing the message into a matrix and reading the columns in a specific order determined by the key. Decryption reverses this process. The key plays a crucial role in determining the order of columns during both encryption and decryption. Padding characters are used if necessary to ensure that the matrix is filled correctly.

*/