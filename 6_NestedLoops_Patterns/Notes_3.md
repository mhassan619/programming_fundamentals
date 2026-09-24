# 🌀 Chapter 6 — Part 3: Spaces & Right-Aligned Patterns
Abhi tak hum mostly ye kar rahe thay:

```text
*
**
***
****
*****
```

Ye **left-aligned** tha.

Ab hum stars ko right side le jayenge:

```text
    *
   **
  ***
 ****
*****
```

Aur yahin se **spaces ka game** start hota hai. 😎

---

# 🧠 Sabse pehle: Space bhi ek character hai

Agar hum likhein:

```cpp
cout << " ";
```

toh ek blank space print hoti hai.

Example:

```cpp
cout << "A";
cout << " ";
cout << "B";
```

Output visually:

```text
A B
```

Pattern printing mein hum spaces ko use karke stars ki **position** control karte hain.

---

# ⭐ Pattern 9 — Right-Aligned Triangle

Target:

```text
    *
   **
  ***
 ****
*****
```

Suppose total rows = `5`.

Ab har row mein:

| Row | Spaces | Stars |
| --- | -----: | ----: |
| 1   |      4 |     1 |
| 2   |      3 |     2 |
| 3   |      2 |     3 |
| 4   |      1 |     4 |
| 5   |      0 |     5 |

Notice:

```text
Spaces = 5 - i
Stars  = i
```

🔥 **Ye formula important hai.**

---

# 🧩 Is pattern ko 2 parts mein tod do

Har row:

```text
[spaces] + [stars]
```

For example row 2:

```text
   **
```

means:

```text
3 spaces + 2 stars
```

---

# Part 1 — Spaces

Outer loop:

```cpp
for(int i = 1; i <= 5; i++)
```

Spaces:

```cpp
for(int j = 1; j <= 5 - i; j++)
{
    cout << " ";
}
```

---

# Part 2 — Stars

```cpp
for(int j = 1; j <= i; j++)
{
    cout << "*";
}
```

---

# Complete Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 5; i++)
    {
        // spaces
        for(int j = 1; j <= 5 - i; j++)
        {
            cout << " ";
        }

        // stars
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
    *
   **
  ***
 ****
*****
```

---

# 🔥 Dry Run

## Row 1

`i = 1`

Spaces:

```text
5 - 1 = 4
```

Stars:

```text
1
```

Output:

```text
    *
```

---

## Row 2

`i = 2`

Spaces:

```text
5 - 2 = 3
```

Stars:

```text
2
```

Output:

```text
   **
```

---

## Row 3

```text
Spaces = 5 - 3 = 2
Stars  = 3
```

Output:

```text
  ***
```

---

## Row 4

```text
Spaces = 1
Stars  = 4
```

```text
 ****
```

---

## Row 5

```text
Spaces = 0
Stars  = 5
```

```text
*****
```

Final:

```text
    *
   **
  ***
 ****
*****
```

---

# 🧠 Pattern Formula

For this type:

```text
    *
   **
  ***
 ****
*****
```

Total rows = `n`

Then:

```text
Spaces = n - i
Stars  = i
```

Code structure:

```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n-i; j++)
        cout << " ";

    for(int j = 1; j <= i; j++)
        cout << "*";

    cout << endl;
}
```

---

# ⭐ Pattern 10 — Reverse Right-Aligned Triangle

Ab iska opposite:

```text
*****
 ****
  ***
   **
    *
```

Again, each row has:

```text
Spaces + Stars
```

Table:

| Row | Spaces | Stars |
| --- | -----: | ----: |
| 1   |      0 |     5 |
| 2   |      1 |     4 |
| 3   |      2 |     3 |
| 4   |      3 |     2 |
| 5   |      4 |     1 |

Notice:

```text
Spaces = i - 1
Stars = n - i + 1
```

---

## Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for(int i = 1; i <= n; i++)
    {
        // spaces
        for(int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }

        // stars
        for(int j = 1; j <= n - i + 1; j++)
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
*****
 ****
  ***
   **
    *
```

---

# 🧠 Compare dono patterns

### Pattern A

```text
    *
   **
  ***
 ****
*****
```

Formula:

```text
spaces = n - i
stars  = i
```

### Pattern B

```text
*****
 ****
  ***
   **
    *
```

Formula:

```text
spaces = i - 1
stars  = n - i + 1
```

Ye formulas **ratne ki zaroorat nahi**.

Bas table banao aur observe karo:

> Har row mein kitni spaces?
>
> Har row mein kitne stars?

Phir formula khud nikal aayega.

---

# ⭐ Pattern 11 — Number Right Triangle

Ab stars ki jagah numbers:

```text
    1
   12
  123
 1234
12345
```

Spaces exactly same:

```text
n - i
```

Stars ki jagah:

```cpp
cout << j;
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
        // spaces
        for(int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // numbers
        for(int j = 1; j <= i; j++)
        {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}
```

Output:

```text
    1
   12
  123
 1234
12345
```

---

# 🔥 Ab real pattern thinking

Pattern ko dekhte hi ye 3 questions poochna:

### 1. Rows kitni hain?

```text
i
```

### 2. Har row mein spaces kitni hain?

Usually first inner loop.

### 3. Har row mein actual characters kitne hain?

Usually second inner loop.

So right-aligned pattern ka general structure:

```cpp
for(int i = 1; i <= n; i++)
{
    // spaces
    for(...)
    {
        cout << " ";
    }

    // actual pattern
    for(...)
    {
        cout << ...;
    }

    cout << endl;
}
```

---

# 🚨 Important: `cout << " "` vs `cout << "*"`

Dono loops ka purpose alag hai.

Example:

```cpp
for(int j = 1; j <= 3; j++)
{
    cout << " ";
}
```

Ye **position** bana raha hai.

Whereas:

```cpp
for(int j = 1; j <= 2; j++)
{
    cout << "*";
}
```

Ye **shape** bana raha hai.

So:

> **Spaces position control karte hain.**
>
> **Stars/numbers actual shape banate hain.**

---

# ⭐ Pattern 12 — Full Pyramid

Ab finally pyramid:

```text
    *
   ***
  *****
 *******
*********
```

🔥 Ye pattern bohat important hai.

Ab har row mein **3 cheezen** hain:

```text
Spaces + Stars
```

Actually stars ki quantity:

```text
1
3
5
7
9
```

So:

```text
Stars = 2*i - 1
```

Spaces:

```text
Spaces = n - i
```

---

# 🧠 Table

For `n = 5`:

| `i` | Spaces | Stars |
| --- | -----: | ----: |
| 1   |      4 |     1 |
| 2   |      3 |     3 |
| 3   |      2 |     5 |
| 4   |      1 |     7 |
| 5   |      0 |     9 |

Ab pattern crystal clear hai.

---

# Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for(int i = 1; i <= n; i++)
    {
        // spaces
        for(int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // stars
        for(int j = 1; j <= 2 * i - 1; j++)
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
    *
   ***
  *****
 *******
*********
```

---

# 🧠 `2*i - 1` kyun?

Ye samajhna important hai.

Odd numbers:

```text
1
3
5
7
9
```

Har baar increase:

```text
+2
```

Formula:

```text
2i - 1
```

Check:

```text
i = 1 → 2(1)-1 = 1
i = 2 → 2(2)-1 = 3
i = 3 → 2(3)-1 = 5
i = 4 → 2(4)-1 = 7
i = 5 → 2(5)-1 = 9
```

That's why pyramid uses:

```cpp
j <= 2 * i - 1
```

---

# 🧠 Chapter 6 ka powerful method

Ab se koi bhi pattern mile, **direct code mat likhna**.

Pehle output ko break karo.

Example:

```text
    *
   ***
  *****
 *******
*********
```

### Step 1

Rows:

```text
5
```

### Step 2

Spaces:

```text
4 3 2 1 0
```

### Step 3

Stars:

```text
1 3 5 7 9
```

### Step 4

Formula:

```text
spaces = n-i
stars = 2*i-1
```

### Step 5

Code.

**Ye approach tumhein eventually unknown patterns solve karna sikhayegi.**

---

# 🎯 Aaj ka Core Concept

Ab tak tumhare paas ye 4 fundamental patterns hain:

### 1. Increasing triangle

```text
*
**
***
****
```

```text
stars = i
```

### 2. Decreasing triangle

```text
****
***
**
*
```

```text
stars = n-i+1
```

### 3. Right-aligned triangle

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

### 4. Pyramid

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

## 🧪 Mini Challenge

Ab inko **code karne se pehle** sirf table/formula derive karo:

### Q1

```text
     *
    **
   ***
  ****
 *****
******
```

Find:

```text
rows =
spaces =
stars =
```

### Q2

```text
******
 *****
  ****
   ***
    **
     *
```

### Q3

```text
     *
    ***
   *****
  *******
 *********
***********
```

Is Q3 mein specially:

```text
spaces = ?
stars = ?
```