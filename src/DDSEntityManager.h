
#ifndef _DDSENTITYMGR_
  #define _DDSENTITYMGR_


  #include "ccpp_dds_dcps.h"
  #include "CheckStatus.h"
  #include "cstring"
  using namespace DDS;

  class DDSEntityManager
  {

      /* Generic DDS entities */
      DomainParticipantFactory_var factory;
      DomainParticipant_var participant;
      Topic_var odr_in;
      Topic_var odr_out;
      Publisher_var publisher;
      Subscriber_var subscriber;
      DataWriter_var writer;
      DataReader_var reader;

      /* QosPolicy holders */
      TopicQos tQos1;
      TopicQos tQos2;
      PublisherQos pub_qos;
      SubscriberQos sub_qos;

	  /* DDS Identifiers */
      DomainId_t domain;
      ReturnCode_t status;

      DDS::String_var partition;
      DDS::String_var typeName;
    public:
      void createParticipant(const char *partitiontName);
      void deleteParticipant();
      void registerType(TypeSupport *ts);
      void createTopic(char *odr_in_name, char *odr_out_name);
      void deleteTopic();
      void createPublisher();
      void deletePublisher();
      void createWriter(Topic_ptr topic);
      void deleteWriter(DDS::DataWriter_ptr dataWriter);
      void createSubscriber();
      void deleteSubscriber();
      void createReader(Topic_ptr topic);
      void deleteReader(DDS::DataReader_ptr dataReader);
      DataReader_ptr getReader();
      DataWriter_ptr getWriter();
      Publisher_ptr getPublisher();
      Subscriber_ptr getSubscriber();
      Topic_ptr getOdrIn();
      Topic_ptr getOdrOut();
      DomainParticipant_ptr getParticipant();
      ~DDSEntityManager();
  };

#endif
