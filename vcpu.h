#include <types.h>

#define FLAG_COUNT 8
#define FLAG_TYPE int
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

typedef struct COMMAND {
    u8 Command;
    u8 Registers;
    u8 Imm;
    u8 Mem;
    u8 FlagDest;
    u8 AllowFlags;
    u8 DenyFlags;
}

typedef struct FIELD {
}

enum COMMANDS
{
    cmdNOP,
    
    cmdMOV_RR,
    cmdMOV_RI,
    
    cmdADD_RR,
    cmdADD_RI,
    
    cmdSUB_RR,
    cmdSUB_RI,
    
    cmdINC_R,
    cmdDEC_R,
    
    cmdEQUALS_RR,
    cmdEQUALS_RI,
    
    cmdNEQUALS_RR,
    cmdNEQUALS_RI,
    
    cmdGREATER_RR,
    cmdGREATER_RI,
    
    cmdLESS_RR,
    cmdLESS_RI,
    
    cmdEAT,
    cmdMOVE_FORWARD,
    cmdMOVE_BACKWARD,
    cmdTURN_LEFT,
    cmdTURN_RIGHT,
    cmdWAIT,
    
    cmdDETECT_FOOD_LEFT,
    cmdDETECT_FOOD_RIGHT,
    cmdDETECT_FOOD_FORWARD,
    
    cmdDETECT_DANGER,
    cmdDETECT_OBSTACLE,
    cmdDETECT_FOOD,
    
    cmdSET_FLAG,
    cmdRESET_FLAG,
    
    cmdJMP_R,
    cmdJMP_I,
    
    cmdFINISH
}

enum ACTIONS
{
    actIDLE,
    actMOVE,
    actEAT
}

typedef struct VCPU {
    u8[256] Memory;
    u8[16] Registers;
    u16 Flags;
    u8 Action;
    u8 Direction;
    u8 StopFlag;
}
