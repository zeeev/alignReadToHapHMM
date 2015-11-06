#include "gtest/gtest.h"
#include "../lib/phredUtils.h"
#include "../lib/alignHMM.h"

TEST(alignHMM, checkCalculations){

  std::vector<std::string> trace;
  std::vector<std::string> quals;

  std::vector<double> answers;

  answers.push_back(-60.4809);
  answers.push_back(-198.926);
  answers.push_back(-196.328);
  answers.push_back(-195.468);
  answers.push_back(-141.216);
  answers.push_back(-200.92);
  answers.push_back(-200.909);
  answers.push_back(-196.945);
  answers.push_back(-199.763);
  answers.push_back(-168.69);
  answers.push_back(-196.138);
  answers.push_back(-192.176);
  answers.push_back(-197.826);
  answers.push_back(-161.079);
  answers.push_back(-199.972);
  answers.push_back(-189.983);
  answers.push_back(-174.137);
  answers.push_back(-180.017);
  answers.push_back(-187.001);
  answers.push_back(-185.074);
  answers.push_back(-197.583);
  answers.push_back(-198.817);
  answers.push_back(-201.791);
  answers.push_back(-181.215);
  answers.push_back(-186.309);
  answers.push_back(-198.127);
  answers.push_back(-184.246);
  answers.push_back(-103.285);
  answers.push_back(-141.517);
  answers.push_back(-156.395);
  answers.push_back(-198.39);
  answers.push_back(-195.902);
  answers.push_back(-167.054);
  answers.push_back(-197.817);
  answers.push_back(-191.474);
  answers.push_back(-193.752);
  answers.push_back(-187.13);
  answers.push_back(-187.623);
  answers.push_back(-161.427);
  answers.push_back(-192.368);
  answers.push_back(-193.1);
  answers.push_back(-192.825);
  answers.push_back(-194.382);
  answers.push_back(-105.77);
  answers.push_back(-194.364);
  answers.push_back(-185.61);
  answers.push_back(-182.681);
  answers.push_back(-187.953);
  answers.push_back(-190.976);
  answers.push_back(-195.794);
  answers.push_back(-196.859);
 
 
  std::string haplotype = "GCTTAAGGGTCCAACTAAACATTGCAGTGGCTCATCACAGAGCTGGAAGGAGCCTATATATAGAACTAGAGGCACAGTGGGTGGCCCTGAATACCTTACAGGAAGCAGACTGATTTTCTCATCCAAAAGGCATGCTACATGATGCAGAACAGTCAGTGGGGCCCCTGCAGTCAGGCCTCTCCCATGGAATCCCTGATCTGCACAATCAGTAAGGAACAGGAAGACTTCTGGGATTCAGATAGTGACCCCATGTTGCCCATTCCCTAGATAATGGGGACTTCAAGACAAAGCTCTAGAAAAATGAAAGGAAAAAGCAAAAAGTATCTAAGTCCTTAGCTGCTCCAAAAAAAAGGCCTGCAGCTGCAGGCTGTTGACCACTAATCCCTGGAAATGCATCAAGTAGACTGAAGCTAGGTCTGAGAAGAAATCAAGGCAGGTGTATACGGCCTACTGCATCTCTTTTCCCAAATTACGTTCAAGAAATACAGAAGTTCTCAGATATTGCTCTTTCCTCATTTTCCTCCTACCTCTTAGCTGTTCTTCCTATGGCCCTTGCACACTGAGTTGCCTGTTGCTCTGTCCAAGTCCTGCTAATTCCATGTTCTTTTTTTTTTTGAGACGGAGTCTCACTTCGTCACCAGGCTGGAGTGCAGTGGCACGATCCTGGCTCACTGCAACCTCTGCCTCCTGGATTCAAGTGATTCTTCTGGCTCAGCCTCCTGAGTAGCTGGGATTACAGGCGTGCGCCAACACGCCCAGCTAATTTTGTATATTTAGTAGAGACGGGGTTTCACCGTGTTAGCCAGGCTGATCTCGAACTCCCAACCTCAGGTGATCTGCCCGCCTCGGTCTCCCAAAGTGCTGGGATTACAGGTATGAGCCACCATGCCCAGCCCTAATTCCACTTTCTATTAATATTTCTGAAGTCTGTGTATTTTCACCTTTACTTAATGCAATGCTTTAAAATGGTCGAGGTATATTCCCTACCTAGAAGAACTCATACTTATACACAGTGGGACACATACACGGACTTACATACCACATAAAATTCATTGACAGAACACAGGAATAAACCAATGGTTGATTTATAAAATGTAATATTTTGTACCAAAGGTTTTCAAACTTCTTGGTCTTGGGATTCCTTTACACGCTTATTATATTGATCTTATCAGAAATTAAAACAATTTTTTTTGGAAAATTTAAGTCATTTAGAAAGGATAAACTTACTACATGTTAACATTTTTATGGAAAATAACTATATTTTCTAAATAAAAAATAATTTAGTGAAAAGAATGGCATTGTTTTACATTTTAAAAATGTCAGATCTACTTTTGCTTATACAGAATCTTTAGTCACAATCAGTCCATTCCACCTTTGAACTGAAAATGGTATTAATAGCGTGCAAAAATGTAAGGGGGCCTCTCCCTCTCCCTCTCCCTCTCCGTCTCCCTCTCCCTCTCCCTCTCCCTCTCCCTCTCACTCTCCCCACGGTCTCCCTCTCATGCGGAGCCGAAGCTGGACTGTACTGCTGCCATCTCGGCTCACTGCAACCTCCCTGCCTGATTCTCCTGCCTCAGCCTGCCGAGTGCCTGCGATTGCAGGCACGCGCCGCCACACCTGACTGGTCTTGGTGGAGACGGGGTTTCGCTGTGTTGGCCGGGCCGGTCTCCAGCCCCTGACCGCGAGTGATCCGCCAGCCTTGGCCTCCCGAGGTGCCAGGATTGCAGACGGAGTCTCGTTCACTCAGTGCTCAATGGTGCCCAGACTGGAGTGCAGTGGCGTGATCTCGGCTCGCTACGGCCTACACCTCCCAGCCGCCTGCCTTGGCCTCCCACGGTGCCGAGATTGCAGCCTCTGCCCGGCCGCCACCCCGTCTGGGAAGTGAGGAGCGTCTCTGCCTGGCTGCCCATCGTCTGGGATGTGAGGAGCCTCTCTGCCTGGCTGCCCAGTCTGGAAAGTGAGGAGCGTCTGCGCCCGGCCGCCATCCCATCTAGGAAGTGAGGAGCGCCTCTTCCCAGCCGCCATCACATCTAGGAAGTGAGGAGCGTCTCTGCCCGGCCGCCCATCGTCTGAGATGTGGGGAGCGCCTCTGCCCCGCCGCCCCATCTGGGATGTGAGGAGTGCCTCTGCCCGGCCGAGACCCCGTCTGGGAGGTGAGGAGCGTCTCTGCCCGGCCGCCCCGTGTGAGAAGTGAGGAGACCCTCTGCCTGGCAACCACCCCGTCTGAGAAGTGAGGAGCCCCTCCGCCCGGCAGCTGCCCCGTCTGAGAAGTGAGGAGCCTCTCCGCCCGGCAGCCACCCCATCTGGGAAGTGAGGAGCGTCTCTGCCCGGCAGCCACCCCGTCCGGGAGGGAGGTGGGGGGGTCAGCCCCTGCCCGGCCAGCCGCCCCATCCGGGAGGGAGGTCGGGGGTCAGCCCCCCGCCCGGCCAGCCGCCCCGTCCGGGAGGTGAGGGGCGCCTCTGCCCGGCCACCCCTACTGGGAAGTGAGGAGCCCCTCAGCCTGGCCAGCTGCCCTGTCCGGGAGGGAGGTGGGGGGGTCAGCCCTCCGCCCGGCCAGCCGCCCCGTCTGGGAGGTGAGGGGCGCCTCTGCCCGGCCGCCCCTACTGGGAAGTGAGGAGCCCCTCTGCCCGGCCAGCCGCCCCGTCCGGGAGGGAGGTGGGGGGGTCAGCCCCCTGCCCAGCCAGCCGCCCTGTCCAGGAGGGAGGTGGGGGGGTCAGCCCTCCGCCCGGCCAGCTGCCCCGTCTGGGAGGTGAGGGGCGCCTCTGCCCGGCCGCCCCTACTGGGAAGTGAGGAGCCCCTTTGCCCGGCCAGCCGCCCAGTCTGGGAGGGAGGTGGGGGGGTCAGCCCCCTGCCCGGCCAGCTGCCCCGTCCGGGAGGTGAGGGGCACCTCTGCCCGGCCGCCCCTACTGGGAAGTGAGGAGCCCCTCTGCCCGGCCAGCTGCCCCGTCTGGGAGGGAGGTGGGGGGGGGTCAGCCCCCCCGCCCGGCCAGCTGCCCCGTCCGGGAGGTGAGGGGCGCCTCTGCCCGGCCGCCCCTACTGGGAAGTGAGGAGCCCCTCTGCCCAGCCACCACCCCGTCTGGGAGGTGTGCCCAACAGCTCATTGAGAACGGGCCATGATGACAATGGCGGTTTTGTGGAATAGAAAAGGGGGAAAGGTGGGGAAAAGATTGAGAAATCGGATGGTTGCTGTGTCTGTGTAGAAAGAAGTAGACATGGGAGACTTTTCATTTTGTTCTGCACTAAGAAAAATTCTTCTGCCTTGGGATCCTGTTGATCTGTGACCTTACCCCCAACCCTGTGCTCTCTGAAACATGTGCTGTGTCCACTCAGGGTTAAATGGATTAAGGGCGGTGCAAGATGTGCTTTGTTAAACAGATGCTTGAAGGCAGCATGCTCGTTAAGAGTCATCACCAATCCCTAATCTCAAGTAATCAGGGACACAAACACTGCGGAAGGCTGCAGGGTCCTCTGCCTAGGAAAACCAGAGACCTTTGTTCACTTGTTTATCTGCTGACCTTCCCTCCACTATTGTCCCATGACCCTGCCAAATCCCCCTCTGTGAGAAACAACCAAGAATTATCAATAAAAAAATAAATTAAAAAAAAAAAAAAAAAAAAAAAAAGAAAATGGTATTAATACCATCAGCTGACATTAATTAAGCACTTAGTTTAGTTTATTTATCTATCTCATTTAATCCTTATAACAGCCCAATAAGCTAGACATCATTATTCCCATTATGAAGATGAGGCAGAAGACCTAAGGAAGGATAAATAATTCGCCAAATGTCACTTAAGCACCTGGTTGGACTGCAATGATTCTAATCTAGATGCTCTTACCCACCATGCTGTTAAACTTGATTGCACTGCATCATACACTTGATAATTCAACAGTTAATGATAATAAAGTCAAATTTACATCTACAAATCATGCAAGCTTAAATTGATACTACAAGTTTATTTCAACTTAATAGCTGGGAAATACTTAGGGGGTGTTATGGGCT";

  trace.push_back("CCATAGAACAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");
  trace.push_back("CAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTG");
  trace.push_back("CAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTG");
  trace.push_back("CAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTG");
  trace.push_back("ACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAG");
  trace.push_back("ACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAG");
  trace.push_back("CCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGA");
  trace.push_back("AAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAAT");
  trace.push_back("AGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATG");
  trace.push_back("AGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATG");
  trace.push_back("CACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCT");
  trace.push_back("CTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTCGGTTTGAAGAATGCTGAT");
  trace.push_back("TTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATG");
  trace.push_back("ACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACA");
  trace.push_back("CTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACAT");
  trace.push_back("TGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTT");
  trace.push_back("CAGCTCTCTAAGGGCCCAGATTTGAGTGTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTT");
  trace.push_back("AGCNNTCTNAGGGCCCAGANTTGAGTTTTGACTCAGAGAAGAGAGAGNAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTG");
  trace.push_back("CTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCA");
  trace.push_back("CTCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCA");
  trace.push_back("TCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAA");
  trace.push_back("TCTCTAAGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAA");
  trace.push_back("AGGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCC");
  trace.push_back("GGGCCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCT");
  trace.push_back("CCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTA");
  trace.push_back("CCCAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTA");
  trace.push_back("CAGATTTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATC");
  trace.push_back("TTGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTACAACTATCCTTTATCATCTG");
  trace.push_back("TGAGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCACCTGT");
  trace.push_back("AGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTT");
  trace.push_back("AGTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTT");
  trace.push_back("GTTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTT");
  trace.push_back("TTTTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTC");
  trace.push_back("TTGACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTG");
  trace.push_back("ACTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTAC");
  trace.push_back("CTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACT");
  trace.push_back("CTCAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGTAACTATCCTTTATCATCTGTTTTCTGTACT");
  trace.push_back("CAGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTC");
  trace.push_back("AGAGAAGAGCGAGCAGAGGTCTCTAGAAATGACTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCC");
  trace.push_back("AGAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCC");
  trace.push_back("GAGAAGAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCA");
  trace.push_back("GAGAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCACCACT");
  trace.push_back("GAGAGCAGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCACCACTGG");
  trace.push_back("GCAGAGGTCTCTAGAAATGCCTGTTGGGTGTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCACCACTGGCTCC");
  trace.push_back("AGAGGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCACCACTGGCTCCAC");
  trace.push_back("GGTCTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCACCACTGGCTCCACCTT");
  trace.push_back("CTCTAGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCACCACTGGCTCCACCTTTTT");
  trace.push_back("AGAAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCACCACTGGCTCCACCTTTTTCTTT");
  trace.push_back("AAATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCACCACTGGCTCCACCTTTTTCTTTCT");
  trace.push_back("AATGCCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCACCACTGGCTCCACCTTTTTCTTTCTG");
  trace.push_back("CCTGTTGGGTTTGAAGAATGCTGATGACATTTTTGCAACTATCCTTTATCATCTGTTTTCTGTACTTCCACCACTGGCTCCACCTTTTTCTTTCTGCAGT");
  
  quals.push_back("=?1+4=+2+2AA+AB9EDE:3<<A+2?E########################################################################");
  quals.push_back("CCCFFFFFGDFHHJJJJJJJJJIJJJJIIJIJJJJJJJJIIJJJJBHHIIGGHIIIIJJIIIIJJDHHHHFFFFD>@CEECDDDDDDDDDDDDDDB?BDD");
  quals.push_back("CC@DFDFFHHHH@HJIGIJJIIIIGIGBEHIIJIJGJIIHHEHGIGE?FHHHEHIGGHIIIFIIHGHGFGFFFDC;@AAEDCDDDDDCDCDCCAB\?\?@DD");
  quals.push_back("DBDDDCC@A>5DCCECEEEEDCFDBCEFFHJIIGCJHIIIIHIGJIHGIIHFBGBG>GGGIIIHGGHCHCIGIJJIIHGGJIJIG;IGHHHHFFFFF@C@");
  quals.push_back("@@;DDDDDHHHBFHCFHD:C3<+C<<<F<A;?FDDB?)0?B?D;9B?GGFD**).).8=F@@)5-5=E>E=5\?\?)76@6;>CC35(;@CA##########");
  quals.push_back(":DCCC>>5DDDCCCEEEEECFFEFHGHHFHGA>C:JIJJIJIIJIJIHIHEGJJIIIIHF>JIIIJIEIIJJIJIJIJJJJIGGIIJGGHGHEFFFFC@C");
  quals.push_back("BCCFFFFFFHHGHJJJIIJJJHIHJIJHIJGIIJJIDGIJEFGGHGIJIGHJJJJIIJJJJGIEHIHHGHH3;CDFDCEE6>CDDCDACDBD8?@@CCDC");
  quals.push_back("@@@FFFFFHGHHHJJIGIJJJJHIIIIICHIJGIJGIJFGIGGHIBGIJJEHGGFHJJJEGIJJCHGHH\?\?BDFFFFFEECEEEDDDDDD1<@?CCC@CD");
  quals.push_back("@A>:DDCDDCDDDEEEDDFFCBBDHHCHD@EIJIJIJJJJIIIGHHIIIGHEJJJIGIIIJJIGJIJIJJJIIIJJJIJIGIJJJIJHHHHHFFFFFCCC");
  quals.push_back("#@>:@:3A@>@CCC@>?;7;;;;7.AEGEGC4;B..4:EH>GFF99?*94HFB93FBB9?DGBHH:;DF?BE9C@AE>HH9@IHIIHFHHGGFDFDD<B=");
  quals.push_back("C@@FFFFFHHHHHJGIJIIIIIIJJJHHIJIJJIIIIJCFFHIIJEHHIGDCFGIJGGIIIDGHIGECHHEHHDFFFFBEECEECB@\?\?BDCCCDCCCDD");
  quals.push_back("CCCFFFFFHGHHHJJIGFHEHGCGHIIJIJIGGIJHIIIGIIGJJJIJGIHIJACGIIGGIJJCEHHHHHHHHFF?DFFEC(5;;@BDCDDCDDDDDDDD");
  quals.push_back("CCCFFFFFHHHGGIGIHIJJ>BGIJIJIICIJCH<GHHJJJJJGIGIGIGHIJJJJJIIJJJ=CGHEFHHHHGFD@CD;CEDD?@BBCCDDDDDDDCDCD");
  quals.push_back("@?@DD<DDFFH?F>EEE3C@G@=AC<<9:*81:DH>89?BBGHCB>D;BFI1C(8=9;@.7).>AC>A=.7=?C>?B?=/55=;;5;:ACCCC:(:>A##");
  quals.push_back("CCCFFFFFHHHHHJIJJJJJJJJJGJJJIJGIIIIIJIJIJIJGIJGHGHBCHIJIJJBCGGIIIGHFHHHHGDDFFFDBDBBDACDCDCCDDDDDEDCC");
  quals.push_back("@CCFDEFFHFFFHIGIGDFHJJIGIJIBCGFHJ=@DHIBGIGHDEEGGDBGHGIIE@@CHGGGGGGEEEECE=?>B8;=BBCACC3@@CACCDDDDDDC5");
  quals.push_back("CC<<C@CCCC?=.6))7?;?C>ACA;.)):HFC=)CCHFC<B:FB?FD393@?FD?4BB<DCD\?\?1=C)GFACGHHHIDF?HGG>G@FF<DHD>DDD<@<");
  quals.push_back("#########BDDBC?A=5,#FFFEHHHHEJIIHIJJJJJIJJIHF?0#IJIIHEJJJIJJJJIJJJJIHGIIJJIIIIJHIJIJJJJHGHHHFFFFFCCC");
  quals.push_back("7CCCC@=;?DA;<EFFDC>?;?6;>GAA@ECGHF>C=;HIGCJGIGGHGIIHDCFB@GCGFEGHEGIIHDDDGHGHHIGHGGJIGBJHHFHHDFDDF@@@");
  quals.push_back("B@@CCAAB;=9>;>7;;?@DEA?AC;CCC=4EEHCGFFHHCDF<?D?B?BF<IGG>GIHGFB=CECIHGCIHIGGIH@F<H>IHFFADFFHHDDBDDCC@");
  quals.push_back("@B@FDFADHHHHHIIIJJJIJJFGIIGEHEHCGIIGIGIGHHHIICHDGH3BFHIGGIIGEIIIJJHHGGG(;?BCCCEEDDDDDDCDEDDDDEEDDDED");
  quals.push_back(">ADDCCA@DDDEECFFDBFFGHHHA>HDGEIJIGHCCGAFIIIIJHGIHHIGGGGGGEGIGGGIIIIHHGFGIIIIHDJGGIGIIHHGGGHHFFFFFCCC");
  quals.push_back("CCCFFFFFHHHHHJJJEEHIJJJJJJJIJJIIGIGIEIDGHHII9DHIJFIJIGIJJJJJIIJJJCEFHFFFFFBAC@CEDDDCDDCDEDDDCCDDCACD");
  quals.push_back("@?@DFABDDHHGG@DG<<B:;AAFCHFH;ECFECCGGGCHAGA09DBGHE>@@FHCGA@8CHEHDEH7?>7@DFF>ACCCCCCCCCDDC;:5@@ACCC?D");
  quals.push_back("CCCFFFFFHHGHFEHGBGDIGCGGGGGEGH3EFAGGGEII3\?\?FH9DGIIIEGIBFHJEG65;CAEGH33?ADDB@DFF;>@CDEEBCCCA:>ACCACD@");
  quals.push_back("DC@DDCC?EEEEDEFFDCFFGGHHA>IJIIJJJIJIJIIEGJIGJJJIIIJIJJJJJJHHEJJIJJJIJJIJJJJJJIHIJJJIIGJGHFFHFFFFFCCC");
  quals.push_back("ACC@DDDCC>;..(@7C>CCHECEHECE@7=:DGGHCFB=:IIIGEGGFBBF;CFBDDCCEIHF?BCIHCAGGHGF<<IIHFEIHGFDHDHGFFFFF@@@");
  quals.push_back("######################################C@CB00B2D?8)1DDCD?4?1*:1:1*94C2++,+3EC<AC<EC<2+EEDB<DDD8DD\?\?\?\?");
  quals.push_back("###########A;>AA;73A?>DAA>@3>C@88))888=8BBB688B)2;DD<CIFFAFDC@*9<<>FEA<CC++:A+++,F:EE9BDA:?BD==+;=?8");
  quals.push_back("?@@\?\?DB=BBF<\?\?CF@F;:C++<AA?BE@@?9CFFC<@D<**000BFHIG@(71==FFC@;DD@AHE:7?E=?;;';(>;;A>@(;(;AA;@>CA####");
  quals.push_back("DDDDDDCCC@ACEEFFFFFFEHHHHFJJJIIJJJJIJJIJIJJJIGAIHHGHGJJJJJIIJJJJIJIIHCJIJJJJGGIHJJJGIIJHGHHGFFFFFCCC");
  quals.push_back("A>;CCC>A>C@ECEEDFED@FEHCCHJJJIIIJJIHF@3?HF@HIJJJJIIIHDJJIJJIIGBGGGC4GIIJJJJEJJIGJIHEGGHFFFDHDFDFFC@@");
  quals.push_back(":?8BD;4A=3ACDAGH@?AC;;CED+AF*::?FBFGG4*0DGFGFEB8@BBBAB)77=C@=..4.====AE;A>5;);;ACACCDCACCC:;>CC@AC9>");
  quals.push_back("DDCDDDDDDEEDEEDFFFDEFHHHHHJJIIJJJIGGHGFGGIGHGHIIJJJIIGIHGJIIIJIGGGIIIIIJJIIHIJIHIJIGGGEHHDADFFFFFCCC");
  quals.push_back("CCCFFFDFFDHDDFHGHEHHJIIAFHGGHGIIBGGHGDGGIIIIDFHHIJHGHIGGGIJJGIGJIEHIGHHH@EEFFFFEEEDEDEDCCDCCDCCDCAAC");
  quals.push_back("CADDDDDDDECEEEDFFFFFB>EHGHHIJJIIGHEJIIGHGIEIIIHHEHHGGA@GGIJIJJIIIIIHEJIIHHG@HHHEHJBJIGGFHDFFDDFFF@C@");
  quals.push_back("@:DDDDCCCEECCECDDDEEEECCC>EAEIIHGGDGGIJIHJIJJJIIGHAHFFFADIIDDBD=JIIGGHEIGEGHFBHFGGIHGGEGHGGHFFFFD@@B");
  quals.push_back("@CCDDEFF?F?FDHHIJFII3AHHIJIGJJDHIIFGGGIIIDDHGE@DDAAFHHIIIIJJJFDHIJGA?EHHHCFE>BFCECECCCC@CCCAC>>B:@CD");
  quals.push_back("\?\??DDDDDD+0)0C:A+AE2CBEE@B4CCDB*?1:0\?\?@AB\?\?7/BBD3B8A;CE:A=7).=.@CD;A:?;77;@>AAAB;(;5>A>>A?AAADAA>;>A");
  quals.push_back("DDC@DDDDDCEDDEEFFFFHHHGHGGIIIIJJIHCEGIIIJJIIIEIGDCDGCFIEIGGCFEJGIGIGGGH@HHEJGJIHHHGJIIGDGHHHFEDFD@CB");
  quals.push_back("DDDDDDCDCC@CDEEEBFFFFHHHHHHGGHIIIJIJJIIJJGJIIHIIHDIGDGGHGHEDJJJIJIIDJJIIIGIIGGHJJIJIJJIHHFFHDDFFF@C@");
  quals.push_back("CCCFFBDFGHGHHFHIJJJJJJJIJIJJJHIJJJHIIJIIIJJJJJIJIJJJJJJJJJJJJJJJJIJJJJHHHHHFHEFFDFFEEEEEEEEFDDDDDBDD");
  quals.push_back("DDDCDDDDDDEDEEEEEFFFEFHGHHHCGHFFGGIJIJHEHAJJJJJIIIIGGJIJJIJHGGGHFIHIJJJJJJIJIIIGJGJIIHEHFHF?DFFFFCCB");
  quals.push_back("#####################################CC8.==*?/B9()DB?0*B::0*1**9\?\?\?\?9?*:+FA3<A<HF@C<CGBFDDDFDDDDB\?\?@");
  quals.push_back("DDC<DDDDCEEECCC=DDFFFFHHHHIJJJIJJJJIIIIJJGHGJIGJIHABHGDHHGGFJJJJIIJJHGIIIJIGIJHHGJIIHFCFHFGGFFFFFCCC");
  quals.push_back("<?53CCEDDA;>5?=9CA9?FHECCFIIIIIHEGEGIHHCHGHCB?*IHFFDFDB9IIIIIGD>FCHGAFE<EHHC9HGIEHGBIHGHHHHF?ADDDC@@");
  quals.push_back("@@@FFDFFHHGDBGHIIIBFCGGGA<FFCGHGIJJJCACEHGIGGGGBBC?BDEFFHIIEEBB;F@7;FGEHGJGDHHGHHBDDB?7@2;>?@CB;@###");
  quals.push_back("@@@DFDFFHHGHHJIGCEFDHDFEHCA4E4*:<FFFGGIIIHEGGHGGHIHHGHGHFGIIJGHJDGIEIHAEHGC@?AA9C>CDDEC?CCAD:>>>>C@C");
  quals.push_back("@@CFFFF>DDHFBHFFHI@DDCHEHEGCF@GHI@GHI>DFI@HIIIIHICHIGHHIGBFEFEHHIIICEHIIGE>CHEHGDBFDFB:@>?>;@CCCCCCC");
  quals.push_back("DDBDBDDDDDBBEDEDACEFFFFFFHHHHHHEIIGJJJJIGHCEJJJIGJJJIGHGIIGJIGIJIGEEIGHGE9HFHFIJIIIIHAJHFHGHFFFFFCCC");
  quals.push_back("CCCFFFFFHHHHFIJJJHIIIJJJIGIIIIJJIJJJIJJIIGIGGHICGIJJJJJDFCHGIG=FHHIIIGJJIGGHCCEFFFFFEEEEEDCCCDDDDDC@");

    for(uint i = 0; i < trace.size(); i++){
      alignHMM mats(int(trace[i].size()) +1,int(haplotype.size()) +1);
      mats.initPriors(haplotype, trace[i], quals[i]);
      mats.initTransProbs();
      mats.initializeDelMat();
      mats.updatecells();
      
      double pRead = mats.finalLikelihoodCalculation();

      ASSERT_NEAR(answers[i], pRead, 5);
      
    }
};


TEST(alignHMM, higherQualHigherLL){

  std::vector<std::string> trace;
  std::vector<std::string> quals;

  std::string haplotype = "CCATAGAACAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT";
  trace.push_back("CCATAGAACAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");
  trace.push_back("CCATAGAACAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");
  trace.push_back("CCATAGAACAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");
  trace.push_back("CCATAGAACAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");

  quals.push_back("=?1+4=+2+2AA+AB9EDE:3<<A+2?E######!!!!!!##################################################!!!!!!!###");
  quals.push_back("=?1+4=+2+2AA+AB9EDE:3<<A+2?E####################################222#################################");
  quals.push_back("=?1+4=+2+2AA+AB9EDE:3<<A+2?E##############EE####################222################DDDDDDDDDD#######");
  quals.push_back("AAAA4=+2+2AA+AB9EDE:3<<A+2?E##############EE####################222################DDDDDDDDDD#######");

  alignHMM mats1(int(trace[0].size()) +1,int(haplotype.size()) +1);
  mats1.initPriors(haplotype, trace[0], quals[0]);
  mats1.initTransProbs();
  mats1.initializeDelMat();
  mats1.updatecells();

  //  double pRead1 = mats1.finalLikelihoodCalculation();

  alignHMM mats2(int(trace[1].size()) +1,int(haplotype.size()) +1);
  mats2.initPriors(haplotype, trace[1], quals[1]);
  mats2.initTransProbs();
  mats2.initializeDelMat();
  mats2.updatecells();

  double pRead2 = mats2.finalLikelihoodCalculation();


  alignHMM mats3(int(trace[2].size()) +1,int(haplotype.size()) +1);
  mats3.initPriors(haplotype, trace[2], quals[2]);
  mats3.initTransProbs();
  mats3.initializeDelMat();
  mats3.updatecells();

  double pRead3 = mats3.finalLikelihoodCalculation();

  alignHMM mats4(int(trace[3].size()) +1,int(haplotype.size()) +1);
  mats4.initPriors(haplotype, trace[3], quals[3]);
  mats4.initTransProbs();
  mats4.initializeDelMat();
  mats4.updatecells();

  double pRead4 = mats4.finalLikelihoodCalculation();


  std::cout << std::endl;
  std::cout << "[          ] alignment logLikelihood higher1 sanger qual : " << pRead2 << std::endl;
  std::cout << "[          ] alignment logLikelihood higher2 sanger qual : " << pRead3 << std::endl;
  std::cout << "[          ] alignment logLikelihood higher3 sanger qual : " << pRead4 << std::endl;
  std::cout << std::endl;

  ASSERT_GT(pRead4, pRead3);
  ASSERT_GT(pRead3, pRead2);

}


TEST(alignHMM, variants){

  std::vector<std::string> trace;
  std::vector<std::string> quals;

  // added TGC at start and end for indel buffering

  std::string haplotype = "TGCCCATAGAACAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGTTGC";

   
  trace.push_back("CCATAGAACAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");
  //                                 X  
  trace.push_back("CCATAGAACAAACCAAGCTCCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");
  //                                                             AGA  
  trace.push_back("CCATAGAACAAACCAAGCTCCTTTACTTGCAGCTCTCTAAGGGCCCTTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");
  //                                            CAT
  trace.push_back("CCATAGAACAAACCAAGCTCCTTTACTTGCATCAGCTCTCTAAGGGCCCTTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");
  //                                            CAT
  trace.push_back("CCATAGAACAAACCAAGCTCCTTTACTTGCATCAGCTCTCTAAGGGCCCTTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");

  quals.push_back("=?1+4=+2+2AA+AB9EDE:3<<A+2?E########################################################################");
  quals.push_back("=?1+4=+2+2AA+AB9EDE:3<<A+2?E########################################################################");
  quals.push_back("=?1+4=+2+2AA+AB9EDE:3<<A+2?E#####################################################################");
  quals.push_back("=?1+4=+2+2AA+AB9EDE:3<<A+2?E#$$$####################################################################");
  quals.push_back("=?1+4=+2+2AA+AB9EDE:3<<A+2?E#HHH####################################################################");


  alignHMM mats1(int(trace[0].size()) +1,int(haplotype.size()) +1);
  mats1.initPriors(haplotype, trace[0], quals[0]);
  mats1.initTransProbs();
  mats1.initializeDelMat();
  mats1.updatecells();

  double pRead1 = mats1.finalLikelihoodCalculation();
  
  alignHMM mats2(int(trace[1].size()) +1,int(haplotype.size()) +1);
  mats2.initPriors(haplotype, trace[1], quals[1]);
  mats2.initTransProbs();
  mats2.initializeDelMat();
  mats2.updatecells();

  double pRead2 = mats2.finalLikelihoodCalculation();


  alignHMM mats3(int(trace[2].size()) +1,int(haplotype.size()) +1);
  mats3.initPriors(haplotype, trace[2], quals[2]);
  mats3.initTransProbs();
  mats3.initializeDelMat();
  mats3.updatecells();

  double pRead3 = mats3.finalLikelihoodCalculation();

  alignHMM mats4(int(trace[3].size()) +1,int(haplotype.size()) +1);
  mats4.initPriors(haplotype, trace[3], quals[3]);
  mats4.initTransProbs();
  mats4.initializeDelMat();
  mats4.updatecells();

  double pRead4 = mats4.finalLikelihoodCalculation();

  alignHMM mats5(int(trace[4].size()) +1,int(haplotype.size()) +1);
  mats5.initPriors(haplotype, trace[4], quals[4]);
  mats5.initTransProbs();
  mats5.initializeDelMat();
  mats5.updatecells();

  double pRead5 = mats5.finalLikelihoodCalculation();

  std::cout << std::endl;
  std::cout << "[          ] logLikelihood exact match      : " << pRead1 << std::endl;
  std::cout << "[          ] logLikelihood 1 SNV            : " << pRead2 << std::endl;
  std::cout << "[          ] logLikelihood 3bp DEL          : " << pRead3 << std::endl;
  std::cout << "[          ] logLikelihood 3bp lowQual INS  : " << pRead4 << std::endl;
  std::cout << "[          ] logLikelihood 3bp highQual INS : " << pRead5 << std::endl;
  std::cout << std::endl;

  ASSERT_GT(pRead1, pRead2);
  ASSERT_GT(pRead1, pRead3);
  ASSERT_GT(pRead1, pRead4);
  ASSERT_GT(pRead1, pRead5);

};

TEST(alignHMM, variantCrossMapping){

  std::vector<std::string> trace;
  std::vector<std::string> quals;

  // added TGC at start and end for indel buffering

  std::string haplotypeA = "TGCCCATAGAACAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGTTGC";
  //                           CCATAGAACAAACCAAGCACCTTTACTTGCAG----------------ATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT
  std::string haplotypeB = "AGCTCCAGTTGCCCATAGAACAAACCAAGCACCTTTACTTGCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGTTGCCCAGCCC";


  trace.push_back("CCATAGAACAAACCAAGCACCTTTACTTGCAGCTCTCTAAGGGCCCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");
  trace.push_back("CCATAGAACAAACCAAGCACCTTTACTTGCAGATTTGAGTTTTGATTCAGAGATGAGATAGCAGAGGTCTCTAGAAATGTCTGT");

  quals.push_back("CCCFFFFFHHHHFIJJJHIIIJJJIGIIIIJJIJJJIJJIIGIGGHICGIJJJJJDFCHGIG=FHHIIIGJJIGGHCCEFFFFFEEEEEDCCCDDDDDC@");
  quals.push_back("CCCFFFFFHHHHFIJJJHIIIJJJIGIIIIJJIJJJIJJIIGIGGHICGIJJJJJDFCHGIG=FHHIIIGJJIGGHCCEFFFFF");


 
  alignHMM mats1(int(trace[0].size()) +1,int(haplotypeA.size()) +1);
  mats1.initPriors(haplotypeA, trace[0], quals[0]);
  mats1.initTransProbs();
  mats1.initializeDelMat();
  mats1.updatecells();

 double pRead1Ref = mats1.finalLikelihoodCalculation();

 alignHMM mats2(int(trace[0].size()) +1,int(haplotypeB.size()) +1);
 mats2.initPriors(haplotypeB, trace[0], quals[0]);
 mats2.initTransProbs();
 mats2.initializeDelMat();
 mats2.updatecells();

 double pRead1Alt = mats2.finalLikelihoodCalculation();



 std::cout << std::endl;
 std::cout << "[          ] logLikelihood ref read aligned to ref : " << pRead1Ref << std::endl;
 std::cout << "[          ] logLikelihood ref read aligned to alt : " << pRead1Alt << std::endl;
 std::cout << std::endl;

 ASSERT_GT(pRead1Ref, pRead1Alt);


 alignHMM mats3(int(trace[1].size()) +1,int(haplotypeA.size()) +1);
 mats3.initPriors(haplotypeA, trace[1], quals[1]);
 mats3.initTransProbs();
 mats3.initializeDelMat();
 mats3.updatecells();

 double pRead2Ref = mats3.finalLikelihoodCalculation();

 alignHMM mats4(int(trace[1].size()) +1,int(haplotypeB.size()) +1);
 mats4.initPriors(haplotypeB, trace[1], quals[1]);
 mats4.initTransProbs();
 mats4.initializeDelMat();
 mats4.updatecells();

 double pRead2Alt = mats4.finalLikelihoodCalculation();

 std::cout << std::endl;
 std::cout << "[          ] logLikelihood alt read aligned to ref : " << pRead2Ref << std::endl;
 std::cout << "[          ] logLikelihood alt read aligned to alt : " << pRead2Alt << std::endl;
 std::cout << std::endl;

 ASSERT_GT(pRead2Alt, pRead2Ref);


};
