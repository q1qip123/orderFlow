#include "orderDataSplDcps.h"
#include "ccpp_orderData.h"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__order__copyIn(
    c_base base,
    const struct order *from,
    struct _order *to)
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
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'order.dish' of type 'c_string' is NULL.");
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
__order__copyOut(
    const void *_from,
    void *_to)
{
    const struct _order *from = (const struct _order *)_from;
    struct order *to = (struct order *)_to;
    to->customerID = (::DDS::Long)from->customerID;
    to->dish = DDS::string_dup(from->dish ? from->dish : "");
    to->amount = (::DDS::Long)from->amount;
}

