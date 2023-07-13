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

class PassthroughMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ORIGIN_ID = null;
      this.TARGET_ID = null;
      this.CHANNEL = null;
      this.INTERFACE = null;
      this.DATA = null;
    }
    else {
      if (initObj.hasOwnProperty('ORIGIN_ID')) {
        this.ORIGIN_ID = initObj.ORIGIN_ID
      }
      else {
        this.ORIGIN_ID = 0;
      }
      if (initObj.hasOwnProperty('TARGET_ID')) {
        this.TARGET_ID = initObj.TARGET_ID
      }
      else {
        this.TARGET_ID = 0;
      }
      if (initObj.hasOwnProperty('CHANNEL')) {
        this.CHANNEL = initObj.CHANNEL
      }
      else {
        this.CHANNEL = 0;
      }
      if (initObj.hasOwnProperty('INTERFACE')) {
        this.INTERFACE = initObj.INTERFACE
      }
      else {
        this.INTERFACE = 0;
      }
      if (initObj.hasOwnProperty('DATA')) {
        this.DATA = initObj.DATA
      }
      else {
        this.DATA = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PassthroughMsg
    // Serialize message field [ORIGIN_ID]
    bufferOffset = _serializer.uint8(obj.ORIGIN_ID, buffer, bufferOffset);
    // Serialize message field [TARGET_ID]
    bufferOffset = _serializer.uint8(obj.TARGET_ID, buffer, bufferOffset);
    // Serialize message field [CHANNEL]
    bufferOffset = _serializer.uint8(obj.CHANNEL, buffer, bufferOffset);
    // Serialize message field [INTERFACE]
    bufferOffset = _serializer.uint8(obj.INTERFACE, buffer, bufferOffset);
    // Serialize message field [DATA]
    bufferOffset = _serializer.string(obj.DATA, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PassthroughMsg
    let len;
    let data = new PassthroughMsg(null);
    // Deserialize message field [ORIGIN_ID]
    data.ORIGIN_ID = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [TARGET_ID]
    data.TARGET_ID = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [CHANNEL]
    data.CHANNEL = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [INTERFACE]
    data.INTERFACE = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [DATA]
    data.DATA = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.DATA);
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'avl_bsd_translator/PassthroughMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '68cb8a05d5ebb8373e58b01f1c0af317';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #===============================================================================
    # Autonomous Vehicle Library Backseat Driver
    #
    # Description: Defines a message that contains a passthrough message
    #===============================================================================
    
    uint8 ORIGIN_ID
    uint8 TARGET_ID
    uint8 CHANNEL
    uint8 INTERFACE
    string DATA
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PassthroughMsg(null);
    if (msg.ORIGIN_ID !== undefined) {
      resolved.ORIGIN_ID = msg.ORIGIN_ID;
    }
    else {
      resolved.ORIGIN_ID = 0
    }

    if (msg.TARGET_ID !== undefined) {
      resolved.TARGET_ID = msg.TARGET_ID;
    }
    else {
      resolved.TARGET_ID = 0
    }

    if (msg.CHANNEL !== undefined) {
      resolved.CHANNEL = msg.CHANNEL;
    }
    else {
      resolved.CHANNEL = 0
    }

    if (msg.INTERFACE !== undefined) {
      resolved.INTERFACE = msg.INTERFACE;
    }
    else {
      resolved.INTERFACE = 0
    }

    if (msg.DATA !== undefined) {
      resolved.DATA = msg.DATA;
    }
    else {
      resolved.DATA = ''
    }

    return resolved;
    }
};

module.exports = PassthroughMsg;
