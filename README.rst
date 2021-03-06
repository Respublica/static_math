``static_math``
###############

``static_math`` is a C++ library dedicated to compile time mathematics.

Compatibility
=============

``static_math`` heavily relies on C++11 features and even on some planned features
that have been confirmed for the next C++ standards provided some compiler already
implements them. So, do not have high expectations, only a few compilers will be
able to compile it.

* Compiles fine with g++ 4.7.0 and later releases.
* Does not compile with Clang (lack of ``constexpr`` for ``std::initializer_list``,
  may compile with libstdc++ instead of libc++).
* Does not compile with MSVC (lack of ``constexpr``).

Principle
=========

``static_math`` makes a heavy use of the C++11 keyword ``constexpr`` to reimplement
a number of existing mathematical functions and some new ones. It also provides
a range of classes (``rational``, ``complex``, etc...) whose functions can be used
at compile time too. The library also contains some common mathematical constants.

Design choices
==============

Compile time library
--------------------

``static_math`` has only been made to be usable at compile time and shall not be
used at runtime. It's still possible to use it at runtime though, but it's not
well advised.

On of the reasons is due to the heavy use of the keyword ``constexpr``: it forces
the functions to be stateless and so to implement a large part of them with deep
recursion. Used at runtime, these functions would be very slow because of the high
number of functions calls that occur for each mathematical computation.

Since the library is only meant to be used at compile time, some choices have
been done to improve usability or convenience over performance. For example, the
rational numbers are simplified after each operation, which could badly alter the
performance in a runtime library.

In order to force the user to think of this library as only a compile-time only
library, somme class functions that could have been implemented (without being
compile-time functions) have simply not been implemented. One of the major examples
is that no class provides any assignment operator since it involves a change of
state.

Intuitive feel
--------------

One of ``static_math``'s aims is to be easy to use. The functions are implemented
so that they can be used in a straightforward way. This implies that the user will
not have to deal with complex metaprogramming tricks - even though some are used in
the implementation -.

This intuitive feel is the one reason why ``static_math`` needs a recent compiler
since the library will need a heavy support for ``constexpr``, ``std::initializer_list``
and variadic templates in order to work fine.

Flexibility
-----------

Some classes such as ``rational`` or ``complex`` make a heavy use of some templates
facilities such as SFINAE in order to gain some flexibility. For example, many
functions won't compile if the parameters given are not of an integral or a
floating point type.

Moreover, if two different types such as ``int`` and ``long long int`` int are passed
to a function that uses them to output an integral type, the bigger of the two
will be chosen for the output::
		
		// Two different types used to represent
		// the same kind of data
		int a = 5;
		long long int b = 100000;
		
		// The bigger of them is used as the output type
		auto c = gcd(a, b); // type is long long int
