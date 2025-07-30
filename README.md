<br>

---

# C-Script

> _TypeScript ergonomics. C++ power._

### _C++ doesn’t need training wheels — just new handlebars_

The STL optimizes C++ for compilers. Now C-Script is optimizing for developers.

C-Script brings Typescript expressiveness to the C++ development experience (DX) without bloat.  
This lightweight, **header-only** library offers ergonomic data structures and fluent APIs that feel modern, intuitive, and powerful.

Whether you're building high-performance systems or quick prototypes, C-Script provides C++ power — without its paperwork.

<br>

### 🧠 Namespace

All features live under the `cpps` namespace (short for **C++ Script**).  
Just `#include` and go. No macros, no weird build steps, and no ceremony.

> #### Pronunciation Note
>
> _For the curious, `cpps` is pronounced "sips".
> <br>
> C-P-P-S is inferior, but nonetheless a valid choice._ > <br>

---

## Classes

**Array**

- In TypeScript fashion, this is actually a vector... "Array" just rolls off the tongue better.  
  _Yes, I know it’s not technically an array. But the TS devs didn’t care — and neither do I._

**Queues**

- Four styles included:
  - Restricted-input (default)
  - Classic (FIFO, theoretical queue)
  - Deque (double-ended)
  - Restricted-output (yeah, it’s weird)

**Stack**

- Like a TS Array, `Array` supports several stack methods...
  - But reducing a cornerstone data structure to a couple of members in another class feels wrong.
- Also, blending Stack and Array creates a messy interface and violates ISP like crazy.  
  (Why does a stack have iteration and random access?? It shouldn’t.)

**String**

- This library doesn’t reinvent `std::string`.
- It just adds convenient string utilities _atop_ `std::string`.

Plus: since the library is header-only and super tight, it’s totally reasonable to use `namespace cpps` in your project as well.  
(Because who’s still writing `using namespace std` in 2025?)

<br>

---

## Future Data Structures

The following have been identified as possible additions to the library in future versions.

| **Class**        | **Why Not Support This Type Now?**                                                                                                                                               | Likelihood of Future Support |
| ---------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------- |
| FixedArray<N,T\> | **_const Array<T\>_** should be pretty sufficient for many cases, so it need not be a priority to write a dedicated **_FixedAray</T>_** right now.                               | high                         |
| Map<Key,Value\>  | I've got to crawl before I ball. I think this should definitely wait until I've gotten all my ducks in a row with development, testing, and docs for the main 4 class categories | high                         |
