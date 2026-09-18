# 📘 PF Chapter 2 — Variables & Data Types

Is chapter ka goal ye hai ke tumhe clearly samajh aaye:

> **Data memory mein kaise store hota hai, variable kya hota hai, data type kyun hota hai, aur C++ kis tarah decide karta hai ke kitni memory aur kis type ka data rakhna hai.**

---

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



# Part 1 — Variables ka core concept

### Variable

```cpp
int age = 20;
```

* `int` → type
* `age` → variable
* `20` → value

### Declaration

```cpp
int age;
```

### Initialization

```cpp
int age = 20;
```

### Assignment

```cpp
age = 25;
```

Difference:

```cpp
int age = 20;  // initialization
age = 25;      // assignment
```

---

# Part 2 — Basic Data Types

## `int`

Whole numbers:

```cpp
int x = 10;
int y = -50;
```

---

## `float`

Decimal:

```cpp
float price = 12.5f;
```

`f` batata hai ke literal ko `float` treat karna hai.

---

## `double`

More precision wala floating-point type:

```cpp
double pi = 3.1415926535;
```

Generally normal decimal calculations mein `double` use karna common hai.

---

## `char`

One character:

```cpp
char grade = 'A';
```

Single quotes.

---

## `bool`

True/false:

```cpp
bool passed = true;
bool failed = false;
```

---

# Part 3 — `int` aur `double` ka dangerous difference

Ye **bohat important** hai.

Dekho:

```cpp
int a = 5;
int b = 2;

cout << a / b;
```

Tum logically soch sakte ho:

```text
5 / 2 = 2.5
```

Lekin output:

```text
2
```

### WHY?

Dono operands `int` hain:

```text
5 / 2
↓
integer division
↓
2
```

Decimal part discard ho jata hai.

---

### Agar:

```cpp
double a = 5;
double b = 2;

cout << a / b;
```

Output approximately:

```text
2.5
```

---

### Aur ye dekho:

```cpp
cout << 5 / 2;
```

→ `2`

Lekin:

```cpp
cout << 5.0 / 2;
```

→ `2.5`

Because `5.0` floating-point value hai.

---

# 🔥 Very Important Rule

> **Division ka result sirf assignment variable ke type se decide nahi hota; operands ke types bhi matter karte hain.**

Example:

```cpp
double result = 5 / 2;
```

Kya result `2.5` hoga?

❌ Nahi.

Pehle:

```text
5 / 2
↓
2
```

phir:

```text
2 → double
```

So:

```text
result = 2.0
```

---

### Correct:

```cpp
double result = 5.0 / 2;
```

→ `2.5`

Ye interview/output questions mein frequently test hota hai.

---

# Part 4 — Type Conversion

Ek type ki value ko doosre type mein convert karna.

Example:

```cpp
int x = 10;
double y = x;
```

Conceptually:

```text
int 10
 ↓
double 10.0
```

Ye generally safe conversion hai because `double` integer values ko represent kar sakta hai within its precision limits.

---

# Part 5 — Implicit Conversion

Compiler automatically conversion kar de.

```cpp
int x = 10;
double y = x;
```

Compiler effectively:

```text
int → double
```

automatically kar raha hai.

Isko **implicit conversion** kehte hain.

---

# Part 6 — Explicit Conversion / Casting

Hum khud compiler ko bolte hain:

> Is value ko doosre type mein treat karo.

Modern C++ mein:

```cpp
double result = static_cast<double>(5) / 2;
```

Ab:

```text
5 → 5.0
5.0 / 2 → 2.5
```

Output:

```text
2.5
```

---

## Example

```cpp
int a = 5;
int b = 2;

double result = static_cast<double>(a) / b;

cout << result;
```

Output:

```text
2.5
```

---

# Part 7 — Character aur ASCII

`char` internally numeric representation rakhta hai.

Example:

```cpp
char ch = 'A';

cout << ch;
```

Output:

```text
A
```

Lekin:

```cpp
cout << static_cast<int>(ch);
```

ASCII encoding mein:

```text
65
```

Similarly commonly:

```text
'A' → 65
'B' → 66
'C' → 67
```

Lowercase:

```text
'a' → 97
'b' → 98
```

Is concept ka use baad mein strings, character problems aur DSA mein hota hai.

---

# Part 8 — Character arithmetic

Ab interesting:

```cpp
char ch = 'A';

cout << ch + 1;
```

Output:

```text
66
```

Why?

`ch` arithmetic mein promote ho kar integer value use karta hai:

```text
'A'
↓
65
↓
65 + 1
↓
66
```

Agar next character chahiye:

```cpp
char next = ch + 1;

cout << next;
```

Output:

```text
B
```

---

# Part 9 — `bool` ka actual behavior

```cpp
bool x = true;
bool y = false;
```

C++ mein streams normally:

```cpp
cout << x;
```

→

```text
1
```

and:

```cpp
cout << y;
```

→

```text
0
```

Agar readable form chahiye:

```cpp
cout << boolalpha << x;
```

→

```text
true
```

---

# Part 10 — `const`

Agar value change nahi honi:

```cpp
const int DAYS = 7;
```

Then:

```cpp
DAYS = 10;
```

❌ Error.

Useful examples:

```cpp
const double PI = 3.141592653589793;
const int MONTHS = 12;
```

---

# Part 11 — Variable Naming

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

Aur:

```cpp
int int;
```

❌ because `int` keyword hai.

---

# Part 12 — Case Sensitivity

C++ mein:

```cpp
age
Age
AGE
```

teen different identifiers hain.

```cpp
int age = 20;

cout << Age;
```

❌ `Age` naam ka variable declared nahi hua.

---

# Part 13 — Scope ka basic idea

Variable har jagah accessible nahi hota.

Example:

```cpp
int main()
{
    int x = 10;

    cout << x;
}
```

`x` yahan accessible hai.

Lekin:

```cpp
if (true)
{
    int y = 20;
}

cout << y;
```

❌

Because `y` ka scope `if` block ke andar tha.

Concept:

```text
{
    variable exists here
}
```

Block khatam:

```text
variable ka scope khatam
```

Scope ko hum Chapter 7/8 mein aur deeply cover karenge.

---

# Part 14 — Memory aur `sizeof`

C++ mein:

```cpp
sizeof()
```

se type/variable ki memory size check kar sakte hain.

Example:

```cpp
cout << sizeof(int);
```

Common systems par output often:

```text
4
```

Similarly commonly:

```cpp
sizeof(char)   → 1
sizeof(bool)   → 1
sizeof(float)  → 4
sizeof(double) → 8
```

⚠️ Lekin important:

> Ye sizes language mein har platform par universally fixed nahi hain.

Isliye interview mein blindly ye mat kehna ke "`int` always 4 bytes hota hai." Better:

> `int` is at least 16 bits, and on many modern systems it is 32 bits (commonly 4 bytes).

---

# Part 15 — Integer Overflow

Ye DSA ke liye **bohat important** hai.

Suppose:

```cpp
int x = 2147483647;
```

Typical 32-bit `int` ka maximum:

```text
2147483647
```

Ab:

```cpp
x = x + 1;
```

Problem ho sakti hai because value `int` range se bahar chali gayi.

Conceptually:

```text
maximum limit
      ↓
2147483647
      +
      1
      ↓
range exceeded
```

Signed integer overflow in C++ is **undefined behavior**, so exact result assume nahi karna chahiye.

---

# Part 16 — `long long`

Large integers ke liye:

```cpp
long long x = 1000000000000LL;
```

`LL` literal ko `long long` type ke liye indicate karta hai.

DSA mein ye bohat commonly use hoga.

Example:

```cpp
long long sum = 0;
```

Agar array ke numbers ka sum potentially large ho, `int` ki jagah `long long` useful ho sakta hai.

---

# Part 17 — `unsigned`

Basic idea:

```cpp
unsigned int x;
```

Unsigned integer negative values represent nahi karta; uski available range non-negative values ke liye hoti hai.

Example:

```cpp
unsigned int x = 10;
```

Lekin PF ke is stage par **unsigned ko blindly use mat karna**. Signed/unsigned mixing later tricky bugs create kar sakti hai.

---

# Part 18 — Multiple Variables

```cpp
int a = 10;
int b = 20;
int c = 30;
```

Same type ko ek line mein bhi declare kar sakte ho:

```cpp
int a = 10, b = 20, c = 30;
```

Lekin readability ke liye separate declarations often easier hoti hain.

---

# Part 19 — Assignment ka real concept

Dekho:

```cpp
int a = 10;
int b = 20;

a = b;
```

Iske baad:

```text
a = 20
b = 20
```

`a = b` ka matlab:

> **b ki value copy karke a mein store karo.**

Ye nahi:

> a aur b ko permanently connect kar do.

Isliye:

```cpp
a = b;
a = 50;
```

Now:

```text
a = 50
b = 20
```

---

# Part 20 — Increment / Decrement

Ye variables ke saath bohat important hain.

```cpp
int x = 5;

x++;
```

Now:

```text
x = 6
```

Similarly:

```cpp
x--;
```

→ `5`

---

## `x++` vs `++x`

Ye especially important hai.

### Post-increment

```cpp
int x = 5;
int y = x++;
```

Pehle old value use:

```text
y = 5
```

phir:

```text
x = 6
```

---

### Pre-increment

```cpp
int x = 5;
int y = ++x;
```

Pehle increment:

```text
x = 6
```

phir value use:

```text
y = 6
```

### Mental rule:

```text
x++ → use first, increase later
++x → increase first, use later
```

---

# 🔥 Part 21 — Tricky Output Questions

Ab actual PF wali practice.

### Question 1

```cpp
int a = 10;
int b = a;

a = 20;

cout << a << " " << b;
```

Output:

```text
20 10
```

Because `b = a` ne **value copy** ki thi.

---

### Question 2

```cpp
int a = 5;
int b = 2;

double x = a / b;

cout << x;
```

Output:

```text
2
```

Technically displayed as `2`/`2.0` depending on formatting.

Reason:

```text
a / b
5 / 2
↓
integer division
↓
2
↓
double
```

---

### Question 3

```cpp
double x = 5 / 2;

cout << x;
```

Again:

```text
2
```

---

### Question 4

```cpp
double x = 5.0 / 2;

cout << x;
```

→

```text
2.5
```

---

### Question 5

```cpp
int x = 5;

cout << x++ << endl;
cout << x;
```

Output:

```text
5
6
```

---

### Question 6

```cpp
int x = 5;

cout << ++x << endl;
cout << x;
```

Output:

```text
6
6
```

---

# 🧠 Chapter 2 ka Master Mental Model

Ab jab tum koi variable dekho:

```cpp
long long total = 500;
```

Tumhare dimagh mein ye sequence hona chahiye:

```text
long long
    ↓
data type
    ↓
memory/range representation

total
    ↓
variable name

500
    ↓
stored value
```

Aur jab expression dekho:

```cpp
5 / 2
```

turant check:

```text
Operands kis type ke hain?
        ↓
int + int
        ↓
integer division
        ↓
2
```

Agar:

```cpp
5.0 / 2
```

then:

```text
double + int
        ↓
floating-point calculation
        ↓
2.5
```

---

# 🎯 Chapter 2 — Final Checklist

Agar ye concepts tum explain kar sakte ho, **Chapter 2 complete**:

* ✅ Variable
* ✅ Declaration
* ✅ Initialization
* ✅ Assignment
* ✅ `int`
* ✅ `float`
* ✅ `double`
* ✅ `char`
* ✅ `bool`
* ✅ `const`
* ✅ Naming rules
* ✅ Case sensitivity
* ✅ Scope ka basic idea
* ✅ `sizeof`
* ✅ Memory basics
* ✅ Type conversion
* ✅ Implicit conversion
* ✅ Explicit casting
* ✅ Integer division
* ✅ Character/ASCII concept
* ✅ `bool` representation
* ✅ `long long`
* ✅ Integer overflow
* ✅ `++x` vs `x++`
* ✅ Value copying

### 🚨 Sabse important 5 cheezen

Agar interview/DSA perspective se priority lagani ho:

- **1. Integer division**
- **2. Type conversion/casting**
- **3. Overflow + `long long`**
- **4. Pre/post increment**
- **5. Variable/value vs memory ka concept**

---

## 🧪 Chapter 2 Final Test

Ab main solution nahi de raha. 😈 Tum khud solve karo.

### Q1

```cpp
int a = 7;
int b = 2;

double result = a / b;

cout << result;
```

Output + reason.

### Q2

```cpp
int x = 5;
int y = x++;

cout << x << " " << y;
```

Output + reason.

### Q3

```cpp
int x = 5;
int y = ++x;

cout << x << " " << y;
```

Output + reason.

### Q4

```cpp
char ch = 'A';

cout << static_cast<int>(ch);
```

Output?

### Q5 — conceptual

Explain in your own words:

> **`double result = 5 / 2;` mein `2.5` kyun nahi aata?**
