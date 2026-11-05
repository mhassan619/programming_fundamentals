# Part 3 — Arrays with Functions

## 1. Array ko function mein pass karna

Suppose hamare paas array hai aur hum uska sum calculate karna chahte hain.

Without function:

```
int arr[5] = {10, 20, 30, 40, 50};

int sum = 0;

for(int i = 0; i < 5; i++)
{
    sum += arr[i];
}

cout << sum;
```

Ab isi logic ko function mein move karte hain:

```
int calculateSum(int arr[], int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    cout << calculateSum(arr, 5);
}
```

Output:

```
150
```

Notice karo:

```
int calculateSum(int arr[], int size)
```

Function ko do cheezein mil rahi hain:

1. `arr[]` → array ka access.
2. `size` → array mein kitne elements hain.

## 2. Array ka size separately kyun pass karte hain?

Ye bohat important question hai.

Normally hum sochte hain ke agar array pass kar diya hai to function ko uska size bhi automatically pata hona chahiye.

Lekin C++ mein jab built-in array function parameter ke taur par pass hota hai, to woh pointer parameter mein adjust ho jata hai.

Example:

```
void display(int arr[])
{
    cout << sizeof(arr);
}
```

Yahan `sizeof(arr)` array ka total size nahi dega. Ye pointer ka size dega.

Isliye:

```
void display(int arr[], int size)
```

Hum explicitly size pass karte hain.

Golden rule: Function parameter mein `int arr[]` likhne ka matlab ye nahi ke function ko original array ka complete size automatically mil gaya.

## 3. Kya function original array modify kar sakta hai?

Yes! Aur ye bohat important concept hai.

Example:

```
void changeArray(int arr[], int size)
{
    arr[0] = 100;
}

int main()
{
    int arr[3] = {10, 20, 30};

    changeArray(arr, 3);

    cout << arr[0];
}
```

Output:

```
100
```

Lekin ruk jao!

Humne function mein array ki copy to create nahi ki thi. Phir original array change kaise hua?

Concept: Built-in array ko function mein pass karne par function original elements tak access kar sakta hai. Parameter pointer ke through unhi elements ko modify karta hai.

Conceptual flow

main()

`arr = {10, 20, 30}`

Array ka address pass hota hai

changeArray()

`arr[0] = 100`

Original array

`{100, 20, 30}`

## 4. Array aur pass by value ka confusion

Ab ek tricky distinction samjho.

```
void change(int x)
{
    x = 100;
}

int main()
{
    int a = 10;

    change(a);

    cout << a;
}
```

Output:

```
10
```

Kyun?

Kyun ke normal integer pass by value hota hai. Function ko copy milti hai.

Lekin array:

```
void change(int arr[])
{
    arr[0] = 100;
}
```

Yahan array ke elements original memory mein modify ho rahe hain.

Isliye array parameter ko ordinary integer parameter ki tarah samajhna galat hoga.

## 5. Function se array return kar sakte hain?

Built-in local array ko directly return nahi kar sakte.

Incorrect:

```
int[] createArray()
{
    int arr[3] = {10, 20, 30};
    return arr;
}
```

C++ mein ye valid syntax nahi hai.

Aur local array ka pointer/reference return karna bhi unsafe hai, kyun ke function end hone par local array ki lifetime khatam ho jati hai.

Modern C++ mein is purpose ke liye `vector` ya `array` use kar sakte hain.

Example with `vector`:

```
#include <iostream>
#include <vector>
using namespace std;

vector<int> createArray()
{
    vector<int> arr = {10, 20, 30};

    return arr;
}

int main()
{
    vector<int> result = createArray();

    for(int x : result)
    {
        cout << x << " ";
    }
}
```

Output:

```
10 20 30
```

Abhi hum built-in arrays par focus rakhenge. `vector` ko baad mein STL chapter mein deeply cover karenge.

## 6. Array ko modify kiye baghair function mein use karna

Agar hum chahte hain ke function array ko read kar sake lekin modify na kar sake, to `const` use karte hain.

```
int calculateSum(const int arr[], int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}
```

Ab ye allowed hai:

```
sum += arr[i];
```

Lekin ye allowed nahi:

```
arr[i] = 100;
```

Compiler modification prevent karega.

Why use `const`?

- Accidental modification se protection.
- Function ka intention clear hota hai.
- Read-only operations ke liye achhi practice hai.

# 7. Important function patterns

In patterns ko yaad karne ke bajaye samjho.

Pattern A — Array print karna

```
void display(const int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
```

Pattern B — Array ka sum

```
int getSum(const int arr[], int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}
```

Pattern C — Array ka maximum

```
int getMax(const int arr[], int size)
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

Note: `getMax` assume karta hai ke `size > 0` hai. Empty array ke liye pehle validation chahiye.

Pattern D — Array search

```
int search(const int arr[], int size, int target)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}
```

Yahan interesting cheez:

```
return i;
```

Jaise hi element milta hai, function terminate ho jata hai. Isliye separate `break` ki zaroorat nahi.

# 8. Complexity Analysis

Suppose function mein:

```
int getSum(const int arr[], int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}
```

| Operation       | Complexity                |
| --------------- | ------------------------- |
| Function call   | \\(O(1)\\) overhead model |
| Loop            | \\(O(n)\\)                |
| Total time      | \\(O(n)\\)                |
| Auxiliary space | \\(O(1)\\)                |

Array pass karne se poore array ki copy nahi banti. Isliye parameter passing itself \\(O(n)\\) copying cost introduce nahi karta.

# 9. Practice Challenge

Ab tum ye questions independently solve karo.

Q1. `displayArray()` function banao jo array ke tamam elements print kare.

Q2. `calculateSum()` function banao jo array ka sum return kare.

Q3. `countEven()` function banao jo even numbers ki quantity return kare.

Q4. `findMax()` function banao jo maximum element return kare.

Q5. `linearSearch()` function banao jo target ka index return kare. Target na mile to `-1`.

Q6. Tricky — Dry Run

```
void update(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = arr[i] * 2;
    }
}

int main()
{
    int arr[4] = {2, 4, 6, 8};

    update(arr, 4);

    cout << arr[0] << " ";
    cout << arr[2];
}
```

Output kya hoga aur kyun?

Q7. Conceptual Interview Question

Agar function parameter ye ho:

```
void display(int arr[])
```

To kya function ko automatically pata chal jayega ke original array mein kitne elements hain? Reason explain karo.

Part 3 complete

Aaj ke 3 most important concepts:

1. Built-in array function mein pass hone par pointer parameter mein adjust hota hai.
2. Array ka size separately pass karna hota hai.
3. Function original array ke elements modify kar sakta hai; `const` read-only access deta hai.