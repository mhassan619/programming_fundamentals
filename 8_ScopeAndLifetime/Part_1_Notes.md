# Chapter 8 — Scope & Lifetime

## Part 1: Scope vs Lifetime

Sabse pehle ek important distinction samjho:

- Scope: Variable ko code mein kahan access kar sakte ho?
- Lifetime: Variable memory mein kab se kab tak exist karta hai?

Yaad rakhne ka simple tareeqa:

Scope = Visibility

Variable ko code ke kis area se use kar sakte ho?

Lifetime = Existence

Variable kab create hota hai aur kab uski lifetime end hoti hai?

## 1. Scope ko dry run se samjho

```
#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    if (a > 5)
    {
        int b = 20;
        cout << a << " " << b << endl;
    }

    cout << a << endl;
    // cout << b;  // Error!
}
```

Output:

```
10 20
10
```

Aisa kyun?

- `a` ko `main()` ke andar declare kiya, isliye `main()` ke andar aur uske nested blocks mein accessible hai.
- `b` ko `if` block ke andar declare kiya, isliye uska scope usi block tak hai.
- `if` block ke bahar `b` accessible nahi hai.

Scope ka golden rule

Variable jis block `{ }` mein declare hota hai, us block ke andar accessible hota hai, including uske nested blocks — subject to normal C++ name-lookup rules.

## 2. Lifetime ko samjho

Ab dekho:

```
#include <iostream>
using namespace std;

int main()
{
    cout << "Start" << endl;

    {
        int x = 50;
        cout << x << endl;
    } // x ki lifetime yahan end

    cout << "End" << endl;
}
```

Output:

```
Start
50
End
```

Jab execution inner block mein enter karta hai, `x` create hota hai. Block se bahar nikalne par `x` ki lifetime end ho jati hai.

Yahan scope aur lifetime dono same block se linked hain, lekin yaad rakho: scope visibility ka concept hai, jabke lifetime object ke existence ka concept hai.

## 3. Local variable: har function ki apni copy

```
void first()
{
    int x = 10;
}

void second()
{
    int x = 20;
}
```

Dono variables ka naam `x` hai, lekin dono alag local variables hain.

```
first()  → x = 10
second() → x = 20
```

Ek function ka local `x`, doosre function ke local `x` ko automatically change nahi karta.

## 4. Global variable

Global variable kisi function ke bahar declare hota hai:

```
#include <iostream>
using namespace std;

int score = 100;

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

Global variable `score` ko in functions mein access kiya ja sakta hai, kyunki uska scope uski declaration aur C++ name-lookup rules ke mutabiq in jagahon ko cover karta hai.

Lekin global variables har jagah use karna best practice nahi. Unnecessary shared state bugs aur debugging ko difficult bana sakti hai.

## 5. Ek hi naam: local vs global

Ye interview-style example hai:

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

Kyun?

- `x` → nearest visible local variable, value `20`.
- `::x` → global-scope `x`, value `100`.

`::` ko yahan scope resolution operator kehte hain.

## 6. Ab tumhari practice 💪

Code ko khud dry run karo, phir answers check karne ke liye bhej dena.

### Q1 — Scope

```
int main()
{
    int a = 5;

    {
        int b = 10;
        cout << a + b << endl;
    }

    cout << a << endl;
}
```

Output kya hoga?

### Q2 — Error identify karo

```
int main()
{
    if (true)
    {
        int marks = 90;
    }

    cout << marks;
}
```

Compile error kyun aayega?

### Q3 — Local vs global

```
int x = 50;

void fun()
{
    int x = 10;
    cout << x << endl;
}

int main()
{
    fun();
    cout << x << endl;
}
```

Output kya hoga?

### Q4 — Conceptual challenge

Scope aur lifetime mein kya difference hai? Apne words mein explain karo aur ek example do jahan variable ka scope khatam ho jata hai.