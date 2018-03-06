/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Components"
 * 	found in "../supl-common.asn"
 */

#ifndef _Velocity_H_
#define _Velocity_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Horvel.h"
#include "Horandvervel.h"
#include "Horveluncert.h"
#include "Horandveruncert.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /* Dependencies */
    typedef enum Velocity_PR
    {
        Velocity_PR_NOTHING, /* No components present */
        Velocity_PR_horvel,
        Velocity_PR_horandvervel,
        Velocity_PR_horveluncert,
        Velocity_PR_horandveruncert,
        /* Extensions may appear below */

    } Velocity_PR;

    /* Velocity */
    typedef struct Velocity
    {
        Velocity_PR present;
        union Velocity_u
        {
            Horvel_t horvel;
            Horandvervel_t horandvervel;
            Horveluncert_t horveluncert;
            Horandveruncert_t horandveruncert;
            /*
		 * This type is extensible,
		 * possible extensions are below.
		 */
        } choice;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } Velocity_t;

    /* Implementation */
    extern asn_TYPE_descriptor_t asn_DEF_Velocity;

#ifdef __cplusplus
}
#endif

#endif /* _Velocity_H_ */
#include <asn_internal.h>
