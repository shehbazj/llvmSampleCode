#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/CFGPrinter.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

using namespace llvm;

namespace {
  struct Hello : public FunctionPass {
    static char ID;
    Hello() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      errs() << "Hello: ";
      errs().write_escaped(F.getName()) << '\n';
	//F.viewCFG();
	int fd = open("myfile", O_RDWR | O_CREAT);
	if(fd < 0){
		assert(0);
	}
	raw_fd_ostream File(fd, false) ;
	WriteGraph(File, (const llvm::Function*) &F);
      return false;
    }
  };
}

char Hello::ID = 0;
static RegisterPass<Hello> X("hello", "Hello World Pass", false, false);
