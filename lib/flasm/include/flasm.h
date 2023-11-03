

namespace flasm {

    // My first IR should mix assembly with real code?
    // Honestly, it would be nice if this were always the case...
    // Let's load the entire thing into memory.
    // It will be slower, but more flexibly for future choices.

    // Should I have abstraction for instructions?
    // Or should this be the final stop of the compiler?
    // I would say that we provide abstraction?

    // The goal is to design this in such a way that addition of newly 
    // supported instruction types is easy!
    // The construction should not be specific to any single set of 
    // instructions.

    class Instruction {
    };

    // Should there be a different class for each instruciton type??
    // Maybe....
    class MoveInstruction {
           

    };

    class Operand {
        // Operands have many different types.
        // This will be hard to figure out.
    };
}
