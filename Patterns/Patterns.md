## Total Categories & Count of Patterns

### 1. 🔺 Triangle Patterns (~8-10)
- Right triangle, inverted, mirrored right, mirrored inverted
- Left-aligned, right-aligned variants
- Floyd's triangle (numbers)
- Pascal's triangle

### 2. 🔷 Pyramid & Diamond (~5-6)
- Simple pyramid, inverted pyramid
- Full diamond, half diamond
- Hollow pyramid, hollow diamond

### 3. 🔲 Square & Rectangle (~4-5)
- Solid square, hollow square
- Solid rectangle, hollow rectangle
- Border-only patterns

### 4. 🔢 Number Patterns (~10-12)
- Number triangle, reverse number triangle
- Same number rows (111, 222...)
- Palindrome number pattern
- 1 12 123... / 1 22 333...
- Binary patterns (0s and 1s)

### 5. 🔤 Alphabet/Character Patterns (~6-8)
- A B C triangle
- Same letter rows
- Diamond with letters
- Mirrored alphabet

### 6. ⭐ Star Special Shapes (~5-6)
- Butterfly (jo dekha)
- Hourglass
- Cross / Plus shape
- Arrow shape (up/down)
- Zigzag

### 7. 🌀 Spiral & Matrix (~3-4)
- Spiral matrix (fill numbers in spiral)
- Wave pattern
- Checkerboard

---

## Total count?

Roughly **50-60+ patterns** hain across all categories. Lekin interview aur DSA ke liye:

> **Top 30 patterns** aate hain — Striver ki A2Z sheet par yeh sab covered hain specifically pattern section mein.

## Plan — Lets do these Patterns in Batches

- **Batch 1 — Triangles (8 patterns)**
- **Batch 2 — Pyramids & Diamonds (6 patterns)**
- **Batch 3 — Number Patterns (8 patterns)**
- **Batch 4 — Alphabet Patterns (4 patterns)**
- **Batch 5 — Special Shapes (4 patterns)**

---

Har batch ka:
- Visual hoga
- C++ code hoga 
- Logic explain hoga 
- Common mistake batayien jaein gii

---


# 🔺 Triangle Patterns — Batch 1

This batch contains **8 fundamental triangle patterns** in C++.

Each pattern focuses on understanding:
- Nested loops
- Rows and columns
- Spaces and alignment
- Conditions
- Number sequences


---

## Pattern 1 — Solid Right Triangle

### Output

```text
* 
* * 
* * * 
* * * * 
* * * * *
````

### Code

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++)
        cout << "* ";

    cout << "\n";
}
```

### Logic

* Outer loop controls the **rows**.
* Inner loop prints stars.
* Row `i` contains exactly `i` stars.
* Therefore:

```text
Row 1 → 1 star
Row 2 → 2 stars
Row 3 → 3 stars
...
```

### Key Trick

```cpp
j <= i
```

---

## Pattern 2 — Inverted Right Triangle

### Output

```text
* * * * *
* * * *
* * *
* *
*
```

### Code

```cpp
for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= i; j++)
        cout << "* ";

    cout << "\n";
}
```

### Logic

Here the outer loop runs **backwards**.

```text
n → n-1 → n-2 → ... → 1
```

So the number of stars decreases after every row.

### Key Trick

```cpp
i--
```

---

## Pattern 3 — Mirrored Right Triangle

### Output

```text
        *
      * *
    * * *
  * * * *
* * * * *
```

### Code

```cpp
for (int i = 1; i <= n; i++) {

    // Spaces
    for (int j = 1; j <= n - i; j++)
        cout << "  ";

    // Stars
    for (int j = 1; j <= i; j++)
        cout << "* ";

    cout << "\n";
}
```

### Logic

This pattern has **two inner loops**:

1. Print spaces
2. Print stars

For every row:

```text
Spaces = n - i
Stars  = i
```

### Key Trick

```cpp
n - i
```

controls the spaces.

---

## Pattern 4 — Mirrored Inverted Triangle

### Output

```text
* * * * *
  * * * *
    * * *
      * *
        *
```

### Code

```cpp
for (int i = n; i >= 1; i--) {

    // Spaces
    for (int j = 1; j <= n - i; j++)
        cout << "  ";

    // Stars
    for (int j = 1; j <= i; j++)
        cout << "* ";

    cout << "\n";
}
```

### Logic

This is basically a combination of:

* Inverted triangle
* Mirroring using spaces

The number of stars decreases:

```text
n → n-1 → n-2 → ... → 1
```

while spaces increase.

---

## Pattern 5 — Floyd's Triangle

### Output

```text
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

### Code

```cpp
int num = 1;

for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= i; j++)
        cout << num++ << " ";

    cout << "\n";
}
```

### Logic

The important part is:

```cpp
int num = 1;
```

It is declared **outside both loops**.

Then:

```cpp
num++
```

keeps increasing the number continuously.

### Key Insight

Don't reset `num` inside the outer loop.

❌ Wrong:

```cpp
for (int i = 1; i <= n; i++) {
    int num = 1;
}
```

✅ Correct:

```cpp
int num = 1;

for (int i = 1; i <= n; i++) {
    ...
}
```

---

## Pattern 6 — 0-1 Triangle

### Output

```text
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
```

### Code

```cpp
for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= i; j++)
        cout << ((i + j) % 2 == 0 ? 1 : 0) << " ";

    cout << "\n";
}
```

### Logic

We use:

```cpp
(i + j) % 2
```

If the sum is even:

```text
1
```

If the sum is odd:

```text
0
```

### Key Trick

```cpp
(i + j) % 2 == 0
```

---

## Pattern 7 — Same Number Per Row

### Output

```text
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
```

### Code

```cpp
for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= i; j++)
        cout << i << " ";

    cout << "\n";
}
```

### Logic

Notice that we print:

```cpp
i
```

instead of:

```cpp
j
```

The outer loop `i` represents the current row.

Therefore, every element in the same row is identical.

### Key Trick

```cpp
cout << i;
```

---

## Pattern 8 — Reverse Number Triangle

### Output

```text
5 4 3 2 1
4 3 2 1
3 2 1
2 1
1
```

### Code

```cpp
for (int i = n; i >= 1; i--) {

    for (int j = n; j >= n - i + 1; j--)
        cout << j << " ";

    cout << "\n";
}
```

### Logic

The outer loop decreases:

```text
n → n-1 → n-2 → ... → 1
```

The inner loop also moves backwards.

For `n = 5`:

```text
i = 5 → 5 4 3 2 1
i = 4 → 4 3 2 1
i = 3 → 3 2 1
...
```

---

# 📌 Batch 1 — Quick Summary

| # | Pattern                    | Main Trick           |
| - | -------------------------- | -------------------- |
| 1 | Solid Right Triangle       | `j <= i`             |
| 2 | Inverted Right Triangle    | Outer loop backwards |
| 3 | Mirrored Right Triangle    | Spaces + stars       |
| 4 | Mirrored Inverted Triangle | Backwards + spaces   |
| 5 | Floyd's Triangle           | Extra `num` variable |
| 6 | 0-1 Triangle               | `(i + j) % 2`        |
| 7 | Same Number Per Row        | Print `i`            |
| 8 | Reverse Number Triangle    | Inner loop backwards |


# 🔺 Pyramids & Diamonds — Batch 2

This batch contains **6 pyramid and diamond patterns** in C++.

These patterns introduce an important concept:

> **Spaces + Stars + Symmetry**

The main focus is understanding how spaces and stars change from row to row.

---

# 🧠 The Important Space Formula

For centered pyramid patterns, remember:

```text
Left Spaces = n - i
Stars       = 2i - 1
````

For example, if:

```text
n = 5
```

then:

```text
Row 1 → Spaces = 4, Stars = 1
Row 2 → Spaces = 3, Stars = 3
Row 3 → Spaces = 2, Stars = 5
Row 4 → Spaces = 1, Stars = 7
Row 5 → Spaces = 0, Stars = 9
```

This gives us:

```text
    *
   ***
  *****
 *******
*********
```

---

# Pattern 9 — Simple Pyramid

## Output

```text
    *
   * *
  * * *
 * * * *
* * * * *
```

## Code

```cpp
for (int i = 1; i <= n; i++) {

    // Spaces
    for (int j = 1; j <= n - i; j++)
        cout << " ";

    // Stars
    for (int j = 1; j <= i; j++)
        cout << "* ";

    cout << "\n";
}
```

## Logic

Every row contains two things:

1. Spaces
2. Stars

For every row:

```text
Spaces = n - i
Stars  = i
```

Example for `n = 5`:

```text
Row 1 → 4 spaces + 1 star
Row 2 → 3 spaces + 2 stars
Row 3 → 2 spaces + 3 stars
Row 4 → 1 space  + 4 stars
Row 5 → 0 spaces + 5 stars
```

### Key Trick

```cpp
n - i
```

controls the left indentation.

---

# Pattern 10 — Full Centered Pyramid

## Output

```text
    *
   ***
  *****
 *******
*********
```

## Code

```cpp
for (int i = 1; i <= n; i++) {

    // Spaces
    for (int j = 1; j <= n - i; j++)
        cout << " ";

    // Stars
    for (int j = 1; j <= 2 * i - 1; j++)
        cout << "*";

    cout << "\n";
}
```

## Logic

This is the classic centered pyramid.

For every row:

```text
Spaces = n - i
Stars  = 2i - 1
```

Example:

```text
i = 1 → 4 spaces + 1 star
i = 2 → 3 spaces + 3 stars
i = 3 → 2 spaces + 5 stars
i = 4 → 1 space  + 7 stars
i = 5 → 0 spaces + 9 stars
```

### Important

Here we use:

```cpp
cout << "*";
```

NOT:

```cpp
cout << "* ";
```

Because `* ` adds an extra space after every star and changes the width of the pyramid.

### Key Formula

```cpp
2 * i - 1
```

---

# Pattern 11 — Inverted Full Pyramid

## Output

```text
*********
 *******
  *****
   ***
    *
```

## Code

```cpp
for (int i = n; i >= 1; i--) {

    // Spaces
    for (int j = 1; j <= n - i; j++)
        cout << " ";

    // Stars
    for (int j = 1; j <= 2 * i - 1; j++)
        cout << "*";

    cout << "\n";
}
```

## Logic

This is simply the full pyramid in reverse.

The outer loop decreases:

```text
n → n-1 → n-2 → ... → 1
```

The formulas remain:

```text
Spaces = n - i
Stars  = 2i - 1
```

So the stars decrease:

```text
9 → 7 → 5 → 3 → 1
```

while spaces increase:

```text
0 → 1 → 2 → 3 → 4
```

### Key Trick

Only the outer loop direction changes:

```cpp
i--
```

---

# Pattern 12 — Diamond

## Output

```text
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```

## Code

```cpp
// Upper half
for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= n - i; j++)
        cout << " ";

    for (int j = 1; j <= 2 * i - 1; j++)
        cout << "*";

    cout << "\n";
}

// Lower half
for (int i = n - 1; i >= 1; i--) {

    for (int j = 1; j <= n - i; j++)
        cout << " ";

    for (int j = 1; j <= 2 * i - 1; j++)
        cout << "*";

    cout << "\n";
}
```

## Logic

A diamond consists of **two pyramids**:

```text
Upper Pyramid
      ↓
    *
   ***
  *****
 *******
*********

Lower Inverted Pyramid
      ↓
 *******
  *****
   ***
    *
```

### Important

The lower half starts from:

```cpp
i = n - 1
```

NOT:

```cpp
i = n
```

Why?

Because if we start from `n`, the middle row will be printed twice.

### Key Trick

```cpp
n - 1
```

prevents the middle row from repeating.

---

# Pattern 13 — Hollow Pyramid

## Output

```text
    *
   * *
  *   *
 *     *
*********
```

## Code

```cpp
for (int i = 1; i <= n; i++) {

    // Spaces
    for (int j = 1; j <= n - i; j++)
        cout << " ";

    // Stars / Empty Space
    for (int j = 1; j <= 2 * i - 1; j++) {

        if (j == 1 || j == 2 * i - 1 || i == n)
            cout << "*";
        else
            cout << " ";
    }

    cout << "\n";
}
```

## Logic

Instead of printing a star everywhere, we only print stars on the **boundary**.

There are three conditions:

### 1. Left Edge

```cpp
j == 1
```

### 2. Right Edge

```cpp
j == 2 * i - 1
```

### 3. Bottom Row

```cpp
i == n
```

The complete condition becomes:

```cpp
if (j == 1 || j == 2 * i - 1 || i == n)
```

### Why `i == n`?

The last row should be completely filled with stars.

Otherwise, the pyramid would have an empty bottom.

### Key Trick

```cpp
j == 1 || j == 2 * i - 1 || i == n
```

---

# Pattern 14 — Hollow Diamond

## Output

```text
    *
   * *
  *   *
 *     *
*       *
 *     *
  *   *
   * *
    *
```

## Code

```cpp
// Upper half
for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= n - i; j++)
        cout << " ";

    for (int j = 1; j <= 2 * i - 1; j++) {

        if (j == 1 || j == 2 * i - 1)
            cout << "*";
        else
            cout << " ";
    }

    cout << "\n";
}

// Lower half
for (int i = n - 1; i >= 1; i--) {

    for (int j = 1; j <= n - i; j++)
        cout << " ";

    for (int j = 1; j <= 2 * i - 1; j++) {

        if (j == 1 || j == 2 * i - 1)
            cout << "*";
        else
            cout << " ";
    }

    cout << "\n";
}
```

## Logic

Hollow Diamond is made from:

```text
Hollow Pyramid
       +
Hollow Inverted Pyramid
```

But unlike the hollow pyramid, there is **no completely filled bottom row**.

That's why the condition is only:

```cpp
j == 1 || j == 2 * i - 1
```

### Boundary Conditions

```text
Left edge  → j == 1
Right edge → j == 2*i - 1
```

Everything between the edges becomes a space.

---

# 📊 Batch 2 — Master Table

| #  | Pattern          | Spaces | Stars  | Special Condition      |
| -- | ---------------- | ------ | ------ | ---------------------- |
| 9  | Simple Pyramid   | `n-i`  | `i`    | —                      |
| 10 | Full Pyramid     | `n-i`  | `2i-1` | No space between stars |
| 11 | Inverted Pyramid | `n-i`  | `2i-1` | Outer loop backwards   |
| 12 | Diamond          | `n-i`  | `2i-1` | Two halves             |
| 13 | Hollow Pyramid   | `n-i`  | `2i-1` | Boundary + last row    |
| 14 | Hollow Diamond   | `n-i`  | `2i-1` | Boundary only          |


# 🔢 Number Patterns — Batch 3

This batch contains **8 important number patterns** in C++.

In this batch, stars ki jagah numbers use honge, lekin basic structure wahi rahega:

* Outer loop → rows
* Inner loop → columns
* `i` → row number
* `j` → column number
* Extra counter → continuously increasing value

---

# 🧠 Number Patterns ki 3 Basic Types

Number patterns ko samajhne ke liye pehle yeh distinction clear karo.

### 1. `j` print karo → Column Number

```cpp
cout << j;
```

Example:

```text
1
1 2
1 2 3
1 2 3 4
```

---

### 2. `i` print karo → Row Number

```cpp
cout << i;
```

Example:

```text
1
2 2
3 3 3
4 4 4 4
```

---

### 3. Counter print karo → Continuous Number

```cpp
cout << num++;
```

Example:

```text
1
2 3
4 5 6
7 8 9 10
```

### ⭐ Golden Idea

> Pehle decide karo ke **print kya karna hai** — `i`, `j`, ya koi separate counter. Baaki loop structure aksar same hota hai.

---

# Pattern 15 — Simple Number Triangle

## Output

```text
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
```

## Code

```cpp
for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= i; j++)
        cout << j << " ";

    cout << "\n";
}
```

## Logic

Outer loop rows control karta hai.

Inner loop:

```cpp
j <= i
```

ki wajah se har row mein numbers `1` se `i` tak print hote hain.

Example:

```text
i = 1 → 1
i = 2 → 1 2
i = 3 → 1 2 3
i = 4 → 1 2 3 4
```

### Key Trick

```cpp
cout << j;
```

Yahan `j` **column number** represent kar raha hai.

---

# Pattern 16 — Reverse Number Triangle

## Output

```text
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
```

## Code

```cpp
for (int i = n; i >= 1; i--) {

    for (int j = 1; j <= i; j++)
        cout << j << " ";

    cout << "\n";
}
```

## Logic

Pattern 15 jaisa hi structure hai.

Difference sirf outer loop ka hai:

```cpp
i = n
i--
```

Isliye rows ki length continuously decrease hoti hai.

For `n = 5`:

```text
i = 5 → 1 2 3 4 5
i = 4 → 1 2 3 4
i = 3 → 1 2 3
i = 2 → 1 2
i = 1 → 1
```

### Key Trick

Outer loop backwards:

```cpp
i--
```

---

# Pattern 17 — Same Number Each Row

## Output

```text
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
```

## Code

```cpp
for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= i; j++)
        cout << i << " ";

    cout << "\n";
}
```

## Logic

Yahan important difference hai:

```cpp
cout << i;
```

Hum `j` print nahi kar rahe.

`i` current row ko represent karta hai, isliye same row mein same number repeat hota hai.

Example:

```text
i = 1 → 1
i = 2 → 2 2
i = 3 → 3 3 3
i = 4 → 4 4 4 4
```

### Key Trick

```cpp
cout << i;
```

### Remember

```text
i → Row
j → Column
```

---

# Pattern 18 — Floyd's Triangle

## Output

```text
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

## Code

```cpp
int num = 1;

for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= i; j++)
        cout << num++ << " ";

    cout << "\n";
}
```

## Logic

Yahan `i` ya `j` print nahi karna.

Humein ek separate counter chahiye:

```cpp
int num = 1;
```

Aur har number print hone ke baad:

```cpp
num++;
```

Example:

```text
1
2 3
4 5 6
7 8 9 10
```

### ⭐ Important

`num` ko loops ke **bahar** declare karo.

Correct:

```cpp
int num = 1;

for (...) {
    for (...) {
        cout << num++;
    }
}
```

Wrong:

```cpp
for (...) {
    int num = 1;
}
```

Agar `num` outer loop ke andar reset hoga, to numbers continuously increase nahi honge.

### Key Trick

```cpp
num++
```

---

# Pattern 19 — Pascal's Triangle

## Output

```text
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
```

## Code

```cpp
for (int i = 0; i < n; i++) {

    // Spaces for centering
    for (int j = 0; j < n - i - 1; j++)
        cout << " ";

    int val = 1;

    for (int j = 0; j <= i; j++) {

        cout << val << " ";

        val = val * (i - j) / (j + 1);
    }

    cout << "\n";
}
```

## Logic

Pascal's Triangle mein har row ke numbers **binomial coefficients** hote hain.

For example:

```text
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

Har row ka first value:

```text
1
```

hota hai.

Hum:

```cpp
int val = 1;
```

se start karte hain.

Phir next value calculate karne ke liye:

```cpp
val = val * (i - j) / (j + 1);
```

use karte hain.

### Important

Yahan `val` ko **har row ke start par 1** se reset karna zaroori hai.

Isliye:

```cpp
for (int i = 0; i < n; i++) {

    int val = 1;

    ...
}
```

### Key Concept

Pascal's Triangle ka mathematical relation:

```text
C(n,r) = n! / (r!(n-r)!)
```

Lekin code mein har element ke liye factorial calculate karne ke bajaye hum previous value se next value efficiently generate kar rahe hain.

---

# Pattern 20 — Number Pyramid

## Output

```text
    1
   222
  33333
 4444444
555555555
```

## Code

```cpp
for (int i = 1; i <= n; i++) {

    // Spaces
    for (int j = 1; j <= n - i; j++)
        cout << " ";

    // Numbers
    for (int j = 1; j <= 2 * i - 1; j++)
        cout << i;

    cout << "\n";
}
```

## Logic

Yeh Pattern 10 ke Full Pyramid jaisa hai.

Difference:

```cpp
cout << "*";
```

ki jagah:

```cpp
cout << i;
```

print kar rahe hain.

Formula:

```text
Spaces = n - i
Numbers = 2i - 1
```

Example:

```text
i = 1 → 1
i = 2 → 222
i = 3 → 33333
i = 4 → 4444444
```

### Key Trick

```cpp
2 * i - 1
```

centered pyramid ki width control karta hai.

---

# Pattern 21 — Palindrome Number Triangle

## Output

```text
    1
   212
  32123
 4321234
543212345
```

## Code

```cpp
for (int i = 1; i <= n; i++) {

    // Spaces
    for (int j = 1; j <= n - i; j++)
        cout << " ";

    // Left side: i down to 1
    for (int j = i; j >= 1; j--)
        cout << j;

    // Right side: 2 up to i
    for (int j = 2; j <= i; j++)
        cout << j;

    cout << "\n";
}
```

## Logic

Yeh pattern do number sequences ko combine karta hai.

### Left Half

Numbers decrease karte hain:

```text
i → i-1 → ... → 2 → 1
```

Example for `i = 4`:

```text
4 3 2 1
```

### Right Half

Numbers increase karte hain:

```text
2 → 3 → ... → i
```

Example:

```text
2 3 4
```

Together:

```text
4 3 2 1 2 3 4
```

### ⭐ Why start from `2`?

Agar right side bhi `1` se start karein:

```text
4 3 2 1 1 2 3 4
```

to center mein `1` repeat ho jayega.

Isliye:

```cpp
for (int j = 2; j <= i; j++)
```

use karte hain.

### Key Trick

```text
Left  → i down to 1
Right → 2 up to i
```

---

# Pattern 22 — Sandglass Number Pattern

## Output

```text
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
```

## Code

```cpp
// Upper half
for (int i = n; i >= 1; i--) {

    for (int j = 1; j <= i; j++)
        cout << j << " ";

    cout << "\n";
}

// Lower half
for (int i = 2; i <= n; i++) {

    for (int j = 1; j <= i; j++)
        cout << j << " ";

    cout << "\n";
}
```

## Logic

Sandglass ko do parts mein divide karo:

```text
Upper Half
↓
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

Lower Half
↓
1 2
1 2 3
1 2 3 4
1 2 3 4 5
```

### Upper Half

```cpp
for (int i = n; i >= 1; i--)
```

Numbers decrease karte hain.

### Lower Half

```cpp
for (int i = 2; i <= n; i++)
```

Numbers increase karte hain.

### ⭐ Important

Lower half `2` se start hota hai, `1` se nahi.

Agar:

```cpp
i = 1
```

se start karoge to middle row:

```text
1
```

dobara print ho jayegi.

### Key Trick

```text
Upper → n to 1
Lower → 2 to n
```

---

# 📊 Batch 3 — Quick Reference

| #  | Pattern                 | Key Trick             | Print   |
| -- | ----------------------- | --------------------- | ------- |
| 15 | Simple Number Triangle  | `j <= i`              | `j`     |
| 16 | Reverse Number Triangle | Outer loop backwards  | `j`     |
| 17 | Same Number Each Row    | `j <= i`              | `i`     |
| 18 | Floyd's Triangle        | Counter outside loops | `num++` |
| 19 | Pascal's Triangle       | nCr relation          | `val`   |
| 20 | Number Pyramid          | Spaces + `2i-1`       | `i`     |
| 21 | Palindrome Triangle     | Two number sequences  | `j`     |
| 22 | Sandglass               | Two halves            | `j`     |

---

# 🧠 Core Concepts Learned

After completing Batch 3, you should understand:

* Difference between `i` and `j`
* Row number vs column number
* Continuous counters
* Number sequences
* Reverse loops
* Centered number patterns
* `2 * i - 1` formula
* Pascal's Triangle
* Palindromic patterns
* Splitting patterns into two halves
* Avoiding duplicate middle rows

---

# 🔑 The Golden Rule

> **Star pattern mein `"*"` ki jagah number pattern mein decide karo ke kya print karna hai.**

Usually:

```text
j      → Column-based pattern
i      → Row-based pattern
num    → Continuous sequence
val    → Calculated value
```

For example:

```cpp
cout << j;
```

means:

```text
Column number
```

while:

```cpp
cout << i;
```

means:

```text
Row number
```

and:

```cpp
cout << num++;
```

means:

```text
Continuous counter
```

---


# 🔤 Alphabet & Character Patterns — Batch 4

This batch contains **6 important alphabet and character patterns** in C++.

Number patterns ki tarah hi yahan bhi nested loops use honge.

Difference sirf itna hai ke numbers ki jagah **characters** print honge.

---

# 🧠 Pehle Character Logic Samjho

C++ mein characters internally numeric ASCII values ke through represent hote hain.

For example:

```cpp
'A' + 0  → A
'A' + 1  → B
'A' + 2  → C
'A' + 3  → D
'A' + 4  → E
```

Isliye hum likh sakte hain:

```cpp
(char)('A' + j)
```

### Example

```cpp
cout << (char)('A' + 0);
```

Output:

```text
A
```

Aur:

```cpp
cout << (char)('A' + 4);
```

Output:

```text
E
```

### ⭐ Important

`'A' + j` ka result integer expression ho sakta hai, isliye character output ko clear rakhne ke liye:

```cpp
(char)('A' + j)
```

use karte hain.

---

# Pattern 23 — Simple Alphabet Triangle

## Output

```text
A
A B
A B C
A B C D
A B C D E
```

## Code

```cpp
for (int i = 0; i < n; i++) {

    for (int j = 0; j <= i; j++)
        cout << (char)('A' + j) << " ";

    cout << "\n";
}
```

## Logic

Yeh Pattern 15 ke Simple Number Triangle jaisa hai.

Number pattern mein:

```cpp
cout << j;
```

tha.

Alphabet pattern mein:

```cpp
cout << (char)('A' + j);
```

hai.

### Example

For `i = 2`:

```text
j = 0 → A
j = 1 → B
j = 2 → C
```

Output:

```text
A B C
```

### Key Trick

```cpp
'A' + j
```

`j` ko alphabet position mein convert karta hai.

---

# Pattern 24 — Same Letter Per Row

## Output

```text
A
B B
C C C
D D D D
E E E E E
```

## Code

```cpp
for (int i = 0; i < n; i++) {

    for (int j = 0; j <= i; j++)
        cout << (char)('A' + i) << " ";

    cout << "\n";
}
```

## Logic

Yahan `j` print nahi ho raha.

Hum print kar rahe hain:

```cpp
(char)('A' + i)
```

Because `i` current row represent karta hai.

### Example

```text
i = 0 → A
i = 1 → B
i = 2 → C
i = 3 → D
```

Aur har row mein wohi letter repeat hota hai.

### Key Trick

```cpp
'A' + i
```

### Number Pattern se Relation

Number version:

```cpp
cout << i;
```

Alphabet version:

```cpp
cout << (char)('A' + i);
```

---

# Pattern 25 — Reverse Alphabet Triangle

## Output

For `n = 5`:

```text
E
E D
E D C
E D C B
E D C B A
```

## Code

```cpp
for (int i = 0; i < n; i++) {

    for (int j = n - 1; j >= n - 1 - i; j--)
        cout << (char)('A' + j) << " ";

    cout << "\n";
}
```

## Logic

Agar:

```text
n = 5
```

to last alphabet index:

```text
n - 1 = 4
```

Aur:

```text
'A' + 4 = E
```

Isliye pattern `E` se start hota hai.

### Row by Row

```text
i = 0 → E
i = 1 → E D
i = 2 → E D C
i = 3 → E D C B
i = 4 → E D C B A
```

### Key Trick

Inner loop backwards:

```cpp
j--
```

Aur starting position:

```cpp
j = n - 1
```

---

# Pattern 26 — Alphabet Pyramid

## Output

```text
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
```

## Code

```cpp
for (int i = 0; i < n; i++) {

    // Spaces
    for (int j = 0; j < n - i - 1; j++)
        cout << " ";

    // Left side: A to current letter
    for (int j = 0; j <= i; j++)
        cout << (char)('A' + j);

    // Right side: current letter back to A
    for (int j = i - 1; j >= 0; j--)
        cout << (char)('A' + j);

    cout << "\n";
}
```

## Logic

Yeh pattern **3 parts** mein socho:

```text
Spaces
+
Increasing Letters
+
Decreasing Letters
```

### Example: Row `i = 2`

Spaces:

```text
2 spaces
```

Left side:

```text
A B C
```

Right side:

```text
B A
```

Together:

```text
ABCBA
```

### Why `i - 1`?

Right side mein:

```cpp
for (int j = i - 1; j >= 0; j--)
```

use kiya hai.

Agar right side `i` se start kar dein:

```text
ABC CBA
```

to middle letter repeat ho jayega.

Correct:

```text
ABCBA
```

### Key Trick

```text
Left  → A to current letter
Right → previous letter back to A
```

---

# Pattern 27 — Diamond with Letters

## Output

```text
    A
   BB
  CCC
 DDDD
EEEEE
 DDDD
  CCC
   BB
    A
```

## Code

```cpp
// Upper half
for (int i = 0; i < n; i++) {

    for (int j = 0; j < n - i - 1; j++)
        cout << " ";

    for (int j = 0; j <= i; j++)
        cout << (char)('A' + i) << " ";

    cout << "\n";
}

// Lower half
for (int i = n - 2; i >= 0; i--) {

    for (int j = 0; j < n - i - 1; j++)
        cout << " ";

    for (int j = 0; j <= i; j++)
        cout << (char)('A' + i) << " ";

    cout << "\n";
}
```

## Logic

Yeh pattern do halves se mil kar banta hai.

### Upper Half

```text
A
BB
CCC
DDDD
EEEEE
```

### Lower Half

```text
DDDD
CCC
BB
A
```

Dono combine:

```text
    A
   BB
  CCC
 DDDD
EEEEE
 DDDD
  CCC
   BB
    A
```

### ⭐ Important

Lower half:

```cpp
i = n - 2
```

se start hota hai.

`n - 1` se start nahi karte, warna middle row repeat ho jayegi.

### Key Trick

```text
Upper → 0 to n-1
Lower → n-2 to 0
```

---

# Pattern 28 — Mirrored Alphabet Triangle

## Output

```text
        A
      A B
    A B C
  A B C D
A B C D E
```

## Code

```cpp
for (int i = 0; i < n; i++) {

    // Spaces
    for (int j = 0; j < n - i - 1; j++)
        cout << "  ";

    // Letters
    for (int j = 0; j <= i; j++)
        cout << (char)('A' + j) << " ";

    cout << "\n";
}
```

## Logic

Is pattern mein:

```text
Spaces  = n - i - 1
Letters = i + 1
```

### Example for `n = 5`

```text
Row 1 → 4 spaces + A
Row 2 → 3 spaces + A B
Row 3 → 2 spaces + A B C
Row 4 → 1 space  + A B C D
Row 5 → 0 spaces + A B C D E
```

### Why `"  "` for spaces?

Hum letters ke baad:

```cpp
cout << " ";
```

use kar rahe hain.

Isliye alignment maintain karne ke liye indentation mein:

```cpp
cout << "  ";
```

use karna helpful hai.

### Key Trick

```cpp
n - i - 1
```

controls the indentation.

---

# 📊 Batch 4 — Quick Reference

| #  | Pattern                    | Key Idea                  | Print        |
| -- | -------------------------- | ------------------------- | ------------ |
| 23 | Simple Alphabet Triangle   | `j <= i`                  | `'A' + j`    |
| 24 | Same Letter Per Row        | `j <= i`                  | `'A' + i`    |
| 25 | Reverse Alphabet Triangle  | Inner loop backwards      | `'A' + j`    |
| 26 | Alphabet Pyramid           | Two letter loops + spaces | Up then down |
| 27 | Diamond with Letters       | Two halves                | `'A' + i`    |
| 28 | Mirrored Alphabet Triangle | Spaces + letters          | `'A' + j`    |

---

# 🧠 Core Concepts Learned

After completing Batch 4, you should understand:

* Character representation in C++
* ASCII-based character arithmetic
* `'A' + i`
* `'A' + j`
* Character casting
* Increasing alphabet sequences
* Decreasing alphabet sequences
* Same character per row
* Centered alphabet pyramids
* Alphabet diamonds
* Mirrored alphabet patterns
* Two-half patterns

---

# 🔑 Master Rule — Number vs Alphabet

Number patterns mein:

```cpp
cout << j;
```

Alphabet patterns mein:

```cpp
cout << (char)('A' + j);
```

---

Number row mein:

```cpp
cout << i;
```

Alphabet row mein:

```cpp
cout << (char)('A' + i);
```

---

Continuous character sequence ke liye:

```cpp
char ch = 'A';

cout << ch++;
```

---

# ⭐ Conversion Rule

Agar tumhare paas koi number pattern hai:

```cpp
cout << j;
```

to usko alphabet pattern mein convert karne ke liye generally:

```cpp
cout << (char)('A' + j - 1);
```

ya zero-based indexing mein:

```cpp
cout << (char)('A' + j);
```

use kiya ja sakta hai.

### Difference samjho

Agar:

```text
j = 0
```

then:

```cpp
'A' + j
```

gives:

```text
A
```

Agar:

```text
j = 1
```

then:

```cpp
'A' + j
```

gives:

```text
B
```

Isliye loop `0` se start ho to:

```cpp
(char)('A' + j)
```

natural choice hai.

---

# ⭐ Batch 5 — Special Shapes

Special Shapes thode creative hote hain, kyunki inmein simple patterns ko **combine** karke ek complex shape banayi jati hai.

Is batch mein hum **Butterfly, Hourglass, Cross, Arrow, Zigzag/Wave aur Spiral Matrix** cover karenge.

---

## 🏆 Golden Rule for Special Shapes

> **Koi bhi complex shape = 2 ya 3 simple parts ka combination.**

Pehle shape ko mentally split karo:

```text
Shape
 ↓
Parts identify karo
 ↓
Har part ka loop socho
 ↓
Parts ko combine karo
 ↓
Final pattern
```

Yani direct poori shape ko code karne ki koshish mat karo.
**Pehle shape ko todho, phir code karo.**

---

# 🦋 Pattern 29 — Butterfly

Butterfly pattern ko hum **2 wings + middle spaces** mein divide kar sakte hain.

### Output

For `n = 4`:

```text
*      *
**    **
***  ***
********
***  ***
**    **
*      *
```

### Code

```cpp
// Upper half
for (int i = 1; i <= n; i++) {

    // Left wing
    for (int j = 1; j <= i; j++)
        cout << "*";

    // Middle spaces
    for (int j = 1; j <= 2 * (n - i); j++)
        cout << " ";

    // Right wing
    for (int j = 1; j <= i; j++)
        cout << "*";

    cout << "\n";
}

// Lower half
for (int i = n - 1; i >= 1; i--) {

    // Left wing
    for (int j = 1; j <= i; j++)
        cout << "*";

    // Middle spaces
    for (int j = 1; j <= 2 * (n - i); j++)
        cout << " ";

    // Right wing
    for (int j = 1; j <= i; j++)
        cout << "*";

    cout << "\n";
}
```

### 🧠 Logic

Har row mein 3 cheezen hain:

```text
Left Stars + Middle Spaces + Right Stars
```

Upper half:

```text
Stars ↑
Spaces ↓
```

Lower half:

```text
Stars ↓
Spaces ↑
```

### 🔑 Key Trick

Middle spaces ka formula:

```cpp
2 * (n - i)
```

Example `n = 4`:

```text
i = 1 → 6 spaces
i = 2 → 4 spaces
i = 3 → 2 spaces
i = 4 → 0 spaces
```

---

# ⌛ Pattern 30 — Hourglass / Sandglass

Hourglass ko do triangles mein divide karo:

```text
Inverted Triangle
       +
Normal Triangle
```

### Output

For `n = 5`:

```text
* * * * *
 * * * *
  * * *
   * *
    *
   * *
  * * *
 * * * *
* * * * *
```

### Code

```cpp
// Upper half — inverted triangle
for (int i = n; i >= 1; i--) {

    // Spaces
    for (int j = 1; j <= n - i; j++)
        cout << " ";

    // Stars
    for (int j = 1; j <= i; j++)
        cout << "* ";

    cout << "\n";
}

// Lower half — normal triangle
for (int i = 2; i <= n; i++) {

    // Spaces
    for (int j = 1; j <= n - i; j++)
        cout << " ";

    // Stars
    for (int j = 1; j <= i; j++)
        cout << "* ";

    cout << "\n";
}
```

### 🧠 Logic

Upper half:

```text
n → 1
```

Stars decrease.

Lower half:

```text
2 → n
```

Stars increase.

### 🔑 Key Trick

Lower loop **2 se start** hota hai:

```cpp
for (int i = 2; i <= n; i++)
```

Kyun?

Kyunkay middle row already upper half mein print ho chuki hai.

---

# ✚ Pattern 31 — Cross / Plus Shape

Yeh pattern thoda different hai.

Ismein nested loops se grid banayenge aur ek condition decide karegi ke star print karna hai ya space.

### Output

For `n = 5`:

```text
  *
  *
*****
  *
  *
```

### Code

```cpp
int mid = n / 2;

for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

        if (i == mid || j == mid)
            cout << "*";
        else
            cout << " ";
    }

    cout << "\n";
}
```

### 🧠 Logic

Grid mein har position `(i, j)` ko check karo.

Agar:

```cpp
i == mid
```

toh **middle row** hai.

Ya:

```cpp
j == mid
```

toh **middle column** hai.

Dono mein se koi bhi true ho:

```cpp
i == mid || j == mid
```

toh star print karo.

### 🔑 Key Trick

Cross ke liye main condition:

```cpp
i == mid || j == mid
```

Aur:

```cpp
int mid = n / 2;
```

### ⚠️ Important

Symmetric Cross ke liye `n` ko **odd** rakhna best hai:

```text
5
7
9
11
...
```

---

# ➡️ Pattern 32 — Arrow

Is arrow ko hum do simple triangles se bana sakte hain:

```text
Normal Triangle
       +
Inverted Triangle
```

Yeh left-aligned hai, isliye extra spaces ki zaroorat nahi.

### Output

For `n = 5`:

```text
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*
```

### Code

```cpp
// Upper half
for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= i; j++)
        cout << "* ";

    cout << "\n";
}

// Lower half
for (int i = n - 1; i >= 1; i--) {

    for (int j = 1; j <= i; j++)
        cout << "* ";

    cout << "\n";
}
```

### 🧠 Logic

Upper half:

```text
1
2
3
4
5
```

Lower half:

```text
4
3
2
1
```

Middle row ko repeat nahi karna, isliye lower half:

```cpp
i = n - 1
```

se start hota hai.

### 🔑 Key Trick

Arrow basically:

```text
Increasing Triangle
        +
Decreasing Triangle
```

Aur kyunki left-aligned hai:

> **No extra spaces required.**

---

# 🌊 Pattern 33 — Zigzag / Wave

Zigzag pattern fixed-width pattern hai.

Is example mein hum **3 rows** aur **9 columns** use kar rahe hain.

### Output

```text
*   *   *
* * * * *
  *   *  
```

### Code

```cpp
int cols = 9;

// Row 1 — top peaks
for (int j = 0; j < cols; j++)
    cout << (j % 4 == 0 ? "*" : " ");

cout << "\n";

// Row 2 — middle
for (int j = 0; j < cols; j++)
    cout << (j % 2 == 0 ? "*" : " ");

cout << "\n";

// Row 3 — bottom valleys
for (int j = 0; j < cols; j++)
    cout << (j % 4 == 2 ? "*" : " ");

cout << "\n";
```

### 🧠 Logic

Yahan hum `%` operator ka use kar rahe hain.

Top row:

```cpp
j % 4 == 0
```

Middle row:

```cpp
j % 2 == 0
```

Bottom row:

```cpp
j % 4 == 2
```

Yani **modulo patterns** ko control kar raha hai.

### 🔑 Key Trick

Zigzag ke liye:

```text
% 4
% 2
% 4
```

positions determine karte hain.

Yeh pattern normal nested-loop shapes se different hai, kyunki yahan **position-based condition** important hai.

---

# 🌀 Pattern 34 — Spiral Matrix

Ab aata hai is batch ka sabse important pattern:

> **Spiral Matrix**

Ismein matrix ke andar numbers ko clockwise spiral mein fill kiya jata hai.

### Output

For `n = 5`:

```text
1    2    3    4    5
16   17   18   19   6
15   24   25   20   7
14   23   22   21   8
13   12   11   10   9
```

### Code

```cpp
int n = 5;

int mat[5][5] = {};

int top = 0;
int bottom = n - 1;
int left = 0;
int right = n - 1;

int num = 1;

while (top <= bottom && left <= right) {

    // Left to right — top row
    for (int i = left; i <= right; i++)
        mat[top][i] = num++;

    top++;

    // Top to bottom — right column
    for (int i = top; i <= bottom; i++)
        mat[i][right] = num++;

    right--;

    // Right to left — bottom row
    for (int i = right; i >= left; i--)
        mat[bottom][i] = num++;

    bottom--;

    // Bottom to top — left column
    for (int i = bottom; i >= top; i--)
        mat[i][left] = num++;

    left++;
}

// Print matrix
for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++)
        cout << mat[i][j] << "\t";

    cout << "\n";
}
```

### 🧠 Logic

Spiral ko 4 directions mein divide karo:

```text
1. Left → Right
2. Top → Bottom
3. Right → Left
4. Bottom → Top
```

Har complete round ke baad boundaries shrink hoti hain.

Initially:

```cpp
top = 0
bottom = n - 1
left = 0
right = n - 1
```

Phir:

```text
Top row complete     → top++
Right column complete → right--
Bottom row complete  → bottom--
Left column complete → left++
```

Yeh process tab tak chalega jab tak:

```cpp
top <= bottom && left <= right
```

### 🔑 Key Trick

Spiral Matrix ka golden concept:

> **4 boundaries ko maintain karo aur har round ke baad unhein shrink karo.**

```text
        top
   ┌────────────┐
left│            │right
   │            │
   │            │
   └────────────┘
       bottom
```

### ⭐ Why Important?

Spiral Matrix type problems DSA mein bohat useful hain, especially **2D arrays / matrices** ke questions mein.

Is pattern se tumhein:

* Matrix traversal
* Boundary handling
* Nested loops
* Direction-based traversal
* Edge cases

samajhne mein help milegi.

---

# 📋 Batch 5 — Quick Reference

| #  | Pattern       | Main Parts                      | Key Trick                |
| -- | ------------- | ------------------------------- | ------------------------ |
| 29 | Butterfly     | Left wing + spaces + right wing | `2*(n-i)`                |
| 30 | Hourglass     | Inverted + normal triangle      | 2 outer loops            |
| 31 | Cross / Plus  | Middle row + middle column      | `i == mid \|\| j == mid` |
| 32 | Arrow         | Triangle + inverted triangle    | Left-aligned             |
| 33 | Zigzag / Wave | 3 fixed rows                    | `%4` and `%2`            |
| 34 | Spiral Matrix | 4 boundaries                    | Boundaries shrink        |

---

# 🧠 Core Concepts — Batch 5

Is batch ke baad tumhein yeh concepts confidently samajhne chahiye:

### 1. Shape Decomposition

Complex shape ko simple parts mein divide karna:

```text
Butterfly
= Triangle + Spaces + Triangle
```

```text
Hourglass
= Inverted Triangle + Triangle
```

```text
Arrow
= Triangle + Inverted Triangle
```

---

### 2. Multiple Outer Loops

Jab shape ke upper aur lower parts different hon:

```cpp
for (...)
{
    // upper
}

for (...)
{
    // lower
}
```

---

### 3. Condition-Based Patterns

Cross aur Zigzag mein conditions important hain:

```cpp
if (condition)
    cout << "*";
else
    cout << " ";
```

---

### 4. Modulo `%`

Zigzag jaise patterns mein positions control karne ke liye:

```cpp
j % 2
j % 4
```

bohat useful hain.

---

### 5. Matrix Boundaries

Spiral Matrix mein 4 boundaries:

```text
top
bottom
left
right
```

maintain karna seekha.

---

# 🏆 Golden Rule — Final Version

Ab tak patterns mein sabse important skill **syntax yaad karna nahi**, balki shape ko read karna hai.

Jab koi pattern dekho:

```text
        ↓
Shape ko observe karo
        ↓
Rows aur columns identify karo
        ↓
Shape ko parts mein divide karo
        ↓
Stars / numbers / spaces ki quantity dekho
        ↓
Formula ya condition find karo
        ↓
Loops likho
        ↓
Pattern generate karo
```

> **Pattern Programming ka asli goal: "code yaad karna" nahi, "pattern ka logic dekhna" hai.**

---

# 🎯 Poora 34-Pattern Journey — Complete!

```text
Batch 1 ✅  Triangles          (P1  – P8)
Batch 2 ✅  Pyramids           (P9  – P14)
Batch 3 ✅  Number Patterns    (P15 – P22)
Batch 4 ✅  Alphabet Patterns  (P23 – P28)
Batch 5 ✅  Special Shapes     (P29 – P34)
```

## 🎉 PATTERN SECTION COMPLETE!

**34 patterns done.** 🔥

Ab next step patterns ko sirf dekhna nahi, balki **bina dekhe implement karna** hai.

---

# 🚀 Ab Kya Karna Hai?

### Step 1 — Practice

Har pattern ko bina notes dekhe khud code karo.

```text
P29 → Butterfly
P30 → Hourglass
P31 → Cross
P32 → Arrow
P33 → Zigzag
P34 → Spiral Matrix
```

### Step 2 — Debug

Jahan output galat aaye:

```text
Output dekho
   ↓
Expected vs Actual compare karo
   ↓
Loop / condition check karo
   ↓
Fix karo
```

### Step 3 — Striver Pattern Section

Ab **Striver A2Z Sheet ke Pattern Section** ko solve karo.

Tum notice karoge ke bohat se patterns wahi concepts use karte hain jo humne yahan cover kiye:

```text
Nested Loops
+
Spaces
+
Stars
+
Conditions
+
Math / Formula
```

---

# 🏁 Final Takeaway

> **Complex pattern ko kabhi complex mat samjho.**

Usay tod do:

```text
Complex Shape
      ↓
Simple Parts
      ↓
Loops
      ↓
Conditions
      ↓
Formula
      ↓
Pattern
```

**Batch 5 complete. Pattern Programming officially complete. 🔥🎯**

Ab DSA ka real safar start hota hai 🚀