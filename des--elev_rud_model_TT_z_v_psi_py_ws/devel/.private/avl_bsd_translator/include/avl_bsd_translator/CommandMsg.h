// Generated by gencpp from file avl_bsd_translator/CommandMsg.msg
// DO NOT EDIT!


#ifndef AVL_BSD_TRANSLATOR_MESSAGE_COMMANDMSG_H
#define AVL_BSD_TRANSLATOR_MESSAGE_COMMANDMSG_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace avl_bsd_translator
{
template <class ContainerAllocator>
struct CommandMsg_
{
  typedef CommandMsg_<ContainerAllocator> Type;

  CommandMsg_()
    : COMMAND_NAME()
    , NAMES()
    , TYPES()
    , VALUES()  {
    }
  CommandMsg_(const ContainerAllocator& _alloc)
    : COMMAND_NAME(_alloc)
    , NAMES(_alloc)
    , TYPES(_alloc)
    , VALUES(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _COMMAND_NAME_type;
  _COMMAND_NAME_type COMMAND_NAME;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> _NAMES_type;
  _NAMES_type NAMES;

   typedef std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> _TYPES_type;
  _TYPES_type TYPES;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> _VALUES_type;
  _VALUES_type VALUES;





  typedef boost::shared_ptr< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> const> ConstPtr;

}; // struct CommandMsg_

typedef ::avl_bsd_translator::CommandMsg_<std::allocator<void> > CommandMsg;

typedef boost::shared_ptr< ::avl_bsd_translator::CommandMsg > CommandMsgPtr;
typedef boost::shared_ptr< ::avl_bsd_translator::CommandMsg const> CommandMsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::avl_bsd_translator::CommandMsg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::avl_bsd_translator::CommandMsg_<ContainerAllocator1> & lhs, const ::avl_bsd_translator::CommandMsg_<ContainerAllocator2> & rhs)
{
  return lhs.COMMAND_NAME == rhs.COMMAND_NAME &&
    lhs.NAMES == rhs.NAMES &&
    lhs.TYPES == rhs.TYPES &&
    lhs.VALUES == rhs.VALUES;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::avl_bsd_translator::CommandMsg_<ContainerAllocator1> & lhs, const ::avl_bsd_translator::CommandMsg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace avl_bsd_translator

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "90b8ee5c95edfe3031b61b3ce483a6c9";
  }

  static const char* value(const ::avl_bsd_translator::CommandMsg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x90b8ee5c95edfe30ULL;
  static const uint64_t static_value2 = 0x31b61b3ce483a6c9ULL;
};

template<class ContainerAllocator>
struct DataType< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "avl_bsd_translator/CommandMsg";
  }

  static const char* value(const ::avl_bsd_translator::CommandMsg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#===============================================================================\n"
"# Autonomous Vehicle Library Backseat Driver\n"
"#\n"
"# Description: Defines a ROS message that contains a command\n"
"#===============================================================================\n"
"\n"
"string COMMAND_NAME\n"
"string[] NAMES\n"
"uint8[] TYPES\n"
"string[] VALUES\n"
;
  }

  static const char* value(const ::avl_bsd_translator::CommandMsg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.COMMAND_NAME);
      stream.next(m.NAMES);
      stream.next(m.TYPES);
      stream.next(m.VALUES);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CommandMsg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::avl_bsd_translator::CommandMsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::avl_bsd_translator::CommandMsg_<ContainerAllocator>& v)
  {
    s << indent << "COMMAND_NAME: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.COMMAND_NAME);
    s << indent << "NAMES[]" << std::endl;
    for (size_t i = 0; i < v.NAMES.size(); ++i)
    {
      s << indent << "  NAMES[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.NAMES[i]);
    }
    s << indent << "TYPES[]" << std::endl;
    for (size_t i = 0; i < v.TYPES.size(); ++i)
    {
      s << indent << "  TYPES[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.TYPES[i]);
    }
    s << indent << "VALUES[]" << std::endl;
    for (size_t i = 0; i < v.VALUES.size(); ++i)
    {
      s << indent << "  VALUES[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.VALUES[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // AVL_BSD_TRANSLATOR_MESSAGE_COMMANDMSG_H