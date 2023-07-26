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

class ResponseMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.DESC = null;
      this.NAME = null;
      this.SOURCE = null;
      this.RESULT = null;
      this.DATA = null;
    }
    else {
      if (initObj.hasOwnProperty('DESC')) {
        this.DESC = initObj.DESC
      }
      else {
        this.DESC = 0;
      }
      if (initObj.hasOwnProperty('NAME')) {
        this.NAME = initObj.NAME
      }
      else {
        this.NAME = '';
      }
      if (initObj.hasOwnProperty('SOURCE')) {
        this.SOURCE = initObj.SOURCE
      }
      else {
        this.SOURCE = 0;
      }
      if (initObj.hasOwnProperty('RESULT')) {
        this.RESULT = initObj.RESULT
      }
      else {
        this.RESULT = false;
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
    // Serializes a message object of type ResponseMsg
    // Serialize message field [DESC]
    bufferOffset = _serializer.uint8(obj.DESC, buffer, bufferOffset);
    // Serialize message field [NAME]
    bufferOffset = _serializer.string(obj.NAME, buffer, bufferOffset);
    // Serialize message field [SOURCE]
    bufferOffset = _serializer.uint64(obj.SOURCE, buffer, bufferOffset);
    // Serialize message field [RESULT]
    bufferOffset = _serializer.bool(obj.RESULT, buffer, bufferOffset);
    // Serialize message field [DATA]
    bufferOffset = _serializer.string(obj.DATA, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ResponseMsg
    let len;
    let data = new ResponseMsg(null);
    // Deserialize message field [DESC]
    data.DESC = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [NAME]
    data.NAME = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [SOURCE]
    data.SOURCE = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [RESULT]
    data.RESULT = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [DATA]
    data.DATA = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.NAME);
    length += _getByteLength(object.DATA);
    return length + 18;
  }

  static datatype() {
    // Returns string type for a message object
    return 'avl_bsd_translator/ResponseMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f6a85287137e7f8b62777ed3e0afe18e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #===============================================================================
    # Autonomous Vehicle Library Backseat Driver
    #
    # Description: Defines a message that contains a response from the vehicle
    #              computer
    #===============================================================================
    
    uint8 DESC
    string NAME
    uint64 SOURCE
    bool RESULT
    string DATA
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ResponseMsg(null);
    if (msg.DESC !== undefined) {
      resolved.DESC = msg.DESC;
    }
    else {
      resolved.DESC = 0
    }

    if (msg.NAME !== undefined) {
      resolved.NAME = msg.NAME;
    }
    else {
      resolved.NAME = ''
    }

    if (msg.SOURCE !== undefined) {
      resolved.SOURCE = msg.SOURCE;
    }
    else {
      resolved.SOURCE = 0
    }

    if (msg.RESULT !== undefined) {
      resolved.RESULT = msg.RESULT;
    }
    else {
      resolved.RESULT = false
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

module.exports = ResponseMsg;
