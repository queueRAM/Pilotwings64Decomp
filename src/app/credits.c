#include "common.h"
#include <uv_environment.h>
#include <uv_event.h>
#include <uv_font.h>
#include <uv_graphics.h>
#include <uv_memory.h>
#include <uv_texture.h>
#include <uv_vector.h>
#include "code_9A960.h"
#include "code_B2900.h"
#include "code_D2B10.h"
#include "credits.h"
#include "demo.h"
#include "demo_attitude.h"
#include "env_sound.h"
#include "environment.h"
#include "fire_effects.h"
#include "game.h"
#include "snd.h"
#include "text_data.h"

typedef struct {
    const char* unk0;
    s16 type;
    s16 unk6; // updated with some sort of row count or something?
} CreditLines;

CreditLines D_8034F4E0[] = {
    {            "NINTENDO STAFF", 0x1, 0x0 },
    {                  "DIRECTOR", 0x2, 0x0 },
    {               "MAKOTO WADA", 0x3, 0x0 },
    {               "CO DIRECTOR", 0x2, 0x0 },
    {            "YASUYUKI OYAGI", 0x3, 0x0 },
    {          "GRAPHIC DESIGNER", 0x2, 0x0 },
    {          "HIROAKI TAKENAKA", 0x3, 0x0 },
    {            "YOSHIYUKI KATO", 0x3, 0x0 },
    {         "SOUND ARRANGEMENT", 0x2, 0x0 },
    {           "AKITO NAKATSUKA", 0x3, 0x0 },
    {       "PROJECT ARRANGEMENT", 0x2, 0x0 },
    {         "SHIGEKI YAMASHIRO", 0x3, 0x0 },
    {             "HIRO NAKAMURA", 0x3, 0x0 },
    {              "DARREN SMITH", 0x3, 0x0 },
    {               "JIM WORNELL", 0x3, 0x0 },
    {            "PARADIGM STAFF", 0x1, 0x0 },
    {           "PROJECT MANAGER", 0x2, 0x0 },
    {              "DAVE GATCHEL", 0x3, 0x0 },
    {    "LEAD SOFTWARE ENGINEER", 0x2, 0x0 },
    {          "MIKE ENGELDINGER", 0x3, 0x0 },
    { "LEAD MODELING AND EFFECTS", 0x2, 0x0 },
    {               "WES HOFFMAN", 0x3, 0x0 },
    {      "SOFTWARE ENGINEERING", 0x2, 0x0 },
    {               "MIKE PANOFF", 0x3, 0x0 },
    {           "AARON HIGHTOWER", 0x3, 0x0 },
    {                 "JON DAVIS", 0x3, 0x0 },
    {           "STEVE LOTSPEICH", 0x3, 0x0 },
    {             "MIKE BIENVENU", 0x3, 0x0 },
    {                "SAM PERERA", 0x3, 0x0 },
    {             "STEVE FUHRMAN", 0x3, 0x0 },
    {                "ROB ROSSOW", 0x3, 0x0 },
    {             "CHRIS MUMFORD", 0x3, 0x0 },
    {             "RICHARD BAKER", 0x3, 0x0 },
    {    "MODELING AND ANIMATION", 0x2, 0x0 },
    {             "DAVID KRUEGER", 0x3, 0x0 },
    {                "GARY BANDY", 0x3, 0x0 },
    {                 "GREG GUTH", 0x3, 0x0 },
    {             "AUDIO SUPPORT", 0x2, 0x0 },
    {             "SCOTT GARGASH", 0x3, 0x0 },
    {                "ANU APPAJI", 0x3, 0x0 },
    {               "JOHN PERSER", 0x3, 0x0 },
    {         "MUSIC COMPOSITION", 0x2, 0x0 },
    {                  "DAN HESS", 0x3, 0x0 },
    { "PRODUCT MARKETING SUPPORT", 0x2, 0x0 },
    { "MATTHEW SHANNON YARBROUGH", 0x3, 0x0 },
    {            "SPECIAL THANKS", 0x2, 0x0 },
    {           "KIMIYOSHI FUKUI", 0x3, 0x0 },
    {                "KENJI MIKI", 0x3, 0x0 },
    {         "MASATO HATAKEYAMA", 0x3, 0x0 },
    {            "KENSUKE TANABE", 0x3, 0x0 },
    {           "NARUHISA KAWANO", 0x3, 0x0 },
    {              "EIJI ONOZUKA", 0x3, 0x0 },
    {             "SHIGEO KIMURA", 0x3, 0x0 },
    {               "HIRO YAMADA", 0x3, 0x0 },
    {            "KOJI MITSUNARI", 0x3, 0x0 },
    {              "KAZUNOBU ERI", 0x3, 0x0 },
    {        "YOSHITAKA YASUMOTO", 0x3, 0x0 },
    {        "TSUTOMU KOGANEZAWA", 0x3, 0x0 },
    {          "TAKAYUKI HASHIDA", 0x3, 0x0 },
    {              "SATOSHI KIRA", 0x3, 0x0 },
    {                          "", 0x3, 0x0 },
    {               "MIKE FUKUDA", 0x3, 0x0 },
    {         "MASAHITO WATANABE", 0x3, 0x0 },
    {          "MICHAEL KELBAUGH", 0x3, 0x0 },
    {                          "", 0x3, 0x0 },
    {                "RON TOUPAL", 0x3, 0x0 },
    {                 "RON PAIGE", 0x3, 0x0 },
    {                "DIANE ROTH", 0x3, 0x0 },
    {           "SHARON LINDHOLM", 0x3, 0x0 },
    {             "CHRIS JOHNSON", 0x3, 0x0 },
    {             "JANICE PANOFF", 0x3, 0x0 },
    {                          "", 0x3, 0x0 },
    {          "MARIO CLUB STAFF", 0x3, 0x0 },
    {                          "", 0x3, 0x0 },
    {       "NOA PRODUCT TESTING", 0x3, 0x0 },
    {                 "PRODUCERS", 0x2, 0x0 },
    {              "GENYO TAKEDA", 0x4, 0x0 },
    {          "SHIGERU MIYAMOTO", 0x4, 0x0 },
    {        "EXECUTIVE PRODUCER", 0x2, 0x0 },
    {          "HIROSHI YAMAUCHI", 0x3, 0x0 },
    {                          "", 0x3, 0x0 },
    {              "PRESENTED BY", 0x2, 0x0 },
    {                  "NINTENDO", 0x5, 0x0 },
    {                        NULL, 0x3, 0x0 },
};

f32 D_8034F780 = -32.0f;
u8 D_8034F784 = 1;
f32 D_8034F788 = 0.0f;
f32 D_8034F78C = -1.0f;
f32 D_8034F790 = 0.0f;
s32 D_8036A8B0;

s32 credits_8030CB60(s32 arg0) {
    s32 var_a2;
    s32 var_a1;
    s32 temp_v0;

    var_a2 = credits_8030CC48();
    if (arg0 != 0) {
        var_a1 = D_80362690->unkC[D_80362690->unk9C].unk8A;
        D_80362690->unkC[D_80362690->unk9C].unk8A = var_a1 == 0;
        saveFileLoad(D_80362690->unkC[D_80362690->unk9C].unk8A);
        temp_v0 = credits_8030CC48();
        if (var_a2 < temp_v0) {
            var_a2 = temp_v0;
        }
        var_a1 = D_80362690->unkC[D_80362690->unk9C].unk8A;
        D_80362690->unkC[D_80362690->unk9C].unk8A = var_a1 == 0;
        saveFileLoad(D_80362690->unkC[D_80362690->unk9C].unk8A);
    }
    return var_a2;
}

s32 credits_8030CC48(void) {
    if (func_8032C27C() != 0) {
        return 3;
    }
    if (func_8032C3C4(D_80362690->unkC[D_80362690->unk9C].unk74, 3) >= 3) {
        return 2;
    }
    if (func_8032C3C4(D_80362690->unkC[D_80362690->unk9C].unk74, 1) > 0) {
        return 1;
    }
    return 0;
}

s32 creditsMainRender(void) {
    D_8036A8B0 = credits_8030CC48();
    credits_8030CDA0(D_8036A8B0);
    while (credits_8030D208() == 0) {
        uvGfxBegin();
        creditsScene();
        func_8034B688();
        uvGfxEnd();
    }
    credits_8030D1D4();
    if (D_80362690->unkA8 < D_8036A8B0) {
        D_80362690->unkA8 = D_8036A8B0;
    }
    return 0;
}

void credits_8030CDA0(s32 timeOfDay) {
    Unk80362690_Unk0* sp2C;
    Camera* sp28;
    CreditLines* credLine;
    s32 prevType;
    s32 var_v0;
    s32 envId;
    f32 ft0;
    s32 i;

    D_8034F780 = -32.0f;
    D_8034F784 = 1;

    var_v0 = 0;
    prevType = D_8034F4E0[0].type;
    for (i = 0; D_8034F4E0[i].unk0 != NULL; i++) {
        credLine = &D_8034F4E0[i];
        if (prevType != credLine->type) {
            switch (prevType) {
            case 1:
                if (credLine->type != 3) {
                    var_v0 -= 40.0f;
                }
                break;
            case 2:
                if ((credLine->type != 3) && (credLine->type != 4) && (credLine->type != 5)) {
                    var_v0 -= 30.0f;
                }
                break;
            case 3:
            case 4:
            case 5:
                var_v0 -= 50.0f;
                break;
            }
            prevType = credLine->type;
        }

        credLine->unk6 = var_v0;
        switch (credLine->type) {
        case 1:
            var_v0 -= 30.0f;
            break;
        case 2:
            if (credLine->type != 5) { // case is always true
                var_v0 -= 30.0f;
            }
            break;
        case 3:
        case 5:
            var_v0 -= 30.0f;
            break;
        case 4:
            var_v0 -= 40.0f;
            break;
        }
    }
    ft0 = var_v0;
    D_8034F788 = -ft0 / 210.0f;

    sp28 = D_80362690->unkC[D_80362690->unk9C].unk70;
    sp2C = &D_80362690->unkC[D_80362690->unk9C];
    uvLevelInit();
    D_80362690->map = MAP_LITTLE_STATES;
    D_80362690->terraId = 3;
    switch (timeOfDay) {
    default:
        D_80362690->envId = 0x10;
        break;
    case 1:
        D_80362690->envId = 0x10;
        break;
    case 2:
        D_80362690->envId = 0xC;
        break;
    case 3:
        D_80362690->envId = 0x11;
        break;
    }
    envSoundInit();
    textLoadBlock(0x42);
    if (D_80362690->envId == 0x11) {
        envLoadTerrainPal(D_80362690->envId);
    }
    uvLevelAppend(5);
    func_8034B5E0(sp28->unk22C, sp28);
    envId = D_80362690->envId;
    env_802E1444((envId != 0) ? envId : 0x10);
    func_80204BD4(sp28->unk22C, 1, 1.0f);
    uvChanTerra(sp2C->unk70->unk22C, D_80362690->terraId);
    func_80204A8C(sp28->unk22C, 3);
    uvEnvFunc(D_80362690->envId, 0, env_802E0CF0);
    func_80204AB0(sp28->unk22C, 1, func_8034B6F8);
    func_80313640(-1419.9f, 871.2f, 639.72f, 1.1452856f, -0.2094396f, 0.0f, &sp28->unk108);
    fireFxInit();
    fireFxCreateAll();
    uvFontSet(0);
    uvFontScale(1.0, 1.0);
    demoAttInit(0x54);
    func_8033F748(0x1E);
    func_8033F964(0);
    func_8033FCD0(sp2C->veh);
}

void credits_8030D1D4(void) {
    uvEventPost(0xD, 0);
    func_8033F964(1U);
    fireFxDeinit();
}

s32 credits_8030D208(void) {
    demoAtt_80320FBC();
    demo_80323020();
    func_80313D74();
    if ((D_8034F784 == 0) && (demoButtonPress(D_80362690->unk9C, A_BUTTON | B_BUTTON | START_BUTTON) != 0)) {
        if (demoButtonPress(D_80362690->unk9C, A_BUTTON | START_BUTTON) != 0) {
            sndPlaySfx(SFX_UI_CONFIRM);
            return 1;
        }
        if (demoButtonPress(D_80362690->unk9C, B_BUTTON) != 0) {
            sndPlaySfx(SFX_UI_CANCEL);
        }
        return 1;
    }
    if (D_8034F784 != 0) {
        D_8034F780 += D_8034F788 * D_8034F854;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/credits/creditsScene.s")
