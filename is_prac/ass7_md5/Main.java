import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.nio.charset.StandardCharsets;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        String text = "Hello, World!";
        System.out.println("Original Text : " + text);

        String md5Hash = calculateMD5(text);
        System.out.println("MD5 Hash : " + md5Hash);
    }

    public static String calculateMD5(String text) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("MD5");
        byte[] hashInBytes = md.digest(text.getBytes(StandardCharsets.UTF_8));

        // bytes to hex
        String md5Hash = new BigInteger(1, hashInBytes).toString(16);
        while (md5Hash.length() < 32) {
            md5Hash = "0" + md5Hash;
        }
        return md5Hash;
    }
}

/*
    Here’s a complete explanation and theory of the **MD5 Hashing Algorithm** code you shared, along with important **viva questions and answers** to help you prepare effectively.

---

## 🧠 **Theory: MD5 Hashing Algorithm**

### 🔸 What is MD5?

**MD5** stands for **Message Digest Algorithm 5**. It is a widely used **cryptographic hash function** that produces a **128-bit (16-byte)** hash value, typically represented as a 32-digit hexadecimal number.

---

### 🔸 Key Features:

* **Deterministic**: Same input always gives the same hash.
* **Fixed Output Size**: 128 bits (32 hex characters), regardless of input size.
* **Fast and Simple**: Efficient to compute.
* **One-way Function**: It is computationally infeasible to reverse.
* **Collision Risk**: Not collision-resistant (different inputs can produce the same hash), so not suitable for security-critical use today.

---

## 🔧 **Use Cases of MD5**

* Checksums and file integrity verification
* Password hashing (not recommended anymore)
* Data fingerprinting
* Digital signatures (legacy systems)

---

## ✅ **Code Explanation (Java)**

### 📌 `String text = "Hello, World!";`

This is the input string you want to hash.

---

### 📌 `MessageDigest.getInstance("MD5")`

This initializes the **MD5 hashing algorithm** using Java's built-in `MessageDigest` class.

---

### 📌 `digest(...)`

This method processes the input bytes and returns the **hash in byte array** form.

```java
byte[] hashInBytes = md.digest(text.getBytes(StandardCharsets.UTF_8));
```

---

### 📌 Convert Byte Array to Hexadecimal

```java
String md5Hash = new BigInteger(1, hashInBytes).toString(16);
```

* Converts the hash to a hexadecimal string using `BigInteger`.
* The loop pads the result with leading zeros to ensure the length is exactly **32 hex digits**.

---

### 📌 Output Example

```
Original Text : Hello, World!
MD5 Hash : ed076287532e86365e841e92bfc50d8c
```

---

## 🎤 **Viva Questions & Answers**

---

### ❓ Q1. What is a hash function?

A **hash function** takes an input and returns a fixed-size string (hash) which appears random. It’s used for checking data integrity and for cryptographic applications.

---

### ❓ Q2. What is the output length of MD5?

MD5 produces a **128-bit hash**, usually represented as a **32-character hexadecimal string**.

---

### ❓ Q3. Is MD5 secure?

No. **MD5 is not secure** for cryptographic purposes due to known **collision attacks**. It is now considered **broken** and should be avoided in modern security systems.

---

### ❓ Q4. What are collisions in hashing?

A **collision** occurs when two different inputs produce the same hash output. Cryptographic hash functions should ideally be **collision-resistant**.

---

### ❓ Q5. What is the use of MessageDigest in Java?

`MessageDigest` is a built-in class in Java that provides **cryptographic hashing algorithms** like MD5, SHA-1, and SHA-256.

---

### ❓ Q6. Why do we pad the MD5 string with zeros?

To ensure the output hash is exactly **32 characters long**, as MD5 hashes should be uniformly represented.

---

### ❓ Q7. Is MD5 reversible?

No. MD5 is a **one-way function**. It’s not possible to reverse it to get the original message.

---

Would you like this explanation summarized into a one-page PDF for printing or revision?

*/