# 🌀 Chapter 6 — Part 5: Hollow & Special/Tricky Patterns

> **Hollow patterns mein har position par star nahi hota — condition decide karti hai ke star print hoga ya space.**

Yahan se tumhari pattern logic aur strong hogi.

---

# ⭐ Pattern 19 — Hollow Rectangle

Target:

```text
*****
*   *
*   *
*   *
*****
```

Suppose:

```text
rows = 5
columns = 5
```

Ab observe karo:

### First row

Sab stars:

```text
*****
```

### Last row

Sab stars:

```text
*****
```

### Middle rows

Sirf first aur last column:

```text
*   *
```

---

# 🧠 Main condition

Har position `(i, j)` par star tab print hoga jab:

```text
first row
OR
last row
OR
first column
OR
last column
```

C++ condition:

```cpp
if(i == 1 || i == rows || j == 1 || j == columns)
```

Otherwise:

```cpp
cout << " ";
```

---

# Code

```cpp id="9k0t6m"
#include <iostream>
using namespace std;

int main()
{
    int rows = 5;
    int columns = 5;

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(i == 1 || i == rows || j == 1 || j == columns)
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

```text id="v5s1z4"
*****
*   *
*   *
*   *
*****
```

---

# 🧠 Isko visually samjho

Positions:

```text id="f2bq3x"
(1,1) (1,2) (1,3) (1,4) (1,5)
  *     *     *     *     *

(2,1)                 (2,5)
  *                       *

(3,1)                 (3,5)
  *                       *

(4,1)                 (4,5)
  *                       *

(5,1) (5,2) (5,3) (5,4) (5,5)
  *     *     *     *     *
```

Basically:

> **Boundary = star**
>
> **Inside = space**

---

# 🔥 Pattern 20 — Hollow Square

A square is simply:

```text
rows = columns
```

Target:

```text
****
*  *
*  *
****
```

Code:

```cpp id="9scnq5"
int n = 4;

for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n; j++)
    {
        if(i == 1 || i == n || j == 1 || j == n)
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
```

Output:

```text id="f6k3ah"
****
*  *
*  *
****
```

---

# ⭐ Pattern 21 — Hollow Triangle

Target:

```text id="h1m7q8"
*
**
* *
*  *
*****
```

Ab thoda tricky hai.

Let's analyze.

Rows:

```text
1
2
3
4
5
```

For each row, stars generally appear at:

* first position
* last position
* entire last row

So condition roughly:

```cpp id="v5i5ab"
if(j == 1 || j == i || i == n)
```

---

# Code

```cpp id="1y5wq2"
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(j == 1 || j == i || i == n)
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

```text id="c0uxw3"
*
**
* *
*  *
*****
```

---

# 🧠 Condition ko samjho

For row 4:

```text
*  *
```

Positions:

```text
j = 1 → *
j = 2 → space
j = 3 → space
j = 4 → *
```

So:

```text id="0y5f6v"
j == 1 → star
j == i → star
```

For last row:

```text
*****
```

Because:

```text id="wzv8du"
i == n
```

true hai, so **har position star**.

---

# ⭐ Pattern 22 — Hollow Inverted Triangle

Target:

```text id="n9e5r7"
*****
*  *
* *
**
*
```

Isko bhi boundary logic se solve kar sakte hain.

Outer:

```cpp id="s5f5k3"
for(int i = n; i >= 1; i--)
```

Inner:

```cpp id="v5a7iq"
for(int j = 1; j <= i; j++)
```

Boundary condition ko carefully derive karna hoga.

```cpp id="k4g7g7"
if(j == 1 || j == i || i == n)
```

Code:

```cpp id="3u9q1r"
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for(int i = n; i >= 1; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            if(j == 1 || j == i || i == n)
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

---

# 🧠 Lekin ek important point

Pattern questions mein **same-looking output** different logic se bhi ban sakta hai.

Isliye goal:

❌ "Is pattern ka exact code yaad karna"

Nahi.

Goal:

✅ "Main output ko conditions mein convert kar sakun."

Ye DSA mein bhi kaam aayega.

---

# 🔥 Special Patterns

Ab ek interesting concept:

> Complex pattern ko **multiple simple parts** mein divide karo.

Example:

```text id="9a8i9e"
*
**
***
****
***
**
*
```

Isko hum pehle hi kar chuke hain:

```text id="fj2bd4"
Increasing triangle
+
Decreasing triangle
```

Ye decomposition hai.

---

# ⭐ Pattern 23 — Diamond

Target:

```text id="2f5e3r"
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

Bhai isko dekh kar direct nested loop likhne ki zaroorat **bilkul nahi**. 😭

Break it:

### Upper half

```text id="78w8z4"
    *
   ***
  *****
 *******
*********
```

Ye hum already jaante hain:

```text
spaces = n - i
stars = 2*i - 1
```

### Lower half

```text id="pl3kq3"
 *******
  *****
   ***
    *
```

Ye reverse pyramid hai.

So:

> **Diamond = Pyramid + Reverse Pyramid**

---

# 🧠 Ye Chapter 6 ka most important skill hai

Jab complex pattern dekho:

```text
        ?
```

Don't panic.

Ask:

### Step 1

**Kya ye 2 simple patterns ka combination hai?**

### Step 2

**Har row mein spaces kitni?**

### Step 3

**Actual characters kitne?**

### Step 4

**Kya boundary condition hai?**

### Step 5

**Kya upper/lower half separate kar sakte hain?**

---

# ⭐ Pattern 24 — Butterfly

Ab ek famous pattern:

```text id="m5q9vv"
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

Bhai ye dekh kar initially scary lagta hai. 😭

Lekin:

> **Butterfly = Left Triangle + Spaces + Right Triangle**

Upper half:

```text id="2l1b9b"
*        *
**      **
***    ***
****  ****
**********
```

Left stars:

```text id="9j8r2b"
1
2
3
4
5
```

Middle spaces:

```text id="b8n8s4"
8
6
4
2
0
```

Right stars:

```text id="xknf64"
1
2
3
4
5
```

So har row:

```text id="j3j1zh"
stars + middle spaces + stars
```

🔥 Yehi decomposition approach tumhein difficult patterns mein bachayegi.

---

# 🧠 Hollow vs Solid — Core Difference

### Solid rectangle:

```text
*****
*****
*****
*****
```

Har position:

```cpp
cout << "*";
```

### Hollow rectangle:

```text
*****
*   *
*   *
*****
```

Har position:

```cpp
if(boundary)
    cout << "*";
else
    cout << " ";
```

So:

> **Solid pattern → print everywhere**
>
> **Hollow pattern → condition decide karegi**

---

# 🎯 Part 5 ka Master Concept

Pattern printing mein ab tumhare paas 4 major techniques hain:

### 1️⃣ Fixed quantity

```cpp
j <= n
```

### 2️⃣ Row-dependent quantity

```cpp
j <= i
```

### 3️⃣ Spaces + characters

```cpp
spaces
+
stars
```

### 4️⃣ Conditional printing

```cpp
if(condition)
    cout << "*";
else
    cout << " ";
```

Aur complex patterns:

```text
Simple Pattern 1
+
Simple Pattern 2
+
Simple Pattern 3
```

---

# 🧪 Final Part 5 Challenge

Code se pehle **logic** derive karna:

### Q1

```text
*****
*   *
*   *
*   *
*****
```

Boundary condition kya hogi?

---

### Q2

```text
*
**
* *
*  *
*****
```

Star condition kya hogi?

---

### Q3

```text
    *
   ***
  *****
 *******
*********
```

Spaces aur stars ke formulas?

---

### Q4

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

Isko **2 simple patterns** mein kaise divide karoge?

---

### Q5 — 🔥

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

Isko 3 components mein break karo.

---