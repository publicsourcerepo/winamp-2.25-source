/***************************************************************************\
 *
*                    MPEG Layer3-Audio Decoder
*                  � 1997-2006 by Fraunhofer IIS
 *                        All Rights Reserved
 *
 *   filename: polyphase.cpp
 *   project : ISO/MPEG-Decoder
 *   author  : Stefan Gewinner
 *   date    : 1998-05-26
 *   contents/description: polyphase class
 *
 *
\***************************************************************************/

/*
 * $Date: 2011/02/14 22:43:53 $
 * $Id: polyphase.cpp,v 1.7 2011/02/14 22:43:53 bigg Exp $
 */

/* ------------------------ includes --------------------------------------*/

#include "polyphase.h"

/*-------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------
 *
 * function to convert a Polyphase Window according to ISO/MPEG into a
 * polyphase window used in _this_ decoder
 *
 *
 *  int    i, j, index = 0;
 *  double tmp;
 *  float  window[512];    // ISO/MPEG Window
 *  float  my_window[512]; // window used in _this_ decoder
 *
 *  for ( i=0; i<512; i+=32 )
 *    for ( j=1; j<8; j++ )
 *      {
 *      tmp            = window[i+j+16];
 *      window[i+j+16] = window[i+32-j];
 *      window[i+32-j] = tmp;
 *      }
 *
 *  for ( j=0; j<16; j++ )
 *     for ( i=0; i<512; i+=64 )
 *       {
 *       window[i+j+16] *= -1.0;
 *       window[i+j+32] *= -1.0;
 *       window[i+j+48] *= -1.0;
 *       }
 *
 *  for ( j=0; j<16; j++ )
 *    for ( i=0; i<512; i+=64 )
 *      {
 *      my_window[index]    = window[i+j];
 *      my_window[index+1]  = window[i+j+16];
 *      my_window[index+2]  = window[i+j+32];
 *      my_window[index+3]  = window[i+j+48];
 *      index += 4;
 *      }
 * ------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------*/

static const float syn_f_window[HAN_SIZE] =
{
                        0,       7.62939453125e-005f,       0.0004425048828125f,          0.0015869140625f,
      0.0032501220703125f,       -0.002227783203125f,       0.0070037841796875f,       0.0239105224609375f,
      0.0310821533203125f,       0.0006866455078125f,       0.0786285400390625f,       0.1484222412109375f,
       0.100311279296875f,       0.1522064208984375f,       0.5720367431640625f,       0.9768524169921875f,
       1.144989013671875f,      -0.9768524169921875f,      -0.5720367431640625f,      -0.1522064208984375f,
       0.100311279296875f,      -0.1484222412109375f,      -0.0786285400390625f,      -0.0006866455078125f,
      0.0310821533203125f,      -0.0239105224609375f,      -0.0070037841796875f,        0.002227783203125f,
      0.0032501220703125f,         -0.0015869140625f,      -0.0004425048828125f,      -7.62939453125e-005f,
     -1.52587890625e-005f,        0.000396728515625f,       0.0004730224609375f,           0.003173828125f,
       0.003326416015625f,       0.0061187744140625f,       0.0079193115234375f,       0.0314788818359375f,
          0.030517578125f,         0.07305908203125f,       0.0841827392578125f,        0.108856201171875f,
      0.0909271240234375f,          0.5438232421875f,          0.6002197265625f,           1.144287109375f,
          1.144287109375f,         -0.6002197265625f,         -0.5438232421875f,       0.0909271240234375f,
       0.108856201171875f,      -0.0841827392578125f,        -0.07305908203125f,           0.030517578125f,
      0.0314788818359375f,      -0.0079193115234375f,      -0.0061187744140625f,        0.003326416015625f,
          0.003173828125f,      -0.0004730224609375f,       -0.000396728515625f,      -1.52587890625e-005f,
     -1.52587890625e-005f,          0.0003662109375f,       0.0005340576171875f,        0.003082275390625f,
       0.003387451171875f,       0.0052947998046875f,       0.0088653564453125f,            0.03173828125f,
           0.02978515625f,       0.0675201416015625f,       0.0897064208984375f,          0.1165771484375f,
         0.0806884765625f,       0.5156097412109375f,          0.6282958984375f,          1.1422119140625f,
         1.1422119140625f,         -0.6282958984375f,      -0.5156097412109375f,          0.0806884765625f,
         0.1165771484375f,      -0.0897064208984375f,      -0.0675201416015625f,            0.02978515625f,
           0.03173828125f,      -0.0088653564453125f,      -0.0052947998046875f,        0.003387451171875f,
       0.003082275390625f,      -0.0005340576171875f,         -0.0003662109375f,      -1.52587890625e-005f,
     -1.52587890625e-005f,       0.0003204345703125f,        0.000579833984375f,         0.00299072265625f,
      0.0034332275390625f,        0.004486083984375f,       0.0098419189453125f,       0.0318450927734375f,
      0.0288848876953125f,       0.0619964599609375f,       0.0951690673828125f,         0.12347412109375f,
      0.0695953369140625f,       0.4874725341796875f,        0.656219482421875f,        1.138763427734375f,
       1.138763427734375f,       -0.656219482421875f,      -0.4874725341796875f,       0.0695953369140625f,
        0.12347412109375f,      -0.0951690673828125f,      -0.0619964599609375f,       0.0288848876953125f,
      0.0318450927734375f,      -0.0098419189453125f,       -0.004486083984375f,       0.0034332275390625f,
        0.00299072265625f,       -0.000579833984375f,      -0.0003204345703125f,      -1.52587890625e-005f,
     -1.52587890625e-005f,       0.0002899169921875f,       0.0006256103515625f,        0.002899169921875f,
      0.0034637451171875f,         0.00372314453125f,       0.0108489990234375f,       0.0318145751953125f,
       0.027801513671875f,       0.0565338134765625f,       0.1005401611328125f,         0.12957763671875f,
            0.0576171875f,            0.45947265625f,       0.6839141845703125f,       1.1339263916015625f,
      1.1339263916015625f,      -0.6839141845703125f,           -0.45947265625f,             0.0576171875f,
        0.12957763671875f,      -0.1005401611328125f,      -0.0565338134765625f,        0.027801513671875f,
      0.0318145751953125f,      -0.0108489990234375f,        -0.00372314453125f,       0.0034637451171875f,
       0.002899169921875f,      -0.0006256103515625f,      -0.0002899169921875f,      -1.52587890625e-005f,
     -1.52587890625e-005f,       0.0002593994140625f,       0.0006866455078125f,       0.0027923583984375f,
        0.00347900390625f,       0.0030059814453125f,       0.0118865966796875f,       0.0316619873046875f,
      0.0265350341796875f,       0.0511322021484375f,       0.1058197021484375f,          0.1348876953125f,
      0.0447845458984375f,       0.4316558837890625f,       0.7113189697265625f,         1.12774658203125f,
        1.12774658203125f,      -0.7113189697265625f,      -0.4316558837890625f,       0.0447845458984375f,
         0.1348876953125f,      -0.1058197021484375f,      -0.0511322021484375f,       0.0265350341796875f,
      0.0316619873046875f,      -0.0118865966796875f,      -0.0030059814453125f,         0.00347900390625f,
      0.0027923583984375f,      -0.0006866455078125f,      -0.0002593994140625f,      -1.52587890625e-005f,
     -1.52587890625e-005f,           0.000244140625f,       0.0007476806640625f,           0.002685546875f,
        0.00347900390625f,       0.0023345947265625f,           0.012939453125f,       0.0313873291015625f,
        0.02508544921875f,         0.04583740234375f,       0.1109466552734375f,       0.1394500732421875f,
      0.0310821533203125f,        0.404083251953125f,        0.738372802734375f,       1.1202239990234375f,
      1.1202239990234375f,       -0.738372802734375f,       -0.404083251953125f,       0.0310821533203125f,
      0.1394500732421875f,      -0.1109466552734375f,        -0.04583740234375f,         0.02508544921875f,
      0.0313873291015625f,          -0.012939453125f,      -0.0023345947265625f,         0.00347900390625f,
          0.002685546875f,      -0.0007476806640625f,          -0.000244140625f,      -1.52587890625e-005f,
      -3.0517578125e-005f,        0.000213623046875f,       0.0008087158203125f,       0.0025787353515625f,
      0.0034637451171875f,       0.0016937255859375f,       0.0140228271484375f,           0.031005859375f,
      0.0234222412109375f,       0.0406341552734375f,       0.1159210205078125f,       0.1432647705078125f,
       0.016510009765625f,        0.376800537109375f,       0.7650299072265625f,       1.1113739013671875f,
      1.1113739013671875f,      -0.7650299072265625f,       -0.376800537109375f,        0.016510009765625f,
      0.1432647705078125f,      -0.1159210205078125f,      -0.0406341552734375f,       0.0234222412109375f,
          0.031005859375f,      -0.0140228271484375f,      -0.0016937255859375f,       0.0034637451171875f,
      0.0025787353515625f,      -0.0008087158203125f,       -0.000213623046875f,       -3.0517578125e-005f,
      -3.0517578125e-005f,       0.0001983642578125f,        0.000885009765625f,       0.0024566650390625f,
           0.00341796875f,          0.0010986328125f,       0.0151214599609375f,       0.0305328369140625f,
       0.021575927734375f,        0.035552978515625f,        0.120697021484375f,          0.1463623046875f,
       0.001068115234375f,       0.3498687744140625f,       0.7912139892578125f,       1.1012115478515625f,
      1.1012115478515625f,      -0.7912139892578125f,      -0.3498687744140625f,        0.001068115234375f,
         0.1463623046875f,       -0.120697021484375f,       -0.035552978515625f,        0.021575927734375f,
      0.0305328369140625f,      -0.0151214599609375f,         -0.0010986328125f,            0.00341796875f,
      0.0024566650390625f,       -0.000885009765625f,      -0.0001983642578125f,       -3.0517578125e-005f,
      -3.0517578125e-005f,       0.0001678466796875f,       0.0009613037109375f,        0.002349853515625f,
      0.0033721923828125f,         0.00054931640625f,          0.0162353515625f,        0.029937744140625f,
              0.01953125f,        0.030609130859375f,       0.1252593994140625f,        0.148773193359375f,
      -0.015228271484375f,       0.3233184814453125f,        0.816864013671875f,         1.08978271484375f,
        1.08978271484375f,       -0.816864013671875f,      -0.3233184814453125f,       -0.015228271484375f,
       0.148773193359375f,      -0.1252593994140625f,       -0.030609130859375f,               0.01953125f,
       0.029937744140625f,         -0.0162353515625f,        -0.00054931640625f,       0.0033721923828125f,
       0.002349853515625f,      -0.0009613037109375f,      -0.0001678466796875f,       -3.0517578125e-005f,
      -3.0517578125e-005f,        0.000152587890625f,         0.00103759765625f,       0.0022430419921875f,
      0.0032806396484375f,        3.0517578125e-005f,       0.0173492431640625f,       0.0292816162109375f,
      0.0172576904296875f,         0.02581787109375f,       0.1295623779296875f,       0.1504974365234375f,
      -0.032379150390625f,        0.297210693359375f,        0.841949462890625f,        1.077117919921875f,
       1.077117919921875f,       -0.841949462890625f,       -0.297210693359375f,       -0.032379150390625f,
      0.1504974365234375f,      -0.1295623779296875f,        -0.02581787109375f,       0.0172576904296875f,
      0.0292816162109375f,      -0.0173492431640625f,       -3.0517578125e-005f,       0.0032806396484375f,
      0.0022430419921875f,        -0.00103759765625f,       -0.000152587890625f,       -3.0517578125e-005f,
     -4.57763671875e-005f,       0.0001373291015625f,       0.0011138916015625f,       0.0021209716796875f,
          0.003173828125f,      -0.0004425048828125f,        0.018463134765625f,        0.028533935546875f,
       0.014801025390625f,         0.02117919921875f,       0.1335906982421875f,       0.1515960693359375f,
       -0.05035400390625f,       0.2715911865234375f,        0.866363525390625f,       1.0632171630859375f,
      1.0632171630859375f,       -0.866363525390625f,      -0.2715911865234375f,        -0.05035400390625f,
      0.1515960693359375f,      -0.1335906982421875f,        -0.02117919921875f,        0.014801025390625f,
       0.028533935546875f,       -0.018463134765625f,       0.0004425048828125f,           0.003173828125f,
      0.0021209716796875f,      -0.0011138916015625f,      -0.0001373291015625f,      -4.57763671875e-005f,
     -4.57763671875e-005f,          0.0001220703125f,       0.0012054443359375f,         0.00201416015625f,
         0.0030517578125f,      -0.0008697509765625f,       0.0195770263671875f,       0.0277252197265625f,
       0.012115478515625f,       0.0167083740234375f,        0.137298583984375f,        0.152069091796875f,
     -0.0691680908203125f,       0.2465057373046875f,       0.8900909423828125f,         1.04815673828125f,
        1.04815673828125f,      -0.8900909423828125f,      -0.2465057373046875f,      -0.0691680908203125f,
       0.152069091796875f,       -0.137298583984375f,      -0.0167083740234375f,        0.012115478515625f,
      0.0277252197265625f,      -0.0195770263671875f,       0.0008697509765625f,          0.0030517578125f,
        0.00201416015625f,      -0.0012054443359375f,         -0.0001220703125f,      -4.57763671875e-005f,
       -6.103515625e-005f,       0.0001068115234375f,       0.0012969970703125f,       0.0019073486328125f,
      0.0028839111328125f,      -0.0012664794921875f,         0.02069091796875f,       0.0268402099609375f,
      0.0092315673828125f,        0.012420654296875f,       0.1406707763671875f,       0.1519622802734375f,
      -0.088775634765625f,         0.22198486328125f,        0.913055419921875f,       1.0319366455078125f,
      1.0319366455078125f,       -0.913055419921875f,        -0.22198486328125f,       -0.088775634765625f,
      0.1519622802734375f,      -0.1406707763671875f,       -0.012420654296875f,       0.0092315673828125f,
      0.0268402099609375f,        -0.02069091796875f,       0.0012664794921875f,       0.0028839111328125f,
      0.0019073486328125f,      -0.0012969970703125f,      -0.0001068115234375f,        -6.103515625e-005f,
       -6.103515625e-005f,       0.0001068115234375f,       0.0013885498046875f,       0.0017852783203125f,
      0.0027008056640625f,       -0.001617431640625f,         0.02178955078125f,        0.025909423828125f,
       0.006134033203125f,       0.0083160400390625f,          0.1436767578125f,         0.15130615234375f,
      -0.109161376953125f,         0.19805908203125f,       0.9351959228515625f,        1.014617919921875f,
       1.014617919921875f,      -0.9351959228515625f,        -0.19805908203125f,       -0.109161376953125f,
        0.15130615234375f,         -0.1436767578125f,      -0.0083160400390625f,        0.006134033203125f,
       0.025909423828125f,        -0.02178955078125f,        0.001617431640625f,       0.0027008056640625f,
      0.0017852783203125f,      -0.0013885498046875f,      -0.0001068115234375f,        -6.103515625e-005f,
     -7.62939453125e-005f,        9.1552734375e-005f,       0.0014801025390625f,       0.0016937255859375f,
      0.0024871826171875f,      -0.0019378662109375f,        0.022857666015625f,        0.024932861328125f,
      0.0028228759765625f,            0.00439453125f,       0.1462554931640625f,        0.150115966796875f,
       -0.13031005859375f,       0.1747894287109375f,         0.95648193359375f,        0.996246337890625f,
       0.996246337890625f,        -0.95648193359375f,      -0.1747894287109375f,        -0.13031005859375f,
       0.150115966796875f,      -0.1462554931640625f,           -0.00439453125f,       0.0028228759765625f,
       0.024932861328125f,       -0.022857666015625f,       0.0019378662109375f,       0.0024871826171875f,
      0.0016937255859375f,      -0.0014801025390625f,       -9.1552734375e-005f,      -7.62939453125e-005f,

};

static const float cost32_c0[] =
  {
  0.50060299823520f,  0.50547095989754f,  0.51544730992262f,  0.53104259108978f,
  0.55310389603444f,  0.58293496820613f,  0.62250412303566f,  0.67480834145501f,
  0.74453627100230f,  0.83934964541553f,  0.97256823786196f,  1.16943993343288f,
  1.48416461631417f,  2.05778100995341f,  3.40760841846872f, 10.19000812354803f
  };

/* ------------------------------------------------------------------------*/

static const float cost32_c1[] =
  {
  0.50241928618816f,  0.52249861493969f,  0.56694403481636f,  0.64682178335999f,
  0.78815462345125f,  1.06067768599035f,  1.72244709823833f,  5.10114861868916f
  };

/* ------------------------------------------------------------------------*/

static const float cost32_c2[] =
  {
  0.50979557910416f,  0.60134488693505f,  0.89997622313642f,  2.56291544774151f
  };

/* ------------------------------------------------------------------------*/

static const float cost32_c3[] =
  {
  0.54119610014620f,  1.30656296487638f  
  };

/* ------------------------------------------------------------------------*/

static const float cost32_c4[] =
  {
  0.70710678118655f   // cos(pi/4)
  };

/*-------------------------------------------------------------------------*/

static void cost32(const float *vec,float *f_vec);

/*-------------------------------------------------------------------------*/

static void cost16(const float *vec,float *f_vec)
{
  float tmp1_0,tmp1_1,tmp1_2,tmp1_3,tmp1_4,tmp1_5,tmp1_6,tmp1_7;
  float res1_0,res1_1,res1_2,res1_3,res1_4,res1_5,res1_6,res1_7;

  float tmp2_0,tmp2_1,tmp2_2,tmp2_3;
  float res2_0,res2_1,res2_2,res2_3;

  float tmp3_0,tmp3_1;
  float res3_0,res3_1;

  tmp1_0 = vec[0]+vec[15];
  tmp1_1 = vec[1]+vec[14];
  tmp1_2 = vec[2]+vec[13];
  tmp1_3 = vec[3]+vec[12];
  tmp1_4 = vec[4]+vec[11];
  tmp1_5 = vec[5]+vec[10];
  tmp1_6 = vec[6]+vec[9];
  tmp1_7 = vec[7]+vec[8];

  tmp2_0 = tmp1_0+tmp1_7;
  tmp2_1 = tmp1_1+tmp1_6;
  tmp2_2 = tmp1_2+tmp1_5;
  tmp2_3 = tmp1_3+tmp1_4;

  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  f_vec[0]  = tmp3_0+tmp3_1;
  f_vec[16] = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];

  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];

  f_vec[8]  = res3_0+res3_1;
  f_vec[24] = res3_1;

  tmp2_0 = (tmp1_0-tmp1_7)*cost32_c2[0];
  tmp2_1 = (tmp1_1-tmp1_6)*cost32_c2[1];
  tmp2_2 = (tmp1_2-tmp1_5)*cost32_c2[2];
  tmp2_3 = (tmp1_3-tmp1_4)*cost32_c2[3];
  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  res2_0 = tmp3_0+tmp3_1;
  res2_2 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];
  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];

  res2_1 = res3_0+res3_1;
  res2_3 = res3_1;

  res1_1 = res2_0+res2_1;
  res1_3 = res2_1+res2_2;
  res1_5 = res2_2+res2_3;
  res1_7 = res2_3;

  f_vec[12] = res1_1;
  f_vec[4]  = res1_3;
  f_vec[20] = res1_5;
  f_vec[28] = res1_7;

  tmp1_0 = (vec[0]-vec[15])*cost32_c1[0];
  tmp1_1 = (vec[1]-vec[14])*cost32_c1[1];
  tmp1_2 = (vec[2]-vec[13])*cost32_c1[2];
  tmp1_3 = (vec[3]-vec[12])*cost32_c1[3];
  tmp1_4 = (vec[4]-vec[11])*cost32_c1[4];
  tmp1_5 = (vec[5]-vec[10])*cost32_c1[5];
  tmp1_6 = (vec[6]-vec[9])*cost32_c1[6];
  tmp1_7 = (vec[7]-vec[8])*cost32_c1[7];

  tmp2_0 = tmp1_0+tmp1_7;
  tmp2_1 = tmp1_1+tmp1_6;
  tmp2_2 = tmp1_2+tmp1_5;
  tmp2_3 = tmp1_3+tmp1_4;

  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  res1_0 = tmp3_0+tmp3_1;
  res1_4 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];

  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];

  res1_2 = res3_0+res3_1;
  res1_6 = res3_1;

  tmp2_0 = (tmp1_0-tmp1_7)*cost32_c2[0];
  tmp2_1 = (tmp1_1-tmp1_6)*cost32_c2[1];
  tmp2_2 = (tmp1_2-tmp1_5)*cost32_c2[2];
  tmp2_3 = (tmp1_3-tmp1_4)*cost32_c2[3];
  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  res2_0 = tmp3_0+tmp3_1;
  res2_2 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];

  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];

  res2_1 = res3_0+res3_1;
  res2_3 = res3_1;
  res1_1 = res2_0+res2_1;
  res1_3 = res2_1+res2_2;
  res1_5 = res2_2+res2_3;
  res1_7 = res2_3;

  f_vec[14] = res1_0+res1_1;
  f_vec[10] = res1_1+res1_2;
  f_vec[6] = res1_2+res1_3;
  f_vec[2] = res1_3+res1_4;
  f_vec[18] = res1_4+res1_5;
  f_vec[22] = res1_5+res1_6;
  f_vec[26] = res1_6+res1_7;
  f_vec[30] = res1_7;
}

/*-------------------------------------------------------------------------*/

static void cost8(const float *vec,float *f_vec)
{
  float res1_1,res1_3,res1_5,res1_7;

  float tmp2_0,tmp2_1,tmp2_2,tmp2_3;
  float res2_0,res2_1,res2_2,res2_3;

  float tmp3_0,tmp3_1;
  float res3_0,res3_1;

  tmp2_0 = vec[0]+vec[7];
  tmp2_1 = vec[1]+vec[6];
  tmp2_2 = vec[2]+vec[5];
  tmp2_3 = vec[3]+vec[4];

  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  f_vec[0]  = tmp3_0+tmp3_1;
  f_vec[16] = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];

  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];

  f_vec[8]  = res3_0+res3_1;
  f_vec[24] = res3_1;

  tmp2_0 = (vec[0]-vec[7])*cost32_c2[0];
  tmp2_1 = (vec[1]-vec[6])*cost32_c2[1];
  tmp2_2 = (vec[2]-vec[5])*cost32_c2[2];
  tmp2_3 = (vec[3]-vec[4])*cost32_c2[3];
  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  res2_0 = tmp3_0+tmp3_1;
  res2_2 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];
  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];

  res2_1 = res3_0+res3_1;
  res2_3 = res3_1;

  res1_1 = res2_0+res2_1;
  res1_3 = res2_1+res2_2;
  res1_5 = res2_2+res2_3;
  res1_7 = res2_3;

  f_vec[12] = res1_1;
  f_vec[4]  = res1_3;
  f_vec[20] = res1_5;
  f_vec[28] = res1_7;
}

/*-------------------------------------------------------------------------*/

//-------------------------------------------------------------------------*
//
//                   C P o l y p h a s e
//
//-------------------------------------------------------------------------*

//-------------------------------------------------------------------------*
//   constructor
//-------------------------------------------------------------------------*

CPolyphase::CPolyphase (const MPEG_INFO &_info) :  info (_info)

{
  Init() ;
}

//-------------------------------------------------------------------------*
//   Init
//-------------------------------------------------------------------------*

void CPolyphase::Init(void)
{
  int i,j;

  for ( j=0; j<2; j++ )
    for ( i=0; i<HAN_SIZE; i++ )
      syn_buf[j][i] = 0.0f;

  bufOffset = 32;
}

//-------------------------------------------------------------------------*
//   Apply (float)
//-------------------------------------------------------------------------*

float *CPolyphase::Apply(POLYSPECTRUM &sample, float *pPcm, int frms)
{
	int nChannels    = info.stereo;
	int k;

	if (nChannels == 1) // mono
	{
			for (k=0;k<frms;k++)
			{
				bufOffset = (bufOffset-32)&(HAN_SIZE-1);
				cost32(sample[0][k], &(syn_buf[0][bufOffset]));
				window_band_m(bufOffset, pPcm);
				pPcm += 32;
			}
	}
	else
	{

			for (k=0;k<frms;k++)
			{
				bufOffset = (bufOffset-32)&(HAN_SIZE-1);
				cost32(sample[0][k], &(syn_buf[0][bufOffset]));
				cost32(sample[1][k], &(syn_buf[1][bufOffset]));
				window_band_s(bufOffset, pPcm);
				pPcm += 64;
			}
		
		
	}
	
	return pPcm;
}

/*-------------------------------------------------------------------------*/

void CPolyphase::window_band_m(int bufOffset, float *out_samples) const
{
	const float *winPtr = syn_f_window;
	double       sum1,sum2;
	int          i,j;

	/* sum 0 and sum 16, 8, 4 (full, half, quarter spectrum) */
	sum1 = sum2 = 0;

	for ( i=0; i<512; i+=64 )
	{
		sum1 += syn_buf[0][(bufOffset+i+16)    & (HAN_SIZE-1)]*winPtr[0];
		sum2 += syn_buf[0][(bufOffset+i+32)    & (HAN_SIZE-1)]*winPtr[3];
		sum1 += syn_buf[0][(bufOffset+i+32+16) & (HAN_SIZE-1)]*winPtr[2];
		winPtr += 4;
	}

	out_samples[0]          = float(sum1 / 32768.0);
	out_samples[16] = float(sum2 / 32768.0);

	/* sum 1-15, 1-7, 1-3 and 17-31, 9-15, 5-7 (full, half, quarter spectrum) */

	for ( j=1; j<16; j++ )
	{
		sum1 = sum2 = 0;

		for ( i=0;i<512;i+=64 )
		{
			sum1 += syn_buf[0][(bufOffset+i+j+16) & (HAN_SIZE-1)]*winPtr[0];
			sum2 += syn_buf[0][(bufOffset+i+j+16) & (HAN_SIZE-1)]*winPtr[1];
			sum1 += syn_buf[0][(bufOffset+i+j+32) & (HAN_SIZE-1)]*winPtr[2];
			sum2 += syn_buf[0][(bufOffset+i+j+32) & (HAN_SIZE-1)]*winPtr[3];
			winPtr += 4;
		}

		out_samples[j]            = float(sum1 / 32768.0);
		out_samples[32-j] = float(sum2 / 32768.0);
	}
}

/*-------------------------------------------------------------------------*/

void CPolyphase::window_band_s(int bufOffset, float *out_samples) const
{
  const float *winPtr = syn_f_window;
  double       sum1l,sum2l,sum1r,sum2r;
  int          i,j,bufPtr;

  /* sum 0 and sum 16, 8, 4 (full, half, quarter spectrum) */
  sum1l = sum2l = sum1r = sum2r = 0;

  bufPtr = bufOffset;

  for ( i=0; i<512; i+=64 )
    {
    sum1l += syn_buf[0][bufPtr+16] * winPtr[0];
    sum1r += syn_buf[1][bufPtr+16] * winPtr[0];

    bufPtr = (bufPtr+32)&(HAN_SIZE-1);

    sum1l += syn_buf[0][bufPtr+16] * winPtr[2];
    sum1r += syn_buf[1][bufPtr+16] * winPtr[2];
    sum2l += syn_buf[0][bufPtr   ] * winPtr[3];
    sum2r += syn_buf[1][bufPtr   ] * winPtr[3];

    bufPtr = (bufPtr+32)&(HAN_SIZE-1);

    winPtr+=4;
    }

  out_samples[0]            = float(sum1l / 32768.0);
  out_samples[32>>0]     = float(sum2l / 32768.0);
  out_samples[1]            = float(sum1r / 32768.0);
  out_samples[(32>>0)+1] = float(sum2r / 32768.0);

  /* sum 1-15, 1-7, 1-3 and 17-31, 9-15, 5-7 (full, half, quarter spectrum) */

  for ( j=1; j<(16>>0); j++ )
    {
    sum1l = sum2l = sum1r = sum2r = 0;

    bufPtr  = bufOffset+j*(1<<0);
    winPtr += (1<<0)*32 - 32;

    for ( i=0; i<512; i+=64 )
      {
      sum1l += syn_buf[0][bufPtr+16]*winPtr[0];
      sum1r += syn_buf[1][bufPtr+16]*winPtr[0];
      sum2l += syn_buf[0][bufPtr+16]*winPtr[1];
      sum2r += syn_buf[1][bufPtr+16]*winPtr[1];

      bufPtr = (bufPtr+32)&(HAN_SIZE-1);

      sum1l += syn_buf[0][bufPtr]*winPtr[2];
      sum1r += syn_buf[1][bufPtr]*winPtr[2];
      sum2l += syn_buf[0][bufPtr]*winPtr[3];
      sum2r += syn_buf[1][bufPtr]*winPtr[3];

      bufPtr = (bufPtr+32)&(HAN_SIZE-1);

      winPtr += 4;
      }

    out_samples[j*2]                = float(sum1l / 32768.0);
    out_samples[((32>>0)-j)*2]   = float(sum2l / 32768.0);
    out_samples[j*2+1]              = float(sum1r / 32768.0);
    out_samples[((32>>0)-j)*2+1] = float(sum2r / 32768.0);
    }
}

/*-------------------------------------------------------------------------*/

static void cost32(const float *vec,float *f_vec)
{
  float tmp0_0,tmp0_1,tmp0_2,tmp0_3,tmp0_4,tmp0_5,tmp0_6,tmp0_7;
  float tmp0_8,tmp0_9,tmp0_10,tmp0_11,tmp0_12,tmp0_13,tmp0_14,tmp0_15;
  float res0_0,res0_1,res0_2,res0_3,res0_4,res0_5,res0_6,res0_7;
  float res0_8,res0_9,res0_10,res0_11,res0_12,res0_13,res0_14,res0_15;

  float tmp1_0,tmp1_1,tmp1_2,tmp1_3,tmp1_4,tmp1_5,tmp1_6,tmp1_7;
  float res1_0,res1_1,res1_2,res1_3,res1_4,res1_5,res1_6,res1_7;

  float tmp2_0,tmp2_1,tmp2_2,tmp2_3;
  float res2_0,res2_1,res2_2,res2_3;

  float tmp3_0,tmp3_1;
  float res3_0,res3_1;

  tmp0_0 = vec[0]+vec[31];
  tmp0_1 = vec[1]+vec[30];
  tmp0_2 = vec[2]+vec[29];
  tmp0_3 = vec[3]+vec[28];
  tmp0_4 = vec[4]+vec[27];
  tmp0_5 = vec[5]+vec[26];
  tmp0_6 = vec[6]+vec[25];
  tmp0_7 = vec[7]+vec[24];
  tmp0_8 = vec[8]+vec[23];
  tmp0_9 = vec[9]+vec[22];
  tmp0_10 = vec[10]+vec[21];
  tmp0_11 = vec[11]+vec[20];
  tmp0_12 = vec[12]+vec[19];
  tmp0_13 = vec[13]+vec[18];
  tmp0_14 = vec[14]+vec[17];
  tmp0_15 = vec[15]+vec[16];

  tmp1_0 = tmp0_0+tmp0_15;
  tmp1_1 = tmp0_1+tmp0_14;
  tmp1_2 = tmp0_2+tmp0_13;
  tmp1_3 = tmp0_3+tmp0_12;
  tmp1_4 = tmp0_4+tmp0_11;
  tmp1_5 = tmp0_5+tmp0_10;
  tmp1_6 = tmp0_6+tmp0_9;
  tmp1_7 = tmp0_7+tmp0_8;

  tmp2_0 = tmp1_0+tmp1_7;
  tmp2_1 = tmp1_1+tmp1_6;
  tmp2_2 = tmp1_2+tmp1_5;
  tmp2_3 = tmp1_3+tmp1_4;

  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  f_vec[0]  = tmp3_0+tmp3_1;
  f_vec[16] = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];

  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];

  f_vec[8]  = res3_0+res3_1;
  f_vec[24] = res3_1;

  tmp2_0 = (tmp1_0-tmp1_7)*cost32_c2[0];
  tmp2_1 = (tmp1_1-tmp1_6)*cost32_c2[1];
  tmp2_2 = (tmp1_2-tmp1_5)*cost32_c2[2];
  tmp2_3 = (tmp1_3-tmp1_4)*cost32_c2[3];
  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  res2_0 = tmp3_0+tmp3_1;
  res2_2 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];
  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];

  res2_1 = res3_0+res3_1;
  res2_3 = res3_1;

  res1_1 = res2_0+res2_1;
  res1_3 = res2_1+res2_2;
  res1_5 = res2_2+res2_3;
  res1_7 = res2_3;

  f_vec[12]  = res1_1;
  f_vec[4] = res1_3;
  f_vec[20] = res1_5;
  f_vec[28] = res1_7;

  tmp1_0 = (tmp0_0-tmp0_15)*cost32_c1[0];
  tmp1_1 = (tmp0_1-tmp0_14)*cost32_c1[1];
  tmp1_2 = (tmp0_2-tmp0_13)*cost32_c1[2];
  tmp1_3 = (tmp0_3-tmp0_12)*cost32_c1[3];
  tmp1_4 = (tmp0_4-tmp0_11)*cost32_c1[4];
  tmp1_5 = (tmp0_5-tmp0_10)*cost32_c1[5];
  tmp1_6 = (tmp0_6-tmp0_9)*cost32_c1[6];
  tmp1_7 = (tmp0_7-tmp0_8)*cost32_c1[7];
  tmp2_0 = tmp1_0+tmp1_7;
  tmp2_1 = tmp1_1+tmp1_6;
  tmp2_2 = tmp1_2+tmp1_5;
  tmp2_3 = tmp1_3+tmp1_4;
  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  res1_0 = tmp3_0+tmp3_1;
  res1_4 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];

  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];

  res1_2 = res3_0+res3_1;
  res1_6 = res3_1;

  tmp2_0 = (tmp1_0-tmp1_7)*cost32_c2[0];
  tmp2_1 = (tmp1_1-tmp1_6)*cost32_c2[1];
  tmp2_2 = (tmp1_2-tmp1_5)*cost32_c2[2];
  tmp2_3 = (tmp1_3-tmp1_4)*cost32_c2[3];
  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  res2_0 = tmp3_0+tmp3_1;
  res2_2 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];

  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];

  res2_1 = res3_0+res3_1;
  res2_3 = res3_1;
  res1_1 = res2_0+res2_1;
  res1_3 = res2_1+res2_2;
  res1_5 = res2_2+res2_3;
  res1_7 = res2_3;

  f_vec[14] = res1_0+res1_1;
  f_vec[10] = res1_1+res1_2;
  f_vec[6] = res1_2+res1_3;
  f_vec[2] = res1_3+res1_4;
  f_vec[18] = res1_4+res1_5;
  f_vec[22] = res1_5+res1_6;
  f_vec[26] = res1_6+res1_7;
  f_vec[30] = res1_7;

  /*  Odd Terms */
  tmp0_0 = (vec[0]-vec[31])*cost32_c0[0];
  tmp0_1 = (vec[1]-vec[30])*cost32_c0[1];
  tmp0_2 = (vec[2]-vec[29])*cost32_c0[2];
  tmp0_3 = (vec[3]-vec[28])*cost32_c0[3];
  tmp0_4 = (vec[4]-vec[27])*cost32_c0[4];
  tmp0_5 = (vec[5]-vec[26])*cost32_c0[5];
  tmp0_6 = (vec[6]-vec[25])*cost32_c0[6];
  tmp0_7 = (vec[7]-vec[24])*cost32_c0[7];
  tmp0_8 = (vec[8]-vec[23])*cost32_c0[8];
  tmp0_9 = (vec[9]-vec[22])*cost32_c0[9];
  tmp0_10 = (vec[10]-vec[21])*cost32_c0[10];
  tmp0_11 = (vec[11]-vec[20])*cost32_c0[11];
  tmp0_12 = (vec[12]-vec[19])*cost32_c0[12];
  tmp0_13 = (vec[13]-vec[18])*cost32_c0[13];
  tmp0_14 = (vec[14]-vec[17])*cost32_c0[14];
  tmp0_15 = (vec[15]-vec[16])*cost32_c0[15];

  tmp1_0 = tmp0_0+tmp0_15;
  tmp1_1 = tmp0_1+tmp0_14;
  tmp1_2 = tmp0_2+tmp0_13;
  tmp1_3 = tmp0_3+tmp0_12;
  tmp1_4 = tmp0_4+tmp0_11;
  tmp1_5 = tmp0_5+tmp0_10;
  tmp1_6 = tmp0_6+tmp0_9;
  tmp1_7 = tmp0_7+tmp0_8;
  tmp2_0 = tmp1_0+tmp1_7;
  tmp2_1 = tmp1_1+tmp1_6;
  tmp2_2 = tmp1_2+tmp1_5;
  tmp2_3 = tmp1_3+tmp1_4;
  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  res0_0 = tmp3_0+tmp3_1;
  res0_8 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];
  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];
  res0_4 = res3_0+res3_1;
  res0_12 = res3_1;

  tmp2_0 = (tmp1_0-tmp1_7)*cost32_c2[0];
  tmp2_1 = (tmp1_1-tmp1_6)*cost32_c2[1];
  tmp2_2 = (tmp1_2-tmp1_5)*cost32_c2[2];
  tmp2_3 = (tmp1_3-tmp1_4)*cost32_c2[3];
  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;
  res2_0 = tmp3_0+tmp3_1;
  res2_2 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];
  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];
  res2_1 = res3_0+res3_1;
  res2_3 = res3_1;
  res0_2 = res2_0+res2_1;
  res0_6 = res2_1+res2_2;
  res0_10 = res2_2+res2_3;
  res0_14 = res2_3;

  tmp1_0 = (tmp0_0-tmp0_15)*cost32_c1[0];
  tmp1_1 = (tmp0_1-tmp0_14)*cost32_c1[1];
  tmp1_2 = (tmp0_2-tmp0_13)*cost32_c1[2];
  tmp1_3 = (tmp0_3-tmp0_12)*cost32_c1[3];
  tmp1_4 = (tmp0_4-tmp0_11)*cost32_c1[4];
  tmp1_5 = (tmp0_5-tmp0_10)*cost32_c1[5];
  tmp1_6 = (tmp0_6-tmp0_9)*cost32_c1[6];
  tmp1_7 = (tmp0_7-tmp0_8)*cost32_c1[7];
  tmp2_0 = tmp1_0+tmp1_7;
  tmp2_1 = tmp1_1+tmp1_6;
  tmp2_2 = tmp1_2+tmp1_5;
  tmp2_3 = tmp1_3+tmp1_4;
  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;

  res1_0 = tmp3_0+tmp3_1;
  res1_4 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];
  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];
  res1_2 = res3_0+res3_1;
  res1_6 = res3_1;

  tmp2_0 = (tmp1_0-tmp1_7)*cost32_c2[0];
  tmp2_1 = (tmp1_1-tmp1_6)*cost32_c2[1];
  tmp2_2 = (tmp1_2-tmp1_5)*cost32_c2[2];
  tmp2_3 = (tmp1_3-tmp1_4)*cost32_c2[3];
  tmp3_0 = tmp2_0+tmp2_3;
  tmp3_1 = tmp2_1+tmp2_2;
  res2_0 = tmp3_0+tmp3_1;
  res2_2 = (tmp3_0-tmp3_1)*cost32_c4[0];

  tmp3_0 = (tmp2_0-tmp2_3)*cost32_c3[0];
  tmp3_1 = (tmp2_1-tmp2_2)*cost32_c3[1];
  res3_0 = tmp3_0+tmp3_1;
  res3_1 = (tmp3_0-tmp3_1)*cost32_c4[0];
  res2_1 = res3_0+res3_1;
  res2_3 = res3_1;
  res1_1 = res2_0+res2_1;
  res1_3 = res2_1+res2_2;
  res1_5 = res2_2+res2_3;
  res1_7 = res2_3;
  res0_1 = res1_0+res1_1;
  res0_3 = res1_1+res1_2;
  res0_5 = res1_2+res1_3;
  res0_7 = res1_3+res1_4;
  res0_9 = res1_4+res1_5;
  res0_11 = res1_5+res1_6;
  res0_13 = res1_6+res1_7;
  res0_15 = res1_7;

  f_vec[15] = res0_0+res0_1;
  f_vec[13] = res0_1+res0_2;
  f_vec[11] = res0_2+res0_3;
  f_vec[9] = res0_3+res0_4;
  f_vec[7] = res0_4+res0_5;
  f_vec[5] = res0_5+res0_6;
  f_vec[3] = res0_6+res0_7;
  f_vec[1] = res0_7+res0_8;
  f_vec[17] = res0_8+res0_9;
  f_vec[19] = res0_9+res0_10;
  f_vec[21] = res0_10+res0_11;
  f_vec[23] = res0_11+res0_12;
  f_vec[25] = res0_12+res0_13;
  f_vec[27] = res0_13+res0_14;
  f_vec[29] = res0_14+res0_15;
  f_vec[31] = res0_15;
}

void CPolyphase::Reorder(int channels, POLYSPECTRUM &output, const SPECTRUM &input)
{
	int ch, sb, ss;

	for ( ch=0; ch<channels; ch++ )
	{
		for ( ss=0; ss<SSLIMIT; ss++ )
			for ( sb=0; sb<SBLIMIT; sb++ )
				output[ch][ss][sb] = input[ch][sb][ss];
	}
}