#include "OrderData.h"
#include "OrderDataDcps.h"

namespace OrderData
{
#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUVLSeq < OrderData::order, struct orderSeq_uniq_>;
#endif

const char * OrderData::orderTypeSupportInterface::_local_id = "IDL:::OrderData/orderTypeSupportInterface:1.0";

OrderData::orderTypeSupportInterface_ptr OrderData::orderTypeSupportInterface::_duplicate (OrderData::orderTypeSupportInterface_ptr p)
{
    if (p) p->m_count++;
    return p;
}

DDS::Boolean OrderData::orderTypeSupportInterface::_local_is_a (const char * _id)
{
    if (strcmp (_id, OrderData::orderTypeSupportInterface::_local_id) == 0)
    {
        return true;
    }

    typedef DDS::TypeSupport NestedBase_1;

    if (NestedBase_1::_local_is_a (_id))
    {
        return true;
    }

    return false;
}

OrderData::orderTypeSupportInterface_ptr OrderData::orderTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
    OrderData::orderTypeSupportInterface_ptr result = NULL;
    if (p && p->_is_a (OrderData::orderTypeSupportInterface::_local_id))
    {
        result = dynamic_cast < OrderData::orderTypeSupportInterface_ptr> (p);
        if (result) result->m_count++;
    }
    return result;
}

OrderData::orderTypeSupportInterface_ptr OrderData::orderTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
    OrderData::orderTypeSupportInterface_ptr result;
    result = dynamic_cast < OrderData::orderTypeSupportInterface_ptr> (p);
    if (result) result->m_count++;
    return result;
}

const char * OrderData::orderDataWriter::_local_id = "IDL:::OrderData/orderDataWriter:1.0";

OrderData::orderDataWriter_ptr OrderData::orderDataWriter::_duplicate (OrderData::orderDataWriter_ptr p)
{
    if (p) p->m_count++;
    return p;
}

DDS::Boolean OrderData::orderDataWriter::_local_is_a (const char * _id)
{
    if (strcmp (_id, OrderData::orderDataWriter::_local_id) == 0)
    {
        return true;
    }

    typedef DDS::DataWriter NestedBase_1;

    if (NestedBase_1::_local_is_a (_id))
    {
        return true;
    }

    return false;
}

OrderData::orderDataWriter_ptr OrderData::orderDataWriter::_narrow (DDS::Object_ptr p)
{
    OrderData::orderDataWriter_ptr result = NULL;
    if (p && p->_is_a (OrderData::orderDataWriter::_local_id))
    {
        result = dynamic_cast < OrderData::orderDataWriter_ptr> (p);
        if (result) result->m_count++;
    }
    return result;
}

OrderData::orderDataWriter_ptr OrderData::orderDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
    OrderData::orderDataWriter_ptr result;
    result = dynamic_cast < OrderData::orderDataWriter_ptr> (p);
    if (result) result->m_count++;
    return result;
}

const char * OrderData::orderDataReader::_local_id = "IDL:::OrderData/orderDataReader:1.0";

OrderData::orderDataReader_ptr OrderData::orderDataReader::_duplicate (OrderData::orderDataReader_ptr p)
{
    if (p) p->m_count++;
    return p;
}

DDS::Boolean OrderData::orderDataReader::_local_is_a (const char * _id)
{
    if (strcmp (_id, OrderData::orderDataReader::_local_id) == 0)
    {
        return true;
    }

    typedef DDS::DataReader NestedBase_1;

    if (NestedBase_1::_local_is_a (_id))
    {
        return true;
    }

    return false;
}

OrderData::orderDataReader_ptr OrderData::orderDataReader::_narrow (DDS::Object_ptr p)
{
    OrderData::orderDataReader_ptr result = NULL;
    if (p && p->_is_a (OrderData::orderDataReader::_local_id))
    {
        result = dynamic_cast < OrderData::orderDataReader_ptr> (p);
        if (result) result->m_count++;
    }
    return result;
}

OrderData::orderDataReader_ptr OrderData::orderDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
    OrderData::orderDataReader_ptr result;
    result = dynamic_cast < OrderData::orderDataReader_ptr> (p);
    if (result) result->m_count++;
    return result;
}

const char * OrderData::orderDataReaderView::_local_id = "IDL:::OrderData/orderDataReaderView:1.0";

OrderData::orderDataReaderView_ptr OrderData::orderDataReaderView::_duplicate (OrderData::orderDataReaderView_ptr p)
{
    if (p) p->m_count++;
    return p;
}

DDS::Boolean OrderData::orderDataReaderView::_local_is_a (const char * _id)
{
    if (strcmp (_id, OrderData::orderDataReaderView::_local_id) == 0)
    {
        return true;
    }

    typedef DDS::DataReaderView NestedBase_1;

    if (NestedBase_1::_local_is_a (_id))
    {
        return true;
    }

    return false;
}

OrderData::orderDataReaderView_ptr OrderData::orderDataReaderView::_narrow (DDS::Object_ptr p)
{
    OrderData::orderDataReaderView_ptr result = NULL;
    if (p && p->_is_a (OrderData::orderDataReaderView::_local_id))
    {
        result = dynamic_cast < OrderData::orderDataReaderView_ptr> (p);
        if (result) result->m_count++;
    }
    return result;
}

OrderData::orderDataReaderView_ptr OrderData::orderDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
    OrderData::orderDataReaderView_ptr result;
    result = dynamic_cast < OrderData::orderDataReaderView_ptr> (p);
    if (result) result->m_count++;
    return result;
}

}

