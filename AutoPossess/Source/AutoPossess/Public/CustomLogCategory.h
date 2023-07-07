/*
* AutoPossess - Unreal Engine 5 Plugin 
*
* Copyright (C) 2023 VOORHU <voorhu@gmail.com> All Rights Reserved.
*/

#pragma once

#include "Logging/LogMacros.h"
//DECLARE_LOG_CATEGORY_EXTERN(Voorhu, Log, VeryVerbose);
DECLARE_LOG_CATEGORY_EXTERN(Voorhu, Log, All);

//DECLARE_LOG_CATEGORY_EXTERN(Voorhu, LogVerbosity, CompiledVerbosity);
//DEFINE_LOG_CATEGORY_STATIC(Voorhu, Log, All);

//#define NETMODE_WORLD (((GEngine == nullptr) \
//(GetWorld() == nullptr)) ? TEXT("") \
//    : (GEngine->GetNetMode(GetWorld()) == NM_Client) ? TEXT("[Client] ") \
//    : (GEngine->GetNetMode(GetWorld()) == NM_ListenServer) ? TEXT("[ListenServer] ") \
//    : (GEngine->GetNetMode(GetWorld()) == NM_DedicatedServer) ? TEXT("[DedicatedServer] ") \
//    : TEXT("[Standalone] "))
//
//#if _MSC_VER
//#define FUNC_NAME    TEXT(__FUNCTION__)
//#else // FIXME - GCC?
//#define FUNC_NAME    TEXT(__func__)
//#endif
//
//#define TRACE(Format, ...) \
//{ \
//    SET_WARN_COLOR(COLOR_CYAN);\
//    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
//    if (Msg == "") \
//    { \
//        UE_LOG(Voorhu, Log, TEXT("%s%s() : %s"), *GetNameSafe(this));\
//    } \
//    else \
//    { \
//        UE_LOG(Voorhu, Log, TEXT("%s%s() : %s"), *Msg);\
//    } \
//    CLEAR_WARN_COLOR();\
//}

#define TRACESUCCESS(Format, ...) \
{ \
    SET_WARN_COLOR(COLOR_CYAN);\
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(Voorhu, Log, TEXT("%s() : %s"), *Msg);\
    CLEAR_WARN_COLOR();\
}
#define TRACESTATIC(Format, ...) \
{ \
    SET_WARN_COLOR(COLOR_CYAN);\
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(Voorhu, Log, TEXT("%s() : %s"), *Msg);\
    CLEAR_WARN_COLOR();\
}

#define TRACEWARN(Format, ...) \
{ \
    SET_WARN_COLOR( COLOR_YELLOW );\
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(Voorhu, Log, TEXT("**WARNING** %s%s() : %s"), *Msg);\
    CLEAR_WARN_COLOR();\
}

#define TRACEERROR(Format, ...) \
{ \
    SET_WARN_COLOR( COLOR_RED );\
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(Voorhu, Log, TEXT("**ERROR** %s%s() : %s"), *Msg);\
    CLEAR_WARN_COLOR();\
}

#define SCREENDEBUG(Format, ...) \
{ \
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    if (Msg == "") \
    { \
        TCHAR StdMsg[MAX_SPRINTF] = TEXT(""); \
        FCString::Sprintf(StdMsg, TEXT("%s%s() : %s"), *GetNameSafe(this)); \
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, StdMsg); \
    } \
    else \
    { \
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, Msg); \
    } \
}