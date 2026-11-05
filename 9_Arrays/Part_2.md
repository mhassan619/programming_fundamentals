# Part 2 — Array Traversal

## 1. Array Traversal kya hoti hai?

Traversal ka matlab hai array ke har element ko one by one visit karna.

Example:

```
int arr[5] = {10, 20, 30, 40, 50};

for(int i = 0; i < 5; i++)
{
    cout << arr[i] << " ";
}
```

Output:

```
10 20 30 40 50
```

Dry run:

| Iteration | `i` | `arr[i]` |
| --------- | --- | -------- |
| 1         | 0   | 10       |
| 2         | 1   | 20       |
| 3         | 2   | 30       |
| 4         | 3   | 40       |
| 5         | 4   | 50       |

Loop `i < 5` tak chalta hai, kyun ke last valid index 4 hai.

Important pattern:

```
for(int i = 0; i < size; i++)
{
    // arr[i] par operation
}
```

Ye pattern arrays mein bohat frequently use hoga.

## 2. User se array input lena

Suppose user se 5 numbers lene hain:

```
int arr[5];

for(int i = 0; i < 5; i++)
{
    cin >> arr[i];
}
```

Agar input ho:

```
5 10 15 20 25
```

To array ban jayega:

```
Index:  0   1   2   3   4
Value:  5  10  15  20  25
```

Array print karne ke liye doosra loop:

```
for(int i = 0; i < 5; i++)
{
    cout << arr[i] << " ";
}
```

Input aur output ke loops separate rakhna beginners ke liye zyada clear hota hai.

## 3. Sum of Array Elements

Problem: Array ke tamam elements ka sum calculate karo.

Example:

```
arr = {5, 10, 15, 20}
```

Expected sum:

\\[ 5+10+15+20=50 \\]

Code:

```
int arr[4] = {5, 10, 15, 20};

int sum = 0;

for(int i = 0; i < 4; i++)
{
    sum = sum + arr[i];
}

cout << sum;
```

Dry run

| `i` | `arr[i]` | Previous sum | New sum |
| --- | -------- | ------------ | ------- |
| 0   | 5        | 0            | 5       |
| 1   | 10       | 5            | 15      |
| 2   | 15       | 15           | 30      |
| 3   | 20       | 30           | 50      |

Yahan important concept hai accumulator.

Accumulator wo variable hota hai jo repeatedly values collect karta hai.

```
int sum = 0;
sum = sum + arr[i];
```

Sum ko `0` se initialize karte hain kyun ke addition ka identity element zero hai.

## 4. Count specific elements

Problem: Array mein even numbers kitne hain?

```
int arr[6] = {2, 5, 8, 11, 14, 17};

int count = 0;

for(int i = 0; i < 6; i++)
{
    if(arr[i] % 2 == 0)
    {
        count++;
    }
}

cout << count;
```

Output:

```
3
```

Even numbers: `2, 8, 14`.

Yahan `count` accumulator ki tarah nahi, counting variable ki tarah kaam kar raha hai.

General pattern:

```
int count = 0;

for(int i = 0; i < size; i++)
{
    if(condition)
    {
        count++;
    }
}
```

Is pattern se tum count kar sakte ho:

- Positive numbers
- Negative numbers
- Even/odd numbers
- Numbers greater than 10
- Zero elements

## 5. Maximum element find karna

Problem: Array ka largest number find karo.

```
int arr[5] = {12, 45, 7, 89, 23};

int maximum = arr[0];

for(int i = 1; i < 5; i++)
{
    if(arr[i] > maximum)
    {
        maximum = arr[i];
    }
}

cout << maximum;
```

Output:

```
89
```

Ab logic samjho.

Initially:

```
int maximum = arr[0];
```

Hum assume karte hain ke first element hi maximum hai.

Phir baqi elements se comparison karte hain.

| `i`     | Current element | Current maximum |
| ------- | --------------- | --------------- |
| Initial | 12              | 12              |
| 1       | 45              | 45              |
| 2       | 7               | 45              |
| 3       | 89              | 89              |
| 4       | 23              | 89              |

Important question: `maximum = 0` kyun nahi likha?

Agar array ho:

```
int arr[4] = {-10, -5, -20, -3};
```

Aur maximum ko zero initialize kar dein, to answer zero aa sakta hai, jabke zero array mein exist hi nahi karta.

Isliye non-empty array ke liye:

```
int maximum = arr[0];
```

Best approach hai.

## 6. Minimum element find karna

Maximum ka reverse logic:

```
int arr[5] = {12, 45, 7, 89, 23};

int minimum = arr[0];

for(int i = 1; i < 5; i++)
{
    if(arr[i] < minimum)
    {
        minimum = arr[i];
    }
}

cout << minimum;
```

Output:

```
7
```

Yahan bhi first element se initialize karte hain.

## 7. Linear Search

Ab ek bohat important concept: Searching.

Problem: Array mein check karo ke number `30` exist karta hai ya nahi.

```
int arr[5] = {10, 20, 30, 40, 50};

int target = 30;
int index = -1;

for(int i = 0; i < 5; i++)
{
    if(arr[i] == target)
    {
        index = i;
        break;
    }
}

cout << index;
```

Output:

```
2
```

Isay Linear Search kehte hain.

Logic:

1. First element check karo.
2. Agar target mil gaya to uska index save karo.
3. Warna next element check karo.
4. Agar poora array check karne ke baad bhi na mile, index `-1` rahega.

`break` ka purpose: Target milne ke baad unnecessary comparisons rok dena.

Complexity:

| Case         | Time Complexity |
| ------------ | --------------- |
| Best case    | \\(O(1)\\)      |
| Average case | \\(O(n)\\)      |
| Worst case   | \\(O(n)\\)      |
| Space        | \\(O(1)\\)      |

Linear search sorted aur unsorted dono arrays mein kaam karti hai.

## 8. Ek hi traversal mein multiple operations

Ab dekho, hum sum, even count, maximum aur minimum ek hi loop mein calculate kar sakte hain.

```
int arr[5] = {10, 25, 8, 40, 17};

int sum = 0;
int evenCount = 0;
int maximum = arr[0];
int minimum = arr[0];

for(int i = 0; i < 5; i++)
{
    sum += arr[i];

    if(arr[i] % 2 == 0)
    {
        evenCount++;
    }

    if(arr[i] > maximum)
    {
        maximum = arr[i];
    }

    if(arr[i] < minimum)
    {
        minimum = arr[i];
    }
}

cout << "Sum: " << sum << endl;
cout << "Even Count: " << evenCount << endl;
cout << "Maximum: " << maximum << endl;
cout << "Minimum: " << minimum << endl;
```

Output:

```
Sum: 100
Even Count: 2
Maximum: 40
Minimum: 8
```

Yahan humne 4 separate traversals ki jagah ek traversal use ki.

Time complexity phir bhi \\(O(n)\\) hai, kyun ke har element sirf ek baar visit ho raha hai. Space complexity \\(O(1)\\) hai.

# 9. Practice Problems

Ab tumhari turn. Solutions abhi nahi de raha.

Q1 — Sum: Array ke tamam elements ka sum calculate karo.

```
int arr[6] = {3, 7, 2, 9, 4, 5};
```

Q2 — Count: Array mein kitne negative numbers hain?

```
int arr[7] = {-2, 5, -8, 0, 4, -1, 9};
```

Q3 — Maximum & Minimum: Dono values find karo.

```
int arr[6] = {45, 12, 89, 3, 67, 21};
```

Q4 — Search: Target `25` find karo. Agar exist karta hai to index print karo, warna `Not Found`.

```
int arr[6] = {10, 20, 30, 40, 50, 60};
```

Q5 — Tricky Dry Run:

```
int arr[5] = {2, 4, 6, 8, 10};

int sum = 0;

for(int i = 0; i < 5; i++)
{
    if(arr[i] > 5)
    {
        sum += arr[i];
    }
}

cout << sum;
```

Q6 — Interview-style: Kya tum ek hi loop mein even numbers ka sum aur odd numbers ka count calculate kar sakte ho? Code likho.

## Part 2 — Quick Revision

| Operation | Main logic         |
| --------- | ------------------ |
| Traversal | `arr[i]`           |
| Sum       | `sum += arr[i]`    |
| Count     | `count++`          |
| Maximum   | `arr[i] > maximum` |
| Minimum   | `arr[i] < minimum` |
| Search    | `arr[i] == target` |

Complexity reminder: In tamam basic operations ki worst-case time complexity \\(O(n)\\) hai, aur auxiliary space \\(O(1)\\) hai.