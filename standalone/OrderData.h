#ifndef _OrderData_H_
#define _OrderData_H_

#include "sacpp_mapping.h"
#include "cpp_dcps_if.h"


namespace OrderData
{
    struct  order
    {
        ::DDS::Long customerID;
        ::DDS::String_mgr dish;
        ::DDS::Long amount;
    };

    typedef DDS_DCPSStruct_var<order> order_var;
    typedef DDS_DCPSStruct_out < order> order_out;

}

#endif /* _OrderData_H_ */
