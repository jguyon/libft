# libft

Static library to use in [42 school](https://en.wikipedia.org/wiki/42_(school)) C projects.  
It has only been tested on the 64-bit versions of linux and osx, but should work on 32-bit
or other similar \*NIX systems without major changes, I think.

## What the fudge is this?

This is one of the first project we have to complete at 42, the goal being to use it in later ones
and to regularly improve it. We are limited in the external functions we can use on each project,
which is why a significant part of this library is a reimplementation of some parts of the standard libc.

Related reading:
[Don't Reinvent The Wheel, Unless You Plan on Learning More About Wheels](https://blog.codinghorror.com/dont-reinvent-the-wheel-unless-you-plan-on-learning-more-about-wheels/)

## Disclaimer

I'm a student. I'm learning and experimenting and stuff.  
Bad code and bad practices are going to appear here, I hope not too often though.

## Usage

```sh
git clone https://github.com/jguyon/libft.git && cd libft
make # Compile the library
make fclean debug # Recompile with debug flags
make check # Compile and run the tests
make fclean && make release check # Test the release version of the library
echo "DEFAULT_BUILD = debug" > local.mk # Compile the debug version by default on your local machine
npm install -g node-tap && echo "PROVE = tap" > local.mk # Change the tap output processor for tests
cd /some/neat/new/project \
    && git subtree add --prefix=libft https://github.com/jguyon/libft.git \
    && make -C libft # Use it in another project
```

Further details are available as comments in the source code.
Especially look at `config.mk` for configuring compilation and `includes/*.h` for
how to use the different modules and functions.