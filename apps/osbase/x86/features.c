/*++

Copyright (c) 2015 Minoca Corp. All Rights Reserved

Module Name:

    features.c

Abstract:

    This module implements support for return processor features.

Author:

    Evan Green 11-Nov-2015

Environment:

    User mode

--*/

//
// ------------------------------------------------------------------- Includes
//

#include "../osbasep.h"

//
// ---------------------------------------------------------------- Definitions
//

//
// ------------------------------------------------------ Data Type Definitions
//

//
// ----------------------------------------------- Internal Function Prototypes
//

//
// -------------------------------------------------------------------- Globals
//

//
// ------------------------------------------------------------------ Functions
//

OS_API
BOOL
OsTestProcessorFeature (
    ULONG Feature
    )

/*++

Routine Description:

    This routine determines if a given processor features is supported or not.

Arguments:

    Feature - Supplies the feature to test, which is an enum of type
        OS_<arch>_PROCESSOR_FEATURE.

Return Value:

    TRUE if the feature is set.

    FALSE if the feature is not set or not recognized.

--*/

{

    PUSER_SHARED_DATA Data;
    ULONG Mask;

    Data = OspGetUserSharedData();
    switch (Feature) {
    case OsX86Sysenter:
        Mask = X86_FEATURE_SYSENTER;
        break;

    case OsX86I686:
        Mask = X86_FEATURE_I686;
        break;

    default:
        Mask = 0;
        break;
    }

    if ((Data->ProcessorFeatures & Mask) != 0) {
        return TRUE;
    }

    return FALSE;
}

//
// --------------------------------------------------------- Internal Functions
//
