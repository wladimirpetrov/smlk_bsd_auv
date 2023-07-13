
"use strict";

let PassthroughMsg = require('./PassthroughMsg.js');
let DeviceMsg = require('./DeviceMsg.js');
let HeartbeatMsg = require('./HeartbeatMsg.js');
let CommandMsg = require('./CommandMsg.js');
let ActionMsg = require('./ActionMsg.js');
let ResponseMsg = require('./ResponseMsg.js');

module.exports = {
  PassthroughMsg: PassthroughMsg,
  DeviceMsg: DeviceMsg,
  HeartbeatMsg: HeartbeatMsg,
  CommandMsg: CommandMsg,
  ActionMsg: ActionMsg,
  ResponseMsg: ResponseMsg,
};
