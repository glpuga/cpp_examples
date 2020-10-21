
== Structure of a program. Header files, source files, object files.

- What's a header file?
- What's an translation unit?
- What's an object file?
- How does the program get from a collection of header and source files to an executable file?
- What's the role of the compiler during build? What are the inputs? what are the outputs?
- What's the role of the linker during build? What are the inputs? what are the outputs?
- What is the preprocessor?
- At what point during build does the preprocessor act on the sources?
- How do you manually build a file from source file to executable using gcc on a terminal? How does it change if you have more than one source file?

== Expressions and statements. Control flow.

- How does the `while` loop work? when do you use it?
- How does the `do-while` loop work? When do you use it?
- How does the `for` loop work? when do you use it? What's the scope of the index variable?
- What's the `for-range` loop?
- What advantages does `for-range` have over the simpler `for` loop?
- What datatypes admit iterating on them using a `for-range` loop?

== Numeric datatypes

- What's a `bool`? What values does it take?
- What's an `int`? how wide is a default integer?
- how can you specify the width of the word in a portable way?
- What are the fields in a floating point variable?
- How many significant digits is a float expected to hold? and a double?
- What does it mean for a floating point to store "N significant digits"?

== Strings

- What's a string literal? 
- What's a zero terminated string?
- What's an std::string? how does it differ from a legacy zero-terminated string?
- What's the "short string optimization"?

== Composite data types. Class, Structs and unions.

- What's a class? What's a structure? What's a union?
- What are the similarities and differences between `class` and `struct`?
- Can a `class` inherit? Can a `struct` inherit?
- What kinds of members can a `class` have?
- What do the access specifiers `public`, `private`, `protected` do?
- Can a `struct` have access specifiers?
- What's does `const` mean in a method declaration within a class?
- What's `this`?
- What's does `static` do in member variables declarations?
- What's does `static` do in member function declarations?
- What's limitations do `static` member functions have?
- Why can't `static` member functions use `this`?
- When are static data members initialized? When are they destroyed?
- What's called a static method? and an instance method?
- How do you call a static method? and an instance method?
- Where are `static` data members allocated in memory?
- What are `friend` methods?
- What are `friend` classes?

== Enum class vs enum.

- What's an `enum`? In what name scope are the constants created?
- What's a `class enum`? In what name scope are the constants created?
- How does `enum` compare against `enum class`?

== References and pointers. Primitive arrays.

- What's a raw pointer?
- How do you create a raw pointer? How do you release a raw pointer?
- What's a reference? How do you create a reference?
- What are the similarities and differences between a reference and a pointer?
- What's a dangling reference? provide a code example that creates a dangling reference.
- what's "void"? What can you do with it?
- What are the advantages of passing parameters to functions by `const T &`?
- What's the rule of thumb to determine when to pass parameters to functions by `const T &`?

== Const and constexpr. Volatile.

- What does it mean to declare a variable as `const`?
- Is `const` a build-time or run-time feature?
- Where is a `const` variables stored?
- Can I create a `const` variable that holds an information piece the user provided during execution? (i.e: through the terminal).
- What does it mean to declare a variable as `constexpr`?
- Is `constexpr` a build-time or run-time feature?
- Where are `constexpr` variables stored?
- Can I create a `constexpr` variable that holds an information piece the user provided during execution? (i.e: through the terminal).
- What does it mean for a function to be `constexpr`?
- What limitations does a `constexpr` function has?
- What does `volatile` do? Explain the difference in the generated assembler code in https://godbolt.org/z/sac448 .
- In a class-member function, what's the difference between `int f() const;` and `const int f();`?
- What's the problem with declaring the by-value return type of a function as `const`, such as in `const std::string f();`?

== “Auto” statement. Uniform initialization. 

- What does the `auto` statement does?
- What are the advantages of using `auto`?
- How does `auto` interact with the uniform initializer `{}`?

== Namespaces. Anonymous namespaces.

- What's a namespace?
- What do you use a namespace for?
- What namespaces do you know?
- What's an anonymous namespace? What is it for?
- What does the `using namespace ...` clause do? What problem can it bring?

== Life scope of variables: automatic, global, dynamic.

- What's the life scope of a variable?
- What's the scope of a global variable? where is it stored?
- What's an automatic variable? Where is it stored?
- What's the scope of a variable in dynamic memory? where is it stored?

== Construction and destruction:

- What is a `class` constructor?
- What's a user-defined constructor?
- What happens if there are no user-defined constructors in a class? Are there no constructors at all in this case?
- Why doesn't this build? https://godbolt.org/z/nb6G45
- How many constructors can there be in a class?
- How does a constructor report an error?
- What's a `class` destructor?
- What's user-defined constructor?
- what happens if there are no-user defined constructors in a class?
- How does a destructor report an error?
- Are constructors and destructors functions? how do they differ from regular functions?
- What does the `explicit` keyword do? Provide examples.
- What's a class? and object? and instance?
- What's direct initialization of an object?
- What's assignment initialization of an object?
- Explain each constructor/destructor call caused by the sentence in line 35 here: https://godbolt.org/z/5hPd6o .
- Consider this piece of code: https://godbolt.org/z/PeW6Tv . What's the order in which objects `base_va_`, `base_vb_`, `derived_va_`, `derived_vb`, and the constructors of `Base` and `Derived` get executed? What the destruction order for the same items?
- What construction/destruction order do member variables have within a class?
- What's the constructor initialization list is? how listing order relate to member initialization order?
- What's the difference between initializing something in the initialization list, and initializing it within the body of the constructor?
- How does the "-fno-elide-constructors" argument affect the outcome in https://godbolt.org/z/5hPd6o ?
- What's a delegating constructor?

== Overloading

- What's funcition overloading?
- What's the function/method signature? What's in and what's out?
- How does the compiler choose what overload to use for a particular call of an overloaded funciton?
- What's the difference between "int value();" and "int value() const;"? Can you have both in a class?
- What's operator overloading?
- What operators can be overloaded?
- When should you use operator overloading?
- what's the signature to overload the operator "+" when declared as a member method?
- what's the signature to overload the operator "+" when declared as a non-member method?
- what's the signature to overload the operator "*=" when declared as a member method?
- what's the signature to overload the operator "*=" when declared as a non-member method?

== Move semantics

- What's an rvalue? provide examples.
- What's an lvalue? provide examples.
- How does `std::move()` move an object into another, if it can't access the target?  
- What is a copy constructor? What's the signature?
- What is a move constructor? What's the signature?
- What is a copy assingment? What's the signature?
- What is a move assignment? What's the signature?
- Consider "const std::string value();" How does `const` prevent using move semantics?
- What's the "rule of three"?
- What's the "rule of five"?
- Under what circumstances are default copy operations created by the compiler?
- Under what circumstances are default move operations created by the compiler?

== Containers

- What's an `std::array`?
- What's an `std::vector`?
- What's an `std::list`?
- What's an `std::map`? What's an `std::unordered_map`?
- What's an `std::set`? What's an `std::unordered_set`?
- What's the difference between ordered and unordered containers?
- What's the difference between `std::list` and `std::forward_list`?
- How does an `std::array` compare to an `std::vector`? when should you use each?
- Under what circumstances does the `std::vector` reallocate its buffer?
- What does `reserve()` do in an `std::vector`?
- What is the difference between `size()` and `capacity()` in `std::vector`?
- How do you release the resources used by an `std::vector`?
- What's the performance penalty of an insertion in an `std::vector`?
- What's the performance penalty of a removal from an `std::vector`?
- What's the performance penalty of an insertion in an `std::list`?
- What's the performance penalty of a removal from an `std::list`?
- What's the difference between `emplace` and `insert`, when both operations are provided by a container?
- What's iterator invalidation?
- What operations invalidate iterators on an `std::array`?
- What operations invalidate iterators on an `std::vector`?
- What operations invalidate iterators on an `std::list`?

