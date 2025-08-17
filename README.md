<br>

---

# The C-Script Library (CppS)

> _TypeScript ergonomics. C++ power._

### ⚖️ The STL optimizes for compilers. C-Script optimizes for developers.

#### **Contrasting Priorities**

The STL has served the C++ community well — and C++ is a better language because of it.  
But while the STL is built with compilers in mind, **C-Script** is built with developers in mind.

#### **Introducing C-Script**

The C-Script Library offers ergonomic alternatives to several STL ADTs, **while maintaining seamless interoperability with the STL.**  
You can drop CPPS objects into preexisting code without friction, by design.  

This reflects C-Script’s core philosophy: **"Usability is Utility".**

C-Script isn’t here to replace the STL — it’s here to complement it by prioritizing developer experience where the STL prioritizes performance and generality.  

<br>

     Note for Integration:
     The C-Script Library targets the C++20 standard.

---

### 🔧 C++ doesn’t need training wheels. It needs just better handlebars.

  > #### **TypeScript-Inspired APIs in C++**

The C-Script Library brings TypeScript-inspired ergonomics to C++, with sleek APIs and a priority for developer experience (DX).
It features a header-only suite of ADTs and a lightweight, reimagined String class, all drop-in compatible with legacy STL code.

This compact library offers:

- A **header-only suite** of templated ADTs for zero-hassle integration
- A **featherlight `String` class**, reimagined for both utility and comfort
- A developer-first perspective on C++ programming.

The result is a fluent modern suite that feels natural and powerful without ditching the C++ philosophy.

<br>

---

### ⚙️ How to Use C-Script

C-Script is made up of a set of mostly-independent modules. All features live under the `cpps` namespace (short for **C++ Script**).

To get started with C-Script, follow 2 simple steps.  
    
    (1) Enable String
          - Do this by running the tiny script under /script:  enable_string
          - Supported runtimes include bash, node, and powershell (python3 support is coming).
          
    (2) Then #include as you wish!

#### **What Necessitates "Enabling String"?**
String is not templated like the rest of the class. Therefore, it must be compiled into a usable form before you can work with it. 
There are a handful of ways to achieve that result, but they are not equal. Some have significant performance issues, and others
undermine the pro-DX angle of the C-Script Library altogether.  

In essence, this approach lets C-Script provide you implementations while allowing your environment and compiler actually generate the flavor of binary that _you_ need.
This is optimal, because C-Script doesn't need to provide 180 different precompiled binaries, and _you_ don't need to compile and link anything on your own.
The script handles that.


> #### **Pronunciation Note**
>
> For the curious, `cpps` is pronounced "sips".
> <br>
> Yes, you *could* call it C-P-P-S, but that's like choosing S-Q-L over sequel.
>
> Don't do that yourself, _please._

<br>

---

## Classes

**Array**

- In TypeScript fashion, this is "secretly" a vector.  
  _So yes, I know it’s not technically an array. But TypeScript didn't care — and neither do most devs._

**String**

- This library doesn’t reinvent `std::string`.
- It just adds convenient string utilities _atop_ `std::string`.

Plus: since the library is header-only and super tight, it’s totally reasonable to use `namespace cpps` in your project as well.  
(Because who’s still writing `using namespace std` in 2025?)

**Lists**

- Three flavors:
  - List (singly-linked)
  - DList (doubly-linked & circular)
  - CList (circular & singly-linked)  

**Queues**

- Four styles included:
  - Restricted-Input Queue (cpps default)
    - Removals can happen at the front or back, but insertions are back-only 
  - Classic Queue
    - The typical FIFO model. Front-only removals and Back-only inserts.
  - Deque
    - Double-Ended Queue, meaning both front and back are valid for insert and removal 
  - Restricted-output queue (yeah, it’s weird)
    - A niche type of queue where inserts can happen anywhere, but removals are back-only 

**Stack**

- Like a TS Array, `Array` supports several stack methods...
  - But reducing a cornerstone data structure to a couple of members in another class feels wrong.
- Also, blending Stack and Array creates a messy interface and violates ISP like crazy.  
  *(Why does a stack have iteration and random access?? It shouldn’t.)*


<br>

---

## Future Data Structures

The following have been identified as possible additions to the library in future versions.

| **Class**        | **Why Not Support This Type Now?**                                                                                                                                               | Likelihood of Future Support |
| ---------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------- |
| FixedArray<N,T\> | **_const Array<T\>_** should be pretty sufficient for many cases, so it need not be a priority to write a dedicated **_FixedAray</T>_** right now.                               | low                          |
| Map<Key,Value\>  | I've got to crawl before I ball. I think this should definitely wait until I've gotten all my ducks in a row with development, testing, and docs for the main 4 class categories | high                         |
| Tuple            | I want to finish the core ADTs before I start adding special ones.                                                                                                               | medium                       |
| BitArray         | I think this might be more niche than what is neccessary for this library.                                                                                                       | low ?                        |
