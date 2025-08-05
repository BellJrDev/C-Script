<br>

---

# The C-Script Library (CppS)

> _TypeScript ergonomics. C++ power._

### ⚖️ The STL optimizes for compilers. C-Script optimizes for developers.

#### **Contrasting Priorities**

The STL has served the C++ community well — and C++ is a better language because of it.  
But while the STL is built with compilers in mind, **C-Script** is built with developers in mind.

#### **Introducing C-Script**

The C-Script Library offers ergonomic alternatives to several STL ADTs,  
**while maintaining seamless interoperability with the STL.**  
You can drop CPPS objects into legacy code without friction, by design.

This reflects C-Script’s core philosophy: **"Usability is Utility".**

<br>

---

### 🔧 C++ doesn’t need training wheels — just better handlebars.

#### **TypeScript-Inspired APIs in C++**

C-Script brings TypeScript-like expressiveness to modern C++ without the bloat.  
Inspired by the developer experience (DX) of TypeScript, C-Script delivers a cleaner, more intuitive API surface.

This compact library offers:

- A **header-only suite** of templated ADTs for zero-hassle integration
- A **featherlight `String` class**, reimagined for both utility and comfort  
  _(powered by the library’s single compiled `.cpp` file)_

The result is a fluent, modern API that feels natural and powerful — while staying true to the C++ philosophy.

**Yes, C++ doesn’t need training wheels — just better handlebars.**  
That’s the C-Script way.

<br>

---

### ⚙️ How to Use C-Script

C-Script is made up of a set of mostly-independent modules. All features live under the `cpps` namespace (short for **C++ Script**).

Just `#include` and go. No macros, no weird build steps, and no ceremony.

> #### Pronunciation Note
>
> _For the curious, `cpps` is pronounced "sips".
> <br>
> C-P-P-S is an inferior choice, but it is also technically valid._

<br>

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
