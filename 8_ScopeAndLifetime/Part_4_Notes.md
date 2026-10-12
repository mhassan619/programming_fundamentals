# 1. Sabse pehle: Scope, Lifetime aur Storage Duration

Bhai, ye teen terms related hain, lekin same nahi hain.

Scope — Visibility

Variable ka naam code ke kis area mein use ho sakta hai?

Lifetime — Existence

Object kab create hota hai aur kab destroy hota hai?

Storage duration — Storage period

Object ke liye storage kis duration tak available rehti hai?

C++ mein common storage durations hain:

- Automatic: aam local variables ki tarah.
- Static: global variables aur local `static` variables ki tarah.
- Dynamic: jab memory dynamically allocate ki jaye, jaise `new` se.
- Thread: thread-storage wale objects; isko hum baad mein zaroorat par cover karenge.

Abhi pehle teen par focus karte hain.

# 2. Automatic storage duration

Example:

```
#include <iostream>
using namespace std;

void fun()
{
    int x = 10;
    x++;
    cout << x << endl;
}

int main()
{
    fun();
    fun();
}
```

Output:

```
11
11
```

Dry run:

### First call

`x = 10` → `x++` → `x = 11` → print `11` → function ends.

### Second call

Naya local `x = 10` → `x++` → `x = 11` → print `11`.

Yahan `x` automatic local variable hai. Function ki har call mein naya local object banta hai, aur uski lifetime function ke execution se linked hoti hai.

Important: Automatic ka matlab ye nahi ke variable hamesha stack par hi store hona chahiye. Compiler implementation optimize kar sakta hai; language ka rule uski storage duration ke baare mein hai.

# 3. Static storage duration

Ab sirf ek keyword change karo:

```
#include <iostream>
using namespace std;

void fun()
{
    static int x = 10;
    x++;
    cout << x << endl;
}

int main()
{
    fun();
    fun();
}
```

Output:

```
11
12
```

Kyun?

- `x` ki initialization pehli baar hoti hai.
- Function ke khatam hone par `x` destroy nahi hota.
- Agli call mein uski preserved value `11` hoti hai.
- Increment karne par `12` print hota hai.

Yahan scope local hai, lekin storage duration static hai.

## Automatic vs static

| Feature                           | `int x = 10;` local | `static int x = 10;` local |
| --------------------------------- | ------------------- | -------------------------- |
| Scope                             | Local               | Local                      |
| Initialization                    | Har call par        | Pehli execution par        |
| Value calls ke darmiyan preserve? | Nahi                | Haan                       |
| Storage duration                  | Automatic           | Static                     |

# 4. `auto` keyword — C++ ka important twist

Bhai, `auto` ke do historical uses ko mix nahi karna.

Modern C++ mein:

```
auto age = 20;
auto price = 9.5;
auto letter = 'A';
```

Compiler initializer se type deduce karta hai:

- `age` → `int`
- `price` → `double`
- `letter` → `char`

Yahan `auto` ka matlab automatic storage duration nahi hai. Ye compiler ko variable ka type infer karne deta hai.

Example:

```
int main()
{
    auto x = 10;
    x = 20;

    cout << x;
}
```

Output:

```
20
```

Type `int` deduce hua aur phir `x` ki value change hui.

Golden rule: `auto` type deduction karta hai; local variable ki storage duration aam tor par uski declaration aur context se determine hoti hai.

# 5. `extern` — variable doosri jagah declare ho sakta hai

Ab maan lo tumhare program mein global variable ki definition ek source file mein hai aur tum doosri source file se use karna chahte ho.

`main.cpp`:

```
int score = 100;  // Definition

int main()
{
    return 0;
}
```

`helper.cpp`:

```
extern int score; // Declaration, definition nahi

void increaseScore()
{
    score++;
}
```

Yahan `extern int score;` compiler ko batata hai ke `score` naam ka external variable kahin aur defined hai.

Agar dono source files ko ek program ke taur par compile aur link kiya jaye, to `helper.cpp` usi global `score` ko access kar sakta hai.

Yaad rakho:

- Declaration: batata hai ke naam aur type kya hai.
- Definition: actual variable ko define karta hai aur storage provide karta hai.
- `extern int score;` jaisi declaration, initializer ke baghair, aam tor par sirf declaration hoti hai.

Agar variable ki definition hi na mile, to linker error aa sakta hai.

## `extern` vs `static` at file scope

| Keyword                           | Simple meaning                                     |
| --------------------------------- | -------------------------------------------------- |
| `extern int x;`                   | External variable ki declaration                   |
| `int x = 5;` at file scope        | External linkage wala global variable definition   |
| `static int x = 5;` at file scope | Internal linkage; naam isi source file tak limited |

Ye distinction multi-file C++ projects mein useful hai.

# 6. Ek combined example — predict the output

Ab teeno concepts ko ek saath dekhte hain:

```
#include <iostream>
using namespace std;

int total = 100;

void fun()
{
    int a = 1;
    static int b = 1;

    a++;
    b++;
    total++;

    cout << a << " " << b << " " << total << endl;
}

int main()
{
    fun();
    fun();
}
```

Khud dry run karo:

- `a` har call par dobara initialize hota hai.
- `b` calls ke darmiyan value preserve karta hai.
- `total` global variable hai, isliye uski updated value agle call mein bhi available hai.

## Quick check

Output ki kaunsi sequence correct hai?

`2 2 101` phir `2 3 102`

`2 2 101` phir `2 2 101`

`2 2 101` phir `3 3 102`

`2 1 101` phir `2 2 102`

Check answer

# 7. Part 4 — Practice questions

Ab ye questions khud solve karo, jaise hum pehle chapters mein karte aaye hain.

Q1 — Automatic variable

Output predict karo:

```
void test()
{
    int x = 5;
    x += 3;
    cout << x << endl;
}
```

Agar `test()` 3 baar call ho, output kya hoga?

Q2 — Static variable

```
void test()
{
    static int x = 5;
    x += 3;
    cout << x << endl;
}
```

Agar `test()` 3 baar call ho, output kya hoga?

Q3 — Conceptual

Kya `auto x = 10;` ka matlab hai ke `x` ki storage duration static hai? Explain karo.

Q4 — Debugging

Do source files mein ek global variable share karna hai. Tum `extern` kyun use karoge? Kya har file mein `int score = 100;` likhna correct hoga?

Q5 — Interview-style

Scope, lifetime aur storage duration mein difference apne words mein samjhao. Apni explanation mein ek normal local variable aur ek local `static` variable ka example zaroor include karna.

## Aaj ka recap

- Automatic local variables aam tor par function/block ke execution se linked lifetime rakhte hain.
- Local `static` variable apni value calls ke darmiyan preserve karta hai.
- Modern C++ mein `auto` type deduction ke liye hai.
- `extern` doosri jagah defined external variable ko declare karne mein use hota hai.
- File-scope `static` internal linkage deta hai; local `static` ki scope local hi rehti hai.