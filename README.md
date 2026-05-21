# Are Occurrences Equal

## Problem Statement

Given a string `s`, determine if all characters in the string appear the same number of times.

Return:

* `true` if every character has equal frequency
* `false` otherwise

---

## Example 1

### Input

```cpp
s = "abacbc"
```

### Frequency Count

| Character | Frequency |
| --------- | --------- |
| a         | 2         |
| b         | 2         |
| c         | 2         |

All characters appear `2` times.

### Output

```cpp
true
```

---

## Example 2

### Input

```cpp
s = "aaabb"
```

### Frequency Count

| Character | Frequency |
| --------- | --------- |
| a         | 3         |
| b         | 2         |

Frequencies are not equal.

### Output

```cpp
false
```

---

# Approach

We use an `unordered_map` to store the frequency of each character.

### Steps

1. Traverse the string
2. Store frequency of every character in hashmap
3. Push all frequencies into a vector
4. Compare adjacent frequencies
5. If any frequency is different, return `false`
6. Otherwise return `true`

---

# Code (C++)

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {

        unordered_map<char,int>freq;
        vector<int>ans;

        // Count frequency
        for(char x : s){
            freq[x]++;
        }

        // Store frequencies
        for(auto & it : freq){
            ans.push_back(it.second);
        }

        // Compare frequencies
        for(int i = 1; i < ans.size(); i++){

            if(ans[i] != ans[i-1]){
                return false;
            }
        }

        return true;
    }
};

int main(){

    Solution s;

    string str = "abacbc";

    cout << s.areOccurrencesEqual(str) << endl;

    return 0;
}
```

---

# Dry Run

### Input

```cpp
s = "abacbc"
```

### Step 1: Count Frequencies

```cpp
a -> 2
b -> 2
c -> 2
```

### Step 2: Store in Vector

```cpp
ans = [2, 2, 2]
```

### Step 3: Compare Adjacent Values

```cpp
2 == 2
2 == 2
```

All are equal.

### Final Output

```cpp
true
```

---

# Time Complexity

```cpp
O(n)
```

Because we traverse the string once.

---

# Space Complexity

```cpp
O(26)
```

At maximum, lowercase English letters are stored.
