# 🌀 Chapter 6 — Part 6: Final Pattern Challenge

Is part ka goal ab naya pattern syntax seekhna nahi hai. Goal hai:

> **Jo kuch humne seekha hai, usko use karke unfamiliar pattern khud todna aur code karna.**

---

# 🧠 Pattern-Solving Formula

Ab kisi bhi pattern ko dekh kar ye sequence follow karna:

### Step 1 — Rows

```text
Kitni rows hain?
```

### Step 2 — Har row ka structure

```text
Spaces?
Stars?
Numbers?
Characters?
```

### Step 3 — Quantity

```text
Har row mein kitne spaces?
Kitne stars?
```

### Step 4 — Formula

Examples:

```text
i
n-i
n-i+1
2*i-1
2*i
```

### Step 5 — Multiple parts?

Agar pattern complex hai:

```text
Part A + Part B + Part C
```

### Step 6 — Code

Finally nested loops.

---

# 🔥 Challenge 1 — Solid Pyramid

Output:

```text
    *
   ***
  *****
 *******
*********
```

Hum iska logic already jaante hain.

For `n = 5`:

| i | Spaces | Stars |
| - | -----: | ----: |
| 1 |      4 |     1 |
| 2 |      3 |     3 |
| 3 |      2 |     5 |
| 4 |      1 |     7 |
| 5 |      0 |     9 |

Formula:

```text
spaces = n - i
stars  = 2*i - 1
```

Code:

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        for(int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
```

---

# 🔥 Challenge 2 — Hollow Pyramid

Ab actual challenge:

```text
    *
   * *
  *   *
 *     *
*********
```

Ismein:

* Spaces before stars
* Hollow middle
* Last row completely stars

### Step 1 — Leading spaces

Same as pyramid:

```text
n - i
```

### Step 2 — Width

Total positions:

```text
2*i - 1
```

### Step 3 — Star condition

Star print karo agar:

```text
first position
OR
last position
OR
last row
```

Code:

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for(int i = 1; i <= n; i++)
    {
        // leading spaces
        for(int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // pyramid body
        for(int j = 1; j <= 2 * i - 1; j++)
        {
            if(j == 1 || j == 2 * i - 1 || i == n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
```

Output:

```text
    *
   * *
  *   *
 *     *
*********
```

---

# 🧠 Ye pattern important kyun hai?

Yahan humne **3 concepts combine** kiye:

```text
Nested loops
+
Spaces
+
Condition
```

Yani ab tum sirf fixed patterns nahi bana rahe.

Tum **position-based logic** laga rahe ho.

---

# 🔥 Challenge 3 — Diamond

Output:

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

Isko todna:

```text
Upper pyramid
+
Lower inverted pyramid
```

### Upper

```text
i = 1 → n
```

### Lower

```text
i = n-1 → 1
```

Code:

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    // Upper half
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        for(int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Lower half
    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        for(int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
```

---

# ⭐ Challenge 4 — Hollow Diamond

Ab thoda serious. 😎

Output:

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

Again:

```text
Hollow pyramid
+
Hollow inverted pyramid
```

Upper half:

```cpp
if(j == 1 || j == 2*i-1)
```

Lower half mein same boundary concept.

Code:

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    // Upper half
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        for(int j = 1; j <= 2 * i - 1; j++)
        {
            if(j == 1 || j == 2 * i - 1)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    // Lower half
    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        for(int j = 1; j <= 2 * i - 1; j++)
        {
            if(j == 1 || j == 2 * i - 1)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}
```

Output:

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

---

# 🔥 Challenge 5 — Butterfly

Ab final boss-type pattern:

```text
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
```

Break:

```text
Upper half
+
Lower half
```

And each row:

```text
left stars
+
middle spaces
+
right stars
```

---

## Upper Half

For `i = 1 → n`:

```text
left stars  = i
spaces      = 2*(n-i)
right stars = i
```

For `n = 5`:

| i | Left | Middle | Right |
| - | ---: | -----: | ----: |
| 1 |    1 |      8 |     1 |
| 2 |    2 |      6 |     2 |
| 3 |    3 |      4 |     3 |
| 4 |    4 |      2 |     4 |
| 5 |    5 |      0 |     5 |

Notice middle spaces:

```text
8, 6, 4, 2, 0
```

Formula:

```text
2 * (n - i)
```

---

## Complete Butterfly Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    // Upper half
    for(int i = 1; i <= n; i++)
    {
        // Left stars
        for(int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // Middle spaces
        for(int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }

        // Right stars
        for(int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Lower half
    for(int i = n - 1; i >= 1; i--)
    {
        // Left stars
        for(int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // Middle spaces
        for(int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }

        // Right stars
        for(int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
```

Output:

```text
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
```

---

# 🧠 Ab ek VERY important observation

Butterfly dekh kar koi kahe:

> "Bhai iska code yaad karna hai."

❌ Wrong approach.

Tumhein ye yaad hona chahiye:

```text
Butterfly
=
Left triangle
+
Middle spaces
+
Right triangle
```

Aur lower half:

```text
same thing
but decreasing
```

**That's pattern solving.**

---

# 🧩 Final Challenge 6 — Number Pyramid

Ab stars se bahar niklo.

Output:

```text
    1
   123
  12345
 1234567
123456789
```

Observe:

Spaces:

```text
4 3 2 1 0
```

Numbers:

```text
1 3 5 7 9
```

So:

```text
spaces = n-i
numbers = 2*i-1
```

And print:

```cpp
cout << j;
```

because numbers are:

```text
123...
```

Code:

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        for(int j = 1; j <= 2 * i - 1; j++)
        {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}
```

---

# 🏆 Chapter 6 — FINAL MASTER SUMMARY

Bhai, ab tumhare paas pattern solving ke ye major tools hain:

### 1. Rectangle

```text
*****
*****
*****
```

```text
rows = n
columns = m
```

---

### 2. Increasing triangle

```text
*
**
***
****
```

```text
stars = i
```

---

### 3. Decreasing triangle

```text
****
***
**
*
```

```text
stars = n-i+1
```

---

### 4. Right-aligned triangle

```text
   *
  **
 ***
****
```

```text
spaces = n-i
stars = i
```

---

### 5. Pyramid

```text
   *
  ***
 *****
*******
```

```text
spaces = n-i
stars = 2*i-1
```

---

### 6. Hollow

```text
*****
*   *
*   *
*****
```

```cpp
if(boundary)
    star;
else
    space;
```

---

### 7. Diamond

```text
Pyramid
+
Inverted Pyramid
```

---

### 8. Butterfly

```text
Left stars
+
Middle spaces
+
Right stars
```

---

# 🧠 The Ultimate Pattern Framework

Ab kisi bhi pattern ko dekh kar:

```text
             PATTERN
                ↓
             ROWS?
                ↓
       ┌────────┴────────┐
       ↓                 ↓
    SPACES?          CHARACTERS?
       ↓                 ↓
  how many spaces?   how many characters
       ↓                 ↓
    FORMULA            FORMULA
       └────────┬────────┘
                ↓
          CONDITION?
                ↓
        MULTIPLE PARTS?
                ↓
             CODE
                ↓
            DRY RUN
```

Ye **sirf pattern printing ka trick nahi** hai.

Ye actual **problem decomposition** hai — aur isi skill ki zaroorat DSA mein hogi.

---

# 🎯 Chapter 6 Status

## 🌀 Nested Loops & Patterns — **DONE ✅**

Tumne cover kiya:

* ✅ Nested loops
* ✅ Rows & columns
* ✅ Rectangle patterns
* ✅ Increasing triangles
* ✅ Decreasing triangles
* ✅ Number patterns
* ✅ Character patterns
* ✅ Spaces
* ✅ Right-aligned patterns
* ✅ Pyramids
* ✅ Hollow patterns
* ✅ Diamond
* ✅ Hollow diamond
* ✅ Butterfly
* ✅ Pattern decomposition
* ✅ `i` vs `j`
* ✅ Formula derivation
* ✅ Condition-based printing

---