#include "orderData.h"
#include "orderDataDcps.h"

#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUVLSeq < order, struct orderSeq_uniq_>;
#endif

const char * orderTypeSupportInterface::_local_id = "IDL:/orderTypeSupportInterface:1.0";

orderTypeSupportInterface_ptr orderTypeSupportInterface::_duplicate (orderTypeSupportInterface_ptr p)
{
    if (p) p->m_count++;
    return p;
}

DDS::Boolean orderTypeSupportInterface::_local_is_a (const char * _id)
{
    if (strcmp (_id, orderTypeSupportInterface::_local_id) == 0)
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

orderTypeSupportInterface_ptr orderTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
    orderTypeSupportInterface_ptr result = NULL;
    if (p && p->_is_a (orderTypeSupportInterface::_local_id))
    {
        result = dynamic_cast < orderTypeSupportInterface_ptr> (p);
        if (result) result->m_count++;
    }
    return result;
}

orderTypeSupportInterface_ptr orderTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
    orderTypeSupportInterface_ptr result;
    result = dynamic_cast < orderTypeSupportInterface_ptr> (p);
    if (result) result->m_count++;
    return result;
}

const char * orderDataWriter::_local_id = "IDL:/orderDataWriter:1.0";

orderDataWriter_ptr orderDataWriter::_duplicate (orderDataWriter_ptr p)
{
    if (p) p->m_count++;
    return p;
}

DDS::Boolean orderDataWriter::_local_is_a (const char * _id)
{
    if (strcmp (_id, orderDataWriter::_local_id) == 0)
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

orderDataWriter_ptr orderDataWriter::_narrow (DDS::Object_ptr p)
{
    orderDataWriter_ptr result = NULL;
    if (p && p->_is_a (orderDataWriter::_local_id))
    {
        result = dynamic_cast < orderDataWriter_ptr> (p);
        if (result) result->m_count++;
    }
    return result;
}

orderDataWriter_ptr orderDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
    orderDataWriter_ptr result;
    result = dynamic_cast < orderDataWriter_ptr> (p);
    if (result) result->m_count++;
    return result;
}

const char * orderDataReader::_local_id = "IDL:/orderDataReader:1.0";

orderDataReader_ptr orderDataReader::_duplicate (orderDataReader_ptr p)
{
    if (p) p->m_count++;
    return p;
}

DDS::Boolean orderDataReader::_local_is_a (const char * _id)
{
    if (strcmp (_id, orderDataReader::_local_id) == 0)
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

orderDataReader_ptr orderDataReader::_narrow (DDS::Object_ptr p)
{
    orderDataReader_ptr result = NULL;
    if (p && p->_is_a (orderDataReader::_local_id))
    {
        result = dynamic_cast < orderDataReader_ptr> (p);
        if (result) result->m_count++;
    }
    return result;
}

orderDataReader_ptr orderDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
    orderDataReader_ptr result;
    result = dynamic_cast < orderDataReader_ptr> (p);
    if (result) result->m_count++;
    return result;
}

const char * orderDataReaderView::_local_id = "IDL:/orderDataReaderView:1.0";

orderDataReaderView_ptr orderDataReaderView::_duplicate (orderDataReaderView_ptr p)
{
    if (p) p->m_count++;
    return p;
}

DDS::Boolean orderDataReaderView::_local_is_a (const char * _id)
{
    if (strcmp (_id, orderDataReaderView::_local_id) == 0)
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

orderDataReaderView_ptr orderDataReaderView::_narrow (DDS::Object_ptr p)
{
    orderDataReaderView_ptr result = NULL;
    if (p && p->_is_a (orderDataReaderView::_local_id))
    {
        result = dynamic_cast < orderDataReaderView_ptr> (p);
        if (result) result->m_count++;
    }
    return result;
}

orderDataReaderView_ptr orderDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
    orderDataReaderView_ptr result;
    result = dynamic_cast < orderDataReaderView_ptr> (p);
    if (result) result->m_count++;
    return result;
}

