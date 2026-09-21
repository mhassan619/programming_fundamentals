# 🧠 Chapter 4 — Conditional Statements

## Part A — Condition kya hoti hai?

Condition basically ek aisa expression hota hai jiska result:

```text
true
```

ya

```text
false
```

hota hai.

Example:

```cpp
int age = 20;

age >= 18
```

Check:

```text
20 >= 18
```

Result:

```text
true
```

Another:

```cpp
age < 18
```

Result:

```text
false
```

---

# Part B — `if` Statement

Sabse basic conditional statement:

```cpp
if (condition)
{
    // code
}
```

Example:

```cpp
int age = 20;

if (age >= 18)
{
    cout << "Adult";
}
```

### Dry run

Initial:

```text
age = 20
```

Condition:

```text
age >= 18
20 >= 18
true
```

Condition true hai, therefore block execute hoga:

```text
Adult
```

---

## Agar condition false ho?

```cpp
int age = 15;

if (age >= 18)
{
    cout << "Adult";
}
```

Check:

```text
15 >= 18
false
```

So block execute nahi hoga.

Output:

```text
nothing
```

### Important mental model:

```text
if
 ↓
condition?
 ↓
 ├── true  → block execute
 └── false → block skip
```

---

# Part C — `if-else`

Ab agar condition false ho to hum alternate kaam kar sakte hain.

Syntax:

```cpp
if (condition)
{
    // true
}
else
{
    // false
}
```

Example:

```cpp
int age = 15;

if (age >= 18)
{
    cout << "Adult";
}
else
{
    cout << "Minor";
}
```

Dry run:

```text
age = 15

15 >= 18
↓
false
```

So `if` block skip.

`else` execute:

```text
Minor
```

---

# 🔥 `if-else` ka simple flow

```text
             condition
                 ↓
           ┌─────┴─────┐
         true         false
          ↓              ↓
       IF block       ELSE block
```

**Sirf ek branch execute hoti hai.**

---

# Part D — `else if`

Kabhi humein **2 nahi, multiple conditions** check karni hoti hain.

Example grading:

```text
90+ → A
80+ → B
70+ → C
60+ → D
otherwise → F
```

Code:

```cpp
int marks = 85;

if (marks >= 90)
{
    cout << "A";
}
else if (marks >= 80)
{
    cout << "B";
}
else if (marks >= 70)
{
    cout << "C";
}
else if (marks >= 60)
{
    cout << "D";
}
else
{
    cout << "F";
}
```

### Dry run

`marks = 85`

First:

```text
85 >= 90
false
```

Next:

```text
85 >= 80
true
```

So:

```text
B
```

And **baqi conditions check nahi hotin**.

---

# ⚠️ Very Important: `else if` chain stops

Example:

```cpp
int x = 90;

if (x >= 50)
{
    cout << "Pass";
}
else if (x >= 80)
{
    cout << "Excellent";
}
```

Output:

```text
Pass
```

Why?

First condition:

```text
90 >= 50
true
```

So first block execute ho gaya.

C++ second condition tak pohanchta hi nahi.

### Therefore:

`else if` mein **order matters**.

---

# Part E — Condition Ordering

Ye bohat common mistake hai.

Suppose:

```cpp
int marks = 95;

if (marks >= 50)
{
    cout << "Pass";
}
else if (marks >= 90)
{
    cout << "A";
}
```

Tum expect kar sakte ho:

```text
A
```

Lekin output:

```text
Pass
```

because:

```text
95 >= 50
```

already true tha.

### Correct order:

Specific/high conditions pehle:

```cpp
if (marks >= 90)
{
    cout << "A";
}
else if (marks >= 50)
{
    cout << "Pass";
}
```

---

# Part F — Nested `if`

Ab ek `if` ke andar doosra `if`.

Example:

```cpp
int age = 20;
bool hasCard = true;

if (age >= 18)
{
    if (hasCard)
    {
        cout << "Allowed";
    }
}
```

### Dry run

First:

```text
age >= 18
20 >= 18
true
```

Ab inner condition:

```text
hasCard
true
```

So:

```text
Allowed
```

---

## Nested if ko mentally aise dekho

```text
if age >= 18?
       |
      yes
       ↓
   hasCard?
       |
      yes
       ↓
    Allowed
```

Agar first condition false ho gayi, inner `if` tak program pohanchta hi nahi.

---

# Part G — Nested `if` vs `&&`

Ye dono kabhi same logic represent kar sakte hain.

Nested:

```cpp
if (age >= 18)
{
    if (hasCard)
    {
        cout << "Allowed";
    }
}
```

Combined:

```cpp
if (age >= 18 && hasCard)
{
    cout << "Allowed";
}
```

Dono ka basic condition same ho sakta hai.

### Lekin mental difference:

Nested form:

> Pehle age check karo, phir card check karo.

`&&`:

> Dono conditions simultaneously required hain.

Usually simple conditions ke liye:

```cpp
if (age >= 18 && hasCard)
```

cleaner hota hai.

---

# Part H — Boolean Conditions

`if` ko zaroori nahi ke comparison hi diya jaye.

Example:

```cpp
bool isLoggedIn = true;

if (isLoggedIn)
{
    cout << "Welcome";
}
```

Since:

```text
isLoggedIn = true
```

block execute hoga.

---

## `bool` false

```cpp
bool isLoggedIn = false;

if (isLoggedIn)
{
    cout << "Welcome";
}
```

Nothing prints.

---

# Part I — Truthy / Falsy in C++

C++ mein condition ke andar integer bhi use kar sakte ho.

```cpp
if (5)
{
    cout << "YES";
}
```

`5` non-zero hai → treated as `true`.

So:

```text
5 → true
```

Similarly:

```cpp
if (-10)
```

also true.

But:

```cpp
if (0)
```

false.

### Rule:

```text
0       → false
non-zero → true
```

Ye concept bohat important hai.

---

# Part J — Common Trap: `if (x = 5)`

Ye Chapter 3 mein bhi dekha tha, ab conditional context mein important hai.

```cpp
int x = 10;

if (x = 5)
{
    cout << "YES";
}
```

Yahan:

```cpp
x = 5
```

assignment hai.

Ab:

```text
x = 5
```

aur expression ki value:

```text
5
```

5 non-zero hai → `true`.

Therefore:

```text
YES
```

print hoga.

### Correct:

```cpp
if (x == 5)
```

---

# Part K — Multiple Conditions

Suppose:

> Number positive AND even hona chahiye.

```cpp
int n = 8;

if (n > 0 && n % 2 == 0)
{
    cout << "Positive Even";
}
```

Break it:

```text
n > 0
8 > 0
true
```

and:

```text
n % 2 == 0
8 % 2 == 0
0 == 0
true
```

So:

```text
true && true
```

Result:

```text
Positive Even
```

---

# Part L — `if / else if / else` ka real example

Number classify karte hain:

```text
positive
negative
zero
```

Code:

```cpp
int n;

cin >> n;

if (n > 0)
{
    cout << "Positive";
}
else if (n < 0)
{
    cout << "Negative";
}
else
{
    cout << "Zero";
}
```

### Agar input:

```text
-7
```

Then:

```text
-7 > 0 → false
-7 < 0 → true
```

Output:

```text
Negative
```

### Input:

```text
0
```

Both comparisons false:

```text
0 > 0 → false
0 < 0 → false
```

So `else`:

```text
Zero
```

---

# Part M — Multiple Independent `if`s vs `else if`

Ye **bohat important distinction** hai.

### Case 1: `else if`

```cpp
int x = 10;

if (x > 0)
{
    cout << "Positive ";
}
else if (x < 20)
{
    cout << "Less than 20";
}
```

First condition true hai, so second **check nahi hogi**.

Output:

```text
Positive
```

---

### Case 2: Separate `if`

```cpp
int x = 10;

if (x > 0)
{
    cout << "Positive ";
}

if (x < 20)
{
    cout << "Less than 20";
}
```

Ab dono independent hain.

Dono true:

```text
Positive Less than 20
```

### Golden difference:

```text
else if
```

means:

> **In alternatives mein se pehli matching branch.**

Separate `if`s:

> **Har condition independently check karo.**

---

# Part N — Braces `{}` ka importance

Ye dekho:

```cpp
if (x > 0)
{
    cout << "Positive";
    cout << "Number";
}
```

Dono statements condition ke andar hain.

Lekin:

```cpp
if (x > 0)
    cout << "Positive";

cout << "Number";
```

Sirf first statement `if` ka part hai.

`cout << "Number";` **always execute** hoga.

---

# ⚠️ Classic beginner trap

```cpp
if (x > 0)
    cout << "Positive";
    cout << "Number";
```

Indentation dekh kar lagta hai dono `if` ke andar hain.

Lekin C++ indentation nahi dekhta.

Actually:

```cpp
if (x > 0)
    cout << "Positive";

cout << "Number";
```

Isliye PF mein abhi se habit banao:

```cpp
if (condition)
{
    ...
}
```

Braces use karo.

---

# Part O — Dangling `else`

Nested conditions mein `else` kis `if` ke saath attach hota hai, ye tricky ho sakta hai.

Example:

```cpp
if (x > 0)
    if (x > 10)
        cout << "A";
    else
        cout << "B";
```

Yahan `else` **nearest unmatched `if`** ke saath attach hota hai.

Yani:

```cpp
if (x > 10)
```

wala `if`.

Is confusion se bachne ka best tareeqa:

```cpp
if (x > 0)
{
    if (x > 10)
    {
        cout << "A";
    }
    else
    {
        cout << "B";
    }
}
```

---

# 🧠 Chapter 4 ka Mental Map — Part 1

```text
Conditional Statements
│
├── if
│
├── if-else
│
├── else-if
│
├── nested if
│
├── boolean conditions
│
├── truthy/falsy integers
│
├── multiple conditions
│   ├── &&
│   └── ||
│
├── separate if vs else-if
│
├── braces
│
└── dangling else
```

Bhai yahan tak ek cheez especially yaad rakhna:

> **`if` decision leta hai, `else if` alternatives check karta hai, aur `else` tab chalta hai jab upar ki koi condition true na ho.**

# Part P — `switch` Statement

`switch` ka use tab hota hai jab humein **ek value ko multiple fixed options ke against compare** karna ho.

Example:

```cpp
int day = 3;

switch (day)
{
    case 1:
        cout << "Monday";
        break;

    case 2:
        cout << "Tuesday";
        break;

    case 3:
        cout << "Wednesday";
        break;

    default:
        cout << "Invalid day";
}
```

Output:

```text
Wednesday
```

---

# 🧠 `switch` ka flow

Agar:

```cpp
day = 3;
```

to C++ dekhega:

```text
case 1? ❌
case 2? ❌
case 3? ✅
```

Then:

```cpp
cout << "Wednesday";
```

---

# Part Q — `case` kya karta hai?

Syntax:

```cpp
switch (expression)
{
    case value1:
        // code

    case value2:
        // code
}
```

Example:

```cpp
int choice = 2;

switch (choice)
{
    case 1:
        cout << "Add";
        break;

    case 2:
        cout << "Delete";
        break;

    case 3:
        cout << "Exit";
        break;
}
```

Since:

```text
choice = 2
```

`case 2` execute hoga.

Output:

```text
Delete
```

---

# 🔥 Part R — `break` kyun lagate hain?

Ye **switch ka sabse important concept** hai.

Example:

```cpp
int x = 2;

switch (x)
{
    case 1:
        cout << "One";
        break;

    case 2:
        cout << "Two";
        break;

    case 3:
        cout << "Three";
        break;
}
```

Output:

```text
Two
```

`break` ka matlab:

> **Switch se bahar nikal jao.**

---

# ⚠️ `break` remove kar do to?

```cpp
int x = 2;

switch (x)
{
    case 1:
        cout << "One";

    case 2:
        cout << "Two";

    case 3:
        cout << "Three";
}
```

Ab `x = 2`.

`case 2` match hua:

```text
Two
```

Lekin `break` nahi hai.

To C++ neeche continue karega:

```text
Two
Three
```

Output:

```text
TwoThree
```

Is behavior ko kehte hain:

> **Fall-through**

---

# 🧠 Fall-through ko visually samjho

```text
case 2 matched
     ↓
  "Two"
     ↓
 no break
     ↓
  "Three"
     ↓
 switch ends
```

Normally jab tumhe sirf matching case execute karna ho:

```cpp
case 2:
    cout << "Two";
    break;
```

---

# Part S — `default`

Agar **koi bhi case match na kare**, `default` execute hota hai.

Example:

```cpp
int day = 8;

switch (day)
{
    case 1:
        cout << "Monday";
        break;

    case 2:
        cout << "Tuesday";
        break;

    case 3:
        cout << "Wednesday";
        break;

    default:
        cout << "Invalid day";
}
```

`8` ka koi case nahi.

So:

```text
Invalid day
```

### Mental model:

```text
case 1? ❌
case 2? ❌
case 3? ❌
        ↓
     default
```

---

# Part T — `switch` kis type ke data ke saath?

Beginner level par common:

```cpp
int
char
```

Example with `char`:

```cpp
char grade = 'A';

switch (grade)
{
    case 'A':
        cout << "Excellent";
        break;

    case 'B':
        cout << "Good";
        break;

    case 'C':
        cout << "Average";
        break;

    default:
        cout << "Invalid";
}
```

Output:

```text
Excellent
```

---

# ⚠️ `case` mein condition nahi likhte

Wrong:

```cpp
switch (x)
{
    case x > 10:
        cout << "Big";
}
```

`case` normally **constant matching value** deta hai, condition nahi.

Agar tumhe range check karni ho:

```text
x > 10
x >= 50
x < 100
```

to `if-else` zyada suitable hai.

---

# Part U — `switch` vs `if-else`

Ye distinction bohat important hai.

## `switch`

Jab ek value ke **fixed exact options** hon:

```text
1 → Add
2 → Delete
3 → Update
4 → Exit
```

Use:

```cpp
switch(choice)
```

---

## `if-else`

Jab **ranges ya complex conditions** hon:

```text
marks >= 90
age >= 18
x > 0 && x % 2 == 0
```

Use:

```cpp
if / else if
```

### Example

Ye `switch` ke liye natural hai:

```cpp
int choice = 3;

switch (choice)
{
    case 1:
        cout << "Add";
        break;

    case 2:
        cout << "Delete";
        break;

    case 3:
        cout << "Update";
        break;
}
```

Lekin:

```cpp
if (marks >= 90)
```

ke liye `switch` natural choice nahi hai.

---

# Part V — Menu-Based Program

`switch` ka bohat common real-world use **menu** hai.

```cpp
int choice;

cout << "1. Add\n";
cout << "2. Delete\n";
cout << "3. Search\n";
cout << "4. Exit\n";

cin >> choice;

switch (choice)
{
    case 1:
        cout << "Add selected";
        break;

    case 2:
        cout << "Delete selected";
        break;

    case 3:
        cout << "Search selected";
        break;

    case 4:
        cout << "Exit selected";
        break;

    default:
        cout << "Invalid choice";
}
```

Ye pattern future mein **loops + functions + DSA projects** mein bhi kaam aayega.

---

# Part W — Multiple Cases Same Code

Suppose:

```text
1 → Monday
2 → Tuesday
...
7 → Sunday
```

Aur tum check karna chahte ho ke day weekend hai ya nahi.

Tum multiple cases ko same block mein group kar sakte ho:

```cpp
int day = 6;

switch (day)
{
    case 6:
    case 7:
        cout << "Weekend";
        break;

    default:
        cout << "Weekday";
}
```

Dry run:

```text
day = 6
↓
case 6 matched
↓
no code
↓
case 7
↓
"Weekend"
↓
break
```

Output:

```text
Weekend
```

Ye intentional **fall-through** hai.

---

# Part X — Nested Conditions: Real Problem

Ab thoda problem-solving.

### Problem:

Ek number diya hai. Determine karo:

* positive even
* positive odd
* negative
* zero

Code:

```cpp
int n;
cin >> n;

if (n > 0)
{
    if (n % 2 == 0)
    {
        cout << "Positive Even";
    }
    else
    {
        cout << "Positive Odd";
    }
}
else if (n < 0)
{
    cout << "Negative";
}
else
{
    cout << "Zero";
}
```

### Input:

```text
8
```

Dry run:

```text
8 > 0
true
```

Inside:

```text
8 % 2 == 0
0 == 0
true
```

Output:

```text
Positive Even
```

---

# Part Y — Same Problem using `&&`

Nested version:

```cpp
if (n > 0)
{
    if (n % 2 == 0)
        cout << "Positive Even";
    else
        cout << "Positive Odd";
}
```

Isko partially simplify kar sakte hain:

```cpp
if (n > 0 && n % 2 == 0)
{
    cout << "Positive Even";
}
else if (n > 0 && n % 2 != 0)
{
    cout << "Positive Odd";
}
else if (n < 0)
{
    cout << "Negative";
}
else
{
    cout << "Zero";
}
```

Dono approaches possible hain.

### Problem-solving lesson:

> Code likhne se pehle decide karo ke conditions ka **structure** kya hai.

---

# Part Z — Validation Logic 🔥

Conditional statements ka ek bohat important use hai:

> **Input valid hai ya nahi?**

Example:

```cpp
int age;
cin >> age;

if (age < 0)
{
    cout << "Invalid age";
}
else
{
    cout << "Valid age";
}
```

Multiple constraints:

```cpp
int marks;
cin >> marks;

if (marks >= 0 && marks <= 100)
{
    cout << "Valid";
}
else
{
    cout << "Invalid";
}
```

Yahan:

```text
marks >= 0
```

AND

```text
marks <= 100
```

**dono** true hone chahiye.

---

# 🔥 Range Conditions

Suppose:

> Number 10 se 20 ke beech hai.

Correct:

```cpp
if (x >= 10 && x <= 20)
```

Not:

```cpp
if (10 <= x <= 20)
```

C++ mein second form ko mathematical chained comparison ki tarah use nahi karna chahiye.

---

# Part AA — Common Conditional Mistakes

## Mistake 1 — `=` instead of `==`

```cpp
if (x = 5)
```

❌ Assignment.

Correct:

```cpp
if (x == 5)
```

---

## Mistake 2 — Wrong `else if` order

```cpp
if (marks >= 50)
    cout << "Pass";
else if (marks >= 90)
    cout << "A";
```

❌ `90` bhi pehle condition mein capture ho jayega.

Better:

```cpp
if (marks >= 90)
    cout << "A";
else if (marks >= 50)
    cout << "Pass";
```

---

## Mistake 3 — `if`s ko `else if` samajhna

```cpp
if (x > 0)
    cout << "Positive";

if (x < 10)
    cout << "Small";
```

Dono execute ho sakte hain.

---

## Mistake 4 — Braces bhool jana

```cpp
if (x > 0)
    cout << "Positive";
    cout << "Number";
```

Sirf first statement conditional hai.

---

## Mistake 5 — `switch` mein `break` bhool jana

```cpp
case 1:
    cout << "One";

case 2:
    cout << "Two";
```

Potential fall-through.

---

# 🧠 Chapter 4 — Ab tak ka complete map

```text
Conditional Statements
│
├── if
│
├── if-else
│
├── else-if
│
├── nested if
│
├── Boolean conditions
│
├── && / ||
│
├── Multiple independent ifs
│
├── switch
│   ├── case
│   ├── break
│   ├── default
│   └── fall-through
│
├── Validation
│
├── Range conditions
│
└── Common conditional traps
```

Ab **Chapter 4 ka concept portion almost complete** hai. 🔥

# 🔥 Chapter 4 — Final Advanced Portion

Ab hum woh conditional problems karenge jahan sirf syntax nahi, **logic samajhna** important hota hai.

---

## Part AB — Tricky Conditional Problem #1

### Teen numbers mein maximum find karna

Problem:

```text
Teen integers a, b, c diye gaye hain.
Sab se bara number find karo.
```

### Approach

Pehle `a` ko maximum maan lo:

```cpp
int maximum = a;
```

Phir check:

```cpp
if (b > maximum)
    maximum = b;

if (c > maximum)
    maximum = c;
```

### Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int maximum = a;

    if (b > maximum)
        maximum = b;

    if (c > maximum)
        maximum = c;

    cout << maximum;

    return 0;
}
```

### Dry Run

Input:

```text
10 25 18
```

Initially:

```text
maximum = 10
```

Check `b`:

```text
25 > 10 → true
maximum = 25
```

Check `c`:

```text
18 > 25 → false
```

Output:

```text
25
```

### Important concept 🔥

Yahan humne `else if` nahi lagaya.

Kyun?

Because dono comparisons independently important hain.

---

# Part AC — Tricky Problem #2

## Maximum + Minimum

Input:

```text
7 3 10
```

Find:

```text
Maximum = 10
Minimum = 3
```

Ek simple approach:

```cpp
int maximum = a;
int minimum = a;

if (b > maximum)
    maximum = b;

if (c > maximum)
    maximum = c;

if (b < minimum)
    minimum = b;

if (c < minimum)
    minimum = c;
```

Yahan ek important pattern hai:

> **Pehle assumption banao, phir conditions se update karo.**

Ye pattern DSA mein bhi bohat kaam aayega.

---

# Part AD — Tricky Problem #3

## Number positive, negative ya zero — aur saath even/odd

Problem:

```text
Number positive hai?
Negative hai?
Zero hai?

Agar positive/negative hai to even ya odd bhi batao.
```

### Code

```cpp
int n;
cin >> n;

if (n > 0) {
    if (n % 2 == 0)
        cout << "Positive Even";
    else
        cout << "Positive Odd";
}
else if (n < 0) {
    if (n % 2 == 0)
        cout << "Negative Even";
    else
        cout << "Negative Odd";
}
else {
    cout << "Zero";
}
```

### Dry Run

Input:

```text
-7
```

Check:

```text
-7 > 0 → false
```

Then:

```text
-7 < 0 → true
```

Ab nested condition:

```text
-7 % 2 == 0
```

False.

So:

```text
Negative Odd
```

### Is problem ka pattern

Ye basically:

```text
Category
   ↓
Sub-category
```

hai.

Matlab:

```text
Positive
   ├── Even
   └── Odd

Negative
   ├── Even
   └── Odd

Zero
```

---

# Part AE — Tricky Problem #4

## Grade Calculator

Marks:

```text
90-100 → A
80-89  → B
70-79  → C
60-69  → D
Below 60 → F
```

Sab se pehle **validation**:

```cpp
if (marks < 0 || marks > 100)
    cout << "Invalid marks";
```

Phir grading.

```cpp
if (marks < 0 || marks > 100) {
    cout << "Invalid marks";
}
else if (marks >= 90) {
    cout << "A";
}
else if (marks >= 80) {
    cout << "B";
}
else if (marks >= 70) {
    cout << "C";
}
else if (marks >= 60) {
    cout << "D";
}
else {
    cout << "F";
}
```

### Important 🔥

Notice humne ye nahi likha:

```cpp
if (marks >= 90 && marks <= 100)
```

har condition mein.

Humne pehle hi validate kar diya:

```cpp
marks 0-100
```

Phir descending order use kiya:

```text
>=90
>=80
>=70
>=60
else
```

Ye clean aur readable hai.

---

# Part AF — Tricky Problem #5

## Leap Year

Ye interview/PF ka famous conditional problem hai.

Rules:

A year leap year hota hai agar:

```text
year % 400 == 0
```

**OR**

```text
year % 4 == 0 AND year % 100 != 0
```

### Code

```cpp
int year;
cin >> year;

if (year % 400 == 0 ||
    (year % 4 == 0 && year % 100 != 0)) {
    
    cout << "Leap Year";
}
else {
    cout << "Not Leap Year";
}
```

### Dry Run

Suppose:

```text
year = 2024
```

Check:

```text
2024 % 400 == 0 → true
```

Then:

```text
2024 % 4 == 0 → true
2024 % 100 != 0 → true
```

So:

```text
true || (true && true)
```

Result:

```text
true
```

Output:

```text
Leap Year
```

### Tricky case

```text
1900
```

1900 is divisible by 4:

```text
1900 % 4 == 0
```

But divisible by 100 too:

```text
1900 % 100 == 0
```

So:

```text
year % 100 != 0
```

is false.

Therefore:

```text
Not Leap Year
```

---

# Part AG — Output-Based Interview Questions

Ab abhi **code run nahi karna**. Pehle mentally output predict karo.

---

### Q1

```cpp
int x = 10;

if (x > 5)
    cout << "A";
else
    cout << "B";

cout << "C";
```

Output?

Think:

```text
x > 5 → true
```

So:

```text
AC
```

---

### Q2

```cpp
int x = 5;

if (x > 10)
    cout << "A";
else if (x > 3)
    cout << "B";
else
    cout << "C";
```

Check:

```text
5 > 10 → false
5 > 3 → true
```

Output:

```text
B
```

---

### Q3

```cpp
int x = 10;

if (x > 5)
    cout << "A";

if (x > 8)
    cout << "B";
```

Dono independent `if` hain.

Both true.

Output:

```text
AB
```

🔥 Ye `else if` aur separate `if` ka difference hai.

---

# Part AH — Dangling Else Challenge

Ye dekho:

```cpp
int x = 10;

if (x > 5)
    if (x > 8)
        cout << "A";
    else
        cout << "B";
```

`else` kis `if` ke saath attach hoga?

**Nearest unmatched `if`** ke saath.

So:

```cpp
if (x > 8)
```

ke saath.

Since:

```text
10 > 8 → true
```

Output:

```text
A
```

### Golden rule

> `else` hamesha nearest unmatched `if` ke saath attach hota hai.

Lekin isi confusion se bachne ke liye braces use karo:

```cpp
if (x > 5) {
    if (x > 8) {
        cout << "A";
    }
    else {
        cout << "B";
    }
}
```

---

# Part AI — Short-Circuit + Conditions

Ye important hai:

```cpp
int x = 0;

if (x != 0 && 10 / x > 2)
    cout << "Yes";
else
    cout << "No";
```

Pehle:

```cpp
x != 0
```

False hai.

`&&` mein agar pehli condition false ho gayi, C++ second condition check hi nahi karega.

Isliye:

```cpp
10 / x
```

execute nahi hota.

Output:

```text
No
```

### Pattern yaad rakho:

```cpp
safe_check && dangerous_check
```

Pehle safe condition.

---

# Part AJ — Edge Cases

Conditional problems mein sirf normal input nahi dekhna.

### Maximum/minimum

Input:

```text
5 5 5
```

Maximum?

```text
5
```

---

### Grade

Boundary values:

```text
90
80
70
60
59
```

Har boundary test karna important hai.

---

### Leap year

Important tests:

```text
2024
1900
2000
2023
```

Especially:

```text
1900
2000
```

because ye rule ko properly test karte hain.

---

### Positive/negative

Test:

```text
10
-10
0
1
-1
```

`0` ko separately sochna zaroori hai.

---

# 🧠 Chapter 4 ka Master Pattern

Conditional problem dekhte hi ye questions apne dimagh mein chalao:

```text
1. Kitni possible categories hain?
        ↓
2. Kya ranges hain ya exact values?
        ↓
3. Kya validation required hai?
        ↓
4. Kya conditions independent hain?
        ↓
5. Ya sirf ek category select karni hai?
        ↓
6. Kya nested condition chahiye?
        ↓
7. Kya && / || use honge?
        ↓
8. Boundary values kya hain?
        ↓
9. Edge cases kya hain?
```

Aur phir:

```text
Problem
 ↓
Conditions identify
 ↓
Order decide
 ↓
Algorithm
 ↓
Code
 ↓
Dry run
 ↓
Edge cases
```

---

# 🔥 FINAL CHALLENGE — Chapter 4

Ab ye **5 problems** tum khud solve karna. Main abhi solutions nahi de raha 😈

### Q1 — Largest of 3

Teen integers lo aur largest print karo.

Test:

```text
12 7 19
```

Expected:

```text
19
```

---

### Q2 — Number Classification

Ek integer lo aur print karo:

```text
Positive Even
Positive Odd
Negative Even
Negative Odd
Zero
```

---

### Q3 — Grade

Marks `0–100` hain.

```text
90+ → A
80+ → B
70+ → C
60+ → D
<60 → F
```

Invalid marks bhi handle karo.

---

### Q4 — Leap Year

Year input lo aur determine karo:

```text
Leap Year
Not Leap Year
```

---

### Q5 — Triangle Validity 🔥

Three sides:

```text
a, b, c
```

Triangle valid tab hota hai jab:

```text
a + b > c
a + c > b
b + c > a
```

Agar valid hai:

```text
Valid Triangle
```

warna:

```text
Invalid Triangle
```

**Edge cases:** equal sides, zero, negative values, very large values.

---

## 🏁 Chapter 4 Completion Rule

Agar tum in 5 problems ko **algorithm → conditions → code → dry run → edge cases** ke saath solve kar lete ho, to samjho:

> ✅ **Conditional Statements officially DONE.**
