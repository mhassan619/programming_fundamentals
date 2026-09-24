# 🌀 Chapter 6 — Part 2: Variable Columns & Triangle Patterns

# ⭐ Pattern 4 — Increasing Triangle

Sabse basic triangle:

```text
*
**
***
****
*****
```

Ab isko dekho carefully.

| Row (`i`) | Stars |
| --------- | ----: |
| 1         |     1 |
| 2         |     2 |
| 3         |     3 |
| 4         |     4 |
| 5         |     5 |

Notice kya hua?

> **Row number = stars ki quantity**

Isliye inner loop ki condition:

```cpp
j <= i
```

---

## Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
```

---

# 🧠 Sabse important change

Rectangle mein:

```cpp
j <= 5
```

because har row mein 5 stars.

Triangle mein:

```cpp
j <= i
```

because stars ki quantity **row number ke equal** hai.

Yani:

```text
i = 1 → j = 1       → *
i = 2 → j = 1,2     → **
i = 3 → j = 1,2,3   → ***
i = 4 → j = 1..4    → ****
```

---

# 🔥 Dry Run

Code:

```cpp
for(int i = 1; i <= 5; i++)
{
    for(int j = 1; j <= i; j++)
    {
        cout << "*";
    }

    cout << endl;
}
```

### i = 1

```text
j = 1
```

Output:

```text
*
```

### i = 2

```text
j = 1
j = 2
```

Output:

```text
**
```

### i = 3

```text
j = 1
j = 2
j = 3
```

Output:

```text
***
```

And so on.

Final:

```text
*
**
***
****
*****
```

---

# ⭐ Pattern 5 — Number Triangle

Ab stars ki jagah numbers.

Output:

```text
1
12
123
1234
12345
```

Notice:

| Row | Output  |
| --- | ------- |
| 1   | `1`     |
| 2   | `12`    |
| 3   | `123`   |
| 4   | `1234`  |
| 5   | `12345` |

Yahan bhi:

```cpp
j <= i
```

Lekin ab print karenge:

```cpp
cout << j;
```

### Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}
```

---

# 🧠 Yahan ek bohat important cheez

Pattern ki **structure** aur **printed value** do different cheezen hain.

Structure:

```cpp
for(int i = 1; i <= 5; i++)
{
    for(int j = 1; j <= i; j++)
```

same reh sakta hai.

Sirf:

```cpp
cout << "*";
```

ko change karke:

```cpp
cout << j;
```

kar diya.

Isliye pattern questions mein pehle:

> **Loop structure identify karo**

phir:

> **Kya print karna hai identify karo.**

---

# ⭐ Pattern 6 — Same Number Per Row

Ab output:

```text
1
22
333
4444
55555
```

Yahan dekho:

Row 1:

```text
1
```

Row 2:

```text
22
```

Row 3:

```text
333
```

So:

> Row number `i` decide kar raha hai **kya print hoga**.

Aur:

> `j` decide kar raha hai **kitni baar print hoga**.

Therefore:

```cpp
cout << i;
```

### Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << i;
        }

        cout << endl;
    }

    return 0;
}
```

---

# 🔥 `i` vs `j` ka difference

Ye concept **bahut important** hai.

Pattern:

```text
1
22
333
4444
```

Har row mein:

```text
quantity = i
value    = i
```

So:

```cpp
for(int i = 1; i <= 4; i++)
{
    for(int j = 1; j <= i; j++)
    {
        cout << i;
    }

    cout << endl;
}
```

---

Pattern:

```text
1
12
123
1234
```

Yahan:

```text
quantity = i
value    = j
```

So:

```cpp
cout << j;
```

---

# 🧠 Golden Question

Jab bhi number pattern aaye, khud se **2 questions** poochna:

### 1. Kitni baar print karna hai?

Ye usually `j` ki condition decide karega.

Example:

```cpp
j <= i
```

### 2. Kya print karna hai?

Ye decide karega:

```cpp
cout << ?
```

Wahan `i`, `j`, ya koi formula aa sakta hai.

---

# ⭐ Pattern 7 — Decreasing Triangle

Ab ulta:

```text
*****
****
***
**
*
```

Rows = 5.

Stars:

```text
5
4
3
2
1
```

So inner loop ki starting/ending condition change hogi.

Simple approach:

```cpp
for(int i = 5; i >= 1; i--)
{
    for(int j = 1; j <= i; j++)
    {
        cout << "*";
    }

    cout << endl;
}
```

### Dry run

```text
i = 5 → *****
i = 4 → ****
i = 3 → ***
i = 2 → **
i = 1 → *
```

Final:

```text
*****
****
***
**
*
```

---

# ⭐ Pattern 8 — Increasing then Decreasing

Ab thoda interesting:

```text
*
**
***
****
*****
****
***
**
*
```

Yahan ek single loop se directly karna possible hai, lekin beginner ke liye **2 parts** mein sochna best hai.

### Part 1

```text
*
**
***
****
*****
```

### Part 2

```text
****
***
**
*
```

Toh:

```cpp
// increasing
for(int i = 1; i <= 5; i++)
{
    for(int j = 1; j <= i; j++)
    {
        cout << "*";
    }

    cout << endl;
}

// decreasing
for(int i = 4; i >= 1; i--)
{
    for(int j = 1; j <= i; j++)
    {
        cout << "*";
    }

    cout << endl;
}
```

Output:

```text
*
**
***
****
*****
****
***
**
*
```

---

# 🧩 Complex Pattern ka Golden Rule

Ye line yaad rakhna:

> **Complex pattern = simple patterns ka combination.**

Agar pattern dekh kar confuse ho jao:

```text
     *
    ***
   *****
  *******
 *********
```

toh seedha code likhne ki koshish mat karo.

Pehle identify karo:

```text
Spaces + Stars
```

Phir dono ko separately solve karo.

Isi approach se hum aage **pyramids, hollow patterns aur special patterns** solve karenge.

---

# 📝 Aaj ka Mini Challenge

Abhi sirf logic strong karte hain.

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
Rows = ?
Stars in row = ?
Inner condition = ?
```

---

### Q2

```text
******
*****
****
***
**
*
```

Find:

```text
Rows = ?
Stars in first row = ?
Stars in last row = ?
```

---

### Q3

Output:

```text
1
22
333
4444
55555
```

Question:

`cout << i` kyun hoga aur `cout << j` kyun nahi?

---

### Q4

Output:

```text
1
12
123
1234
12345
```

Question:

`cout << i` aur `cout << j` mein se kaunsa use hoga aur **kyun?**