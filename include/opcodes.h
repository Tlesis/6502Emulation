#pragma once

// Load A register
#define LDA_IM 0xA9
#define LDA_ZP 0xA5
#define LDA_ZPX 0xB5
#define LDA_ABS 0xAD
#define LDA_ABSX 0xBD
#define LDA_ABSY 0xB9
#define LDA_INDX 0xA1

// Jump to Sub-Routine
#define JSR 0x20

// Load X register
#define LDX_IM 0xA2
#define LDX_ZP 0xA6
#define LDX_ZPY 0xB6
#define LDX_ABS 0xAE
#define LDX_ABSY 0xBE

// Load Y register
#define LDY_IM 0xA0
#define LDY_ZP 0xA4
#define LDY_ZPX 0xB4
#define LDY_ABS 0xAC
#define LDY_ABSX 0xBC

// Store Accumulator
#define STA_ZP 0x85
#define STA_ZPX 0x95
#define STA_ABS 0x8D
#define STA_ABSX 0x9D
#define STA_ABSY 0x99
#define STA_INDX 0x81
#define STA_INDY 0x91

// Store X
#define STX_ZP 0x86
#define STX_ZPY 0x96
#define STX_ABS 0x8E

// Store Y
#define STY_ZP 0x84
#define STY_ZPX 0x94
#define STY_ABS 0x8C

// transfer stack pointer to X
#define TSX 0xBA

// transfer X to stack pointer
#define TXS 0x9A

// push accumulator
#define PHA 0x48

// pull accumulator
#define PLA 0x68

// push processor status register (with break flag set)
#define PHP 0x08

// pull processor status register
#define PLP 0x28

// Jump
#define JMP_ABS 0x4C
#define JMP_IND 0x6C
#define JSR 0x20
#define RTS 0x60

//Logical Ops

// AND
#define AND_IM 0x29
#define AND_ZP 0x25
#define AND_ZPX 0x35
#define AND_ABS 0x2D
#define AND_ABSX 0x3D
#define AND_ABSY 0x39
#define AND_INDX 0x21
#define AND_INDY 0x31

// OR
#define ORA_IM 0x09
#define ORA_ZP 0x05
#define ORA_ZPX 0x15
#define ORA_ABS 0x0D
#define ORA_ABSX 0x1D
#define ORA_ABSY 0x19
#define ORA_INDX 0x01
#define ORA_INDY 0x11

// Ex-OR
#define EOR_IM 0x49
#define EOR_ZP  0x45
#define EOR_ZPX 0x55
#define EOR_ABS 0x4D
#define EOR_ABSX 0x5D
#define EOR_ABSY 0x59
#define EOR_INDX 0x41
#define EOR_INDY 0x51

// BIT
#define BIT_ZP 0x24
#define BIT_ABS 0x2C

// Transfer Registers
#define TAX 0xAA
#define TAY 0xA8
#define TXA 0x8A
#define TYA 0x98

// Increments/Decrements
#define INX 0xE8
#define INY 0xC8
#define DEY 0x88
#define DEX 0xCA
#define DEC_ZP 0xC6
#define DEC_ZPX 0xD6
#define DEC_ABS 0xCE
#define DEC_ABSX 0xDE
#define INC_ZP 0xE6
#define INC_ZPX 0xF6
#define INC_ABS 0xEE
#define INC_ABSX 0xFE

// branches
#define BEQ 0xF0
#define BNE 0xD0
#define BCS 0xB0
#define BCC 0x90
#define BMI 0x30
#define BPL 0x10
#define BVC 0x50
#define BVS 0x70

// status flag changes
#define CLC 0x18
#define SEC 0x38
#define CLD 0xD8
#define SED 0xF8
#define CLI 0x58
#define SEI 0x78
#define CLV 0xB8

// Arithmetic
#define ADC 0x69
#define ADC_ZP 0x65
#define ADC_ZPX 0x75
#define ADC_ABS 0x6D
#define ADC_ABSX 0x7D
#define ADC_ABSY 0x79
#define ADC_INDX 0x61
#define ADC_INDY 0x71

#define SBC 0xE9
#define SBC_ABS 0xED
#define SBC_ZP 0xE5
#define SBC_ZPX 0xF5
#define SBC_ABSX 0xFD
#define SBC_ABSY 0xF9
#define SBC_INDX 0xE1
#define SBC_INDY 0xF1

// Register Comparison
#define CMP 0xC9
#define CMP_ZP 0xC5
#define CMP_ZPX 0xD5
#define CMP_ABS 0xCD
#define CMP_ABSX 0xDD
#define CMP_ABSY 0xD9
#define CMP_INDX 0xC1
#define CMP_INDY 0xD1

#define CPX 0xE0
#define CPY 0xC0
#define CPX_ZP 0xE4
#define CPY_ZP 0xC4
#define CPX_ABS 0xEC
#define CPY_ABS 0xCC

// shifts
#define ASL 0x0A
#define ASL_ZP 0x06
#define ASL_ZPX 0x16
#define ASL_ABS 0x0E
#define ASL_ABSX 0x1E

#define LSR 0x4A
#define LSR_ZP 0x46
#define LSR_ZPX 0x56
#define LSR_ABS 0x4E
#define LSR_ABSX 0x5E

#define ROL 0x2A
#define ROL_ZP 0x26
#define ROL_ZPX 0x36
#define ROL_ABS 0x2E
#define ROL_ABSX 0x3E

#define ROR 0x6A
#define ROR_ZP 0x66
#define ROR_ZPX 0x76
#define ROR_ABS 0x6E
#define ROR_ABSX 0x7E

// misc
#define NOP 0xEA
#define BRK 0x00
#define RTI 0x40