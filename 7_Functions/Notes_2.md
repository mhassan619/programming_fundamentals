# 🧩 Chapter 7 — Part 5: Function Overloading

## 1. Function Overloading kya hoti hai?

Simple definition:

> **Same function name, lekin different parameters.**

Example:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Ab hum same naam ka doosra function bana sakte hain:

```cpp
double add(double a, double b)
{
    return a + b;
}
```

Dono ka naam:

```text
add
```

hai.

Lekin parameters different hain:

```text
add(int, int)
add(double, double)
```

C++ arguments dekh kar decide karta hai ke kaunsa function call karna hai.

---

# 2. Example

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

Ab:

```cpp
cout << add(5, 10);
```

Yahan integers hain:

```text
add(int, int)
```

call hoga.

Result:

```text
15
```

Aur:

```cpp
cout << add(2.5, 3.5);
```

Yahan doubles hain:

```text
add(double, double)
```

call hoga.

Result:

```text
6
```

---

# 3. C++ kaise decide karta hai?

Function call:

```cpp
add(5, 10);
```

C++ dekhta hai:

```text
Arguments:
int, int
```

Available functions:

```text
add(int, int)       ← match
add(double, double) ← conversion required
```

So first wala select hota hai.

---

# 4. Sirf return type change karke overloading nahi hoti ❌

Ye **invalid** hai:

```cpp
int add(int a, int b)
{
    return a + b;
}

double add(int a, int b)
{
    return a + b;
}
```

Kyun?

Dono ka parameter list exactly same hai:

```text
(int, int)
```

C++ function choose karte waqt **return type ko basis nahi banata**.

So:

```text
❌ Different return type only
```

enough nahi hai.

---

# 5. Parameter count different ho sakta hai

Valid:

```cpp
int sum(int a, int b)
{
    return a + b;
}

int sum(int a, int b, int c)
{
    return a + b + c;
}
```

Ab:

```cpp
sum(2, 3);
```

calls:

```text
sum(int, int)
```

Aur:

```cpp
sum(2, 3, 4);
```

calls:

```text
sum(int, int, int)
```

---

# 6. Parameter types different

Ye bhi valid:

```cpp
int show(int x)
{
    return x;
}

double show(double x)
{
    return x;
}
```

```cpp
show(10);
```

→ `int` version

```cpp
show(10.5);
```

→ `double` version

---

# 7. Real-world intuition

Imagine tumhare paas:

```text
print()
```

function ka concept hai.

Tum chahte ho:

```cpp
print(10);
```

integer print kare.

Aur:

```cpp
print(10.5);
```

double handle kare.

Aur:

```cpp
print('A');
```

character handle kare.

Same conceptual task:

```text
print
```

but different inputs.

Isi ko **function overloading** kehte hain.

---

# 8. Important: Parameter names matter nahi karte

Ye:

```cpp
int add(int a, int b)
```

aur:

```cpp
int add(int x, int y)
```

**overloaded functions nahi hain.**

Because parameter types same hain:

```text
(int, int)
```

Names `a,b` vs `x,y` irrelevant hain.

---

# 9. Overloading ka mental rule

Function overload valid hai agar **parameter list different** ho.

Difference ho sakta hai:

```text
1. Number of parameters
2. Parameter types
3. Parameter arrangement/order
```

Example:

```cpp
void fun(int, double);
void fun(double, int);
```

Ye dono different hain:

```text
(int, double)
(double, int)
```

---

# 10. Default arguments + overloading ⚠️

Yahan thoda tricky case aa sakta hai.

```cpp
void fun(int a)
{
    cout << "A";
}

void fun(int a, int b = 10)
{
    cout << "B";
}
```

Ab:

```cpp
fun(5);
```

Problem ho sakti hai because dono functions call ke liye viable hain:

```text
fun(int)
fun(int, int=10)
```

So **default arguments ke saath overloading ambiguity create kar sakti hai.**

Abhi golden rule:

> Agar overloads bana rahe ho to unnecessary default arguments se ambiguity avoid karo.

---

# 🧠 Function Overloading ka summary

```text
Same function name
        +
Different parameter list
        =
Function Overloading
```

But:

```text
Same parameters
+
Different return type
=
❌ Not allowed
```

---

# 🎯 Practice — Part 5

### Q1

Kya ye overloading hai?

```cpp
int fun(int x)
{
    return x;
}

double fun(double x)
{
    return x;
}
```

---

### Q2

Kya ye valid overloading hai?

```cpp
int add(int a, int b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}
```

---

### Q3

Kya ye valid hai?

```cpp
int test(int a, int b)
{
    return a + b;
}

double test(int x, int y)
{
    return x + y;
}
```

**Why?**

---

### Q4 — Output

```cpp
void show(int x)
{
    cout << "INT";
}

void show(double x)
{
    cout << "DOUBLE";
}

int main()
{
    show(5);
    show(5.5);
}
```

Output?

---

### Q5 🔥

```cpp
void fun(int a)
{
    cout << "A";
}

void fun(int a, int b)
{
    cout << "B";
}

int main()
{
    fun(10);
    fun(10, 20);
}
```

Output?

---

Ye topic **DSA ke liye bohat important** hai, kyun ke arrays ko functions mein pass karna almost har jagah milega.

# 🧩 Part 6 — Arrays + Functions

## 1. Array ko function mein pass karna

Normal variable:

```cpp
void change(int x)
```

Array:

```cpp
void printArray(int arr[], int size)
```

Example:

```cpp
void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
```

Call:

```cpp
int arr[] = {10, 20, 30, 40, 50};

printArray(arr, 5);
```

Output:

```text
10 20 30 40 50
```

---

# 2. `arr[]` ke saath `size` kyun dete hain?

Ye bohat important hai.

Jab function ko array dete ho:

```cpp
printArray(arr, 5);
```

function ko automatically ye nahi pata ke array mein kitne elements hain.

Isliye:

```cpp
printArray(arr, 5);
```

mein `5` size pass kiya.

Function:

```cpp
void printArray(int arr[], int size)
```

mein:

```text
arr  → array
size → elements ki quantity
```

---

# 3. Dry Run

Array:

```text
10 20 30 40
```

Call:

```cpp
printArray(arr, 4);
```

Function ke andar:

```text
i = 0 → arr[0] → 10
i = 1 → arr[1] → 20
i = 2 → arr[2] → 30
i = 3 → arr[3] → 40
```

Output:

```text
10 20 30 40
```

---

# 4. Array modify karna

Ab important difference:

```cpp
void changeFirst(int arr[])
{
    arr[0] = 100;
}
```

Call:

```cpp
int arr[] = {10, 20, 30};

changeFirst(arr);

cout << arr[0];
```

Output:

```text
100
```

Original array change ho gaya.

---

# 🧠 Why?

Simple variables mein:

```cpp
void change(int x)
```

copy milti hai.

Lekin arrays function ko pass karte waqt function array ke elements ko modify kar sakta hai.

Conceptually:

```text
main array
   ↓
function
   ↓
same underlying array elements
```

Isliye:

```cpp
arr[0] = 100;
```

original array mein change nazar aata hai.

---

# 5. Array + function = common DSA pattern

Example: array ka sum.

```cpp
int sumArray(int arr[], int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}
```

Call:

```cpp
int arr[] = {2, 4, 6, 8};

int result = sumArray(arr, 4);

cout << result;
```

Dry run:

```text
sum = 0

i=0 → sum = 2
i=1 → sum = 6
i=2 → sum = 12
i=3 → sum = 20
```

Return:

```text
20
```

---

# 6. Array ka maximum function

```cpp
int findMax(int arr[], int size)
{
    int maximum = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }

    return maximum;
}
```

Call:

```cpp
int arr[] = {7, 2, 15, 4, 9};

cout << findMax(arr, 5);
```

Output:

```text
15
```

Notice:

```cpp
int maximum = arr[0];
```

`0` se initialize nahi kiya.

Ye isliye ke agar array ho:

```text
-8 -3 -10 -5
```

to maximum `-3` hona chahiye.

---

# 7. Array search function

```cpp
bool contains(int arr[], int size, int target)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            return true;
        }
    }

    return false;
}
```

Call:

```cpp
int arr[] = {4, 8, 2, 9};

cout << contains(arr, 4, 8);
```

Output:

```text
1
```

Agar target na mile:

```text
0
```

### Important:

```cpp
return true;
```

milte hi function terminate kar deta hai.

Ye exactly wohi early-exit pattern hai jo tumne prime checking mein dekha tha.

---

# 8. Array function mein index bhi pass kar sakte hain

Ye recursion mein bohat useful hai:

```cpp
int arraySum(int arr[], int index, int size)
{
    if(index == size)
        return 0;

    return arr[index] + arraySum(arr, index + 1, size);
}
```

Call:

```cpp
int arr[] = {1, 2, 3, 4, 5};

cout << arraySum(arr, 0, 5);
```

Result:

```text
15
```

Yani functions + arrays + recursion directly connect ho rahe hain.

---

# 9. `arr[]` aur `arr` call mein

Tumne recursion mein pehle ye confusion kiya tha:

```cpp
arraySum(arr, index + 1);
```

`arr[]` kyun nahi?

Answer:

### Function definition:

```cpp
int sum(int arr[], int size)
```

Yahan `[]` batata hai ke parameter array hai.

### Function call:

```cpp
sum(arr, 5);
```

Yahan sirf:

```cpp
arr
```

pass karte hain.

So:

```text
Definition → arr[]
Call        → arr
```

---

# 10. Array + `void`

Function ko value return karna zaroori nahi.

```cpp
void printEven(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
        {
            cout << arr[i] << " ";
        }
    }
}
```

Call:

```cpp
int arr[] = {1, 2, 3, 4, 6};

printEven(arr, 5);
```

Output:

```text
2 4 6
```

---

# 11. Array + Pass by Reference ka important distinction

Abhi ek subtle point:

```cpp
void fun(int arr[])
```

aur:

```cpp
void fun(int &x)
```

same cheez nahi hain.

First:

```cpp
int arr[]
```

array parameter hai.

Second:

```cpp
int &x
```

single variable ka reference hai.

Array ke saath C++ mein references ka aur advanced syntax bhi hota hai, jaise:

```cpp
void fun(int (&arr)[5])
```

Lekin **abhi isko memorize mat karo**. Pehle basic array-function model strong karo. DSA mein iska use context ke saath samjhenge.

---

# 12. Time Complexity bhi function ke saath

Example:

```cpp
int sumArray(int arr[], int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}
```

Loop `size` times chalega.

Therefore:

```text
Time Complexity = O(n)
```

Aur extra variables:

```text
sum
i
```

constant hain.

So:

```text
Space Complexity = O(1)
```

---

# 🧠 Golden Pattern

Jab bhi array function problem mile:

```text
Array
 ↓
Function
 ↓
size pass karo
 ↓
loop/index use karo
 ↓
required operation
 ↓
return / print
```

Typical functions:

```text
sumArray()
findMax()
findMin()
search()
countEven()
reverseArray()
isSorted()
```

Ye sab DSA mein repeatedly aayenge.

---

# 🎯 Practice — Part 6

Ab tum khud solve karo bhai.

### Q1

Function complete karo:

```cpp
void printArray(int arr[], int size)
{
    // your code
}
```

Input array:

```text
5 10 15 20
```

Output:

```text
5 10 15 20
```

---

### Q2

Function banao:

```cpp
int sumArray(int arr[], int size)
```

jo array ka sum return kare.

For:

```text
1 2 3 4 5
```

answer:

```text
15
```

---

### Q3 🔥

Function banao:

```cpp
int findMax(int arr[], int size)
```

For:

```text
{4, 9, 2, 15, 7}
```

return kya karega?

---

### Q4 — Search

Function:

```cpp
bool search(int arr[], int size, int target)
```

Agar target mil jaye → `true`

warna → `false`.

---

### Q5 — Dry Run

```cpp
void change(int arr[], int size)
{
    arr[0] = 100;

    arr[size - 1] = 200;
}

int main()
{
    int arr[] = {10, 20, 30, 40};

    change(arr, 4);

    cout << arr[0] << " " << arr[3];
}
```

Output kya hoga?

Aur explain karo **original array kyun change hua**.

---

### Q6 🔥 Interview-style

```cpp
bool isSorted(int arr[], int size)
```

Aisa function banao jo check kare ke array ascending order mein sorted hai ya nahi.

Example:

```text
{2, 4, 7, 9} → true
{2, 7, 5, 9} → false
```

**Hint:** Har element ko next element se compare karna hai.

Chalo bhai 🔥 **Chapter 7 — Part 7: Strings + Functions**.

Arrays ke baad strings ko functions mein handle karna naturally next step hai. Aur yahan se **strings + loops + functions** ek saath combine honge.

# 🧩 Part 7 — Strings with Functions

## 1. String ko function mein pass karna

C++ mein do common string approaches hain:

### C-style string

```cpp
char name[] = "Hassan";
```

### C++ `string`

```cpp
string name = "Hassan";
```

Abhi hum mainly **`string`** use karenge, kyun ke ye cleaner aur beginner-friendly hai.

---

# 2. Basic string function

```cpp
#include <iostream>
#include <string>
using namespace std;

void printName(string name)
{
    cout << name;
}

int main()
{
    string name = "Hassan";

    printName(name);
}
```

Flow:

```text
main
 ↓
name = "Hassan"
 ↓
printName(name)
 ↓
function ko string milti hai
 ↓
Hassan
```

---

# 3. String parameter

Ye:

```cpp
void printName(string name)
```

mein:

```text
string → data type
name   → parameter
```

Call:

```cpp
printName("Hassan");
```

mein:

```text
"Hassan" → argument
```

Same parameter/argument concept jo normal variables mein tha.

---

# 4. String ki length function

C++ `string` ka:

```cpp
.length()
```

use kar sakte hain.

Example:

```cpp
int lengthOfString(string s)
{
    return s.length();
}
```

Call:

```cpp
string name = "Hassan";

cout << lengthOfString(name);
```

Output:

```text
6
```

Because:

```text
H a s s a n
0 1 2 3 4 5
```

6 characters.

---

# 5. String ke characters access karna

Bilkul array ki tarah:

```cpp
string s = "Hello";

cout << s[0];
cout << s[1];
cout << s[2];
```

Output:

```text
Hel
```

Index:

```text
H e l l o
0 1 2 3 4
```

So:

```cpp
s[i]
```

se character access hota hai.

---

# 6. Function: string print character by character

```cpp
void printChars(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        cout << s[i] << " ";
    }
}
```

Call:

```cpp
printChars("HELLO");
```

Output:

```text
H E L L O
```

### Pattern familiar hai?

Bilkul array jaisa:

```cpp
for(int i = 0; i < size; i++)
```

String mein:

```cpp
for(int i = 0; i < s.length(); i++)
```

---

# 7. Count vowels using function

Ab thoda useful problem:

```cpp
int countVowels(string s)
{
    int count = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'a' ||
           s[i] == 'e' ||
           s[i] == 'i' ||
           s[i] == 'o' ||
           s[i] == 'u')
        {
            count++;
        }
    }

    return count;
}
```

Call:

```cpp
cout << countVowels("hello");
```

Dry run:

```text
h → no
e → yes → count = 1
l → no
l → no
o → yes → count = 2
```

Return:

```text
2
```

---

# 8. Uppercase vowels ka kya?

Agar input:

```text
HELLO
```

hai, previous function lowercase vowels hi check karega.

We can handle both:

```cpp
if(s[i] == 'a' || s[i] == 'e' ||
   s[i] == 'i' || s[i] == 'o' ||
   s[i] == 'u' ||
   s[i] == 'A' || s[i] == 'E' ||
   s[i] == 'I' || s[i] == 'O' ||
   s[i] == 'U')
{
    count++;
}
```

Ab:

```text
hello → 2
HELLO → 2
HeLLo → 2
```

---

# 9. String mein specific character count karna

Ye zyada general function hai:

```cpp
int countCharacter(string s, char target)
{
    int count = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == target)
        {
            count++;
        }
    }

    return count;
}
```

Call:

```cpp
cout << countCharacter("banana", 'a');
```

Dry run:

```text
b → no
a → yes → 1
n → no
a → yes → 2
n → no
a → yes → 3
```

Output:

```text
3
```

Yahan dekho:

```cpp
char target
```

ek parameter hai.

So function multiple data types bhi accept kar sakta hai:

```cpp
int countCharacter(string s, char target)
```

---

# 10. String reverse using function

Tum recursion mein reverse string already dekh chuke ho. Ab loop + function se.

```cpp
void reverseString(string s)
{
    for(int i = s.length() - 1; i >= 0; i--)
    {
        cout << s[i];
    }
}
```

Call:

```cpp
reverseString("HELLO");
```

Output:

```text
OLLEH
```

### Important:

Ye function **reverse print** kar raha hai.

Original string modify nahi kar raha.

---

# 11. Reverse karke return karna

Agar humein reversed string **return** karni ho:

```cpp
string reverseString(string s)
{
    string result = "";

    for(int i = s.length() - 1; i >= 0; i--)
    {
        result += s[i];
    }

    return result;
}
```

Call:

```cpp
string answer = reverseString("HELLO");

cout << answer;
```

Output:

```text
OLLEH
```

Yahan important difference:

```text
void function
→ print kar sakti hai

string function
→ string return kar sakti hai
```

---

# 12. Palindrome function

Ab recursion se connection 🔥

Palindrome:

```text
madam
level
racecar
```

Forward aur backward same.

Function:

```cpp
bool isPalindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while(left < right)
    {
        if(s[left] != s[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
```

Example:

```cpp
cout << isPalindrome("madam");
```

Output:

```text
1
```

---

# 13. Is function ka dry run

String:

```text
madam
```

Indices:

```text
m a d a m
0 1 2 3 4
```

Initially:

```text
left = 0
right = 4
```

Compare:

```text
s[0] == s[4]
m == m ✓
```

Then:

```text
left = 1
right = 3
```

Compare:

```text
a == a ✓
```

Then:

```text
left = 2
right = 2
```

Loop:

```cpp
left < right
```

false.

So:

```cpp
return true;
```

---

# 14. Why `left < right`?

Because humein pair comparisons karni hain.

```text
m a d a m
↑       ↑
L       R

  ↑   ↑
  L   R

    ↑
    same
```

Center character ko khud se compare karne ki zaroorat nahi.

Isliye:

```cpp
left < right
```

---

# 15. String + Pass by Reference

Ab previous topic ka connection.

Suppose:

```cpp
void change(string &s)
{
    s[0] = 'X';
}
```

Call:

```cpp
string name = "Hassan";

change(name);

cout << name;
```

Output:

```text
Xassan
```

Kyun?

`string &s` reference hai.

So:

```text
s → original name
```

Aur:

```cpp
s[0] = 'X';
```

original string modify kar deta hai.

---

# 16. Agar modification nahi karni ho?

Large strings ke case mein unnecessary copying avoid karne ke liye commonly:

```cpp
void print(const string &s)
{
    cout << s;
}
```

Yahan:

```text
const → function string ko modify nahi karega
&     → unnecessary copy avoid
```

Abhi isko **advanced best-practice concept** samjho. `const` references ko detail mein pointers/references ke saath aur deeply cover karenge.

---

# 🧠 Array vs String

Ab comparison dekho:

### Array

```cpp
void printArray(int arr[], int size)
```

### String

```cpp
void printString(string s)
```

Array mein manually size pass karna common hai:

```cpp
printArray(arr, 5);
```

String mein:

```cpp
s.length()
```

se length mil sakti hai:

```cpp
printString(s);
```

---

# 🔥 Important DSA Connection

Strings ke bohat se problems actually arrays jaisi hi thinking use karte hain:

```text
String
 ↓
indexing
 ↓
loop
 ↓
comparison
 ↓
count / search / modify
```

Examples:

* Count vowels
* Count a character
* Reverse string
* Palindrome
* Find character
* Count digits
* Remove spaces
* Check frequency
* Compare strings

Isliye arrays strong honge to strings bhi comparatively easy feel hongi.

---

# 🎯 Part 7 Practice

Ab tumhari turn bhai.

### Q1 — Length

Function banao:

```cpp
int getLength(string s)
```

jo string ki length return kare.

---

### Q2 — Character Count

```cpp
int countCharacter(string s, char target)
```

For:

```text
"programming", 'g'
```

answer kya hoga?

---

### Q3 — Vowels

```cpp
int countVowels(string s)
```

For:

```text
"education"
```

vowels count karo.

---

### Q4 — Reverse

Function:

```cpp
string reverseString(string s)
```

`"Hassan"` ko reverse karke return kare.

---

### Q5 🔥 Palindrome

Function:

```cpp
bool isPalindrome(string s)
```

Check:

```text
"madam" → true
"hello" → false
"level" → true
```

---

### Q6 — Dry Run

```cpp
void change(string &s)
{
    s[0] = 'X';
    s[2] = 'Y';
}

int main()
{
    string s = "Hassan";

    change(s);

    cout << s;
}
```

Exact output kya hoga?

Aur explain karo ke **original string change kyun hui**.

---

# 🧩 Part 8 — Functions + Recursion

## 1. Recursive Function kya hota hai?

Simple:

> **Aisa function jo khud ko call kare, recursive function kehlata hai.**

Example:

```cpp
void countDown(int n)
{
    if(n == 0)
        return;

    cout << n << " ";

    countDown(n - 1);
}
```

Call:

```cpp
countDown(5);
```

Output:

```text
5 4 3 2 1
```

---

# 2. Recursive function ke 2 essential parts

Har proper recursive function mein normally:

### 1. Base Case

```cpp
if(n == 0)
    return;
```

Ye recursion ko stop karta hai.

### 2. Recursive Case

```cpp
countDown(n - 1);
```

Ye function ko smaller problem ke saath dobara call karta hai.

Mental model:

```text
Recursive Function
│
├── Base Case
│    └── Stop
│
└── Recursive Case
     └── Function calls itself
```

---

# 3. Function call flow connect karo

Example:

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    cout << n << " ";

    fun(n - 1);
}
```

Call:

```cpp
fun(3);
```

Flow:

```text
main
 ↓
fun(3)
 ↓
print 3
 ↓
fun(2)
 ↓
print 2
 ↓
fun(1)
 ↓
print 1
 ↓
fun(0)
 ↓
return
```

Output:

```text
3 2 1
```

---

# 4. `return` ka role recursion mein

Ye bohat important hai.

```cpp
if(n == 0)
    return;
```

Yahan `return` ka matlab:

> Is particular function call ko terminate karo aur previous call mein wapas jao.

Example:

```text
fun(3)
 ↓
fun(2)
 ↓
fun(1)
 ↓
fun(0)
```

`fun(0)` mein:

```cpp
return;
```

Then:

```text
fun(0) ends
 ↓
fun(1)
 ↓
fun(1) continues/ends
 ↓
fun(2)
 ↓
fun(3)
```

Ye wahi **rewinding/unwinding** hai jo hum recursion chapter mein kar chuke hain.

---

# 5. Return value wali recursion

Ab `void` nahi.

```cpp
int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

Call:

```cpp
int result = factorial(5);
```

---

# 6. Dry Run — Factorial

Mathematical:

```text
5! = 5 × 4 × 3 × 2 × 1
```

Function:

```text
factorial(5)
= 5 * factorial(4)

= 5 * 4 * factorial(3)

= 5 * 4 * 3 * factorial(2)

= 5 * 4 * 3 * 2 * factorial(1)

= 5 * 4 * 3 * 2 * 1 * factorial(0)
```

Base case:

```cpp
factorial(0)
→ 1
```

Now return upward:

```text
factorial(0) = 1

factorial(1) = 1 × 1 = 1

factorial(2) = 2 × 1 = 2

factorial(3) = 3 × 2 = 6

factorial(4) = 4 × 6 = 24

factorial(5) = 5 × 24 = 120
```

Final:

```text
120
```

---

# 7. Function + recursion + array

Ab tumhare previous array-function topic ko recursion ke saath combine karte hain.

```cpp
int arraySum(int arr[], int index, int size)
{
    if(index == size)
        return 0;

    return arr[index] + arraySum(arr, index + 1, size);
}
```

Array:

```text
1 2 3 4 5
```

Call:

```cpp
arraySum(arr, 0, 5);
```

Expansion:

```text
arraySum(arr,0,5)
= 1 + arraySum(arr,1,5)

= 1 + 2 + arraySum(arr,2,5)

= 1 + 2 + 3 + arraySum(arr,3,5)

= 1 + 2 + 3 + 4 + arraySum(arr,4,5)

= 1 + 2 + 3 + 4 + 5 + arraySum(arr,5,5)
```

Base:

```text
arraySum(arr,5,5) = 0
```

Return:

```text
5
↑
5 + 0 = 5

4 + 5 = 9

3 + 9 = 12

2 + 12 = 14

1 + 14 = 15
```

Result:

```text
15
```

---

# 8. Function + recursion + string

Palindrome recursion:

```cpp
bool isPalindrome(string s, int left, int right)
{
    if(left >= right)
        return true;

    if(s[left] != s[right])
        return false;

    return isPalindrome(s, left + 1, right - 1);
}
```

Call:

```cpp
string s = "madam";

cout << isPalindrome(s, 0, s.length() - 1);
```

---

# 9. Is recursion ko samjho

String:

```text
m a d a m
↑       ↑
L       R
```

Compare:

```text
m == m ✓
```

Then:

```text
  ↑   ↑
  L   R
```

Compare:

```text
a == a ✓
```

Then:

```text
    ↑
    L/R
```

Base case:

```cpp
left >= right
```

So:

```text
true
```

Return chain:

```text
true
↑
true
↑
true
```

Final result:

```text
true
```

---

# 10. Recursion mein parameters ka role

Ye function:

```cpp
int factorial(int n)
```

har recursive call mein **new parameter value** receive karta hai.

```text
factorial(5)
    n = 5

factorial(4)
    n = 4

factorial(3)
    n = 3

factorial(2)
    n = 2

factorial(1)
    n = 1

factorial(0)
    n = 0
```

Ye tumhare earlier stack-frame concept se directly connected hai.

Har call ka apna:

```text
parameter
local variables
return point
```

hota hai.

---

# 11. Recursion mein local variables bhi separate hote hain

Example:

```cpp
void fun(int n)
{
    int x = n;

    if(n == 0)
        return;

    fun(n - 1);
}
```

Agar:

```cpp
fun(3);
```

call karo, conceptual stack:

```text
fun(3): x = 3
fun(2): x = 2
fun(1): x = 1
fun(0): x = 0
```

Har call ka `x` alag hai.

Ye bilkul normal function scope + recursion ka combination hai.

---

# 12. Recursion + `return` ko confuse mat karna

Compare:

### Printing recursion

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    cout << n;
    fun(n - 1);
}
```

Yahan recursive call ka return value nahi chahiye.

---

### Returning recursion

```cpp
int fun(int n)
{
    if(n == 0)
        return 0;

    return n + fun(n - 1);
}
```

Yahan recursive call ka result **important** hai.

For `fun(3)`:

```text
fun(3)
= 3 + fun(2)
= 3 + 2 + fun(1)
= 3 + 2 + 1 + fun(0)
= 6
```

---

# 13. Recursion + function decomposition

Functions ka main benefit hi yahan nazar aata hai.

Suppose program mein:

```text
sum
max
search
reverse
palindrome
```

sab tasks hain.

Hum separate functions bana sakte hain:

```cpp
sumArray()
findMax()
search()
reverseString()
isPalindrome()
```

Aur agar problem naturally recursive hai:

```cpp
arraySum()
factorial()
binarySearch()
isPalindrome()
```

to function ke andar recursion use kar sakte hain.

So:

> **Recursion koi separate type of function nahi hai. Recursion ek function ke execution ka pattern hai jahan function khud ko call karta hai.**

🔥 Ye line yaad rakhna.

---

# 14. Time Complexity connection

Ab functions ke saath complexity bhi connect karo.

### Factorial

```cpp
int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

Recurrence:

```text
T(n) = T(n-1) + O(1)
```

Therefore:

```text
Time = O(n)
```

Aur recursive call stack:

```text
n calls
```

so:

```text
Space = O(n)
```

---

### Recursive array sum

```cpp
arraySum(arr, index + 1, size)
```

Har element once process hota hai:

```text
Time = O(n)
Space = O(n)
```

Space yahan recursion call stack ki wajah se hai.

---

# 🧠 Master Mental Model

Functions ko ab is tarah dekho:

```text
FUNCTION
│
├── Input
│   └── Parameters
│
├── Processing
│
├── Output
│   └── Return value
│
├── Scope
│
├── Pass by Value / Reference
│
├── Arrays / Strings
│
└── Recursion
    ├── Base Case
    ├── Recursive Case
    └── Call Stack
```

Ye structure PF ke baad DSA mein repeatedly kaam aayega.

---

# 🎯 Part 8 Practice

Ab tumhari turn bhai. Solutions abhi mat dekhna.

### Q1 — Basic recursion

Function banao:

```cpp
void printNumbers(int n)
```

jo:

```text
5 4 3 2 1
```

print kare recursively.

---

### Q2 — Return recursion

Function:

```cpp
int sumN(int n)
```

jo:

```text
1 + 2 + 3 + ... + n
```

return kare.

For:

```text
sumN(5) → 15
```

---

### Q3 — Factorial

```cpp
int factorial(int n)
```

`5!` calculate karo recursively.

---

### Q4 — Array recursion 🔥

```cpp
int arraySum(int arr[], int index, int size)
```

For:

```text
{2, 4, 6, 8}
```

sum return karo.

---

### Q5 — String recursion 🔥

```cpp
bool isPalindrome(string s, int left, int right)
```

Check:

```text
"level"
"hello"
```

---

### Q6 — Dry Run

Sabse important:

```cpp
int fun(int n)
{
    if(n == 0)
        return 0;

    return n + fun(n - 1);
}
```

Find:

```cpp
fun(4)
```

**Call expansion + return/unwinding dono likhna.**

---

### Q7 — Complexity

Is function ki:

```cpp
int fun(int n)
{
    if(n == 0)
        return 1;

    return fun(n - 1);
}
```

* Time Complexity?
* Space Complexity?

---