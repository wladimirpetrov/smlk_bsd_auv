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

class CommandMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.COMMAND_NAME = null;
      this.NAMES = null;
      this.TYPES = null;
      this.VALUES = null;
    }
    else {
      if (initObj.hasOwnProperty('COMMAND_NAME')) {
        this.COMMAND_NAME = initObj.COMMAND_NAME
      }
      else {
        this.COMMAND_NAME = '';
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
    // Serializes a message object of type CommandMsg
    // Serialize message field [COMMAND_NAME]
    bufferOffset = _serializer.string(obj.COMMAND_NAME, buffer, bufferOffset);
    // Serialize message field [NAMES]
    bufferOffset = _arraySerializer.string(obj.NAMES, buffer, bufferOffset, null);
    // Serialize message field [TYPES]
    bufferOffset = _arraySerializer.uint8(obj.TYPES, buffer, bufferOffset, null);
    // Serialize message field [VALUES]
    bufferOffset = _arraySerializer.string(obj.VALUES, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CommandMsg
    let len;
    let data = new CommandMsg(null);
    // Deserialize message field [COMMAND_NAME]
    data.COMMAND_NAME = _deserializer.string(buffer, bufferOffset);
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
    length += _getByteLength(object.COMMAND_NAME);
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
    return 'avl_bsd_translator/CommandMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '90b8ee5c95edfe3031b61b3ce483a6c9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #===============================================================================
    # Autonomous Vehicle Library Backseat Driver
    #
    # Description: Defines a ROS message that contains a command
    #===============================================================================
    
    string COMMAND_NAME
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
    const resolved = new CommandMsg(null);
    if (msg.COMMAND_NAME !== undefined) {
      resolved.COMMAND_NAME = msg.COMMAND_NAME;
    }
    else {
      resolved.COMMAND_NAME = ''
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

module.exports = CommandMsg;
