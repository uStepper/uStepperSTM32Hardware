/* LL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef STM32H7xx
  #include "stm32h7xx_ll_swpmi.c"
#elif STM32L4xx
  #include "stm32l4xx_ll_swpmi.c"
#endif
#pragma GCC diagnostic pop
