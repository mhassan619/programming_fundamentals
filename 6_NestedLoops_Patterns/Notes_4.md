# 🌀 Chapter 6 — Part 4: Number & Character Patterns

Ab tak humne mostly `*` use kiya. Lekin nested loops sirf stars ke liye nahi hain.

Same logic se hum bana sakte hain:

* Numbers
* Characters
* Counting patterns
* Repeating patterns
* Row/column based patterns

---

# ⭐ Pattern 13 — Number Triangle

Output:

```text
1
12
123
1234
12345
```

Isko hum already dekh chuke hain, lekin ab **logic deeply** samjho.

### Table

| Row `i` | `j` values | Output  |
| ------- | ---------- | ------- |
| 1       | 1          | `1`     |
| 2       | 1,2        | `12`    |
| 3       | 1,2,3      | `123`   |
| 4       | 1,2,3,4    | `1234`  |
| 5       | 1,2,3,4,5  | `12345` |

So:

```cpp
for(int i = 1; i <= 5; i++)
{
    for(int j = 1; j <= i; j++)
    {
        cout << j;
    }

    cout << endl;
}
```

### Important:

```cpp
j <= i
```

decides **quantity**.

And:

```cpp
cout << j;
```

decides **value**.

---

# ⭐ Pattern 14 — Repeated Number Triangle

Output:

```text
1
22
333
4444
55555
```

Ab table:

| Row `i` | `j` runs | Print |
| ------- | -------- | ----- |
| 1       | 1 time   | `1`   |
| 2       | 2 times  | `2`   |
| 3       | 3 times  | `3`   |
| 4       | 4 times  | `4`   |
| 5       | 5 times  | `5`   |

Notice:

```text
quantity → i
value    → i
```

So:

```cpp
for(int i = 1; i <= 5; i++)
{
    for(int j = 1; j <= i; j++)
    {
        cout << i;
    }

    cout << endl;
}
```

---

# 🔥 Pattern 15 — Continuous Counting

Ab ek interesting one:

```text
1
23
456
78910
```

Yahan numbers **reset nahi ho rahe**.

Agar hum sirf `j` print karein:

```text
1
12
123
1234
```

toh har row mein `j` dobara `1` se start hota hai.

Humein ek separate variable chahiye:

```cpp
int num = 1;
```

Then:

```cpp
for(int i = 1; i <= 4; i++)
{
    for(int j = 1; j <= i; j++)
    {
        cout << num;
        num++;
    }

    cout << endl;
}
```

Output:

```text
1
23
456
78910
```

---

# 🧠 Yahan ek new concept

Nested loops mein sirf `i` aur `j` hi zaroori nahi.

Hum apna variable bhi rakh sakte hain:

```cpp
int num = 1;
```

Then:

```cpp
cout << num;
num++;
```

Is variable ko **outer loop ke bahar** rakha hai, isliye ye rows ke darmiyan reset nahi hota.

---

# ⭐ Pattern 16 — Character Triangle

Output:

```text
A
AB
ABC
ABCD
ABCDE
```

Exactly number triangle jaisa logic hai.

Bas:

```cpp
cout << j;
```

ki jagah character banana hai.

Ek simple way:

```cpp
cout << char('A' + j - 1);
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
            cout << char('A' + j - 1);
        }

        cout << endl;
    }

    return 0;
}
```

Output:

```text
A
AB
ABC
ABCD
ABCDE
```

---

# 🧠 `char('A' + j - 1)` kyun?

ASCII/character values ki wajah se:

```text
'A' → A
'B' → B
'C' → C
'D' → D
'E' → E
```

So:

```text
j = 1
'A' + 1 - 1 = 'A'

j = 2
'A' + 2 - 1 = 'B'

j = 3
'A' + 3 - 1 = 'C'
```

---

# ⭐ Pattern 17 — Same Character Per Row

Output:

```text
A
BB
CCC
DDDD
EEEEE
```

Yahan `j` quantity control karega aur `i` character.

```cpp
for(int i = 1; i <= 5; i++)
{
    for(int j = 1; j <= i; j++)
    {
        cout << char('A' + i - 1);
    }

    cout << endl;
}
```

Output:

```text
A
BB
CCC
DDDD
EEEEE
```

Notice again:

> `i` = row/value
> `j` = repetition/quantity

---

# 🔥 `i` vs `j` — Master Understanding

Ye table save kar lo mentally:

| Pattern        | Quantity | Print   |
| -------------- | -------- | ------- |
| `*` triangle   | `i`      | `*`     |
| `123` triangle | `i`      | `j`     |
| `111` style    | `i`      | `i`     |
| `ABC` triangle | `i`      | `A+j-1` |
| `AAA` style    | `i`      | `A+i-1` |

Yani pattern solve karte waqt:

### Question 1:

**Kitni baar print karna hai?**

→ Inner loop condition.

### Question 2:

**Kya print karna hai?**

→ `cout << ...`

---

# ⭐ Pattern 18 — Row Number + Column Number

Ab ek useful debugging pattern:

```text
11
12
13
21
22
23
31
32
33
```

Code:

```cpp
for(int i = 1; i <= 3; i++)
{
    for(int j = 1; j <= 3; j++)
    {
        cout << i << j << endl;
    }
}
```

Dry run:

```text
i = 1
    j = 1 → 11
    j = 2 → 12
    j = 3 → 13

i = 2
    j = 1 → 21
    j = 2 → 22
    j = 3 → 23
```

etc.

Isse `i` aur `j` ka relationship bohat clearly samajh aata hai.

---

# ⚠️ Ek subtle cheez

Agar likho:

```cpp
cout << i << j;
```

toh `endl` nahi hai.

Output:

```text
111213
212223
313233
```

Agar:

```cpp
cout << i << j << endl;
```

toh har pair separate line mein:

```text
11
12
13
21
22
23
31
32
33
```

Aur agar:

```cpp
cout << i << j << " ";
```

toh:

```text
11 12 13
21 22 23
31 32 33
```

So **spaces aur `endl` bhi pattern ka part hain.**

---

# 🧠 Pattern ka actual architecture

Ab tak humne jo seekha hai usko generalize karo:

```cpp
for(int i = 1; i <= rows; i++)
{
    // spaces if needed

    for(int j = 1; j <= something; j++)
    {
        cout << something;
    }

    cout << endl;
}
```

Aur complex pattern mein multiple inner loops ho sakte hain:

```cpp
for(rows)
{
    // Part 1
    for(...)
        cout << " ";

    // Part 2
    for(...)
        cout << "*";

    // Part 3
    for(...)
        cout << " ";

    cout << endl;
}
```

🔥 **Yahi technique hum hollow aur special patterns mein use karenge.**

---

# 🧪 Quick Challenge

Abhi code nahi — pehle **logic identify** karo.

### Q1

```text
1
23
456
78910
```

Batao:

* `i` kya control karega?
* `j` kya control karega?
* extra variable ki zaroorat hai?
* us variable ko kahan declare karoge?

---

### Q2

```text
A
BB
CCC
DDDD
EEEEE
```

Batao:

* quantity kis se control hogi?
* character kis se determine hoga?

---

### Q3

```text
ABCDE
ABCD
ABC
AB
A
```

Ismein:

* first row mein characters kitne?
* last row mein kitne?
* inner loop ki condition kya hogi?
* print `i` hoga ya `j`?