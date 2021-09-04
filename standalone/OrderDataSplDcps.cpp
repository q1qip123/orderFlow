#include "OrderDataSplDcps.h"
#include "ccpp_OrderData.h"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__OrderData_order__copyIn(
    c_base base,
    const struct ::OrderData::order *from,
    struct _OrderData_order *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->customerID = (c_long)from->customerID;
#ifdef OSPL_BOUNDS_CHECK
    if(from->dish){
        to->dish = c_stringNew_s(base, from->dish);
        if(to->dish == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'OrderData::order.dish' of type 'c_string' is NULL.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->dish = c_stringNew_s(base, from->dish);
    if(to->dish == NULL) {
        result = V_COPYIN_RESULT_OUT_OF_MEMORY;
    }
#endif
    to->amount = (c_long)from->amount;
    return result;
}

void
__OrderData_order__copyOut(
    const void *_from,
    void *_to)
{
    const struct _OrderData_order *from = (const struct _OrderData_order *)_from;
    struct ::OrderData::order *to = (struct ::OrderData::order *)_to;
    to->customerID = (::DDS::Long)from->customerID;
    to->dish = DDS::string_dup(from->dish ? from->dish : "");
    to->amount = (::DDS::Long)from->amount;
}

