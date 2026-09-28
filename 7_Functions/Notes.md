## Chapter 7 roadmap

Hum roughly ye cover karenge:

1. Function kya hota hai?
2. Function ki need — code duplication
3. Declaration / Prototype
4. Definition
5. Function Call
6. Parameters & Arguments
7. `void` functions
8. Return values
9. `return` ka actual flow
10. Pass by Value
11. Pass by Reference
12. Scope — local/global
13. Default Arguments
14. Function Overloading
15. Arrays with Functions
16. Strings with Functions
17. Functions + Recursion
18. Common mistakes
19. Interview-style problems
20. Final Functions Challenge

Aaj **foundation** se start karte hain.

---

# Part 1 — Function kya hota hai?

Simple words mein:

> **Function code ka ek reusable block hota hai jo ek specific kaam karta hai.**

Example:

```cpp
void sayHello()
{
    cout << "Hello";
}
```

Ye function `sayHello()` ka kaam hai:

> `"Hello"` print karna.

Lekin sirf function banane se ye automatically execute nahi hota.

Humein usko **call** karna hota hai:

```cpp
sayHello();
```

---

# 🧠 Function ke 3 basic parts

Ye example dekho:

```cpp
void sayHello()
{
    cout << "Hello";
}

int main()
{
    sayHello();

    return 0;
}
```

Ismein:

### 1. Function Definition

```cpp
void sayHello()
{
    cout << "Hello";
}
```

Hum bata rahe hain:

> Function kya karega?

### 2. Function Call

```cpp
sayHello();
```

Hum keh rahe hain:

> "Bhai, ab ye function execute karo."

### 3. Function ka kaam

```cpp
cout << "Hello";
```

---

# 🔥 Function ko real-life example se samjho

Socho tumhare paas ek machine hai:

```text
        ┌─────────────┐
Input → │   FUNCTION  │ → Output
        └─────────────┘
```

Example:

```text
2, 3 → [add function] → 5
```

Function:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Call:

```cpp
int result = add(2, 3);
```

Output/value:

```text
5
```

---

# 🧩 Function kyun use karte hain?

Suppose tumhein 3 jagah sum calculate karna hai.

Without function:

```cpp
int a = 5, b = 10;
cout << a + b;

int x = 20, y = 30;
cout << x + y;

int p = 50, q = 60;
cout << p + q;
```

Same logic baar baar likh rahe ho.

Function:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Ab:

```cpp
cout << add(5, 10);
cout << add(20, 30);
cout << add(50, 60);
```

🔥 **Ek logic define karo, multiple times reuse karo.**

---

# ⭐ Function ka basic structure

General form:

```cpp
returnType functionName(parameters)
{
    // function body
}
```

Example:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Isko pieces mein dekho:

```text
int
↓
return type

add
↓
function name

(a, b)
↓
parameters

return a + b;
↓
function body / result
```

---

# 🧠 Return Type kya hota hai?

Return type batata hai:

> Function **kya value wapas dega?**

Examples:

```cpp
int
```

means integer return karega.

```cpp
double
```

means decimal value return karega.

```cpp
char
```

means character return karega.

```cpp
bool
```

means true/false return karega.

Aur:

```cpp
void
```

means:

> Function koi value return nahi karega.

---

# ⭐ Example — `int` function

```cpp
int square(int n)
{
    return n * n;
}
```

Call:

```cpp
int result = square(5);
cout << result;
```

Output:

```text
25
```

Flow:

```text
square(5)
   ↓
n = 5
   ↓
5 * 5
   ↓
25
   ↓
return 25
```

---

# 🔥 `return` ko properly samjho

Ye line:

```cpp
return n * n;
```

sirf value calculate nahi kar rahi.

Ye **function ko terminate bhi karti hai** aur value caller ko wapas bhejti hai.

Example:

```cpp
int test()
{
    cout << "A";

    return 10;

    cout << "B";
}
```

`"B"` print nahi hoga.

Because:

```cpp
return 10;
```

ke baad function khatam.

Output:

```text
A
```

Aur function ki returned value:

```text
10
```

---

# ⭐ `void` Function

Agar function ko koi value return nahi karni:

```cpp
void greet()
{
    cout << "Hello";
}
```

Call:

```cpp
greet();
```

Output:

```text
Hello
```

Yahan:

```cpp
void
```

ka matlab hai:

> **No return value.**

---

# ⚠️ Important Difference

Ye:

```cpp
void greet()
{
    cout << "Hello";
}
```

aur ye:

```cpp
int getNumber()
{
    return 10;
}
```

different hain.

### `void`

```text
Function → kaam karta hai
          ↓
       no value back
```

### `int`

```text
Function → kaam karta hai
          ↓
       int value back
```

---

# ⭐ Parameters vs Arguments

Ye terminology bohat important hai.

Function definition:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Yahan:

```cpp
a
b
```

**parameters** hain.

Jab call karte hain:

```cpp
add(5, 10);
```

Yahan:

```cpp
5
10
```

**arguments** hain.

Simple rule:

> **Definition mein → parameters**
>
> **Call mein → arguments**

---

# 🧠 Dry Run

Code:

```cpp
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int result = add(7, 3);

    cout << result;

    return 0;
}
```

Execution:

### Step 1

Program `main()` mein:

```cpp
int result = add(7, 3);
```

### Step 2

Function call:

```text
add(7,3)
```

Values transfer:

```text
a = 7
b = 3
```

### Step 3

Function:

```cpp
return a + b;
```

becomes:

```cpp
return 7 + 3;
```

### Step 4

Returns:

```text
10
```

### Step 5

Now:

```cpp
int result = 10;
```

### Step 6

```cpp
cout << result;
```

Output:

```text
10
```

---

# 🔥 Function Call ko ek jump samjho

Agar:

```cpp
int main()
{
    cout << "A";

    add(5, 3);

    cout << "B";
}
```

Execution:

```text
main
 ↓
print A
 ↓
call add()
 ↓
function executes
 ↓
function ends
 ↓
back to main
 ↓
print B
```

Output depends on function body.

Ye concept tum **recursion ke call stack** mein already dekh chuke ho.

Functions ka normal call bhi isi basic mechanism par based hai.

---

# ⭐ Function Declaration / Prototype

Ek aur important concept.

Suppose function `main()` ke baad define kiya:

```cpp
int main()
{
    cout << add(5, 3);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}
```

Problem: compiler ne `main()` par `add` ko abhi dekha hi nahi.

Isliye pehle declaration de sakte hain:

```cpp
int add(int a, int b);
```

Complete:

```cpp
#include <iostream>
using namespace std;

int add(int a, int b);

int main()
{
    cout << add(5, 3);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}
```

---

# 🧠 Declaration vs Definition

### Declaration

```cpp
int add(int a, int b);
```

Compiler ko bata raha hai:

> "Aisa function exist karta hai."

### Definition

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Bata raha hai:

> "Aur ye function actually karta kya hai."

---

# 🎯 Ek complete mental model

Function ko abhi is form mein dekho:

```text
                FUNCTION
                    │
        ┌───────────┴───────────┐
        ↓                       ↓
      Input                   Output
   parameters               return value
        │                       │
        └────── FUNCTION ───────┘
                   │
                Task/Logic
```

Example:

```cpp
int multiply(int x, int y)
{
    return x * y;
}
```

```text
x,y
 ↓
multiply
 ↓
x*y
 ↓
result
```

---

# 🧪 Ab tumhara first Functions test

**Solutions abhi mat dekho/search karo — khud attempt karna.**

### Q1

Ek function banao:

```text
Name: printHello
Return type: void
Parameters: none
Task: "Hello" print kare
```

---

### Q2

Function banao:

```text
Name: square
Return type: int
Parameter: int n
Task: n ka square return kare
```

Call:

```cpp
square(6)
```

ka result kya hoga?

---

### Q3

Is code ka output:

```cpp
void test()
{
    cout << "A";
    cout << "B";
}

int main()
{
    test();
    cout << "C";

    return 0;
}
```

---

### Q4

Ismein **parameters** aur **arguments** identify karo:

```cpp
int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    cout << multiply(4, 7);
}
```

---

### Q5 🔥

Dry run:

```cpp
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x = 5;
    int y = 8;

    int result = add(x, y);

    cout << result;

    return 0;
}
```

Step-by-step batao:

```text
x = ?
y = ?
a = ?
b = ?
return = ?
result = ?
output = ?
```
---

# 🔥 Part 2 — Parameters, Arguments & Return Values

Part 1 mein humne basic function dekha tha. Ab functions ko properly **input dena aur output lena** samjhenge.

---

## 1. Function ko input kaise dete hain?

Example:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Yahan:

```cpp
int a, int b
```

ye **parameters** hain.

Jab function call karte hain:

```cpp
int result = add(5, 10);
```

to:

```text
5  → a
10 → b
```

Aur `5 + 10 = 15` return hoga.

---

# 2. Parameter vs Argument

Ye distinction interview mein bhi pooch sakte hain.

### Function definition:

```cpp
int multiply(int x, int y)
{
    return x * y;
}
```

`x` aur `y` = **parameters**

### Function call:

```cpp
multiply(4, 6);
```

`4` aur `6` = **arguments**

Simple rule:

> **Definition mein → Parameters**
> **Call mein → Arguments**

---

# 3. Parameters variables ki tarah behave karte hain

Dekho:

```cpp
int add(int a, int b)
{
    int sum = a + b;
    return sum;
}
```

Jab:

```cpp
add(7, 3);
```

call hoga, function ke andar temporary situation kuch aisi hogi:

```text
a = 7
b = 3
sum = 10
```

Phir:

```cpp
return sum;
```

means:

```text
10 → wapas caller ko
```

---

# 4. Return Value ka actual flow

Ye bohat important hai.

```cpp
int square(int n)
{
    return n * n;
}

int main()
{
    int result = square(5);
    cout << result;
}
```

Dry run:

### Step 1

```cpp
square(5)
```

Function call.

### Step 2

```text
n = 5
```

### Step 3

Function execute:

```cpp
return 5 * 5;
```

### Step 4

Function `25` return karta hai.

So:

```cpp
int result = 25;
```

### Step 5

```cpp
cout << result;
```

Output:

```text
25
```

Mental model:

```text
main
 ↓
square(5)
 ↓
n = 5
 ↓
5 × 5
 ↓
return 25
 ↓
main
 ↓
result = 25
```

---

# 5. `return` sirf value nahi deta — function bhi terminate karta hai

Ye bohat important point hai.

```cpp
int test()
{
    cout << "A";

    return 10;

    cout << "B";
}
```

Output:

```text
A
```

`B` kabhi execute nahi hoga.

Kyun?

Because:

```cpp
return 10;
```

function ko **immediately terminate** kar deta hai.

So:

```text
return = value wapas bhejo + function khatam
```

---

# 6. `void` vs non-void

### `void`

```cpp
void hello()
{
    cout << "Hello";
}
```

Ye koi value return nahi karta.

Call:

```cpp
hello();
```

---

### `int`

```cpp
int square(int n)
{
    return n * n;
}
```

Ye `int` value return karega.

Call:

```cpp
int x = square(4);
```

---

### `double`

```cpp
double half(double n)
{
    return n / 2;
}
```

---

### `bool`

```cpp
bool isEven(int n)
{
    return n % 2 == 0;
}
```

Yahan function:

```text
true
```

ya

```text
false
```

return karega.

---

# 7. Function ke andar `return` aur `cout` same cheez nahi hain

Ye confusion nahi honi chahiye.

### `cout`

```cpp
void square(int n)
{
    cout << n * n;
}
```

Ye **screen par print** karta hai.

### `return`

```cpp
int square(int n)
{
    return n * n;
}
```

Ye **value caller ko deta hai**.

For example:

```cpp
int x = square(5);
```

Return ki wajah se:

```text
x = 25
```

---

# 8. Multiple function calls

Ab thoda interesting:

```cpp
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x = add(2, 3);
    int y = add(10, 5);

    cout << x << endl;
    cout << y;
}
```

Dry run:

```text
add(2,3)
→ 5
→ x = 5

add(10,5)
→ 15
→ y = 15
```

Output:

```text
5
15
```

Har function call ka apna execution hota hai.

---

# 🧠 Ek important concept: arguments variables bhi ho sakte hain

Sirf direct numbers zaroori nahi:

```cpp
int add(int a, int b)
{
    return a + b;
}

int x = 10;
int y = 20;

int result = add(x, y);
```

Call ke waqt:

```text
x → 10 → a
y → 20 → b
```

Result:

```text
30
```

---

# 🎯 Ab tumhari practice

Is baar main solutions nahi de raha. Pehle tum khud attempt karo.

### Q1 — Output

```cpp
void test()
{
    cout << "A";
    cout << "B";
}

int main()
{
    test();
    cout << "C";
}
```

Output kya hoga?

---

### Q2 — Return

```cpp
int square(int n)
{
    return n * n;
}

int main()
{
    int x = square(6);
    cout << x;
}
```

Output?

---

### Q3 — Parameters/Arguments

```cpp
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x = 7;
    int y = 4;

    int result = add(x, y);
}
```

Batao:

* Parameters kaun hain?
* Arguments kaun hain?
* `a` ki value kya hogi?
* `b` ki value kya hogi?
* `result` ki value kya hogi?

---

### Q4 — Thoda tricky

```cpp
int test(int x)
{
    cout << x;
    return x + 5;
}

int main()
{
    int a = test(10);
    cout << a;
}
```

Output kya hoga?

Aur **exact flow** bhi batao.

---

### Q5 — Important

```cpp
int fun(int x)
{
    cout << "A";
    return x * 2;
    cout << "B";
}

int main()
{
    int result = fun(5);
    cout << result;
}
```

Output kya hoga aur `"B"` kyun nahi print hoga?

# Part 3 — Pass by Value vs Pass by Reference

Ye topic **bohat important** hai, kyun ke yahin se samajh aata hai ke function ke andar variable change karne se `main()` wala original variable change hota hai ya nahi.

---

## 1. Pass by Value — copy jaati hai

Sabse pehle:

```cpp
void change(int x)
{
    x = 100;
}
```

Aur:

```cpp
int main()
{
    int a = 10;

    change(a);

    cout << a;
}
```

Output:

```text
10
```

### Why?

Jab:

```cpp
change(a);
```

call hua:

```text
a = 10
 ↓
copy
 ↓
x = 10
```

Ab function ke andar:

```cpp
x = 100;
```

sirf **x** change hua.

```text
main:
a = 10

function:
x = 100
```

Dono alag variables hain.

Isliye function ke baad:

```text
a = 10
```

---

# 2. Pass by Value ka mental model

```cpp
void change(int x)
{
    x = 50;
}
```

Call:

```cpp
int a = 10;
change(a);
```

Imagine:

```text
a
┌──────┐
│  10  │
└──────┘
   │
   │ copy
   ↓
x
┌──────┐
│  10  │
└──────┘
```

Function:

```cpp
x = 50;
```

Ab:

```text
a = 10
x = 50
```

Function finish → `x` khatam.

`a` unchanged.

---

# 3. Pass by Reference — original variable access hota hai

Ab ye dekho:

```cpp
void change(int &x)
{
    x = 100;
}
```

Notice:

```cpp
int &x
```

Yahan `&` ka matlab hai ke `x` **reference** hai.

Call:

```cpp
int main()
{
    int a = 10;

    change(a);

    cout << a;
}
```

Output:

```text
100
```

### Why?

Ab copy nahi bani.

```text
a
┌──────┐
│  10  │
└──────┘
   ↑
   │
   x
```

`x` basically `a` ko refer kar raha hai.

So:

```cpp
x = 100;
```

means original `a` ko change karna.

---

# 4. Sabse important comparison

### Pass by Value

```cpp
void change(int x)
{
    x = 100;
}
```

```text
original → copy
```

Original change nahi hota.

---

### Pass by Reference

```cpp
void change(int &x)
{
    x = 100;
}
```

```text
original → reference
```

Original change hota hai.

---

# 5. Dry Run — dono ko compare karo

```cpp
void value(int x)
{
    x = 20;
}

void reference(int &x)
{
    x = 30;
}

int main()
{
    int a = 10;

    value(a);
    cout << a << endl;

    reference(a);
    cout << a;
}
```

### Step 1

Initially:

```text
a = 10
```

### Step 2

```cpp
value(a);
```

Copy:

```text
a = 10
x = 10
```

Function:

```cpp
x = 20;
```

Ab:

```text
a = 10
x = 20
```

Function ends.

So:

```text
a = 10
```

Print:

```text
10
```

---

### Step 3

```cpp
reference(a);
```

Ab `x` reference hai.

```text
x → a
```

Function:

```cpp
x = 30;
```

Therefore:

```text
a = 30
```

Final output:

```text
10
30
```

---

# 6. Ye swap mein bohat important hai

Tumne pehle bhi swap ka concept dekha hai. Ab usko functions ke saath connect karo.

### ❌ Pass by value se swap

```cpp
void swapNumbers(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
```

Call:

```cpp
int x = 10;
int y = 20;

swapNumbers(x, y);

cout << x << " " << y;
```

Output:

```text
10 20
```

Kyun?

Function ko copies mili:

```text
x = 10 → a = 10
y = 20 → b = 20
```

Function ke andar swap hua:

```text
a = 20
b = 10
```

Lekin original:

```text
x = 10
y = 20
```

same rahe.

---

# 7. Reference ke saath actual swap

```cpp
void swapNumbers(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
```

Call:

```cpp
int x = 10;
int y = 20;

swapNumbers(x, y);

cout << x << " " << y;
```

Ab:

```text
a → x
b → y
```

Function:

```text
temp = 10
a = 20
b = 10
```

Since `a` and `b` original variables ko refer kar rahe hain:

```text
x = 20
y = 10
```

Output:

```text
20 10
```

🔥 **Isi wajah se swap function mein references commonly use hote hain.**

---

# 8. Ek aur important use: multiple values change karna

Normally ek function ek value return kar sakta hai:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Lekin references ki help se function multiple variables modify kar sakta hai.

Example:

```cpp
void calculate(int a, int b, int &sum, int &product)
{
    sum = a + b;
    product = a * b;
}
```

Call:

```cpp
int sum;
int product;

calculate(5, 4, sum, product);
```

Ab:

```text
sum = 9
product = 20
```

Yahan:

```text
sum
product
```

original variables hain jo function ke andar modify hue.

---

# 9. `&` ka ek important confusion

C++ mein `&` different contexts mein different meanings de sakta hai.

Yahan:

```cpp
int &x
```

**reference** hai.

Lekin:

```cpp
a & b
```

bitwise AND hai.

Aur:

```cpp
&x
```

address-of operator bhi ho sakta hai.

Abhi functions ke context mein bas:

```cpp
int &x
```

ko **reference parameter** samjho.

Pointers wale chapter mein `&` ka address wala concept properly connect karenge.

---

# 🧠 Golden Rule

Yaad rakho:

```text
Pass by Value
     ↓
COPY
     ↓
Original safe/unchanged
```

```text
Pass by Reference
     ↓
REFERENCE TO ORIGINAL
     ↓
Original can be changed
```

---

# 🎯 Ab tumhari practice

Pehle khud dry run karna.

### Q1

```cpp
void change(int x)
{
    x = 50;
}

int main()
{
    int a = 10;
    change(a);
    cout << a;
}
```

Output?

---

### Q2

```cpp
void change(int &x)
{
    x = 50;
}

int main()
{
    int a = 10;
    change(a);
    cout << a;
}
```

Output?

---

### Q3 — Important

```cpp
void test(int x, int &y)
{
    x = 100;
    y = 200;
}

int main()
{
    int a = 10;
    int b = 20;

    test(a, b);

    cout << a << " " << b;
}
```

Output?

Aur explain karo:

* `x` kis ka copy hai?
* `y` kis ko refer kar raha hai?
* `a` change hoga?
* `b` change hoga?

---

### Q4 — Swap

Is function ko **properly kaam karne wala swap** banao:

```cpp
void swapNumbers(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
```

Sirf function ko modify karo.

---

### Q5 — Thoda interview-style

```cpp
void fun(int &a, int b)
{
    a = a + 10;
    b = b + 20;
}

int main()
{
    int x = 5;
    int y = 7;

    fun(x, y);

    cout << x << " " << y;
}
```

Output kya hoga?

**Is Q5 ko proper dry run ke saath solve karna** — yahan value + reference dono ek saath test ho rahe hain.
---

Aaj ke 2 important topics:

1. **Scope — Local vs Global Variables**
2. **Default Arguments**

---

# 🧩 Part 4 — Scope + Default Arguments

## 1. Scope kya hota hai?

**Scope** ka simple matlab:

> Koi variable/program element **kahan tak accessible hai?**

Example:

```cpp
void test()
{
    int x = 10;

    cout << x;
}
```

`x` ko hum function ke andar use kar sakte hain.

Lekin:

```cpp
int main()
{
    cout << x;   // ❌
}
```

nahi kar sakte.

Kyun?

Because `x` ka scope `test()` ke andar hai.

---

# 2. Local Variable

Jo variable kisi function/block ke andar declare ho:

```cpp
void test()
{
    int x = 10;
}
```

`x` = **local variable**

Iska scope:

```text
test() ke andar
```

Bahar:

```cpp
cout << x; // ❌
```

---

## Example

```cpp
void test()
{
    int x = 50;

    cout << x;
}

int main()
{
    test();

    // cout << x;   // ❌
}
```

Dry run:

```text
main()
  ↓
test()
  ↓
x = 50
  ↓
print x
  ↓
test ends
  ↓
x ka scope ends
```

---

# 3. Different functions ke local variables independent hote hain

Ye bohat important hai:

```cpp
void fun1()
{
    int x = 10;
}

void fun2()
{
    int x = 50;
}
```

Dono ka naam same hai:

```text
x
```

Lekin ye **same variable nahi hain**.

```text
fun1:
x = 10

fun2:
x = 50
```

Completely separate.

---

# 4. Global Variable

Agar variable functions ke bahar declare karo:

```cpp
int x = 100;

void test()
{
    cout << x;
}

int main()
{
    cout << x;
}
```

Yahan `x` **global variable** hai.

Ye multiple functions se accessible ho sakta hai.

```text
Global:
x = 100
 ↓
 ├── test()
 └── main()
```

---

# 5. Global variable ko function modify bhi kar sakta hai

```cpp
int x = 10;

void change()
{
    x = 50;
}

int main()
{
    change();

    cout << x;
}
```

Output:

```text
50
```

Kyun?

`change()` ne global `x` ko directly modify kiya.

---

# 6. Local vs Global — direct comparison

### Local

```cpp
void test()
{
    int x = 10;
}
```

```text
sirf test() ke scope mein
```

### Global

```cpp
int x = 10;

void test()
{
    cout << x;
}
```

```text
multiple functions access kar sakte hain
```

---

# ⚠️ 7. Same naam ka Local + Global

Ab asli interesting case:

```cpp
int x = 100;

void test()
{
    int x = 50;

    cout << x;
}

int main()
{
    test();
    cout << x;
}
```

Output:

```text
50
100
```

### Why?

Function ke andar:

```cpp
int x = 50;
```

local `x` ne global `x` ko **shadow** kar diya.

So:

```text
test():
x → 50

main():
x → 100
```

---

# 🧠 Golden Rule

Agar local aur global variable ka naam same ho:

> **Nearest scope wala variable use hota hai.**

Example:

```text
Global x = 100

function ke andar:
Local x = 50

function mein x → 50
function ke bahar x → 100
```

---

# 8. Block Scope

Scope sirf functions tak limited nahi hota.

Example:

```cpp
int main()
{
    int a = 10;

    if (a > 5)
    {
        int b = 20;
        cout << b;
    }

    // cout << b;  // ❌
}
```

`b` sirf `if` block ke andar accessible hai.

```text
main scope
│
├── a
│
└── if scope
    └── b
```

`if` khatam → `b` ka scope khatam.

---

# 9. Nested scope

```cpp
int main()
{
    int x = 10;

    {
        int y = 20;

        cout << x;
        cout << y;
    }

    cout << x;
}
```

Inner block outer variable ko access kar sakta hai:

```text
outer x
  ↓
inner block → x accessible
```

Lekin outer block inner ka `y` access nahi kar sakta.

---

# 🟢 Part 2 — Default Arguments

Ab functions ka ek aur useful feature.

Suppose:

```cpp
void greet(string name)
{
    cout << "Hello " << name;
}
```

Call:

```cpp
greet("Hassan");
```

Har call mein argument dena padega.

Lekin hum **default value** de sakte hain:

```cpp
void greet(string name = "User")
{
    cout << "Hello " << name;
}
```

Ab:

```cpp
greet();
```

Output:

```text
Hello User
```

Aur:

```cpp
greet("Ali");
```

Output:

```text
Hello Ali
```

---

# 10. Default argument ka concept

```cpp
void greet(string name = "User")
```

Means:

> Agar caller argument nahi dega, `"User"` use kar lena.

So:

```cpp
greet();
```

becomes effectively:

```text
name = "User"
```

But:

```cpp
greet("Hassan");
```

means:

```text
name = "Hassan"
```

Default value replace ho jaati hai.

---

# 11. Multiple parameters with default values

```cpp
int add(int a, int b = 10)
{
    return a + b;
}
```

Now:

```cpp
add(5);
```

means:

```text
a = 5
b = 10
```

Result:

```text
15
```

But:

```cpp
add(5, 20);
```

means:

```text
a = 5
b = 20
```

Result:

```text
25
```

---

# ⚠️ 12. Important rule: Default arguments right side se

Ye valid hai:

```cpp
void fun(int a, int b = 10, int c = 20)
{
}
```

Lekin generally ye invalid hai:

```cpp
void fun(int a = 10, int b)
{
}
```

Kyun?

Agar call:

```cpp
fun(5);
```

to confusion hoga:

```text
5 kis ko milega?
a ko?
b ko?
```

Isliye rule:

> **Default parameters ke baad wale parameters bhi default hone chahiye.**

Valid:

```cpp
void fun(int a, int b = 10, int c = 20);
```

Invalid:

```cpp
void fun(int a = 10, int b, int c = 20);
```

---

# 13. Real example

```cpp
int power(int base, int exponent = 2)
{
    int result = 1;

    for(int i = 1; i <= exponent; i++)
    {
        result *= base;
    }

    return result;
}
```

Now:

```cpp
power(5);
```

means:

```text
5² = 25
```

And:

```cpp
power(5, 3);
```

means:

```text
5³ = 125
```

Same function, different usage.

---

# 🧠 Ab tak Functions ka mental map

```text
FUNCTIONS
│
├── Function definition
├── Function call
├── Parameters
├── Arguments
├── Return value
├── void
│
├── Pass by Value
├── Pass by Reference
│
├── Scope
│   ├── Local
│   ├── Global
│   └── Block
│
└── Default Arguments
```

Aur next important topics:

```text
Function Overloading
Arrays + Functions
Strings + Functions
Functions + Recursion
```

---

# 🎯 Part 4 Practice

Ab bhai **khud dry run** karo.

### Q1 — Local scope

```cpp
void test()
{
    int x = 20;
    cout << x;
}

int main()
{
    int x = 10;

    test();

    cout << x;
}
```

Exact output?

---

### Q2 — Shadowing

```cpp
int x = 100;

void test()
{
    int x = 50;

    cout << x;
}

int main()
{
    test();
    cout << x;
}
```

Output aur explain karo ke dono `x` different kyun hain.

---

### Q3 — Block scope

```cpp
int main()
{
    int a = 10;

    if(a > 5)
    {
        int b = 20;
        cout << b;
    }

    // cout << b;
}
```

Comment hata dein to kya hoga?

---

### Q4 — Default argument

```cpp
int add(int a, int b = 5)
{
    return a + b;
}

int main()
{
    cout << add(10) << endl;
    cout << add(10, 20);
}
```

Output?

---

### Q5 — Thoda tricky 🔥

```cpp
int x = 10;

void test(int x = 50)
{
    cout << x;
}

int main()
{
    test();
    test(100);
    cout << x;
}
```

Output kya hoga?

Yahan **global variable + parameter + default argument** teenon ko ek saath track karna hai.