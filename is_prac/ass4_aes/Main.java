import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.nio.charset.StandardCharsets;
import java.util.Base64;

public class Main {
    public static void main(String[] args) throws Exception {
        String key = "squirrel12345678"; // 16 characters for AES

        String plainText = "Hello, World!";
        System.out.println("Plain Text : " + plainText);

        String encryptedText = encrypt(key, plainText);
        System.out.println("Encrypted Text : " + encryptedText);

        String decryptedText = decrypt(key, encryptedText);
        System.out.println("Decrypted Text : " + decryptedText);
    }

    public static String encrypt(String key, String message) throws Exception {
        SecretKeySpec secretKey = new SecretKeySpec(key.getBytes(), "AES");

        Cipher aesCipher = Cipher.getInstance("AES");
        aesCipher.init(Cipher.ENCRYPT_MODE, secretKey);

        byte[] textEncrypted = aesCipher.doFinal(message.getBytes(StandardCharsets.UTF_8));

        return Base64.getEncoder().encodeToString(textEncrypted);
    }

    public static String decrypt(String key, String message) throws Exception {
        byte[] bytes = Base64.getDecoder().decode(message);

        SecretKeySpec secretKey = new SecretKeySpec(key.getBytes(), "AES");

        Cipher aesCipher = Cipher.getInstance("AES");
        aesCipher.init(Cipher.DECRYPT_MODE, secretKey);

        byte[] textDecrypted = aesCipher.doFinal(bytes);

        return new String(textDecrypted);
    }
}


// ### AES Encryption and Decryption Program - Theory and Viva Preparation

// This program demonstrates AES (Advanced Encryption Standard) encryption and decryption in Java. It encrypts a plaintext message using a secret key and then decrypts the ciphertext back to the original message using the same key. Here is the theory behind AES and an explanation of how it works, which would help you prepare for a viva.

// ---

// ### 1. **What is AES?**

// **AES (Advanced Encryption Standard)** is a symmetric encryption algorithm widely used to secure data. Symmetric encryption means that the same key is used for both encryption and decryption.

// * **AES operates on 128-bit blocks of data** and supports key sizes of 128, 192, or 256 bits.
// * AES was adopted as the encryption standard by the U.S. National Institute of Standards and Technology (NIST) in 2001 to replace the older DES (Data Encryption Standard).

// ---

// ### 2. **Why is AES important?**

// * **Efficiency**: AES is efficient and widely used in a variety of applications such as data encryption, SSL/TLS protocols, and secure communication systems.
// * **Security**: It is considered highly secure, and AES-256 (256-bit key) is often regarded as unbreakable with current computing power.
// * **Speed**: AES is faster than many older encryption algorithms and is supported natively in hardware on modern processors.

// ---

// ### 3. **Key Components of AES:**

// * **Key Size**: AES supports three key sizes — 128, 192, and 256 bits. The key size determines the number of rounds used in encryption.

//   * AES-128 uses 10 rounds
//   * AES-192 uses 12 rounds
//   * AES-256 uses 14 rounds
// * **Block Size**: AES operates on 128-bit blocks of data, meaning each block is 16 bytes long.

// ---

// ### 4. **Working of AES:**

// AES encryption involves several rounds of transformation, where data is substituted, shifted, mixed, and combined with the encryption key. These steps are done repeatedly for a number of rounds, depending on the key size.

// The basic steps of AES encryption are:

// 1. **Initial Round**:

//    * **AddRoundKey**: The plaintext is XORed with the encryption key.

// 2. **Rounds (depends on the key size)**:

//    * **SubBytes**: A substitution step where each byte of the data is replaced using a fixed substitution table called the S-Box.
//    * **ShiftRows**: The rows of the state matrix are shifted cyclically.
//    * **MixColumns**: The columns of the state matrix are mixed to provide diffusion.
//    * **AddRoundKey**: The round key is XORed with the data again.

// 3. **Final Round** (no MixColumns in the final round):

//    * **SubBytes**
//    * **ShiftRows**
//    * **AddRoundKey**

// The decryption process reverses these steps.

// ---

// ### 5. **Explanation of the Java Program:**

// This Java program demonstrates AES encryption and decryption using a 16-byte key (128 bits).

// #### Key Components:

// * **Key**: The key used here is a 16-character string (`"squirrel12345678"`) which is used for both encryption and decryption. This string is converted into bytes to form the encryption key.

// ```java
// String key = "squirrel12345678"; // 16 characters = 128-bit AES key
// ```

// * **Plaintext**: The message to be encrypted is `"Hello, World!"`.

// #### Steps:

// 1. **Encryption Process**:

//    * The plaintext is converted into bytes and encrypted using the AES algorithm with the specified key.
//    * The encrypted data is then encoded in Base64 so that it can be easily represented as a string.
//    * The `SecretKeySpec` is used to convert the key into the correct format for AES encryption.

// ```java
// Cipher aesCipher = Cipher.getInstance("AES");
// aesCipher.init(Cipher.ENCRYPT_MODE, secretKey);
// byte[] textEncrypted = aesCipher.doFinal(message.getBytes(StandardCharsets.UTF_8));
// return Base64.getEncoder().encodeToString(textEncrypted);
// ```

// 2. **Decryption Process**:

//    * The encrypted message (Base64-encoded) is decoded back to its byte form.
//    * The same key is used for decryption, and the AES algorithm decrypts the ciphertext to the original plaintext.

// ```java
// byte[] bytes = Base64.getDecoder().decode(message);
// aesCipher.init(Cipher.DECRYPT_MODE, secretKey);
// byte[] textDecrypted = aesCipher.doFinal(bytes);
// return new String(textDecrypted);
// ```

// #### Key Java Classes Used:

// * **SecretKeySpec**: Used to specify the key to be used for AES encryption. It takes a byte array and the algorithm name (here, "AES").
// * **Cipher**: A class that provides the cryptographic operations (encryption and decryption) in Java.
// * **Base64**: A utility class for encoding and decoding binary data into readable Base64 format.

// ---

// ### 6. **Important Concepts and Questions for the Viva:**

// #### a) **What is the difference between symmetric and asymmetric encryption?**

// * **Symmetric Encryption**: The same key is used for both encryption and decryption. AES is an example of symmetric encryption.
// * **Asymmetric Encryption**: A pair of keys is used: a public key for encryption and a private key for decryption. RSA is an example of asymmetric encryption.

// #### b) **Why is the key size important in AES?**

// * The key size determines the level of security. Larger keys result in more rounds of encryption, making the encryption more secure but also slower.
// * AES-128, AES-192, and AES-256 provide different levels of security, with AES-256 being the most secure.

// #### c) **What is padding in AES?**

// * AES operates on fixed-size blocks (128 bits). If the data being encrypted is not a multiple of 128 bits, padding is added to the data to make it fit. In this case, padding is handled automatically by the `Cipher` class in Java.

// #### d) **What is Base64 encoding and why is it used here?**

// * Base64 encoding is used to convert binary data (like encrypted ciphertext) into a readable ASCII string. This is important because encrypted data is often binary and may contain non-printable characters, which are not suitable for display or transmission.

// #### e) **What happens if the encryption key is incorrect during decryption?**

// * If the wrong key is used for decryption, the output will be gibberish (incorrect plaintext). AES decryption relies on the key being the same for both encryption and decryption.

// #### f) **What exceptions might occur in this program?**

// * `NoSuchAlgorithmException`: If the AES algorithm is not available.
// * `InvalidKeyException`: If the key is of an incorrect size.
// * `BadPaddingException`: If there is an error with padding during encryption or decryption.

// #### g) **Explain the role of the `SecretKeySpec` in AES encryption.**

// * `SecretKeySpec` is a subclass of `Key`, and it is used to wrap the byte array of the encryption key. It provides a specification for the AES key, which is then used in the `Cipher` for encryption and decryption.

// #### h) **Can AES encryption be broken?**

// * AES is considered highly secure and is resistant to brute-force attacks, especially with longer key sizes. AES-256 is practically unbreakable with current computational resources, but vulnerabilities can exist in weak implementations, poor key management, or misuse.

// ---

// ### 7. **Security Considerations:**

// * **Key Management**: In a real-world scenario, key management is critical. Never hardcode keys in the source code, and use secure methods to store and distribute keys.
// * **Padding and Modes of Operation**: AES can be used in different modes (e.g., ECB, CBC, etc.) depending on the security needs. The program uses the default ECB mode, which is not secure for some applications as it doesn't hide patterns in the plaintext.

// ---

// This explanation covers the theory behind AES encryption, how it works in the provided Java program, and key concepts to be aware of during a viva.
