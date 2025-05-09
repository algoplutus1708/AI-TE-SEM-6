 import javax.crypto.Cipher;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.util.Base64;

public class Main {
    public static void main(String[] args) throws Exception {
        KeyPair keyPair = generateKeyPair();
        PublicKey publicKey = keyPair.getPublic();
        PrivateKey privateKey = keyPair.getPrivate();

        String plainText = "Hello, World!";
        System.out.println("Plain Text : " + plainText);

        String encryptedText = encrypt(publicKey, plainText);
        System.out.println("Encrypted Text : " + encryptedText);

        String decryptedText = decrypt(privateKey, encryptedText);
        System.out.println("Decrypted Text : " + decryptedText);
    }

    public static KeyPair generateKeyPair() throws Exception {
        KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA");
        generator.initialize(2048);
        return generator.generateKeyPair();
    }

    public static String encrypt(PublicKey key, String message) throws Exception {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, key);
        return Base64.getEncoder().encodeToString(cipher.doFinal(message.getBytes("UTF-8")));
    }

    public static String decrypt(PrivateKey key, String encrypted) throws Exception {
        byte[] bytes = Base64.getDecoder().decode(encrypted);
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.DECRYPT_MODE, key);
        return new String(cipher.doFinal(bytes), "UTF-8");
    }
}

/*
Here’s a complete **theory and code explanation** of your Java program that performs **RSA encryption and decryption** — useful for understanding, documentation, and viva preparation.

---

## 🔐 **Theory: RSA Encryption and Decryption**

### 🔸 What is RSA?

**RSA (Rivest–Shamir–Adleman)** is an **asymmetric cryptographic algorithm** used for secure data transmission. It uses two different but mathematically related keys:

* **Public Key**: Used to encrypt the message.
* **Private Key**: Used to decrypt the message.

### 🔸 Key Features:

* **Asymmetric**: Unlike AES (symmetric), RSA uses a pair of keys.
* **Key Size**: Commonly 1024, 2048, or 4096 bits. Higher key sizes = better security.
* **Secure for small data**: Typically used to encrypt small pieces of data like passwords or keys, not large files.

---

## 🧠 **RSA Encryption Workflow**

1. **Key Generation**:

   * A pair of keys (public and private) is generated.
2. **Encryption**:

   * Plain text is encrypted using the **public key**.
3. **Decryption**:

   * Cipher text is decrypted using the **private key**.

This ensures **confidentiality**, since only the private key holder can decrypt the message.

---

## ✅ **Code Explanation**

Here's a breakdown of your Java code and what each part does.

### 📌 1. **Key Generation**

```java
KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA");
generator.initialize(2048);
return generator.generateKeyPair();
```

* `KeyPairGenerator`: Java class that generates public-private key pairs.
* `initialize(2048)`: Sets the key size to 2048 bits.
* `generateKeyPair()`: Generates the RSA key pair.

---

### 📌 2. **Main Method**

```java
KeyPair keyPair = generateKeyPair();
PublicKey publicKey = keyPair.getPublic();
PrivateKey privateKey = keyPair.getPrivate();
```

* Generates keys and separates the public and private key.

```java
String plainText = "Hello, World!";
```

* The original message to be encrypted.

```java
String encryptedText = encrypt(publicKey, plainText);
String decryptedText = decrypt(privateKey, encryptedText);
```

* Message is encrypted using the public key.
* Message is decrypted using the private key.

---

### 📌 3. **Encryption Function**

```java
public static String encrypt(PublicKey key, String message) throws Exception {
    Cipher cipher = Cipher.getInstance("RSA");
    cipher.init(Cipher.ENCRYPT_MODE, key);
    return Base64.getEncoder().encodeToString(cipher.doFinal(message.getBytes("UTF-8")));
}
```

* `Cipher.getInstance("RSA")`: Initializes RSA cipher.
* `ENCRYPT_MODE`: Sets mode to encryption.
* `cipher.doFinal(...)`: Encrypts the message.
* `Base64`: Encodes binary data into string format for display.

---

### 📌 4. **Decryption Function**

```java
public static String decrypt(PrivateKey key, String encrypted) throws Exception {
    byte[] bytes = Base64.getDecoder().decode(encrypted);
    Cipher cipher = Cipher.getInstance("RSA");
    cipher.init(Cipher.DECRYPT_MODE, key);
    return new String(cipher.doFinal(bytes), "UTF-8");
}
```

* `Base64.getDecoder()`: Decodes the encrypted text back to bytes.
* `Cipher.DECRYPT_MODE`: Configures cipher for decryption.
* Returns the original plain text after decryption.

---

## 🎤 **Common Viva Questions**

### Q1. What is the difference between symmetric and asymmetric encryption?

* **Symmetric**: Same key for encryption and decryption (e.g., AES).
* **Asymmetric**: Different keys; public key for encryption, private key for decryption (e.g., RSA).

### Q2. Why do we use Base64 encoding?

* Because RSA output is binary. Base64 encodes it into readable ASCII text format.

### Q3. Can you encrypt with the private key?

* Yes, but it’s usually done to **digitally sign** data. Anyone with the public key can verify the sender.

### Q4. Is RSA secure?

* Yes, if implemented properly with key size ≥ 2048 bits and secure padding. However, it's slower than symmetric encryption.

### Q5. Why not use RSA for large files?

* RSA is computationally expensive and is meant for small data. Large data is usually encrypted using symmetric keys, which are then secured with RSA (called hybrid encryption).

---

## 📝 Output Sample:

```
Plain Text : Hello, World!
Encrypted Text : [Base64-encoded encrypted text]
Decrypted Text : Hello, World!
```

This confirms that the encryption and decryption process worked correctly using RSA.

---

Would you like a PDF summary of this explanation for your viva prep?

*/