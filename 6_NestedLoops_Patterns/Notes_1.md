# 🌀 Chapter 6 — Nested Loops & Pattern Printing
---

# 🎯 Chapter 6 ka Goal

Is chapter ke end tak tum:

* Nested loops samjhoge
* Rows & columns ka concept samjhoge
* `i` aur `j` ka role samjhoge
* `*`, numbers aur characters ki patterns banaoge
* Triangles
* Inverted triangles
* Pyramids
* Hollow patterns
* Number patterns
* Character patterns
* Special/tricky patterns

aur sab se important:

> **Kisi bhi unknown pattern ko dekh kar uska logic khud derive kar sakoge.**

---

# Part 1 — Nested Loop kya hota hai?

Simple loop:

```cpp
for(int i = 1; i <= 3; i++)
{
    cout << i << endl;
}
```

Output:

```text
1
2
3
```

Yahan sirf **ek loop** hai.

Ab dekho:

```cpp
for(int i = 1; i <= 3; i++)
{
    for(int j = 1; j <= 4; j++)
    {
        cout << "*";
    }

    cout << endl;
}
```

Output:

```text
****
****
****
```

Yahan:

* Outer loop → rows control kar raha hai
* Inner loop → columns/items control kar raha hai

Yahi hai **nested loop**.

---

# 🧠 Sabse important rule

Isko yaad kar lo:

> **Outer loop ek row banata hai.**
>
> **Inner loop us row ke andar ki cheezen banata hai.**

Matlab:

```text
Outer loop
    ↓
Row 1 → inner loop runs
Row 2 → inner loop runs
Row 3 → inner loop runs
```

Aur har row ke andar inner loop **poora** run hota hai.

---

# 🔥 Dry Run

Code:

```cpp
for(int i = 1; i <= 3; i++)
{
    for(int j = 1; j <= 4; j++)
    {
        cout << "*";
    }

    cout << endl;
}
```

### Step 1

`i = 1`

Inner loop:

```text
j = 1 → *
j = 2 → *
j = 3 → *
j = 4 → *
```

Row complete:

```text
****
```

---

### Step 2

Outer loop:

```text
i = 2
```

Inner loop **dobara zero se start**:

```text
j = 1 → *
j = 2 → *
j = 3 → *
j = 4 → *
```

Row:

```text
****
```

---

### Step 3

```text
i = 3
```

Again:

```text
****
```

Final:

```text
****
****
****
```

---

# ⚠️ Ek bohat important concept

Ye mat sochna:

> `i = 1`, phir `j = 1`, phir `i = 2`, phir `j = 2`...

Aisa nahi hota.

Actually:

```text
i = 1
    j = 1
    j = 2
    j = 3
    j = 4

i = 2
    j = 1
    j = 2
    j = 3
    j = 4

i = 3
    j = 1
    j = 2
    j = 3
    j = 4
```

**Outer loop ki ek iteration ke andar inner loop complete hota hai.**

---

# 🧩 Part 2 — Rows & Columns

Ab pattern ko ek matrix ki tarah dekho.

```text
* * * *
* * * *
* * * *
```

Ismein:

* Rows = `3`
* Columns = `4`

Hum isko table ki tarah imagine kar sakte hain:

```text
        j
       1 2 3 4
i=1    * * * *
i=2    * * * *
i=3    * * * *
```

Yahan:

```cpp
i → row
j → column
```

Usually pattern questions mein:

```cpp
i = rows
j = columns
```

Ye convention bohat useful hai.

---

# ⭐ Pattern 1 — Rectangle

Question:

> 4 rows aur 5 columns ke stars print karo.

### Step 1: Rows

4 rows chahiye:

```cpp
for(int i = 1; i <= 4; i++)
```

### Step 2: Har row mein 5 stars

```cpp
for(int j = 1; j <= 5; j++)
```

### Complete code

```cpp
#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 5; j++)
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
*****
*****
*****
```

---

# 🧠 Is code ko ek sentence mein samjho

```cpp
for(int i = 1; i <= 4; i++)
```

means:

> **4 rows banao.**

Aur:

```cpp
for(int j = 1; j <= 5; j++)
```

means:

> **Har row mein 5 stars banao.**

Bas! Pattern printing ka foundation yahi hai.

---

# ⭐ Pattern 2 — 3 × 3

Question:

```text
***
***
***
```

Rows = `3`

Columns = `3`

```cpp
for(int i = 1; i <= 3; i++)
{
    for(int j = 1; j <= 3; j++)
    {
        cout << "*";
    }

    cout << endl;
}
```

---

# ⭐ Pattern 3 — 5 × 2

Question:

```text
**
**
**
**
**
```

Rows = `5`

Columns = `2`

```cpp
for(int i = 1; i <= 5; i++)
{
    for(int j = 1; j <= 2; j++)
    {
        cout << "*";
    }

    cout << endl;
}
```

---

# 🚨 Pattern Printing ka Golden Rule

Bhai isko **strongly yaad** kar lo:

### Agar output mein new line aa rahi hai:

```cpp
cout << endl;
```

usually **outer loop ke andar**, lekin **inner loop ke baad** hogi.

Example:

```cpp
for(rows)
{
    for(columns)
    {
        cout << "*";
    }

    cout << endl;
}
```

Why?

Because pehle **poori row** print hogi:

```text
*****
```

phir:

```cpp
cout << endl;
```

next row par jayega.

Agar `endl` inner loop ke andar laga diya:

```cpp
for(int i = 1; i <= 4; i++)
{
    for(int j = 1; j <= 5; j++)
    {
        cout << "*" << endl;
    }
}
```

Output hoga:

```text
*
*
*
*
*
*
*
*
*
*
...
```

Kyunkay har star ke baad new line aa rahi hai.

---

# 🧪 Mini Dry Run

Code:

```cpp
for(int i = 1; i <= 2; i++)
{
    for(int j = 1; j <= 3; j++)
    {
        cout << "*";
    }

    cout << endl;
}
```

Trace:

| `i` | `j` values | Output |
| --- | ---------- | ------ |
| 1   | 1,2,3      | `***`  |
| 2   | 1,2,3      | `***`  |

Final:

```text
***
***
```

---

# 🔥 Ab ek important mindset

Pattern questions ko **"stars kaise print karun?"** ke perspective se mat dekho.

Is tarah dekho:

> **Mujhe kitni rows chahiye?**
>
> **Har row mein kitni cheezen chahiye?**

For example:

```text
*****
*****
*****
*****
```

Tum immediately bolo:

```text
Rows = 4
Columns = 5
```

Then:

```cpp
for(int i = 1; i <= 4; i++)
{
    for(int j = 1; j <= 5; j++)
    {
        cout << "*";
    }

    cout << endl;
}
```

That's it.

---

# 🧠 Chapter 6 ka First Formula

Basic rectangle pattern:

```cpp
for(int i = 1; i <= rows; i++)
{
    for(int j = 1; j <= columns; j++)
    {
        cout << "*";
    }

    cout << endl;
}
```

Is formula ko **ratta nahi**, samjho:

```text
i → how many rows?
j → how many things in each row?
```

---

## 📝 Ab tumhari first practice

Without looking at the code above, ye 3 patterns khud try karo:

### Q1

```text
****
****
****
****
****
```

### Q2

```text
******
******
******
```

### Q3

```text
**
**
**
**
**
**
**
```

Har question mein pehle mujhe ye batao:

```text
Rows = ?
Columns = ?
```

Phir code likhna.