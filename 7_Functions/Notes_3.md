# 🧩 Part 9 — Common Function Mistakes

## 1. `return` type mismatch

Agar function:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

hai to ye `int` return kar raha hai.

Lekin agar:

```cpp
int add(int a, int b)
{
    cout << a + b;
}
```

to problem hai.

Function ka return type:

```cpp
int
```

hai, lekin actual `int` return nahi kiya.

Correct:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

---

# 2. `void` function se value return karna

```cpp
void test()
{
    return 10;   // ❌
}
```

`void` ka matlab:

> Function koi value return nahi karega.

Correct:

```cpp
void test()
{
    cout << "Hello";
    return;
}
```

`return;` allowed hai because koi value nahi bhej rahe.

---

# 3. `return` ke baad code

```cpp
int test()
{
    return 10;

    cout << "Hello"; // ❌ unreachable
}
```

`return` function ko terminate kar deta hai.

So `"Hello"` execute nahi hoga.

---

# 4. Function ko call karna bhool jana

Definition:

```cpp
void hello()
{
    cout << "Hello";
}
```

Sirf definition likhne se output nahi aayega.

Need:

```cpp
hello();
```

Mental model:

```text
Definition → function ko banana
Call       → function ko chalana
```

---

# 5. Wrong number of arguments

Function:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Correct:

```cpp
add(5, 10);
```

Wrong:

```cpp
add(5);        // ❌
add(5, 10, 20); // ❌
```

Unless default parameter available ho.

---

# 6. Wrong argument types

Example:

```cpp
int square(int n)
{
    return n * n;
}
```

Normally:

```cpp
square(5);
```

Expected.

C++ kuch conversions automatically kar sakta hai, but function arguments ke types ko consciously samajhna zaroori hai.

---

# 7. Local variable ko function ke bahar use karna

```cpp
void test()
{
    int x = 10;
}

int main()
{
    cout << x; // ❌
}
```

`x` local hai.

Uska scope sirf `test()` hai.

---

# 8. Pass by value ki wajah se original change na hona

Common mistake:

```cpp id="e2ot7q"
void change(int x)
{
    x = 100;
}

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

Agar original change karna ho:

```cpp
void change(int &x)
{
    x = 100;
}
```

---

# 9. Swap mein reference bhool jana

Wrong:

```cpp id="04xg7k"
void swapNumbers(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
```

Original variables change nahi honge.

Correct:

```cpp id="2x4k8u"
void swapNumbers(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
```

---

# 10. Array function mein size bhoolna

Common pattern:

```cpp
void printArray(int arr[], int size)
```

Call:

```cpp
printArray(arr, 5);
```

Array ke elements process karne ke liye size/length ka knowledge zaroori hai.

---

# 11. Array boundary mistake

Example:

```cpp
void printArray(int arr[], int size)
{
    for(int i = 0; i <= size; i++)
    {
        cout << arr[i];
    }
}
```

❌ Wrong.

Agar size = 5 hai, valid indices:

```text
0 1 2 3 4
```

Correct:

```cpp
for(int i = 0; i < size; i++)
```

Golden rule:

> **Size = number of elements, last index = size - 1**

---

# 12. Recursive function mein base case bhoolna

❌

```cpp
void fun(int n)
{
    cout << n;
    fun(n - 1);
}
```

No stopping condition.

Eventually invalid recursion / stack overflow.

Correct:

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    cout << n;
    fun(n - 1);
}
```

---

# 13. Recursive function mein problem smaller na karna

Ye bhi dangerous:

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    fun(n);
}
```

`n` kabhi change nahi hua.

So:

```text
fun(5)
→ fun(5)
→ fun(5)
→ fun(5)
...
```

Correct recursive progression usually:

```cpp
fun(n - 1);
```

or:

```cpp
fun(index + 1);
```

depending on problem.

---

# 14. Wrong base case

Factorial:

```cpp
int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

Agar accidentally:

```cpp
if(n == 0)
    return 0;
```

kar do:

```text
factorial(5)
= 5 * 4 * 3 * 2 * 1 * 0
= 0
```

So base case sirf recursion rokta nahi — **correct result bhi establish karta hai.**

---

# 🔥 Interview Problem 1 — Even/Odd Function

Problem:

```text
Ek function banao jo check kare ke number even hai ya odd.
```

Best design:

```cpp
bool isEven(int n)
{
    return n % 2 == 0;
}
```

Then:

```cpp
if(isEven(10))
    cout << "Even";
else
    cout << "Odd";
```

Yahan function ka kaam sirf **decision return karna** hai.

---

# 🔥 Interview Problem 2 — Maximum of Two

```cpp
int maximum(int a, int b)
{
    if(a > b)
        return a;

    return b;
}
```

Call:

```cpp
cout << maximum(10, 7);
```

Output:

```text
10
```

Notice function reusable hai:

```cpp
maximum(10, 7)
maximum(50, 80)
maximum(-3, -8)
```

---

# 🔥 Interview Problem 3 — Maximum of Three

```cpp
int maximum(int a, int b, int c)
{
    int maximum = a;

    if(b > maximum)
        maximum = b;

    if(c > maximum)
        maximum = c;

    return maximum;
}
```

Example:

```text
4, 15, 9
```

Dry run:

```text
maximum = 4

15 > 4
maximum = 15

9 > 15? No

answer = 15
```

---

# 🔥 Interview Problem 4 — Count Digits

```cpp
int countDigits(int n)
{
    if(n == 0)
        return 1;

    int count = 0;

    while(n != 0)
    {
        n /= 10;
        count++;
    }

    return count;
}
```

Important edge case:

```text
n = 0
```

Normally loop:

```cpp
while(n != 0)
```

execute nahi karega.

Lekin `0` mein one digit hai.

So:

```cpp
if(n == 0)
    return 1;
```

---

# 🔥 Interview Problem 5 — Prime Function

Tumne pehle bhi isko deeply kiya hai.

```cpp
bool isPrime(int n)
{
    if(n < 2)
        return false;

    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}
```

Yahan multiple function concepts combine hain:

```text
Parameter
   ↓
Return value
   ↓
Loop
   ↓
Condition
   ↓
Early return
   ↓
Edge cases
```

---

# 🧠 Function Design ka Golden Rule

Jab tum function bana rahe ho, pehle ye 4 questions poochho:

### 1. Function ka kaam kya hai?

Example:

```text
check prime
```

### 2. Isko input kya chahiye?

```text
n
```

### 3. Output kya chahiye?

```text
true / false
```

### 4. Return type kya hoga?

```cpp
bool
```

Then:

```cpp
bool isPrime(int n)
```

Function design ho gaya.

---

# 🎯 Practice — Part 9

Ab bhai thoda interview mode. **Code khud likhna.**

### Q1

Function:

```cpp
bool isPositive(int n)
```

banao.

Expected:

```text
10 → true
-5 → false
0 → false
```

---

### Q2

```cpp
int minimum(int a, int b)
```

banao.

---

### Q3 🔥

```cpp
int countEven(int arr[], int size)
```

Array mein kitne even numbers hain, return karo.

Example:

```text
{2, 5, 8, 9, 10}
→ 3
```

---

### Q4 🔥

```cpp
bool isSorted(int arr[], int size)
```

Ascending sorted check karo.

```text
{1, 2, 4, 7} → true
{1, 5, 3, 7} → false
```

---

### Q5 — Recursion

```cpp
int sumN(int n)
```

recursive function banao:

```text
sumN(5) = 15
```

---

### Q6 — Debugging

Is code mein mistakes identify karo:

```cpp
int square(int n)
{
    cout << n * n;
}

int main()
{
    int x = square(5);
    cout << x;
}
```

**Kam az kam 2 issues** identify karo.

---

### Q7 — Design Question 🔥

Agar tumhein function banana ho:

```text
"Array mein target exist karta hai ya nahi?"
```

to batao:

* Function name?
* Parameters?
* Return type?
* `true/false` kab return hoga?

Code abhi optional hai — pehle **function design** socho.

---

# 🏆 Part 10 — Functions Mastery

## 1. Function banane ka complete thought process

Kisi bhi function ko dekh kar immediately code mat likho.

Pehle:

```text
Problem
   ↓
Function ka kaam?
   ↓
Input kya chahiye?
   ↓
Output kya chahiye?
   ↓
Return type?
   ↓
Parameters?
   ↓
Algorithm
   ↓
Code
   ↓
Dry Run
   ↓
Complexity
```

### Example

Problem:

> Array mein maximum element find karo.

### Step 1 — Kaam

```text
maximum find karna
```

### Step 2 — Input

Array + size.

### Step 3 — Output

Ek integer.

### Step 4 — Function design

```cpp
int findMax(int arr[], int size)
```

### Step 5 — Algorithm

```text
maximum = arr[0]

har element check karo
agar current > maximum
    maximum update karo

maximum return karo
```

### Step 6 — Code

```cpp
int findMax(int arr[], int size)
{
    int maximum = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] > maximum)
            maximum = arr[i];
    }

    return maximum;
}
```

---

# 2. Function concepts ka master map 🧠

Ab tak humne ye seekha:

```text
FUNCTIONS
│
├── Basic Function
│   ├── Definition
│   ├── Declaration
│   └── Call
│
├── Parameters / Arguments
│
├── Return
│   ├── int
│   ├── double
│   ├── bool
│   └── void
│
├── Pass by Value
│
├── Pass by Reference
│
├── Scope
│   ├── Local
│   ├── Global
│   └── Block
│
├── Default Arguments
│
├── Function Overloading
│
├── Arrays + Functions
│
├── Strings + Functions
│
└── Recursion
```

Ye basically tumhara **Functions toolbox** hai.

---

# 3. `void` vs `return` — final clarity

Ye distinction bohot important hai.

### `void`

Function ka kaam perform karo:

```cpp
void printSquare(int n)
{
    cout << n * n;
}
```

Call:

```cpp
printSquare(5);
```

---

### `return`

Function result calculate karke caller ko do:

```cpp
int square(int n)
{
    return n * n;
}
```

Call:

```cpp
int result = square(5);
```

Mental model:

```text
void
→ "Kaam karo"

return value
→ "Kaam karo aur result mujhe wapas do"
```

---

# 4. Pass by Value vs Reference — final mental model

### Value

```cpp
void change(int x)
{
    x = 100;
}
```

```text
a = 10
 ↓
copy
 ↓
x = 10
 ↓
x = 100

original a = 10
```

### Reference

```cpp
void change(int &x)
{
    x = 100;
}
```

```text
a = 10
 ↓
x ─────→ a
 ↓
x = 100

a = 100
```

---

# 5. Function + Array

Ye DSA ke liye **bohot important** hai.

```cpp
int sumArray(int arr[], int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}
```

Call:

```cpp
int arr[] = {2, 4, 6, 8};

cout << sumArray(arr, 4);
```

Output:

```text
20
```

Complexity:

```text
Time  = O(n)
Space = O(1)
```

---

# 6. Function + String

Example:

```cpp
int countVowels(string s)
{
    int count = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]=='a' || s[i]=='e' || 
           s[i]=='i' || s[i]=='o' || 
           s[i]=='u')
        {
            count++;
        }
    }

    return count;
}
```

Again:

```text
Input
 ↓
Process
 ↓
Result
 ↓
return
```

---

# 7. Function + Recursion

Example:

```cpp
int sumN(int n)
{
    if(n == 0)
        return 0;

    return n + sumN(n - 1);
}
```

Dry run:

```text
sumN(4)
= 4 + sumN(3)
= 4 + 3 + sumN(2)
= 4 + 3 + 2 + sumN(1)
= 4 + 3 + 2 + 1 + sumN(0)
= 10
```

Complexity:

```text
Time  = O(n)
Space = O(n)
```

Space `O(n)` because call stack mein `n` calls accumulate hoti hain.

---

# 8. Overloading — final reminder

Same name, different parameter list:

```cpp
int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}
```

C++ arguments dekh kar appropriate function choose karta hai.

Important:

```cpp
int test(int x)
```

aur

```cpp
double test(int x)
```

❌ sirf return type ki wajah se overload nahi ho sakte.

---

# 9. Default Arguments

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
5 + 10
```

while:

```cpp
add(5, 20);
```

means:

```text
5 + 20
```

---

# 🔥 FINAL CHALLENGE

Ab bhai **actual test mode**.

Main solutions nahi de raha. Tum khud solve karo.

## Q1 — Basic

```cpp
int cube(int n)
```

Function banao jo number ka cube return kare.

Example:

```text
cube(3) → 27
```

---

## Q2 — Reference 🔥

Function:

```cpp
void swapNumbers(int &a, int &b)
```

banao.

Example:

```text
a = 10
b = 20

after swap:

a = 20
b = 10
```

---

## Q3 — Array

```cpp
int findMax(int arr[], int size)
```

Array ka maximum return karo.

Test:

```text
{4, 15, 2, 9, 7}
```

Expected:

```text
15
```

---

## Q4 — Array + Boolean

```cpp
bool isSorted(int arr[], int size)
```

Ascending order check karo.

```text
{1,2,3,4,5} → true
{1,3,2,4,5} → false
```

**Hint:** adjacent elements compare karna.

---

## Q5 — String 🔥

```cpp
int countVowels(string s)
```

String mein vowels count karo.

Example:

```text
"hello"
→ 2
```

---

## Q6 — String + Two Pointers

```cpp
bool isPalindrome(string s)
```

Palindrome check karo.

Examples:

```text
"madam" → true
"hello" → false
```

---

## Q7 — Recursion

```cpp
int factorial(int n)
```

recursive factorial.

```text
factorial(5) → 120
```

Aur iska:

```text
Time Complexity = ?
Space Complexity = ?
```

bhi batao.

---

# 🔥 Q8 — Mixed Problem

Function:

```cpp
int countEven(int arr[], int size)
```

Array mein even numbers count karo.

Example:

```text
{2, 5, 8, 11, 14}
```

Answer:

```text
3
```

Complexity bhi batao.

---

# 🧠 Q9 — Debug This

Is function mein problem kya hai?

```cpp
int maximum(int arr[], int size)
{
    int max = 0;

    for(int i = 0; i <= size; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}
```

**Kam az kam 2 mistakes** find karo.

Aur explain karo ke negative array ke case mein kya problem hogi.

---

# 💀 Q10 — Interview-Level Design

Problem:

> Ek function banao jo check kare ke given number prime hai ya nahi.

Tum sirf code nahi likhoge.

Pehle ye 5 cheezen do:

```text
1. Function name:
2. Parameter:
3. Return type:
4. Algorithm:
5. Time Complexity:
```

Phir code.

---

# 🏁 Chapter 7 Final Boss

Last problem thori interesting hai:

```cpp
int secondLargest(int arr[], int size)
```

Array ka **second largest distinct element** return karo.

Example:

```text
{10, 5, 8, 10, 3}
```

Answer:

```text
8
```

### Important edge cases:

```text
{5}
{5,5}
{10,10,8}
{-5,-2,-10}
```

Yahan tumhein decide karna hoga ke **second largest distinct element exist karta bhi hai ya nahi**.

Is problem ko brute-force sorting se bhi solve kiya ja sakta hai, lekin abhi tumhara target hai **function + array + logical thinking**.

---

## 🎯 Chapter 7 ka final takeaway

Agar tum function ko dekh kar ye identify kar sakte ho:

```text
Input?
   ↓
Parameters?
   ↓
Value ya Reference?
   ↓
Processing?
   ↓
Return ya void?
   ↓
Edge cases?
   ↓
Complexity?
```

to tum sirf **functions ki syntax** nahi jaante — tum function ko **problem-solving tool** ke taur par use karna seekh rahe ho.

**Chapter 7 — Functions: DONE after this challenge.** 🏆