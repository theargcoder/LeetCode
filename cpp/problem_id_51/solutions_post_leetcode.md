# **🚀 N-Queens – The Ultimate 0ms Solution: Bitmasks, Shifts & Hyper-Optimization ⚡**  


# Intuition & Approach

<!-- Describe your first thoughts on how to solve this problem. -->
At first, I tried using vectors and checking every single row like a **good brute-force person**…  

Then I realized that wasn’t great, so I switched to a **flattened bitset** 2D array of size **81**  
(max size given the constraints: **1 ≤ n ≤ 9**).  

After checking every permutation across the **full board**, the solution worked—  
but it took **79 ms**… (*SLOWWW* 🚶💨).  

### The First Optimization – Bitmasks & Shifts  
I restructured each **column** of the flattened bitset into a **`unsigned short` array of size 9**,  
with a **bitmask** set to:  

- **Binary:** `const unsigned short BASE = 0b1111111111111111 & (0b1111111111111111 << n)`;

This allowed **diagonal checks** using **bit shifts**, bringing execution time **down to 22 ms**.  

### Why 22ms Was Still Inefficient 🧐  
There were **several major inefficiencies** in this 22ms solution:  

1. **Diagonal shift checking loop didn't check all previous rows.**  
2. **It validated rows *below* the current row.**  
   > (IDK what I was thinking—it was 2 AM... 😵‍💫)  
   > Since this is a *forward trial* algorithm, we should only care about the past, *not the future*.  
3. **We checked the entire board** every time for diagonal attacks.  
4. **We recalculated all masks on every check** 
   > ENPHASIS ON POINT 4 MY LORD ITS HORRIBLY INEFFICIENT. 

---

### The Breakthrough – 0ms Solutions 🚀  
Realizing all these inefficiencies, I got to work—leading to the **0ms (ORIGINAL)**  
and **0ms (HYPER-OPTIMIZED)** versions.  

1. **We precompute & save all possible column states.**  
2. **We use a boolean array** to track used columns (instead of checking collisions manually).  
   > No point in checking *up/down* conflicts—just discard invalid columns immediately.  
3. **We store previous masks**, so we compute each row's mask **only once per loop**.  
4. **Diagonal checks** (`diagonal_cmpnd` function) are **hyper-efficient**:  
   - **1 micro-op** per **bit shift** (`1-bit` or `10-bit` shift → still just **1 micro-op**).  
   - **1 micro-op** per **comparison**.  
   - Done **twice** (left + right diagonals).  
   - In **4 × idx operations**, we verify all diagonals for a board.  

Super. **Efficient.** 🔥

# SOLUTIONS

The solutions are listed in order of execution time:

1. *63 ms solution* → [Jump to 63 ms solution](#63-ms-solution)  
2. *23 ms solution* → [Jump to 23 ms solution](#23-ms-solution)  
3. *12 ms solution* → [Jump to 12 ms solution](#12-ms-solution)  
4. *0-2 ms solution* → [Jump to 1/0 ms solution](#1-ms-or-0-ms-solution)  
5. *0 ms solution (BEST ONE)* → [Jump to 0 ms solution](#0ms-solution-fastest)  

💡 *I highly recommend going through all of them!*  
It's interesting to see how small logic changes between solutions **increase speed by at least 79x!*


# Complexity
- Time complexity:
$$O(N!)$$

> NOTE : there is pruning so its ONLY IN WORST CASE $$O(N!)$$ 

- Space complexity:
$$O(N)$$

### 63 ms SOLUTION
This is the section you want to jump to.

```cpp
class Solution
{
 public:
   std::vector<std::vector<std::string> >
   solveNQueens (int n)
   {
      std::bitset<81> board; // max size (1 <= n <= 9)
      const int nn = n * n;

      for (int i = 0; i < nn; i++)
         {
            board[i] = false;
         }

      std::vector<std::vector<std::string> > res{};
      helper (res, board, n, nn, 0, 0);
      return res;
   }

   void
   helper (std::vector<std::vector<std::string> > &res, std::bitset<81> &board,
           const int &n, const int &nn, int row, int col)
   {
      if (row >= n)
         {
            res.push_back ({});
            for (int i = 0; i < n; i++)
               {
                  res.back ().push_back ("");
                  for (int j = 0; j < n; j++)
                     {
                        const int Q = i * n + j;
                        if (board[Q])
                           res.back ()[i].push_back ('Q');
                        else
                           res.back ()[i].push_back ('.');
                     }
               }
            return;
         }

      for (int i = col; i < row * n + n; i++)
         {
            if (board[i] == false)
               {
                  board[i] = true;
                  if (is_valid (board, n, nn))
                     {
                        helper (res, board, n, nn, row + 1, 0);
                     }
                  board[i] = false;
               }
         }
   }
   // they cant attack eachother
   bool
   is_valid (std::bitset<81> &board, const int &n, const int &nn)
   {
      for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < n; j++)
               {
                  const int Q = i * n + j;
                  if (!board[Q])
                     continue;
                  int x, y;
                  for (x = i * n; x < (i * n + n); x++)
                     {
                        if (x != Q)
                           {
                              if (!board[x])
                                 continue;
                              return false;
                           }
                     }
                  for (y = j; y < (nn); y += n)
                     {
                        if (y != Q)
                           {
                              if (!board[y])
                                 continue;
                              return false;
                           }
                     }
                  if (!check_diagonals (board, i - 1, j - 1, n, "LU"))
                     return false;
                  if (!check_diagonals (board, i - 1, j + 1, n, "LD"))
                     return false;
                  if (!check_diagonals (board, i + 1, j - 1, n, "RU"))
                     return false;
                  if (!check_diagonals (board, i + 1, j + 1, n, "RD"))
                     return false;
               }
         }
      return true;
   }

   bool
   check_diagonals (std::bitset<81> &board, int x, int y, const int &n,
                    const char LDLURDRU[2])
   {
      if (x < 0 || x >= n)
         return true;
      if (y < 0 || y >= n)
         return true;

      bool left = (LDLURDRU[0] == 'L');
      bool up = (LDLURDRU[1] == 'U');

      while (x >= 0 && x < n && y >= 0 && y < n)
         {
            const int index = (x * n) + y;

            if (board[index])
               {
                  return false;
               }

            if (left && up)
               {
                  x--;
                  y--;
               }
            else if (left && !up)
               {
                  x--;
                  y++;
               }
            else if (!left && up)
               {
                  x++;
                  y--;
               }
            else
               {
                  x++;
                  y++;
               }
         }
      return true;
   }
};
```

### 23 ms SOLUTION 
```cpp
class Solution
{
 public:
   std::vector<std::vector<std::string> >
   solveNQueens (int n)
   {
      unsigned short BASE = 1;
      for (int i = 0; i < 16 - n; i++)
         BASE = (BASE << 1) | (0x1);
      for (int i = 0; i < n; i++)
         BASE = (BASE << 1);
      unsigned short board[9];
      std::unordered_map<unsigned short, bool> used;

      for (int i = 0; i < n; i++)
         {
            unsigned short tmp = BASE | (1 << i);
            used[tmp] = false;
         }

      std::vector<std::vector<std::string> > res{};
      helper (res, &board[0], n, 0, BASE, used);
      return res;
   }

   void
   helper (std::vector<std::vector<std::string> > &res, unsigned short *board,
           const int &n, const int row, const unsigned short &BASE,
           std::unordered_map<unsigned short, bool> &used)
   {
      if (row >= n)
         {
            if (is_valid (board, n, BASE))
               {
                  res.push_back ({});
                  for (int i = 0; i < n; i++)
                     {
                        res.back ().push_back ("");
                        for (int j = 0; j < n; j++)
                           {
                              if ((board[i] >> j) & 0b1)
                                 res.back ()[i].push_back ('Q');
                              else
                                 res.back ()[i].push_back ('.');
                           }
                     }
               }
            return;
         }

      // Use row as the limit (number of rows filled so far) in the partial
      // check.
      for (int i = 0; i < n; i++)
         {
            board[row] = BASE | (1 << i);
            if (!used[board[row]] && diagonal (board, n, BASE, row))
               {
                  used[board[row]] = true;
                  helper (res, board, n, row + 1, BASE, used);
                  used[board[row]] = false;
               }
         }
      board[row] = BASE;
      return;
   }
   bool
   diagonal (unsigned short *board, const int n, const unsigned short &BASE,
             int idx)
   {
      // Isolate the queen's bit from the current row.
      unsigned short queenPos = board[idx] & ~BASE;

      // Check the row above (if any)
      if (idx > 0)
         {
            unsigned short queenAbove = board[idx - 1] & ~BASE;
            // If shifting queenAbove left or right gives queenPos, they share
            // a diagonal.
            if ((queenAbove << 1) == queenPos || (queenAbove >> 1) == queenPos)
               return false;
         }

      // Check the row below (if any)
      if (idx < n - 1)
         {
            unsigned short queenBelow = board[idx + 1] & ~BASE;
            if ((queenBelow << 1) == queenPos || (queenBelow >> 1) == queenPos)
               return false;
         }

      return true;
   }
   // they cant attack eachother
   bool
   is_valid (unsigned short *board, const int &n, const unsigned short &BASE)
   {
      for (int i = 0; i < n; i++)
         {
            short count = 0, count_cpy;
            unsigned short tmp = board[i];
            while (!(tmp & 0b1))
               {
                  count++;
                  tmp >>= 1;
               }
            // UPPER LEFT DIAGONAL
            count_cpy = count + 1;
            for (int j = i - 1; j >= 0; j--)
               {
                  tmp = board[j];

                  if (count_cpy >= n)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy++;
               }
            // UPPER RIGHT DIAGONAL
            count_cpy = count - 1;
            for (int j = i - 1; j >= 0; j--)
               {
                  tmp = board[j];

                  if (count_cpy < 0)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy--;
               }
            // LOWER RIGHT DIAGONAL
            count_cpy = count - 1;
            for (int j = i + 1; j < n; j++)
               {
                  tmp = board[j];

                  if (count_cpy < 0)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy--;
               }
            // LOWER LEFT DIAGONAL
            count_cpy = count + 1;
            for (int j = i + 1; j < n; j++)
               {
                  tmp = board[j];

                  if (count_cpy >= n)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy++;
               }
         }
      return true;
   }
};

```

### 12 ms SOLUTION 
```cpp
class Solution
{
 public:
   std::vector<std::vector<std::string> >
   solveNQueens (int n)
   {
      unsigned short BASE = 1;
      for (int i = 0; i < 16 - n; i++)
         BASE = (BASE << 1) | (0x1);
      for (int i = 0; i < n; i++)
         BASE = (BASE << 1);
      unsigned short board[9];
      unsigned short options[9];
      bool used[9];

      for (int i = 0; i < n; i++)
         {
            unsigned short tmp = BASE | (1 << i);
            options[i] = tmp;
            used[i] = false;
            board[i] = BASE;
         }

      std::vector<std::vector<std::string> > res{};
      helper (res, &board[0], n, 0, BASE, &used[0], &options[0]);
      return res;
   }
   void
   helper (std::vector<std::vector<std::string> > &res, unsigned short *board,
           const int &n, const int row, const unsigned short &BASE, bool *used,
           unsigned short *options)
   {
      if (row >= n)
         {
            if (is_valid (board, n, BASE))
               {
                  res.push_back ({});
                  for (int i = 0; i < n; i++)
                     {
                        res.back ().push_back ("");
                        for (int j = 0; j < n; j++)
                           {
                              if ((board[i] >> j) & 0b1)
                                 res.back ()[i].push_back ('Q');
                              else
                                 res.back ()[i].push_back ('.');
                           }
                     }
               }

            return;
         }

      // Use row as the limit (number of rows filled so far) in the partial
      // check.
      for (int i = 0; i < n; i++)
         {
            board[row] = options[i];
            if (!used[i] && diagonal (board, n, BASE, row))
               {
                  used[i] = true;
                  helper (res, board, n, row + 1, BASE, used, options);
                  used[i] = false;
               }
         }
      board[row] = BASE;
      return;
   }
   bool
   diagonal (unsigned short *board, const int n, const unsigned short &BASE,
             int idx)
   {
      // Isolate the queen's bit from the current row.
      unsigned short queenPos = board[idx] & ~BASE;

      // Check the row above (if any)
      if (idx > 0)
         {
            unsigned short queenAbove = board[idx - 1] & ~BASE;
            // If shifting queenAbove left or right gives queenPos, they share
            // a diagonal.
            if ((queenAbove << 1) == queenPos || (queenAbove >> 1) == queenPos)
               return false;
         }

      // Check the row below (if any)
      if (idx < n - 1)
         {
            unsigned short queenBelow = board[idx + 1] & ~BASE;
            if ((queenBelow << 1) == queenPos || (queenBelow >> 1) == queenPos)
               return false;
         }

      return true;
   }
   // they cant attack eachother
   bool
   is_valid (unsigned short *board, const int &n, const unsigned short &BASE)
   {
      for (int i = 0; i < n; i++)
         {
            short count = 0, count_cpy;
            unsigned short tmp = board[i];
            while (!(tmp & 0b1))
               {
                  count++;
                  tmp >>= 1;
               }
            // UPPER LEFT DIAGONAL
            count_cpy = count + 1;
            for (int j = i - 1; j >= 0; j--)
               {
                  tmp = board[j];

                  if (count_cpy >= n)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy++;
               }
            // UPPER RIGHT DIAGONAL
            count_cpy = count - 1;
            for (int j = i - 1; j >= 0; j--)
               {
                  tmp = board[j];

                  if (count_cpy < 0)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy--;
               }
            // LOWER RIGHT DIAGONAL
            count_cpy = count - 1;
            for (int j = i + 1; j < n; j++)
               {
                  tmp = board[j];

                  if (count_cpy < 0)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy--;
               }
            // LOWER LEFT DIAGONAL
            count_cpy = count + 1;
            for (int j = i + 1; j < n; j++)
               {
                  tmp = board[j];

                  if (count_cpy >= n)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy++;
               }
         }
      return true;
   }
};


```
### 1 ms or 0 ms SOLUTION 
> 0 || 1 || 2 ms i think its the compiler to blame for the variations
> regardless it's not the most optimized one possible (see NEXT)
> pretty redable solution simple and easy

```cpp 
class Solution
{
 public:
   std::vector<std::vector<std::string> >
   solveNQueens (int n)
   {
      unsigned short BASE = 1;
      for (int i = 0; i < 16 - n; i++)
         BASE = (BASE << 1) | (0x1);
      for (int i = 0; i < n; i++)
         BASE = (BASE << 1);
      unsigned short board[9];
      unsigned short options[9];
      unsigned short prev_mask[9];
      bool used[9];

      for (int i = 0; i < n; i++)
         {
            unsigned short tmp = BASE | (1 << i);
            options[i] = tmp;
            used[i] = false;
            board[i] = BASE;
         }

      std::vector<std::vector<std::string> > res{};
      helper (res, &board[0], n, 0, BASE, &used[0], &options[0],
              &prev_mask[0]);
      return res;
   }
   void
   helper (std::vector<std::vector<std::string> > &res, unsigned short *board,
           const int &n, const int row, const unsigned short &BASE, bool *used,
           unsigned short *options, unsigned short *prev_mask)
   {
      if (row >= n)
         {
            res.push_back ({});
            for (int i = 0; i < n; i++)
               {
                  res.back ().push_back ("");
                  for (int j = 0; j < n; j++)
                     {
                        if ((board[i] >> j) & 0b1)
                           res.back ()[i].push_back ('Q');
                        else
                           res.back ()[i].push_back ('.');
                     }
               }

            return;
         }

      // Use row as the limit (number of rows filled so far) in the partial
      // check.
      for (int i = 0; i < n; i++)
         {
            board[row] = options[i];
            if (!used[i] && diagonal_cmpnd (board, n, BASE, row, prev_mask))
               {
                  used[i] = true;
                  helper (res, board, n, row + 1, BASE, used, options,
                          prev_mask);
                  used[i] = false;
               }
         }
      board[row] = BASE;
      return;
   }
   bool
   diagonal_cmpnd (unsigned short *board, const int n,
                   const unsigned short &BASE, int idx,
                   unsigned short *prev_mask)
   {
      // Isolate the queen's bit from the current row.
      unsigned short queenPos = board[idx] & ~BASE;

      for (int i = 0; i < idx; i++)
         {
            // If shifting queenAbove left or right gives queenPos, they share
            // a diagonal.
            if ((prev_mask[i] >> (idx - i)) == queenPos
                || (prev_mask[i] << (idx - i)) == queenPos)
               return false;
         }
      prev_mask[idx] = queenPos;

      return true;
   }
};
```

### 0ms SOLUTION (FASTEST) 

> 0 ms (as fast as possible in C++ (IMO))
> pretty redable solution simple and easy
> would need asm/verilog levels of bit ops to even be able to start to make it faster

```cpp
// FINAL indebatable 0ms
// HYPER OPTIMIZED IDK even where it can be better
class Solution
{
 public:
   std::vector<std::vector<std::string> >
   solveNQueens (int n)
   {
      unsigned short BASE = 0b1111111111111111 & (0b1111111111111111 << n);
      unsigned short board[9];
      unsigned short options[9];
      unsigned short prev_mask[9];
      bool used[9];

      for (int i = 0; i < n; i++)
         {
            options[i] = BASE | (1 << i);
            used[i] = false;
            board[i] = BASE;
         }

      int row = 0;

      std::vector<std::vector<std::string> > res{};
      res.reserve (353);
      helper (res, &board[0], n, row, BASE, &used[0], &options[0],
              &prev_mask[0]);
      return res;
   }

 private:
   void
   helper (std::vector<std::vector<std::string> > &res, unsigned short *board,
           const int &n, int &row, const unsigned short &BASE, bool *used,
           unsigned short *options, unsigned short *prev_mask)
   {
      if (row >= n)
         {
            res.push_back ({});
            for (int i = 0; i < n; i++)
               {
                  res.back ().push_back ("");
                  for (int j = 0; j < n; j++)
                     {
                        if ((board[i] >> j) & 0b1)
                           res.back ()[i].push_back ('Q');
                        else
                           res.back ()[i].push_back ('.');
                     }
               }

            return;
         }

      // Use row as the limit (number of rows filled so far) in the partial
      // check.
      for (int i = 0; i < n; i++)
         {
            if (!used[i])
               {
                  used[i] = true;
                  board[row] = options[i];
                  if (diagonal_cmpnd (board, n, BASE, row, prev_mask))
                     {
                        row++;
                        helper (res, board, n, row, BASE, used, options,
                                prev_mask);
                        row--;
                     }
                  used[i] = false;
               }
         }
      return;
   }
   inline bool
   diagonal_cmpnd (unsigned short *board, const int n,
                   const unsigned short &BASE, int idx,
                   unsigned short *prev_mask)
   {
      // Isolate the queen's bit from the current row.
      unsigned short queenPos = board[idx] & ~BASE;

      for (unsigned char i = 0; i < idx; i++)
         {
            // If shifting queenAbove left or right gives queenPos, they share
            // a diagonal.
            if ((prev_mask[i] >> (idx - i)) == queenPos
                || (prev_mask[i] << (idx - i)) == queenPos)
               return false;
         }
      prev_mask[idx] = queenPos;

      return true;
   }
};
```
