//
//  example
//  
//
//  Created by Zev Kronenberg on 7/29/15.
//  This is prototype code - NO GUARANTEE
//  The code was ported from : https://github.com/broadinstitute/hellbender/tree/179e3f1350befc857041615f1816de48b9445603/src/main/java/org/broadinstitute/hellbender/utils/pairhmm


#include <iostream>
#include "lib/alignHMM.h"
#include "lib/phredUtils.h"
//#include "phredUtilsTests.h"

int main(int argc, const char * argv[]) {
        
  // reference sequence (no quality assumed)
  std::string haplotype = "TGGGGTTCA";
  // read DNA sequence N okay
  std::string readSeq  =  "ACGTGCT";
  // phred scaled quality string
  std::string readQual =  "=@@:5((";


  std::cerr << "Haplotype: "  << std::endl;
  std::cerr << "           TGGGGTTCA" << std::endl;
  std::cerr <<  "Read     : "  << std::endl;
  std::cerr << "           " << readSeq << std::endl;
  std::cerr << "Read Qual: " << std::endl;
  std::cerr << "           " << readQual << std::endl;
  std::cerr << std::endl;
  

  std::cerr << "Step1. Construct class with readlength +1 and halotype length +1." << std::endl; 
  std::cerr << "Step2. Init priors with haplotype seq, read seq and read quals."   << std::endl; 
  std::cerr << "Step3. Update cells in model."                                     << std::endl;
  std::cerr << "step4. Call finalLikelihoodCalculation()                           " << std::endl;

  // constructing the alignHMM class
  alignHMM mats(int(readSeq.size()) +1,int(haplotype.size()) +1);
    
  //Transition matrix was taken verbatim
  //transitions :
  //            : Match to Insertion: Q45
  //            : Match to Deletion : Q45
  //            : Match To Match    :    

  mats.initPriors(haplotype, readSeq, readQual);
  mats.initTransProbs();
  mats.initializeDelMat();
  mats.updatecells();

  std::cout << "priors    : " << std::endl;
  mats.dumpPrior();
  std::cout << "trans     : " << std::endl;
  mats.dumpTrans();
   
  std::cout << "deletion  : " << std::endl;
  mats.dumpDeletionMatrix() ;

  std::cout << "insertion : " << std::endl;
  mats.dumpInsertionMatrix();
    
  std::cout << "match     : " << std::endl;
  mats.dumpMatchMatrix();

  double pRead = mats.finalLikelihoodCalculation();
  std::cout << "Final log10 read prob given haplotype: "
	    << pRead << std::endl;
  return 0;
}
