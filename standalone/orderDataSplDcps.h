#ifndef orderDataSPLTYPES_H
#define orderDataSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "ccpp_orderData.h"


extern const char *order_metaDescriptor[];
extern const int order_metaDescriptorArrLength;
extern const int order_metaDescriptorLength;
extern c_metaObject __order__load (c_base base);
struct _order ;
extern  v_copyin_result __order__copyIn(c_base base, const struct order *from, struct _order *to);
extern  void __order__copyOut(const void *_from, void *_to);
struct _order {
    c_long customerID;
    c_string dish;
    c_long amount;
};

#undef OS_API
#endif
