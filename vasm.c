#include<stdio.h>
#include <types.h>
#define u8 uint8_t
#define u16 uint16_t
/* demo.c: My first C program on a Linux */
/*
ASSEMBLER
4-bit command
*/


/* [COMMAND]
[R_DEST] [R_SRC]
[IMM]
[FLAGS_DEST_0]
[FLAGS_DEST_1]
[ALLOW_FLAGS_0]
[ALLOW_FLAGS_1]
[DENY_FLAGS_0]
[DENY_FLAGS_1]
*/

/*
[ ] [ ] [ ] [ ] [ ]
[ ] [ ] [ ] [ ] [ ]
[ ] [ ] [x] [ ] [ ]
[ ] [ ] [ ] [ ] [ ]
[ ] [ ] [ ] [ ] [ ]
*/

bool CheckFlags(VCPU &vcpu, COMMAND &command, FIELD &field)
{
    return (((vcpu.Flags & command.DenyFlags) == 0) && (((vcpu.Flags & command.AllowFlags) != 0) || (vcpu.Flags == 0)) )
}

FLAG_TYPE ResultToFlag(FLAG_TYPE V, FLAG_TYPE Mask, FLAG_TYPE F)
{
    FLAG_TYPE f2 = (F | Mask) ^ Mask;
    
    if (V != 0)
        f2 = f2 | Mask;
        
    return f2;
}

int lfMOV_RR(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    vcpu.Registers[r_dest] = vcpu.Registers[r_src]
        
    return 0;
}


int lfMOV_RI(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    vcpu.Registers[r_dest] = command.Imm;
        
    return 0;
}


int lfADD_RR(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    vcpu.Registers[r_dest] += vcpu.Registers[r_src]
    
    return 0;
}

int lfADD_RI(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    vcpu.Registers[r_dest] += command.Imm;
        
    return 0;
}

int lfSUB_RR(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    vcpu.Registers[r_dest] -= vcpu.Registers[r_src]
    
    return 0;
}

int lfSUB_RI(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    vcpu.Registers[r_dest] -= command.Imm;
        
    return 0;
}

int lfINC_R(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    vcpu.Registers[r_dest] += 1;
        
    return 0;
}

int lfDEC_R(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    vcpu.Registers[r_dest] -= 1;
        
    return 0;
}

int lfEQUALS_RR(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    int r = vcpu.Registers[r_dest] == vcpu.Registers[r_src];
    vcpu.Flags = ResultToFlags(r, command.FlagsDest, vcpu.Flags);
}

int lfEQUALS_RI(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    int r = vcpu.Registers[r_dest] == vcpu.Registers[r_src];
    vcpu.Flags = ResultToFlags(r, command.FlagsDest, vcpu.Flags);
}

int lfNEQUALS_RR(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    int r = vcpu.Registers[r_dest] != vcpu.Registers[r_src];
    vcpu.Flags = ResultToFlags(r, command.FlagsDest, vcpu.Flags);
}

int lfNEQUALS_RI(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    int r = vcpu.Registers[r_dest] != vcpu.Registers[r_src];
    vcpu.Flags = ResultToFlags(r, command.FlagsDest, vcpu.Flags);
}

int lfGREATER_RR(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    int r = vcpu.Registers[r_dest] > vcpu.Registers[r_src];
    vcpu.Flags = ResultToFlags(r, command.FlagsDest, vcpu.Flags);
}

int lfGREATER_RI(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    int r = vcpu.Registers[r_dest] > vcpu.Registers[r_src];
    vcpu.Flags = ResultToFlags(r, command.FlagsDest, vcpu.Flags);
}

int lfLESS_RR(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    int r = vcpu.Registers[r_dest] < vcpu.Registers[r_src];
    vcpu.Flags = ResultToFlags(r, command.FlagsDest, vcpu.Flags);
}

int lfLESS_RI(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    r_dest = vcpu.Registers & 0x0F;
    r_src = (vcpu.Registers >> 4) & 0x0F;
    int r = vcpu.Registers[r_dest] < vcpu.Registers[r_src];
    vcpu.Flags = ResultToFlags(r, command.FlagsDest, vcpu.Flags);
}

int lfEAT(VCPU &vcpu, COMMAND &command, FIELD &field, FIELD &dest_field)
{
    vcpu.Action = actEAT;
}


int Step(VCPU * vcpu)
{
    cmd = *vcpu.Command;
    switch (cmd):
    {
        case cmdNOP:
            break;
        
        case cmdMOV_RR:
            
    }
}

/* object FIELD
width
height
cells:



*/

#define 

int main(void)
{
    printf("Hello! This is a test prgoram.\n");
    return 0;
}
