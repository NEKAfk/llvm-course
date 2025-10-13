#include <vector>
#include <functional>

#include "llvm/IR/Module.h"
#include "llvm/IR/Attributes.h"

namespace meta {
    static std::vector<std::string> includes {
        "../SDL/include/sim.h",
        "llvm/ExecutionEngine/ExecutionEngine.h",
        "llvm/ExecutionEngine/GenericValue.h",
        "llvm/IR/IRBuilder.h",
        "llvm/IR/LLVMContext.h",
        "llvm/IR/Module.h",
        "llvm/IR/Verifier.h",
        "llvm/Support/TargetSelect.h",
        "llvm/Support/raw_ostream.h"
    };

    static std::vector<std::string> functions {
        "memset",
        "simFlush",
        "simRand",
        "simPutPixel"
    };

    static std::vector<std::pair<std::string, std::function<llvm::Type*(llvm::LLVMContext&)>>> types{
        {"Int1", llvm::Type::getInt1Ty},
        {"Int8", llvm::Type::getInt8Ty},
        {"Int32", llvm::Type::getInt32Ty},
        {"Int64",llvm::Type::getInt64Ty},
        {"Void", llvm::Type::getVoidTy}
        // Add yours if needed
    };

    static inline std::string boolToStr(bool val) {
        return val ? "true" : "false";
    }

    static inline llvm::Type* getType(llvm::Type* type, bool isPtr) {
        return isPtr ? type->getPointerTo() : type;
    }

    static inline std::string getTypeName(llvm::LLVMContext& context, llvm::Type* type) {
        for (const auto& [name, getter] : meta::types) {
            if (meta::getType(getter(context), type->isPointerTy()) == type) {
                return name + std::string(type->isPointerTy() ? "Ptr" : "") + std::string("Type");
            }
        }
        std::unreachable();
    }
}