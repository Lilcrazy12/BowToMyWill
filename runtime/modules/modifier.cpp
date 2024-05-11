#include "modifier.hpp"
/** 
    @brief identifiers has this struct but modifier
            since size is less than address
            and for more flexibility
*/

typedef struct {
    /** 
        @brief writable
            ex override in methods
    */
    bool overwrite : 1;

    /** 
        @brief prioritized than read below
            ex const in variables
    */
    bool constant : 1;

    // within a function
    bool function_read : 1;
    bool function_write : 1;

    bool nested_function_read : 1;
    bool nested_function_write : 1;

    bool another_function_read : 1;
    bool another_function_write : 1;

    // inside the namespace
    bool namespace_read : 1;
    bool namespace_write : 1;

    // inside the nested namespace
    bool nested_namespace_read : 1;
    bool nested_namespace_write : 1;

    // exported destination
    bool another_namespace_read : 1;
    bool another_namespace_write : 1;

    bool class_read : 1;
    bool class_write : 1;

    bool nested_class_read : 1;
    bool nested_class_write : 1;

    bool deriving_class_read : 1;
    bool deriving_class_write : 1;

    // ex friend in modern
    bool another_class_read : 1;
    bool another_class_write : 1;

    // within a file
    bool file_read : 1;
    bool file_write : 1;

    // exported destination
    bool another_file_read : 1;
    bool another_file_write : 1;

    // can be acccessed from anywhere in a program
    bool program_read : 1;
    bool program_write : 1;

} ModifierBitMap;

class Modifier {
public:
    Modifier() {
        memset(&bitmap, 0, sizeof(ModifierBitMap));
    }

    void setOverwritable() { bitmap.overwritable = true; }
    void setConstant() { bitmap.constant = true; }
    void setFunctionRead() { bitmap.function_read = true; }
    void setFunctionWrite() { bitmap.function_write = true; }
    void setNamespaceRead() { bitmap.namespace_read = true; }
    void setNamespaceWrite() { bitmap.namespace_write = true; }
    void setNestedNamespaceRead() { bitmap.nested_namespace_read = true; }
    void setNestedNamespaceWrite() { bitmap.nested_namespace_write = true; }
    void setClassRead() { bitmap.class_read = true; }
    void setClassWrite() { bitmap.class_write = true; }
    void setNestedClassRead() { bitmap.nested_class_read = true; }
    void setNestedClassWrite() { bitmap.nested_class_write = true; }
    void setDerivingClassRead() { bitmap.deriving_class_read = true; }
    void setDerivingClassWrite() { bitmap.deriving_class_write = true; }

    bool isOverwritable() const { return bitmap.overwritable; }
    bool isConstant() const { return bitmap.constant; }
    bool isFunctionRead() const { return bitmap.function_read; }
    bool isFunctionWrite() const { return bitmap.function_write; }
    bool isNamespaceRead() const { return bitmap.namespace_read; }
    bool isNamespaceWrite() const { return bitmap.namespace_write; }
    bool isNestedNamespaceRead() const { return bitmap.nested_namespace_read; }
    bool isNestedNamespaceWrite() const { return bitmap.nested_namespace_write; }
    bool isClassRead() const { return bitmap.class_read; }
    bool isClassWrite() const { return bitmap.class_write; }
    bool isNestedClassRead() const { return bitmap.nested_class_read; }
    bool isNestedClassWrite() const { return bitmap.nested_class_write; }
    bool isDerivingClassRead() const { return bitmap.deriving_class_read; }
    bool isDerivingClassWrite() const { return bitmap.deriving_class_write; }

private:
    ModifierBitMap bitmap;
};
