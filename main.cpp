#include "include/cpu.h"

int main() {
    Memory mem;
    Cpu cpu;

    cpu.reset(mem);
    // ~~~~~~~~~~~~~~~
    mem[0xFFFC] = INS_JSR;
    mem[0xFFFD] = 0x42;
    mem[0xFFFE] = 0x42;
    mem[0x4242] = LDA_IM;
    mem[0x4243] = 0x80;
    // ~~~~~~~~~~~~~~~
    cpu.execute(9, mem);

    std::cout << cpu.A << std::endl;
}