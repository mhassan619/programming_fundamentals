# Chapter 8 — Part 6: Object Lifetime, Dangling References & Memory Safety

Ye topic important hai kyunki functions aur references mein ek common bug hota hai: aisi memory ko access karna jiska object ab exist hi nahi karta.

## 1. Reference kya hota hai?

Pehle basic example:

```
int x = 10;
int &ref = x;

ref = 50;

cout << x;
```

Output:

```
50
```

`ref` koi independent integer copy nahi. Ye `x` ka reference hai. Isliye `ref` ko modify karne se `x` modify hota hai.

## 2. Dangling reference kya hota hai?

Ab ye code dekho:

```
int& getValue()
{
    int x = 10;
    return x;  // Dangerous!
}
```

Function ke andar `x` ek local automatic variable hai.

Jab function end hota hai, `x` ki lifetime end ho jati hai. Lekin function usi `x` ka reference return karne ki koshish kar raha hai.

Caller ke paas phir aisa reference aa sakta hai jo ab valid object ko refer nahi karta. Isay dangling reference kehte hain.

Aisa code use mat karna.

### Correct approach 1: Value return karo

```
int getValue()
{
    int x = 10;
    return x;
}

int main()
{
    int result = getValue();
    cout << result;
}
```

Output:

```
10
```

Yahan function `x` ki value return karta hai, reference nahi. Caller ko result mil jata hai aur local `x` ki lifetime independently end ho sakti hai.

Golden rule: Agar local variable ki value chahiye, aam tor par value return karo.

## 3. Kya har reference return karna dangerous hai?

Nahi bhai! Agar referred object abhi bhi alive hai, to reference return karna valid ho sakta hai.

```
int& getValue(int &x)
{
    return x;
}

int main()
{
    int a = 10;

    getValue(a) = 50;

    cout << a;
}
```

Output:

```
50
```

Kyun safe hai?

- `a` `main()` mein exist karta hai.
- `getValue()` ko `a` ka reference milta hai.
- Function usi valid object ka reference return karta hai.
- `a` ki lifetime abhi end nahi hui.

Yahan reference return karna useful hai, kyunki caller original variable ko modify kar sakta hai.

## 4. Local `static` variable ka reference

Ye bhi valid example hai:

```
int& getValue()
{
    static int x = 10;
    return x;
}

int main()
{
    int &ref = getValue();

    ref = 99;

    cout << getValue();
}
```

Output:

```
99
```

Local `static` variable ki lifetime program ke end tak hoti hai. Isliye function ke return hone par `x` destroy nahi hota.

Lekin yaad rakho: reference return karna tabhi safe hai jab referred object ki lifetime us reference ke use tak valid rahe.

## 5. Scope aur lifetime ka final connection

| Variable                              | Scope             | Lifetime                       |
| ------------------------------------- | ----------------- | ------------------------------ |
| `int x = 5;` inside a function        | Local block       | Automatic                      |
| `static int x = 5;` inside a function | Local block       | Program ke end tak             |
| `int x = 5;` at global scope          | Global/file scope | Program ke execution ke dauran |

Scope batata hai naam kahan visible hai. Lifetime batati hai object kab tak exist karta hai.

Dono alag concepts hain.

## 6. Quick practice — output ya bug identify karo

Question: Is code mein problem kya hai?

```
int& test()
{
    int n = 25;
    return n;
}
```

Koi problem nahi, reference value ki copy return karta hai

`n` ki lifetime function end par khatam hoti hai, isliye returned reference dangling ho sakta hai

Har function reference return nahi kar sakta

Sirf `return n;` ko `return &n;` karna chahiye

Check answer