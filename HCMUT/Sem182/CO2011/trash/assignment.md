# Bitcoin & Blockchain

## Ledger

### Introduction

A **ledger** is a list of transactions, in which **anyone can create a new line**.

```
Alice pays Bob $100.
Bob pays Charlie $50.
Charlie pays Denial $200.
```

**Problem 1**: What if Bob is going to write a line: `Alice pays Bob $100` without Alice approving?

**Solution**: Alice should have a way to verify the line: using **digital signature**.

## Digital Signature

A **digital signature** is a mean to verify a transaction.

**Problem 2**: What if someone try to forge (copy) Alice's signature? 

A **digital signature** must have this property:
If a digital signature belongs to a specific person, for example, Alice, then **nobody should be able to** forge (copy) her signature.

**Solution**: A digital signature must be encoded using cryptography.

Each person has a **secret key** (`sk`) and a **public key** (`pk`).
* Nobody knows the **secret key** except the one having it.
* Everybody knows the **public key** of one another.

One signature of is created by a function `Sign` taking two parameters: `message` and `sk`:

```
Sign(message, sk) = Signature
```

This means two different signatures of the same person would look completely different on two different messages.

To verify if 