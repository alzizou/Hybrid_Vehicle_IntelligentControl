call "%VS100COMNTOOLS%\..\..\VC\vcvarsall.bat" AMD64
nmake -f online_fuzz_clus_sfun.mak
