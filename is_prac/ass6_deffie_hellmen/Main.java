import java.math.BigInteger;
import java.security.SecureRandom;

public class Main {
    private final static SecureRandom random = new SecureRandom();

    public static void main(String[] args) {
        BigInteger p = BigInteger.probablePrime(512, random);
        BigInteger g = new BigInteger("3");
        BigInteger aliceSecret = new BigInteger("123456789");
        BigInteger bobSecret = new BigInteger("987654321");

        // Alice computes her public key
        BigInteger alicePublic = g.modPow(aliceSecret, p);

        // Bob computes his public key
        BigInteger bobPublic = g.modPow(bobSecret, p);

        // Alice and Bob exchange their public keys and compute their own private keys
        BigInteger alicePrivate = bobPublic.modPow(aliceSecret, p);
        BigInteger bobPrivate = alicePublic.modPow(bobSecret, p);

        System.out.println("Alice's Private Key: " + alicePrivate);
        System.out.println("Bob's Private Key: " + bobPrivate);
    }
}

/*
Here's a **complete theory and code explanation** of the **Diffie-Hellman Key Exchange** Java program you've shared, suitable for viva preparation or understanding the cryptographic concept.

---

## 🔐 **Theory: Diffie-Hellman Key Exchange**

### 🔸 What is Diffie-Hellman?

**Diffie-Hellman (DH)** is a cryptographic algorithm used to **securely exchange cryptographic keys over a public channel**. It was the **first practical method** of establishing a shared secret between two parties without transmitting the key directly.

### 🔸 Key Idea:

Two parties (say Alice and Bob) can **generate the same shared secret** key independently, using:

* A shared public prime `p` and base `g`
* Their **own private secrets**
* Each other's **public values**

Even if an attacker intercepts the public values, they **cannot compute** the secret key due to the **discrete logarithm problem**, which is computationally infeasible for large primes.

---

## 🧠 **How It Works (Step-by-step)**

1. **Public Parameters (shared):**

   * A large prime number `p`
   * A primitive root modulo `p`, called generator `g`

2. **Private Keys (kept secret):**

   * Alice chooses a private key `a`
   * Bob chooses a private key `b`

3. **Public Keys (shared openly):**

   * Alice computes: `A = g^a mod p`
   * Bob computes: `B = g^b mod p`

4. **Shared Secret Calculation:**

   * Alice computes: `s = B^a mod p`
   * Bob computes: `s = A^b mod p`

   **Result**: Both get the same `s`, which becomes the **shared secret key**.

---

## ✅ **Java Code Explanation**

Let’s break your code into parts.

---

### 📌 1. Import and Setup

```java
import java.math.BigInteger;
import java.security.SecureRandom;
```

* `BigInteger`: To handle large prime numbers (512 bits).
* `SecureRandom`: Cryptographically secure random number generator.

---

### 📌 2. Prime and Generator Initialization

```java
BigInteger p = BigInteger.probablePrime(512, random);
BigInteger g = new BigInteger("3");
```

* `p`: A large prime number (512 bits).
* `g`: A small integer (commonly 2, 3, or 5) — a **primitive root modulo `p`**.

---

### 📌 3. Private Keys (Secrets)

```java
BigInteger aliceSecret = new BigInteger("123456789");
BigInteger bobSecret = new BigInteger("987654321");
```

* These are **private secrets** chosen by Alice and Bob. In real implementations, these should be large random numbers.

---

### 📌 4. Public Key Computation

```java
BigInteger alicePublic = g.modPow(aliceSecret, p);
BigInteger bobPublic = g.modPow(bobSecret, p);
```

* Computes `g^a mod p` and `g^b mod p`.

---

### 📌 5. Shared Secret Computation

```java
BigInteger alicePrivate = bobPublic.modPow(aliceSecret, p);
BigInteger bobPrivate = alicePublic.modPow(bobSecret, p);
```

* Alice computes: `B^a mod p`
* Bob computes: `A^b mod p`
* Both values are equal and become the **shared secret**.

---

### 📌 6. Output

```java
System.out.println("Alice's Private Key: " + alicePrivate);
System.out.println("Bob's Private Key: " + bobPrivate);
```

* These will **print the same value**, confirming that both parties share the same secret key without ever sending it directly.

---

## 🔍 **Output Sample**

```
Alice's Private Key: 4523871058...
Bob's Private Key: 4523871058...
```

---

## 🎤 **Viva Questions You Might Be Asked**

### Q1. What is the purpose of the Diffie-Hellman algorithm?

To securely generate a shared secret key over an insecure channel.

### Q2. What makes the shared key secure?

The **discrete logarithm problem** — it's hard to reverse `g^x mod p` to find `x`.

### Q3. Why is `p` a large prime number?

To ensure brute-force and discrete logarithm attacks are computationally infeasible.

### Q4. Can this algorithm be used for encryption?

No, it is used for **key exchange** only. The shared key is then used in encryption algorithms like AES.

### Q5. What is the risk if an attacker gets the public values?

They still cannot derive the private secret without solving the discrete logarithm, which is very hard.

---

Would you like me to prepare a quick revision PDF or slide deck for this explanation?

*/