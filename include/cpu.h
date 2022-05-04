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
    byte C : 1; // Carry flag
    byte Z : 1; // Zero flag
    byte I : 1; // Interrupt disable
    byte D : 1; // Decimal flag
    byte B : 1; // break flag
    byte V : 1; // Overflow flag
    byte N : 1; // Negitive flag

    void reset(Memory& mem);

    byte fetchByte(i32& cycles, Memory& mem);
    word fetchWord(i32& cycles, Memory& mem );
    byte readByte(i32& cycles, byte address, Memory& mem);

    void LDASetStatus();
    void execute(i32 cycles, Memory& mem);

    inline void swapBytesInWord(word& data) {
        data = ((data << 8) & 0xff00) | ((data >> 8) & 0x00ff);
    }

    /**
     * handle endianness
     * https://stackoverflow.com/a/8571156
     * @brief Get the Endianness of the platform
     * 
     * @return true if little endian
     * @return false if big endian
     */
    inline bool littleEndian() {
        union {
            u8 c[4];
            u32 i;
        } u;

        u.i = 0x01020304;

        if (0x04 == u.c[0]) {
            // std::cout << "Little endian\n";
            return true;
        } else if (0x01 == u.c[0]) {
            // std::cout << "Big endian\n";
            return false;
        }
        std::cerr << "Platform endianness unknown\nassuming little endian";
        return true;
    }
};