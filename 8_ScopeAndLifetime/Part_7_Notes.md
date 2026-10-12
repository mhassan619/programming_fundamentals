# 1. Final revision — 5 concepts ek nazar mein

| Concept            | Meaning                                          | Example                                  |
| ------------------ | ------------------------------------------------ | ---------------------------------------- |
| Scope              | Variable kahan accessible hai?                   | Local `int x`                            |
| Lifetime           | Object kab tak exist karta hai?                  | Local vs `static`                        |
| Automatic          | Normal local object ki storage duration          | `int x = 5;`                             |
| Static             | Object ki storage duration program ke end tak    | `static int x = 5;`                      |
| Dangling reference | Reference ka referred object ab exist nahi karta | Local variable ka reference return karna |

Yaad rakho: scope, lifetime aur storage duration related hain, magar interchangeable terms nahi hain.

# 2. Mixed dry-run questions

## Q1 — Local vs static

```
#include <iostream>
using namespace std;

void fun()
{
    int a = 0;
    static int b = 0;

    a++;
    b++;

    cout << a << " " << b << endl;
}

int main()
{
    fun();
    fun();
    fun();
}
```

Pehle khud output predict karo.

`1 1`, `1 1`, `1 1`

`1 1`, `1 2`, `1 3`

`1 1`, `2 2`, `3 3`

`0 1`, `0 2`, `0 3`

Check answer

## Q2 — Scope aur shadowing

```
int x = 100;

int main()
{
    int x = 20;

    {
        int x = 5;
        cout << x << endl;
    }

    cout << x << endl;
    cout << ::x << endl;
}
```

Teen outputs likho aur explain karo ke har jagah kaunsa `x` access ho raha hai.

## Q3 — Global variable initialization

```
int score;

int main()
{
    cout << score;
}
```

- `score` ki initial value kya hogi?
- Agar isi tarah `int score;` kisi function ke andar declare hota, to kya guarantee hoti?

## Q4 — Undefined behavior

```
int main()
{
    int x;
    x = x + 1;
    cout << x;
}
```

Bug identify karo. Sirf ye kehna ke “random output aayega” sufficient nahi — explain karo ke problem `x + 1` calculate karte waqt kyun hai.

## Q5 — Dangling reference

```
int& getNumber()
{
    int n = 50;
    return n;
}
```

- Problem kya hai?
- Safest simple fix kya hai?
- Kya local `static int n = 50;` karne se lifetime wala issue solve ho sakta hai?

# 3. Debugging challenge 🔥

Is program ko correct karo:

```
#include <iostream>
using namespace std;

int& getScore()
{
    int score = 10;
    return score;
}

int main()
{
    int &result = getScore();
    cout << result;
}
```

Tumhein decide karna hai:

1. Kya function ko reference return karna chahiye?
2. Kya value return karna better hoga?
3. Agar reference return karna hi ho, to referred object ki lifetime kaise ensure karoge?

Hint: Har problem ka best solution same nahi hota. Design aur required behavior par depend karta hai.

# 4. Final mastery test

## Chapter 8 final MCQ

0/5

1\. Scope kis cheez ko define karta hai?

Object kitni der exist karta hai

Variable ka naam kahan accessible hai

Variable ki value kitni hai

2\. Function ke andar \`static int x = 0;\` ki value agle call mein kya hoti hai?

Har baar 0 ho jati hai

Pichli call ki updated value preserve hoti hai

Har call par undefined hoti hai

3\. Global \`int x;\` aam tor par kis value se zero-initialize hota hai?

0

1

Koi guarantee nahi

4\. Local automatic variable ka reference function se return karna unsafe kyun ho sakta hai?

Reference sirf integers ke liye hota hai

Local object ki lifetime function end par khatam ho sakti hai

C++ references return karna allow nahi karta

5\. \`auto x = 3.5;\` mein \`auto\` ka role kya hai?

Static lifetime dena

Type deduce karna

Global scope dena

Check final score

## 🏁 Chapter 8 complete!

Is chapter mein humne cover kiya:

- Scope: local, block, global aur shadowing
- Lifetime aur storage duration
- Normal local vs static local variables
- Global `static` aur `extern` ka introduction
- Initialization, uninitialized variables aur undefined behavior
- Object lifetime aur dangling references
- Final dry runs aur debugging