#ifndef OrderDataSPLTYPES_H
#define OrderDataSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "ccpp_OrderData.h"


extern c_metaObject __OrderData_OrderData__load (c_base base);

extern const char *OrderData_order_metaDescriptor[];
extern const int OrderData_order_metaDescriptorArrLength;
extern const int OrderData_order_metaDescriptorLength;
extern c_metaObject __OrderData_order__load (c_base base);
struct _OrderData_order ;
extern  v_copyin_result __OrderData_order__copyIn(c_base base, const struct OrderData::order *from, struct _OrderData_order *to);
extern  void __OrderData_order__copyOut(const void *_from, void *_to);
struct _OrderData_order {
    c_long customerID;
    c_string dish;
    c_long amount;
};

#undef OS_API
#endif
