# 1. Recursion actually hoti kya hai?

Simple definition:

> **Recursion is a technique in which a function calls itself with a smaller/simpler input until a stopping condition is reached.**

Example:

```cpp
void fun(int n)
{
    if (n == 0)
        return;

    cout << n << endl;

    fun(n - 1);
}
```

Agar:

```cpp
fun(5);
```

toh:

```text
fun(5)
  ↓
fun(4)
  ↓
fun(3)
  ↓
fun(2)
  ↓
fun(1)
  ↓
fun(0)
  ↓
STOP
```

Yahan function **khud ko call** kar raha hai.

---

# 2. Recursion ke 2 most important parts

Har recursion mein sabse pehle ye 2 cheezein dhundo.

## A. Base Case

Ye batata hai:

> **"Kab rukna hai?"**

Example:

```cpp
if (n == 0)
    return;
```

Ye base case hai.

Agar base case nahi hoga, function continuously khud ko call karta rahega.

---

## B. Recursive Case

Ye woh part hai jahan function **khud ko call karta hai**:

```cpp
fun(n - 1);
```

Yahan `n` har baar chhota ho raha hai:

```text
5 → 4 → 3 → 2 → 1 → 0
```

Isliye problem eventually base case tak pohanchti hai.

---

# 3. Ek important rule

Jab bhi recursion ka question mile, **sabse pehle ye mat dekho ke output kya hai.**

Pehle identify karo:

```text
1. Base case kya hai?
2. Recursive call kya hai?
3. Input har call mein kaise change ho raha hai?
4. Function call ke BAAD kya code hai?
```

Ye 4 cheezein recursion solve karne ki foundation hain.

---

# 4. Ab sabse important concept: CALL vs RETURN

Yahin se actual recursion samajh aati hai.

Code:

```cpp
void fun(int n)
{
    if (n == 0)
        return;

    cout << n << " ";

    fun(n - 1);
}
```

`fun(5)`:

```text
fun(5)
print 5
 ↓
fun(4)
print 4
 ↓
fun(3)
print 3
 ↓
fun(2)
print 2
 ↓
fun(1)
print 1
 ↓
fun(0)
return
```

Output:

```text
5 4 3 2 1
```

Abhi tak easy.

Lekin **recursion ka asli game** tab start hota hai jab recursive call ke **baad** koi statement ho.

---

# 5. Ye code dekho

```cpp
void fun(int n)
{
    if (n == 0)
        return;

    fun(n - 1);

    cout << n << " ";
}
```

Notice karo:

Pehle:

```cpp
fun(n - 1);
```

phir:

```cpp
cout << n;
```

Agar:

```cpp
fun(5);
```

toh pehle calls neeche jayengi:

```text
fun(5)
 ↓
fun(4)
 ↓
fun(3)
 ↓
fun(2)
 ↓
fun(1)
 ↓
fun(0)
```

`fun(0)` par return.

**Ab wapas aana start hoga:**

```text
fun(0) returns
   ↑
fun(1) → print 1
   ↑
fun(2) → print 2
   ↑
fun(3) → print 3
   ↑
fun(4) → print 4
   ↑
fun(5) → print 5
```

Output:

```text
1 2 3 4 5
```

### Ye concept bohat important hai:

```text
Recursive call BEFORE cout
        ↓
Output return/unwinding ke waqt

Recursive call AFTER cout
        ↓
Output calling/downward phase mein
```

---

# 6. Ab CALL STACK samjho ⭐⭐⭐

Tumne poocha tha **stack form**.

Actually recursion ko samajhne ke liye **call stack** samajhna bohat zaroori hai.

Computer jab function call karta hai, us function ki information temporarily **stack** mein rakhta hai.

Stack ka rule:

> **LIFO = Last In, First Out**

Jaise plates:

```text
      ┌───────┐
      │ Plate │ ← last placed
      ├───────┤
      │ Plate │
      ├───────┤
      │ Plate │
      └───────┘
```

Jo plate sabse last mein rakhi, woh sabse pehle niklegi.

Recursion mein bhi exactly yehi hota hai.

---

# 7. Call Stack ka example

Code:

```cpp
void fun(int n)
{
    if (n == 0)
        return;

    fun(n - 1);

    cout << n << " ";
}
```

`fun(3)` call karo.

### Step 1

```text
fun(3)
```

Stack:

```text
┌─────────┐
│ fun(3)  │
└─────────┘
```

---

### Step 2

`fun(3)` calls `fun(2)`.

```text
┌─────────┐
│ fun(2)  │ ← top
├─────────┤
│ fun(3)  │
└─────────┘
```

---

### Step 3

`fun(2)` calls `fun(1)`.

```text
┌─────────┐
│ fun(1)  │ ← top
├─────────┤
│ fun(2)  │
├─────────┤
│ fun(3)  │
└─────────┘
```

---

### Step 4

`fun(1)` calls `fun(0)`.

```text
┌─────────┐
│ fun(0)  │ ← top
├─────────┤
│ fun(1)  │
├─────────┤
│ fun(2)  │
├─────────┤
│ fun(3)  │
└─────────┘
```

Now base case:

```cpp
if (n == 0)
    return;
```

So `fun(0)` **pop** ho jayega.

---

# 8. POP hone ke baad kya hota hai?

This is extremely important.

`fun(0)` return:

```text
fun(0) ❌
```

Ab control wapas `fun(1)` mein aayega.

Aur yaad karo `fun(1)` mein:

```cpp
fun(n - 1);

cout << n;
```

`fun(0)` complete ho chuka.

Ab:

```cpp
cout << 1;
```

execute hoga.

Then `fun(1)` finishes.

Then `fun(2)` resume hota hai:

```cpp
cout << 2;
```

Then `fun(3)`:

```cpp
cout << 3;
```

Output:

```text
1 2 3
```

---

# 9. Isko "unwinding" kehte hain

Recursion mein 2 phases imagine karo:

### Phase 1 — Going Down

```text
fun(3)
 ↓
fun(2)
 ↓
fun(1)
 ↓
fun(0)
```

### Phase 2 — Coming Back / Unwinding

```text
fun(0)
 ↑
fun(1)
 ↑
fun(2)
 ↑
fun(3)
```

Isi second phase mein recursive-call ke baad wala code execute hota hai.

---

# 10. Stack Form

Agar teacher **"stack form"** kahe, usually woh recursion ki calls ko stack mein represent karne ki baat kar sakta hai.

Example:

```cpp
fun(3);
```

calls:

```text
        CALLING DOWN

       fun(3)
          ↓
       fun(2)
          ↓
       fun(1)
          ↓
       fun(0)

        RETURNING UP

       fun(0)
          ↑
       fun(1)
          ↑
       fun(2)
          ↑
       fun(3)
```

Stack:

```text
┌─────────┐
│ fun(3)  │
├─────────┤
│ fun(2)  │
├─────────┤
│ fun(1)  │
├─────────┤
│ fun(0)  │
└─────────┘
```

`fun(0)` sabse last mein enter hua tha, therefore woh **sabse pehle return** karega.

---

# 11. "Free structure" kya hota hai?

Mujhe lagta hai tumhare teacher ka term **"free structure"** nahi balki **"tree structure" / "free structure"** ke context mein recursion ke structures ki baat ho sakti hai. Agar unhone exact term **free structure** board/slides par diya hai, woh line/photo bhej dena—main exactly usi terminology ke according samjha dunga.

Lekin recursion mein commonly **linear/stack recursion** aur **tree recursion** hoti hai.

---

# 12. Linear / Stack Recursion

Jab har function call se **sirf ek recursive call** nikle:

```cpp
fun(n - 1);
```

Structure:

```text
fun(5)
  ↓
fun(4)
  ↓
fun(3)
  ↓
fun(2)
  ↓
fun(1)
```

Ye basically **straight line** hai.

Isliye ise linear recursion kaha jata hai.

---

# 13. Tree Recursion ⭐

Ab ye dekho:

```cpp
void fun(int n)
{
    if (n == 0)
        return;

    fun(n - 1);
    fun(n - 1);
}
```

Ek function **do recursive calls** kar raha hai.

For `fun(3)`:

```text
                 fun(3)
                /      \
           fun(2)      fun(2)
           /   \        /   \
       fun(1) fun(1) fun(1) fun(1)
        / \     / \    / \    / \
       ...     ...    ...    ...
```

Ab ye straight line nahi hai.

Ye **tree** jaisa ban gaya.

Isliye:

> **When a recursive function makes multiple recursive calls, the call structure can form a tree.**

---

# 14. Linear vs Tree Recursion

### Linear recursion

```cpp
fun(n - 1);
```

One recursive call.

```text
       fun(5)
          |
       fun(4)
          |
       fun(3)
          |
       fun(2)
```

### Tree recursion

```cpp
fun(n - 1);
fun(n - 1);
```

Two recursive calls.

```text
          fun(5)
         /      \
      fun(4)   fun(4)
      /   \     /   \
   fun3 fun3 fun3 fun3
```

---

# 15. Famous example: Fibonacci

Fibonacci recursion:

```cpp
int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}
```

Yahan:

```cpp
fib(n - 1)
fib(n - 2)
```

**2 recursive calls** hain.

So `fib(5)` creates a tree:

```text
                 fib(5)
                /      \
            fib(4)     fib(3)
           /    \       /   \
       fib(3) fib(2) fib(2) fib(1)
       /  \
   fib(2) fib(1)
```

Isi wajah se Fibonacci ka simple recursive version bohat zyada repeated work karta hai.

---

# 16. Ab recursion ko identify karne ka formula

Quiz mein koi bhi recursive code aaye:

### Step 1

Dekho function **khud ko call kar raha hai?**

```cpp
fun(...)
```

inside:

```cpp
fun(...)
```

Yes → recursion.

### Step 2

Base case find karo.

```cpp
if (...)
    return;
```

### Step 3

Recursive call find karo.

```cpp
fun(...)
```

### Step 4

Dekho input smaller ho raha hai?

```cpp
fun(n - 1)
```

Good.

### Step 5

Dekho recursive call se pehle kya hai.

### Step 6

Dekho recursive call ke baad kya hai.

**Step 6 output questions ke liye bohat important hai.**

---

# 17. Ek SUPER important example

```cpp
void fun(int n)
{
    if (n == 0)
        return;

    cout << n << " ";

    fun(n - 1);

    cout << n << " ";
}
```

Question:

> `fun(3)` ka output?

Don't guess.

Let's break it.

### `fun(3)`

Print:

```text
3
```

then:

```text
fun(2)
```

`fun(2)` prints:

```text
2
```

then:

```text
fun(1)
```

prints:

```text
1
```

then:

```text
fun(0)
```

returns.

Now coming back:

`fun(1)` ka second cout:

```text
1
```

Then `fun(2)`:

```text
2
```

Then `fun(3)`:

```text
3
```

Final:

```text
3 2 1 1 2 3
```

### Ye recursion ka real power hai.

Ek function ke andar statements **downward phase** aur **returning phase** dono mein execute ho sakti hain.

---

# 18. Ab ek aur concept: Recursion aur memory

Har recursive call stack mein apna **separate function frame** banata hai.

For:

```cpp
fun(3)
```

roughly:

```text
┌────────────────┐
│ fun(3): n = 3  │
├────────────────┤
│ fun(2): n = 2  │
├────────────────┤
│ fun(1): n = 1  │
└────────────────┘
```

`n` ki values alag hain.

Ye bohat important hai:

> `fun(3)` ka `n` aur `fun(2)` ka `n` same variable nahi hain. Har function call ka apna local `n` hota hai.

---

# 19. Recursion ka basic mental model

Jab tum recursion dekho, dimagh mein ye picture banao:

```text
             CALL
              ↓
       "Mujhe ye problem
        solve karni hai."
              ↓
       "Lekin main iska
        smaller version
        khud ko de deta hoon."
              ↓
          CALL AGAIN
              ↓
             ...
              ↓
         BASE CASE
              ↓
           RETURN
              ↑
       pending work execute
              ↑
           RETURN
              ↑
       pending work execute
              ↑
             ...
```

**Yehi recursion hai.**

---

# 20. Sabse common beginner mistake

Log recursion ko aise dekhte hain:

```cpp
fun(n - 1);
```

aur confuse ho jate hain:

> "Ye khud ko baar baar call kaise kar raha hai?"

Simple:

`fun(5)` ke andar `fun(4)` call hota hai.

`fun(4)` ke andar `fun(3)` call hota hai.

`fun(3)` ke andar `fun(2)` call hota hai.

Ye **same function** hai, lekin **different function calls / frames** hain.

```text
fun(5) ≠ fun(4) ≠ fun(3)
```

Function ka code same hai, **input/state different hai**.

---

# 🧠 Aaj ke liye ye 7 cheezein pakki kar lo

```text
1. Recursion = function calls itself

2. Base case = stopping condition

3. Recursive case = function calls itself

4. Input ko smaller/simpler banana zaroori hai

5. Function calls stack mein store hoti hain

6. Stack = LIFO
   Last In → First Out

7. Recursive call ke BAAD ka code
   returning/unwinding phase mein execute hota hai
```

Aur structures:

```text
One recursive call
       ↓
Linear / stack-like recursion

Multiple recursive calls
       ↓
Tree recursion
```

### 🎯 Hamara Recursion Attack Plan

Hum questions ko is order mein karenge:

1. **Basic output questions** — `1 to n`, `n to 1`
2. **Before vs after recursive call** — sab se important trick
3. **Sum of n numbers**
4. **Factorial**
5. **Power**
6. **Fibonacci**
7. **Reverse a number / digits**
8. **Sum of digits**
9. **Count digits**
10. **Palindrome**
11. **Array recursion** — print/search/max
12. **String recursion** — reverse/palindrome
13. **Multiple recursive calls**
14. 🌳 **Tree recursion**
15. **Fibonacci recursion tree**
16. **Tracing / call stack questions**
17. **Return-value recursion**
18. **Recursion + loops** — tricky
19. **Nested recursion** — agar syllabus mein ho
20. **Backtracking basics** — recursion ka advanced form
21. **Mixed tricky quiz questions** 😈

Aur har question mein main tumhein ye 5 cheezen pakka karwaunga:

> **Base Case → Recursive Case → Smaller Problem → Call Stack → Unwinding**

---

# 🧠 Question 1 — Sab se basic

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    cout << n << " ";
    fun(n - 1);
}
```

Agar:

```cpp
fun(5);
```

to output kya hoga?

**Pehle khud solve karo.**
Sirf output batao — phir main iska **proper stack dry run** karwaunga.

Hint:

```text
fun(5)
   ↓
fun(4)
   ↓
fun(3)
   ↓
fun(2)
   ↓
fun(1)
   ↓
fun(0)
```

## 🔥 Recursion — Question 2 Family

### Pattern: `Before recursion` vs `After recursion`

### Q2.1 — Basic reverse printing

Write a recursive function that takes an integer `n` and prints numbers from **n down to 1**.

Example:

```text
Input: 5
Output: 5 4 3 2 1
```

---

### Q2.2 — Ascending printing

Write a recursive function that takes an integer `n` and prints numbers from **1 to n**.

Example:

```text
Input: 5
Output: 1 2 3 4 5
```

---

### Q2.3 — Tricky Output ①

What will be the output?

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    fun(n - 1);
    cout << n << " ";
}
```

Call:

```cpp
fun(5);
```

---

### Q2.4 — Tricky Output ②

What will be the output?

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    cout << n << " ";
    fun(n - 1);
    cout << n << " ";
}
```

Call:

```cpp
fun(3);
```

⚠️ **Ye important hai.** Ismein har number **2 dafa** print hoga, lekin order samajhna hai.

---

### Q2.5 — Tricky Output ③

What will be the output?

```cpp
void fun(int n)
{
    if(n <= 0)
        return;

    cout << n << " ";
    fun(n - 1);
    cout << n * 2 << " ";
}
```

Call:

```cpp
fun(3);
```

---

### Q2.6 — Tricky Output ④

What will be the output?

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    fun(n - 1);
    cout << n << " ";
    fun(n - 1);
}
```

Call:

```cpp
fun(3);
```

🔥 **Ye tumhara pehla proper tree-recursion type question hai.**

---

### Q2.7 — Output + Stack

For the following code:

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    cout << "A" << n << " ";
    fun(n - 1);
    cout << "B" << n << " ";
}
```

What is the output for:

```cpp
fun(3);
```

Also identify:

* `A` kis phase mein print hota hai?
* `B` kis phase mein print hota hai?

---

### Q2.8 — Return after recursion

What will this function return?

```cpp
int fun(int n)
{
    if(n == 0)
        return 0;

    return n + fun(n - 1);
}
```

For:

```cpp
fun(5);
```

---

### Q2.9 — Tricky Return

What will this return?

```cpp
int fun(int n)
{
    if(n == 1)
        return 1;

    return fun(n - 1) * 2;
}
```

For:

```cpp
fun(5);
```

---

### Q2.10 — Teacher-style tracing 😈

Trace this completely:

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    cout << n << " ";
    fun(n - 1);
    cout << n << " ";
}
```

For:

```cpp
fun(4);
```

Tumhein **calling phase** aur **returning/unwinding phase** dono likhne hain.

---

## 🧩 Ek important challenge

In questions ko solve karte waqt har recursive function ke liye ye 4 questions khud se poochna:

**1. Base case kya hai?**
**2. Recursive call kis value ke saath hai?**
**3. Recursive call se PEHLE kya ho raha hai?**
**4. Recursive call ke BAAD kya ho raha hai?**

Agar ye 4 cheezen samajh aa gayin, recursion ke output questions kaafi easy ho jayenge.

**Next level mein hum woh questions karenge jahan dekhne mein code simple hota hai lekin output nikalna tricky hota hai.**

## 🔥 Level 2 — Recursion ke Famous Questions

Ab tum **ye solve karo, solutions mat dekhna**:

### Q3 — Sum of first N numbers

Recursive function banao jo:

```text
Input: 5
Output: 15
```

yaani:

```text
1 + 2 + 3 + 4 + 5
```

---

### Q4 — Factorial

Recursive function banao:

```text
Input: 5
Output: 120
```

Because:

```text
5 × 4 × 3 × 2 × 1
```

---

### Q5 — Power

Recursive function banao jo `a^b` calculate kare.

```text
Input: a = 2, b = 5
Output: 32
```

---

### Q6 — Sum of digits

Recursive function banao jo number ke digits ka sum return kare.

```text
Input: 12345
Output: 15
```

---

### Q7 — Count digits

Recursive function banao jo number mein total digits count kare.

```text
Input: 58392
Output: 5
```

---

### Q8 — Reverse a number

Recursive function banao jo:

```text
Input: 1234
Output: 4321
```

⚠️ Ismein thora sochna padega ke **last digit kaise nikalni hai** aur recursion ke baad usko kis position par rakhna hai.

---

### Q9 — Fibonacci

Recursive function banao:

```text
fib(0) = 0
fib(1) = 1
```

Aur:

```text
fib(n) = fib(n-1) + fib(n-2)
```

Find:

```text
fib(6)
```

---

### Q10 — Fibonacci Tree 🌳

`fib(5)` ka **complete recursion tree** draw karo.

Yaani:

```text
                fib(5)
               /      \
           fib(4)     fib(3)
             / \       / \
            ... ...   ... ...
```

**Har call likhni hai jab tak `fib(1)` ya `fib(0)` na aa jaye.**

Ye tree recursion samajhne ke liye **bohat important** hai.

---

### Q11 — Array ka sum

Given:

```cpp
int arr[] = {2, 4, 6, 8, 10};
```

Recursive function se array ka sum calculate karo.

Expected:

```text
30
```

---

### Q12 — Array maximum

Recursive function banao jo array ka **maximum element** return kare.

```text
arr = {4, 9, 2, 15, 7}

Output: 15
```

---

### Q13 — Linear Search

Recursion use karke array mein target search karo.

```text
arr = {10, 20, 30, 40, 50}
target = 40
```

Output:

```text
Found
```

---

### Q14 — String Reverse

Recursive function banao jo:

```text
Input: "HELLO"
Output: "OLLEH"
```

---

### Q15 — Palindrome 🔥

Recursive function banao jo check kare ke string palindrome hai ya nahi.

```text
MADAM → Palindrome
HELLO → Not Palindrome
```

---

## 😈 Aur ab asli teacher-type questions

Inko **compiler se pehle manually solve karna**. Yahan tumhari actual understanding test hogi.

### Q16

```cpp
void fun(int n)
{
    if(n <= 0)
        return;

    cout << n << " ";
    fun(n - 2);
    cout << n << " ";
}
```

Find output:

```cpp
fun(5);
```

---

### Q17

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    fun(n - 1);
    cout << n * n << " ";
}
```

Find output:

```cpp
fun(4);
```

---

### Q18 🔥

```cpp
void fun(int n)
{
    if(n <= 1)
        return;

    cout << n << " ";
    fun(n / 2);
    cout << n << " ";
}
```

Find output:

```cpp
fun(10);
```

---

### Q19 🌳

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    cout << n << " ";
    fun(n - 1);
    fun(n - 1);
}
```

Find the **exact output** for:

```cpp
fun(3);
```

Aur batao total **kitni recursive calls** execute hongi.

---

### Q20 ☠️

```cpp
void fun(int n)
{
    if(n <= 0)
        return;

    fun(n - 1);
    fun(n - 2);
    cout << n << " ";
}
```

Find output for:

```cpp
fun(4);
```

Aur iska **recursion tree** bhi banao.

---

**Strategy:** Q3–Q15 se programming patterns strong karo, phir Q16–Q20 ko **paper par manually trace** karo. Agar tum ye set genuinely samajh kar kar lete ho, phir hum **nested recursion + recursion with loops + tricky return statements + backtracking** par jayenge.

Ab hum 4 patterns karenge:

1. **Recursion + loop**
2. **Multiple recursive calls / tree recursion**
3. **Tricky return-value recursion**
4. **Nested recursion**

Yahan pr **sirf questions** dunga, solutions nahi. Tum khud solve karna.

# 😈 LEVEL 3 — Tricky Recursion

## Q21 — Recursion + Loop

Output find karo:

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    for(int i = 1; i <= n; i++)
        cout << i << " ";

    fun(n - 1);
}
```

For:

```cpp
fun(3);
```

---

## Q22 — Loop AFTER recursion

Output find karo:

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    fun(n - 1);

    for(int i = 1; i <= n; i++)
        cout << i << " ";
}
```

For:

```cpp
fun(3);
```

⚠️ Q21 aur Q22 ka difference **bohat important** hai.

---

## Q23 — Return value + recursion 🔥

What does this return?

```cpp
int fun(int n)
{
    if(n == 0)
        return 0;

    return fun(n - 1) + 2;
}
```

Find:

```cpp
fun(5);
```

---

## Q24 — Return value with multiplication

```cpp
int fun(int n)
{
    if(n == 1)
        return 1;

    return n * fun(n - 1);
}
```

Find:

```cpp
fun(5);
```

Aur manually complete call chain likho.

---

# 🌳 Q25 — Tree Recursion

```cpp
void fun(int n)
{
    if(n <= 0)
        return;

    cout << n << " ";

    fun(n - 1);
    fun(n - 2);
}
```

Find exact output for:

```cpp
fun(4);
```

**Important:** Iska recursion tree bhi draw karo.

---

# 🌳 Q26 — Tree + Return

```cpp
int fun(int n)
{
    if(n <= 1)
        return 1;

    return fun(n - 1) + fun(n - 2);
}
```

Find:

```cpp
fun(5);
```

⚠️ Notice carefully: ye Fibonacci jaisa **dikh raha hai**, lekin base case different hai.

---

# 🔥 Q27 — Same function, different position

Output:

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    cout << "A";

    fun(n - 1);

    cout << "B";

    fun(n - 1);

    cout << "C";
}
```

For:

```cpp
fun(2);
```

Isko **bilkul manually trace** karna.

---

# ☠️ Q28 — Teacher trap

```cpp
int fun(int n)
{
    if(n <= 0)
        return 0;

    return fun(n - 1) + fun(n - 1) + 1;
}
```

Find:

```cpp
fun(3);
```

Aur **total function calls** count karo.

---

# 🧠 Q29 — Negative base case

```cpp
void fun(int n)
{
    if(n < 0)
        return;

    cout << n << " ";

    fun(n - 2);
}
```

Find output:

```cpp
fun(5);
```

⚠️ Dekhna hai `0` ke baad kya hota hai.

---

# 💀 Q30 — Nested Recursion

Ye thora advanced hai:

```cpp
int fun(int n)
{
    if(n > 100)
        return n - 10;

    return fun(fun(n + 11));
}
```

Find:

```cpp
fun(95);
```

**Isko compiler se pehle paper par solve karna.** 😈

---

# 🚨 Q31 — Infinite recursion identify karo

In dono mein se kaunsa function properly terminate karega aur kaunsa infinite recursion mein jayega?

### A

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    fun(n - 1);
}
```

### B

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    fun(n + 1);
}
```

Reason bhi likhna.

---

# 🧩 Q32 — Base Case change

Compare:

### Function A

```cpp
void fun(int n)
{
    if(n == 0)
        return;

    cout << n << " ";
    fun(n - 1);
}
```

### Function B

```cpp
void fun(int n)
{
    if(n == 1)
        return;

    cout << n << " ";
    fun(n - 1);
}
```

`fun(5)` dono mein kya output aayega?

---

# 🔥 Q33 — Array + Recursion

```cpp
int sum(int arr[], int n)
{
    if(n == 0)
        return 0;

    return arr[n - 1] + sum(arr, n - 1);
}
```

Given:

```cpp
int arr[] = {10, 20, 30, 40};
```

Find:

```cpp
sum(arr, 4);
```

Aur call chain likho:

```text
sum(arr,4)
→ ?
→ ?
→ ?
→ ?
```

---

# 🔥 Q34 — Array Reverse Printing

Recursive function banao jo array ko **reverse order** mein print kare.

```text
Input:
1 2 3 4 5

Output:
5 4 3 2 1
```

**Loop use nahi karna.**

---

# 🏆 Q35 — Final Level-3 Challenge

Iska **output + total calls + recursion tree** find karo:

```cpp
void fun(int n)
{
    if(n <= 0)
        return;

    cout << n << " ";

    fun(n - 1);

    cout << n << " ";

    fun(n - 2);
}
```

For:

```cpp
fun(3);
```

---

### ⚠️ Ek rule

Ab Q21 onward **sirf compiler mein run karke answer mat nikalna**.

Pehle:

**Paper → predict → dry run → answer → compiler se verify**

# 🔥 RECURSION — FINAL CHAPTER

Is final chapter ke baad recursion ke liye tumhare paas ye complete mental model hona chahiye:

```text
Recursion
│
├── Base Case
├── Recursive Case
├── Smaller Problem
├── Call Stack
├── Unwinding
│
├── Linear Recursion
├── Tree Recursion
├── Multiple Parameters
├── Return-value Recursion
│
├── Index Recursion
├── Two-pointer Recursion
├── Divide & Conquer
├── Recursion Complexity
└── Backtracking
```

Chalo one-by-one. 👇

---

# PART 1 — Index-Based Recursion

Ab tak hum aksar `n` ko reduce kar rahe thay:

```cpp
fun(n - 1);
```

Lekin arrays aur strings mein ek aur natural technique hai:

```cpp
fun(arr, index);
```

Yahan `index` batata hai:

> "Abhi array ke kis element par kaam karna hai?"

Example:

```cpp
void printArray(int arr[], int index, int n)
{
    if(index == n)
        return;

    cout << arr[index] << " ";

    printArray(arr, index + 1, n);
}
```

Call:

```cpp
printArray(arr, 0, 5);
```

Agar:

```text
arr = 10 20 30 40 50
```

to calls:

```text
printArray(arr,0,5)
        ↓
printArray(arr,1,5)
        ↓
printArray(arr,2,5)
        ↓
printArray(arr,3,5)
        ↓
printArray(arr,4,5)
        ↓
printArray(arr,5,5) ← stop
```

### 🔑 Important

Yahan `n` decrease nahi ho raha.

**Index increase ho raha hai.**

```text
index = 0
index = 1
index = 2
index = 3
index = 4
index = 5 → base case
```

Ye pattern bohat important hai.

---

# PART 2 — Index Recursion ka Reverse

Ab agar:

```cpp
void printReverse(int arr[], int index, int n)
```

banana ho to tumhe decide karna hai:

> Recursive call se pehle print karna hai ya baad mein?

Agar pehle:

```text
10 20 30 40 50
```

Agar recursion ke baad:

```text
50 40 30 20 10
```

**Yahi woh concept hai jo tum pehle master kar chuke ho.**

---

# PART 3 — Two-Pointer Recursion

Ab aur interesting. 😈

Array:

```text
10 20 30 40 50
↑             ↑
left          right
```

Har recursive call mein:

```text
left++
right--
```

Example:

```cpp
fun(arr, left, right)
```

Conceptually:

```text
fun(arr,0,4)
      ↓
fun(arr,1,3)
      ↓
fun(arr,2,2)
      ↓
STOP
```

Base case:

```cpp
if(left >= right)
    return;
```

### Is pattern se kya solve ho sakta hai?

* Array reverse
* Palindrome array
* Palindrome string
* Two-ended processing

---

# PART 4 — Palindrome Recursion

Suppose:

```text
MADAM
```

Compare:

```text
M == M
 ↓
A == A
 ↓
D
```

Recursive structure:

```text
isPalindrome("MADAM", left, right)

M == M
    ↓
isPalindrome(..., 1, 3)

A == A
    ↓
isPalindrome(..., 2, 2)

left >= right
    ↓
true
```

### Core idea

Har level par:

> first aur last character compare karo.

Agar unequal:

```text
false
```

Agar equal:

```text
smaller problem solve karo
```

Ye **"smaller version of same problem"** ki perfect example hai.

---

# PART 5 — Divide & Conquer

Ab recursion ka bohat important use.

Suppose array:

```text
[10 20 30 40 50 60 70 80]
```

Instead of:

```text
poora array ek saath
```

hum divide karte hain:

```text
        whole
       /     \
    left     right
```

Phir recursively dono portions solve.

### Famous examples:

* Binary Search
* Merge Sort
* Quick Sort

---

# PART 6 — Recursive Binary Search

Suppose:

```text
[10 20 30 40 50 60 70]
```

Target:

```text
60
```

Middle:

```text
40
```

Target greater hai → right side.

```text
[50 60 70]
```

Middle:

```text
60
```

Found.

Recursive structure:

```cpp
binarySearch(arr, low, high)
```

Important variables:

```text
low
high
mid
```

Base case generally:

```cpp
if(low > high)
    return -1;
```

Then:

```text
target == arr[mid] → found
target < arr[mid]  → left half
target > arr[mid]  → right half
```

Yahan recursion **problem ko half** kar rahi hai.

That's why complexity:

```text
O(log n)
```

---

# PART 7 — Recursion Complexity

Ye interview ke liye **must know** hai.

### Case 1

```cpp
fun(n - 1);
```

One call each level:

```text
n
↓
n-1
↓
n-2
↓
...
```

Total roughly `n` calls.

### Time:

```text
O(n)
```

### Stack space:

```text
O(n)
```

---

## Case 2 — Two recursive calls

```cpp
fun(n - 1);
fun(n - 1);
```

Har call ke andar **2 aur calls**.

Tree banega:

```text
             n
          /     \
       n-1       n-1
      /  \       /  \
    n-2 n-2    n-2 n-2
```

Calls rapidly increase hoti hain.

Classic example:

```cpp
fib(n-1) + fib(n-2)
```

Naive Fibonacci ki time complexity:

```text
O(2^n)
```

roughly exponential.

---

# PART 8 — Recursion Depth

Ye bhi samjho.

```cpp
fun(5)
```

agar har function ek aur function call kare:

```text
fun(5)
fun(4)
fun(3)
fun(2)
fun(1)
fun(0)
```

Ek waqt par stack mein multiple frames hain.

Isko **recursion depth** keh sakte hain.

Agar recursion bohat deep chali jaye to:

```text
Stack Overflow
```

ho sakta hai.

---

# PART 9 — BACKTRACKING 🔥

Ab recursion ka final major concept.

Backtracking ko ek sentence mein yaad rakho:

> **Try → Explore → Undo**

Example: tumhare paas choices hain:

```text
A
B
C
```

Tum pehle:

```text
A choose
```

phir recursively explore:

```text
A → B
A → C
```

Phir:

```text
A undo
```

aur:

```text
B choose
```

### Mental picture:

```text
              Start
           /    |    \
          A     B     C
        /   \
      AB     AC
```

Ye **tree recursion + undo** ka combination hai.

---

# PART 10 — Subsets

Suppose:

```text
[1, 2]
```

Har element ke paas 2 choices:

```text
Take
Don't Take
```

Tree:

```text
             Start
            /     \
         Take     Don't
          1         1
         / \       / \
       2   no    2   no
```

Subsets:

```text
{}
{1}
{2}
{1,2}
```

### Ye pattern bohat important hai:

```cpp
solve(index)
```

Har index par:

```text
take
don't take
```

Phir recursively next index.

---

# PART 11 — Permutations

Suppose:

```text
ABC
```

Har position par different element choose karna.

Result:

```text
ABC
ACB
BAC
BCA
CAB
CBA
```

Yahan branching aur **used elements** ka concept aata hai.

Typical structure:

```text
choose
→ mark used
→ recurse
→ unmark
```

Last step:

> **Undo / Backtrack**

Isi wajah se naam **backtracking** hai.

---

# PART 12 — Recursion vs Backtracking

Ye distinction clear rakho:

### Recursion

Function khud ko call karta hai.

```text
solve smaller problem
```

### Backtracking

Recursion + choices + undo.

```text
choose
↓
recursive exploration
↓
undo
```

So:

> **Every backtracking solution uses recursion commonly, but every recursive solution is NOT backtracking.**

---

# 🧠 Ab tumhara Recursion Mental Framework

Kal ya interview mein koi bhi recursion question aaye, immediately ye checklist lagao:

### Step 1

**Problem ko smallest possible case tak kaise le ja sakta hoon?**

### Step 2

**Base case kya hoga?**

### Step 3

**Ek step ka kaam kya hai?**

### Step 4

**Remaining problem kya hai?**

### Step 5

**Recursive call remaining problem solve karegi.**

### Step 6

Dekho:

```text
answer recursive call se PEHLE chahiye?
```

ya

```text
answer recursive call ke BAAD chahiye?
```

### Step 7

Agar multiple choices hain:

```text
Tree?
```

### Step 8

Agar choices + undo hai:

```text
Backtracking?
```

### Step 9

Complexity:

```text
Kitni calls?
Kitni depth?
Har call mein kitna kaam?
```

---

# 🏆 FINAL RECURSION CHECK

Ab tum recursion ke **conceptual level par complete** ho:

```text
                 RECURSION
                     │
       ┌─────────────┴─────────────┐
       │                           │
    Linear                       Tree
       │                           │
   one call                 multiple calls
       │                           │
       └──────────┬────────────────┘
                  │
             Advanced
                  │
       ┌──────────┼──────────┐
       │          │          │
     Index     Divide      Backtrack
                & Conquer
```

### Ab sirf ek cheez baqi hai:

**Mastery through problems.**