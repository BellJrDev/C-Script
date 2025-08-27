## 🔧 C++ doesn’t need training wheels. It just needs better handlebars.
When it comes to fine-grained development control, performance, and raw power, C++ dominates the competition.  
However, there is one area in which C++ has consistently fallen short: developer experience (DX).

While C++ has undeniable strengths, it also has:
- poor ergonomics
- unwieldy boilerplate
- excessive verbosity
- utilitarian APIs
The result is a good language that can unfortunately be a little painful to work with.

<br>

## Introducing C-Script
  > #### **TypeScript-Inspired APIs in C++**
The C-Script library adorns C++ with ergonomics inspired by TypeScript.

The core philosophy is simple: "Usability ***is*** utility."  
C-Script refines and reimagines cornerstone ADTs by offering sleek interfaces that prioritize a good DX. 
It blends compiled efficiency with header flexibility, preserving the high performance that C++ is known for.
Additionally, the library’s components are fully interoperable with STL containers and algorithms, for seamless integration. The result is that developers can drop any C-Script object into pre-existing C++20 code without friction.

<br>

**C-Script Offers:**  
- A versatile collection of robust, generic ADTs
- A powerful String class, reimagined for both utility and comfort
- Convenient drop-in compatibility with the C++ Standard Library – including the STL
- A developer-first perspective on C++ programming
<br>

*C-Script is here to complement the Standard Library and enhance C++ with APIs that make DX the #1 priority.*

<br>

     ⚠️ **Requires C++20 or Newer**
     The C-Script Library makes use of modern C++20 features (e.g. concepts). It will not compile with older standards. 
---

## ⚙️ How to Use C-Script
All features of the C-Script library live under the `cpps` namespace (short for **C++ Script**).
To get started with C-Script, follow 2 simple steps.  
    
    (1) Enable C-Script
          - Run the script under /script: `enable_cpps`
          	- Supported runtimes: bash, node, python3, powershell.
          	- Each script is fully transparent and simply compiles the `String`, `Array`, and `Queue` implementations under the hood.  
          
    (2) Then #include as you wish!
          - Components use the include pattern, `<cpps/COMPONENT>` (e.g. `<cpps/String>`)


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
