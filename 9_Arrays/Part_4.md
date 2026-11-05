Is part mein 4 major concepts cover karenge:

1. Array memory mein kaise store hota hai?
2. Contiguous memory kya hoti hai?
3. Index se address calculate kaise hota hai?
4. Common array bugs aur unki debugging.

# 1. Array memory mein kaise store hota hai?

Suppose:

```
int arr[5] = {10, 20, 30, 40, 50};
```

C++ memory mein array ke elements ko contiguous memory locations mein store karta hai.

Contiguous ka matlab: elements ki memory locations ek doosre ke bilkul baad hoti hain.

Example ke liye assume karte hain ke `int` ka size 4 bytes hai aur array ka starting address `1000` hai.

Array memory representation

## 10

Index 0

1000

## 20

Index 1

1004

## 30

Index 2

1008

## 40

Index 3

1012

## 50

Index 4

1016

Illustrative addresses — actual addresses program execution mein different ho sakte hain.

Notice karo:

- `arr[0]` address 1000 par hai.
- `arr[1]` address 1004 par hai.
- `arr[2]` address 1008 par hai.
- `arr[3]` address 1012 par hai.

Har next integer 4 bytes aage hai.

Important: C++ standard har system par `int` ka size 4 bytes guarantee nahi karta. Humne yahan example ke liye 4 bytes assume kiye hain.

# 2. Contiguous Memory ka advantage kya hai?

Suppose array mein 100 elements hain.

Agar humhein `arr[70]` access karna hai, to computer ko pehle 69 elements traverse karne ki zaroorat nahi.

Woh directly address calculate kar sakta hai.

Isi wajah se array ka index-based access:

\\[ O(1) \\]

hota hai.

Ye array ki sab se important properties mein se ek hai.

Compare karo:

| Operation       | Array      |
| --------------- | ---------- |
| Access by index | \\(O(1)\\) |
| Update by index | \\(O(1)\\) |
| Linear search   | \\(O(n)\\) |
| Full traversal  | \\(O(n)\\) |

Yaad rakho: Index se element access karna fast hai, lekin kisi unknown value ko search karna generally \\(O(n)\\) hai.

# 3. Address Calculation Formula

Ab ek important formula:

\\[ \text{Address}(arr[i]) = \text{Base Address} + i \times \text{Element Size} \\]

Where:

- Base Address = first element ka address.
- `i` = index.
- Element Size = ek element kitne bytes occupy karta hai.

Example:

```
int arr[5] = {10, 20, 30, 40, 50};
```

Assume:

- Base address = 2000
- `sizeof(int) = 4`

Question: `arr[3]` ka address kya hoga?

\\[ 2000 + 3 \times 4 \\]

\\[ =2012 \\]

Answer: 2012.

C++ mein khud address print karna:

```
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    cout << &arr[0] << endl;
    cout << &arr[1] << endl;
    cout << &arr[2] << endl;
}
```

`&` address-of operator hai.

Ye tumhein elements ke actual memory addresses print karke dikhayega.

# 4. `arr[i]` internally kaise work karta hai?

Ye interesting concept hai.

C++ mein built-in arrays ke liye:

\\[ arr[i] \equiv \*(arr+i) \\]

Matlab:

```
arr[2]
```

Aur:

```
*(arr + 2)
```

Dono same element access karte hain.

Example:

```
int arr[3] = {10, 20, 30};

cout << arr[2] << endl;
cout << *(arr + 2) << endl;
```

Output:

```
30
30
```

Lekin `arr + 2` ka matlab kya hai?

Agar base address 1000 hai aur integer 4 bytes ka hai, to:

```
arr + 2
```

address 1008 ki taraf point karega, 1002 ki taraf nahi.

Pointer arithmetic mein increment element size ke mutabiq hota hai.

Is concept ko pointers chapter mein aur deeply cover karenge.

# 5. Array ke common bugs

Ab kuch mistakes jo beginners se hi nahi, experienced programmers se bhi ho sakti hain.

## Bug 1: Off-by-one error

```
int arr[5] = {1, 2, 3, 4, 5};

for(int i = 0; i <= 5; i++)
{
    cout << arr[i] << " ";
}
```

Problem:

Valid indexes `0` se `4` hain.

Lekin condition:

```
i <= 5
```

ki wajah se `i = 5` par bhi access ho raha hai.

Correct:

```
for(int i = 0; i < 5; i++)
```

Rule: Array traversal mein generally `i < size` use karo, `i <= size` nahi.

## Bug 2: Uninitialized array

```
int arr[5];

cout << arr[0];
```

Local built-in array ke elements ko explicitly initialize nahi kiya gaya.

Uninitialized element ko read karna safe nahi hai; is se undefined behavior ho sakta hai.

Correct:

```
int arr[5] = {};
```

Ab tamam elements zero initialized hain.

## Bug 3: Wrong maximum initialization

```
int arr[4] = {-10, -20, -5, -30};

int maximum = 0;
```

Yahan maximum ki initial value 0 rakhna logically incorrect hai.

Array mein koi bhi value zero nahi.

Correct:

```
int maximum = arr[0];
```

## Bug 4: Array size aur loop size mismatch

```
int arr[3] = {10, 20, 30};

for(int i = 0; i < 5; i++)
{
    cout << arr[i];
}
```

Array mein 3 elements hain, lekin loop 5 elements access karne ki koshish kar raha hai.

Correct:

```
for(int i = 0; i < 3; i++)
```

## Bug 5: Empty array par first element access

```
int getMax(const int arr[], int size)
{
    int maximum = arr[0];
    // ...
}
```

Agar `size == 0` ho, to `arr[0]` access invalid hai.

Function ko empty input handle karna chahiye.

Ek option:

```
bool getMax(const int arr[], int size, int &result)
{
    if(size <= 0)
    {
        return false;
    }

    result = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] > result)
        {
            result = arr[i];
        }
    }

    return true;
}
```

Yahan:

- `true` ka matlab maximum successfully calculate hua.
- `false` ka matlab valid non-empty array available nahi tha.
- `result` reference ke through answer caller ko milta hai.

# 6. Array ka total memory size

Suppose:

```
int arr[10];
```

Agar:

```
sizeof(int) = 4
```

To total memory:

\\[ 10 \times 4 = 40 \text{ bytes} \\]

C++ mein:

```
cout << sizeof(arr);
```

Output (is assumed system par):

```
40
```

Aur:

```
cout << sizeof(arr) / sizeof(arr[0]);
```

Output:

```
10
```

Ye technique tab useful hai jab array actual array object ho, jaise `main()` mein declaration.

Warning: Function parameter mein `int arr[]` pointer ban jata hai. Wahan `sizeof(arr)` se original array ka total size nahi milta.

# 7. Practice — Memory & Debugging Challenge

Ab ye questions khud attempt karo.

Q1. Address Calculation

Assume base address 5000 aur `sizeof(int) = 4`.

`arr[6]` ka address calculate karo.

Q2. Memory Calculation

```
double arr[8];
```

Assume `sizeof(double) = 8`.

Total memory kitni hogi?

Q3. Dry Run

```
int arr[4] = {5, 10, 15, 20};

cout << *(arr + 1) << endl;
cout << *(arr + 3) << endl;
cout << arr[2];
```

Output batao.

Q4. Debugging

Is code mein kya mistake hai?

```
int arr[5] = {10, 20, 30, 40, 50};

for(int i = 1; i <= 5; i++)
{
    cout << arr[i] << " ";
}
```

Q5. Conceptual

Array mein index access \\(O(1)\\) kyun hota hai? Apne words mein explain karo.

Q6. Tricky

Kya ye dono expressions equivalent hain?

```
arr[3]
```

```
*(arr + 3)
```

Reason bhi explain karna.

Part 4 complete

Part 4 ka core takeaway:

- Arrays contiguous memory mein store hote hain.
- Index access direct address calculation se hota hai.
- `arr[i]` aur `*(arr+i)` equivalent hain.
- Indexing errors undefined behavior cause kar sakte hain.
- Array ka size aur function parameter ka pointer size different concepts hain.