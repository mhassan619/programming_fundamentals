# 📘 Chapter 5 — Loops

## Part A — Loop hota kya hai?

Simple:

> **Loop ka matlab hai kisi kaam ko repeatedly perform karna jab tak condition satisfy ho.**

For example agar humein:

```text
1
2
3
4
5
```

print karna ho.

Without loop:

```cpp
cout << 1 << endl;
cout << 2 << endl;
cout << 3 << endl;
cout << 4 << endl;
cout << 5 << endl;
```

Ye obviously repetitive hai.

Loop:

```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << endl;
}
```

Bas ek chhota sa code aur kaam ho gaya.

---

# Part B — Loop ke 3 Basic Components

Har loop mein generally 3 important cheezein hoti hain:

```text
Initialization
      ↓
Condition
      ↓
Update
```

Example:

```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << endl;
}
```

### 1. Initialization

```cpp
int i = 1;
```

Yahan hum kehte hain:

> "Loop kahan se start hoga?"

---

### 2. Condition

```cpp
i <= 5
```

Ye decide karegi:

> "Loop abhi chalna chahiye ya nahi?"

---

### 3. Update

```cpp
i++
```

Ye decide karta hai:

> "Har iteration ke baad kya change hoga?"

---

# Part C — `for` Loop

Sabse pehle `for` loop.

Syntax:

```cpp
for (initialization; condition; update) {
    // body
}
```

Example:

```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << endl;
}
```

---

# 🧠 Isko computer ki tarah dry run karo

Code:

```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << endl;
}
```

### Step 1

```text
i = 1
```

Condition:

```text
1 <= 5 → true
```

Print:

```text
1
```

Update:

```text
i++
```

Now:

```text
i = 2
```

---

### Step 2

```text
2 <= 5 → true
```

Print:

```text
2
```

Update:

```text
i = 3
```

---

Same process:

```text
i = 3 → print 3
i = 4 → print 4
i = 5 → print 5
```

Then:

```text
i = 6
```

Condition:

```text
6 <= 5 → false
```

Loop stops.

### Final output

```text
1
2
3
4
5
```

---

# 🔥 Most Important Loop Flow

Ye diagram yaad kar lo:

```text
Initialization
      ↓
   Condition
      ↓
   true?
   ↙    ↘
 yes     no
  ↓       ↓
 Body     STOP
  ↓
Update
  ↓
Condition
```

Notice:

> **Update ke baad wapas condition check hoti hai.**

---

# Part D — `i++` ka role

Agar:

```cpp
for (int i = 1; i <= 5; i++)
```

mein `i++` na ho:

```cpp
for (int i = 1; i <= 5;) {
    cout << i;
}
```

To `i` hamesha `1` rahega.

Condition:

```text
1 <= 5
```

hamesha true.

Result:

> ❌ Infinite loop

Isliye update bohat important hai.

---

# Part E — Different Directions

Sirf increasing loop nahi hota.

### 1 → 5

```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}
```

Output:

```text
1 2 3 4 5
```

### 5 → 1

```cpp
for (int i = 5; i >= 1; i--) {
    cout << i << " ";
}
```

Output:

```text
5 4 3 2 1
```

Yahan:

```text
initialization = 5
condition      = i >= 1
update         = i--
```

---

# Part F — Different Step Sizes

### Even numbers

```cpp
for (int i = 2; i <= 10; i += 2) {
    cout << i << " ";
}
```

Output:

```text
2 4 6 8 10
```

### 5 ke multiples

```cpp
for (int i = 5; i <= 25; i += 5) {
    cout << i << " ";
}
```

Output:

```text
5 10 15 20 25
```

### Reverse even numbers

```cpp
for (int i = 10; i >= 2; i -= 2) {
    cout << i << " ";
}
```

Output:

```text
10 8 6 4 2
```

---

# Part G — Loop ke andar multiple statements

Loop body mein multiple statements ho sakti hain:

```cpp
for (int i = 1; i <= 3; i++) {
    cout << "Number: ";
    cout << i << endl;
}
```

Output:

```text
Number: 1
Number: 2
Number: 3
```

Braces `{}` yahan important hain because dono statements loop ka part hain.

---

# Part H — `while` Loop

Ab second major loop.

Syntax:

```cpp
while (condition) {
    // body
}
```

Example:

```cpp
int i = 1;

while (i <= 5) {
    cout << i << endl;
    i++;
}
```

Output:

```text
1
2
3
4
5
```

### Difference?

`for`:

```cpp
for (int i = 1; i <= 5; i++)
```

`while`:

```cpp
int i = 1;

while (i <= 5) {
    ...
    i++;
}
```

Logic basically same hai.

---

# Part I — `for` vs `while`

### `for`

Jab iterations ka pattern relatively clear ho:

```cpp
for (int i = 1; i <= 100; i++)
```

Usually convenient.

### `while`

Jab loop kisi condition ke based chale aur number of iterations beforehand clear na ho.

Example:

```cpp
while (password != correctPassword) {
    // try again
}
```

Simple rule:

> **Known/count-controlled → `for` often convenient.**
> **Condition-controlled → `while` often convenient.**

Lekin ye strict rule nahi hai. Dono se bohat se same problems solve ho sakte hain.

---

# Part J — `do-while`

Third loop:

```cpp
do {
    // body
} while (condition);
```

Example:

```cpp
int i = 1;

do {
    cout << i << endl;
    i++;
} while (i <= 5);
```

Output:

```text
1
2
3
4
5
```

---

# 🚨 `while` vs `do-while` ka MAIN difference

Ye bohat important hai.

### `while`

Pehle condition:

```text
Condition
   ↓
true?
 ↓
Body
```

### `do-while`

Pehle body:

```text
Body
 ↓
Condition
 ↓
true?
```

Matlab:

> **`do-while` body ko kam az kam ek baar zaroor execute karta hai.**

---

## Example

```cpp
int x = 10;

while (x < 5) {
    cout << "Hello";
}
```

Condition pehle hi false:

```text
10 < 5 → false
```

Output:

```text
Nothing
```

Lekin:

```cpp
int x = 10;

do {
    cout << "Hello";
} while (x < 5);
```

Pehle `Hello` print hoga.

Phir condition check:

```text
10 < 5 → false
```

So output:

```text
Hello
```

🔥 Ye `do-while` ka core concept hai.

---

# Part K — Loop Counter

Ek common pattern:

```cpp
int count = 0;

for (int i = 1; i <= 10; i++) {
    count++;
}

cout << count;
```

Output:

```text
10
```

Yahan `count` number of occurrences/iterations track kar raha hai.

Ye concept baad mein bohat use hoga:

* count even numbers
* count positive numbers
* count digits
* count vowels
* count occurrences
* count array elements satisfying condition

---

# Part L — Sum using Loop

1 se 5 tak sum:

```cpp
int sum = 0;

for (int i = 1; i <= 5; i++) {
    sum = sum + i;
}

cout << sum;
```

Dry run:

| i     | sum |
| ----- | --: |
| start |   0 |
| 1     |   1 |
| 2     |   3 |
| 3     |   6 |
| 4     |  10 |
| 5     |  15 |

Output:

```text
15
```

Yahan ek **accumulator pattern** introduce hua:

```text
sum = old sum + current value
```

Ye DSA mein extremely important pattern hai.

---

# 🧠 Abhi tak ke Core Patterns

Loops mein ye 4 patterns yaad rakho:

### 1. Printing

```cpp
for (...) {
    cout << i;
}
```

### 2. Counting

```cpp
count++;
```

### 3. Accumulation

```cpp
sum += i;
```

### 4. Condition-based processing

```cpp
if (i % 2 == 0) {
    ...
}
```

Aur in patterns ko combine karke actual problems banti hain.

---

# 🔥 Mini Practice — abhi theory ke baad

Inko **code se pehle dry run mentally** karna:

### Q1

```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}
```

Output?

### Q2

```cpp
for (int i = 10; i >= 1; i -= 2) {
    cout << i << " ";
}
```

Output?

### Q3

```cpp
int sum = 0;

for (int i = 1; i <= 4; i++) {
    sum += i;
}

cout << sum;
```

Output?

### Q4

```cpp
int i = 5;

while (i > 0) {
    cout << i << " ";
    i--;
}
```

Output?

### Q5 🔥

```cpp
int x = 10;

do {
    cout << x;
} while (x < 5);
```

Output?

**Q5 especially dekho — `do-while` ki wajah se kya hoga.**

# 📘 Chapter 5 — Part 2: Loop Control & Core Patterns

---

## Part M — `break`

`break` ka matlab:

> **Loop ko foran terminate kar do.**

Example:

```cpp
for (int i = 1; i <= 10; i++) {
    if (i == 5)
        break;

    cout << i << " ";
}
```

### Dry Run

```text
i = 1 → print 1
i = 2 → print 2
i = 3 → print 3
i = 4 → print 4
i = 5 → break
```

Output:

```text
1 2 3 4
```

Notice:

`i == 5` par `break` execute hua, isliye `5` print nahi hua.

### Golden rule:

```text
break = poora loop khatam
```

---

# Part N — `continue`

`continue` ka matlab:

> **Current iteration skip karo, lekin loop continue rakho.**

Example:

```cpp
for (int i = 1; i <= 5; i++) {

    if (i == 3)
        continue;

    cout << i << " ";
}
```

Dry run:

```text
1 → print
2 → print
3 → continue → skip
4 → print
5 → print
```

Output:

```text
1 2 4 5
```

### Difference 🔥

| Statement  | Kaam                   |
| ---------- | ---------------------- |
| `break`    | poora loop stop        |
| `continue` | current iteration skip |

---

# ⚠️ `continue` ka tricky point

Ye `while` loop mein specially important hai.

Example:

```cpp
int i = 1;

while (i <= 5) {

    if (i == 3) {
        continue;
    }

    cout << i;
    i++;
}
```

Problem?

Jab:

```text
i = 3
```

hoga:

```cpp
continue;
```

execute hoga.

`i++` tak pohanchega hi nahi.

So `i` **3 hi rahega**.

Result:

> ❌ Infinite loop.

Isliye `while` + `continue` use karte waqt update ko carefully place karna.

---

# Part O — Counting Pattern

Suppose:

> 1 se 10 tak kitne even numbers hain?

```cpp
int count = 0;

for (int i = 1; i <= 10; i++) {

    if (i % 2 == 0)
        count++;
}

cout << count;
```

### Dry run

Even numbers:

```text
2
4
6
8
10
```

So:

```text
count = 5
```

Output:

```text
5
```

### Important pattern

```cpp
if (condition)
    count++;
```

Ye pattern bohat important hai.

---

# Part P — Sum of Even Numbers

Ab sirf count nahi, sum chahiye:

> 1 se 10 tak even numbers ka sum.

```cpp
int sum = 0;

for (int i = 1; i <= 10; i++) {

    if (i % 2 == 0)
        sum += i;
}

cout << sum;
```

Calculation:

```text
2 + 4 + 6 + 8 + 10 = 30
```

Output:

```text
30
```

### Difference samjho:

Count:

```cpp
count++;
```

Sum:

```cpp
sum += i;
```

---

# Part Q — Product / Multiplication Pattern

Suppose:

```text
1 × 2 × 3 × 4 × 5
```

Product calculate karna hai.

```cpp
int product = 1;

for (int i = 1; i <= 5; i++) {
    product *= i;
}

cout << product;
```

Output:

```text
120
```

### Important 🔥

Sum ke liye:

```cpp
int sum = 0;
```

Product ke liye:

```cpp
int product = 1;
```

Kyun?

Agar:

```cpp
int product = 0;
```

then:

```text
0 × anything = 0
```

poora result zero ho jayega.

---

# Part R — Loop + Input

Loops ka actual use tab start hota hai jab user multiple values enter kare.

Example:

> 5 numbers input lo aur unka sum nikalo.

```cpp
int sum = 0;

for (int i = 1; i <= 5; i++) {

    int x;
    cin >> x;

    sum += x;
}

cout << sum;
```

Input:

```text
10 20 5 3 2
```

Dry run:

```text
sum = 0

10 → sum = 10
20 → sum = 30
5  → sum = 35
3  → sum = 38
2  → sum = 40
```

Output:

```text
40
```

### Important concept

Loop ki har iteration mein:

```cpp
cin >> x;
```

ek naya value leta hai.

---

# Part S — Count Positive Numbers

Problem:

> 5 integers input lo aur count karo kitne positive hain.

```cpp
int count = 0;

for (int i = 1; i <= 5; i++) {

    int x;
    cin >> x;

    if (x > 0)
        count++;
}

cout << count;
```

Input:

```text
-2 5 0 7 -3
```

Check:

```text
-2 → no
 5 → yes → count = 1
 0 → no
 7 → yes → count = 2
-3 → no
```

Output:

```text
2
```

---

# Part T — Find Maximum using Loop

Ye bohat important pattern hai.

Problem:

> 5 numbers input lo aur maximum find karo.

```cpp
int x;
cin >> x;

int maximum = x;

for (int i = 2; i <= 5; i++) {

    cin >> x;

    if (x > maximum)
        maximum = x;
}

cout << maximum;
```

### Why first value separately?

Hum initially bolte hain:

```cpp
maximum = first number;
```

Phir baaki numbers compare karte hain.

Suppose input:

```text
8 3 15 6 11
```

Dry run:

```text
maximum = 8

3 > 8  → false
15 > 8 → true → maximum = 15
6 > 15 → false
11 > 15 → false
```

Final:

```text
15
```

---

# 🔥 Important: `maximum = 0` kyun dangerous ho sakta hai?

Agar tum likho:

```cpp
int maximum = 0;
```

aur input ho:

```text
-5 -2 -10
```

To:

```text
-5 > 0 → false
-2 > 0 → false
-10 > 0 → false
```

Maximum incorrectly:

```text
0
```

aa jayega.

Lekin `0` input mein tha hi nahi.

Isliye general solution:

> **Maximum ko first actual value se initialize karo.**

```cpp
maximum = first value;
```

Ye bohat important problem-solving habit hai.

---

# Part U — Minimum bhi Same Pattern

```cpp
int x;
cin >> x;

int minimum = x;

for (int i = 2; i <= 5; i++) {

    cin >> x;

    if (x < minimum)
        minimum = x;
}

cout << minimum;
```

Maximum:

```cpp
if (x > maximum)
```

Minimum:

```cpp
if (x < minimum)
```

Bas comparison reverse.

---

# Part V — Nested Loops 🔥

Ab important concept.

> **Loop ke andar loop = nested loop.**

Example:

```cpp
for (int i = 1; i <= 3; i++) {

    for (int j = 1; j <= 2; j++) {
        cout << "Hello ";
    }

    cout << endl;
}
```

Output:

```text
Hello Hello
Hello Hello
Hello Hello
```

---

# 🧠 Nested Loop kaise sochna hai?

Outer loop:

```text
i = 1
```

Inner loop complete chalega:

```text
j = 1
j = 2
```

Phir:

```text
i = 2
```

Inner loop **dobara start** hoga:

```text
j = 1
j = 2
```

Phir `i = 3`.

So total inner executions:

```text
3 × 2 = 6
```

---

# Part W — Nested Loop Dry Run

Code:

```cpp
for (int i = 1; i <= 2; i++) {

    for (int j = 1; j <= 3; j++) {
        cout << i << "," << j << endl;
    }
}
```

Output:

```text
1,1
1,2
1,3
2,1
2,2
2,3
```

Observe:

```text
i = 1
    j = 1
    j = 2
    j = 3

i = 2
    j = 1
    j = 2
    j = 3
```

### Golden rule 🔥

> **Outer loop ki ek iteration ke liye inner loop apni complete journey karta hai.**

Ye patterns aur 2D arrays ke liye foundation hai.

---

# Part X — Nested Loop ka Common Trap

Ye:

```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        cout << "*";
    }
}
```

`3 × 3 = 9` stars print karega.

Output conceptually:

```text
*********
```

Kyun?

Kyunkay abhi newline nahi hai.

Agar:

```cpp
for (int i = 1; i <= 3; i++) {

    for (int j = 1; j <= 3; j++) {
        cout << "*";
    }

    cout << endl;
}
```

then:

```text
***
***
***
```

Yehi nested loops aage **pattern printing** ka base banenge.

---

# 🧠 Part Y — Loop Complexity ka First Introduction

Agar:

```cpp
for (int i = 1; i <= n; i++) {
    cout << i;
}
```

to loop approximately `n` times chalta hai.

So:

```text
Time Complexity = O(n)
```

Agar:

```cpp
for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= n; j++) {
        cout << "*";
    }
}
```

Outer:

```text
n
```

Inner:

```text
n
```

Total:

```text
n × n = n²
```

So:

```text
O(n²)
```

Abhi complexity ko deeply nahi karenge; bas intuition build kar rahe hain.

---

# 🚨 Part Z — Common Loop Mistakes

### Mistake 1: Update bhool jana

```cpp
while (i <= 10) {
    cout << i;
}
```

❌ Infinite loop.

---

### Mistake 2: Wrong condition

```cpp
for (int i = 1; i >= 10; i++)
```

Start:

```text
1 >= 10 → false
```

Loop **ek baar bhi nahi chalega**.

---

### Mistake 3: `<=` vs `<`

```cpp
for (int i = 1; i <= 5; i++)
```

prints:

```text
1 2 3 4 5
```

while:

```cpp
for (int i = 1; i < 5; i++)
```

prints:

```text
1 2 3 4
```

Boundary carefully check karo.

---

### Mistake 4: Wrong update direction

```cpp
for (int i = 10; i >= 1; i++)
```

Yahan `i++` ho raha hai.

So:

```text
10
11
12
13
...
```

Condition `i >= 1` continuously true rahegi.

❌ Infinite loop.

Correct:

```cpp
i--
```

---

# 🔥 Ab Tumhari Turn — Part 2 Challenge

Pehle **dry run**, phir code.

### Q1

1 se 20 tak **even numbers** print karo.

Expected:

```text
2 4 6 8 10 12 14 16 18 20
```

---

### Q2

1 se 50 tak **odd numbers ka sum** find karo.

---

### Q3

10 integers input lo aur batao:

```text
Kitne positive?
Kitne negative?
Kitne zero?
```

---

### Q4 🔥

10 numbers input lo aur:

```text
maximum
minimum
```

dono find karo.

**Important:** all numbers negative bhi ho sakte hain.

---

### Q5 🔥 Nested Loop

Ye output generate karo:

```text
1 2 3
1 2 3
1 2 3
1 2 3
```

---

### Q6 — Output Question

Output batao:

```cpp
int count = 0;

for (int i = 1; i <= 10; i++) {

    if (i % 2 == 0)
        count++;
}

cout << count;
```

---

### Q7 — Tricky 🔥

Output kya hoga?

```cpp
for (int i = 1; i <= 5; i++) {

    if (i == 3)
        continue;

    cout << i << " ";
}
```

---

### Q8 — Tricky 🔥🔥

Output:

```cpp
for (int i = 1; i <= 5; i++) {

    if (i == 3)
        break;

    cout << i << " ";
}
```

**Q7 aur Q8 ka difference especially samajhna.**

# 📘 Chapter 5 — Part 3

## Number Problems + Loop Thinking

Sab se pehle ek bohat important concept:

> **Number ke digits ko process karne ke liye `/ 10` aur `% 10` hamare main tools hain.**

---

# Part AA — Last Digit nikalna

Suppose:

```text
n = 5837
```

Last digit chahiye.

Use:

```cpp
n % 10
```

Because:

```text
5837 % 10 = 7
```

So:

```cpp
int digit = n % 10;
```

`digit = 7`

---

# Part AB — Last Digit Remove karna

Agar:

```text
n = 5837
```

aur:

```cpp
n /= 10;
```

to:

```text
5837 / 10 = 583
```

Phir:

```text
583 / 10 = 58
58 / 10 = 5
5 / 10 = 0
```

So:

> `% 10` → last digit **nikalo**
> `/ 10` → last digit **remove karo**

🔥 Ye pair bohat important hai.

---

# Part AC — Number ke Digits Print Karna

Problem:

```text
5837
```

ke digits print karo.

```cpp
int n = 5837;

while (n > 0) {
    cout << n % 10 << " ";
    n /= 10;
}
```

Dry run:

```text
n = 5837
n % 10 = 7
n /= 10 → 583

n = 583
n % 10 = 3
n /= 10 → 58

n = 58
n % 10 = 8
n /= 10 → 5

n = 5
n % 10 = 5
n /= 10 → 0
```

Output:

```text
7 3 8 5
```

Notice:

> Digits **reverse order** mein aaye.

Original:

```text
5 8 3 7
```

Output:

```text
7 3 8 5
```

Kyun? Because hum **last digit se start** kar rahe hain.

---

# Part AD — Sum of Digits 🔥

Problem:

```text
5837
```

Sum:

```text
5 + 8 + 3 + 7 = 23
```

Code:

```cpp
int n = 5837;
int sum = 0;

while (n > 0) {

    int digit = n % 10;

    sum += digit;

    n /= 10;
}

cout << sum;
```

### Dry Run

|    n | digit | sum |
| ---: | ----: | --: |
| 5837 |     7 |   7 |
|  583 |     3 |  10 |
|   58 |     8 |  18 |
|    5 |     5 |  23 |
|    0 |  stop |  23 |

Output:

```text
23
```

### Pattern:

```cpp
digit = n % 10;
sum += digit;
n /= 10;
```

Is 3-line pattern ko **strongly yaad** rakho.

---

# Part AE — Count Digits

Problem:

```text
5837
```

mein kitne digits hain?

Answer:

```text
4
```

Code:

```cpp
int n = 5837;
int count = 0;

while (n > 0) {

    count++;

    n /= 10;
}

cout << count;
```

Dry run:

```text
5837 → count 1
583  → count 2
58   → count 3
5    → count 4
0    → stop
```

Output:

```text
4
```

---

# ⚠️ Zero ka Edge Case

Agar:

```text
n = 0
```

aur code:

```cpp
while (n > 0)
```

hai, loop chalega hi nahi.

So `count = 0` hi rahega.

Lekin mathematically `0` mein **1 digit** hai.

Isliye:

```cpp
if (n == 0)
    count = 1;
else {
    while (n > 0) {
        count++;
        n /= 10;
    }
}
```

Ye edge case yaad rakhna.

---

# Part AF — Reverse Number 🔥

Ab:

```text
5837
```

ko reverse karna hai:

```text
7385
```

Formula:

```cpp
reverse = reverse * 10 + digit;
```

Complete:

```cpp
int n = 5837;
int reverse = 0;

while (n > 0) {

    int digit = n % 10;

    reverse = reverse * 10 + digit;

    n /= 10;
}

cout << reverse;
```

### Dry Run

Start:

```text
reverse = 0
```

### First digit

```text
digit = 7
reverse = 0 * 10 + 7
        = 7
```

### Second

```text
digit = 3
reverse = 7 * 10 + 3
        = 73
```

### Third

```text
digit = 8
reverse = 73 * 10 + 8
        = 738
```

### Fourth

```text
digit = 5
reverse = 738 * 10 + 5
        = 7385
```

Final:

```text
7385
```

---

# 🧠 Reverse Formula ko samjho

Ye random formula nahi hai.

Agar current reverse:

```text
73
```

hai aur next digit:

```text
8
```

hai.

Humein `73` ko left shift karke:

```text
730
```

banana hai.

Isliye:

```text
73 × 10 = 730
```

phir:

```text
730 + 8 = 738
```

So:

```text
reverse = reverse * 10 + digit
```

---

# Part AG — Palindrome Number

Palindrome woh number jo reverse karne par same rahe.

Examples:

```text
121 → 121
1331 → 1331
555 → 555
```

Non-palindrome:

```text
123 → 321
```

Approach:

1. Original number save karo.
2. Reverse nikalo.
3. Compare karo.

```cpp
int n;
cin >> n;

int original = n;
int reverse = 0;

while (n > 0) {

    int digit = n % 10;

    reverse = reverse * 10 + digit;

    n /= 10;
}

if (original == reverse)
    cout << "Palindrome";
else
    cout << "Not Palindrome";
```

### Dry Run

Input:

```text
121
```

Original:

```text
121
```

Reverse:

```text
121
```

Comparison:

```text
121 == 121 → true
```

Output:

```text
Palindrome
```

---

# Part AH — Factors of a Number

Ab ek different type ka loop.

Suppose:

```text
n = 12
```

Factors:

```text
1 2 3 4 6 12
```

Hum check kar sakte hain:

```cpp
for (int i = 1; i <= n; i++) {

    if (n % i == 0)
        cout << i << " ";
}
```

Why?

Agar:

```text
12 % 3 == 0
```

to 3 factor hai.

Agar:

```text
12 % 5 != 0
```

to 5 factor nahi hai.

---

# Part AI — Prime Number using Loop

Ab previous PF concept ko loop ke saath connect karte hain.

Prime number:

> Number greater than 1 jiske exactly 2 positive factors hon: 1 aur itself.

Simple beginner approach:

```cpp
int n;
cin >> n;

int count = 0;

for (int i = 1; i <= n; i++) {

    if (n % i == 0)
        count++;
}

if (count == 2)
    cout << "Prime";
else
    cout << "Not Prime";
```

Example:

```text
n = 7
```

Factors:

```text
1, 7
```

count:

```text
2
```

So:

```text
Prime
```

---

# 🔥 Better Prime Approach

Upar wala correct hai, lekin unnecessarily `1` se `n` tak check karta hai.

Hum sirf:

```text
2 → √n
```

tak check kar sakte hain.

Without math library, condition:

```cpp
i * i <= n
```

Example:

```cpp
bool isPrime = true;

if (n < 2) {
    isPrime = false;
}
else {
    for (int i = 2; i * i <= n; i++) {

        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
}

if (isPrime)
    cout << "Prime";
else
    cout << "Not Prime";
```

### Why `break`?

Suppose:

```text
n = 15
```

`i = 3`:

```text
15 % 3 == 0
```

Humein already pata chal gaya:

> 15 prime nahi hai.

Ab baaki values check karne ka koi faida nahi.

So:

```cpp
break;
```

loop immediately stop kar deta hai.

---

# Part AJ — `break` ka Real Use

Ye example important hai:

```cpp
for (int i = 2; i * i <= n; i++) {

    if (n % i == 0) {
        isPrime = false;
        break;
    }
}
```

Yahan:

```text
break
```

ka matlab:

> "Mujhe answer mil gaya. Ab further searching ki zaroorat nahi."

Ye DSA mein bohat common idea hai.

---

# Part AK — First Matching Value

Suppose:

> 1 se 100 tak pehla number find karo jo 7 se divisible ho.

```cpp
for (int i = 1; i <= 100; i++) {

    if (i % 7 == 0) {
        cout << i;
        break;
    }
}
```

First match:

```text
7
```

Output:

```text
7
```

Pattern:

```text
search
 ↓
match?
 ↓
yes → process + break
```

Ye future mein **linear search** ke concept se connect hoga.

---

# Part AL — Loop + Conditions Combined

Ab dekho loop aur Chapter 4 ka conditional knowledge kaise combine hota hai.

Problem:

> 1 se 20 tak numbers mein kitne even aur kitne odd hain?

```cpp
int even = 0;
int odd = 0;

for (int i = 1; i <= 20; i++) {

    if (i % 2 == 0)
        even++;
    else
        odd++;
}

cout << "Even: " << even << endl;
cout << "Odd: " << odd;
```

Result:

```text
Even: 10
Odd: 10
```

Yahan:

```text
Loop → numbers generate/process
Condition → classify
Counter → result store
```

Ye **problem-solving ka core pattern** hai.

---

# Part AM — Multiple Conditions inside Loop

Problem:

> 1 se 100 tak kitne numbers 3 aur 5 dono se divisible hain?

```cpp
int count = 0;

for (int i = 1; i <= 100; i++) {

    if (i % 3 == 0 && i % 5 == 0)
        count++;
}

cout << count;
```

Numbers:

```text
15, 30, 45, 60, 75, 90
```

Total:

```text
6
```

Notice:

```cpp
&&
```

jo hum Chapter 4 mein seekh chuke hain, ab loop ke andar use ho raha hai.

---

# 🧠 Part AN — Loop Problem ko Todne ka Formula

Jab koi number-loop problem aaye, ye questions pucho:

### Step 1

**Kya mujhe number repeatedly process karna hai?**

Agar haan:

```cpp
while
```

often useful.

### Step 2

**Last digit chahiye?**

```cpp
n % 10
```

### Step 3

**Last digit remove karni hai?**

```cpp
n /= 10
```

### Step 4

**Count karna hai?**

```cpp
count++;
```

### Step 5

**Sum karna hai?**

```cpp
sum += value;
```

### Step 6

**Product?**

```cpp
product *= value;
```

### Step 7

**Maximum?**

```cpp
if (value > maximum)
    maximum = value;
```

### Step 8

**Minimum?**

```cpp
if (value < minimum)
    minimum = value;
```

### Step 9

**Answer milte hi ruk sakte hain?**

```cpp
break;
```

---

# 🔥 Part AO — Important Output Questions

Ab thora brain exercise.

## Q1

```cpp
int n = 1234;

while (n > 0) {
    cout << n % 10 << " ";
    n /= 10;
}
```

Output?

---

## Q2

```cpp
int n = 4321;
int sum = 0;

while (n > 0) {
    sum += n % 10;
    n /= 10;
}

cout << sum;
```

Output?

---

## Q3

```cpp
int n = 12345;
int count = 0;

while (n > 0) {
    count++;
    n /= 10;
}

cout << count;
```

Output?

---

## Q4 🔥

```cpp
int n = 2468;
int reverse = 0;

while (n > 0) {
    int digit = n % 10;
    reverse = reverse * 10 + digit;
    n /= 10;
}

cout << reverse;
```

Output?

---

## Q5 🔥

```cpp
int count = 0;

for (int i = 1; i <= 20; i++) {

    if (i % 3 == 0)
        count++;
}

cout << count;
```

Output?

---

# 🏆 Part 3 Practice Challenge

Ab ye actual coding problems hain:

### Q1

Ek integer input lo aur uske **digits ka sum** nikalo.

### Q2

Ek integer input lo aur uske **digits count** karo.

### Q3

Ek integer ko **reverse** karo.

### Q4

Check karo number **palindrome** hai ya nahi.

### Q5

Number ke **saare factors** print karo.

### Q6

Check karo number **prime** hai ya nahi.

### Q7 🔥

1 se `n` tak kitne numbers **3 se divisible** hain?

### Q8 🔥

1 se `n` tak un numbers ka sum nikalo jo **3 aur 5 dono se divisible** hain.

### Q9 🔥

10 numbers input lo aur find karo:

```text
positive count
negative count
zero count
maximum
minimum
```

### Q10 🔥🔥

Ek number input lo aur determine karo:

```text
number of digits
sum of digits
reverse
palindrome or not
```

---

### 🧠 Ek baat specially yaad rakho

Ab tumhare paas ye powerful combination aa gaya hai:

```text
LOOP
  +
CONDITION
  +
COUNTER / SUM / MAX / MIN
  +
% and / 10
```

Isi combination se PF ke **bohat saare number problems** solve ho jate hain.