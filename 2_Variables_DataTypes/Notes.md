# 📘 PF Chapter 2 — Variables & Data Types

--- 

# 🎯 Chapter 2 ka Learning Order

Hum is chapter ko is order mein complete karenge:

### Part A — Variables & Types

* Variables
* Declaration
* Initialization
* Assignment
* Data types
* `const`
* Memory basics

### Part B — Type System

* Type conversion
* Implicit conversion
* Explicit casting
* `int` vs `double`
* Character/integer relationship
* Overflow basics

### Part C — Input/Output

* `cin`
* `cout`
* multiple inputs
* multiple outputs
* whitespace/newline
* common input mistakes

### Part D — Tricky PF

* integer division
* decimal calculations
* precedence with types
* overflow
* type conversion traps
* interview-style output questions

### Part E — Practice

Easy → medium → tricky → interview-style.

---

Is chapter ka goal ye hai ke tumhe clearly samajh aaye:

> **Data memory mein kaise store hota hai, variable kya hota hai, data type kyun hota hai, aur C++ kis tarah decide karta hai ke kitni memory aur kis type ka data rakhna hai.**

---

# 📘 Chapter 2 — Part A: Variables and Types

## 2.1 Variable kya hota hai?

Simple definition:

> **Variable memory mein ek named storage location hota hai jahan hum data store karte hain.**

Example:

```cpp
int age = 20;
```

Isko todte hain:

```text
int     age     =     20
 ↑       ↑             ↑
type   variable       value
```

Yahan:

* `int` → data type
* `age` → variable ka naam
* `20` → value

Socho memory mein ek box hai:

```text
┌─────────────┐
│     20      │
└─────────────┘
      age
```

`age` us box ka **naam** hai.

---

# 2.2 Variable ki zaroorat kyun?

Suppose humein student ki age use karni hai multiple jagah:

```cpp
cout << 20;
cout << 20 + 5;
cout << 20 * 2;
```

Kaam ho jayega.

Lekin agar age change ho:

```text
20 → 21
```

to har jagah `20` change karna padega.

Variable:

```cpp
int age = 20;

cout << age;
cout << age + 5;
cout << age * 2;
```

Ab sirf:

```cpp
age = 21;
```

aur poora program updated value use karega.

**Yahi variable ka basic purpose hai.**

---

# 2.3 Declaration vs Initialization

Ye interview mein bhi important concept hai.

### Declaration

```cpp
int age;
```

Humne kaha:

> `age` naam ka integer variable bana do.

Abhi value assign nahi ki.

---

### Initialization

```cpp
int age = 20;
```

Variable banate waqt hi initial value de di.

```text
int age = 20;
    ↑       ↑
 variable  initial value
```

---

### Assignment

Baad mein value change karna:

```cpp
age = 25;
```

Ye **assignment** hai.

Difference:

```cpp
int age = 20;  // initialization

age = 25;      // assignment
```

---

# 2.4 Data Type kya hota hai?

Ab important part.

Computer ko pata hona chahiye:

> Is variable mein kis type ka data store hoga?

For example:

```cpp
int age = 20;
```

`int` batata hai ke `age` integer values ke liye hai.

Examples:

```cpp
int age = 20;
double price = 99.99;
char grade = 'A';
bool passed = true;
```

Different data → different data types.

---

# 2.5 Common C++ Data Types

Sabse pehle ye 5 strong karo:

| Type     | Example   | Usually used for      |
| -------- | --------- | --------------------- |
| `int`    | `25`      | whole numbers         |
| `float`  | `3.14f`   | decimal numbers       |
| `double` | `3.14159` | more precise decimals |
| `char`   | `'A'`     | single character      |
| `bool`   | `true`    | true/false            |

---

## `int`

Whole numbers:

```cpp
int marks = 85;
int age = 20;
int temperature = -5;
```

Decimal nahi:

```cpp
int x = 3.14;
```

Yahan important issue hai: `int` decimal portion ko retain nahi karta. Isliye floating-point type use karna chahiye agar decimal required ho.

---

# 2.6 `float` vs `double`

Dono decimal values ke liye hain.

```cpp
float x = 3.14f;
double y = 3.14;
```

Basic PF level par:

> `double` generally `float` se zyada precision provide karta hai.

Isliye jab specifically `float` ki requirement na ho, practical C++ programming mein `double` commonly preferred hota hai for ordinary decimal calculations.

---

# 2.7 `char`

Sirf **one character**:

```cpp
char grade = 'A';
```

Notice:

```cpp
'A'
```

single quotes.

Ye:

```cpp
"A"
```

same cheez nahi hai.

`'A'` → character

`"A"` → string literal

Abhi string ko baad mein properly cover karenge.

---

# 2.8 `bool`

Sirf do logical states:

```cpp
bool isPassed = true;
bool isAdult = false;
```

Basically:

```text
true
false
```

Conditions aur decision making mein bohat important hoga.

Example:

```cpp
bool isEven = (10 % 2 == 0);
```

Result:

```text
isEven = true
```

Yahan expression pehle calculate hota hai:

```cpp
10 % 2 == 0
```

→ `0 == 0`

→ `true`

---

# 2.9 Variable Naming Rules

Valid:

```cpp
int age;
int studentAge;
int marks1;
int _value;
```

Invalid:

```cpp
int 1age;        // ❌
int student age; // ❌
int my-age;      // ❌
```

Variable name:

* number se start nahi ho sakta
* spaces nahi
* hyphen `-` allowed nahi
* C++ keywords use nahi kar sakte

For example:

```cpp
int int; // ❌
```

because `int` already C++ keyword hai.

---

# 2.10 Case Sensitive

C++ **case-sensitive** hai.

```cpp
int age = 20;

cout << age;
```

aur:

```cpp
cout << Age;
```

same nahi hain.

```text
age ≠ Age ≠ AGE
```

Ye choti cheez hai lekin bugs bohat create karti hai.

---

# 2.11 Ek important concept: Memory

Ab thoda deeper PF.

Jab hum likhte hain:

```cpp
int age = 20;
```

to computer memory mein space reserve karta hai.

Conceptually:

```text
Memory
┌───────────────┐
│      20       │
├───────────────┤
│               │
├───────────────┤
│               │
└───────────────┘
      age
```

Actual memory address bhi hota hai.

Example conceptually:

```text
age
 ↓
Address: 1000
Value:   20
```

Baad mein jab hum **pointers** padhenge, ye concept bohat important ho jayega.

Abhi sirf itna yaad rakho:

> **Variable ka naam hum use karte hain, lekin actual data memory mein stored hota hai.**

---

# 2.12 `const` — Constant Variable

Kabhi humein chahiye hota hai ke value change na ho.

Example:

```cpp
const double PI = 3.14159;
```

Ab:

```cpp
PI = 5;
```

❌ allowed nahi.

Concept:

```text
normal variable → value change ho sakti hai

const variable → value change nahi karni
```

Example:

```cpp
const int DAYS_IN_WEEK = 7;
```

Ye useful hai because program ke andar accidental modification prevent hoti hai.

---

# 🧠 Ab ek important thinking question

Dekho:

```cpp
int a = 10;
int b = a;
a = 20;

cout << a << endl;
cout << b << endl;
```

Output kya hoga?

Socho carefully.

Kya:

```text
20
20
```

ya:

```text
20
10
```

?

**Iska answer abhi mat dekhna — khud dry run karo.**

Trace table banao:

| Step         | `a` | `b` |
| ------------ | --: | --: |
| `int a = 10` |   ? |   ? |
| `int b = a`  |   ? |   ? |
| `a = 20`     |   ? |   ? |

---

## 🔥 Mini-task

Pehle upar wale dry run ka answer do:

```cpp
int a = 10;
int b = a;
a = 20;

cout << a << endl;
cout << b << endl;
```

**Output kya hoga aur WHY?**

# 📘 Chapter 2 — Part B: Type System

Hum 6 cheezen cover karenge:

1. Type Conversion
2. Implicit Conversion
3. Explicit Casting
4. `int` vs `double`
5. Character ↔ Integer relationship
6. Overflow basics

---

# 1. Type Conversion — Basic Idea

Suppose:

```cpp
int x = 10;
double y = x;
```

Yahan:

```text
int
 ↓
10
 ↓
double
 ↓
10.0
```

Ek data type ki value ko doosre data type mein convert karna **type conversion** hai.

### Simple example

```cpp
int x = 10;
double y = x;

cout << y;
```

Output:

```text
10
```

Conceptually `y` floating-point type ka hai.

---

# 2. Conversion ki 2 Main Types

C++ mein broadly:

```text
Type Conversion
      │
      ├── Implicit
      │
      └── Explicit
```

---

# 3. Implicit Conversion

**Implicit = compiler khud conversion karta hai.**

Example:

```cpp
int x = 10;
double y = x;
```

Tumne manually nahi kaha:

> `x` ko double banao.

Compiler automatically conversion karta hai.

```text
int 10
   ↓
double 10.0
```

### Ek aur example

```cpp
double x = 10;
```

Yahan integer literal `10` ko floating-point value mein convert kiya ja sakta hai.

---

# 4. Widening Conversion

Ek common case:

```text
smaller representation/range
        ↓
larger representation/range
```

For example:

```cpp
int x = 100;
double y = x;
```

Generally information loss nahi hota for ordinary integer values within the exact-integer range of `double`.

Isko commonly **widening conversion** kaha jata hai.

---

# 5. Narrowing Conversion

Ab reverse:

```cpp
double x = 10.75;
int y = x;
```

Yahan decimal part retain nahi hota:

```text
10.75
 ↓
int
 ↓
10
```

So:

```cpp
cout << y;
```

→ `10`

### Important:

Ye rounding nahi hai.

```text
10.75 → 10
```

not:

```text
10.75 → 11
```

Conversion fractional part ko discard/truncate karti hai.

---

# 6. ⚠️ Important: Conversion aur Assignment Same Thing Nahi

Ye:

```cpp
double x = 10;
```

mein conversion ho sakti hai.

Lekin:

```cpp
x = 20;
```

mein hum existing variable ko **new value assign** kar rahe hain.

Conceptually:

```text
conversion → type change/interpretation
assignment → value store/change
```

Dono concepts ko mix mat karna.

---

# 7. Explicit Casting

Ab compiler ko khud conversion karne dene ke bajaye hum **explicitly** bolte hain:

> Mujhe is value ko is type mein convert karna hai.

Modern C++ syntax:

```cpp
static_cast<type>(value)
```

Example:

```cpp
double x = 10.75;

int y = static_cast<int>(x);
```

Now:

```text
y = 10
```

---

# 8. Sabse Important Example — Division

Ye DSA/PF ka **classic trap** hai.

```cpp
int a = 5;
int b = 2;

double result = a / b;
```

Tum soch sakte ho:

```text
5 / 2 = 2.5
```

Lekin nahi.

Pehle expression calculate hoga:

```text
a / b
↓
5 / 2
↓
int / int
↓
2
```

Phir:

```text
2 → double
```

So:

```text
result = 2.0
```

---

# 9. Explicit Casting se Problem Solve

```cpp
int a = 5;
int b = 2;

double result =
    static_cast<double>(a) / b;
```

Ab:

```text
static_cast<double>(a)
↓
5.0
```

Then:

```text
5.0 / 2
↓
2.5
```

So:

```text
result = 2.5
```

---

# 🧠 Golden Rule

> **Division se pehle operands ke types dekho.**

Ye mat dekho ke result kis variable mein ja raha hai.

❌ Wrong thinking:

```cpp
double result = 5 / 2;
```

"result double hai, isliye 2.5 hoga."

No.

✅ Correct thinking:

```text
5 / 2
↓
int / int
↓
2
↓
then assigned to double
```

---

# 10. `int` vs `double`

Ab dono ko properly compare karte hain.

## `int`

Whole numbers:

```cpp
int x = 10;
int y = -5;
```

No fractional part.

---

## `double`

Floating-point numbers:

```cpp
double x = 10.5;
double y = -3.75;
```

Fractional values represent kar sakta hai.

---

### Example

```cpp
int a = 7;
int b = 2;

cout << a / b;
```

→ `3`

But:

```cpp
double a = 7;
double b = 2;

cout << a / b;
```

→ `3.5`

---

# 11. Mixed `int` + `double`

Ab interesting case:

```cpp
int a = 5;
double b = 2.0;

cout << a / b;
```

Yahan:

```text
int / double
```

C++ calculation ko floating-point side par le jata hai.

Conceptually:

```text
5 → 5.0
5.0 / 2.0
↓
2.5
```

Output:

```text
2.5
```

---

# 12. Ek bohat important comparison

### Case 1

```cpp
cout << 5 / 2;
```

→ `2`

### Case 2

```cpp
cout << 5.0 / 2;
```

→ `2.5`

### Case 3

```cpp
cout << static_cast<double>(5) / 2;
```

→ `2.5`

### Case 4

```cpp
double result = 5 / 2;
```

→ `2`

### Case 5

```cpp
double result = 5.0 / 2;
```

→ `2.5`

Ye **5 cases** yaad karne ke bajaye ek rule yaad karo:

> **Integer division tab hoti hai jab division ke operands integral types mein hon. Floating-point operand aa jaye to calculation floating-point side par chali jati hai.**

---

# 13. Character aur Integer ka Relationship

Ab `char`.

```cpp
char ch = 'A';
```

Computer character ko internally numeric encoding ke through represent karta hai.

ASCII mein:

```text
'A' → 65
'B' → 66
'C' → 67
```

and:

```text
'a' → 97
'b' → 98
'c' → 99
```

---

# 14. `char` ko `int` mein convert karna

```cpp
char ch = 'A';

cout << static_cast<int>(ch);
```

Output:

```text
65
```

Because `'A'` ki ASCII value 65 hai.

---

# 15. `int` ko `char` mein convert karna

Reverse:

```cpp
int x = 65;

cout << static_cast<char>(x);
```

Output commonly:

```text
A
```

So:

```text
'A' ↔ 65
```

---

# 16. Character Arithmetic

Ab ye bohat useful hai.

```cpp
char ch = 'A';

cout << ch + 1;
```

Output:

```text
66
```

Why?

```text
ch
↓
'A'
↓
65
↓
65 + 1
↓
66
```

Agar:

```cpp
char next = ch + 1;

cout << next;
```

then:

```text
66
↓
'B'
```

Output:

```text
B
```

---

# 17. Character Comparison

Ye bhi isi relationship ki wajah se possible hai.

```cpp
char a = 'A';
char b = 'B';

cout << (a < b);
```

Conceptually:

```text
'A' → 65
'B' → 66

65 < 66
↓
true
```

Output normally:

```text
1
```

Ye later strings aur character algorithms mein kaam aayega.

---

# 18. ⚠️ `'5'` aur `5` Same Nahi

Ye **super important** hai.

```cpp
char a = '5';
int b = 5;
```

`a` contains character `'5'`.

`b` contains number `5`.

ASCII mein:

```text
'5' → 53
5   → numeric value 5
```

So:

```cpp
cout << static_cast<int>('5');
```

→ `53`

not `5`.

---

# 19. `'0'` se Digit Conversion

Suppose:

```cpp
char ch = '7';
```

Agar actual numeric digit `7` chahiye:

```cpp
int digit = ch - '0';
```

Why?

ASCII:

```text
'7' = 55
'0' = 48

55 - 48
↓
7
```

So:

```cpp
char ch = '7';

int digit = ch - '0';

cout << digit;
```

Output:

```text
7
```

Ye strings/number problems mein **extremely useful** technique hai.

---

# 20. Reverse: Digit ko Character

Agar:

```cpp
int digit = 7;
```

and character `'7'` chahiye:

```cpp
char ch = digit + '0';
```

Because:

```text
7 + ASCII('0')
7 + 48
↓
55
↓
'7'
```

So:

```cpp
cout << ch;
```

→ `7`

---

# 21. Overflow Basics

Ab important aur thoda dangerous topic. ⚠️

Har data type ki representable range hoti hai.

Example commonly 32-bit signed `int`:

```text
minimum ≈ -2,147,483,648
maximum ≈  2,147,483,647
```

Agar tum:

```cpp
int x = 2147483647;
```

then `x` typical 32-bit signed int ke maximum par hai.

Ab:

```cpp
x = x + 1;
```

Value representable range se bahar chali jati hai.

---

# 22. Signed Integer Overflow

Yahan ek important C++ rule:

> **Signed integer overflow is undefined behavior.**

Matlab ye assume nahi karna chahiye ke C++ guaranteed `-2147483648` dega.

Kuch machines/compilers par aisa appear ho sakta hai, lekin language guarantee nahi karti.

So interview mein:

❌ "`INT_MAX + 1` always becomes `INT_MIN`."

Better:

✅ "It causes signed integer overflow, which is undefined behavior."

---

# 23. Overflow kyun hota hai?

Simplified idea:

Suppose imaginary type ki range hai:

```text
0 → 9
```

Aur:

```text
x = 9
```

Ab:

```text
x + 1
```

to `10` type ki range mein nahi.

Real integer types bhi limited representation use karte hain.

Isliye:

```text
Data type
   ↓
finite representation
   ↓
finite range
   ↓
range exceed
   ↓
overflow / undefined behavior
```

---

# 24. `long long` kyun?

Agar values bohat badi hon:

```cpp
long long x = 1000000000000LL;
```

`long long` generally `int` se considerably larger integer range provide karta hai.

DSA mein frequently:

```cpp
long long sum = 0;
```

use karoge.

Especially jab:

* large numbers
* array sums
* multiplication
* counting
* formulas

involved hon.

---

# 25. Lekin `long long` bhi Infinite Nahi 😄

Ye:

```cpp
long long
```

bhi finite range rakhta hai.

So:

```text
int
↓
limited

long long
↓
larger but still limited
```

Agar uski range bhi exceed kar di → signed overflow again.

---

# 26. Overflow ka DSA Example

Suppose:

```cpp
int a = 100000;
int b = 100000;

int result = a * b;
```

Mathematically:

```text
100000 × 100000
= 10,000,000,000
```

Ye typical 32-bit `int` range se bahar hai.

Important subtlety:

```cpp
long long result = a * b;
```

**automatically safe nahi ban jata.**

Why?

Because multiplication pehle:

```text
int × int
```

mein ho sakti hai.

Correct:

```cpp
long long result =
    static_cast<long long>(a) * b;
```

Now one operand `long long` hai, so multiplication wider integer type mein hoti hai.

🔥 Ye **real DSA-level trap** hai.

---

# 27. Ek aur subtle point

Suppose:

```cpp
int a = 100000;
long long result = a * a;
```

Still dangerous.

Because:

```text
a * a
↓
int * int
↓
int calculation
```

phir result ko `long long` mein store karne ki koshish hoti hai.

Correct:

```cpp
long long result =
    1LL * a * a;
```

or:

```cpp
long long result =
    static_cast<long long>(a) * a;
```

`1LL` ka matlab yahan integer literal ko `long long` type ka banana hai.

---

# 28. Type Conversion + Overflow Connection

Ye dono concepts connected hain.

Dekho:

```cpp
int a = 100000;
int b = 100000;

long long x = a * b;
```

Potential problem:

```text
a * b
↓
int calculation
↓
overflow may happen
↓
then assignment to long long
```

Whereas:

```cpp
long long x = 1LL * a * b;
```

```text
1LL * a
↓
long long
↓
(long long) * b
↓
large result safely represented
```

Ye habit DSA mein bohat kaam aayegi.

---

# 29. Type Conversion ka ek Master Example

Isko dekho:

```cpp
int a = 7;
int b = 2;

double x = a / b;
double y = static_cast<double>(a) / b;
```

### `x`

```text
a / b
↓
int / int
↓
3
↓
double
↓
3.0
```

### `y`

```text
static_cast<double>(a)
↓
7.0

7.0 / 2
↓
3.5
```

Therefore:

```text
x = 3.0
y = 3.5
```

---

# 🧠 Master Rules — Part B

Ab ye **6 golden rules** yaad rakho:

### Rule 1

**Implicit conversion** = compiler automatically conversion kare.

### Rule 2

**Explicit casting** = tum khud conversion request karo.

```cpp
static_cast<double>(x)
```

### Rule 3

`int / int` → integer division.

```cpp
5 / 2 → 2
```

### Rule 4

Floating-point operand aa jaye:

```cpp
5.0 / 2 → 2.5
```

### Rule 5

Character numeric encoding rakhta hai.

```text
'A' → 65
'0' → 48
```

Aur:

```cpp
digit = ch - '0';
```

### Rule 6

Large calculation mein **calculation ke waqt** type dekho, sirf result variable ka type nahi.

```cpp
long long x = a * b;       // may still overflow
long long x = 1LL * a * b; // wider calculation
```

---

# 🔥 Ab Part B ka Real Test

Ab main answers nahi de raha. Ye tumhara **Chapter 2 Part B assessment** hai.

### Q1

```cpp
int a = 9;
int b = 2;

double x = a / b;
```

`x` ki value kya hogi aur **kyun?**

---

### Q2

```cpp
int a = 9;
int b = 2;

double x = static_cast<double>(a) / b;
```

`x`?

---

### Q3

```cpp
double x = 15.87;
int y = static_cast<int>(x);

cout << y;
```

Output?

Aur batao **rounding hui ya truncation?**

---

### Q4

```cpp
char ch = 'C';

cout << static_cast<int>(ch);
```

Output?

---

### Q5

```cpp
char ch = '8';

int x = ch - '0';

cout << x;
```

Output aur **why**?

---

### Q6 — DSA Trap 😈

```cpp
int a = 100000;
int b = 100000;

long long result = a * b;
```

Kya sirf `result` ka type `long long` hone ki wajah se calculation definitely safe hai?

**Why/why not?**

---

### Q7 — Pro Thinking

```cpp
int a = 7;
double b = 2;

cout << a / b;
```

Output kya hoga?

**Hint:** operands dekho, result variable nahi — yahan direct `cout` hai.

---

In **7 questions** ko khud solve karo. Agar tum inki reasoning correctly explain kar dete ho, to Part B sirf "yaad" nahi hoga — **actually samajh aa gaya hoga**.

# 📘 Chapter 2 — Part C: Input / Output

Hum ye 6 cheezen cover karenge:

1. `cin`
2. `cout`
3. Multiple inputs
4. Multiple outputs
5. Whitespace / newline
6. Common input mistakes

---

# 1. `cout` — Output

`cout` ka kaam hai **program ka result screen par print karna**.

Basic:

```cpp
cout << "Hello";
```

Output:

```text
Hello
```

Variable:

```cpp
int age = 20;

cout << age;
```

Output:

```text
20
```

### Mental model

```text
cout
 ↓
"jo cheez << ke right side par hai"
 ↓
screen par bhejo
```

---

# 2. `<<` kya karta hai?

```cpp
cout << age;
```

Yahan `<<` ko **stream insertion operator** kehte hain.

Simple PF level par:

> `cout` ko batata hai ke kya output stream mein bhejna hai.

Multiple things:

```cpp
int age = 20;

cout << "Age: " << age;
```

Output:

```text
Age: 20
```

Isko tum chain bhi kar sakte ho:

```cpp
cout << "Age: " << age << " years";
```

Output:

```text
Age: 20 years
```

---

# 3. `endl`

Agar next line par jana hai:

```cpp
cout << "Hello" << endl;
cout << "World";
```

Output:

```text
Hello
World
```

`endl` newline insert karta hai aur stream ko flush bhi karta hai.

Daily/competitive code mein commonly:

```cpp
cout << "\n";
```

bhi use karte hain.

For example:

```cpp
cout << "Hello\n";
cout << "World";
```

Same visible output:

```text
Hello
World
```

### Difference basic level par:

```text
endl → newline + flush
\n   → newline character
```

Normally unnecessary `endl` ke bajaye `\n` use karna performance-sensitive code mein preferable ho sakta hai.

---

# 4. `cin` — Input

Ab reverse.

`cout`:

```text
Program → Screen
```

`cin`:

```text
Keyboard/Input → Program
```

Example:

```cpp
int age;

cin >> age;
```

Program user se integer read karega.

Complete:

```cpp
#include <iostream>
using namespace std;

int main()
{
    int age;

    cin >> age;

    cout << "Your age is " << age;

    return 0;
}
```

Agar user input kare:

```text
20
```

Output:

```text
Your age is 20
```

---

# 5. `>>` kya karta hai?

```cpp
cin >> age;
```

Yahan `>>` ko **stream extraction operator** kehte hain.

Simple mental model:

```text
cin
 ↓
input stream se data lo
 ↓
age mein store karo
```

So:

```text
cout << value
```

→ output

```text
cin >> variable
```

→ input

🔥 Yaad rakhne ka easy trick:

```text
cout <<

cin >>
```

`cout` ka arrow **bahar** ja raha hai.

`cin` ka arrow **andar** aa raha hai.

---

# 6. Multiple Inputs

Suppose:

```text
10 20
```

Read karna hai.

```cpp
int a, b;

cin >> a >> b;
```

Ab:

```text
a = 10
b = 20
```

User input ek line mein de:

```text
10 20
```

ya separate lines:

```text
10
20
```

Dono normally kaam karenge.

---

# 7. Multiple Inputs ka Important Concept

Code:

```cpp
int a, b, c;

cin >> a >> b >> c;
```

Input:

```text
10 20 30
```

Result:

```text
a = 10
b = 20
c = 30
```

Input:

```text
10
20
30
```

Result bhi:

```text
a = 10
b = 20
c = 30
```

Why?

Because formatted `cin >>` whitespace ko generally separator ki tarah treat karta hai.

---

# 8. Whitespace kya hota hai?

Whitespace basically spaces/newline/tab waghera.

Example:

```text
10 20 30
```

spaces:

```text
10[space]20[space]30
```

Newline:

```text
10
20
30
```

Tab:

```text
10    20
```

For numeric input, `cin >>` generally in sab whitespace ko skip karke next value read karta hai.

---

# 9. Example — Whitespace

```cpp
int a, b;

cin >> a >> b;
```

All these inputs generally equivalent hain:

```text
10 20
```

```text
10
20
```

```text
10     20
```

```text
10        20
```

Because `cin >>` numeric extraction ke waqt whitespace skip karta hai.

---

# 10. Multiple Outputs

Bilkul isi tarah:

```cpp
int a = 10;
int b = 20;

cout << a << b;
```

Output:

```text
1020
```

⚠️ `10` aur `20` automatically separate nahi honge.

Agar space chahiye:

```cpp
cout << a << " " << b;
```

Output:

```text
10 20
```

Newline:

```cpp
cout << a << "\n" << b;
```

Output:

```text
10
20
```

---

# 11. Output formatting ka basic rule

Agar expected output hai:

```text
10 20 30
```

then:

```cpp
cout << a << " " << b << " " << c;
```

Agar expected hai:

```text
10
20
30
```

then:

```cpp
cout << a << "\n";
cout << b << "\n";
cout << c << "\n";
```

Competitive programming mein **exact output format** important hota hai.

---

# 12. `cin` aur `cout` Data Type ke According

C++ `cin` input ko variable ke type ke according interpret karta hai.

```cpp
int age;
cin >> age;
```

Expected:

```text
20
```

---

```cpp
double price;
cin >> price;
```

Can read:

```text
99.99
```

---

```cpp
char grade;
cin >> grade;
```

Input:

```text
A
```

Then:

```text
grade = 'A'
```

---

```cpp
bool passed;
cin >> passed;
```

Default formatted input generally `0` or `1` expect karta hai unless `boolalpha` enabled ho.

---

# 13. Common Mistake #1 — Variable Declare nahi ki

Wrong:

```cpp
cin >> age;
```

Agar `age` declared hi nahi:

```text
❌ compilation error
```

Correct:

```cpp
int age;
cin >> age;
```

---

# 14. Common Mistake #2 — Wrong type

Example:

```cpp
int age;

cin >> age;
```

User:

```text
twenty
```

Problem.

`int` ko numeric input chahiye.

---

# 15. Common Mistake #3 — `cin` mein `<<`

Wrong:

```cpp
cin << age;
```

❌

Correct:

```cpp
cin >> age;
```

Remember:

```text
cout <<
cin  >>
```

---

# 16. Common Mistake #4 — `cout` mein `>>`

Wrong:

```cpp
cout >> age;
```

❌

Correct:

```cpp
cout << age;
```

---

# 17. Common Mistake #5 — Input ko output samajhna

```cpp
int a;

cin >> a;
```

Ye **print nahi** kar raha.

Ye input le raha hai.

Aur:

```cpp
cout << a;
```

Ye input nahi le raha.

Ye print kar raha hai.

---

# 18. Common Mistake #6 — Uninitialized Variable

Dekho:

```cpp
int x;

cout << x;
```

❌ `x` ko value assign nahi ki gayi.

Local variable `x` ki value indeterminate hoti hai; usko read karna undefined behavior hai.

Correct:

```cpp
int x = 0;
cout << x;
```

ya:

```cpp
int x;
cin >> x;
cout << x;
```

---

# 19. Input lene se pehle Initialization zaroori hai?

Ye distinction important hai.

```cpp
int x;
cin >> x;
```

✅ Fine.

`cin` x ke andar input value store karega.

Lekin:

```cpp
int x;
cout << x;
```

❌ Problem.

So:

```text
cin >> x
```

→ value provide kar raha hai.

---

# 20. Common Mistake #7 — `=` vs `==`

Input/output mein nahi, lekin PF mein bohat common:

```cpp
x = 5;
```

means:

> x ko 5 assign karo.

Whereas:

```cpp
x == 5
```

means:

> check karo x 5 ke equal hai ya nahi.

Conditions mein iska use hoga.

---

# 21. Whitespace ka REAL tricky case

Ab ye bohat important hai.

Suppose:

```cpp
int age;
char grade;

cin >> age;
cin >> grade;
```

Input:

```text
20 A
```

Result:

```text
age = 20
grade = 'A'
```

Why?

`cin >> grade` leading whitespace skip karta hai aur `A` read karta hai.

---

# 22. `char` ke saath whitespace

Suppose:

```cpp
char ch;

cin >> ch;
```

Input:

```text
    A
```

`cin >> ch` leading whitespace skip karke:

```text
A
```

read karega.

---

# 23. `cin.get()` vs `cin >>`

Yahan thoda advanced concept hai.

`cin >> ch`:

```text
whitespace skip
↓
character read
```

while:

```cpp
cin.get(ch);
```

character ko directly read karta hai, including whitespace.

Example input:

```text
 A
```

Agar:

```cpp
char ch;
cin.get(ch);
```

to `ch` space bhi ho sakta hai.

Ye distinction strings ke chapter mein bohat important hoga.

---

# 24. Newline `\n`

`\n` newline character hai.

Example:

```cpp
cout << "Hello\nWorld";
```

Output:

```text
Hello
World
```

Multiple:

```cpp
cout << "A\nB\nC";
```

Output:

```text
A
B
C
```

---

# 25. `endl` vs `\n`

```cpp
cout << "Hello" << endl;
```

vs

```cpp
cout << "Hello\n";
```

Dono next line par le ja sakte hain.

But:

```text
endl → newline + flush
\n   → newline
```

Most competitive programming situations mein:

```cpp
cout << "\n";
```

common hai.

---

# 26. ⚠️ Famous `cin` + `getline` Problem

Ye abhi sirf **preview** hai; strings mein properly karenge.

Suppose:

```cpp
int age;
string name;

cin >> age;
getline(cin, name);
```

Input:

```text
20
Muhammad Hassan
```

Beginner ko lag sakta hai ke `name` mein:

```text
Muhammad Hassan
```

aa jayega.

Lekin `cin >> age` ke baad newline input stream mein reh sakti hai, aur `getline()` us pending newline ko consume karke empty string read kar sakta hai.

Common solution:

```cpp
cin.ignore();
getline(cin, name);
```

Lekin `ignore()` ke proper forms aur edge cases strings/input chapter mein detail se karenge.

**Abhi bas problem identify karna seekho.**

---

# 27. `cin` input fail ho sakta hai

Example:

```cpp
int x;
cin >> x;
```

User enters:

```text
abc
```

Integer extraction fail ho sakti hai.

Then stream ka fail state set ho sakta hai.

Basic idea:

```text
valid input
↓
cin successfully reads

invalid input
↓
reading fails
↓
stream enters fail state
```

Later error handling mein isko properly cover karenge.

---

# 28. Complete Example

Ab sab combine:

```cpp
#include <iostream>
using namespace std;

int main()
{
    int age;
    double height;
    char grade;

    cin >> age >> height >> grade;

    cout << "Age: " << age << "\n";
    cout << "Height: " << height << "\n";
    cout << "Grade: " << grade << "\n";

    return 0;
}
```

Input:

```text
20 5.9 A
```

Output:

```text
Age: 20
Height: 5.9
Grade: A
```

---

# 🧠 Input/Output ka Master Mental Model

Jab problem bole:

> Read 3 integers and print their sum.

Tumhara brain immediately:

```text
INPUT
 ↓
int a, b, c
 ↓
cin >> a >> b >> c

PROCESS
 ↓
sum = a + b + c

OUTPUT
 ↓
cout << sum
```

Code:

```cpp
int a, b, c;

cin >> a >> b >> c;

int sum = a + b + c;

cout << sum;
```

Ye **Input → Process → Output** framework hai jo hum Chapter 1 mein seekh chuke hain.

---

# 🔥 Part C ke Most Important Rules

### Rule 1

```cpp
cin >> variable;
```

→ input

### Rule 2

```cpp
cout << value;
```

→ output

### Rule 3

Multiple input:

```cpp
cin >> a >> b >> c;
```

### Rule 4

Multiple output:

```cpp
cout << a << " " << b;
```

### Rule 5

Numeric `cin >>` generally whitespace skip karta hai.

### Rule 6

`\n` = newline.

### Rule 7

`endl` = newline + flush.

### Rule 8

```cpp
int x;
cout << x;
```

❌ uninitialized local variable ko read karna.

### Rule 9

`cin >>` aur `getline()` ka interaction tricky ho sakta hai because of leftover newline.

### Rule 10

**Output format exact hota hai.**

Agar expected:

```text
10 20
```

aur tum:

```text
10
20
```

print kar do, to logically values correct hone ke bawajood online judge wrong answer de sakta hai.

---

# 🧪 Part C Practice — Ab Tumhari Baari

### Q1

Input:

```text
10 20
```

Code:

```cpp
int a, b;

cin >> a >> b;

cout << a << b;
```

Output kya hoga?

---

### Q2

Same input:

```text
10 20
```

Code:

```cpp
int a, b;

cin >> a >> b;

cout << a << " " << b;
```

Output?

---

### Q3

Input:

```text
5
7
```

Code:

```cpp
int a, b;

cin >> a >> b;

cout << a + b;
```

Output?

---

### Q4

Ye code correct hai ya nahi?

```cpp
int x;

cout << x;
```

**Reason bhi.**

---

### Q5 😈

```cpp
int a;
double b;

cin >> a >> b;
```

Input:

```text
10 2.5
```

After input:

```text
a = ?
b = ?
```

---

### Q6 🔥

Explain in your own words:

> `cin >> a >> b` mein agar user input `10 20` **same line** mein de ya `10` aur `20` **different lines** mein de, dono kyun work karte hain?

---

### Q7 — Important

Difference explain karo:

```cpp
cin >> ch;
```

vs

```cpp
cin.get(ch);
```

Especially **whitespace** ke hawale se.

---

# 📘 Part D — Tricky PF

---

## 1. Integer Division

Sabse pehle golden rule:

> **Agar division ke dono operands integer hain, to integer division hoti hai.**

```cpp
int a = 7;
int b = 2;

cout << a / b;
```

Output:

```text
3
```

Mathematically `3.5` hai, lekin:

```text
int / int
↓
integer division
↓
3
```

### Decimal chahiye?

```cpp
cout << 7.0 / 2;
```

→ `3.5`

Ya:

```cpp
cout << static_cast<double>(7) / 2;
```

→ `3.5`

---

## ⚠️ Sabse famous trap

```cpp
int a = 7;
int b = 2;

double result = a / b;
```

`result` **3.5 nahi** hoga.

Execution:

```text
a / b
↓
7 / 2
↓
3
↓
3 → double
↓
3.0
```

So:

```text
result = 3.0
```

### Correct:

```cpp
double result = static_cast<double>(a) / b;
```

→ `3.5`

---

# 2. Decimal Calculations

Suppose:

```cpp
int total = 5;
int count = 2;

double average = total / count;
```

Beginner mistake:

> Average double hai, to 2.5 ayega.

❌ Nope.

`total / count` pehle calculate hoga:

```text
5 / 2
↓
2
```

Then:

```text
2 → 2.0
```

So `average = 2.0`.

### Correct:

```cpp
double average =
    static_cast<double>(total) / count;
```

→ `2.5`

---

# 3. Decimal Calculation ka Rule

Jahan fractional answer chahiye:

```text
At least one operand
        ↓
floating-point
        ↓
division becomes floating-point
```

Examples:

```cpp
5 / 2       → 2
5.0 / 2     → 2.5
5 / 2.0     → 2.5
5.0 / 2.0   → 2.5
```

---

# 4. Precedence + Types

Ab thoda tricky. 😈

Do separate concepts hain:

### Precedence

> Kaunsa operation pehle hoga?

### Type

> Operation kis type mein hoga?

Dono ko mix nahi karna.

Example:

```cpp
int x = 10 + 5 * 2;
```

Multiplication pehle:

```text
5 * 2 = 10

10 + 10 = 20
```

So:

```text
x = 20
```

---

## Type + precedence together

```cpp
double x = 10 / 4 * 2.0;
```

Operators same precedence group mein left-to-right evaluate honge.

Pehle:

```text
10 / 4
```

Both integers:

```text
2
```

Then:

```text
2 * 2.0
```

→ `4.0`

So:

```text
x = 4.0
```

⚠️ Agar tum socho:

```text
10 / 4 * 2.0
= 2.5 * 2
= 5
```

to wrong, because `10 / 4` pehle integer division kar chuka hai.

---

# 5. Parentheses se Control

Agar tum chahte ho:

```text
10 / (4 * 2.0)
```

to:

```cpp
double x = 10 / (4 * 2.0);
```

Calculation:

```text
4 * 2.0
↓
8.0

10 / 8.0
↓
1.25
```

So:

```text
x = 1.25
```

### Lesson:

> **Precedence decide karta hai order; types decide karte hain operation ka nature.**

---

# 6. Type Conversion Traps

## Trap #1

```cpp
double x = 10 / 4;
```

→ `2.0`

not `2.5`.

---

## Trap #2

```cpp
int x = 10.9;
```

Fractional portion lost:

```text
10.9 → 10
```

---

## Trap #3

```cpp
int x = static_cast<int>(10.9);
```

→ `10`

Again, truncation.

---

## Trap #4

```cpp
char ch = '5';

int x = ch;
```

`x` becomes the character's numeric encoding value, not numeric digit `5`.

For digit conversion:

```cpp
int x = ch - '0';
```

---

# 7. Integer Overflow

Typical 32-bit signed `int` range:

```text
-2,147,483,648
to
 2,147,483,647
```

Suppose:

```cpp
int x = 2147483647;
```

Then:

```cpp
x = x + 1;
```

This is **signed integer overflow**, which is undefined behavior in C++.

Don't rely on a particular wrapped value.

---

# 8. Multiplication Overflow Trap

This one is VERY important for DSA.

```cpp
int a = 100000;
int b = 100000;

long long result = a * b;
```

Tum dekh kar keh sakte ho:

> Result `long long` hai, safe hai.

But not necessarily.

Because:

```text
a * b
↓
int * int
↓
calculation occurs as int
↓
potential overflow
↓
then result gets assigned to long long
```

Correct:

```cpp
long long result = 1LL * a * b;
```

or:

```cpp
long long result =
    static_cast<long long>(a) * b;
```

---

# 9. Why `1LL`?

```cpp
1LL
```

means a `long long` integer literal.

Therefore:

```cpp
1LL * a
```

makes the arithmetic happen in a wider integer type.

Then:

```text
long long × int
↓
long long
```

---

# 10. Overflow + Addition

Suppose:

```cpp
int a = 2'000'000'000;
int b = 2'000'000'000;

long long sum = a + b;
```

Again, danger.

`a + b` is calculated before assignment:

```text
int + int
↓
potential overflow
↓
then assignment
```

Correct:

```cpp
long long sum = 1LL * a + b;
```

Now calculation is performed in `long long`.

---

# 11. Overflow + Multiplication in Expressions

Look at:

```cpp
long long x = a * b * c;
```

If all three are `int`, the expression can overflow during intermediate calculations.

Safer:

```cpp
long long x = 1LL * a * b * c;
```

Because first operation already becomes `long long`.

---

# 12. Type Conversion Trap with Negative Division

Another interesting one:

```cpp
cout << -7 / 2;
```

Both integral:

```text
-7 / 2
```

C++ integer division truncates toward zero.

Result:

```text
-3
```

Not `-4`.

So:

```text
7 / 2   → 3
-7 / 2  → -3
```

This is important.

---

# 13. `%` aur Integer Division Connection

Modulo `%` remainder deta hai.

```cpp
cout << 7 % 2;
```

→ `1`

Because:

```text
7 = 2 × 3 + 1
```

And:

```cpp
cout << 7 / 2;
```

→ `3`

So:

```text
/ → quotient
% → remainder
```

Ye DSA mein **extremely important** hai.

---

# 14. Integer Division ka Practical Use

Suppose seconds:

```cpp
int seconds = 367;
```

Minutes:

```cpp
int minutes = seconds / 60;
```

→ `6`

Remaining seconds:

```cpp
int remaining = seconds % 60;
```

→ `7`

So:

```text
367 seconds
↓
6 minutes + 7 seconds
```

Yahan integer division aur modulo dono naturally use hue.

---

# 15. Interview-Style Output Questions 😈

Ab actual brain-training.

### Q1

```cpp
int a = 10;
int b = 3;

cout << a / b;
```

Output?

**Answer:** `3`

---

### Q2

```cpp
double x = 10 / 3;
cout << x;
```

Output conceptually:

```text
3
```

because integer division happened first.

---

### Q3

```cpp
double x = 10.0 / 3;
cout << x;
```

Approximately:

```text
3.33333...
```

Exact displayed digits formatting par depend karte hain.

---

### Q4

```cpp
int a = 5;
int b = 2;

cout << a / b + 1;
```

Precedence:

```text
5 / 2
↓
2

2 + 1
↓
3
```

Output:

```text
3
```

---

### Q5

```cpp
double x = 5 / 2 * 2.0;
```

Step:

```text
5 / 2
↓
2

2 * 2.0
↓
4.0
```

Answer:

```text
4.0
```

---

### Q6 🔥

```cpp
int x = 5;

cout << x++ << " " << ++x;
```

Let's dry run:

Initially:

```text
x = 5
```

`x++`:

```text
print 5
x becomes 6
```

Then `++x`:

```text
x becomes 7
print 7
```

Output:

```text
5 7
```

---

# 🧩 Part E — Practice

Ab proper progression:

```text
Easy
 ↓
Medium
 ↓
Tricky
 ↓
Interview-style
```

Main abhi **solutions nahi de raha**, because actual PF mastery tab aati hai jab tum khud dry-run karte ho.

---

# 🟢 Level 1 — Easy

### Q1

```cpp
int a = 10;
int b = 5;

cout << a + b;
```

Output?

---

### Q2

```cpp
double x = 5.5;
int y = 2;

cout << x + y;
```

Output?

---

### Q3

```cpp
int x = 10;

x = 20;

cout << x;
```

Output?

---

### Q4

```cpp
char ch = 'A';

cout << ch;
```

Output?

---

# 🟡 Level 2 — Medium

### Q5

```cpp
int a = 9;
int b = 2;

cout << a / b;
```

---

### Q6

```cpp
int a = 9;
int b = 2;

cout << static_cast<double>(a) / b;
```

---

### Q7

```cpp
char ch = '7';

int x = ch - '0';

cout << x;
```

---

### Q8

```cpp
int x = 5;

cout << x++ << endl;
cout << x;
```

---

# 🟠 Level 3 — Tricky

### Q9

```cpp
double x = 10 / 4;

cout << x;
```

**Important:** result variable ko dekh kar answer mat dena. Pehle expression solve karo.

---

### Q10

```cpp
double x = 10 / 4.0;

cout << x;
```

---

### Q11

```cpp
double x = 10 / 4 * 2.0;

cout << x;
```

---

### Q12

```cpp
int a = 7;
int b = 2;

double x = a / b + 0.5;

cout << x;
```

---

# 🔴 Level 4 — Interview Style

### Q13

```cpp
int a = 100000;
int b = 100000;

long long x = a * b;
```

Question:

**Kya ye calculation safe hai? Why/why not?**

---

### Q14

```cpp
int a = 100000;
int b = 100000;

long long x = 1LL * a * b;
```

Q13 se difference kya hai?

---

### Q15 😈

```cpp
int x = 10;

cout << x++ << " ";
cout << ++x << " ";
cout << x;
```

Output?

**Har line ko execute karke dry run karo.**

---

### Q16 🔥

```cpp
int a = 7;
int b = 2;

double x = a / b;
double y = static_cast<double>(a) / b;

cout << x << " " << y;
```

Output?

Aur **x aur y different kyun hain?**

---

### Q17 — Real DSA Thinking

```cpp
int seconds = 367;

int minutes = seconds / 60;
int remaining = seconds % 60;

cout << minutes << " " << remaining;
```

Output?

Aur explain karo `/` aur `%` dono kyun use hue.

---

# 🧠 Part D + E ka Final Takeaway

Chapter 2 ke end tak tumhara brain ye checks **automatically** karna chahiye:

```text
Expression dekha
      ↓
Operators kya hain?
      ↓
Precedence kya hai?
      ↓
Operands ke types kya hain?
      ↓
Integer division ho rahi?
      ↓
Conversion ho rahi?
      ↓
Result range se bahar to nahi?
      ↓
Output format kya hai?
```

Ye habit **DSA ke time bohat powerful** hogi.

Especially ye 4 traps kabhi bhoolna nahi:

```cpp
double x = 5 / 2;
```

→ `2.0`, not `2.5`

```cpp
long long x = a * b;
```

→ `long long` variable alone intermediate overflow ko prevent nahi karta.

```cpp
char ch = '5';
```

→ `'5'` character hai, numeric `5` nahi.

```cpp
int x = 10.9;
```

→ fractional part lost; automatic conversion rounding nahi karti.

**Ab Part A → B → C → D → E mila kar Chapter 2 complete hai.** 🔒