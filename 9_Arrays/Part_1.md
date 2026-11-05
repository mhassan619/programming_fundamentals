Chapter 9 ka plan — exactly 6 parts:

1. Array Foundations — declaration, initialization, indexing, bounds.
2. Array Traversal — input/output, sum, count, min/max, searching.
3. Arrays with Functions — passing arrays, size handling.
4. Memory & Common Bugs — contiguous memory, index calculation, off-by-one errors.
5. Problem-Solving Patterns — reverse, second largest, sorted check, frequency basics.
6. Final Revision & Mixed Challenge.

# Chapter 9 — Part 1: Array Foundations

## 1. Array hota kya hai?

Suppose tumhein 5 students ke marks store karne hain.

Normal variables use karo:

```
int marks1 = 85;
int marks2 = 90;
int marks3 = 78;
int marks4 = 92;
int marks5 = 88;
```

Ab imagine karo agar 1000 students ke marks store karne hon. Kya 1000 variables banaoge?

Obviously nahi!

Is problem ka solution hai Array.

Array ek aisa data structure hai jo:

- Same data type ki multiple values store karta hai.
- Values ko ek hi naam ke under rakhta hai.
- Har value ko index ke through access karta hai.

Example:

```
int marks[5] = {85, 90, 78, 92, 88};
```

Array visualization

# 85

Index 0

# 90

Index 1

# 78

Index 2

# 92

Index 3

# 88

Index 4

Array ka naam: marks | Total elements: 5

Notice karo: array mein 5 values hain, lekin unke indexes `0` se `4` tak hain.

## 2. Array declaration ka syntax

```
int arr[5];
```

Iska matlab:

- `int` → har element ka data type integer hoga.
- `arr` → array ka naam.
- `[5]` → array mein 5 elements ki capacity hai.

Important: Array ka size declaration ke waqt fixed hota hai for a built-in array.

## 3. Array initialization

Values assign karne ke different methods:

Method 1: Declaration ke saath

```
int arr[5] = {10, 20, 30, 40, 50};
```

Method 2: Size automatically calculate

```
int arr[] = {10, 20, 30, 40, 50};
```

Compiler elements count karke size 5 samajh lega.

Method 3: Partial initialization

```
int arr[5] = {10, 20};
```

Result:

```
10  20  0  0  0
```

Remaining elements zero initialize ho jaate hain.

Method 4: All elements zero

```
int arr[5] = {};
```

Result:

```
0  0  0  0  0
```

## 4. Array indexing — sab se important concept

Array ka first index hamesha `0` hota hai.

```
int arr[5] = {10, 20, 30, 40, 50};

cout << arr[0]; // 10
cout << arr[1]; // 20
cout << arr[2]; // 30
cout << arr[3]; // 40
cout << arr[4]; // 50
```

Last valid index ka formula:

\\[ \text{Last Index} = \text{Size} - 1 \\]

Agar size 5 hai:

\\[ 5-1=4 \\]

Why zero-based indexing?

C++ array access ko conceptually base address se offset ke through calculate karta hai:

\\[ \text{Address of arr[i]} = \text{Base Address} + i \times \text{sizeof(element)} \\]

Isliye `arr[0]` base address par hota hai, `arr[1]` uske baad wale element par, and so on.

## 5. Array elements access aur update karna

```
int arr[5] = {10, 20, 30, 40, 50};

arr[2] = 100;

cout << arr[2];
```

Output:

```
100
```

Yahan `arr[2]` ki old value `30` thi. Humne usko `100` se replace kar diya.

Array ke elements change ho sakte hain, lekin built-in array ka size declaration ke baad change nahi hota.

## 6. Out of Bounds — dangerous mistake

Suppose:

```
int arr[5] = {10, 20, 30, 40, 50};
```

Valid indexes:

```
0, 1, 2, 3, 4
```

Ab agar likho:

```
cout << arr[5];
```

Yeh invalid access hai.

C++ built-in arrays automatically bounds checking nahi karte. Is tarah ka access Undefined Behavior (UB) hai. Output predictable nahi hota; crash bhi ho sakta hai ya kuch aur.

Golden rule:

\\[ 0 \leq index < size \\]

## 7. Dry Run

Is code ko khud trace karo:

```
int arr[4] = {5, 10, 15, 20};

arr[1] = arr[1] + 5;
arr[3] = arr[0] + arr[2];

cout << arr[0] << endl;
cout << arr[1] << endl;
cout << arr[2] << endl;
cout << arr[3] << endl;
```

Initial array:

```
Index:  0   1   2   3
Value:  5  10  15  20
```

Pehli statement ke baad:

```
arr[1] = arr[1] + 5;
```

Second statement ke baad:

```
arr[3] = arr[0] + arr[2];
```

Final output khud calculate karna.

## 8. Practice — Part 1

Ab ye questions solve karo. Main abhi solutions nahi de raha, pehle tum attempt karo.

Q1. Array declare karo jo 7 integers store kare.

Q2. 5 elements ka array initialize karo aur third element print karo.

Q3. Array `{2, 4, 6, 8, 10}` mein first aur last element swap karo.

Q4. Agar array ka size 12 hai, valid indexes kya honge?

Q5. Is code ka output batao:

```
int arr[5] = {3, 6, 9};

cout << arr[0] << endl;
cout << arr[2] << endl;
cout << arr[4] << endl;
```

Q6. Tricky: Is code mein problem kya hai?

```
int arr[5] = {1, 2, 3, 4, 5};

for(int i = 0; i <= 5; i++)
{
    cout << arr[i] << " ";
}
```

Q7. Apne words mein explain karo: array ka last index `size - 1` kyun hota hai?

Part 1 ka main takeaway: Array same data type ki multiple values ko ek naam ke under store karta hai. Indexing zero se start hoti hai aur valid index hamesha `0` se `size-1` tak hota hai.