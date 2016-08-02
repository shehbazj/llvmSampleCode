# llvmSampleCode

To run the code, replace Hello.c code in the folder llvm/lib/Transforms/Hello/ with any of the files in this folder.
Once that is done, run the following steps:

cd llvm/build
make
opt ../lib/Hello.so -hello < hello.bc > /dev/null

where hello.bc is bitcode for existing program that you want to analyze, generated as follows:

clang -O3 -emit-llvm hello.c -c -o hello.bc

