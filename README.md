# Mothur
# Language: C++
# Input: MOTHUR (input Mothur file)
# Output: none (screen and output files specified in the .mothur input file)
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: Mothur 1.39.5

PluMA plugin that runs Mothur software (Schloss, 2009) (generated by PluGen).
The plugin accepts as input a program in the Mothur domain-specific language (DSL),
similar to the software itself.  We leave the output as "none", since 
the input program will likely produce multiple output files through commands
in the DSL.

Requires Mothur to be installed and in the system PATH
