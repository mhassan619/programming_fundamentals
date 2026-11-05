# Chapter 9 — Part 5: Array Problem-Solving Patterns

Ab tak humne arrays ki foundation, traversal, functions aur memory samajh li. Ab un concepts ko combine karke interview-style problems solve karenge.

Is part mein 5 important problems hain:

1. Reverse an Array
2. Second Largest Element
3. Check if Array is Sorted
4. Frequency Counting
5. Remove Duplicates — basic approach

Har problem mein approach, intuition, code, dry run aur complexity samjhenge.

## 1. Reverse an Array

Problem: Array ke elements ko reverse order mein arrange karo.

Example:

```
int arr[5] = {10, 20, 30, 40, 50};
```

Expected:

```
50 40 30 20 10
```

### Approach: Two Pointers

Hum do variables use karenge:

- `left` → first index
- `right` → last index

Dono elements swap karenge aur pointers ko andar move karenge.

Two-pointer visualization

10

Index 0



Left



20

Index 1



30

Index 2



40

Index 3



50

Index 4



Right



Left aur Right swap honge, phir dono pointers center ki taraf move karenge.

### Code

```
void reverseArray(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while(left < right)
    {
        swap(arr[left], arr[right]);

        left++;
        right--;
    }
}
```

`swap()` ke liye `<algorithm>` ya `<utility>` header include kar sakte ho.

### Dry Run

Initial:

```
10 20 30 40 50
```

| Iteration | Left | Right | Operation   |
| --------- | ---- | ----- | ----------- |
| 1         | 0    | 4     | Swap 10, 50 |
| 2         | 1    | 3     | Swap 20, 40 |
| 3         | 2    | 2     | Stop        |

Final:

```
50 40 30 20 10
```

Why `left < right`?

Jab dono pointers equal ho jayein, center element already correct position par hai. Usko khud se swap karne ki zaroorat nahi.

Complexity:

- Time: \\(O(n)\\)
- Auxiliary Space: \\(O(1)\\)

Ye in-place reversal hai, kyun ke hum extra array create nahi kar rahe.

## 2. Second Largest Element

Important interview problem

Problem: Array ka second largest distinct element find karo.

Example:

```
int arr[6] = {10, 50, 30, 50, 40, 20};
```

Largest = 50

Second largest = 40

Important: Agar largest number multiple times aaye, to woh second largest nahi banega. Humein distinct second largest chahiye.

### Approach: Two Variables

Hum do variables maintain karenge:

- `largest`
- `secondLargest`

Initially:

```
int largest = INT_MIN;
int secondLargest = INT_MIN;
```

Iske liye:

```
#include <climits>
```

include karna hoga.

### Code

```
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[6] = {10, 50, 30, 50, 40, 20};

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < 6; i++)
    {
        if(arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }

    if(secondLargest == INT_MIN)
        cout << "Second largest does not exist";
    else
        cout << secondLargest;
}
```

Output:

```
40
```

### Dry Run

Array:

```
10 50 30 50 40 20
```

| Element | Largest | Second Largest |
| ------- | ------- | -------------- |
| 10      | 10      | INT_MIN        |
| 50      | 50      | 10             |
| 30      | 50      | 30             |
| 50      | 50      | 30             |
| 40      | 50      | 40             |
| 20      | 50      | 40             |

Answer = 40.

### Tricky cases

| Array          | Second largest distinct |
| -------------- | ----------------------- |
| `{5, 4, 3}`    | 4                       |
| `{5, 5, 4}`    | 4                       |
| `{9, 9, 9}`    | Doesn't exist           |
| `{-5, -2, -8}` | -5                      |
| `{10}`         | Doesn't exist           |

Important implementation note: `INT_MIN` sentinel approach mein agar actual array value bhi `INT_MIN` ho sakti hai, to sentinel ko missing value distinguish karne ke liye use nahi karna chahiye. A more robust approach boolean flags ya `optional` use karna hai. Hum challenge mein is edge case ko bhi test karenge.

Complexity:

- Time: \\(O(n)\\)
- Auxiliary Space: \\(O(1)\\)

## 3. Check Whether Array is Sorted

Problem: Check karo array ascending order mein sorted hai ya nahi.

Example:

```
1 2 3 4 5
```

Sorted: Yes.

```
1 3 2 4 5
```

Sorted: No.

### Intuition

Ascending sorted array mein har next element previous element se chhota nahi hona chahiye.

Mathematically:

\\[ arr[i] \leq arr[i+1] \\]

Har adjacent pair check karenge.

### Code

```
bool isSorted(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            return false;
        }
    }

    return true;
}
```

### Dry Run

```
arr = {2, 4, 6, 5, 8}
```

| Comparison | Result |
| ---------- | ------ |
| 2 > 4      | False  |
| 4 > 6      | False  |
| 6 > 5      | True   |

Jaise hi `6 > 5` true hua, function `false` return kar dega.

Why `i < size - 1`?

Kyun ke hum `arr[i+1]` bhi access kar rahe hain.

Agar size 5 hai, last comparison:

```
arr[3] > arr[4]
```

hoga.

`i = 4` allow kar diya to `arr[5]` access ho jayega, jo invalid hai.

Complexity:

- Time: \\(O(n)\\) worst case
- Best case: \\(O(1)\\), agar first comparison hi fail ho.
- Auxiliary Space: \\(O(1)\\)

## 4. Frequency Counting

Problem: Array mein har number kitni baar appear hota hai?

Example:

```
int arr[7] = {2, 3, 2, 5, 3, 2, 5};
```

Expected frequencies:

```
2 → 3 times
3 → 2 times
5 → 2 times
```

### Approach: Nested Loops

Abhi hum basic arrays use kar rahe hain, isliye nested loops se samjhenge.

```
int arr[7] = {2, 3, 2, 5, 3, 2, 5};

for(int i = 0; i < 7; i++)
{
    bool alreadyCounted = false;

    for(int j = 0; j < i; j++)
    {
        if(arr[i] == arr[j])
        {
            alreadyCounted = true;
            break;
        }
    }

    if(alreadyCounted)
        continue;

    int count = 0;

    for(int j = 0; j < 7; j++)
    {
        if(arr[i] == arr[j])
        {
            count++;
        }
    }

    cout << arr[i] << " appears " << count << " times" << endl;
}
```

Output:

```
2 appears 3 times
3 appears 2 times
5 appears 2 times
```

### `alreadyCounted` kyun use kiya?

Agar hum ye check na karein, to `2` ke liye frequency calculate hogi:

- First occurrence par.
- Second occurrence par.
- Third occurrence par.

Lekin humein har distinct number ki frequency sirf ek baar print karni hai.

Isliye inner loop previous indexes check karta hai.

### Complexity

Is simple approach mein nested loops hain:

\\[ O(n^2) \\]

Auxiliary space:

\\[ O(1) \\]

Baad mein Hashing aur `unordered_map` se frequency counting ko efficient banayenge.

## 5. Remove Duplicates — Basic Approach

Problem: Sorted array mein duplicate elements remove karke unique elements ko beginning mein place karo.

Example:

```
1 1 2 2 3 3 4
```

Expected unique portion:

```
1 2 3 4
```

### Intuition

Sorted array mein duplicates adjacent hote hain.

Hum ek `uniqueIndex` maintain karenge jo last unique element ka index represent karega.

### Code

```
int removeDuplicates(int arr[], int size)
{
    if(size == 0)
        return 0;

    int uniqueIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(arr[i] != arr[uniqueIndex])
        {
            uniqueIndex++;

            arr[uniqueIndex] = arr[i];
        }
    }

    return uniqueIndex + 1;
}
```

Example:

```
int arr[7] = {1, 1, 2, 2, 3, 3, 4};

int newSize = removeDuplicates(arr, 7);
```

Result:

```
Unique portion: 1 2 3 4
New size: 4
```

Notice karo: Original built-in array ka physical size 7 hi rahega. Function sirf unique elements ki new logical length return karta hai.

Complexity:

- Time: \\(O(n)\\)
- Auxiliary Space: \\(O(1)\\)

# 6. Problem-Solving Patterns — Summary

| Problem           | Pattern             | Time         |
| ----------------- | ------------------- | ------------ |
| Reverse Array     | Two Pointers        | \\(O(n)\\)   |
| Second Largest    | Tracking two values | \\(O(n)\\)   |
| Is Sorted         | Adjacent comparison | \\(O(n)\\)   |
| Frequency         | Nested loops        | \\(O(n^2)\\) |
| Remove Duplicates | Two Pointers        | \\(O(n)\\)   |

Ye patterns DSA mein baar baar use honge.

# 7. Your Interview Practice Challenge

Ab tumhari turn. Is baar main solutions nahi de raha. Tum khud approach aur code likho.

Q1 — Reverse Array

Array ko reverse karo without creating another array.

```
int arr[6] = {1, 2, 3, 4, 5, 6};
```

Q2 — Second Largest

Second largest distinct element find karo.

```
int arr[8] = {12, 35, 1, 10, 34, 35, 20, 34};
```

Q3 — Sorted Check

Function banao jo ascending sorted array ke liye `true`, warna `false` return kare.

Q4 — Count Occurrences

Function banao:

```
int countOccurrences(int arr[], int size, int target);
```

Ye target ki total occurrences return kare.

Q5 — Move Zeros to End

Interview-style

Input:

```
0 1 0 3 12
```

Expected:

```
1 3 12 0 0
```

Conditions:

- Relative order of non-zero elements same rehna chahiye.
- Extra array create nahi karna.
- In-place solution likhna.

Q6 — Tricky Second Largest

```
int arr[5] = {-10, -20, -30, -40, -50};
```

Second largest distinct element kya hoga?

Q7 — Complexity

Frequency-counting wale nested loop approach ki worst-case complexity \\(O(n^2)\\) kyun hai? Explain karo.

Part 5 complete