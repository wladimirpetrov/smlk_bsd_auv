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

class ActionMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ACTION_TYPE = null;
      this.MODE = null;
      this.NAMES = null;
      this.TYPES = null;
      this.VALUES = null;
    }
    else {
      if (initObj.hasOwnProperty('ACTION_TYPE')) {
        this.ACTION_TYPE = initObj.ACTION_TYPE
      }
      else {
        this.ACTION_TYPE = '';
      }
      if (initObj.hasOwnProperty('MODE')) {
        this.MODE = initObj.MODE
      }
      else {
        this.MODE = 0;
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
    // Serializes a message object of type ActionMsg
    // Serialize message field [ACTION_TYPE]
    bufferOffset = _serializer.string(obj.ACTION_TYPE, buffer, bufferOffset);
    // Serialize message field [MODE]
    bufferOffset = _serializer.uint8(obj.MODE, buffer, bufferOffset);
    // Serialize message field [NAMES]
    bufferOffset = _arraySerializer.string(obj.NAMES, buffer, bufferOffset, null);
    // Serialize message field [TYPES]
    bufferOffset = _arraySerializer.uint8(obj.TYPES, buffer, bufferOffset, null);
    // Serialize message field [VALUES]
    bufferOffset = _arraySerializer.string(obj.VALUES, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ActionMsg
    let len;
    let data = new ActionMsg(null);
    // Deserialize message field [ACTION_TYPE]
    data.ACTION_TYPE = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [MODE]
    data.MODE = _deserializer.uint8(buffer, bufferOffset);
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
    length += _getByteLength(object.ACTION_TYPE);
    object.NAMES.forEach((val) => {
      length += 4 + _getByteLength(val);
    });
    length += object.TYPES.length;
    object.VALUES.forEach((val) => {
      length += 4 + _getByteLength(val);
    });
    return length + 17;
  }

  static datatype() {
    // Returns string type for a message object
    return 'avl_bsd_translator/ActionMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '26d51459ba77981700e1646ecfd1099d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #===============================================================================
    # Autonomous Vehicle Library Backseat Driver
    #
    # Description: Defines a ROS message that contains an action
    #===============================================================================
    
    string ACTION_TYPE
    uint8 MODE
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
    const resolved = new ActionMsg(null);
    if (msg.ACTION_TYPE !== undefined) {
      resolved.ACTION_TYPE = msg.ACTION_TYPE;
    }
    else {
      resolved.ACTION_TYPE = ''
    }

    if (msg.MODE !== undefined) {
      resolved.MODE = msg.MODE;
    }
    else {
      resolved.MODE = 0
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

module.exports = ActionMsg;
