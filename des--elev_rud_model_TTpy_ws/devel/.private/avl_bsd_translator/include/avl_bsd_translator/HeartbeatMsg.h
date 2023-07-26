// Generated by gencpp from file avl_bsd_translator/HeartbeatMsg.msg
// DO NOT EDIT!


#ifndef AVL_BSD_TRANSLATOR_MESSAGE_HEARTBEATMSG_H
#define AVL_BSD_TRANSLATOR_MESSAGE_HEARTBEATMSG_H


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
struct HeartbeatMsg_
{
  typedef HeartbeatMsg_<ContainerAllocator> Type;

  HeartbeatMsg_()
    : HEARTBEAT_STATUS(0)
    , HEARTBEAT_UMODEM_SYNC(0)
    , HEARTBEAT_IRIDIUM_STR(0)
    , HEARTBEAT_MISSION_MODE(0)
    , HEARTBEAT_FSD_MISSION_STATE(0)
    , HEARTBEAT_FSD_CURRENT_ACTION(0)
    , HEARTBEAT_FSD_TOTAL_ACTIONS(0)
    , HEARTBEAT_BSD_MISSION_STATE(0)
    , HEARTBEAT_BSD_CURRENT_ACTION(0)
    , HEARTBEAT_BSD_TOTAL_ACTIONS(0)
    , HEARTBEAT_GPS_SATS(0)
    , HEARTBEAT_NAV_INITIALIZED(0)
    , HEARTBEAT_ROLL(0.0)
    , HEARTBEAT_PITCH(0.0)
    , HEARTBEAT_YAW(0.0)
    , HEARTBEAT_WX(0.0)
    , HEARTBEAT_WY(0.0)
    , HEARTBEAT_WZ(0.0)
    , HEARTBEAT_AX(0.0)
    , HEARTBEAT_AY(0.0)
    , HEARTBEAT_AZ(0.0)
    , HEARTBEAT_VN(0.0)
    , HEARTBEAT_VE(0.0)
    , HEARTBEAT_VD(0.0)
    , HEARTBEAT_DEPTH(0.0)
    , HEARTBEAT_HEIGHT(0.0)
    , HEARTBEAT_RPM(0.0)
    , HEARTBEAT_VOLTAGE(0.0)
    , HEARTBEAT_FSD_ACTION_PERCENT(0.0)
    , HEARTBEAT_BSD_ACTION_PERCENT(0.0)
    , HEARTBEAT_GPS_LAT(0.0)
    , HEARTBEAT_GPS_LON(0.0)
    , HEARTBEAT_GPS_ALT(0.0)
    , HEARTBEAT_NAV_LAT(0.0)
    , HEARTBEAT_NAV_LON(0.0)
    , HEARTBEAT_NAV_ALT(0.0)
    , HEARTBEAT_NAV_YAW_STD(0.0)
    , HEARTBEAT_NAV_AVG_POS_ERR(0.0)  {
    }
  HeartbeatMsg_(const ContainerAllocator& _alloc)
    : HEARTBEAT_STATUS(0)
    , HEARTBEAT_UMODEM_SYNC(0)
    , HEARTBEAT_IRIDIUM_STR(0)
    , HEARTBEAT_MISSION_MODE(0)
    , HEARTBEAT_FSD_MISSION_STATE(0)
    , HEARTBEAT_FSD_CURRENT_ACTION(0)
    , HEARTBEAT_FSD_TOTAL_ACTIONS(0)
    , HEARTBEAT_BSD_MISSION_STATE(0)
    , HEARTBEAT_BSD_CURRENT_ACTION(0)
    , HEARTBEAT_BSD_TOTAL_ACTIONS(0)
    , HEARTBEAT_GPS_SATS(0)
    , HEARTBEAT_NAV_INITIALIZED(0)
    , HEARTBEAT_ROLL(0.0)
    , HEARTBEAT_PITCH(0.0)
    , HEARTBEAT_YAW(0.0)
    , HEARTBEAT_WX(0.0)
    , HEARTBEAT_WY(0.0)
    , HEARTBEAT_WZ(0.0)
    , HEARTBEAT_AX(0.0)
    , HEARTBEAT_AY(0.0)
    , HEARTBEAT_AZ(0.0)
    , HEARTBEAT_VN(0.0)
    , HEARTBEAT_VE(0.0)
    , HEARTBEAT_VD(0.0)
    , HEARTBEAT_DEPTH(0.0)
    , HEARTBEAT_HEIGHT(0.0)
    , HEARTBEAT_RPM(0.0)
    , HEARTBEAT_VOLTAGE(0.0)
    , HEARTBEAT_FSD_ACTION_PERCENT(0.0)
    , HEARTBEAT_BSD_ACTION_PERCENT(0.0)
    , HEARTBEAT_GPS_LAT(0.0)
    , HEARTBEAT_GPS_LON(0.0)
    , HEARTBEAT_GPS_ALT(0.0)
    , HEARTBEAT_NAV_LAT(0.0)
    , HEARTBEAT_NAV_LON(0.0)
    , HEARTBEAT_NAV_ALT(0.0)
    , HEARTBEAT_NAV_YAW_STD(0.0)
    , HEARTBEAT_NAV_AVG_POS_ERR(0.0)  {
  (void)_alloc;
    }



   typedef uint8_t _HEARTBEAT_STATUS_type;
  _HEARTBEAT_STATUS_type HEARTBEAT_STATUS;

   typedef uint8_t _HEARTBEAT_UMODEM_SYNC_type;
  _HEARTBEAT_UMODEM_SYNC_type HEARTBEAT_UMODEM_SYNC;

   typedef uint8_t _HEARTBEAT_IRIDIUM_STR_type;
  _HEARTBEAT_IRIDIUM_STR_type HEARTBEAT_IRIDIUM_STR;

   typedef uint8_t _HEARTBEAT_MISSION_MODE_type;
  _HEARTBEAT_MISSION_MODE_type HEARTBEAT_MISSION_MODE;

   typedef uint8_t _HEARTBEAT_FSD_MISSION_STATE_type;
  _HEARTBEAT_FSD_MISSION_STATE_type HEARTBEAT_FSD_MISSION_STATE;

   typedef uint8_t _HEARTBEAT_FSD_CURRENT_ACTION_type;
  _HEARTBEAT_FSD_CURRENT_ACTION_type HEARTBEAT_FSD_CURRENT_ACTION;

   typedef uint8_t _HEARTBEAT_FSD_TOTAL_ACTIONS_type;
  _HEARTBEAT_FSD_TOTAL_ACTIONS_type HEARTBEAT_FSD_TOTAL_ACTIONS;

   typedef uint8_t _HEARTBEAT_BSD_MISSION_STATE_type;
  _HEARTBEAT_BSD_MISSION_STATE_type HEARTBEAT_BSD_MISSION_STATE;

   typedef uint8_t _HEARTBEAT_BSD_CURRENT_ACTION_type;
  _HEARTBEAT_BSD_CURRENT_ACTION_type HEARTBEAT_BSD_CURRENT_ACTION;

   typedef uint8_t _HEARTBEAT_BSD_TOTAL_ACTIONS_type;
  _HEARTBEAT_BSD_TOTAL_ACTIONS_type HEARTBEAT_BSD_TOTAL_ACTIONS;

   typedef uint8_t _HEARTBEAT_GPS_SATS_type;
  _HEARTBEAT_GPS_SATS_type HEARTBEAT_GPS_SATS;

   typedef uint8_t _HEARTBEAT_NAV_INITIALIZED_type;
  _HEARTBEAT_NAV_INITIALIZED_type HEARTBEAT_NAV_INITIALIZED;

   typedef double _HEARTBEAT_ROLL_type;
  _HEARTBEAT_ROLL_type HEARTBEAT_ROLL;

   typedef double _HEARTBEAT_PITCH_type;
  _HEARTBEAT_PITCH_type HEARTBEAT_PITCH;

   typedef double _HEARTBEAT_YAW_type;
  _HEARTBEAT_YAW_type HEARTBEAT_YAW;

   typedef double _HEARTBEAT_WX_type;
  _HEARTBEAT_WX_type HEARTBEAT_WX;

   typedef double _HEARTBEAT_WY_type;
  _HEARTBEAT_WY_type HEARTBEAT_WY;

   typedef double _HEARTBEAT_WZ_type;
  _HEARTBEAT_WZ_type HEARTBEAT_WZ;

   typedef double _HEARTBEAT_AX_type;
  _HEARTBEAT_AX_type HEARTBEAT_AX;

   typedef double _HEARTBEAT_AY_type;
  _HEARTBEAT_AY_type HEARTBEAT_AY;

   typedef double _HEARTBEAT_AZ_type;
  _HEARTBEAT_AZ_type HEARTBEAT_AZ;

   typedef double _HEARTBEAT_VN_type;
  _HEARTBEAT_VN_type HEARTBEAT_VN;

   typedef double _HEARTBEAT_VE_type;
  _HEARTBEAT_VE_type HEARTBEAT_VE;

   typedef double _HEARTBEAT_VD_type;
  _HEARTBEAT_VD_type HEARTBEAT_VD;

   typedef double _HEARTBEAT_DEPTH_type;
  _HEARTBEAT_DEPTH_type HEARTBEAT_DEPTH;

   typedef double _HEARTBEAT_HEIGHT_type;
  _HEARTBEAT_HEIGHT_type HEARTBEAT_HEIGHT;

   typedef double _HEARTBEAT_RPM_type;
  _HEARTBEAT_RPM_type HEARTBEAT_RPM;

   typedef double _HEARTBEAT_VOLTAGE_type;
  _HEARTBEAT_VOLTAGE_type HEARTBEAT_VOLTAGE;

   typedef double _HEARTBEAT_FSD_ACTION_PERCENT_type;
  _HEARTBEAT_FSD_ACTION_PERCENT_type HEARTBEAT_FSD_ACTION_PERCENT;

   typedef double _HEARTBEAT_BSD_ACTION_PERCENT_type;
  _HEARTBEAT_BSD_ACTION_PERCENT_type HEARTBEAT_BSD_ACTION_PERCENT;

   typedef double _HEARTBEAT_GPS_LAT_type;
  _HEARTBEAT_GPS_LAT_type HEARTBEAT_GPS_LAT;

   typedef double _HEARTBEAT_GPS_LON_type;
  _HEARTBEAT_GPS_LON_type HEARTBEAT_GPS_LON;

   typedef double _HEARTBEAT_GPS_ALT_type;
  _HEARTBEAT_GPS_ALT_type HEARTBEAT_GPS_ALT;

   typedef double _HEARTBEAT_NAV_LAT_type;
  _HEARTBEAT_NAV_LAT_type HEARTBEAT_NAV_LAT;

   typedef double _HEARTBEAT_NAV_LON_type;
  _HEARTBEAT_NAV_LON_type HEARTBEAT_NAV_LON;

   typedef double _HEARTBEAT_NAV_ALT_type;
  _HEARTBEAT_NAV_ALT_type HEARTBEAT_NAV_ALT;

   typedef double _HEARTBEAT_NAV_YAW_STD_type;
  _HEARTBEAT_NAV_YAW_STD_type HEARTBEAT_NAV_YAW_STD;

   typedef double _HEARTBEAT_NAV_AVG_POS_ERR_type;
  _HEARTBEAT_NAV_AVG_POS_ERR_type HEARTBEAT_NAV_AVG_POS_ERR;





  typedef boost::shared_ptr< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> const> ConstPtr;

}; // struct HeartbeatMsg_

typedef ::avl_bsd_translator::HeartbeatMsg_<std::allocator<void> > HeartbeatMsg;

typedef boost::shared_ptr< ::avl_bsd_translator::HeartbeatMsg > HeartbeatMsgPtr;
typedef boost::shared_ptr< ::avl_bsd_translator::HeartbeatMsg const> HeartbeatMsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator1> & lhs, const ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator2> & rhs)
{
  return lhs.HEARTBEAT_STATUS == rhs.HEARTBEAT_STATUS &&
    lhs.HEARTBEAT_UMODEM_SYNC == rhs.HEARTBEAT_UMODEM_SYNC &&
    lhs.HEARTBEAT_IRIDIUM_STR == rhs.HEARTBEAT_IRIDIUM_STR &&
    lhs.HEARTBEAT_MISSION_MODE == rhs.HEARTBEAT_MISSION_MODE &&
    lhs.HEARTBEAT_FSD_MISSION_STATE == rhs.HEARTBEAT_FSD_MISSION_STATE &&
    lhs.HEARTBEAT_FSD_CURRENT_ACTION == rhs.HEARTBEAT_FSD_CURRENT_ACTION &&
    lhs.HEARTBEAT_FSD_TOTAL_ACTIONS == rhs.HEARTBEAT_FSD_TOTAL_ACTIONS &&
    lhs.HEARTBEAT_BSD_MISSION_STATE == rhs.HEARTBEAT_BSD_MISSION_STATE &&
    lhs.HEARTBEAT_BSD_CURRENT_ACTION == rhs.HEARTBEAT_BSD_CURRENT_ACTION &&
    lhs.HEARTBEAT_BSD_TOTAL_ACTIONS == rhs.HEARTBEAT_BSD_TOTAL_ACTIONS &&
    lhs.HEARTBEAT_GPS_SATS == rhs.HEARTBEAT_GPS_SATS &&
    lhs.HEARTBEAT_NAV_INITIALIZED == rhs.HEARTBEAT_NAV_INITIALIZED &&
    lhs.HEARTBEAT_ROLL == rhs.HEARTBEAT_ROLL &&
    lhs.HEARTBEAT_PITCH == rhs.HEARTBEAT_PITCH &&
    lhs.HEARTBEAT_YAW == rhs.HEARTBEAT_YAW &&
    lhs.HEARTBEAT_WX == rhs.HEARTBEAT_WX &&
    lhs.HEARTBEAT_WY == rhs.HEARTBEAT_WY &&
    lhs.HEARTBEAT_WZ == rhs.HEARTBEAT_WZ &&
    lhs.HEARTBEAT_AX == rhs.HEARTBEAT_AX &&
    lhs.HEARTBEAT_AY == rhs.HEARTBEAT_AY &&
    lhs.HEARTBEAT_AZ == rhs.HEARTBEAT_AZ &&
    lhs.HEARTBEAT_VN == rhs.HEARTBEAT_VN &&
    lhs.HEARTBEAT_VE == rhs.HEARTBEAT_VE &&
    lhs.HEARTBEAT_VD == rhs.HEARTBEAT_VD &&
    lhs.HEARTBEAT_DEPTH == rhs.HEARTBEAT_DEPTH &&
    lhs.HEARTBEAT_HEIGHT == rhs.HEARTBEAT_HEIGHT &&
    lhs.HEARTBEAT_RPM == rhs.HEARTBEAT_RPM &&
    lhs.HEARTBEAT_VOLTAGE == rhs.HEARTBEAT_VOLTAGE &&
    lhs.HEARTBEAT_FSD_ACTION_PERCENT == rhs.HEARTBEAT_FSD_ACTION_PERCENT &&
    lhs.HEARTBEAT_BSD_ACTION_PERCENT == rhs.HEARTBEAT_BSD_ACTION_PERCENT &&
    lhs.HEARTBEAT_GPS_LAT == rhs.HEARTBEAT_GPS_LAT &&
    lhs.HEARTBEAT_GPS_LON == rhs.HEARTBEAT_GPS_LON &&
    lhs.HEARTBEAT_GPS_ALT == rhs.HEARTBEAT_GPS_ALT &&
    lhs.HEARTBEAT_NAV_LAT == rhs.HEARTBEAT_NAV_LAT &&
    lhs.HEARTBEAT_NAV_LON == rhs.HEARTBEAT_NAV_LON &&
    lhs.HEARTBEAT_NAV_ALT == rhs.HEARTBEAT_NAV_ALT &&
    lhs.HEARTBEAT_NAV_YAW_STD == rhs.HEARTBEAT_NAV_YAW_STD &&
    lhs.HEARTBEAT_NAV_AVG_POS_ERR == rhs.HEARTBEAT_NAV_AVG_POS_ERR;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator1> & lhs, const ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace avl_bsd_translator

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ac1c7d62091790946cc68f56d9855dd5";
  }

  static const char* value(const ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xac1c7d6209179094ULL;
  static const uint64_t static_value2 = 0x6cc68f56d9855dd5ULL;
};

template<class ContainerAllocator>
struct DataType< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "avl_bsd_translator/HeartbeatMsg";
  }

  static const char* value(const ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#===============================================================================\n"
"# Autonomous Vehicle Library Backseat Driver\n"
"#\n"
"# Description: Defines a ROS message that contains a heartbeat\n"
"#===============================================================================\n"
"\n"
"\n"
"uint8 HEARTBEAT_STATUS\n"
"uint8 HEARTBEAT_UMODEM_SYNC\n"
"uint8 HEARTBEAT_IRIDIUM_STR\n"
"\n"
"uint8 HEARTBEAT_MISSION_MODE\n"
"uint8 HEARTBEAT_FSD_MISSION_STATE\n"
"uint8 HEARTBEAT_FSD_CURRENT_ACTION\n"
"uint8 HEARTBEAT_FSD_TOTAL_ACTIONS\n"
"uint8 HEARTBEAT_BSD_MISSION_STATE\n"
"uint8 HEARTBEAT_BSD_CURRENT_ACTION\n"
"uint8 HEARTBEAT_BSD_TOTAL_ACTIONS\n"
"uint8 HEARTBEAT_GPS_SATS\n"
"uint8 HEARTBEAT_NAV_INITIALIZED\n"
"\n"
"float64 HEARTBEAT_ROLL\n"
"float64 HEARTBEAT_PITCH\n"
"float64 HEARTBEAT_YAW\n"
"float64 HEARTBEAT_WX\n"
"float64 HEARTBEAT_WY\n"
"float64 HEARTBEAT_WZ\n"
"float64 HEARTBEAT_AX\n"
"float64 HEARTBEAT_AY\n"
"float64 HEARTBEAT_AZ\n"
"float64 HEARTBEAT_VN\n"
"float64 HEARTBEAT_VE\n"
"float64 HEARTBEAT_VD\n"
"float64 HEARTBEAT_DEPTH\n"
"float64 HEARTBEAT_HEIGHT\n"
"float64 HEARTBEAT_RPM\n"
"float64 HEARTBEAT_VOLTAGE\n"
"float64 HEARTBEAT_FSD_ACTION_PERCENT\n"
"float64 HEARTBEAT_BSD_ACTION_PERCENT\n"
"float64 HEARTBEAT_GPS_LAT\n"
"float64 HEARTBEAT_GPS_LON\n"
"float64 HEARTBEAT_GPS_ALT\n"
"float64 HEARTBEAT_NAV_LAT\n"
"float64 HEARTBEAT_NAV_LON\n"
"float64 HEARTBEAT_NAV_ALT\n"
"float64 HEARTBEAT_NAV_YAW_STD\n"
"float64 HEARTBEAT_NAV_AVG_POS_ERR\n"
;
  }

  static const char* value(const ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.HEARTBEAT_STATUS);
      stream.next(m.HEARTBEAT_UMODEM_SYNC);
      stream.next(m.HEARTBEAT_IRIDIUM_STR);
      stream.next(m.HEARTBEAT_MISSION_MODE);
      stream.next(m.HEARTBEAT_FSD_MISSION_STATE);
      stream.next(m.HEARTBEAT_FSD_CURRENT_ACTION);
      stream.next(m.HEARTBEAT_FSD_TOTAL_ACTIONS);
      stream.next(m.HEARTBEAT_BSD_MISSION_STATE);
      stream.next(m.HEARTBEAT_BSD_CURRENT_ACTION);
      stream.next(m.HEARTBEAT_BSD_TOTAL_ACTIONS);
      stream.next(m.HEARTBEAT_GPS_SATS);
      stream.next(m.HEARTBEAT_NAV_INITIALIZED);
      stream.next(m.HEARTBEAT_ROLL);
      stream.next(m.HEARTBEAT_PITCH);
      stream.next(m.HEARTBEAT_YAW);
      stream.next(m.HEARTBEAT_WX);
      stream.next(m.HEARTBEAT_WY);
      stream.next(m.HEARTBEAT_WZ);
      stream.next(m.HEARTBEAT_AX);
      stream.next(m.HEARTBEAT_AY);
      stream.next(m.HEARTBEAT_AZ);
      stream.next(m.HEARTBEAT_VN);
      stream.next(m.HEARTBEAT_VE);
      stream.next(m.HEARTBEAT_VD);
      stream.next(m.HEARTBEAT_DEPTH);
      stream.next(m.HEARTBEAT_HEIGHT);
      stream.next(m.HEARTBEAT_RPM);
      stream.next(m.HEARTBEAT_VOLTAGE);
      stream.next(m.HEARTBEAT_FSD_ACTION_PERCENT);
      stream.next(m.HEARTBEAT_BSD_ACTION_PERCENT);
      stream.next(m.HEARTBEAT_GPS_LAT);
      stream.next(m.HEARTBEAT_GPS_LON);
      stream.next(m.HEARTBEAT_GPS_ALT);
      stream.next(m.HEARTBEAT_NAV_LAT);
      stream.next(m.HEARTBEAT_NAV_LON);
      stream.next(m.HEARTBEAT_NAV_ALT);
      stream.next(m.HEARTBEAT_NAV_YAW_STD);
      stream.next(m.HEARTBEAT_NAV_AVG_POS_ERR);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct HeartbeatMsg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::avl_bsd_translator::HeartbeatMsg_<ContainerAllocator>& v)
  {
    s << indent << "HEARTBEAT_STATUS: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_STATUS);
    s << indent << "HEARTBEAT_UMODEM_SYNC: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_UMODEM_SYNC);
    s << indent << "HEARTBEAT_IRIDIUM_STR: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_IRIDIUM_STR);
    s << indent << "HEARTBEAT_MISSION_MODE: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_MISSION_MODE);
    s << indent << "HEARTBEAT_FSD_MISSION_STATE: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_FSD_MISSION_STATE);
    s << indent << "HEARTBEAT_FSD_CURRENT_ACTION: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_FSD_CURRENT_ACTION);
    s << indent << "HEARTBEAT_FSD_TOTAL_ACTIONS: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_FSD_TOTAL_ACTIONS);
    s << indent << "HEARTBEAT_BSD_MISSION_STATE: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_BSD_MISSION_STATE);
    s << indent << "HEARTBEAT_BSD_CURRENT_ACTION: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_BSD_CURRENT_ACTION);
    s << indent << "HEARTBEAT_BSD_TOTAL_ACTIONS: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_BSD_TOTAL_ACTIONS);
    s << indent << "HEARTBEAT_GPS_SATS: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_GPS_SATS);
    s << indent << "HEARTBEAT_NAV_INITIALIZED: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.HEARTBEAT_NAV_INITIALIZED);
    s << indent << "HEARTBEAT_ROLL: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_ROLL);
    s << indent << "HEARTBEAT_PITCH: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_PITCH);
    s << indent << "HEARTBEAT_YAW: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_YAW);
    s << indent << "HEARTBEAT_WX: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_WX);
    s << indent << "HEARTBEAT_WY: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_WY);
    s << indent << "HEARTBEAT_WZ: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_WZ);
    s << indent << "HEARTBEAT_AX: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_AX);
    s << indent << "HEARTBEAT_AY: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_AY);
    s << indent << "HEARTBEAT_AZ: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_AZ);
    s << indent << "HEARTBEAT_VN: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_VN);
    s << indent << "HEARTBEAT_VE: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_VE);
    s << indent << "HEARTBEAT_VD: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_VD);
    s << indent << "HEARTBEAT_DEPTH: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_DEPTH);
    s << indent << "HEARTBEAT_HEIGHT: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_HEIGHT);
    s << indent << "HEARTBEAT_RPM: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_RPM);
    s << indent << "HEARTBEAT_VOLTAGE: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_VOLTAGE);
    s << indent << "HEARTBEAT_FSD_ACTION_PERCENT: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_FSD_ACTION_PERCENT);
    s << indent << "HEARTBEAT_BSD_ACTION_PERCENT: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_BSD_ACTION_PERCENT);
    s << indent << "HEARTBEAT_GPS_LAT: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_GPS_LAT);
    s << indent << "HEARTBEAT_GPS_LON: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_GPS_LON);
    s << indent << "HEARTBEAT_GPS_ALT: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_GPS_ALT);
    s << indent << "HEARTBEAT_NAV_LAT: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_NAV_LAT);
    s << indent << "HEARTBEAT_NAV_LON: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_NAV_LON);
    s << indent << "HEARTBEAT_NAV_ALT: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_NAV_ALT);
    s << indent << "HEARTBEAT_NAV_YAW_STD: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_NAV_YAW_STD);
    s << indent << "HEARTBEAT_NAV_AVG_POS_ERR: ";
    Printer<double>::stream(s, indent + "  ", v.HEARTBEAT_NAV_AVG_POS_ERR);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AVL_BSD_TRANSLATOR_MESSAGE_HEARTBEATMSG_H