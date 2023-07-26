//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ctrl_TT_ad_ctrl_cpp_ros_feedback_2_data.cpp
//
// Code generated for Simulink model 'ctrl_TT_ad_ctrl_cpp_ros_feedback_2'.
//
// Model version                  : 10.24
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Jul 17 11:01:04 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ctrl_TT_ad_ctrl_cpp_ros_feedback_2.h"

// Block parameters (default storage)
P_ctrl_TT_ad_ctrl_cpp_ros_fee_T ctrl_TT_ad_ctrl_cpp_ros_feedb_P = {
  // Variable: L1
  //  Referenced by:
  //    '<S16>/l1 aug - depth'
  //    '<S16>/l1 aug - heading'

  {
    { -0.16, 0.0625, -0.1024, 0.0 },

    { 0.25, 0.0 },

    { 0.0, 0.4096 },
    0.0,

    { 0.0012764451244209954, -0.012224361388609528, -0.0030671091636457204,
      0.0058434863737381465, -0.14378623492472639, 0.0915082980803851,
      0.071116936653190729, -0.024871659945985863, -0.0674902101996962 },

    { -0.0280712803471739, -0.30113422032462378, 0.15936512660241325,
      0.08074639353161997, -0.13604866023966505, -0.20363756721637388 },

    { -0.50068410520012807, -0.043140132833199868, -0.16970973966829755 },

    { 0.0, 0.0 },

    { 0.0, 2.243289689900192, 0.4096, 2.1766303843785977 },

    { -47.441729937340511, 48.902185470676187, 8.9511756285287642,
      -0.013949008362697491 },

    { -0.16, 0.0625, -0.1024, 0.0 },

    { 0.25, 0.0 },

    { 0.0, 0.4096 },
    0.0,

    { -0.017713271175073125, 0.0077507805881514187, -0.00097492994373777,
      -0.011611756542084961, -0.0032666584876351857, -0.00083965142251933795,
      -0.031745747643156845, -0.0073291677104650264, -0.009020070337291736 },

    { 0.073896831806420732, 0.01995699704202274, 0.047237759465753065,
      0.14053127497712981, 0.053671544016775846, 0.11269043914451711 },

    { -0.048880736380448236, -0.2883204839263257, 0.19827660553084711 },

    { 0.0, 0.0 },

    { 0.0, 2.243289689900192, 0.4096, 2.1766303843785977 },

    { -47.441729937340511, 48.902185470676187, 8.9511756285287642,
      -0.013949008362697491 }
  },

  // Variable: Cp
  //  Referenced by: '<S16>/MATLAB Function2'

  { -70.34790039, 18.70597267, -370.80001829999992, -33.25566673, 18.72042656,
    -369.95715330000007, 3.8263091999999972, 17.99342728, -368.51742549999994,
    40.776306149999996, 14.78142262, -366.26702879999993, 77.6704788,
    10.95252895, -363.56683350000003, 114.61882019999999, 7.699644089,
    -362.02432249999993, 151.6235809, 5.157749176, -360.3158264, 188.6551056,
    3.05081749, -357.87298579999992, 225.61410519999998, 5.435264587,
    -355.7553101, 262.3046265, 10.76364708, -353.00335689999997, 296.2495422,
    24.8372879, -349.85032649999994, 325.1644592, 48.01766586,
    -347.62614439999993, 360.4284363, 58.60512924, -338.4219055, 397.4385986,
    59.00138092, -340.00866700000006, 432.802002, 48.08808899, -336.9837341,
    467.48852539999996, 34.96350098, -336.1589203, 502.30291750000004,
    22.20567513, -335.58743290000007, 538.8022461, 17.14488792,
    -333.31735230000004, 575.49646, 22.05385208, -330.87373349999996,
    610.3428955, 34.62557602, -328.5295715, 642.5197144, 52.99218369,
    -326.38710019999996, 668.2819824, 79.1897583, -323.5633392, 683.0167236,
    113.1450958, -310.86288450000006, 689.9683838, 149.4631042, -306.1542511,
    686.3955688, 186.2841339, -296.54257200000006, 676.5204468, 222.0024719,
    -294.0132294, 665.0, 256.2452393, -294.8145905, 615.0, 289.4821472,
    -295.0716095, 550.0, 321.3085327, -272.39442439999993, 505.0, 354.3122559,
    -273.6703186, 495.0, 387.3022461, -273.4302216, 525.0, 417.7374573,
    -269.74476619999996, 550.0, 452.2470398, -257.2883301, 580.0, 489.2296448,
    -247.6094513, 595.0, 525.9245605, -237.75642400000004, 605.0, 560.704895,
    -254.12324520000004, 615.0, 587.9005127, -254.5464783, 625.0, 619.3972168,
    -254.7113342, 634.0882568, 653.3104248, -235.59265140000002, 649.3931885,
    686.9655762, -260.5470123, 649.2317505, 723.8733521, -254.7186127,
    647.1011353, 760.874939, -251.78166199999998, 647.2748413, 797.9623413,
    -244.9696503, 647.5883789, 835.0490723, -246.09265140000002, 647.4017944,
    872.1323242, -243.2965393, 645.3306274, 909.1286011, -241.4419403,
    631.4036865, 943.2999878, -246.60641480000004, 623.1325684, 978.9016113,
    -240.44482419999997, 637.7531738, 1012.827087, -236.87020870000003,
    658.2705078, 1043.709473, -233.4681549, 670.164917, 1076.883789,
    -234.22393799999998, 653.8275146, 1110.12793, -230.85330199999999,
    634.8297119, 1141.981689, -223.33121490000002, 616.6420288, 1174.25061,
    -221.22368619999997, 613.0595703, 1210.884277, -229.9443359, 613.9385376,
    1247.940186, -229.2963562, 612.5089722, 1284.982178, -231.2645569,
    617.4003296, 1321.716919, -228.1138611, 624.6887817, 1358.07666,
    -226.2255707, 631.0795288, 1394.498657, -224.29564670000002, 631.9071655,
    1431.57605, -221.55393220000002 },

  // Variable: Cp_prime
  //  Referenced by: '<S16>/MATLAB Function2'

  { 4.4510680392000008, 0.0017344667999998897, 0.10114379999998846,
    4.4498576270599992, -0.0857570072599998, 0.17157361040001007,
    4.4345275499199994, -0.3755005376799998, 0.26680492840000625,
    4.4276356637999994, -0.45576590633999992, 0.32132464439998643,
    4.4333676179999983, -0.39495425379199989, 0.19436279440000703,
    4.4400070910000018, -0.31213728904, 0.20335968099999491, 4.4434617960000011,
    -0.258051361044, 0.28432873800000635, 4.4360953033999984,
    0.22325434867799998, 0.25867339260000222, 4.4071582087999985,
    0.59230293282399993, 0.32008594399999879, 4.1228107848000022, 1.531422248514,
    0.37114425840000109, 3.5703900140000044, 2.5995106124000009,
    0.28547881800000141, 4.0919979297999944, 1.5475397263599997,
    0.95094741839999841, 4.3993110312, 0.29213928240000087, 0.06857262959999133,
    4.2864241394000082, -1.0155468977399988, 0.24308789359999849,
    4.1813354479999951, -1.5130342709600006, 0.16058099080000332,
    4.1738909910000075, -1.5419419668, 0.07617827999998994, 4.326001464000008,
    -0.85359970167999988, 0.21805468959999885, 4.396679567799989,
    0.25010415261999985, 0.28733395720000843, 4.2480922824000054,
    1.2327475207199996, 0.28487988480000226, 3.9626636988, 1.98378733866,
    0.26476080259999968, 3.348054195999989, 2.8304702755999993,
    0.31159973199999946, 2.2313250696000004, 3.748814458620001,
    1.1092334285999925, 1.1766547880000076, 4.2542034884000017,
    0.91667614519999852, 0.055388059200002004, 4.3953845841999986,
    0.92786138979999855, -0.88250390400000178, 4.3391297615999989,
    0.64347326400000249, -1.3001873759999985, 4.182910618, 0.070371853000001039,
    -3.9990632335999985, 4.0407336419999984, -0.059148069200000819, -6.99,
    3.8953344696000003, 1.4828151906000042, -6.5199999999999987,
    3.8945158728000062, 1.1882651368000017, -3.2299999999999995,
    3.959595337999998, -0.0591158496000026, 1.2000000000000013,
    3.8055120839999974, 0.23553314400000155, 3.3099999999999978,
    3.8885388793999978, 0.95097152860000067, 3.2799999999999994,
    4.2796391600000012, 1.3392291231999987, 2.7899999999999974, 4.4223773778,
    1.1708694749999982, 1.5399999999999947, 4.3038316615999932,
    -0.18106884600000361, 1.1999999999999993, 3.794404300000001,
    -1.1668391389999986, 1.1999999999999993, 3.4699262712000021,
    -0.038385866399996083, 1.1580598127999941, 3.8907636713999949,
    0.86726007219999968, 1.3641245115999929, 4.0582304695999944,
    0.3550280132000001, 1.1870042766000033, 4.1752283970000015,
    -1.7016473669999979, -0.098139647999996527, 4.432685548000002,
    0.58374999599999988, -0.1681096183999955, 4.4434514132000018,
    0.49968640200000003, 0.025878657599999855, 4.4504641091999986,
    0.53178094319999758, 0.020620360599998833, 4.4502894305999874,
    -0.0015102831999982413, -0.082696779999992032, 4.4472070279999869,
    0.30540503280000308, -0.60421325699999073, 4.354806521999997,
    0.01197967499999919, -1.5128698695999887, 4.1406130344000189,
    -0.30260711720000089, -0.3973493610000034, 4.228614977200003,
    0.6721295194000021, 1.8959941344000057, 3.998022931200012,
    0.4248123791999916, 2.2723757344000077, 3.7563087799999977,
    0.31677404419999888, 0.86269287199998956, 3.9823144200000087,
    -0.0081655899999937276, -2.0083754933999955, 3.9642700440000169,
    0.47920243980000166, -2.2667744103999965, 3.8290936719999848,
    0.81601751759999885, -1.9780488275999915, 3.9333769640000185,
    0.10130894640000321, -0.37635791039999589, 4.4011069440000057,
    -0.93405441120000177, 0.082390748999998209, 4.44656990999998,
    0.051595760000001434, -0.12098046559999887, 4.442581032000021,
    -0.19523291200000159, 0.60134545619997937, 4.4059189200000048,
    0.37050906360000013, 0.87102343200001542, 4.3634179439999912,
    0.226761382400003, 0.755763431200003, 4.371950432000026, 0.23321446099999743,
    0.099316403999992531, 4.449287159999983, 0.32900574000000304 },

  // Variable: Kp
  //  Referenced by: '<S35>/Gain1'

  0.1,

  // Variable: Tf
  //  Referenced by: '<S16>/MATLAB Function2'

  500.0,

  // Variable: Ts
  //  Referenced by:
  //    '<S16>/Marin PID'
  //    '<S16>/l1 aug - depth'
  //    '<S16>/l1 aug - heading'

  0.05,

  // Variable: adap
  //  Referenced by:
  //    '<S16>/l1 aug - depth'
  //    '<S16>/l1 aug - heading'

  1.0,

  // Variable: d
  //  Referenced by: '<S41>/Constant3'

  250.0,

  // Mask Parameter: Normalization_Bias
  //  Referenced by: '<S41>/Normalization'

  1.0E-10,

  // Mask Parameter: Normalization1_Bias
  //  Referenced by: '<S41>/Normalization1'

  1.0E-10,

  // Mask Parameter: DirectionCosineMatrixtoRotation
  //  Referenced by:
  //    '<S46>/Constant'
  //    '<S56>/Constant'
  //    '<S57>/Constant'

  1.0,

  // Mask Parameter: DirectionCosineMatrixtoRotati_a
  //  Referenced by:
  //    '<S64>/Constant'
  //    '<S66>/Constant'

  4.4408920985006262E-16,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S2>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S3>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S4>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S5>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_ly
  //  Referenced by: '<S6>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_lj
  //  Referenced by: '<S7>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S8>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S9>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S10>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_b0
  //  Referenced by: '<S11>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S12>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S13>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S14>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_ba
  //  Referenced by: '<S15>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S68>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S20>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S69>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_dn
  //  Referenced by: '<S21>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S70>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_c3
  //  Referenced by: '<S22>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S71>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_aq
  //  Referenced by: '<S23>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S72>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_m1
  //  Referenced by: '<S24>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_gg
  //  Referenced by: '<S73>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S25>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S74>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_hm
  //  Referenced by: '<S26>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S75>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_pp
  //  Referenced by: '<S27>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_hk
  //  Referenced by: '<S76>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_cp
  //  Referenced by: '<S28>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S77>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S29>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_gu
  //  Referenced by: '<S78>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S30>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_lg
  //  Referenced by: '<S79>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_gp
  //  Referenced by: '<S31>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 1
  //  Referenced by: '<S52>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S53>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S48>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S49>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S57>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S56>/Constant1'

  0.0,

  // Expression: -eye(3)
  //  Referenced by: '<S58>/Bias1'

  { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0 },

  // Expression: -1
  //  Referenced by: '<S59>/Bias'

  -1.0,

  // Expression: [-1 0 0 0 0 0; 0 -1 0 0 0 0; 0 0 1 0 0 0; 0 0 0 1 0 0; 0 0 0 0 1 0; 0 0 0 0 0 1]
  //  Referenced by: '<S16>/Constant'

  { -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: [-1 0 0 0 0 0; 0 -1 0 0 0 0; 0 0 1 0 0 0; 0 0 0 1 0 0; 0 0 0 0 1 0; 0 0 0 0 0 1]
  //  Referenced by: '<S16>/Constant2'

  { -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: -1
  //  Referenced by: '<S41>/Gain'

  -1.0,

  // Expression: [1 1 -1]
  //  Referenced by: '<S45>/Gain1'

  { 1.0, 1.0, -1.0 },

  // Expression: [1 1]
  //  Referenced by: '<S45>/Gain2'

  { 1.0, 1.0 },

  // Expression: [-1 1]
  //  Referenced by: '<S45>/Gain3'

  { -1.0, 1.0 },

  // Expression: -1
  //  Referenced by: '<S35>/Gain'

  -1.0
};

//
// File trailer for generated code.
//
// [EOF]
//
