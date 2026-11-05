# Part 6 — Arrays Final Revision

## 1. Complete Chapter Revision

Sabse pehle dekhte hain ke humne kya seekha.

| Concept           | Important point                                 |
| ----------------- | ----------------------------------------------- |
| Declaration       | `int arr[5];`                                   |
| Initialization    | `int arr[3] = {1,2,3};`                         |
| Indexing          | Starts from 0                                   |
| Last index        | `size - 1`                                      |
| Traversal         | `i < size`                                      |
| Sum               | `sum += arr[i]`                                 |
| Counting          | `count++`                                       |
| Maximum           | Initialize with `arr[0]`                        |
| Minimum           | Initialize with `arr[0]`                        |
| Searching         | Linear Search                                   |
| Functions         | Array size separately pass karo                 |
| Modification      | Function original elements modify kar sakta hai |
| Memory            | Contiguous locations                            |
| Access            | \\(O(1)\\)                                      |
| Reverse           | Two Pointers                                    |
| Second Largest    | Two variables                                   |
| Sorted Check      | Adjacent comparison                             |
| Frequency         | Nested loops / Hashing                          |
| Remove Duplicates | Two Pointers on sorted array                    |

## 2. Five Golden Rules

Ye rules arrays mein mistakes se bachayenge.

Rule 1: Index boundaries

```
for(int i = 0; i < size; i++)
```

`i <= size` use karne se last iteration out of bounds ho sakti hai.

Rule 2: Maximum/Minimum initialization

```
int maximum = arr[0];
int minimum = arr[0];
```

Agar array non-empty hai to ye safe logical initialization hai.

Rule 3: Function mein size pass karo

```
void display(int arr[], int size)
```

Function parameter mein array ka original size automatically available nahi hota.

Rule 4: Empty array handle karo

```
if(size == 0)
{
    return;
}
```

Khaas taur par jab `arr[0]` access karna ho.

Rule 5: Complexity samjho

- Single traversal: \\(O(n)\\)
- Nested traversal: commonly \\(O(n^2)\\)
- Direct indexing: \\(O(1)\\)

# 3. Master Assessment — Level 1: Conceptual Questions

Pehle concepts test karte hain.

Q1. Agar array ka size 15 hai to last valid index kya hoga?

Q2. Kya array mein different data types store kar sakte hain? Explain.

Q3. Array ka index access \\(O(1)\\) kyun hota hai?

Q4. Function parameter mein `int arr[]` aur `int size` dono kyun pass karte hain?

Q5. Kya ye code valid hai?

```
int arr[5] = {1, 2, 3, 4, 5};

cout << arr[5];
```

Reason bhi explain karo.

Q6. `arr[i]` aur `*(arr+i)` mein kya relationship hai?

Q7. Agar array mein tamam numbers negative hain to maximum initialize karne ka correct tareeqa kya hai?

# 4. Master Assessment — Level 2: Dry Run

Ab output predict karo.

Q8.

```
int arr[5] = {2, 4, 6, 8, 10};

int result = 0;

for(int i = 0; i < 5; i++)
{
    if(i % 2 == 0)
    {
        result += arr[i];
    }
}

cout << result;
```

Q9.

```
int arr[5] = {10, 20, 30, 40, 50};

for(int i = 0; i < 2; i++)
{
    swap(arr[i], arr[4-i]);
}

for(int i = 0; i < 5; i++)
{
    cout << arr[i] << " ";
}
```

Q10.

```
int arr[6] = {3, 5, 3, 7, 5, 3};

int count = 0;

for(int i = 0; i < 6; i++)
{
    if(arr[i] == 3)
    {
        count++;
    }
}

cout << count;
```

# 5. Master Assessment — Level 3: Debugging

Ye questions particularly important hain, kyun ke interviews mein code debugging bhi test hoti hai.

Q11. Find the bug

```
int arr[5] = {10, 20, 30, 40, 50};

for(int i = 0; i <= 5; i++)
{
    cout << arr[i] << " ";
}
```

Q12. Find the logical error

```
int arr[5] = {-10, -20, -5, -30, -15};

int maximum = 0;

for(int i = 0; i < 5; i++)
{
    if(arr[i] > maximum)
    {
        maximum = arr[i];
    }
}

cout << maximum;
```

Q13. Find the problem

```
int calculateSum(int arr[])
{
    int sum = 0;

    for(int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }

    return sum;
}
```

Function mein kya improvement karni chahiye?

# 6. Master Assessment — Level 4: Coding Challenges

Interview practice

Ab actual programming problems.

Q14 — Reverse Array

```
int arr[7] = {11, 22, 33, 44, 55, 66, 77};
```

Array ko in-place reverse karo.

Q15 — Second Largest Distinct

```
int arr[8] = {10, 20, 40, 30, 40, 50, 20, 50};
```

Second largest distinct element find karo.

Q16 — Move Zeros to End

Input:

```
0 1 0 3 12 0 5
```

Output:

```
1 3 12 5 0 0 0
```

Conditions:

- Extra array nahi banana.
- Non-zero elements ka relative order preserve karna.
- In-place solution.

Q17 — Check Sorted Array

Ek function likho:

```
bool isSorted(int arr[], int size);
```

Ascending order check kare.

Q18 — Find Missing Number

Array mein numbers `1` se `n` tak hain, lekin ek number missing hai.

Example:

```
int arr[5] = {1, 2, 4, 5, 6};
```

Missing number = `3`.

Ek solution likho aur uski time aur space complexity explain karo.

Q19 — Frequency Counter

```
int arr[8] = {4, 2, 4, 3, 2, 4, 5, 3};
```

Har distinct number ki frequency print karo.

Pehle nested loops se solve karo. Hashing hum DSA mein cover karenge.

# 7. Final Complexity Challenge

Neeche diye gaye operations ki time complexity batao.

| Question | Operation                       |
| -------- | ------------------------------- |
| Q20      | `arr[5]` access karna           |
| Q21      | Array ka sum calculate karna    |
| Q22      | Linear search                   |
| Q23      | Nested loops se frequency count |
| Q24      | Two-pointer reverse             |
| Q25      | Sorted array mein binary search |

Expected format:

```
Q20 = O(?)
Q21 = O(?)
...
```

# 8. Chapter 9 Completion Criteria

Mera suggestion hai ke Chapter 9 ko complete tab consider karein jab tum ye skills independently demonstrate kar sako:

- Array declare, initialize aur traverse karna.
- Sum, count, min/max calculate karna.
- Linear search implement karna.
- Arrays ko functions mein pass karna.
- Indexing aur memory address calculation samajhna.
- Reverse array using two pointers.
- Second largest distinct element find karna.
- Sorted check aur frequency count karna.
- Common array bugs debug karna.
- Time aur space complexity analyze karna.

Meri recommendation: Saare 25 questions ek saath solve karne ki zaroorat nahi. Pehle Q1–Q13 attempt karo, phir coding challenges par aana. Main tumhare answers ko strict-teacher style mein check karunga: logic, edge cases, code quality aur complexity.