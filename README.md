# alignReadToHapHMM

alignReadToHapHMM headers align NGS reads to a “reference” haplotype and calculates the probability of the read given the haplotype using a modified pairedHMM.

### Requirements
A modern c++ compiler

cmake

### Running the code:
```
git clone https://github.com/zeeev/alignReadToHapHMM.git
cd alignReadToHapHMM
make

```

### Note :

log10() and pow() approximations have made the code much faster at the expense of ~1-5 logLikelihood.  