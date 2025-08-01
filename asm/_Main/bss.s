#include "macros.S"

.section .bss

.balign 32

.global lbl_10000000
lbl_10000000:
    .skip 0x5FC8
.global lbl_10005FC8
lbl_10005FC8:
    .skip 0x354
.global lbl_1000631C
lbl_1000631C:
    .skip 0x4
.global lbl_10006320
lbl_10006320:
    .skip 0x4
.global lbl_10006324
lbl_10006324:
    .skip 0x4
.global lbl_10006328
lbl_10006328:
    .skip 0x4
.global lbl_1000632C
lbl_1000632C:
    .skip 0x10
.global lbl_1000633C
lbl_1000633C:
    .skip 0xC0
.global gaNnViewRotInvertMtx
gaNnViewRotInvertMtx:
    .skip 0xC0
.global gaNnViewMtx
gaNnViewMtx:
    .skip 0x104
.global lbl_100065C0
lbl_100065C0:
    .skip 0x100
.global lbl_100066C0
lbl_100066C0:
    .skip 0x40
.global lbl_10006700
lbl_10006700:
    .skip 0x100
.global gaNnProjMtx44
gaNnProjMtx44:
    .skip 0x140
.global lbl_10006940
lbl_10006940:
    .skip 0x48
.global gsaCamPosFast
gsaCamPosFast:
    .skip 0x6C
.global PlayerCameraPositionStruct
PlayerCameraPositionStruct:
    # 0x38 in size, 5 cameras
    .skip 0x118
.global gsCameraMisc
gsCameraMisc:
    .skip 0x10
.global gu32StageCameraMotionNum
gu32StageCameraMotionNum:
    .skip 0x4
.global gasCameraPtr
gasCameraPtr:
    .skip 0x80
.global gpsMotion_Camera
gpsMotion_Camera:
    .skip 0x40
.global lbl_10006BE0
lbl_10006BE0:
    .skip 0xC8
.global playerCameraStruct
playerCameraStruct:
    # 0x25C in size, in player order
    .skip 0x154C
.global gu32LightDetailNum
gu32LightDetailNum:
    .skip 0x4
.global gpsLightDetailDefault
gpsLightDetailDefault:
    .skip 0x8
.global gu32ObjMtxPalMaxSize
gu32ObjMtxPalMaxSize:
    .skip 0x4
.global gpsObjMtxPal
gpsObjMtxPal:
    .skip 0x4
.global gu32ObjNodeStatusMaxSize
gu32ObjNodeStatusMaxSize:
    .skip 0x4
.global gpsObjNodeStat
gpsObjNodeStat:
    .skip 0x4
.global gpsStageObjTop
gpsStageObjTop:
    .skip 0x4
.global gpsObjPortal
gpsObjPortal:
    .skip 0x4
.global gpsMapPortal
gpsMapPortal:
    .skip 0x4
.global gpsMapPortalNo2
gpsMapPortalNo2:
    .skip 0x4
.global gpsPitPortal
gpsPitPortal:
    .skip 0x4
.global lbl_10008224
lbl_10008224:
    .skip 0x4
.global lbl_10008228
lbl_10008228:
    .skip 0x4
.global lbl_1000822C
lbl_1000822C:
    .skip 0x4
.global lbl_10008230
lbl_10008230:
    .skip 0x4
.global lbl_10008234
lbl_10008234:
    .skip 0x4
.global lbl_10008238
lbl_10008238:
    .skip 0x4
.global lbl_1000823C
lbl_1000823C:
    .skip 0x4
.global gpsTexList_Map
gpsTexList_Map:
    .skip 0x8
.global gpsObject_Sky
gpsObject_Sky:
    .skip 0x4
.global gpsTexList_Sky
gpsTexList_Sky:
    .skip 0x4
.global lbl_10008250
lbl_10008250:
    .skip 0x4
.global lbl_10008254
lbl_10008254:
    .skip 0x4
.global lbl_10008258
lbl_10008258:
    .skip 0x4
.global lbl_1000825C
lbl_1000825C:
    .skip 0x4
.global lbl_10008260
lbl_10008260:
    .skip 0x4
.global lbl_10008264
lbl_10008264:
    .skip 0x4
.global lbl_10008268
lbl_10008268:
    .skip 0x4
.global lbl_1000826C
lbl_1000826C:
    .skip 0x4
.global lbl_10008270
lbl_10008270:
    .skip 0x4
.global lbl_10008274
lbl_10008274:
    .skip 0x4
.global lbl_10008278
lbl_10008278:
    .skip 0x4
.global lbl_1000827C
lbl_1000827C:
    .skip 0x4
.global lbl_10008280
lbl_10008280:
    .skip 0x4
.global lbl_10008284
lbl_10008284:
    .skip 0x4
.global lbl_10008288
lbl_10008288:
    .skip 0x4
.global lbl_1000828C
lbl_1000828C:
    .skip 0x4
.global lbl_10008290
lbl_10008290:
    .skip 0x4
.global lbl_10008294
lbl_10008294:
    .skip 0x4
.global lbl_10008298
lbl_10008298:
    .skip 0x4
.global lbl_1000829C
lbl_1000829C:
    .skip 0x4
.global lbl_100082A0
lbl_100082A0:
    .skip 0x4
.global gpsObject_EffectLanding
gpsObject_EffectLanding:
    .skip 0x4
.global gpsTexList_EffectLanding
gpsTexList_EffectLanding:
    .skip 0x4
.global gpsMtxPal_EffectLanding
gpsMtxPal_EffectLanding:
    .skip 0x4
.global gpsNodeStat_EffectLanding
gpsNodeStat_EffectLanding:
    .skip 0x4
.global gpsMotion_EffectLanding
gpsMotion_EffectLanding:
    .skip 0x4
.global gpsMatMotObj_EffectLanding
gpsMatMotObj_EffectLanding:
    .skip 0x4
.global gpsMatMotion_EffectLanding
gpsMatMotion_EffectLanding:
    .skip 0x4
.global gpsObject_EffectAirCharge
gpsObject_EffectAirCharge:
    .skip 0x4
.global gpsTexList_EffectAirCharge
gpsTexList_EffectAirCharge:
    .skip 0x4
.global gpsMtxPal_EffectAirCharge
gpsMtxPal_EffectAirCharge:
    .skip 0x4
.global gpsNodeStat_EffectAirCharge
gpsNodeStat_EffectAirCharge:
    .skip 0x4
.global gpsMotion_EffectAirCharge
gpsMotion_EffectAirCharge:
    .skip 0x4
.global gpsMatMotObj_EffectAirCharge
gpsMatMotObj_EffectAirCharge:
    .skip 0x4
.global gpsMatMotion_EffectAirCharge
gpsMatMotion_EffectAirCharge:
    .skip 0x4
.global lbl_100082DC
lbl_100082DC:
    .skip 0x4
.global lbl_100082E0
lbl_100082E0:
    .skip 0x4
.global lbl_100082E4
lbl_100082E4:
    .skip 0x4
.global lbl_100082E8
lbl_100082E8:
    .skip 0x4
.global lbl_100082EC
lbl_100082EC:
    .skip 0x4
.global lbl_100082F0
lbl_100082F0:
    .skip 0x4
.global lbl_100082F4
lbl_100082F4:
    .skip 0x4
.global lbl_100082F8
lbl_100082F8:
    .skip 0x4
.global lbl_100082FC
lbl_100082FC:
    .skip 0x4
.global lbl_10008300
lbl_10008300:
    .skip 0x4
.global lbl_10008304
lbl_10008304:
    .skip 0x4
.global lbl_10008308
lbl_10008308:
    .skip 0x4
.global lbl_1000830C
lbl_1000830C:
    .skip 0x4
.global lbl_10008310
lbl_10008310:
    .skip 0x4
.global lbl_10008314
lbl_10008314:
    .skip 0x4
.global lbl_10008318
lbl_10008318:
    .skip 0x4
.global lbl_1000831C
lbl_1000831C:
    .skip 0x4
.global lbl_10008320
lbl_10008320:
    .skip 0x4
.global lbl_10008324
lbl_10008324:
    .skip 0x4
.global lbl_10008328
lbl_10008328:
    .skip 0x4
.global lbl_1000832C
lbl_1000832C:
    .skip 0x4
.global lbl_10008330
lbl_10008330:
    .skip 0x4
.global lbl_10008334
lbl_10008334:
    .skip 0x4
.global lbl_10008338
lbl_10008338:
    .skip 0x4
.global lbl_1000833C
lbl_1000833C:
    .skip 0x4
.global lbl_10008340
lbl_10008340:
    .skip 0x4
.global lbl_10008344
lbl_10008344:
    .skip 0x4
.global lbl_10008348
lbl_10008348:
    .skip 0x4
.global lbl_1000834C
lbl_1000834C:
    .skip 0x4
.global lbl_10008350
lbl_10008350:
    .skip 0x4
.global lbl_10008354
lbl_10008354:
    .skip 0x4
.global lbl_10008358
lbl_10008358:
    .skip 0x4
.global lbl_1000835C
lbl_1000835C:
    .skip 0x4
.global lbl_10008360
lbl_10008360:
    .skip 0x4
.global lbl_10008364
lbl_10008364:
    .skip 0x4
.global lbl_10008368
lbl_10008368:
    .skip 0x4
.global lbl_1000836C
lbl_1000836C:
    .skip 0x4
.global lbl_10008370
lbl_10008370:
    .skip 0x4
.global lbl_10008374
lbl_10008374:
    .skip 0x4
.global lbl_10008378
lbl_10008378:
    .skip 0x4
.global gpsObject_EffectTurf
gpsObject_EffectTurf:
    .skip 0x4
.global gpsTexList_EffectTurf
gpsTexList_EffectTurf:
    .skip 0x4
.global gpsMtxPal_EffectTurf
gpsMtxPal_EffectTurf:
    .skip 0x4
.global gpsNodeStat_EffectTurf
gpsNodeStat_EffectTurf:
    .skip 0x4
.global gpsMotion_EffectTurf
gpsMotion_EffectTurf:
    .skip 0x4
.global gpsMatMotObj_EffectTurf
gpsMatMotObj_EffectTurf:
    .skip 0x4
.global gpsMatMotion_EffectTurf
gpsMatMotion_EffectTurf:
    .skip 0x4
.global gpsObject_EffectTurbResist
gpsObject_EffectTurbResist:
    .skip 0x4
.global gpsTexList_EffectTurbResist
gpsTexList_EffectTurbResist:
    .skip 0x4
.global gpsMtxPal_EffectTurbResist
gpsMtxPal_EffectTurbResist:
    .skip 0x4
.global gpsNodeStat_EffectTurbResist
gpsNodeStat_EffectTurbResist:
    .skip 0x4
.global gpsMotion_EffectTurbResist
gpsMotion_EffectTurbResist:
    .skip 0x4
.global gpsMatMotObj_EffectTurbResist
gpsMatMotObj_EffectTurbResist:
    .skip 0x4
.global gpsMatMotion_EffectTurbResist
gpsMatMotion_EffectTurbResist:
    .skip 0x4
.global gpsObject_EffectAtkBoost
gpsObject_EffectAtkBoost:
    .skip 0x4
.global gpsTexList_EffectAtkBoost
gpsTexList_EffectAtkBoost:
    .skip 0x4
.global gpsMtxPal_EffectAtkBoost
gpsMtxPal_EffectAtkBoost:
    .skip 0x4
.global gpsNodeStat_EffectAtkBoost
gpsNodeStat_EffectAtkBoost:
    .skip 0x4
.global gpsMotion_EffectAtkBoost
gpsMotion_EffectAtkBoost:
    .skip 0x4
.global gpsMatMotObj_EffectAtkBoost
gpsMatMotObj_EffectAtkBoost:
    .skip 0x4
.global gpsMatMotion_EffectAtkBoost
gpsMatMotion_EffectAtkBoost:
    .skip 0x4
.global gpsObject_EffectMagBarrier
gpsObject_EffectMagBarrier:
    .skip 0x4
.global gpsTexList_EffectMagBarrier
gpsTexList_EffectMagBarrier:
    .skip 0x4
.global gpsMtxPal_EffectMagBarrier
gpsMtxPal_EffectMagBarrier:
    .skip 0x4
.global gpsNodeStat_EffectMagBarrier
gpsNodeStat_EffectMagBarrier:
    .skip 0x4
.global gpsMotion_EffectMagBarrier
gpsMotion_EffectMagBarrier:
    .skip 0x4
.global gpsMatMotObj_EffectMagBarrier
gpsMatMotObj_EffectMagBarrier:
    .skip 0x4
.global gpsMatMotion_EffectMagBarrier
gpsMatMotion_EffectMagBarrier:
    .skip 0x4
.global gpsObject_EffectInvincible
gpsObject_EffectInvincible:
    .skip 0x4
.global gpsTexList_EffectInvincible
gpsTexList_EffectInvincible:
    .skip 0x4
.global gpsMtxPal_EffectInvincible
gpsMtxPal_EffectInvincible:
    .skip 0x4
.global gpsNodeStat_EffectInvincible
gpsNodeStat_EffectInvincible:
    .skip 0x4
.global gpsMotion_EffectInvincible
gpsMotion_EffectInvincible:
    .skip 0x4
.global gpsMatMotObj_EffectInvincible
gpsMatMotObj_EffectInvincible:
    .skip 0x4
.global gpsMatMotion_EffectInvincible
gpsMatMotion_EffectInvincible:
    .skip 0x4
.global gpsTexList_Effect
gpsTexList_Effect:
    .skip 0x4
.global gpsTexList_Score
gpsTexList_Score:
    .skip 0x4
.global gpsTexList_Score2
gpsTexList_Score2:
    .skip 0x4
.global texList_GTSE_0
texList_GTSE_0:
    .skip 0x4
.global texList_GTSE_1
texList_GTSE_1:
    .skip 0x4
.global lbl_1000841C
lbl_1000841C:
    .skip 0x4
.global lbl_10008420
lbl_10008420:
    .skip 0x4
.global lbl_10008424
lbl_10008424:
    .skip 0x4
.global gpsTexList_EffectSunAndLensFlare
gpsTexList_EffectSunAndLensFlare:
    .skip 0x4
.global lbl_1000842C
lbl_1000842C:
    .skip 0x4
.global gpsTexList_EffectFlowLine
gpsTexList_EffectFlowLine:
    .skip 0x4
.global gpsTexList_EffectBackRibbon
gpsTexList_EffectBackRibbon:
    .skip 0x4
.global gpsTexList_EffectAirChargeParticle
gpsTexList_EffectAirChargeParticle:
    .skip 0x4
.global gpsTexList_Particle
gpsTexList_Particle:
    .skip 0x4
.global lbl_10008440
lbl_10008440:
    .skip 0x4
.global lbl_10008444
lbl_10008444:
    .skip 0x4
.global gpsTexList_EffectBoardRibbon
gpsTexList_EffectBoardRibbon:
    .skip 0x4
.global lbl_1000844C
lbl_1000844C:
    .skip 0x4
.global lbl_10008450
lbl_10008450:
    .skip 0x4
.global lbl_10008454
lbl_10008454:
    .skip 0x4
.global lbl_10008458
lbl_10008458:
    .skip 0x4
.global lbl_1000845C
lbl_1000845C:
    .skip 0x4
.global lbl_10008460
lbl_10008460:
    .skip 0x4
.global lbl_10008464
lbl_10008464:
    .skip 0x4
.global lbl_10008468
lbl_10008468:
    .skip 0xC
.global gpsMatMotion_EffectDmg
gpsMatMotion_EffectDmg:
    .skip 0xC
.global gpsMatMotObj_EffectDmg
gpsMatMotObj_EffectDmg:
    .skip 0xC
.global gpsMotion_EffectDmg
gpsMotion_EffectDmg:
    .skip 0xC
.global gpsNodeStat_EffectDmg
gpsNodeStat_EffectDmg:
    .skip 0xC
.global gpsMtxPal_EffectDmg
gpsMtxPal_EffectDmg:
    .skip 0xC
.global gpsTexList_EffectDmg
gpsTexList_EffectDmg:
    .skip 0xC
.global gpsObject_EffectDmg
gpsObject_EffectDmg:
    .skip 0xC
.global lbl_100084C8
lbl_100084C8:
    .skip 0x40
.global lbl_10008508
lbl_10008508:
    .skip 0x40
.global lbl_10008548
lbl_10008548:
    .skip 0xC80
.global lbl_100091C8
lbl_100091C8:
    .skip 0x1E0
.global gsStObj
gsStObj:
    .skip 0x28
.global lbl_100093D0
lbl_100093D0:
    .skip 0x4
.global lbl_100093D4
lbl_100093D4:
    .skip 0x340
.global lbl_10009714
lbl_10009714:
    .skip 0x1DC
.global gpsTexList_EffectSpeedDown
gpsTexList_EffectSpeedDown:
    .skip 0x8
.global gpsObject_EffectSpeedDown
gpsObject_EffectSpeedDown:
    .skip 0x8
.global gpsMatMotion_EffectTurbTrickArrow
gpsMatMotion_EffectTurbTrickArrow:
    .skip 0x8
.global gpsMatMotObj_EffectTurbTrickArrow
gpsMatMotObj_EffectTurbTrickArrow:
    .skip 0x8
.global gpsNodeStat_EffectTurbTrickArrow
gpsNodeStat_EffectTurbTrickArrow:
    .skip 0x8
.global gpsMtxPal_EffectTurbTrickArrow
gpsMtxPal_EffectTurbTrickArrow:
    .skip 0x8
.global gpsTexList_EffectTurbTrickArrow
gpsTexList_EffectTurbTrickArrow:
    .skip 0x8
.global gpsObject_EffectTurbTrickArrow
gpsObject_EffectTurbTrickArrow:
    .skip 0x8
.global gpsMatMotion_EffectTornado
gpsMatMotion_EffectTornado:
    .skip 0x8
.global gpsMatMotObj_EffectTornado
gpsMatMotObj_EffectTornado:
    .skip 0x8
.global gpsMotion_EffectTornado
gpsMotion_EffectTornado:
    .skip 0x8
.global gpsNodeStat_EffectTornado
gpsNodeStat_EffectTornado:
    .skip 0x8
.global gpsMtxPal_EffectTornado
gpsMtxPal_EffectTornado:
    .skip 0x8
.global gpsTexList_EffectTornado
gpsTexList_EffectTornado:
    .skip 0x8
.global gpsObject_EffectTornado
gpsObject_EffectTornado:
    .skip 0x158
.global lbl_10009AB8
lbl_10009AB8:
    .skip 0x18
.global lbl_10009AD0
lbl_10009AD0:
    .skip 0x18
.global lbl_10009AE8
lbl_10009AE8:
    .skip 0x18
.global lbl_10009B00
lbl_10009B00:
    .skip 0x18
.global lbl_10009B18
lbl_10009B18:
    .skip 0x18
.global lbl_10009B30
lbl_10009B30:
    .skip 0x18
.global lbl_10009B48
lbl_10009B48:
    .skip 0x18
.global lbl_10009B60
lbl_10009B60:
    .skip 0x18
.global lbl_10009B78
lbl_10009B78:
    .skip 0x18
.global lbl_10009B90
lbl_10009B90:
    .skip 0x18
.global lbl_10009BA8
lbl_10009BA8:
    .skip 0x18
.global lbl_10009BC0
lbl_10009BC0:
    .skip 0x18
.global lbl_10009BD8
lbl_10009BD8:
    .skip 0x18
.global lbl_10009BF0
lbl_10009BF0:
    .skip 0xC
.global lbl_10009BFC
lbl_10009BFC:
    .skip 0xC
.global lbl_10009C08
lbl_10009C08:
    .skip 0xC
.global lbl_10009C14
lbl_10009C14:
    .skip 0xC
.global lbl_10009C20
lbl_10009C20:
    .skip 0xC
.global lbl_10009C2C
lbl_10009C2C:
    .skip 0xC
.global lbl_10009C38
lbl_10009C38:
    .skip 0xC
.global lbl_10009C44
lbl_10009C44:
    .skip 0x4
.global lbl_10009C48
lbl_10009C48:
    .skip 0x4
.global lbl_10009C4C
lbl_10009C4C:
    .skip 0x4
.global lbl_10009C50
lbl_10009C50:
    .skip 0x4
.global lbl_10009C54
lbl_10009C54:
    .skip 0x4
.global lbl_10009C58
lbl_10009C58:
    .skip 0x4
.global gc8MapDivPortalType
gc8MapDivPortalType:
    .skip 0x1C
.global gu8MapDivType
gu8MapDivType:
    .skip 0x1C
.global gpsMatMotion_DivMap
gpsMatMotion_DivMap:
    .skip 0x68
.global gpsMatMotObj_DivMap
gpsMatMotObj_DivMap:
    .skip 0x68
.global gpsMotion_DivMap
gpsMotion_DivMap:
    .skip 0x68
.global gpsObject_DivMap
gpsObject_DivMap:
    .skip 0xA8
.global lbl_10009E74
lbl_10009E74:
    .skip 0x4
.global lbl_10009E78
lbl_10009E78:
    .skip 0x24
.global lbl_10009E9C
lbl_10009E9C:
    .skip 0x4
.global lbl_10009EA0
lbl_10009EA0:
    .skip 0x4
.global gpsaMotion_PlayerNeo
gpsaMotion_PlayerNeo:
    .skip 0x4000
.global gpsaMtxList_Player
gpsaMtxList_Player:
    .skip 0x20
.global lbl_1000DEC4
lbl_1000DEC4:
    .skip 0x80
.global gpsaTrsListObject_Player
gpsaTrsListObject_Player:
    .skip 0x20
.global gpsaUnitMtxPal_Player
gpsaUnitMtxPal_Player:
    .skip 0x20
.global gpsaNodeStat_Player
gpsaNodeStat_Player:
    .skip 0x40
.global gpsaTexList_Player
gpsaTexList_Player:
    .skip 0x20
.global gpsaObject_Player
gpsaObject_Player:
    .skip 0x28
.global lbl_1000E00C
lbl_1000E00C:
    .skip 0x34
.global lbl_1000E040
lbl_1000E040:
    .skip 0x58
.global lbl_1000E098
lbl_1000E098:
    .skip 0x300
.global gpsTopPlayer
gpsTopPlayer:
    .skip 0x28
.global players
players:
    .skip 0x9480
.global lbl_10017840
lbl_10017840:
    .skip 0x4
.global gpsTimerTask
gpsTimerTask:
    .skip 0x4
.global gpsRankTask
gpsRankTask:
    .skip 0x4
.global lbl_1001784C
lbl_1001784C:
    .skip 0x4
.global gpsInfoTask
gpsInfoTask:
    .skip 0x4
.global lbl_10017854
lbl_10017854:
    .skip 0x4
.global gpsCalcMove2DTask
gpsCalcMove2DTask:
    .skip 0x44
.global lbl_1001789C
lbl_1001789C:
    .skip 0x10
.global lbl_100178AC
lbl_100178AC:
    .skip 0x8
.global gpsAirChargeEffectTask
gpsAirChargeEffectTask:
    .skip 0x10
.global gpsAirCautionEffectTask
gpsAirCautionEffectTask:
    .skip 0x10
.global gpsRotValueTask
gpsRotValueTask:
    .skip 0x10
.global gpsTrickTask
gpsTrickTask:
    .skip 0x10
.global gpsBonusTask
gpsBonusTask:
    .skip 0x10
.global gpsParamTask
gpsParamTask:
    .skip 0x1C
.global CurrentGameMode
CurrentGameMode:
    .skip 0x4
.global geGame_ModeDetail
geGame_ModeDetail:
    .skip 0x4
.global CurrentStage
CurrentStage:
    .skip 0x4
.global gu32Game_IsUraStage
gu32Game_IsUraStage:
    .skip 0x4
.global geGame_Flag
geGame_Flag:
    .skip 0x4
.global gs8Game_GoalUserNum
gs8Game_GoalUserNum:
    .skip 0x1
.global gs8Game_GoalPlayerNum
gs8Game_GoalPlayerNum:
    .skip 0x1
.global gs8Game_RetirePlayerNum
gs8Game_RetirePlayerNum:
    .skip 0x2
.global gu32DivMapNum
gu32DivMapNum:
    .skip 0x4
.global gu32DivMapNo1Num
gu32DivMapNo1Num:
    .skip 0x4
.global RaceExitMethod
RaceExitMethod:
.global gu32EndOfGameFlag
gu32EndOfGameFlag:
    .skip 0x4
.global gpvGame_FreeFrame
gpvGame_FreeFrame:
    .skip 0x4
.global gpvGameRestart_FreeFrame
gpvGameRestart_FreeFrame:
    .skip 0x4
.global gs8PauseCursor
gs8PauseCursor:
    .skip 0x1
.global gs8ConfirmCursor
gs8ConfirmCursor:
    .skip 0x1
.global gs8PauseEnter
gs8PauseEnter:
    .skip 0x2
.global gpsStageTask
gpsStageTask:
    .skip 0x4
.global lbl_10017954
lbl_10017954:
    .skip 0x1
.global lbl_10017955
lbl_10017955:
    .skip 0xB
.global lbl_10017960
lbl_10017960:
    .skip 0x14
.global lbl_10017974
lbl_10017974:
    .skip 0x10
.global lbl_10017984
lbl_10017984:
    .skip 0xC
.global lbl_10017990
lbl_10017990:
    .skip 0xD0
.global lbl_10017A60
lbl_10017A60:
    .skip 0x18
.global lbl_10017A78
lbl_10017A78:
    .skip 0x30
.global gu32Game_StGateFlag
gu32Game_StGateFlag:
    .skip 0x8
.global AllPlayerInput
AllPlayerInput:
    .skip 0x10
.global lbl_10017AC0
lbl_10017AC0:
    .skip 0x28
.global lbl_10017AE8
lbl_10017AE8:
    .skip 0x4
.global gvpMissionExplanationTexData
gvpMissionExplanationTexData:
    .skip 0x4
.global lbl_10017AF0
lbl_10017AF0:
    .skip 0x8
.global lbl_10017AF8
lbl_10017AF8:
    .skip 0x18
.global lbl_10017B10
lbl_10017B10:
    .skip 0x8
.global lbl_10017B18
lbl_10017B18:
    .skip 0xC
.global lbl_10017B24
lbl_10017B24:
    .skip 0x20
.global lbl_10017B44
lbl_10017B44:
    .skip 0x4
.global lbl_10017B48
lbl_10017B48:
    .skip 0x10
.global gsaObjPortalType
gsaObjPortalType:
    .skip 0x20
.global lbl_10017B78
lbl_10017B78:
    .skip 0x4
.global gpsStageFogArray
gpsStageFogArray:
    .skip 0x4
.global gu32FogNum
gu32FogNum:
    .skip 0x4
.global lbl_10017B84
lbl_10017B84:
    .skip 0x4
.global gpsFogDefault
gpsFogDefault:
    .skip 0xC
.global lbl_10017B94
lbl_10017B94:
    .skip 0x4
.global lbl_10017B98
lbl_10017B98:
    .skip 0x14
.global lbl_10017BAC
lbl_10017BAC:
    .skip 0x4
.global lbl_10017BB0
lbl_10017BB0:
    .skip 0xC
.global lbl_10017BBC
lbl_10017BBC:
    .skip 0xA4
.global gs8ColMapNum
gs8ColMapNum:
    .skip 0x4
.global gpsCol_ActiveMap
gpsCol_ActiveMap:
    .skip 0x4
.global gpsCol_MapNo2
gpsCol_MapNo2:
    .skip 0x4
.global gpsCol_Cam
gpsCol_Cam:
    .skip 0x8
.global gpsCol_Map
gpsCol_Map:
    .skip 0xC
.global lbl_10017C80
lbl_10017C80:
    .skip 0x8
.global lbl_10017C88
lbl_10017C88:
    .skip 0x4
.global lbl_10017C8C
lbl_10017C8C:
    .skip 0x2C
.global lbl_10017CB8
lbl_10017CB8:
    .skip 0x4
.global lbl_10017CBC
lbl_10017CBC:
    .skip 0x4
.global lbl_10017CC0
lbl_10017CC0:
    .skip 0x4
.global lbl_10017CC4
lbl_10017CC4:
    .skip 0x4
.global lbl_10017CC8
lbl_10017CC8:
    .skip 0x14
.global lbl_10017CDC
lbl_10017CDC:
    .skip 0x4
.global gpsParFullParam_Leaf
gpsParFullParam_Leaf:
    .skip 0x8
.global lbl_10017CE8
lbl_10017CE8:
    .skip 0x4
.global gs8Path_SkillNum
gs8Path_SkillNum:
    .skip 0x4
.global gpsPath_Skill
gpsPath_Skill:
    .skip 0xC
.global lbl_10017CFC
lbl_10017CFC:
    .skip 0x4
.global gpsPath
gpsPath:
    .skip 0x18
.global lbl_10017D18
lbl_10017D18:
    .skip 0x4
.global lbl_10017D1C
lbl_10017D1C:
    .skip 0x4
.global lbl_10017D20
lbl_10017D20:
    .skip 0x4
.global lbl_10017D24
lbl_10017D24:
    .skip 0x4
.global gpsTurb
gpsTurb:
    .skip 0x8
.global lbl_10017D30
lbl_10017D30:
    .skip 0x8
.global lbl_10017D38
lbl_10017D38:
    .skip 0x8
.global lbl_10017D40
lbl_10017D40:
    .skip 0x10
.global lbl_10017D50
lbl_10017D50:
    .skip 0x4
.global lbl_10017D54
lbl_10017D54:
    .skip 0x184
.global lbl_10017ED8
lbl_10017ED8:
    .skip 0x4
.global lbl_10017EDC
lbl_10017EDC:
    .skip 0x4
.global lbl_10017EE0
lbl_10017EE0:
    .skip 0x14
.global lbl_10017EF4
lbl_10017EF4:
    .skip 0x4
.global lbl_10017EF8
lbl_10017EF8:
    .skip 0xC
.global lbl_10017F04
lbl_10017F04:
    .skip 0x4
.global lbl_10017F08
lbl_10017F08:
    .skip 0x4
.global lbl_10017F0C
lbl_10017F0C:
    .skip 0x4
.global lbl_10017F10
lbl_10017F10:
    .skip 0x4
.global lbl_10017F14
lbl_10017F14:
    .skip 0x10
.global lbl_10017F24
lbl_10017F24:
    .skip 0x4
.global lbl_10017F28
lbl_10017F28:
    .skip 0xC
.global lbl_10017F34
lbl_10017F34:
    .skip 0x4
.global lbl_10017F38
lbl_10017F38:
    .skip 0xC
.global lbl_10017F44
lbl_10017F44:
    .skip 0x34
.global lbl_10017F78
lbl_10017F78:
    .skip 0x8
.global lbl_10017F80
lbl_10017F80:
    .skip 0x4
.global gsAttackObjReadManager
gsAttackObjReadManager:
    .skip 0x18
.global lbl_10017F9C
lbl_10017F9C:
    .skip 0x4
.global lbl_10017FA0
lbl_10017FA0:
    .skip 0x8
.global lbl_10017FA8
lbl_10017FA8:
    .skip 0x4
.global lbl_10017FAC
lbl_10017FAC:
    .skip 0x4
.global lbl_10017FB0
lbl_10017FB0:
    .skip 0x4
.global lbl_10017FB4
lbl_10017FB4:
    .skip 0x4
.global lbl_10017FB8
lbl_10017FB8:
    .skip 0x4
.global lbl_10017FBC
lbl_10017FBC:
    .skip 0x4
.global lbl_10017FC0
lbl_10017FC0:
    .skip 0x4
.global lbl_10017FC4
lbl_10017FC4:
    .skip 0x8
.global lbl_10017FCC
lbl_10017FCC:
    .skip 0x4
.global lbl_10017FD0
lbl_10017FD0:
    .skip 0x4
.global lbl_10017FD4
lbl_10017FD4:
    .skip 0x8
.global lbl_10017FDC
lbl_10017FDC:
    .skip 0x34
.global lbl_10018010
lbl_10018010:
    .skip 0x4
.global lbl_10018014
lbl_10018014:
    .skip 0x4
.global lbl_10018018
lbl_10018018:
    .skip 0x4
.global lbl_1001801C
lbl_1001801C:
    .skip 0x4
.global lbl_10018020
lbl_10018020:
    .skip 0xC
.global lbl_1001802C
lbl_1001802C:
    .skip 0x8
.global gpsCPath
gpsCPath:
    .skip 0x8
.global lbl_1001803C
lbl_1001803C:
    .skip 0x440
.global lbl_1001847C
lbl_1001847C:
    .skip 0x3C0
.global lbl_1001883C
lbl_1001883C:
    .skip 0x3E4
.global lbl_10018C20
lbl_10018C20:
    .skip 0x18
.global lbl_10018C38
lbl_10018C38:
    #.skip 0xE9C
    .skip 0xC34
.global playerWindParticles
playerWindParticles:
    .skip 0x268
.global lbl_10019AD4
lbl_10019AD4:
    .skip 0x4
.global lbl_10019AD8
lbl_10019AD8:
    .skip 0xF0
.global lbl_10019BC8
lbl_10019BC8:
    .skip 0x4
.global lbl_10019BCC
lbl_10019BCC:
    .skip 0x54
.global lbl_10019C20
lbl_10019C20:
    .skip 0x24
.global lbl_10019C44
lbl_10019C44:
    .skip 0x4
.global lbl_10019C48
lbl_10019C48:
    .skip 0x18
.global lbl_10019C60
lbl_10019C60:
    .skip 0x4
.global gpsScriptFunc
gpsScriptFunc:
    .skip 0x4
.global gpsPaticleTbl
gpsPaticleTbl:
    .skip 0x4
.global lbl_10019C6C
lbl_10019C6C:
    .skip 0x4
.global gpsScriptShadow
gpsScriptShadow:
    .skip 0x4
.global gpsMorMotion_ScriptPlayer
gpsMorMotion_ScriptPlayer:
    .skip 0x200
.global gpsMatMotion_ScriptPlayer
gpsMatMotion_ScriptPlayer:
    .skip 0x200
.global gpsMotion_ScriptPlayer
gpsMotion_ScriptPlayer:
    .skip 0x200
.global lbl_1001A274
lbl_1001A274:
    .skip 0x4
.global gppsMorMotion_Script
gppsMorMotion_Script:
    .skip 0x4
.global gppasMorObj_Script
gppasMorObj_Script:
    .skip 0x8
.global gppsMorList_Script
gppsMorList_Script:
    .skip 0x4
.global gppsMatMotion_Script
gppsMatMotion_Script:
    .skip 0x4
.global gppasMatMotObj_Script
gppasMatMotObj_Script:
    .skip 0x8
.global gppsMtxList_Script
gppsMtxList_Script:
    .skip 0x4
.global gppsCamera_Script
gppsCamera_Script:
    .skip 0x4
.global gppsMotion_Script
gppsMotion_Script:
    .skip 0x4
.global gppsTexList_Script
gppsTexList_Script:
    .skip 0x4
.global gppsObject_Script
gppsObject_Script:
    .skip 0x4
.global lbl_1001A2A8
lbl_1001A2A8:
    .skip 0x4
.global lbl_1001A2AC
lbl_1001A2AC:
    .skip 0x3F8
.global gsCut_Script
gsCut_Script:
    .skip 0x40
.global LoadedDynamicDATFileCount
LoadedDynamicDATFileCount:
    .skip 0x4
.global lbl_1001A6E8
lbl_1001A6E8:
    .skip 0x38
.global lbl_1001A720
lbl_1001A720:
    .skip 0xBEE0
.global lbl_10026600
lbl_10026600:
    .skip 0x20
.global lbl_10026620
lbl_10026620:
    .skip 0x100
.global lbl_10026720
lbl_10026720:
    .skip 0x17C
.global lbl_1002689C
lbl_1002689C:
    .skip 0x271E4
.global lbl_1004DA80
lbl_1004DA80:
    .skip 0xC924
.global lbl_1005A3A4
lbl_1005A3A4:
    .skip 0x271F8
.global lbl_1008159C
lbl_1008159C:
    .skip 0x1B00
.global lbl_1008309C
lbl_1008309C:
    .skip 0x3E24
.global lbl_10086EC0
lbl_10086EC0:
    .skip 0xB48
.global lbl_10087A08
lbl_10087A08:
    .skip 0x8
.global lbl_10087A10
lbl_10087A10:
    .skip 0x44
.global gpasComPath
gpasComPath:
    .skip 0xB8
.global lbl_10087B0C
lbl_10087B0C:
    .skip 0x8C
.global lbl_10087B98
lbl_10087B98:
    .skip 0x8
.global lbl_10087BA0
lbl_10087BA0:
    .skip 0x8
.global lbl_10087BA8
lbl_10087BA8:
    .skip 0x8
.global lbl_10087BB0
lbl_10087BB0:
    .skip 0xC
.global lbl_10087BBC
lbl_10087BBC:
    .skip 0x1C
.global lbl_10087BD8
lbl_10087BD8:
    .skip 0x4
.global lbl_10087BDC
lbl_10087BDC:
    .skip 0x8
.global lbl_10087BE4
lbl_10087BE4:
    .skip 0x8
.global lbl_10087BEC
lbl_10087BEC:
    .skip 0x48
.global lbl_10087C34
lbl_10087C34:
    .skip 0x4
.global lbl_10087C38
lbl_10087C38:
    .skip 0x8
.global lbl_10087C40
lbl_10087C40:
    .skip 0x8
.global lbl_10087C48
lbl_10087C48:
    .skip 0x8
.global lbl_10087C50
lbl_10087C50:
    .skip 0x4
.global lbl_10087C54
lbl_10087C54:
    .skip 0x4
.global lbl_10087C58
lbl_10087C58:
    .skip 0x24
.global lbl_10087C7C
lbl_10087C7C:
    .skip 0x4
.global lbl_10087C80
lbl_10087C80:
    .skip 0x4
.global lbl_10087C84
lbl_10087C84:
    .skip 0x4
.global lbl_10087C88
lbl_10087C88:
    .skip 0x60
.global lbl_10087CE8
lbl_10087CE8:
    .skip 0x4
.global lbl_10087CEC
lbl_10087CEC:
    .skip 0x8
.global lbl_10087CF4
lbl_10087CF4:
    .skip 0x4
.global lbl_10087CF8
lbl_10087CF8:
    .skip 0x10
.global lbl_10087D08
lbl_10087D08:
    .skip 0x10
.global lbl_10087D18
lbl_10087D18:
    .skip 0x10
.global lbl_10087D28
lbl_10087D28:
    .skip 0x10
.global lbl_10087D38
lbl_10087D38:
    .skip 0x10
.global lbl_10087D48
lbl_10087D48:
    .skip 0x10
.global lbl_10087D58
lbl_10087D58:
    .skip 0x10
.global lbl_10087D68
lbl_10087D68:
    .skip 0x10
.global lbl_10087D78
lbl_10087D78:
    .skip 0x18
.global lbl_10087D90
lbl_10087D90:
    .skip 0x2C
.global lbl_10087DBC
lbl_10087DBC:
    .skip 0xC
.global lbl_10087DC8
lbl_10087DC8:
    .skip 0x8
.global lbl_10087DD0
lbl_10087DD0:
    .skip 0x8
.global lbl_10087DD8
lbl_10087DD8:
    .skip 0x8
.global lbl_10087DE0
lbl_10087DE0:
    .skip 0x8
.global lbl_10087DE8
lbl_10087DE8:
    .skip 0xC
.global gu32MissionStageNo
gu32MissionStageNo:
    .skip 0x4
.global gcopMissionSetTbl
gcopMissionSetTbl:
    .skip 0x4
.global lbl_10087DFC
lbl_10087DFC:
    .skip 0x4
.global lbl_10087E00
lbl_10087E00:
    .skip 0x14
.global lbl_10087E14
lbl_10087E14:
    .skip 0x40
.global gpsParticleCrash_BreakDown
gpsParticleCrash_BreakDown:
    .skip 0x4
.global lbl_10087E58
lbl_10087E58:
    .skip 0xC
.global lbl_10087E64
lbl_10087E64:
    .skip 0x14
.global gp2DSys
gp2DSys:
    .skip 0xC
.global lbl_10087E84
lbl_10087E84:
    .skip 0x8
.global lbl_10087E8C
lbl_10087E8C:
    .skip 0x8
.global lbl_10087E94
lbl_10087E94:
    .skip 0x8
.global lbl_10087E9C
lbl_10087E9C:
    .skip 0x8
.global gsAdvertise_Common2dDat
gsAdvertise_Common2dDat:
    .skip 0x8
.global lbl_10087EAC
lbl_10087EAC:
    .skip 0x8
.global lbl_10087EB4
lbl_10087EB4:
    .skip 0x8
.global lbl_10087EBC
lbl_10087EBC:
    .skip 0x8
.global lbl_10087EC4
lbl_10087EC4:
    .skip 0x8
.global lbl_10087ECC
lbl_10087ECC:
    .skip 0x8
.global lbl_10087ED4
lbl_10087ED4:
    .skip 0x8
.global gsMenu2dDat
gsMenu2dDat:
    .skip 0x10
.global lbl_10087EEC
lbl_10087EEC:
    .skip 0x14
.global lbl_10087F00
lbl_10087F00:
    .skip 0x4
.global gsSvlMgr
gsSvlMgr:
    .skip 0x30
.global gpsMissionPlayerTask
gpsMissionPlayerTask:
    .skip 0x4
.global lbl_10087F38
lbl_10087F38:
    .skip 0x28
.global lbl_10087F60
lbl_10087F60:
    .skip 0x4
.global lbl_10087F64
lbl_10087F64:
    .skip 0x4
.global lbl_10087F68
lbl_10087F68:
    .skip 0xC
.global lbl_10087F74
lbl_10087F74:
    .skip 0x4
.global lbl_10087F78
lbl_10087F78:
    .skip 0x38
.global lbl_10087FB0
lbl_10087FB0:
    .skip 0x14
.global lbl_10087FC4
lbl_10087FC4:
    .skip 0x28
.global lbl_10087FEC
lbl_10087FEC:
    .skip 0x4
.global lbl_10087FF0
lbl_10087FF0:
    .skip 0x34
.global lbl_10088024
lbl_10088024:
    .skip 0x8
.global lbl_1008802C
lbl_1008802C:
    .skip 0x48
.global lbl_10088074
lbl_10088074:
    .skip 0x10
.global lbl_10088084
lbl_10088084:
    .skip 0x44
.global lbl_100880C8
lbl_100880C8:
    .skip 0x4
.global gs32MenuState
gs32MenuState:
    .skip 0x4
.global lbl_100880D0
lbl_100880D0:
    .skip 0x1
.global lbl_100880D1
lbl_100880D1:
    .skip 0x1
.global lbl_100880D2
lbl_100880D2:
    .skip 0x1
.global lbl_100880D3
lbl_100880D3:
    .skip 0x1
.global gpsSpaniCommon2d
gpsSpaniCommon2d:
    .skip 0x10
.global tpasTwScript2D
tpasTwScript2D:
    .skip 0x80
.global gpsScript2DTexList
gpsScript2DTexList:
    .skip 0x8
.global lbl_1008816C
lbl_1008816C:
    .skip 0x4
.global lbl_10088170
lbl_10088170:
    .skip 0xC
.global lbl_1008817C
lbl_1008817C:
    .skip 0x4
.global lbl_10088180
lbl_10088180:
    .skip 0x4
.global lbl_10088184
lbl_10088184:
    .skip 0x4
.global lbl_10088188
lbl_10088188:
    .skip 0x4
.global lbl_1008818C
lbl_1008818C:
    .skip 0x64
.global lbl_100881F0
lbl_100881F0:
    .skip 0x4
.global lbl_100881F4
lbl_100881F4:
    .skip 0x4
.global lbl_100881F8
lbl_100881F8:
    .skip 0x4
.global lbl_100881FC
lbl_100881FC:
    .skip 0x4
.global lbl_10088200
lbl_10088200:
    .skip 0x14
.global lbl_10088214
lbl_10088214:
    .skip 0x4A50
.global lbl_1008CC64
lbl_1008CC64:
    .skip 0x4
.global lbl_1008CC68
lbl_1008CC68:
    .skip 0x8
.global lbl_1008CC70
lbl_1008CC70:
    .skip 0xCC
.global lbl_1008CD3C
lbl_1008CD3C:
    .skip 0x138
.global lbl_1008CE74
lbl_1008CE74:
    .skip 0x8
.global lbl_1008CE7C
lbl_1008CE7C:
    .skip 0x4
.global lbl_1008CE80
lbl_1008CE80:
    .skip 0x8
.global lbl_1008CE88
lbl_1008CE88:
    .skip 0x4
.global lbl_1008CE8C
lbl_1008CE8C:
    .skip 0x8
.global lbl_1008CE94
lbl_1008CE94:
    .skip 0x18
.global lbl_1008CEAC
lbl_1008CEAC:
    .skip 0x14
.global lbl_1008CEC0
lbl_1008CEC0:
    .skip 0xC
.global lbl_1008CECC
lbl_1008CECC:
    .skip 0x4
.global lbl_1008CED0
lbl_1008CED0:
    .skip 0x8
.global lbl_1008CED8
lbl_1008CED8:
    .skip 0x8
.global lbl_1008CEE0
lbl_1008CEE0:
    .skip 0x4
.global gu8StoryCupNo
gu8StoryCupNo:
    .skip 0x4
.global gpu8StoryMallocedHiAddr
gpu8StoryMallocedHiAddr:
    .skip 0x4
.global lbl_1008CEEC
lbl_1008CEEC:
    .skip 0x4
.global lbl_1008CEF0
lbl_1008CEF0:
    .skip 0x18
.global lbl_1008CF08
lbl_1008CF08:
    .skip 0x48
.global lbl_1008CF50
lbl_1008CF50:
    .skip 0x18
.global lbl_1008CF68
lbl_1008CF68:
    .skip 0xC
.global gu8WorldGPCupNo
gu8WorldGPCupNo:
    .skip 0xC
.global lbl_1008CF80
lbl_1008CF80:
    .skip 0x3004
.global lbl_1008FF84
lbl_1008FF84:
    .skip 0x7C
.global lbl_10090000
lbl_10090000:
    .skip 0x20
.global lbl_10090020
lbl_10090020:
    .skip 0x4E40
.global lbl_10094E60
lbl_10094E60:
    .skip 0x4
.global lbl_10094E64
lbl_10094E64:
    .skip 0x4
.global lbl_10094E68
lbl_10094E68:
    .skip 0x3C
.global lbl_10094EA4
lbl_10094EA4:
    .skip 0x4
.global lbl_10094EA8
lbl_10094EA8:
    .skip 0x18
.global gsGhostSaveData
gsGhostSaveData:
    .skip 0x18DC0
.global GameData
GameData:
    .skip 0x7F0
.global lbl_100AE470
lbl_100AE470:
    .skip 0x8
.global lbl_100AE478
lbl_100AE478:
    .skip 0x4
.global lbl_100AE47C
lbl_100AE47C:
    .skip 0x8
.global tpasTwScriptStr
tpasTwScriptStr:
    .skip 0x14
.global lbl_100AE498
lbl_100AE498:
    .skip 0x8
.global lbl_100AE4A0
lbl_100AE4A0:
    .skip 0x4
.global lbl_100AE4A4
lbl_100AE4A4:
    .skip 0x10
.global lbl_100AE4B4
lbl_100AE4B4:
    .skip 0x4
.global lbl_100AE4B8
lbl_100AE4B8:
    .skip 0x10
.global lbl_100AE4C8
lbl_100AE4C8:
    .skip 0xC
.global lbl_100AE4D4
lbl_100AE4D4:
    .skip 0x14
.global lbl_100AE4E8
lbl_100AE4E8:
    .skip 0x4
.global lbl_100AE4EC
lbl_100AE4EC:
    .skip 0x8
.global lbl_100AE4F4
lbl_100AE4F4:
    .skip 0x4
.global lbl_100AE4F8
lbl_100AE4F8:
    .skip 0xC
.global lbl_100AE504
lbl_100AE504:
    .skip 0x14
.global lbl_100AE518
lbl_100AE518:
    .skip 0x20
.global lbl_100AE538
lbl_100AE538:
    .skip 0x4
.global lbl_100AE53C
lbl_100AE53C:
    .skip 0x1
.global lbl_100AE53D
lbl_100AE53D:
    .skip 0x3
.global lbl_100AE540
lbl_100AE540:
    .skip 0x10
.global lbl_100AE550
lbl_100AE550:
    .skip 0x18
.global lbl_100AE568
lbl_100AE568:
    .skip 0xD8
.global lbl_100AE640
lbl_100AE640:
    .skip 0xA000
.global lbl_100B8640
lbl_100B8640:
    .skip 0x68
.global lbl_100B86A8
lbl_100B86A8:
    .skip 0x14
.global lbl_100B86BC
lbl_100B86BC:
    .skip 0x24
.global lbl_100B86E0
lbl_100B86E0:
    .skip 0x4
.global lbl_100B86E4
lbl_100B86E4:
    .skip 0x4
.global lbl_100B86E8
lbl_100B86E8:
    .skip 0x10
.global lbl_100B86F8
lbl_100B86F8:
    .skip 0x4
.global lbl_100B86FC
lbl_100B86FC:
    .skip 0x4
.global lbl_100B8700
lbl_100B8700:
    .skip 0x4
.global lbl_100B8704
lbl_100B8704:
    .skip 0x1C
.global lbl_100B8720
lbl_100B8720:
    .skip 0x38
.global lbl_100B8758
lbl_100B8758:
    .skip 0xF0
.global lbl_100B8848
lbl_100B8848:
    .skip 0xD8
.global lbl_100B8920
lbl_100B8920:
    .skip 0x4
.global lbl_100B8924
lbl_100B8924:
    .skip 0x4
.global lbl_100B8928
lbl_100B8928:
    .skip 0x18
.global lbl_100B8940
lbl_100B8940:
    .skip 0x18
.global lbl_100B8958
lbl_100B8958:
    .skip 0x18
.global lbl_100B8970
lbl_100B8970:
    .skip 0x4
.global lbl_100B8974
lbl_100B8974:
    .skip 0x8
.global lbl_100B897C
lbl_100B897C:
    .skip 0x8
.global lbl_100B8984
lbl_100B8984:
    .skip 0x8
.global lbl_100B898C
lbl_100B898C:
    .skip 0x4
.global lbl_100B8990
lbl_100B8990:
    .skip 0x8
.global lbl_100B8998
lbl_100B8998:
    .skip 0x4
.global gpasFrameTexCam
gpasFrameTexCam:
    .skip 0x80
.global gpasFrameTexCamMot
gpasFrameTexCamMot:
    .skip 0x80
.global gu8FrameTexMaxCamMotNum
gu8FrameTexMaxCamMotNum:
    .skip 0x4
.global lbl_100B8AA0
lbl_100B8AA0:
    .skip 0x4
.global lbl_100B8AA4
lbl_100B8AA4:
    .skip 0x64
.global lbl_100B8B08
lbl_100B8B08:
    .skip 0x8
.global lbl_100B8B10
lbl_100B8B10:
    .skip 0x4
.global lbl_100B8B14
lbl_100B8B14:
    .skip 0x64
.global lbl_100B8B78
lbl_100B8B78:
    .skip 0xC
.global lbl_100B8B84
lbl_100B8B84:
    .skip 0x8
.global lbl_100B8B8C
lbl_100B8B8C:
    .skip 0x8
.global lbl_100B8B94
lbl_100B8B94:
    .skip 0x18
.global lbl_100B8BAC
lbl_100B8BAC:
    .skip 0x4
.global lbl_100B8BB0
lbl_100B8BB0:
    .skip 0x8
.global lbl_100B8BB8
lbl_100B8BB8:
    .skip 0xA4
.global lbl_100B8C5C
lbl_100B8C5C:
    .skip 0x4
.global lbl_100B8C60
lbl_100B8C60:
    .skip 0x4
.global lbl_100B8C64
lbl_100B8C64:
    .skip 0x28
.global lbl_100B8C8C
lbl_100B8C8C:
    .skip 0x8
.global lbl_100B8C94
lbl_100B8C94:
    .skip 0x840
.global lbl_100B94D4
lbl_100B94D4:
    .skip 0x4
.global lbl_100B94D8
lbl_100B94D8:
    .skip 0x4
.global lbl_100B94DC
lbl_100B94DC:
    .skip 0x8
.global lbl_100B94E4
lbl_100B94E4:
    .skip 0x4
.global lbl_100B94E8
lbl_100B94E8:
    .skip 0x24
.global lbl_100B950C
lbl_100B950C:
    .skip 0x8
.global lbl_100B9514
lbl_100B9514:
    .skip 0xC
.global lbl_100B9520
lbl_100B9520:
    .skip 0x24
.global lbl_100B9544
lbl_100B9544:
    .skip 0x4
.global lbl_100B9548
lbl_100B9548:
    .skip 0x8
.global lbl_100B9550
lbl_100B9550:
    .skip 0xC
.global lbl_100B955C
lbl_100B955C:
    .skip 0x14
.global lbl_100B9570
lbl_100B9570:
    .skip 0xFC8
.global lbl_100BA538
lbl_100BA538:
    .skip 0xC
.global lbl_100BA544
lbl_100BA544:
    .skip 0x18
.global lbl_100BA55C
lbl_100BA55C:
    .skip 0x18
.global lbl_100BA574
lbl_100BA574:
    .skip 0xC
.global lbl_100BA580
lbl_100BA580:
    .skip 0x4
.global lbl_100BA584
lbl_100BA584:
    .skip 0x4
.global lbl_100BA588
lbl_100BA588:
    .skip 0x4
.global lbl_100BA58C
lbl_100BA58C:
    .skip 0x20
.global lbl_100BA5AC
lbl_100BA5AC:
    .skip 0x8
.global lbl_100BA5B4
lbl_100BA5B4:
    .skip 0x8
.global tpsExShadowDraw
tpsExShadowDraw:
    .skip 0x40
.global tpasTwScriptShadow
tpasTwScriptShadow:
    .skip 0x48
.global tpasTwScriptLineEffect
tpasTwScriptLineEffect:
    .skip 0x50
.global lbl_100BA694
lbl_100BA694:
    .skip 0x8
.global lbl_100BA69C
lbl_100BA69C:
    .skip 0x1C
.global lbl_100BA6B8
lbl_100BA6B8:
    .skip 0x8
.global lbl_100BA6C0
lbl_100BA6C0:
    .skip 0x4
.global lbl_100BA6C4
lbl_100BA6C4:
    .skip 0x4
.global lbl_100BA6C8
lbl_100BA6C8:
    .skip 0x4
.global lbl_100BA6CC
lbl_100BA6CC:
    .skip 0x8
.global lbl_100BA6D4
lbl_100BA6D4:
    .skip 0x4
.global lbl_100BA6D8
lbl_100BA6D8:
    .skip 0x8
.global lbl_100BA6E0
lbl_100BA6E0:
    .skip 0x4
.global lbl_100BA6E4
lbl_100BA6E4:
    .skip 0x4
.global lbl_100BA6E8
lbl_100BA6E8:
    .skip 0x4
.global lbl_100BA6EC
lbl_100BA6EC:
    .skip 0x8
.global bss_C24A273C
bss_C24A273C:
    .skip 0x4 # will hold the tornado timers
.global bss_C243568C
bss_C243568C:
    .skip 0x4 # will hold the hold to pause timer
.global bss_C24D91DC
bss_C24D91DC:
    .skip 0x4 # will hold the rainbow trail state
.global bss_CustomMusicID
bss_CustomMusicID:
    .skip 0x4
.global bss_BoardOnlyModelData
bss_BoardOnlyModelData:
    .skip 0x20
.global bss_BoardOnlyTextures
bss_BoardOnlyTextures:
    .skip 0x20