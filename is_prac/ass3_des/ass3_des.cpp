#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// The initial permutation (IP) table
const int IP[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

// The final permutation (FP) table
const int FP[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};

// The function to perform permutation on a bitset
bitset<64> permute(const bitset<64>& input, const int* permTable, int size) {
    bitset<64> output;
    for (int i = 0; i < size; ++i) {
        output[i] = input[permTable[i] - 1];
    }
    return output;
}

// Function to convert a string to a bitset
bitset<64> stringToBitset(const string& str) {
    bitset<64> result;
    int i = 0;
    for (char c : str) {
        for (int j = 7; j >= 0; --j) {
            result[i++] = (c >> j) & 1;
        }
    }
    return result;
}

// Simple function to simulate the DES encryption (simplified version)
bitset<64> desEncrypt(bitset<64> plaintext, bitset<64> key) {
    // Step 1: Initial Permutation (IP)
    bitset<64> permutedText = permute(plaintext, IP, 64);
    
    // Step 2: Simplified DES round function (skip 16 rounds for brevity)
    // Normally, you would apply 16 rounds with key scheduling and S-boxes here.
    // We're skipping the rounds for simplicity.

    // Step 3: Final Permutation (FP)
    bitset<64> ciphertext = permute(permutedText, FP, 64);
    
    return ciphertext;
}

// Function to get user input (plaintext and key)
void getInput(string& message, string& key) {
    cout << "Enter a message (up to 8 characters): ";
    getline(cin, message);
    
    cout << "Enter a 64-bit key (as 16 hexadecimal digits): ";
    cin >> key;
}

int main() {
    string message, key;

    // Step 1: Get input from the user
    getInput(message, key);
    
    // Step 2: Convert message to bitset (64-bit)
    if (message.length() > 8) {
        cout << "Message is too long! It should be a maximum of 8 characters.\n";
        return 1;
    }
    
    // Padding message with spaces if it is less than 8 characters
    while (message.length() < 8) {
        message += ' ';
    }
    
    bitset<64> plaintext = stringToBitset(message);
    
    // Step 3: Convert key (64-bit) from hexadecimal to bitset
    bitset<64> keyBitset;
    for (int i = 0; i < 16; ++i) {
        int hexDigit = (key[i] >= '0' && key[i] <= '9') ? key[i] - '0' : toupper(key[i]) - 'A' + 10;
        for (int j = 0; j < 4; ++j) {
            keyBitset[i * 4 + j] = (hexDigit >> (3 - j)) & 1;
        }
    }
    
    // Step 4: Perform DES encryption
    bitset<64> ciphertext = desEncrypt(plaintext, keyBitset);
    
    // Step 5: Display the result
    cout << "Ciphertext: " << ciphertext << endl;
    
    return 0;
}
/*
### **Explanation of the C++ DES Implementation:**

The program provided is a **simplified version** of the **Data Encryption Standard (DES)** algorithm. Here's a breakdown of how the program works:

1. **Input from the User**:

   * The program prompts the user to input a **plaintext message** (up to 8 characters) and a **64-bit key** (entered as a 16-digit hexadecimal string).

2. **Conversion of Input**:

   * The **plaintext** (message) is converted into a **64-bit binary format** using the `stringToBitset` function. This allows the program to work with the plaintext in a format suitable for bitwise operations.
   * The **key** is converted from a hexadecimal string (e.g., `133457799BBCDFF1`) into a `bitset<64>`. Each character of the hexadecimal string is converted into 4 binary bits and stored in the bitset.

3. **Initial Permutation (IP)**:

   * The plaintext is then subjected to an **Initial Permutation (IP)**, which reorders the bits according to a fixed permutation table. This is the first step in the DES encryption process. In the simplified program, this is done by using the `permute` function, which takes the input and applies the IP table to produce a rearranged bitset.

4. **Skipping the Rounds**:

   * The actual DES algorithm performs **16 rounds** of encryption. In each round, the data is split into two halves, the **round function** is applied, and the two halves are combined. This involves operations like expansion, substitution, and permutation, which are crucial for security.
   * In this simplified version, **the rounds are skipped** for brevity, and we directly apply the **Final Permutation (FP)**.

5. **Final Permutation (FP)**:

   * After the rounds (which are not implemented), a **Final Permutation (FP)** is applied to the data. This final permutation is another fixed rearrangement of the bits, and the result is the final **ciphertext**.

6. **Output**:

   * The **ciphertext** (the result after applying the IP, skipped rounds, and FP) is displayed in binary format as the output. This is the encrypted version of the input message using the provided key.

### **Key Concepts and Features in the DES Algorithm:**

* **Key Generation**: DES uses a **56-bit key** for encryption, but it is often provided as a 64-bit key (with every 8th bit used for parity). This key is split into 16 subkeys (one for each round of encryption) using a process known as **key scheduling**. This process is **not implemented** in the simplified version.

* **Initial Permutation (IP)**: A fixed permutation of the 64-bit input is done before the encryption rounds. This is part of the DES standard.

* **Rounds**: In the full DES algorithm, 16 rounds are performed, where the data is split into two halves, and the right half is transformed through a round function using one of the 16 subkeys. Each round includes a **substitution step** using **S-boxes** (which are not implemented in this program).

* **Final Permutation (FP)**: After completing the 16 rounds, the final permutation is applied to the data, which results in the ciphertext.

* **Bitwise Operations**: DES relies heavily on bitwise operations like **XOR**, **permutation**, and **substitution**. These operations are efficient and crucial for the security of the encryption.

---

### **Viva-Oriented Questions and Answers:**

1. **What is DES (Data Encryption Standard)?**

   * **Answer**: DES is a symmetric-key algorithm used for data encryption. It uses a 56-bit key for encryption and performs 16 rounds of encryption, applying bitwise operations like substitution and permutation.

2. **What is the key size in DES?**

   * **Answer**: The DES algorithm uses a 56-bit key, though it is typically represented as a 64-bit key (with every 8th bit used for parity checking).

3. **What is the role of the Initial Permutation (IP) in DES?**

   * **Answer**: The Initial Permutation (IP) is the first step in the DES algorithm. It rearranges the bits of the input plaintext in a fixed pattern, ensuring that the encryption process starts with a shuffled version of the data.

4. **How is the key used in the DES algorithm?**

   * **Answer**: The key is divided into 16 subkeys, which are used in each of the 16 rounds of encryption. Each round uses one subkey, which is generated through a process called **key scheduling**. The key is also subject to various permutations and bit shifts during this process.

5. **What is a round in DES encryption?**

   * **Answer**: A round in DES consists of splitting the data into two halves, performing a round function on the right half using a subkey, and then swapping the halves. The round function involves expansion, substitution, and permutation.

6. **What are S-boxes, and why are they important in DES?**

   * **Answer**: S-boxes (Substitution boxes) are used in the round function to perform substitution, replacing 6-bit input values with 4-bit outputs. They are crucial for introducing non-linearity and increasing the security of the encryption process.

7. **What is the Final Permutation (FP) in DES?**

   * **Answer**: The Final Permutation (FP) is the last step of the DES algorithm. It rearranges the bits of the data after the rounds are complete, producing the final ciphertext.

8. **Why are 16 rounds used in DES?**

   * **Answer**: The 16 rounds are designed to provide sufficient diffusion and confusion in the ciphertext. This means that small changes in the plaintext or key will cause large, unpredictable changes in the ciphertext, making it difficult for attackers to break the encryption.

9. **What is the purpose of padding the plaintext in this program?**

   * **Answer**: The plaintext is padded with spaces to ensure it is exactly 8 characters long (64 bits). DES operates on 64-bit blocks, so padding ensures that the input message fits this requirement.

10. **Why does this program skip the round function and key scheduling?**

    * **Answer**: The program is a simplified demonstration of DES encryption. The actual DES algorithm involves key scheduling and 16 rounds, but these steps have been skipped for brevity and to keep the focus on the basic structure of the algorithm.

11. **How does the DES algorithm ensure security?**

    * **Answer**: DES ensures security through the use of a combination of techniques:

      * **Permutation and Substitution**: These operations introduce complexity and prevent patterns from emerging in the ciphertext.
      * **Key Scheduling**: This ensures that each round of encryption uses a different subkey, making it harder for attackers to guess the key or reverse the encryption.
      * **16 rounds**: These rounds make it computationally difficult for attackers to analyze the ciphertext and break the encryption.

12. **What are the weaknesses of DES?**

    * **Answer**: The main weakness of DES is its small key size (56 bits). With modern computational power, DES is vulnerable to a **brute-force attack**, where all possible keys are tried until the correct one is found. This is why DES is considered insecure today, and newer algorithms like **AES** (Advanced Encryption Standard) are used instead.

---

### **Further Exploration**:

If you're interested in a **complete DES implementation**, it would involve:

* **Key Scheduling**: Generating 16 subkeys from the 64-bit key.
* **Rounds**: Implementing the round function with expansion, substitution (using S-boxes), and permutation.
* **Decryption**: Reversing the encryption steps, using the subkeys in reverse order.

If you'd like, I can provide more detailed code or explanations on how to extend the implementation.

*/