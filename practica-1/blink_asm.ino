void setup()
{
  DDRB = DDRB | B10000000; // Data Direction Register B: Inputs 0-6, Output 7
}
void loop()
{
  asm (
    "inicio: \n\t"      //sub rutina "inicio"
    "sbi 0x05,0x07 \n\t"// Aqui creemos que prende SBI pone 1 un bit
    "call tiempo \n\t"  // Llamamos a la subrutina tiempo
    "cbi 0x05,0x07 \n\t"// Aqui creemos que apaga CBI pone 0 un bit
    "call tiempo \n\t"  // Llama subrutina tiepo
    "jmp main \n\t"     //saltamos a main, i.e., reempezamos, palabra reservada
    
    "tiempo: \n\t"      //subrutina "tiempo"
    "LDI r22, 45 \n\t"  // Carga 45 al registro 22?
    "LOOP_3: \n\t"      // Subsubrutina loop3
    "LDI r21, 255 \n\t" // Carga 255 al registro r21
      "LOOP_2: \n\t"      // Subsubrutina loop2
      "LDI r20, 255 \n\t" // Carga 255 al registro 20
        "LOOP_1: \n\t"      // Subsubrutina loop1
        "DEC r20 \n\t"      // Resta 1 al registro 20
        "BRNE LOOP_1 \n\t"  // Salta si es diferente a algo....
        "DEC r21 \n\t"      // Resta 1 al registro 21
        "BRNE LOOP_2 \n\t"  // Salta si es diferente a algo....
        "DEC r22 \n\t"      // Resta 1 al registro 22
        "BRNE LOOP_3 \n\t"  // Salta si es diferente a algo...
        "ret \n\t"          // Return
  );
}
