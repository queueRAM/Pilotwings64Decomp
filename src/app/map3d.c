#include <uv_graphics.h>
#include <uv_level.h>
#include <uv_main.h>
#include "code_72B70.h"
#include "demo.h"
#include "map3d.h"

void app_entrypoint(void) {
    uvSysInit(0);
    uvGfxEnableGamma(0);
    func_802EB9C0();
    while (demo_80323020() != 0) {
        func_802EBC30();
    }
    func_8022E2D4(0);
}

void func_8030FE80(Unk80362690* arg0, s32 arg1) {
    map3d(arg0, arg1);
    while (func_80311660(0, arg1) != 0) {
        uvGfxBegin();
        func_80311C68(arg0, arg1);
        uvGfxEnd();
    }
    func_803122B4(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/map3d/map3d.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/map3d/func_80311660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/map3d/func_80311C68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/map3d/func_803122B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/map3d/func_803123C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/map3d/func_80312514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/map3d/map3d_mslot.s")
