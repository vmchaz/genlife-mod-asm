#include <types.h>

#define FLAG_COUNT 8
#define FLAG_TYPE int
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t


typedef struct INSTRUCTION {
    u16 Command;
    u8 RegSrc;
    u8 RegDest;
    u8 Imm;
    u16 FlagDest;
    u16 AllowFlags;
    u16 DenyFlags;
    u8 FlagCombination;
}

typedef struct UNITGLOBALS {
    u32 Action;
    u32 ActionPriority;
    u32 Energy;
    u32 Direction;
}

typedef struct VCPUTHREAD {
    u8 Acc;
    u32 IP;
    u32 Flags;
    u32 DFlags;
}

typedef struct INSTRUCTIONSEQUENCE {
    INSTRUCTION Instructions[256]
}

typedef struct UNIT {
    VCPUTHREAD Threads[8]
}

typedef struct FIELD {
}

typedef struct FIELDPART {
    u32 SizeX;
    u32 SizeY;
    u8 FieldCells[49]
}

#define cmdNOP 0
    
#define cmdMOV_RR 1
#define cmdMOV_RI 2
#define cmdMOV_RA 3
#define cmdMOV_AR 4
#define cmdMOV_AI 5

#define cmdADD_RR 6
#define cmdADD_RI 7
#define cmdADD_AR 8
#define cmdADD_RA 9
#define cmdADD_AI 10

#define cmdSUB_RR 11
#define cmdSUB_RI 12
#define cmdSUB_AR 13
#define cmdSUB_RA 14
#define cmdSUB_AI 15

#define cmdINC_R 16
#define cmdINC_A 17

#define cmdDEC_R 18
#define cmdDEC_A 19

#define cmdEQUALS_RR 20
#define cmdEQUALS_RI 21
#define cmdEQUALS_RA 22
#define cmdEQUALS_AR 23
#define cmdEQUALS_AI 24

#define cmdNEQUALS_RR 25
#define cmdNEQUALS_RI 26
#define cmdNEQUALS_AR 27
#define cmdNEQUALS_RA 28
#define cmdNEQUALS_AI 29

#define cmdGREATER_RR 30
#define cmdGREATER_RI 31
#define cmdGREATER_RA 32
#define cmdGREATER_AR 33
#define cmdGREATER_AI 34

#define cmdLESS_RR 35
#define cmdLESS_RI 36
#define cmdLESS_RA 37
#define cmdLESS_AR 38
#define cmdLESS_AI 39

#define cmdSET_ACTION_STAND 40
#define cmdSET_ACTION_EAT 41
#define cmdSET_ACTION_FORWARD 42
#define cmdSET_ACTION_TURN_BACKWARD 43
#define cmdSET_ACTION_TURN_LEFT 44
#define cmdSET_ACTION_TURN_RIGHT 45
#define cmdSET_ACTION_TURN_MOVE_LEFT 46
#define cmdSET_ACTION_TURN_MOVE_RIGHT 47


#define cmdDETECT_OBSTACLE 48
#define cmdDETECT_FOOD 49
#define cmdDETECT_DANGER 50
#define cmdDETECT_PREDATOR 51
#define cmdDETECT_PREY 52

#define cmdDETECT_OBSTACLE 53
#define cmdDETECT_FOOD 54
#define cmdDETECT_DANGER 55
#define cmdDETECT_PREDATOR 56
#define cmdDETECT_PREY 57

#define cmdSET_FLAG 58
#define cmdRESET_FLAG 59

#define cmdJMP_REL_R 60
#define cmdJMP_REL_I 61
#define cmdJMP_REL_A 62
#define cmdJMP_ABS_R 63
#define cmdJMP_ABS_I 64
#define cmdJMP_ABS_A 65


#define actIDLE 0
#define actEAT 1
#define actMOVEFORWARD 2
#define actTURNMOVEBACKWARD 3
#define actTURNLEFT 4
#define actTURNRIGHT 5
#define actTURNMOVELEFT 6
#define actTURNMOVERIGHT 7

#define act

