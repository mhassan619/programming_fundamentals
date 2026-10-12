Aaj ek aisa concept seekhenge jo initially thora confusing lagta hai: `static` local variable.

## 1. Normal local variable ka behaviour

```
#include <iostream>
using namespace std;

void counter()
{
    int x = 0;
    x++;
    cout << x << endl;
}

int main()
{
    counter();
    counter();
    counter();
}
```

Output:

```
1
1
1
```

Bhai, har call par `x = 0` dobara execute hota hai.

Dry run:

First call

&#x20;x = 0 → 1&#x20;

Second call

&#x20;x = 0 → 1&#x20;

Third call

&#x20;x = 0 → 1&#x20;

Har call mein naya local `x` banta hai. Function complete hone par uski lifetime end ho jati hai.

## 2. Ab `static` use karte hain

Sirf ek keyword change karo:

```
#include <iostream>
using namespace std;

void counter()
{
    static int x = 0;
    x++;
    cout << x << endl;
}

int main()
{
    counter();
    counter();
    counter();
}
```

Output:

```
1
2
3
```

Ye magic nahi hai. `static` local variable apni value function calls ke darmiyan preserve karta hai.

### Normal vs static local variable

| Property         | Normal `int x`                     | `static int x`     |
| ---------------- | ---------------------------------- | ------------------ |
| Scope            | Local block                        | Local block        |
| Lifetime         | Block/function execution se linked | Program ke end tak |
| Value preserved? | No                                 | Yes                |

Notice karo: static variable ka scope local hi rehta hai, lekin lifetime program ke end tak hoti hai.

## 3. Har call par initialization nahi hoti

```
void fun()
{
    static int x = 5;

    x += 2;
    cout << x << endl;
}
```

Agar `fun()` teen baar call ho, dry run:

| Call | Initial value for that call | `x += 2` ke baad |
| ---- | --------------------------- | ---------------- |
| 1    | 5                           | 7                |
| 2    | 7                           | 9                |
| 3    | 9                           | 11               |

Output:

```
7
9
11
```

`static int x = 5;` ki initialization pehli execution par hoti hai. Agli calls par `x` dobara `5` nahi banta.

## 4. Scope ab bhi local hai!

```
void fun()
{
    static int count = 0;
    count++;
}

int main()
{
    fun();

    // cout << count;  // Error!
}
```

Bhale hi `count` program ke end tak exist kare, `main()` usko directly access nahi kar sakta.

Kyun?

- Lifetime long hai.
- Scope ab bhi `fun()` ke block tak limited hai.

Long lifetime ka matlab global accessibility nahi hota.

## 5. Interactive dry run

Bhai, neeche code ka output predict karo.

```
void test()
{
    static int a = 1;
    int b = 1;

    a++;
    b++;

    cout << a << " " << b << endl;
}

int main()
{
    test();
    test();
    test();
}
```

Output kya hoga?

`2 2`, `2 2`, `2 2`

`2 2`, `3 2`, `4 2`

`2 2`, `3 3`, `4 4`

`2 1`, `3 1`, `4 1`

Check answer

## 6. Static local variables kahan useful hain?

- Function calls ki count maintain karna.
- Previous call ka state preserve karna.
- Kuch simple counters ya one-time initialization patterns.

Lekin har jagah `static` use karna zaroori nahi. Agar state explicitly manage karna behtar ho, to parameter ya class member zyada suitable ho sakta hai.

## Part 2 — Quick recap

- Normal local variable har function call mein dobara initialize hota hai.
- Static local variable initialize sirf pehli execution par hota hai aur value preserve karta hai.
- Static local variable ka scope local aur lifetime program ke end tak hoti hai.
- Global variable ka scope aur lifetime alag concepts hain; dono ko confuse nahi karna.