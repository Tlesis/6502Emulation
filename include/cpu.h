#pragma once

#include <iostream>
#include <cstdlib>

#include "types.h"
#include "memory.h"

// TODO: Remove
#include "opcodes.h"

struct Cpu {
    word PC;    // Program Counter
    word SP;    // Stack Pointed

    byte A, X, Y;   // Registers

    /** Status Flags */ 
    byte C : 1; //
    byte Z : 1; //
    byte I : 1; //
    byte D : 1; //
    byte B : 1; //
    byte V : 1; //
    byte N : 1; // Negitive flag

    void reset(Memory& mem);

    byte fetchByte(u32& cycles, Memory& mem);
    word fetchWord(u32& cycles, Memory& mem );
    byte readByte(u32& cycles, byte address, Memory& mem);

    void LDASetStatus();
    void execute(u32 cycles, Memory& mem);
};