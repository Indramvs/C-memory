````markdown
# 🧠 Low-Level Memory Management in C

This repository demonstrates two fundamental low-level memory operations in C:

1. A **custom memory allocator** that mimics `malloc()` and `free()`
2. A **custom memory copy** function similar to `memcpy()`

These projects are built for **educational purposes**, offering a deeper understanding of how C handles dynamic memory and byte-wise memory operations internally.

---

## 📁 Files

| File Name      | Description                                    |
|----------------|------------------------------------------------|
| `mymalloc.c`   | Custom memory allocator using `sbrk()`         |
| `my_memcopy.c` | Byte-wise implementation of `memcpy()`         |

---

## 1️⃣ Custom Memory Allocator (`mymalloc.c`)

### 🔧 How It Works

This program mimics the behavior of the C Standard Library’s `malloc()` and `free()` using a **linked list of memory blocks** and the `sbrk()` system call.

### ✅ Features:
- Allocates memory dynamically
- Tracks free blocks for reuse
- Stores metadata before each block
- Detects double-free issues

### 🧩 Structure

```c
struct block_metadata {
    size_t size;
    struct block_metadata* next;
    bool free;
};
````

### 🔍 Example Usage

```c
int* arr = (int*)malloc(8 * sizeof(int));
for (int i = 0; i < 8; i++) arr[i] = i;
free(arr);
```

### 🚫 Limitations

* No block splitting or merging
* No thread safety
* Memory is not released to the OS

---

## 2️⃣ Custom Memory Copy (`my_memcopy.c`)

### 🔧 How It Works

This function replicates `memcpy()` by copying memory byte-by-byte using **void pointers** and **casting to `char*`** for generalization.

### ✅ Features:

* Works with any data type
* Byte-level shallow copy
* Simple and portable logic

### 🔍 Example Usage

```c
int src[] = {1, 2, 3, 4}, dest[5] = {};
my_memcopy(dest, src, sizeof(src));  // Output: 1 2 3 4

char str1[] = {'a','b','c','d'}, str2[5] = {};
my_memcopy(str2, str1, sizeof(str1));  // Output: a b c d
```

### 🚫 Limitations

* No deep copy (not for pointer-based structs)
* No performance optimizations
* No bounds checking

---

## 🧠 Learning Objectives

* Understand the inner workings of `malloc()` and `free()`
* Use `sbrk()` to manage memory manually
* Learn how to copy memory using pointer arithmetic
* Explore shallow vs deep copy
* Practice with low-level memory access and management in C

---

## 📌 Build & Run

```bash
# Compile and run memory allocator
gcc mymalloc.c -o allocator
./allocator

# Compile and run memory copy
gcc my_memcopy.c -o memcopy
./memcopy
```

---

## ✅ Sample Output

```
# From memory copy program:
1 2 3 4
a b c d

# From memory allocator program:
addr[0]: 0
addr[1]: 1
...
addr[7]: 7
```

---

## ⚠️ Disclaimer

These implementations are for **educational purposes only**. They are not production-ready and lack many of the safety, performance, and system integration features required in real-world applications.

---

## 📚 References

* [man sbrk](https://man7.org/linux/man-pages/man2/sbrk.2.html)
* [C Library memcpy()](https://en.cppreference.com/w/c/string/byte/memcpy)
* Operating systems & system programming courses

---

## 🧑‍💻 Author

**Indra MVS**
[GitHub Profile](https://github.com/Indramvs)
