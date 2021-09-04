#ifndef _OrderDataDCPS_H_
#define _OrderDataDCPS_H_

#include "sacpp_mapping.h"
#include "dds_dcps.h"
#include "OrderData.h"


namespace OrderData
{
    class orderTypeSupportInterface;

    typedef orderTypeSupportInterface * orderTypeSupportInterface_ptr;
    typedef DDS_DCPSInterface_var < orderTypeSupportInterface> orderTypeSupportInterface_var;
    typedef DDS_DCPSInterface_out < orderTypeSupportInterface> orderTypeSupportInterface_out;


    class orderDataWriter;

    typedef orderDataWriter * orderDataWriter_ptr;
    typedef DDS_DCPSInterface_var < orderDataWriter> orderDataWriter_var;
    typedef DDS_DCPSInterface_out < orderDataWriter> orderDataWriter_out;


    class orderDataReader;

    typedef orderDataReader * orderDataReader_ptr;
    typedef DDS_DCPSInterface_var < orderDataReader> orderDataReader_var;
    typedef DDS_DCPSInterface_out < orderDataReader> orderDataReader_out;


    class orderDataReaderView;

    typedef orderDataReaderView * orderDataReaderView_ptr;
    typedef DDS_DCPSInterface_var < orderDataReaderView> orderDataReaderView_var;
    typedef DDS_DCPSInterface_out < orderDataReaderView> orderDataReaderView_out;

    struct orderSeq_uniq_ {};
    typedef DDS_DCPSUVLSeq < order, struct orderSeq_uniq_> orderSeq;
    typedef DDS_DCPSSequence_var < orderSeq> orderSeq_var;
    typedef DDS_DCPSSequence_out < orderSeq> orderSeq_out;

    class  orderTypeSupportInterface :
        virtual public DDS::TypeSupport
    { 
    public:
        typedef orderTypeSupportInterface_ptr _ptr_type;
        typedef orderTypeSupportInterface_var _var_type;

        static orderTypeSupportInterface_ptr _duplicate (orderTypeSupportInterface_ptr obj);
        DDS::Boolean _local_is_a (const char * id);

        static orderTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
        static orderTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
        static orderTypeSupportInterface_ptr _nil () { return 0; }
        static const char * _local_id;
        orderTypeSupportInterface_ptr _this () { return this; }


    protected:
        orderTypeSupportInterface () {};
        ~orderTypeSupportInterface () {};
    private:
        orderTypeSupportInterface (const orderTypeSupportInterface &);
        orderTypeSupportInterface & operator = (const orderTypeSupportInterface &);
    };

    class  orderDataWriter :
        virtual public DDS::DataWriter
    { 
    public:
        typedef orderDataWriter_ptr _ptr_type;
        typedef orderDataWriter_var _var_type;

        static orderDataWriter_ptr _duplicate (orderDataWriter_ptr obj);
        DDS::Boolean _local_is_a (const char * id);

        static orderDataWriter_ptr _narrow (DDS::Object_ptr obj);
        static orderDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
        static orderDataWriter_ptr _nil () { return 0; }
        static const char * _local_id;
        orderDataWriter_ptr _this () { return this; }

        virtual DDS::LongLong register_instance (const order& instance_data) = 0;
        virtual DDS::LongLong register_instance_w_timestamp (const order& instance_data, const DDS::Time_t& source_timestamp) = 0;
        virtual DDS::Long unregister_instance (const order& instance_data, DDS::LongLong handle) = 0;
        virtual DDS::Long unregister_instance_w_timestamp (const order& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
        virtual DDS::Long write (const order& instance_data, DDS::LongLong handle) = 0;
        virtual DDS::Long write_w_timestamp (const order& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
        virtual DDS::Long dispose (const order& instance_data, DDS::LongLong handle) = 0;
        virtual DDS::Long dispose_w_timestamp (const order& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
        virtual DDS::Long writedispose (const order& instance_data, DDS::LongLong handle) = 0;
        virtual DDS::Long writedispose_w_timestamp (const order& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
        virtual DDS::Long get_key_value (order& key_holder, DDS::LongLong handle) = 0;
        virtual DDS::LongLong lookup_instance (const order& instance_data) = 0;

    protected:
        orderDataWriter () {};
        ~orderDataWriter () {};
    private:
        orderDataWriter (const orderDataWriter &);
        orderDataWriter & operator = (const orderDataWriter &);
    };

    class  orderDataReader :
        virtual public DDS::DataReader
    { 
    public:
        typedef orderDataReader_ptr _ptr_type;
        typedef orderDataReader_var _var_type;

        static orderDataReader_ptr _duplicate (orderDataReader_ptr obj);
        DDS::Boolean _local_is_a (const char * id);

        static orderDataReader_ptr _narrow (DDS::Object_ptr obj);
        static orderDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
        static orderDataReader_ptr _nil () { return 0; }
        static const char * _local_id;
        orderDataReader_ptr _this () { return this; }

        virtual DDS::Long read (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long take (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long read_w_condition (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
        virtual DDS::Long take_w_condition (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
        virtual DDS::Long read_next_sample (order& received_data, DDS::SampleInfo& sample_info) = 0;
        virtual DDS::Long take_next_sample (order& received_data, DDS::SampleInfo& sample_info) = 0;
        virtual DDS::Long read_instance (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long take_instance (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long read_next_instance (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long take_next_instance (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long read_next_instance_w_condition (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
        virtual DDS::Long take_next_instance_w_condition (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
        virtual DDS::Long return_loan (orderSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
        virtual DDS::Long get_key_value (order& key_holder, DDS::LongLong handle) = 0;
        virtual DDS::LongLong lookup_instance (const order& instance) = 0;

    protected:
        orderDataReader () {};
        ~orderDataReader () {};
    private:
        orderDataReader (const orderDataReader &);
        orderDataReader & operator = (const orderDataReader &);
    };

    class  orderDataReaderView :
        virtual public DDS::DataReaderView
    { 
    public:
        typedef orderDataReaderView_ptr _ptr_type;
        typedef orderDataReaderView_var _var_type;

        static orderDataReaderView_ptr _duplicate (orderDataReaderView_ptr obj);
        DDS::Boolean _local_is_a (const char * id);

        static orderDataReaderView_ptr _narrow (DDS::Object_ptr obj);
        static orderDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
        static orderDataReaderView_ptr _nil () { return 0; }
        static const char * _local_id;
        orderDataReaderView_ptr _this () { return this; }

        virtual DDS::Long read (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long take (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long read_w_condition (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
        virtual DDS::Long take_w_condition (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
        virtual DDS::Long read_next_sample (order& received_data, DDS::SampleInfo& sample_info) = 0;
        virtual DDS::Long take_next_sample (order& received_data, DDS::SampleInfo& sample_info) = 0;
        virtual DDS::Long read_instance (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long take_instance (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long read_next_instance (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long take_next_instance (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
        virtual DDS::Long read_next_instance_w_condition (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
        virtual DDS::Long take_next_instance_w_condition (orderSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
        virtual DDS::Long return_loan (orderSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
        virtual DDS::Long get_key_value (order& key_holder, DDS::LongLong handle) = 0;
        virtual DDS::LongLong lookup_instance (const order& instance) = 0;

    protected:
        orderDataReaderView () {};
        ~orderDataReaderView () {};
    private:
        orderDataReaderView (const orderDataReaderView &);
        orderDataReaderView & operator = (const orderDataReaderView &);
    };
}

#endif
