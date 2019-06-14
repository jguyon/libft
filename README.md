# libft

Static library used in my [42 school](<https://en.wikipedia.org/wiki/42_(school)>) C projects.

## Usage

```sh
git clone https://github.com/jguyon/libft.git && cd libft
make # Compile the library
make fclean debug # Recompile with debug flags
make check # Compile and run the tests
make TESTS="test_strlen test_strcpy" check # Run only a subset of tests
make fclean && make all check # Test the release version of the library
echo ".DEFAULT_GOAL := debug" > local.mk # Compile the debug version by default on your local machine
npm install -g node-tap && echo "PROVE = tap" > local.mk # Change the tap output processor for tests
cd /some/neat/new/project \
    && git subtree add --prefix=libft https://github.com/jguyon/libft.git \
    && make -C libft # Use it in another project
```

Further details are available as comments in the source code.
Especially look at `config.mk` for configuring compilation and `includes/*.h` for
how to use the different modules and functions.
