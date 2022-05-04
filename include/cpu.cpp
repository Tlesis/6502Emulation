#include "cpu.h"
#include "opcodes.h"

void Cpu::reset(Memory& mem) {
    PC = 0xFFFC;
    SP = 0x0100;
    D = 0; // Clear Decimal flag

    /** clear A, X and Y registers */
    A = 0;
    X = 0;
    Y = 0;
    mem.initialise();
}

byte Cpu::fetchByte(i32& cycles, Memory& mem) {
    byte data = mem[PC];
    PC++;
    cycles--;
    return data;
}

word Cpu::fetchWord(i32& cycles, Memory& mem ) {
	// 6502 is little endian
	word Data = mem[PC];
	PC++;

	Data |= (mem[PC] << 8 );
	PC++;

	cycles -= 2;

    if (!littleEndian()) {
	    swapBytesInWord(Data);
    }

	return Data;
}

byte Cpu::readByte(i32& cycles, byte address, Memory& mem) {
    cycles--;
    return mem[address];
}

void Cpu::LDASetStatus() {
    Z = (A == 0);
    N = (A & 0b10000000) > 0;
}

void Cpu::execute(i32 cycles, Memory& mem) {
    while (cycles > 0) {
        byte ins = fetchByte(cycles, mem);

        switch (ins) {
            case LDA_IM:
            {
                A =  fetchByte(cycles, mem);
                LDASetStatus();
            } break;

            case LDA_ZP:
            {
                byte zeroPageAddress =
                    fetchByte(cycles, mem);
                A = readByte(cycles, zeroPageAddress, mem); 
                LDASetStatus();
            } break;

            case LDA_ZPX:
            {
                byte zeroPageAddress =
                    fetchByte(cycles, mem);
                zeroPageAddress += X;
                cycles--;
                A = readByte(cycles, zeroPageAddress, mem); 
                LDASetStatus();
            } break;

            case LDA_ABS:
            {
                
            }

            case JSR:
            {
                word subAddr = fetchWord(cycles, mem);
                mem.writeWord(PC - 1, SP, cycles);
                SP += 2;
                cycles--;
                PC = subAddr;
                cycles--;
            } break;

            default:
                std::cerr << "Instruction not handled: " << ins << std::endl;
                std::exit(1);
                break;
        }
    }
}