// Auto-generated. Do not edit!

// (in-package avl_bsd_translator.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class HeartbeatMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.HEARTBEAT_STATUS = null;
      this.HEARTBEAT_UMODEM_SYNC = null;
      this.HEARTBEAT_IRIDIUM_STR = null;
      this.HEARTBEAT_MISSION_MODE = null;
      this.HEARTBEAT_FSD_MISSION_STATE = null;
      this.HEARTBEAT_FSD_CURRENT_ACTION = null;
      this.HEARTBEAT_FSD_TOTAL_ACTIONS = null;
      this.HEARTBEAT_BSD_MISSION_STATE = null;
      this.HEARTBEAT_BSD_CURRENT_ACTION = null;
      this.HEARTBEAT_BSD_TOTAL_ACTIONS = null;
      this.HEARTBEAT_GPS_SATS = null;
      this.HEARTBEAT_NAV_INITIALIZED = null;
      this.HEARTBEAT_ROLL = null;
      this.HEARTBEAT_PITCH = null;
      this.HEARTBEAT_YAW = null;
      this.HEARTBEAT_WX = null;
      this.HEARTBEAT_WY = null;
      this.HEARTBEAT_WZ = null;
      this.HEARTBEAT_AX = null;
      this.HEARTBEAT_AY = null;
      this.HEARTBEAT_AZ = null;
      this.HEARTBEAT_VN = null;
      this.HEARTBEAT_VE = null;
      this.HEARTBEAT_VD = null;
      this.HEARTBEAT_DEPTH = null;
      this.HEARTBEAT_HEIGHT = null;
      this.HEARTBEAT_RPM = null;
      this.HEARTBEAT_VOLTAGE = null;
      this.HEARTBEAT_FSD_ACTION_PERCENT = null;
      this.HEARTBEAT_BSD_ACTION_PERCENT = null;
      this.HEARTBEAT_GPS_LAT = null;
      this.HEARTBEAT_GPS_LON = null;
      this.HEARTBEAT_GPS_ALT = null;
      this.HEARTBEAT_NAV_LAT = null;
      this.HEARTBEAT_NAV_LON = null;
      this.HEARTBEAT_NAV_ALT = null;
      this.HEARTBEAT_NAV_YAW_STD = null;
      this.HEARTBEAT_NAV_AVG_POS_ERR = null;
    }
    else {
      if (initObj.hasOwnProperty('HEARTBEAT_STATUS')) {
        this.HEARTBEAT_STATUS = initObj.HEARTBEAT_STATUS
      }
      else {
        this.HEARTBEAT_STATUS = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_UMODEM_SYNC')) {
        this.HEARTBEAT_UMODEM_SYNC = initObj.HEARTBEAT_UMODEM_SYNC
      }
      else {
        this.HEARTBEAT_UMODEM_SYNC = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_IRIDIUM_STR')) {
        this.HEARTBEAT_IRIDIUM_STR = initObj.HEARTBEAT_IRIDIUM_STR
      }
      else {
        this.HEARTBEAT_IRIDIUM_STR = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_MISSION_MODE')) {
        this.HEARTBEAT_MISSION_MODE = initObj.HEARTBEAT_MISSION_MODE
      }
      else {
        this.HEARTBEAT_MISSION_MODE = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_FSD_MISSION_STATE')) {
        this.HEARTBEAT_FSD_MISSION_STATE = initObj.HEARTBEAT_FSD_MISSION_STATE
      }
      else {
        this.HEARTBEAT_FSD_MISSION_STATE = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_FSD_CURRENT_ACTION')) {
        this.HEARTBEAT_FSD_CURRENT_ACTION = initObj.HEARTBEAT_FSD_CURRENT_ACTION
      }
      else {
        this.HEARTBEAT_FSD_CURRENT_ACTION = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_FSD_TOTAL_ACTIONS')) {
        this.HEARTBEAT_FSD_TOTAL_ACTIONS = initObj.HEARTBEAT_FSD_TOTAL_ACTIONS
      }
      else {
        this.HEARTBEAT_FSD_TOTAL_ACTIONS = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_BSD_MISSION_STATE')) {
        this.HEARTBEAT_BSD_MISSION_STATE = initObj.HEARTBEAT_BSD_MISSION_STATE
      }
      else {
        this.HEARTBEAT_BSD_MISSION_STATE = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_BSD_CURRENT_ACTION')) {
        this.HEARTBEAT_BSD_CURRENT_ACTION = initObj.HEARTBEAT_BSD_CURRENT_ACTION
      }
      else {
        this.HEARTBEAT_BSD_CURRENT_ACTION = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_BSD_TOTAL_ACTIONS')) {
        this.HEARTBEAT_BSD_TOTAL_ACTIONS = initObj.HEARTBEAT_BSD_TOTAL_ACTIONS
      }
      else {
        this.HEARTBEAT_BSD_TOTAL_ACTIONS = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_GPS_SATS')) {
        this.HEARTBEAT_GPS_SATS = initObj.HEARTBEAT_GPS_SATS
      }
      else {
        this.HEARTBEAT_GPS_SATS = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_NAV_INITIALIZED')) {
        this.HEARTBEAT_NAV_INITIALIZED = initObj.HEARTBEAT_NAV_INITIALIZED
      }
      else {
        this.HEARTBEAT_NAV_INITIALIZED = 0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_ROLL')) {
        this.HEARTBEAT_ROLL = initObj.HEARTBEAT_ROLL
      }
      else {
        this.HEARTBEAT_ROLL = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_PITCH')) {
        this.HEARTBEAT_PITCH = initObj.HEARTBEAT_PITCH
      }
      else {
        this.HEARTBEAT_PITCH = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_YAW')) {
        this.HEARTBEAT_YAW = initObj.HEARTBEAT_YAW
      }
      else {
        this.HEARTBEAT_YAW = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_WX')) {
        this.HEARTBEAT_WX = initObj.HEARTBEAT_WX
      }
      else {
        this.HEARTBEAT_WX = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_WY')) {
        this.HEARTBEAT_WY = initObj.HEARTBEAT_WY
      }
      else {
        this.HEARTBEAT_WY = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_WZ')) {
        this.HEARTBEAT_WZ = initObj.HEARTBEAT_WZ
      }
      else {
        this.HEARTBEAT_WZ = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_AX')) {
        this.HEARTBEAT_AX = initObj.HEARTBEAT_AX
      }
      else {
        this.HEARTBEAT_AX = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_AY')) {
        this.HEARTBEAT_AY = initObj.HEARTBEAT_AY
      }
      else {
        this.HEARTBEAT_AY = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_AZ')) {
        this.HEARTBEAT_AZ = initObj.HEARTBEAT_AZ
      }
      else {
        this.HEARTBEAT_AZ = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_VN')) {
        this.HEARTBEAT_VN = initObj.HEARTBEAT_VN
      }
      else {
        this.HEARTBEAT_VN = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_VE')) {
        this.HEARTBEAT_VE = initObj.HEARTBEAT_VE
      }
      else {
        this.HEARTBEAT_VE = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_VD')) {
        this.HEARTBEAT_VD = initObj.HEARTBEAT_VD
      }
      else {
        this.HEARTBEAT_VD = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_DEPTH')) {
        this.HEARTBEAT_DEPTH = initObj.HEARTBEAT_DEPTH
      }
      else {
        this.HEARTBEAT_DEPTH = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_HEIGHT')) {
        this.HEARTBEAT_HEIGHT = initObj.HEARTBEAT_HEIGHT
      }
      else {
        this.HEARTBEAT_HEIGHT = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_RPM')) {
        this.HEARTBEAT_RPM = initObj.HEARTBEAT_RPM
      }
      else {
        this.HEARTBEAT_RPM = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_VOLTAGE')) {
        this.HEARTBEAT_VOLTAGE = initObj.HEARTBEAT_VOLTAGE
      }
      else {
        this.HEARTBEAT_VOLTAGE = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_FSD_ACTION_PERCENT')) {
        this.HEARTBEAT_FSD_ACTION_PERCENT = initObj.HEARTBEAT_FSD_ACTION_PERCENT
      }
      else {
        this.HEARTBEAT_FSD_ACTION_PERCENT = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_BSD_ACTION_PERCENT')) {
        this.HEARTBEAT_BSD_ACTION_PERCENT = initObj.HEARTBEAT_BSD_ACTION_PERCENT
      }
      else {
        this.HEARTBEAT_BSD_ACTION_PERCENT = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_GPS_LAT')) {
        this.HEARTBEAT_GPS_LAT = initObj.HEARTBEAT_GPS_LAT
      }
      else {
        this.HEARTBEAT_GPS_LAT = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_GPS_LON')) {
        this.HEARTBEAT_GPS_LON = initObj.HEARTBEAT_GPS_LON
      }
      else {
        this.HEARTBEAT_GPS_LON = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_GPS_ALT')) {
        this.HEARTBEAT_GPS_ALT = initObj.HEARTBEAT_GPS_ALT
      }
      else {
        this.HEARTBEAT_GPS_ALT = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_NAV_LAT')) {
        this.HEARTBEAT_NAV_LAT = initObj.HEARTBEAT_NAV_LAT
      }
      else {
        this.HEARTBEAT_NAV_LAT = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_NAV_LON')) {
        this.HEARTBEAT_NAV_LON = initObj.HEARTBEAT_NAV_LON
      }
      else {
        this.HEARTBEAT_NAV_LON = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_NAV_ALT')) {
        this.HEARTBEAT_NAV_ALT = initObj.HEARTBEAT_NAV_ALT
      }
      else {
        this.HEARTBEAT_NAV_ALT = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_NAV_YAW_STD')) {
        this.HEARTBEAT_NAV_YAW_STD = initObj.HEARTBEAT_NAV_YAW_STD
      }
      else {
        this.HEARTBEAT_NAV_YAW_STD = 0.0;
      }
      if (initObj.hasOwnProperty('HEARTBEAT_NAV_AVG_POS_ERR')) {
        this.HEARTBEAT_NAV_AVG_POS_ERR = initObj.HEARTBEAT_NAV_AVG_POS_ERR
      }
      else {
        this.HEARTBEAT_NAV_AVG_POS_ERR = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type HeartbeatMsg
    // Serialize message field [HEARTBEAT_STATUS]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_STATUS, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_UMODEM_SYNC]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_UMODEM_SYNC, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_IRIDIUM_STR]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_IRIDIUM_STR, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_MISSION_MODE]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_MISSION_MODE, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_FSD_MISSION_STATE]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_FSD_MISSION_STATE, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_FSD_CURRENT_ACTION]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_FSD_CURRENT_ACTION, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_FSD_TOTAL_ACTIONS]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_FSD_TOTAL_ACTIONS, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_BSD_MISSION_STATE]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_BSD_MISSION_STATE, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_BSD_CURRENT_ACTION]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_BSD_CURRENT_ACTION, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_BSD_TOTAL_ACTIONS]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_BSD_TOTAL_ACTIONS, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_GPS_SATS]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_GPS_SATS, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_NAV_INITIALIZED]
    bufferOffset = _serializer.uint8(obj.HEARTBEAT_NAV_INITIALIZED, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_ROLL]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_ROLL, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_PITCH]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_PITCH, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_YAW]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_YAW, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_WX]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_WX, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_WY]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_WY, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_WZ]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_WZ, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_AX]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_AX, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_AY]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_AY, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_AZ]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_AZ, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_VN]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_VN, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_VE]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_VE, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_VD]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_VD, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_DEPTH]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_DEPTH, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_HEIGHT]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_HEIGHT, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_RPM]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_RPM, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_VOLTAGE]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_VOLTAGE, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_FSD_ACTION_PERCENT]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_FSD_ACTION_PERCENT, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_BSD_ACTION_PERCENT]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_BSD_ACTION_PERCENT, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_GPS_LAT]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_GPS_LAT, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_GPS_LON]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_GPS_LON, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_GPS_ALT]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_GPS_ALT, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_NAV_LAT]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_NAV_LAT, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_NAV_LON]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_NAV_LON, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_NAV_ALT]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_NAV_ALT, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_NAV_YAW_STD]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_NAV_YAW_STD, buffer, bufferOffset);
    // Serialize message field [HEARTBEAT_NAV_AVG_POS_ERR]
    bufferOffset = _serializer.float64(obj.HEARTBEAT_NAV_AVG_POS_ERR, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type HeartbeatMsg
    let len;
    let data = new HeartbeatMsg(null);
    // Deserialize message field [HEARTBEAT_STATUS]
    data.HEARTBEAT_STATUS = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_UMODEM_SYNC]
    data.HEARTBEAT_UMODEM_SYNC = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_IRIDIUM_STR]
    data.HEARTBEAT_IRIDIUM_STR = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_MISSION_MODE]
    data.HEARTBEAT_MISSION_MODE = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_FSD_MISSION_STATE]
    data.HEARTBEAT_FSD_MISSION_STATE = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_FSD_CURRENT_ACTION]
    data.HEARTBEAT_FSD_CURRENT_ACTION = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_FSD_TOTAL_ACTIONS]
    data.HEARTBEAT_FSD_TOTAL_ACTIONS = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_BSD_MISSION_STATE]
    data.HEARTBEAT_BSD_MISSION_STATE = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_BSD_CURRENT_ACTION]
    data.HEARTBEAT_BSD_CURRENT_ACTION = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_BSD_TOTAL_ACTIONS]
    data.HEARTBEAT_BSD_TOTAL_ACTIONS = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_GPS_SATS]
    data.HEARTBEAT_GPS_SATS = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_NAV_INITIALIZED]
    data.HEARTBEAT_NAV_INITIALIZED = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_ROLL]
    data.HEARTBEAT_ROLL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_PITCH]
    data.HEARTBEAT_PITCH = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_YAW]
    data.HEARTBEAT_YAW = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_WX]
    data.HEARTBEAT_WX = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_WY]
    data.HEARTBEAT_WY = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_WZ]
    data.HEARTBEAT_WZ = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_AX]
    data.HEARTBEAT_AX = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_AY]
    data.HEARTBEAT_AY = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_AZ]
    data.HEARTBEAT_AZ = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_VN]
    data.HEARTBEAT_VN = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_VE]
    data.HEARTBEAT_VE = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_VD]
    data.HEARTBEAT_VD = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_DEPTH]
    data.HEARTBEAT_DEPTH = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_HEIGHT]
    data.HEARTBEAT_HEIGHT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_RPM]
    data.HEARTBEAT_RPM = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_VOLTAGE]
    data.HEARTBEAT_VOLTAGE = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_FSD_ACTION_PERCENT]
    data.HEARTBEAT_FSD_ACTION_PERCENT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_BSD_ACTION_PERCENT]
    data.HEARTBEAT_BSD_ACTION_PERCENT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_GPS_LAT]
    data.HEARTBEAT_GPS_LAT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_GPS_LON]
    data.HEARTBEAT_GPS_LON = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_GPS_ALT]
    data.HEARTBEAT_GPS_ALT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_NAV_LAT]
    data.HEARTBEAT_NAV_LAT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_NAV_LON]
    data.HEARTBEAT_NAV_LON = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_NAV_ALT]
    data.HEARTBEAT_NAV_ALT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_NAV_YAW_STD]
    data.HEARTBEAT_NAV_YAW_STD = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [HEARTBEAT_NAV_AVG_POS_ERR]
    data.HEARTBEAT_NAV_AVG_POS_ERR = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 220;
  }

  static datatype() {
    // Returns string type for a message object
    return 'avl_bsd_translator/HeartbeatMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ac1c7d62091790946cc68f56d9855dd5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #===============================================================================
    # Autonomous Vehicle Library Backseat Driver
    #
    # Description: Defines a ROS message that contains a heartbeat
    #===============================================================================
    
    
    uint8 HEARTBEAT_STATUS
    uint8 HEARTBEAT_UMODEM_SYNC
    uint8 HEARTBEAT_IRIDIUM_STR
    
    uint8 HEARTBEAT_MISSION_MODE
    uint8 HEARTBEAT_FSD_MISSION_STATE
    uint8 HEARTBEAT_FSD_CURRENT_ACTION
    uint8 HEARTBEAT_FSD_TOTAL_ACTIONS
    uint8 HEARTBEAT_BSD_MISSION_STATE
    uint8 HEARTBEAT_BSD_CURRENT_ACTION
    uint8 HEARTBEAT_BSD_TOTAL_ACTIONS
    uint8 HEARTBEAT_GPS_SATS
    uint8 HEARTBEAT_NAV_INITIALIZED
    
    float64 HEARTBEAT_ROLL
    float64 HEARTBEAT_PITCH
    float64 HEARTBEAT_YAW
    float64 HEARTBEAT_WX
    float64 HEARTBEAT_WY
    float64 HEARTBEAT_WZ
    float64 HEARTBEAT_AX
    float64 HEARTBEAT_AY
    float64 HEARTBEAT_AZ
    float64 HEARTBEAT_VN
    float64 HEARTBEAT_VE
    float64 HEARTBEAT_VD
    float64 HEARTBEAT_DEPTH
    float64 HEARTBEAT_HEIGHT
    float64 HEARTBEAT_RPM
    float64 HEARTBEAT_VOLTAGE
    float64 HEARTBEAT_FSD_ACTION_PERCENT
    float64 HEARTBEAT_BSD_ACTION_PERCENT
    float64 HEARTBEAT_GPS_LAT
    float64 HEARTBEAT_GPS_LON
    float64 HEARTBEAT_GPS_ALT
    float64 HEARTBEAT_NAV_LAT
    float64 HEARTBEAT_NAV_LON
    float64 HEARTBEAT_NAV_ALT
    float64 HEARTBEAT_NAV_YAW_STD
    float64 HEARTBEAT_NAV_AVG_POS_ERR
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new HeartbeatMsg(null);
    if (msg.HEARTBEAT_STATUS !== undefined) {
      resolved.HEARTBEAT_STATUS = msg.HEARTBEAT_STATUS;
    }
    else {
      resolved.HEARTBEAT_STATUS = 0
    }

    if (msg.HEARTBEAT_UMODEM_SYNC !== undefined) {
      resolved.HEARTBEAT_UMODEM_SYNC = msg.HEARTBEAT_UMODEM_SYNC;
    }
    else {
      resolved.HEARTBEAT_UMODEM_SYNC = 0
    }

    if (msg.HEARTBEAT_IRIDIUM_STR !== undefined) {
      resolved.HEARTBEAT_IRIDIUM_STR = msg.HEARTBEAT_IRIDIUM_STR;
    }
    else {
      resolved.HEARTBEAT_IRIDIUM_STR = 0
    }

    if (msg.HEARTBEAT_MISSION_MODE !== undefined) {
      resolved.HEARTBEAT_MISSION_MODE = msg.HEARTBEAT_MISSION_MODE;
    }
    else {
      resolved.HEARTBEAT_MISSION_MODE = 0
    }

    if (msg.HEARTBEAT_FSD_MISSION_STATE !== undefined) {
      resolved.HEARTBEAT_FSD_MISSION_STATE = msg.HEARTBEAT_FSD_MISSION_STATE;
    }
    else {
      resolved.HEARTBEAT_FSD_MISSION_STATE = 0
    }

    if (msg.HEARTBEAT_FSD_CURRENT_ACTION !== undefined) {
      resolved.HEARTBEAT_FSD_CURRENT_ACTION = msg.HEARTBEAT_FSD_CURRENT_ACTION;
    }
    else {
      resolved.HEARTBEAT_FSD_CURRENT_ACTION = 0
    }

    if (msg.HEARTBEAT_FSD_TOTAL_ACTIONS !== undefined) {
      resolved.HEARTBEAT_FSD_TOTAL_ACTIONS = msg.HEARTBEAT_FSD_TOTAL_ACTIONS;
    }
    else {
      resolved.HEARTBEAT_FSD_TOTAL_ACTIONS = 0
    }

    if (msg.HEARTBEAT_BSD_MISSION_STATE !== undefined) {
      resolved.HEARTBEAT_BSD_MISSION_STATE = msg.HEARTBEAT_BSD_MISSION_STATE;
    }
    else {
      resolved.HEARTBEAT_BSD_MISSION_STATE = 0
    }

    if (msg.HEARTBEAT_BSD_CURRENT_ACTION !== undefined) {
      resolved.HEARTBEAT_BSD_CURRENT_ACTION = msg.HEARTBEAT_BSD_CURRENT_ACTION;
    }
    else {
      resolved.HEARTBEAT_BSD_CURRENT_ACTION = 0
    }

    if (msg.HEARTBEAT_BSD_TOTAL_ACTIONS !== undefined) {
      resolved.HEARTBEAT_BSD_TOTAL_ACTIONS = msg.HEARTBEAT_BSD_TOTAL_ACTIONS;
    }
    else {
      resolved.HEARTBEAT_BSD_TOTAL_ACTIONS = 0
    }

    if (msg.HEARTBEAT_GPS_SATS !== undefined) {
      resolved.HEARTBEAT_GPS_SATS = msg.HEARTBEAT_GPS_SATS;
    }
    else {
      resolved.HEARTBEAT_GPS_SATS = 0
    }

    if (msg.HEARTBEAT_NAV_INITIALIZED !== undefined) {
      resolved.HEARTBEAT_NAV_INITIALIZED = msg.HEARTBEAT_NAV_INITIALIZED;
    }
    else {
      resolved.HEARTBEAT_NAV_INITIALIZED = 0
    }

    if (msg.HEARTBEAT_ROLL !== undefined) {
      resolved.HEARTBEAT_ROLL = msg.HEARTBEAT_ROLL;
    }
    else {
      resolved.HEARTBEAT_ROLL = 0.0
    }

    if (msg.HEARTBEAT_PITCH !== undefined) {
      resolved.HEARTBEAT_PITCH = msg.HEARTBEAT_PITCH;
    }
    else {
      resolved.HEARTBEAT_PITCH = 0.0
    }

    if (msg.HEARTBEAT_YAW !== undefined) {
      resolved.HEARTBEAT_YAW = msg.HEARTBEAT_YAW;
    }
    else {
      resolved.HEARTBEAT_YAW = 0.0
    }

    if (msg.HEARTBEAT_WX !== undefined) {
      resolved.HEARTBEAT_WX = msg.HEARTBEAT_WX;
    }
    else {
      resolved.HEARTBEAT_WX = 0.0
    }

    if (msg.HEARTBEAT_WY !== undefined) {
      resolved.HEARTBEAT_WY = msg.HEARTBEAT_WY;
    }
    else {
      resolved.HEARTBEAT_WY = 0.0
    }

    if (msg.HEARTBEAT_WZ !== undefined) {
      resolved.HEARTBEAT_WZ = msg.HEARTBEAT_WZ;
    }
    else {
      resolved.HEARTBEAT_WZ = 0.0
    }

    if (msg.HEARTBEAT_AX !== undefined) {
      resolved.HEARTBEAT_AX = msg.HEARTBEAT_AX;
    }
    else {
      resolved.HEARTBEAT_AX = 0.0
    }

    if (msg.HEARTBEAT_AY !== undefined) {
      resolved.HEARTBEAT_AY = msg.HEARTBEAT_AY;
    }
    else {
      resolved.HEARTBEAT_AY = 0.0
    }

    if (msg.HEARTBEAT_AZ !== undefined) {
      resolved.HEARTBEAT_AZ = msg.HEARTBEAT_AZ;
    }
    else {
      resolved.HEARTBEAT_AZ = 0.0
    }

    if (msg.HEARTBEAT_VN !== undefined) {
      resolved.HEARTBEAT_VN = msg.HEARTBEAT_VN;
    }
    else {
      resolved.HEARTBEAT_VN = 0.0
    }

    if (msg.HEARTBEAT_VE !== undefined) {
      resolved.HEARTBEAT_VE = msg.HEARTBEAT_VE;
    }
    else {
      resolved.HEARTBEAT_VE = 0.0
    }

    if (msg.HEARTBEAT_VD !== undefined) {
      resolved.HEARTBEAT_VD = msg.HEARTBEAT_VD;
    }
    else {
      resolved.HEARTBEAT_VD = 0.0
    }

    if (msg.HEARTBEAT_DEPTH !== undefined) {
      resolved.HEARTBEAT_DEPTH = msg.HEARTBEAT_DEPTH;
    }
    else {
      resolved.HEARTBEAT_DEPTH = 0.0
    }

    if (msg.HEARTBEAT_HEIGHT !== undefined) {
      resolved.HEARTBEAT_HEIGHT = msg.HEARTBEAT_HEIGHT;
    }
    else {
      resolved.HEARTBEAT_HEIGHT = 0.0
    }

    if (msg.HEARTBEAT_RPM !== undefined) {
      resolved.HEARTBEAT_RPM = msg.HEARTBEAT_RPM;
    }
    else {
      resolved.HEARTBEAT_RPM = 0.0
    }

    if (msg.HEARTBEAT_VOLTAGE !== undefined) {
      resolved.HEARTBEAT_VOLTAGE = msg.HEARTBEAT_VOLTAGE;
    }
    else {
      resolved.HEARTBEAT_VOLTAGE = 0.0
    }

    if (msg.HEARTBEAT_FSD_ACTION_PERCENT !== undefined) {
      resolved.HEARTBEAT_FSD_ACTION_PERCENT = msg.HEARTBEAT_FSD_ACTION_PERCENT;
    }
    else {
      resolved.HEARTBEAT_FSD_ACTION_PERCENT = 0.0
    }

    if (msg.HEARTBEAT_BSD_ACTION_PERCENT !== undefined) {
      resolved.HEARTBEAT_BSD_ACTION_PERCENT = msg.HEARTBEAT_BSD_ACTION_PERCENT;
    }
    else {
      resolved.HEARTBEAT_BSD_ACTION_PERCENT = 0.0
    }

    if (msg.HEARTBEAT_GPS_LAT !== undefined) {
      resolved.HEARTBEAT_GPS_LAT = msg.HEARTBEAT_GPS_LAT;
    }
    else {
      resolved.HEARTBEAT_GPS_LAT = 0.0
    }

    if (msg.HEARTBEAT_GPS_LON !== undefined) {
      resolved.HEARTBEAT_GPS_LON = msg.HEARTBEAT_GPS_LON;
    }
    else {
      resolved.HEARTBEAT_GPS_LON = 0.0
    }

    if (msg.HEARTBEAT_GPS_ALT !== undefined) {
      resolved.HEARTBEAT_GPS_ALT = msg.HEARTBEAT_GPS_ALT;
    }
    else {
      resolved.HEARTBEAT_GPS_ALT = 0.0
    }

    if (msg.HEARTBEAT_NAV_LAT !== undefined) {
      resolved.HEARTBEAT_NAV_LAT = msg.HEARTBEAT_NAV_LAT;
    }
    else {
      resolved.HEARTBEAT_NAV_LAT = 0.0
    }

    if (msg.HEARTBEAT_NAV_LON !== undefined) {
      resolved.HEARTBEAT_NAV_LON = msg.HEARTBEAT_NAV_LON;
    }
    else {
      resolved.HEARTBEAT_NAV_LON = 0.0
    }

    if (msg.HEARTBEAT_NAV_ALT !== undefined) {
      resolved.HEARTBEAT_NAV_ALT = msg.HEARTBEAT_NAV_ALT;
    }
    else {
      resolved.HEARTBEAT_NAV_ALT = 0.0
    }

    if (msg.HEARTBEAT_NAV_YAW_STD !== undefined) {
      resolved.HEARTBEAT_NAV_YAW_STD = msg.HEARTBEAT_NAV_YAW_STD;
    }
    else {
      resolved.HEARTBEAT_NAV_YAW_STD = 0.0
    }

    if (msg.HEARTBEAT_NAV_AVG_POS_ERR !== undefined) {
      resolved.HEARTBEAT_NAV_AVG_POS_ERR = msg.HEARTBEAT_NAV_AVG_POS_ERR;
    }
    else {
      resolved.HEARTBEAT_NAV_AVG_POS_ERR = 0.0
    }

    return resolved;
    }
};

module.exports = HeartbeatMsg;
