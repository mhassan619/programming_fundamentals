# Chapter 8 — Scope & Lifetime

## Part 3: Global Scope & Global `static`

### 1. Global variable kya hota hai?

Jab variable kisi function ya block ke bahar declare hota hai, use global scope wala variable kaha jata hai.

```
#include <iostream>
using namespace std;

int score = 100;  // Global variable

void showScore()
{
    cout << score << endl;
}

int main()
{
    showScore();
    cout << score << endl;
}
```

Output:

```
100
100
```

Dry run:

1. `score` global scope mein declare hua, initial value `100` hai.
2. `main()` se `showScore()` call hota hai.
3. `showScore()` global `score` access karta hai aur `100` print karta hai.
4. Function return hota hai.
5. `main()` dobara wahi global `score` access karta hai.

Global variable ki lifetime program ke execution ke dauran hoti hai, aur is example mein woh dono functions mein accessible hai.

### 2. Global variable modify karna

```
#include <iostream>
using namespace std;

int score = 10;

void increaseScore()
{
    score += 5;
}

int main()
{
    cout << score << endl;

    increaseScore();

    cout << score << endl;
}
```

Output:

```
10
15
```

Kyun?

`increaseScore()` ne global variable ki copy modify nahi ki. Usne actual global `score` ko update kiya.

```
Global score = 10
       ↓
increaseScore()
       ↓
Global score = 15
       ↓
main() prints 15
```

Important: Global variable ko modify karne ke liye reference parameter ki zaroorat nahi hoti, kyunki function directly us global variable ko access kar raha hai.

### 3. Local aur global variable ka same naam

Ye concept interviews mein bhi poocha ja sakta hai.

```
#include <iostream>
using namespace std;

int x = 100;

int main()
{
    int x = 20;

    cout << x << endl;
    cout << ::x << endl;
}
```

Output:

```
20
100
```

Samjho:

- `x` → local variable, value `20`.
- `::x` → global-scope variable, value `100`.

`::` ko scope resolution operator kehte hain.

Jab local variable global variable ko same naam se hide karta hai, isay shadowing kehte hain.

Golden rule

```
cout << x;    // Nearest visible x
cout << ::x;  // Global-scope x
```

### 4. Global `static` variable kya hota hai?

Ab naya concept.

```
static int count = 10;
```

Agar ye declaration function ke bahar ho, to `static` ka matlab local `static` se different hota hai.

Global scope par `static` variable ki internal linkage hoti hai. Simple alfaaz mein, us variable ko usi source file ke andar naam ke through refer kiya ja sakta hai; doosri source file us variable ko normal external declaration se access nahi kar sakti.

Example, `main.cpp`:

```
static int count = 10;

int main()
{
    count++;
}
```

Yahan:

- `count` global scope mein hai.
- Iski lifetime program ke execution ke dauran hoti hai.
- Iska naam doosri source file se normal external linkage ke zariye accessible nahi hota.

Bohat important distinction:

| Declaration                       | Scope                               | Lifetime                 |
| --------------------------------- | ----------------------------------- | ------------------------ |
| `int x;` inside a function        | Local/block scope                   | Automatic local lifetime |
| `static int x;` inside a function | Local/block scope                   | Static storage duration  |
| `int x;` at file scope            | Global/file scope                   | Static storage duration  |
| `static int x;` at file scope     | Global/file scope, internal linkage | Static storage duration  |

Yahan ek naya term bhi hai: linkage — iska talluq is baat se hai ke ek source file ka naam doosri source file se refer kiya ja sakta hai ya nahi.

### 5. Kya global variables hamesha accessible hote hain?

Nahi bhai. Ye code dekho:

```
#include <iostream>
using namespace std;

void first()
{
    int marks = 90;
}

void second()
{
    cout << marks;  // Error!
}

int main()
{
    first();
    second();
}
```

`marks` local variable hai. Woh `first()` ke bahar accessible nahi, isliye `second()` use nahi kar sakta.

Global variable hota to situation different hoti:

```
#include <iostream>
using namespace std;

int marks = 90;

void first()
{
    cout << marks << endl;
}

void second()
{
    cout << marks << endl;
}

int main()
{
    first();
    second();
}
```

Output:

```
90
90
```

Lekin real projects mein har function ko global state access dena maintainability aur debugging ko difficult bana sakta hai. Isliye parameters aur return values ko preference dena aksar behtar design hota hai.

## 6. Common mistakes — interview traps

Mistake 1: Scope aur lifetime ko same samajhna.

Variable ki lifetime long ho sakti hai, lekin uska scope local reh sakta hai — jaise function ke andar `static` variable.

Mistake 2: Global aur local `static` ko same samajhna.

- Local `static`: calls ke darmiyan value preserve karta hai.
- File-scope `static`: naam ki linkage ko us source file tak limit karta hai.

Mistake 3: Har variable ko global bana dena.

Isse functions ek doosre ki state par depend kar sakte hain. Chhote examples mein easy lagta hai, lekin bade programs mein bugs trace karna mushkil ho sakta hai.

# 🎯 Part 3 — Practice Time

Bhai, ab khud dry run karo. Answers abhi mat dekho — pehle apni understanding test karo.

### Q1 — Output predict karo

```
int x = 5;

void fun()
{
    x += 2;
}

int main()
{
    fun();
    fun();
    cout << x;
}
```

Output kya hoga aur kyun?

### Q2 — Shadowing

```
int x = 50;

int main()
{
    int x = 10;

    {
        int x = 2;
        cout << x << endl;
    }

    cout << x << endl;
    cout << ::x << endl;
}
```

Teen outputs batao.

### Q3 — Conceptual

Function ke andar `static int count = 0;` aur function ke bahar `static int count = 0;` mein kya difference hai?

### Q4 — Debugging

```
void fun()
{
    int x = 10;
}

int main()
{
    fun();
    cout << x;
}
```

Is code mein error kyun hai? Isay fix karne ke do possible tareeqe batao.

### Q5 — Interview question 🔥

Agar do functions ko ek variable ki current value read bhi karni ho aur modify bhi, to global variable use karna zaroori hai? Ya parameters/references se bhi kaam ho sakta hai? Ek chhota example do.