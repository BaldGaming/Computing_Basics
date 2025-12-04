load sumArr.asm,
output-file sumArr.out,
compare-to sumArr.cmp,
output-list RAM[0]%D2.6.2;

set RAM[1] 5,   // sets test arguments
set RAM[2] 4,
set RAM[5] 100,
set RAM[6] 200,
set RAM[7] 21,
set RAM[8] -5,
set RAM[0] -1;  // tests that product was initialized to 0
repeat 2000 {
  ticktock;
}
output;

set PC 0,
set RAM[1] 5,   // sets test arguments
set RAM[2] 4,
set RAM[5] 0,
set RAM[6] 0,
set RAM[7] 0,
set RAM[8] 0,
set RAM[0] -1;  // tests that product was initialized to 0
repeat 2000 {
  ticktock;
}
output;

set PC 0,
set RAM[1] 5,   // sets test arguments
set RAM[2] 0,
set RAM[5] 2,
set RAM[6] 2,
set RAM[7] 2,
set RAM[8] 2,
set RAM[0] -1;  // tests that product was initialized to 0
repeat 2000 {
  ticktock;
}
output;

set PC 0,
set RAM[1] 10,   // sets test arguments
set RAM[2] 6,
set RAM[10] -10,
set RAM[11] -21,
set RAM[12] -30,
set RAM[13] -41,
set RAM[14] -51,
set RAM[15] -60,
set RAM[0] -1;  // tests that product was initialized to 0
repeat 2000 {
  ticktock;
}
output;

