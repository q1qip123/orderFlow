
#include "DDSEntityManager.h"
#include "cstring"


void DDSEntityManager::createParticipant(const char *partitiontName)
{
  factory = DomainParticipantFactory::get_instance();
  domain = DOMAIN_ID_DEFAULT;
  checkHandle(factory.in(), "DDS::DomainParticipantFactory::get_instance");
  participant = factory->create_participant(domain, PARTICIPANT_QOS_DEFAULT, NULL,
    STATUS_MASK_NONE);
  checkHandle(participant.in(),
    "DDS::DomainParticipantFactory::create_participant");
  partition = partitiontName;
}

void DDSEntityManager::deleteParticipant()
{
  /* Free all resources */
  //status = factory->delete_contained_entities();
  //checkStatus(status, "DDS::DomainParticipant::delete_contained_entities");
  status = factory->delete_participant(participant.in());
  checkStatus(status, "DDS::DomainParticipantFactory::delete_participant");
}

void DDSEntityManager::registerType(TypeSupport *ts)
{
  typeName = ts->get_type_name();
  status = ts->register_type(participant, typeName);
  checkStatus(status, "register_type");
}

void DDSEntityManager::createTopic(char *odr_in_name, char *odr_out_name)
{
  status = participant->get_default_topic_qos(tQos1);
  checkStatus(status, "get_default_topic_qos failed");
  tQos1.reliability.kind = RELIABLE_RELIABILITY_QOS;
  tQos1.durability.kind = TRANSIENT_DURABILITY_QOS;

  status = participant->get_default_topic_qos(tQos2);
  checkStatus(status, "get_default_topic_qos failed");
  tQos2.reliability.kind = RELIABLE_RELIABILITY_QOS;
  tQos2.durability.kind = TRANSIENT_DURABILITY_QOS;
  
  odr_in = participant->create_topic(odr_in_name, typeName, tQos1, NULL, STATUS_MASK_NONE);
  checkHandle(odr_in.in(), "create_odr_in () failed");
  
  odr_out = participant->create_topic(odr_out_name, typeName, tQos2, NULL, STATUS_MASK_NONE);
  checkHandle(odr_out.in(), "create_odr_out () failed");
}

void DDSEntityManager::deleteTopic()
{
  status = participant->delete_topic(odr_in);
  checkStatus(status, "DDS.DomainParticipant.delete_odr_in");
  status = participant->delete_topic(odr_out);
  checkStatus(status, "DDS.DomainParticipant.delete_odr_out");

}

void DDSEntityManager::createPublisher()
{
  status = participant->get_default_publisher_qos(pub_qos);
  checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos");

  pub_qos.partition.name.length(1);
  pub_qos.partition.name[0] = partition;
  publisher = participant->create_publisher(pub_qos, NULL, STATUS_MASK_NONE);
  checkHandle(publisher.in(), "DDS::DomainParticipant::create_publisher");
}

void DDSEntityManager::deletePublisher()
{
  participant->delete_publisher(publisher);
}


void DDSEntityManager::createWriter(Topic_ptr topic)
{
    DataWriterQos dw_qos;
    status = publisher->get_default_datawriter_qos(dw_qos);
    checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos");
    status = publisher->copy_from_topic_qos(dw_qos, tQos1);
    checkStatus(status, "DDS::Publisher::copy_from_topic_qos");
    dw_qos.writer_data_lifecycle.autodispose_unregistered_instances = true;
    writer = publisher->create_datawriter(topic,
        dw_qos, NULL, STATUS_MASK_NONE);
    checkHandle(writer, "DDS::Publisher::create_datawriter (chatMessage)");
}

void DDSEntityManager::deleteWriter(DDS::DataWriter_ptr dataWriter)
{
   status = publisher->delete_datawriter(dataWriter);
   checkStatus(status, "DDS::Publisher::delete_datawriter ");
}

void DDSEntityManager::createSubscriber()
{
  status = participant->get_default_subscriber_qos(sub_qos);
  checkStatus(status, "DDS::DomainParticipant::get_default_subscriber_qos");
  sub_qos.partition.name.length(1);
  sub_qos.partition.name[0] = partition;
  subscriber = participant->create_subscriber(sub_qos, NULL, STATUS_MASK_NONE);
  checkHandle(subscriber.in(), "DDS::DomainParticipant::create_subscriber");
}

void DDSEntityManager::deleteSubscriber()
{
  participant->delete_subscriber(subscriber);
}

void DDSEntityManager::createReader(Topic_ptr topic)
{
   DataReaderQos rQos;
   status = subscriber->get_default_datareader_qos(rQos);
   checkStatus(status, "get_default_datareader_qos() failed");

   status = subscriber->copy_from_topic_qos(rQos, tQos2);
   checkStatus(status, "copy_from_topic_qos() failed");

   reader = subscriber->create_datareader(topic, rQos, NULL, STATUS_MASK_NONE);
   checkHandle(reader, "DDS::Subscriber::create_datareader ()");
}

void DDSEntityManager::deleteReader(DDS::DataReader_ptr dataReader)
{
   status = subscriber->delete_datareader(dataReader);
   checkStatus(status, "DDS::Subscriber::delete_datareader ");
}

DataReader_ptr DDSEntityManager::getReader()
{
  return DataReader::_duplicate(reader.in());
}

DataWriter_ptr DDSEntityManager::getWriter()
{
  return DataWriter::_duplicate(writer.in());
}

Publisher_ptr DDSEntityManager::getPublisher()
{
  return Publisher::_duplicate(publisher.in());
}

Subscriber_ptr DDSEntityManager::getSubscriber()
{
  return Subscriber::_duplicate(subscriber.in());
}

Topic_ptr DDSEntityManager::getOdrIn()
{
  return Topic::_duplicate(odr_in.in());
}

Topic_ptr DDSEntityManager::getOdrOut()
{
  return Topic::_duplicate(odr_out.in());
}

DomainParticipant_ptr DDSEntityManager::getParticipant()
{
  return DomainParticipant::_duplicate(participant.in());
}

DDSEntityManager::~DDSEntityManager(){

}
