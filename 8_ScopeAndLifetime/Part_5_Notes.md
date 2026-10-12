Chalo bhai! 🔥 Aaj PF Chapter 8 — Part 5: Initialization, Uninitialized Variables & Undefined Behavior start karte hain.

Pehle chapters mein humne variables, data types, functions, scope aur lifetime cover ki thi. Aaj samjhenge ke variable ko initialize karna kyun zaroori hai, uninitialized variable se bugs kaise aate hain, aur C++ mein undefined behavior (UB) kya hota hai.

# 1. Declaration vs Initialization vs Assignment

Sabse pehle ye 3 concepts clear kar lo.

```
int x;       // Declaration
int y = 10;  // Declaration + initialization
x = 20;      // Assignment
```

Inka difference:

- Declaration: Compiler ko batana ke variable exist karta hai aur uska type kya hai.
- Initialization: Variable ko shuru mein value dena.
- Assignment: Pehle se existing variable ko value dena ya update karna.

Example:

```
int age = 18;  // Initialization
age = 20;      // Assignment
age = 25;      // Assignment
```

Dry run:

`int age = 18;`

18

`age = 20;`

20

`age = 25;`

25

Har assignment par variable ki current value update hoti hai.

# 2. Uninitialized variable kya hota hai?

Ye code dekho:

```
#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << x;
}
```

Bhai, `x` declare hua hai, lekin initialize nahi hua.

Agar ye ordinary local `int` hai, to isko value assign kiye baghair read karna undefined behavior hai.

Iska matlab ye nahi ke output hamesha `0` hoga, ya hamesha koi random number hoga. C++ language is operation ke behavior ki guarantee nahi deti.

Correct approach:

```
int x = 0;
cout << x;
```

Output:

```
0
```

Ya agar input lena hai:

```
int x;
cin >> x;
```

Lekin yaad rakho: input operation successful bhi hona chahiye. Agar input fail ho jaye, to variable ko use karne se pehle failure handle karo.

# 3. Kya har uninitialized variable dangerous hota hai?

Nahi! C++ mein initialization ka behavior variable ki category par depend karta hai.

Compare karo:

### A. Ordinary local variable

```
void fun()
{
    int x;
}
```

Agar `x` ko initialize nahi kiya, to uski initial value automatically `0` assume nahi kar sakte.

### B. Global variable

```
int x;

int main()
{
    cout << x;
}
```

Output:

```
0
```

Global variable ko static initialization ke rules ke mutabiq zero-initialize kiya jata hai.

### C. Local static variable

```
void fun()
{
    static int x;
    cout << x;
}
```

Output:

```
0
```

Local `static` variable bhi zero-initialize hota hai, agar explicit initializer nahi diya.

### Comparison table

| Variable              | Initialization ke baghair initial value   |
| --------------------- | ----------------------------------------- |
| Local `int x;`        | Indeterminate; read karna UB ho sakta hai |
| Global `int x;`       | `0`                                       |
| Local `static int x;` | `0`                                       |
| `int x = 5;`          | `5`                                       |

Golden rule: Har variable ko automatically zero milta hai — ye assumption galat hai.

# 4. Undefined Behavior (UB) kya hai?

Ye C++ ka bohot important concept hai.

Undefined behavior ka matlab hai ke language standard us operation ke result par requirements impose nahi karta.

Example:

```
int x;
cout << x;
```

Ordinary local `x` ko initialize kiye baghair read karna UB hai.

Ek aur example:

```
int arr[3] = {10, 20, 30};
cout << arr[5];
```

Array ke valid indices `0`, `1`, `2` hain. `arr[5]` access karna out-of-bounds hai aur UB ka sabab ban sakta hai.

Aur:

```
int x = 10;
int y = 0;

cout << x / y;
```

Integer division by zero bhi undefined behavior hai.

Important: UB ka matlab sirf program crash hona nahi. Program apparently correct output de sakta hai, galat output de sakta hai, ya kisi aur tarah behave kar sakta hai. Isliye UB wale code ke output par depend nahi karna chahiye.

# 5. Initialization ke different tareeqe

C++ mein variable initialize karne ke multiple styles hain.

```
int a = 10;  // Copy initialization
int b(10);   // Direct initialization
int c{10};   // Brace initialization
```

Teeno examples mein value `10` hai.

Modern C++ mein braces ka ek benefit ye hai ke narrowing conversions ko reject kar sakte hain.

```
int x{3.5};  // Error: narrowing conversion
```

Iske muqable mein:

```
int x = 3.5;
```

valid C++ hai, lekin fractional part discard hota hai aur `x` ki value `3` hoti hai.

Interview point: Brace initialization unwanted narrowing conversions ko catch karne mein help karti hai.

# 6. `const` variable ko initialize karna zaroori hai

```
const int MAX = 100;
```

`MAX` initialize ho gaya aur ab iski value change nahi kar sakte:

```
MAX = 200;  // Error!
```

Lekin:

```
const int MAX;  // Error
```

Ye invalid hai kyunki ordinary `const int` ko declaration ke waqt initialize karna hota hai.

# 7. Uninitialized variable ki wajah se logical bug

Ye code dekho:

```
int sum;

for(int i = 1; i <= 5; i++)
{
    sum += i;
}
```

Programmer shayad expect kar raha hai:

\\[ 1+2+3+4+5=15 \\]

Lekin `sum` ko initial value nahi di gayi. `sum += i` mein pehle purani value read hoti hai, jo yahan safe nahi.

Correct code:

```
int sum = 0;

for(int i = 1; i <= 5; i++)
{
    sum += i;
}

cout << sum;
```

Output:

```
15
```

Accumulator patterns mein initialization bohot important hai:

- Sum: `0`
- Count: `0`
- Product: `1`
- Maximum/minimum: aksar array ke first element se initialize karna behtar hai, agar array non-empty ho.

# 8. Interview trap: `int arr[5];`

```
int arr[5];
```

Ye local array declare karta hai, lekin elements ko explicit initial values nahi di gayin.

```
int arr[5] = {};
```

Is version mein tamam elements zero-initialize hote hain.

Agar known initial values chahiye:

```
int arr[5] = {1, 2, 3, 4, 5};
```

Array processing mein hamesha ensure karo ke jis element ko read kar rahe ho, woh properly initialized ho aur index valid ho.

# 🧠 Part 5 — Practice time


## Coding challenge 🔥

Is code ko fix karo aur explain karo ke bug kyun aa raha tha:

```
int calculateSum()
{
    int sum;

    for(int i = 1; i <= 10; i++)
    {
        sum += i;
    }

    return sum;
}
```

Tumhara task:

1. Bug identify karo.
2. Correct code likho.
3. `calculateSum()` ka expected result batao.
4. Explain karo ke `sum = 0` kyun use kiya.