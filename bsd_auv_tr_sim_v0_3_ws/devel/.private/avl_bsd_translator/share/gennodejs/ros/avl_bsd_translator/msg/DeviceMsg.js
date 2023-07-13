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

class DeviceMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.DEVICE_NAME = null;
      this.NAMES = null;
      this.TYPES = null;
      this.VALUES = null;
    }
    else {
      if (initObj.hasOwnProperty('DEVICE_NAME')) {
        this.DEVICE_NAME = initObj.DEVICE_NAME
      }
      else {
        this.DEVICE_NAME = '';
      }
      if (initObj.hasOwnProperty('NAMES')) {
        this.NAMES = initObj.NAMES
      }
      else {
        this.NAMES = [];
      }
      if (initObj.hasOwnProperty('TYPES')) {
        this.TYPES = initObj.TYPES
      }
      else {
        this.TYPES = [];
      }
      if (initObj.hasOwnProperty('VALUES')) {
        this.VALUES = initObj.VALUES
      }
      else {
        this.VALUES = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DeviceMsg
    // Serialize message field [DEVICE_NAME]
    bufferOffset = _serializer.string(obj.DEVICE_NAME, buffer, bufferOffset);
    // Serialize message field [NAMES]
    bufferOffset = _arraySerializer.string(obj.NAMES, buffer, bufferOffset, null);
    // Serialize message field [TYPES]
    bufferOffset = _arraySerializer.uint8(obj.TYPES, buffer, bufferOffset, null);
    // Serialize message field [VALUES]
    bufferOffset = _arraySerializer.string(obj.VALUES, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DeviceMsg
    let len;
    let data = new DeviceMsg(null);
    // Deserialize message field [DEVICE_NAME]
    data.DEVICE_NAME = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [NAMES]
    data.NAMES = _arrayDeserializer.string(buffer, bufferOffset, null)
    // Deserialize message field [TYPES]
    data.TYPES = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [VALUES]
    data.VALUES = _arrayDeserializer.string(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.DEVICE_NAME);
    object.NAMES.forEach((val) => {
      length += 4 + _getByteLength(val);
    });
    length += object.TYPES.length;
    object.VALUES.forEach((val) => {
      length += 4 + _getByteLength(val);
    });
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'avl_bsd_translator/DeviceMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ac0218f626191d446efaa61422be9692';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #===============================================================================
    # Autonomous Vehicle Library Backseat Driver
    #
    # Description: Defines a ROS message that contains a device message
    #===============================================================================
    
    string DEVICE_NAME
    string[] NAMES
    uint8[] TYPES
    string[] VALUES
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DeviceMsg(null);
    if (msg.DEVICE_NAME !== undefined) {
      resolved.DEVICE_NAME = msg.DEVICE_NAME;
    }
    else {
      resolved.DEVICE_NAME = ''
    }

    if (msg.NAMES !== undefined) {
      resolved.NAMES = msg.NAMES;
    }
    else {
      resolved.NAMES = []
    }

    if (msg.TYPES !== undefined) {
      resolved.TYPES = msg.TYPES;
    }
    else {
      resolved.TYPES = []
    }

    if (msg.VALUES !== undefined) {
      resolved.VALUES = msg.VALUES;
    }
    else {
      resolved.VALUES = []
    }

    return resolved;
    }
};

module.exports = DeviceMsg;
