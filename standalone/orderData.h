#ifndef _orderData_H_
#define _orderData_H_

#include "sacpp_mapping.h"
#include "cpp_dcps_if.h"


struct  order
{
    ::DDS::Long customerID;
    ::DDS::String_mgr dish;
    ::DDS::Long amount;
};

typedef DDS_DCPSStruct_var<order> order_var;
typedef DDS_DCPSStruct_out < order> order_out;

#endif /* _orderData_H_ */
