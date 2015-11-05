#include "gtest/gtest.h"
#include "../lib/phredUtils.h"

TEST(phredUtils, qualToProbErrorLog10){
  phredUtils pu;
  double Log10P = pu.qualToProbErrorLog10(';');
  ASSERT_NEAR(-2.6, Log10P, 0.5);
};

TEST(phredUtils, phredToLog10){
  phredUtils pu;
  double Log10P = pu.phredToLog10(10);
  ASSERT_NEAR(-1, Log10P, 0.5);
};

TEST(phredUtils, qualToProb){
  phredUtils pu;  
  double prob = pu.qualToProb('@');
  ASSERT_NEAR(0.00079432823472428131, prob, 0.01);
};

TEST(phredUtils, phredToProb){
  phredUtils pu;
  double prob = pu.phredToProb(26);
  ASSERT_NEAR(0.002511886, prob, 0.01);
};

TEST(phredUtils, addLog){
  phredUtils pu;
  double logSum = pu.log10Add(-0.60206,-0.60206);
  ASSERT_NEAR(-0.30103, logSum, 0.01);
};

TEST(phredUtils, qualToPhred){ 
  phredUtils pu;
  int PhredQual = pu.qualToPhred('!');
  ASSERT_EQ(0, PhredQual);
  PhredQual = pu.qualToPhred('+');
  ASSERT_EQ(10, PhredQual);
  PhredQual = pu.qualToPhred('@');
  ASSERT_EQ(31, PhredQual);
  PhredQual = pu.qualToPhred(';');
  ASSERT_EQ(26, PhredQual);
  PhredQual = pu.qualToPhred('D');
  ASSERT_EQ(35, PhredQual);
  PhredQual = pu.qualToPhred('I');
  ASSERT_EQ(40, PhredQual);

  pu.setIllumina();
  
  PhredQual = pu.qualToPhred('@');
  ASSERT_EQ(0, PhredQual);
  PhredQual = pu.qualToPhred('h');
  ASSERT_EQ(40, PhredQual);
};

