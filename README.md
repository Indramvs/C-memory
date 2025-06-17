# C-memory

````markdown
# 🧠 Simple Custom Memory Allocator in C

This project demonstrates a **basic implementation of `malloc()` and `free()`** using low-level system calls like `sbrk()`. It serves as an educational tool to understand how dynamic memory allocation can be manually managed in C.

---

## 📁 Files

- `mymalloc.c`: Contains the full implementation of custom `malloc` and `free`, along with a test example.

---

## 🔧 How It Works

This program mimics the behavior of the C Standard Library’s dynamic memory allocator using a **linked list of metadata blocks**.

### ✅ Features:
- Allocates memory using `sbrk()`
- Reuses previously freed blocks if large enough
- Maintains a simple metadata structure to track block size, status, and links
- Detects double frees with `assert()`

---

## 📄 Structure of a Memory Block

Each allocated block contains:
```c
struct block_metadata {
    size_t size;                  // Size of the user memory
    struct block_metadata* next; // Pointer to next block
    bool free;                    // Is this block free?
};
````

User memory begins right after this metadata in memory.

---

## 🔍 Example Usage

```c
int* addr = (int*)malloc(8 * sizeof(int));
for (int i = 0; i < 8; i++) {
    addr[i] = i;
    printf("addr[%d]: %d\n", i, addr[i]);
}
free(addr);
```

---

## 🚫 Limitations

* No memory splitting (if block is larger than needed)
* No coalescing (adjacent free blocks aren't merged)
* No thread safety
* Memory is never actually returned to the OS

---

## 🧠 Learning Objectives

* Understand low-level memory management
* Explore how malloc/free can be implemented manually
* Study metadata handling and pointer arithmetic in C

---

## ⚠️ Disclaimer

This is **not production-safe** and is meant for **learning purposes only**. For real applications, always use the system-provided memory management.

---

## 📚 References

* [man sbrk](https://man7.org/linux/man-pages/man2/sbrk.2.html)
* CS courses on operating systems and memory management

---

## 📌 To Run

```bash
gcc main.c -o allocator
./allocator
```

---

## 🧑‍💻 Author

Indra MVS
[GitHub Profile](https://github.com/Indramvs)

