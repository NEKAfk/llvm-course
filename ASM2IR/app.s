BB_0:
  MOVi   x1 1
  SUBi   x0 x0 17952
  ZEROES  x0 17952
BB_2:                                                
  MOVi   x4 1
  MULi   x2 x1 66
  GEP32   x2 x0 x2
BB_9:                                                
  XOR   x5 x5 x5
  RND_MOD   x3 10
  JMP_EQ  x3 0 BB_14 BB_19
BB_6:                                                
  XOR   x6 x6 x6
  ADDi   x1 x1 1
  JMP_EQ  x1 33 BB_24 BB_2
BB_14:                                               
  RND_MOD   x3 50
  ICMP_EQ  x3 x3 0
  SELECTii    x5 x3 16711680 65280
BB_19:
  GEP32   x3 x2 x4
  STORE x5 x3
  ADDi   x4 x4 1
  JMP_EQ  x4 65 BB_6 BB_9

BB_24:                                               
  XOR   x1 x1 x1
  GEP2_32   x2 x0 2244 x6 x1
BB_28:
  XOR   x5 x5 x5
  MOV   x3 x1
  ADDi   x1 x1 1
  GEP32   x4 x2 x1   
  SHLi   x3 x3 3
BB_38:                                               
  XOR   x9 x9 x9
  MOV   x10 x5
  ADDi   x5 x5 1
  MULi   x11 x5 66
  GEP32   x11 x4 x11
  LOAD  x11 x11   
  SHLi   x10 x10 3
BB_46:                                               
  XOR   x12 x12 x12
  ADD   x13 x9 x3
BB_52:
  ADD   x14 x12 x10
  PUT_PIXEL   x13 x14 x11
  ADDi   x12 x12 1
  JMP_EQ  x12 8 BB_49 BB_52
BB_34:
  JMP_EQ  x5 32 BB_36 BB_38
BB_36:
  JMP_EQ  x1 64 BB_57 BB_28
BB_49:                                               
  ADDi   x9 x9 1
  JMP_EQ  x9 8 BB_34 BB_46
BB_57:                                               
  MOVi   x1 1
  FLUSH
  XORi   x15 x6 1 
BB_60:                                               
  MOVi   x5 1
  MULi   x12 x1 66   
BB_67:                                               
  MOVi   x9 -1
  MOVi   x11 0
  MOVi   x14 0   
BB_73:                                               
  MOVi   x13 -1
  ADD   x3 x9 x1
  MULi   x3 x3 66
  ADD   x3 x3 x5
BB_86:
  OR  x8 x13 x9
  JMP_EQ  x8 0 BB_103 BB_92
BB_64:
  XORi  x6 x6 1
  JMP   BB_24
BB_70:                                               
  ADDi   x1 x1 1
  JMP_EQ  x1 33 BB_64 BB_60
BB_80:                                               
  ADD   x4 x5 x12
  JMP_EQ  x14 3 BB_114 BB_108
BB_83:                                               
  ADDi   x9 x9 1
  JMP_EQ  x9 2 BB_80 BB_73
BB_92:                                               
  ADD   x8 x3 x13
  GEP2_32   x8 x0 2244 x6 x8
  LOAD  x8 x8
  ICMP_NE  x10 x8 0   
  ADD   x14 x14 x10
  ICMP_EQ  x10 x8 16711680   
  OR  x11 x11 x10
BB_103:
  ADDi   x13 x13 1
  JMP_EQ  x13 2 BB_83 BB_86
BB_108:                                              
  XOR   x2 x2 x2 
  GEP2_32   x8 x0 2244 x6 x4
  LOAD  x8 x8
  ICMP_NE  x8 x8 0
  ICMP_EQ    x7 x14 2
  SELECTri  x8 x8 x7 0
  JMP_COND  x8 BB_114 BB_117
BB_114:                                              
  ICMP_EQ  x8 x11 0
  SELECTii  x2 x8 65280 16711680
BB_117:
  GEP2_32   x8 x0 2244 x15 x4
  STORE x2 x8
  ADDi   x5 x5 1
  JMP_EQ  x5 65 BB_70 BB_67