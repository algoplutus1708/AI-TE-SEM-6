#include <iostream>
using namespace std;

int main() {
    // Original string with a newline character
    const char* str = "Hello World";

    cout << "Original String: " << str << endl;

    cout << "\nAND with 127 results:\n";
    for (int i = 0; str[i] != '\0'; i++) {
        char and_result = str[i] & 127;
        cout << "Char: '" << str[i] << "' -> AND Result: " << and_result << " (ASCII: " << (int)and_result << ")" << endl;
    }

    cout << "\nXOR with 127 results:\n";
    for (int i = 0; str[i] != '\0'; i++) {
        char xor_result = str[i] ^ 127;
        cout << "Char: '" << str[i] << "' -> XOR Result: " << xor_result << " (ASCII: " << (int)xor_result << ")" << endl;
    }

    return 0;
}


/*
Sure! Below is the **detailed explanation and viva-type theory** for the given C++ program that performs `AND` and `XOR` operations with `127` on each character of a string.

---

## ✅ **Program Purpose**

This C++ program performs **bitwise operations** (`AND` and `XOR`) on each character of a string using the number `127`, and displays the results.

---

## 🧠 **Theory**

### 🔡 **What is a String in C++?**

* A **string** in C++ can be represented as a `char` array or `char*` (character pointer).
* It holds a sequence of characters ending with the null character `'\0'`.

```cpp
const char* str = "Hello World";
```

This defines a constant pointer to a C-style string.

---

### 🔧 **Bitwise Operators Used**

#### 🔹 `&` (AND)

* Compares **each bit** of the character's ASCII value with `127` (binary `01111111`).
* **Clears the most significant (8th) bit** and keeps the lower 7 bits.
* Example:

  * `'H'` (ASCII 72) in binary = `01001000`
  * `127` = `01111111`
  * Result = `01001000` (still `'H'`)

#### 🔹 `^` (XOR)

* **Flips the bits** of the character's ASCII value where `127` has `1`s.
* Used for **simple encryption or encoding**.
* Reversible:

  * `XOR again with 127` restores original value.
* Example:

  * `'H'` (72) = `01001000`
  * `127` = `01111111`
  * Result = `00110111` (ASCII 55)

---

## 🔄 **Why Use 127?**

* `127` = `01111111` (all 7 lower bits set)
* It's the **largest 7-bit number** in binary.
* Often used in encoding schemes to ensure characters remain within **standard ASCII range (0–127)**.

---

## 🎓 **Viva Questions & Answers**

### ❓ Q1: What is the purpose of the program?

**Ans**: The program performs bitwise `AND` and `XOR` with `127` on each character of a string to observe how these operations affect character values.

---

### ❓ Q2: Why do we use `127` in bitwise operations?

**Ans**: `127` in binary is `01111111`. Using it in bitwise operations keeps characters within the 7-bit ASCII range. It also helps in simple, reversible transformations using XOR.

---

### ❓ Q3: What is the difference between `AND` and `XOR` in this context?

**Ans**:

* `AND` with 127 keeps the character within ASCII by masking out the 8th bit.
* `XOR` with 127 inverts the lower 7 bits and is reversible (used for encoding/decoding).

---

### ❓ Q4: Is XOR operation reversible? Explain.

**Ans**: Yes. XOR is reversible because:

```
A ^ B ^ B = A
```

So if you XOR a value twice with the same number, you get the original value back.

---

### ❓ Q5: What is the ASCII value of `'A'` and how does it change with XOR 127?

**Ans**:

* ASCII of `'A'` = 65
* 65 ^ 127 = 62
* Resulting character: `'>'`

---

### ❓ Q6: What will happen if you apply XOR 127 again on the result?

**Ans**: You will get the original character back due to the reversible nature of XOR.

---

### ❓ Q7: Why is the null character `'\0'` important in strings?

**Ans**: It marks the end of a C-style string. Without it, loops reading characters might continue beyond the intended end of the string and cause errors.

---

### ❓ Q8: What are practical uses of XOR encoding?

**Ans**: It is used in:

* Simple encryption algorithms.
* Data obfuscation.
* Toggle operations (e.g., flipping bits).
* Checksums in networking and storage.

---

Would you like a version of this explanation formatted as a printable PDF or presentation?

*/