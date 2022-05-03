#pragma once

#include "types.h"

#define MAX_MEM 1024 * 64

struct Memory {
    byte Data[MAX_MEM];

    inline void initialise() {
        for (u32 i = 0; i < MAX_MEM; i++) {
            Data[i] = 0;
        }
    }

    /** read 1 byte */
	inline byte operator[]( u32 Address ) const {
		// assert here Address is < MAX_MEM
		return Data[Address];
	}

	/** write 1 byte */
	inline byte& operator[]( u32 Address ) {
		// assert here Address is < MAX_MEM
		return Data[Address];
	}

	/** write 2 bytes */
	inline void writeWord(word Value, u32 address, u32& cycles )
	{
		Data[address]		= Value & 0xFF;
		Data[address + 1]   = (Value >> 8);
		cycles -= 2;
	}
};