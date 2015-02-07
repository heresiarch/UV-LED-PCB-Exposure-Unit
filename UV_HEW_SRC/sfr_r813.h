/************************************************************************************
*                                                                                   *
*   File Name   : SFR_R813.h                                                        *
*   Contents    : definition of R8C/13 Group SFR									*
*   Copyright, 2003 RENESAS TECHNOLOGY CORPORATION									*
*                   AND RENESAS SOLUTIONS CORPORATION								*
*   Version     : 1.00                                                              *
*   note        :                                                                   *
*                                                                                   *
************************************************************************************/
#ifndef SFR_R813_H
#define SFR_R813_H


/********************************************************
*  declare SFR addresses                                *
********************************************************/

#pragma ADDRESS    pm0_addr     0004H    /* Processor mode register0 */

#pragma ADDRESS    pm1_addr     0005H    /* Processor mode register1 */

#pragma ADDRESS    cm0_addr     0006H    /* System clock control register0 */

#pragma ADDRESS    cm1_addr     0007H    /* System clock control register1 */

#pragma ADDRESS    hr0_addr     0008H    /* High speed on-chip control register0 */

#pragma ADDRESS    aier_addr    0009H    /* Address match interrupt enable register */

#pragma ADDRESS    prcr_addr    000AH    /* Protect register */

#pragma ADDRESS    hr1_addr     000BH    /* High speed on-chip control register1 */

#pragma ADDRESS    ocd_addr     000CH    /* Xin stop detect register */

#pragma ADDRESS    wdtr_addr    000DH    /* Watchdog timer reset register */

#pragma ADDRESS    wdts_addr    000EH    /* Watchdog timer start register */

#pragma ADDRESS    wdc_addr     000FH    /* Watchdog timer control register */

#pragma ADDRESS    rmad0_addr   0010H    /* Address match interrupt register0 */

#pragma ADDRESS    rmad1_addr   0014H    /* Address match interrupt register1 */

#pragma ADDRESS    vcr1_addr    0019H    /* Voltage detect register1 */

#pragma ADDRESS    vcr2_addr    001AH    /* Voltage detect register2 */

#pragma ADDRESS    int0f_addr   001EH    /* INT0 input filter select register */

#pragma ADDRESS    d4int_addr   001FH    /* Voltage detect interrupt register */

#pragma ADDRESS    kupic_addr   004DH    /* Key input interrupt control register */

#pragma ADDRESS    adic_addr    004EH    /* A/D interrupt control register */

#pragma ADDRESS    cmp1ic_addr  0050H    /* Compare 1 interrupt control register */

#pragma ADDRESS    s0tic_addr   0051H    /* UART0 transmit interrupt control register */

#pragma ADDRESS    s0ric_addr   0052H    /* UART0 receive interrupt control register */

#pragma ADDRESS    s1tic_addr   0053H    /* UART1 transmit interrupt control register */

#pragma ADDRESS    s1ric_addr   0054H    /* UART1 receive interrupt control register */

#pragma ADDRESS    int2ic_addr  0055H    /* INT2 interrupt control register */

#pragma ADDRESS    txic_addr    0056H    /* Timer X interrupt control register */

#pragma ADDRESS    tyic_addr    0057H    /* Timer Y interrupt control register */

#pragma ADDRESS    tzic_addr    0058H    /* Timer Z interrupt control register */

#pragma ADDRESS    int1ic_addr  0059H    /* INT1 interrupt control register */

#pragma ADDRESS    int3ic_addr  005AH    /* INT3 interrupt control register */

#pragma ADDRESS    tcic_addr    005BH    /* Timer C interrupt control register */

#pragma ADDRESS    cmp0ic_addr  005CH    /* Compare 0 interrupt control register */

#pragma ADDRESS    int0ic_addr  005DH    /* INT0 interrupt control register */

#pragma ADDRESS    tyzmr_addr   0080H    /* Timer Y,Z mode register */

#pragma ADDRESS    prey_addr    0081H    /* Timer Y prescaler */

#pragma ADDRESS    tysc_addr    0082H    /* Timer Y secondary */

#pragma ADDRESS    typr_addr    0083H    /* Timer Y primary */

#pragma ADDRESS    pum_addr     0084H    /* Timer Y,Z wave-form output control register */

#pragma ADDRESS    prez_addr    0085H    /* Timer Z prescaler */

#pragma ADDRESS    tzsc_addr    0086H    /* Timer Z secondary */

#pragma ADDRESS    tzpr_addr    0087H    /* Timer Z primary */

#pragma ADDRESS    tyzoc_addr   008AH    /* Timer Y,Z output control register */

#pragma ADDRESS    txmr_addr    008BH    /* Timer X mode register */

#pragma ADDRESS    prex_addr    008CH    /* Timer X prescaler */

#pragma ADDRESS    tx_addr      008DH    /* Timer X */

#pragma ADDRESS    tcss_addr    008EH    /* Timer count source select register */

#pragma ADDRESS    tc_addr      0090H    /* Timer C */

#pragma ADDRESS    inten_addr   0096H    /* External interrupt enable register */

#pragma ADDRESS    kien_addr    0098H    /* Key input enable register */

#pragma ADDRESS    tcc0_addr    009AH    /* Timer C control register0 */

#pragma ADDRESS    tcc1_addr    009BH    /* Timer C control register1 */

#pragma ADDRESS    tm0_addr     009CH    /* Capture, compare0 register */

#pragma ADDRESS    tm1_addr     009EH    /* Compare1 register */

#pragma ADDRESS    u0mr_addr    00A0H    /* UART0 transmit/receive mode register */

#pragma ADDRESS    u0brg_addr   00A1H    /* UART0 bit rate generator */

#pragma ADDRESS    u0tb_addr    00A2H    /* UART0 transmit buffer register */

#pragma ADDRESS    u0c0_addr    00A4H    /* UART0 transmit/receive control register0 */

#pragma ADDRESS    u0c1_addr    00A5H    /* UART0 transmit/receive control register1 */

#pragma ADDRESS    u0rb_addr    00A6H    /* UART0 receive buffer register */

#pragma ADDRESS    u1mr_addr    00A8H    /* UART1 transmit/receive mode register */

#pragma ADDRESS    u1brg_addr   00A9H    /* UART1 bit rate generator */

#pragma ADDRESS    u1tb_addr    00AAH    /* UART1 transmit buffer register */

#pragma ADDRESS    u1c0_addr    00ACH    /* UART1 transmit/receive control register0 */

#pragma ADDRESS    u1c1_addr    00ADH    /* UART1 transmit/receive control register1 */

#pragma ADDRESS    u1rb_addr    00AEH    /* UART1 receive buffer register */

#pragma ADDRESS    ucon_addr    00B0H    /* UART transmit/receive control register2 */

#pragma ADDRESS    ad_addr      00C0H    /* A/D register */

#pragma ADDRESS    adcon2_addr  00D4H    /* A/D control register2 */

#pragma ADDRESS    adcon0_addr  00D6H    /* A/D control register0 */

#pragma ADDRESS    adcon1_addr  00D7H    /* A/D control register1 */

#pragma ADDRESS    p0_addr      00E0H    /* Port P0 register */

#pragma ADDRESS    p1_addr      00E1H    /* Port P1 register */

#pragma ADDRESS    pd0_addr     00E2H    /* Port P0 direction register */

#pragma ADDRESS    pd1_addr     00E3H    /* Port P1 direction register */

#pragma ADDRESS    p3_addr      00E5H    /* Port P3 register */

#pragma ADDRESS    pd3_addr     00E7H    /* Port P3 direction register */

#pragma ADDRESS    p4_addr      00E8H    /* Port P4 register */

#pragma ADDRESS    pd4_addr     00EAH    /* Port P4 direction register */

#pragma ADDRESS    pur0_addr    00FCH    /* Pull-up control register0 */

#pragma ADDRESS    pur1_addr    00FDH    /* Pull-up control register1 */

#pragma ADDRESS    drr_addr     00FEH    /* Port P1 drive capacity control register */

#pragma ADDRESS    tcout_addr   00FFH    /* Timer C output control register */

/********************************************************
*  declare SFR bit                                      *
********************************************************/
struct bit_def {
    char  b0:1;
    char  b1:1;
    char  b2:1;
    char  b3:1;
    char  b4:1;
    char  b5:1;
    char  b6:1;
    char  b7:1;
};
union byte_def{
  struct bit_def bit;
  char  byte;
};

/*------------------------------------------------------
  Processor mode register0
------------------------------------------------------*/
union byte_def pm0_addr;
#define    pm0     pm0_addr.byte

#define    pm03    pm0_addr.bit.b3       /* Software reset bit */

/*------------------------------------------------------
  Processor mode register1
------------------------------------------------------*/
union byte_def pm1_addr;
#define    pm1     pm1_addr.byte

#define    pm12    pm1_addr.bit.b2       /* WDT interrupt/reset select bit */

/*------------------------------------------------------
  System clock control register0
------------------------------------------------------*/
union byte_def cm0_addr;
#define    cm0     cm0_addr.byte

#define    cm02    cm0_addr.bit.b2       /* WAIT peripheral function clock stop bit */
#define    cm05    cm0_addr.bit.b5       /* Main clock stop bit */
#define    cm06    cm0_addr.bit.b6       /* Main clock division select bit0 */

/*------------------------------------------------------
  System clock control register1
------------------------------------------------------*/
union byte_def cm1_addr;
#define    cm1     cm1_addr.byte

#define    cm10    cm1_addr.bit.b0       /* All clock stop control bit */
#define    cm13    cm1_addr.bit.b3       /* Port Xin select bit */
#define    cm14    cm1_addr.bit.b4       /* On-chip clock stop bit */
#define    cm15    cm1_addr.bit.b5       /* Xin-Xout drive capacity select bit */
#define    cm16    cm1_addr.bit.b6       /* Main clock division select bit1 */
#define    cm17    cm1_addr.bit.b7       /* Main clock division select bit1 */

/*------------------------------------------------------
  High speed on-chip control register0
------------------------------------------------------*/
union byte_def hr0_addr;
#define    hr0     hr0_addr.byte

#define    hr00    hr0_addr.bit.b0       /* High speed On-chip enable bit */
#define    hr01    hr0_addr.bit.b1       /* High speed On-chip select bit */

/*------------------------------------------------------
  Address match interrupt enable register
------------------------------------------------------*/
union byte_def aier_addr;
#define    aier    aier_addr.byte

#define    aier0   aier_addr.bit.b0      /* Address match interrupt 0 enable bit */
#define    aier1   aier_addr.bit.b1      /* Address match interrupt 1 enable bit */

/*------------------------------------------------------
  Protect register
------------------------------------------------------*/
union byte_def prcr_addr;
#define    prcr    prcr_addr.byte

#define    prc0   prcr_addr.bit.b0       /* Protect bit0 */
#define    prc1   prcr_addr.bit.b1       /* Protect bit1 */
#define    prc2   prcr_addr.bit.b2       /* Protect bit2 */
#define    prc3   prcr_addr.bit.b3       /* Protect bit3 */

/*------------------------------------------------------
  High speed on-chip control register1
------------------------------------------------------*/
union byte_def hr1_addr;
#define    hr1     hr1_addr.byte

/*------------------------------------------------------
  Xin stop detect register
------------------------------------------------------*/
union byte_def ocd_addr;
#define    ocd    ocd_addr.byte

#define    ocd0   ocd_addr.bit.b0        /* Xin stop detect bit */
#define    ocd1   ocd_addr.bit.b1        /* Xin stop detect bit */
#define    ocd2   ocd_addr.bit.b2        /* System clock select bit */
#define    ocd3   ocd_addr.bit.b3        /* Xin-Xout clock monitor bit */

/*------------------------------------------------------
  Watchdog timer reset register
------------------------------------------------------*/
union byte_def wdtr_addr;
#define    wdtr    wdtr_addr.byte

/*------------------------------------------------------
  Watchdog timer start register
------------------------------------------------------*/
union byte_def wdts_addr;
#define    wdts    wdts_addr.byte

/*------------------------------------------------------
  Watchdog timer control register
------------------------------------------------------*/
union byte_def wdc_addr;
#define    wdc     wdc_addr.byte

#define    wdc7    wdc_addr.bit.b7       /* Prescaler select bit */

/*------------------------------------------------------
  Voltage detect register1
------------------------------------------------------*/
union byte_def vcr1_addr;
#define    vcr1    vcr1_addr.byte

#define    vc13    vcr1_addr.bit.b3      /* Voltage watch monitor flag */

/*------------------------------------------------------
  Voltage detect register2
------------------------------------------------------*/
union byte_def vcr2_addr;
#define    vcr2    vcr2_addr.byte

#define    vc27    vcr2_addr.bit.b7      /* Voltage watch enable bit */

/*------------------------------------------------------
  INT0 input filter select register
------------------------------------------------------*/
union byte_def int0f_addr;
#define    int0f   int0f_addr.byte

#define    int0f0  int0f_addr.bit.b0     /* INT0 input filter select bit */
#define    int0f1  int0f_addr.bit.b1     /* INT0 input filter select bit */

/*------------------------------------------------------
  Voltage detect interrupt register
------------------------------------------------------*/
union byte_def d4int_addr;
#define    d4int   d4int_addr.byte

#define    d40     d4int_addr.bit.b0     /* Voltage down detect interrupt enable bit */
#define    d41     d4int_addr.bit.b1     /* STOP mode deactivation control bit */
#define    d42     d4int_addr.bit.b2     /* Voltage change detect flag */
#define    d43     d4int_addr.bit.b3     /* WDT overflow detect flag */
#define    df0     d4int_addr.bit.b4     /* Sampling clock select bit */
#define    df1     d4int_addr.bit.b5     /* Sampling clock select bit */
#define    d46     d4int_addr.bit.b6     /* Voltage down watch mode select bit */
#define    d47     d4int_addr.bit.b7     /* Stop mode exiting condition select bit */

/*------------------------------------------------------
  Timer Y,Z mode register
------------------------------------------------------*/
union byte_def tyzmr_addr;
#define    tyzmr   tyzmr_addr.byte

#define    tymod0  tyzmr_addr.bit.b0     /* TY Operation mode select bit */
#define    r1edg   tyzmr_addr.bit.b1     /* INT2/CNTR1 polarity select bit */
#define    tywc    tyzmr_addr.bit.b2     /* TY write control bit */
#define    tys     tyzmr_addr.bit.b3     /* TY count start bit */
#define    tzmod0  tyzmr_addr.bit.b4     /* TZ Operation mode select bit */
#define    tzmod1  tyzmr_addr.bit.b5     /* TZ Operation mode select bit */
#define    tzwc    tyzmr_addr.bit.b6     /* TZ write control bit */
#define    tzs     tyzmr_addr.bit.b7     /* TZ count start bit */

/*------------------------------------------------------
  Timer Y prescaler
------------------------------------------------------*/
union byte_def prey_addr;
#define    prey    prey_addr.byte

/*------------------------------------------------------
  Timer Y secondary
------------------------------------------------------*/
union byte_def tysc_addr;
#define    tysc    tysc_addr.byte

/*------------------------------------------------------
  Timer Y primary
------------------------------------------------------*/
union byte_def typr_addr;
#define    typr    typr_addr.byte

/*------------------------------------------------------
  Timer Y,Z wave-form output control register
------------------------------------------------------*/
union byte_def pum_addr;
#define    pum     pum_addr.byte

#define    tyopl   pum_addr.bit.b4       /* TY output level latch */
#define    tzopl   pum_addr.bit.b5       /* TZ output level latch */
#define    inostg  pum_addr.bit.b6       /* INT0 one-shot trigger control bit */
#define    inoseg  pum_addr.bit.b7       /* INT0 one-shot trigger polarity select bit */

/*------------------------------------------------------
  Timer Z prescaler
------------------------------------------------------*/
union byte_def prez_addr;
#define    prez    prez_addr.byte

/*------------------------------------------------------
  Timer Z secondary
------------------------------------------------------*/
union byte_def tzsc_addr;
#define    tzsc    tzsc_addr.byte

/*------------------------------------------------------
  Timer Z primary
------------------------------------------------------*/
union byte_def tzpr_addr;
#define    tzpr    tzpr_addr.byte

/*------------------------------------------------------
  Timer Y,Z output control register
------------------------------------------------------*/
union byte_def tyzoc_addr;
#define    tyzoc   tyzoc_addr.byte

#define    tzos    tyzoc_addr.bit.b0     /* TZ one-shot start bit */
#define    tyocnt  tyzoc_addr.bit.b1     /* TY programable output select bit */
#define    tzocnt  tyzoc_addr.bit.b2     /* TZ programable output select bit */

/*------------------------------------------------------
  Timer X mode register
------------------------------------------------------*/
union byte_def txmr_addr;
#define    txmr    txmr_addr.byte

#define    txmod0  txmr_addr.bit.b0      /* TX Operation mode select bit0 */
#define    txmod1  txmr_addr.bit.b1      /* TX Operation mode select bit1 */
#define    r0edg   txmr_addr.bit.b2      /* INT1/CNTR0 polarity select bit */
#define    txs     txmr_addr.bit.b3      /* TX count start bit */
#define    txocnt  txmr_addr.bit.b4      /* P30/CNTR0 select bit */
#define    txmod2  txmr_addr.bit.b5      /* TX Operation mode select bit2 */
#define    txedg   txmr_addr.bit.b6      /* effective edge judge bit */
#define    txund   txmr_addr.bit.b7      /* TX under-flow bit */

/*------------------------------------------------------
  Timer X prescaler
------------------------------------------------------*/
union byte_def prex_addr;
#define    prex    prex_addr.byte

/*------------------------------------------------------
  Timer X
------------------------------------------------------*/
union byte_def tx_addr;
#define    tx    tx_addr.byte

/*------------------------------------------------------
  Timer count source select register
------------------------------------------------------*/
union byte_def tcss_addr;
#define    tcss    tcss_addr.byte

#define    txck0   tcss_addr.bit.b0      /* TX count source select bit */
#define    txck1   tcss_addr.bit.b1      /* TX count source select bit */
#define    tyck0   tcss_addr.bit.b2      /* TY count source select bit */
#define    tyck1   tcss_addr.bit.b3      /* TY count source select bit */
#define    tzck0   tcss_addr.bit.b4      /* TZ count source select bit */
#define    tzck1   tcss_addr.bit.b5      /* TZ count source select bit */

/*------------------------------------------------------
  External interrupt enable register
------------------------------------------------------*/
union byte_def inten_addr;
#define    inten   inten_addr.byte

#define    int0en  inten_addr.bit.b0     /* INT0 interrupt enable bit */
#define    int0pl  inten_addr.bit.b1     /* INT0 polarity select bit */

/*------------------------------------------------------
  Key input enable register
------------------------------------------------------*/
union byte_def kien_addr;
#define    kien    kien_addr.byte

#define    ki0en   kien_addr.bit.b0      /* KI0 input enable bit */
#define    ki0pl   kien_addr.bit.b1      /* KI0 polarity select bit */
#define    ki1en   kien_addr.bit.b2      /* KI1 input enable bit */
#define    ki1pl   kien_addr.bit.b3      /* KI1 polarity select bit */
#define    ki2en   kien_addr.bit.b4      /* KI2 input enable bit */
#define    ki2pl   kien_addr.bit.b5      /* KI2 polarity select bit */
#define    ki3en   kien_addr.bit.b6      /* KI3 input enable bit */
#define    ki3pl   kien_addr.bit.b7      /* KI3 polarity select bit */

/*------------------------------------------------------
  Timer C control register0
------------------------------------------------------*/
union byte_def tcc0_addr;
#define    tcc0    tcc0_addr.byte

#define    tcc00   tcc0_addr.bit.b0      /* TC count start bit */
#define    tcc01   tcc0_addr.bit.b1      /* TC count source select bit */
#define    tcc02   tcc0_addr.bit.b2      /* TC count source select bit */
#define    tcc03   tcc0_addr.bit.b3      /* INT3/capture polarity select bit */
#define    tcc04   tcc0_addr.bit.b4      /* INT3/capture polarity select bit */
#define    tcc07   tcc0_addr.bit.b7      /* INT3/capture input select bit */

/*------------------------------------------------------
  Timer C control register1
------------------------------------------------------*/
union byte_def tcc1_addr;
#define    tcc1    tcc1_addr.byte

#define    tcc10   tcc1_addr.bit.b0      /* INT3 filter select bit */
#define    tcc11   tcc1_addr.bit.b1      /* INT3 filter select bit */
#define    tcc12   tcc1_addr.bit.b2      /* TC counter reload select bit */
#define    tcc13   tcc1_addr.bit.b3      /* Compare0/capture select bit */
#define    tcc14   tcc1_addr.bit.b4      /* Compare0 output mode select bit */
#define    tcc15   tcc1_addr.bit.b5      /* Compare0 output mode select bit */
#define    tcc16   tcc1_addr.bit.b6      /* Compare1 output mode select bit */
#define    tcc17   tcc1_addr.bit.b7      /* Compare1 output mode select bit */

/*------------------------------------------------------
  UART0 bit rate generator
------------------------------------------------------*/
union byte_def u0brg_addr;
#define    u0brg   u0brg_addr.byte

/*------------------------------------------------------
  UART1 bit rate generator
------------------------------------------------------*/
union byte_def u1brg_addr;
#define    u1brg   u1brg_addr.byte

/*------------------------------------------------------
  UART transmit/receive control register2
------------------------------------------------------*/
union byte_def ucon_addr;
#define    ucon    ucon_addr.byte

#define    u0irs   ucon_addr.bit.b0      /* UART0 transmit interrupt cause select bit */
#define    u1irs   ucon_addr.bit.b1      /* UART1 transmit interrupt cause select bit */
#define    u0rrm   ucon_addr.bit.b2      /* UART0 continuous receive mode enable bit */
#define    txd1sel ucon_addr.bit.b5      /* Port P00/TxD11 select bit */
#define    rxd1en  ucon_addr.bit.b6      /* TxD10/RxD1 select bit */

/*------------------------------------------------------
  A/D control register2
------------------------------------------------------*/
union byte_def adcon2_addr;
#define    adcon2  adcon2_addr.byte

#define    smp     adcon2_addr.bit.b0    /* A/D conversion method select bit */

/*------------------------------------------------------
  A/D control register0
------------------------------------------------------*/
union byte_def adcon0_addr;
#define    adcon0  adcon0_addr.byte

#define    ch0     adcon0_addr.bit.b0    /* Analog input pin select bit */
#define    ch1     adcon0_addr.bit.b1    /* Analog input pin select bit */
#define    ch2     adcon0_addr.bit.b2    /* Analog input pin select bit */
#define    md      adcon0_addr.bit.b3    /* A/D operation mode select bit */
#define    adgsel0 adcon0_addr.bit.b4    /* A/D input group select bit */
#define    adst    adcon0_addr.bit.b6    /* A/D conversion start flag */
#define    cks0    adcon0_addr.bit.b7    /* Frequency select bit0 */

/*------------------------------------------------------
  A/D control register1
------------------------------------------------------*/
union byte_def adcon1_addr;
#define    adcon1  adcon1_addr.byte

#define    bits    adcon1_addr.bit.b3    /* 8/10-bit mode select bit */
#define    cks1    adcon1_addr.bit.b4    /* Frequency select bit1 */
#define    vcut    adcon1_addr.bit.b5    /* Vref connect bit */

/*------------------------------------------------------
  Port P0 register
------------------------------------------------------*/
union byte_def p0_addr;
#define    p0      p0_addr.byte

#define    p0_0    p0_addr.bit.b0        /* P0 register bit0 */
#define    p0_1    p0_addr.bit.b1        /* P0 register bit1 */
#define    p0_2    p0_addr.bit.b2        /* P0 register bit2 */
#define    p0_3    p0_addr.bit.b3        /* P0 register bit3 */
#define    p0_4    p0_addr.bit.b4        /* P0 register bit4 */
#define    p0_5    p0_addr.bit.b5        /* P0 register bit5 */
#define    p0_6    p0_addr.bit.b6        /* P0 register bit6 */
#define    p0_7    p0_addr.bit.b7        /* P0 register bit7 */

/*------------------------------------------------------
  Port P1 register
------------------------------------------------------*/
union byte_def p1_addr;
#define    p1      p1_addr.byte

#define    p1_0    p1_addr.bit.b0        /* P1 register bit0 */
#define    p1_1    p1_addr.bit.b1        /* P1 register bit1 */
#define    p1_2    p1_addr.bit.b2        /* P1 register bit2 */
#define    p1_3    p1_addr.bit.b3        /* P1 register bit3 */
#define    p1_4    p1_addr.bit.b4        /* P1 register bit4 */
#define    p1_5    p1_addr.bit.b5        /* P1 register bit5 */
#define    p1_6    p1_addr.bit.b6        /* P1 register bit6 */
#define    p1_7    p1_addr.bit.b7        /* P1 register bit7 */

/*------------------------------------------------------
  Port P0 direction register
------------------------------------------------------*/
union byte_def pd0_addr;
#define    pd0     pd0_addr.byte

#define    pd0_0   pd0_addr.bit.b0       /* P0 direction register bit0 */
#define    pd0_1   pd0_addr.bit.b1       /* P0 direction register bit1 */
#define    pd0_2   pd0_addr.bit.b2       /* P0 direction register bit2 */
#define    pd0_3   pd0_addr.bit.b3       /* P0 direction register bit3 */
#define    pd0_4   pd0_addr.bit.b4       /* P0 direction register bit4 */
#define    pd0_5   pd0_addr.bit.b5       /* P0 direction register bit5 */
#define    pd0_6   pd0_addr.bit.b6       /* P0 direction register bit6 */
#define    pd0_7   pd0_addr.bit.b7       /* P0 direction register bit7 */

/*------------------------------------------------------
  Port P1 direction register
------------------------------------------------------*/
union byte_def pd1_addr;
#define    pd1     pd1_addr.byte

#define    pd1_0   pd1_addr.bit.b0       /* P1 direction register bit0 */
#define    pd1_1   pd1_addr.bit.b1       /* P1 direction register bit1 */
#define    pd1_2   pd1_addr.bit.b2       /* P1 direction register bit2 */
#define    pd1_3   pd1_addr.bit.b3       /* P1 direction register bit3 */
#define    pd1_4   pd1_addr.bit.b4       /* P1 direction register bit4 */
#define    pd1_5   pd1_addr.bit.b5       /* P1 direction register bit5 */
#define    pd1_6   pd1_addr.bit.b6       /* P1 direction register bit6 */
#define    pd1_7   pd1_addr.bit.b7       /* P1 direction register bit7 */

/*------------------------------------------------------
  Port P3 register
------------------------------------------------------*/
union byte_def p3_addr;
#define    p3      p3_addr.byte

#define    p3_0    p3_addr.bit.b0        /* P3 register bit0 */
#define    p3_1    p3_addr.bit.b1        /* P3 register bit1 */
#define    p3_2    p3_addr.bit.b2        /* P3 register bit2 */
#define    p3_3    p3_addr.bit.b3        /* P3 register bit3 */
#define    p3_7    p3_addr.bit.b7        /* P3 register bit7 */

/*------------------------------------------------------
  Port P3 direction register
------------------------------------------------------*/
union byte_def pd3_addr;
#define    pd3     pd3_addr.byte

#define    pd3_0   pd3_addr.bit.b0       /* P3 direction register bit0 */
#define    pd3_1   pd3_addr.bit.b1       /* P3 direction register bit1 */
#define    pd3_2   pd3_addr.bit.b2       /* P3 direction register bit2 */
#define    pd3_3   pd3_addr.bit.b3       /* P3 direction register bit3 */
#define    pd3_7   pd3_addr.bit.b7       /* P3 direction register bit7 */

/*------------------------------------------------------
  Port P4 register
------------------------------------------------------*/
union byte_def p4_addr;
#define    p4      p4_addr.byte

#define    p4_5    p4_addr.bit.b5        /* P4 register bit5 */
#define    p4_6    p4_addr.bit.b6        /* P4 register bit6 */
#define    p4_7    p4_addr.bit.b7        /* P4 register bit7 */

/*------------------------------------------------------
  Port P4 direction register
------------------------------------------------------*/
union byte_def pd4_addr;
#define    pd4     pd4_addr.byte

#define    pd4_5   pd4_addr.bit.b5       /* P4 direction register bit5 */

/*------------------------------------------------------
  Pull-up control register0
------------------------------------------------------*/
union byte_def pur0_addr;
#define    pur0    pur0_addr.byte

#define    pu00    pur0_addr.bit.b0      /* P00 to P03 pull-up */
#define    pu01    pur0_addr.bit.b1      /* P04 to P07 pull-up */
#define    pu02    pur0_addr.bit.b2      /* P10 to P13 pull-up */
#define    pu03    pur0_addr.bit.b3      /* P14 to P17 pull-up */
#define    pu06    pur0_addr.bit.b6      /* P30 to P33 pull-up */
#define    pu07    pur0_addr.bit.b7      /* P37 pull-up */

/*------------------------------------------------------
  Pull-up control register1
------------------------------------------------------*/
union byte_def pur1_addr;
#define    pur1    pur1_addr.byte

#define    pu11    pur1_addr.bit.b1      /* P45 pull-up */

/*------------------------------------------------------
  Port P1 drive capacity control register
------------------------------------------------------*/
union byte_def drr_addr;
#define    drr      drr_addr.byte

#define    drr0    drr_addr.bit.b0       /* Port P1_0 capacity control select bit */
#define    drr1    drr_addr.bit.b1       /* Port P1_1 capacity control select bit */
#define    drr2    drr_addr.bit.b2       /* Port P1_2 capacity control select bit */
#define    drr3    drr_addr.bit.b3       /* Port P1_3 capacity control select bit */
#define    drr4    drr_addr.bit.b4       /* Port P1_4 capacity control select bit */
#define    drr5    drr_addr.bit.b5       /* Port P1_5 capacity control select bit */
#define    drr6    drr_addr.bit.b6       /* Port P1_6 capacity control select bit */
#define    drr7    drr_addr.bit.b7       /* Port P1_7 capacity control select bit */

/*------------------------------------------------------
  Timer C output control register
------------------------------------------------------*/
union byte_def tcout_addr;
#define    tcout   tcout_addr.byte

#define    tcout0  tcout_addr.bit.b0     /* CMP output enable bit0 */
#define    tcout1  tcout_addr.bit.b1     /* CMP output enable bit1 */
#define    tcout2  tcout_addr.bit.b2     /* CMP output enable bit2 */
#define    tcout3  tcout_addr.bit.b3     /* CMP output enable bit3 */
#define    tcout4  tcout_addr.bit.b4     /* CMP output enable bit4 */
#define    tcout5  tcout_addr.bit.b5     /* CMP output enable bit5 */
#define    tcout6  tcout_addr.bit.b6     /* CMP output reverse bit0 */
#define    tcout7  tcout_addr.bit.b7     /* CMP output reverse bit1 */

/*------------------------------------------------------
  Interrupt control register
------------------------------------------------------*/
union{
  struct{
    char  ilvl0:1;      /* Interrupt priority level select bit */
    char  ilvl1:1;      /* Interrupt priority level select bit */
    char  ilvl2:1;      /* Interrupt priority level select bit */
    char  ir:1;         /* Interrupt request bit */
    char  pol:1;        /* Polarity select bit */
    char  b5:1;
    char  b6:1;
    char  b7:1;
  }bit;
  char  byte;
} kupic_addr,adic_addr, cmp1ic_addr, s0tic_addr, s0ric_addr, s1tic_addr, s1ric_addr, int2ic_addr,
  txic_addr, tyic_addr, tzic_addr, int1ic_addr, int3ic_addr, tcic_addr, cmp0ic_addr, int0ic_addr;

/*------------------------------------------------------
  Key input interrupt control register
------------------------------------------------------*/
#define     kupic        kupic_addr.byte

#define     ilvl0_kupic  kupic_addr.bit.ilvl0
#define     ilvl1_kupic  kupic_addr.bit.ilvl1
#define     ilvl2_kupic  kupic_addr.bit.ilvl2
#define     ir_kupic     kupic_addr.bit.ir

/*------------------------------------------------------
  A/D interrupt control register
------------------------------------------------------*/
#define     adic        adic_addr.byte

#define     ilvl0_adic  adic_addr.bit.ilvl0
#define     ilvl1_adic  adic_addr.bit.ilvl1
#define     ilvl2_adic  adic_addr.bit.ilvl2
#define     ir_adic     adic_addr.bit.ir

/*------------------------------------------------------
  Compare 1 interrupt control register
------------------------------------------------------*/
#define     cmp1ic       cmp1ic_addr.byte

#define     ilvl0_cmp1ic cmp1ic_addr.bit.ilvl0
#define     ilvl1_cmp1ic cmp1ic_addr.bit.ilvl1
#define     ilvl2_cmp1ic cmp1ic_addr.bit.ilvl2
#define     ir_cmp1ic    cmp1ic_addr.bit.ir

/*------------------------------------------------------
  UART0 transmit interrupt control register
------------------------------------------------------*/
#define     s0tic        s0tic_addr.byte

#define     ilvl0_s0tic  s0tic_addr.bit.ilvl0
#define     ilvl1_s0tic  s0tic_addr.bit.ilvl1
#define     ilvl2_s0tic  s0tic_addr.bit.ilvl2
#define     ir_s0tic     s0tic_addr.bit.ir

/*------------------------------------------------------
  UART0 receive interrupt control register
------------------------------------------------------*/
#define     s0ric        s0ric_addr.byte

#define     ilvl0_s0ric  s0ric_addr.bit.ilvl0
#define     ilvl1_s0ric  s0ric_addr.bit.ilvl1
#define     ilvl2_s0ric  s0ric_addr.bit.ilvl2
#define     ir_s0ric     s0ric_addr.bit.ir

/*------------------------------------------------------
  UART1 transmit interrupt control register
------------------------------------------------------*/
#define     s1tic        s1tic_addr.byte

#define     ilvl0_s1tic  s1tic_addr.bit.ilvl0
#define     ilvl1_s1tic  s1tic_addr.bit.ilvl1
#define     ilvl2_s1tic  s1tic_addr.bit.ilvl2
#define     ir_s1tic     s1tic_addr.bit.ir

/*------------------------------------------------------
  UART1 receive interrupt control register
------------------------------------------------------*/
#define     s1ric        s1ric_addr.byte

#define     ilvl0_s1ric  s1ric_addr.bit.ilvl0
#define     ilvl1_s1ric  s1ric_addr.bit.ilvl1
#define     ilvl2_s1ric  s1ric_addr.bit.ilvl2
#define     ir_s1ric     s1ric_addr.bit.ir

/*------------------------------------------------------
  INT2 interrupt control register
------------------------------------------------------*/
#define     int2ic        int2ic_addr.byte

#define     ilvl0_int2ic  int2ic_addr.bit.ilvl0
#define     ilvl1_int2ic  int2ic_addr.bit.ilvl1
#define     ilvl2_int2ic  int2ic_addr.bit.ilvl2
#define     ir_int2ic     int2ic_addr.bit.ir

/*------------------------------------------------------
  Timer X interrupt control register
------------------------------------------------------*/
#define     txic        txic_addr.byte

#define     ilvl0_txic  txic_addr.bit.ilvl0
#define     ilvl1_txic  txic_addr.bit.ilvl1
#define     ilvl2_txic  txic_addr.bit.ilvl2
#define     ir_txic     txic_addr.bit.ir

/*------------------------------------------------------
  Timer Y interrupt control register
------------------------------------------------------*/
#define     tyic        tyic_addr.byte

#define     ilvl0_tyic  tyic_addr.bit.ilvl0
#define     ilvl1_tyic  tyic_addr.bit.ilvl1
#define     ilvl2_tyic  tyic_addr.bit.ilvl2
#define     ir_tyic     tyic_addr.bit.ir
/*------------------------------------------------------
  Timer Z interrupt control register
------------------------------------------------------*/
#define     tzic        tzic_addr.byte

#define     ilvl0_tzic  tzic_addr.bit.ilvl0
#define     ilvl1_tzic  tzic_addr.bit.ilvl1
#define     ilvl2_tzic  tzic_addr.bit.ilvl2
#define     ir_tzic     tzic_addr.bit.ir

/*------------------------------------------------------
  INT1 interrupt control register
------------------------------------------------------*/
#define     int1ic        int1ic_addr.byte

#define     ilvl0_int1ic  int1ic_addr.bit.ilvl0
#define     ilvl1_int1ic  int1ic_addr.bit.ilvl1
#define     ilvl2_int1ic  int1ic_addr.bit.ilvl2
#define     ir_int1ic     int1ic_addr.bit.ir
/*------------------------------------------------------
  INT3 interrupt control register
------------------------------------------------------*/
#define     int3ic        int3ic_addr.byte

#define     ilvl0_int3ic  int3ic_addr.bit.ilvl0
#define     ilvl1_int3ic  int3ic_addr.bit.ilvl1
#define     ilvl2_int3ic  int3ic_addr.bit.ilvl2
#define     ir_int3ic     int3ic_addr.bit.ir
/*------------------------------------------------------
  Timer C interrupt control register
------------------------------------------------------*/
#define     tcic        tcic_addr.byte

#define     ilvl0_tcic  tcic_addr.bit.ilvl0
#define     ilvl1_tcic  tcic_addr.bit.ilvl1
#define     ilvl2_tcic  tcic_addr.bit.ilvl2
#define     ir_tcic     tcic_addr.bit.ir

/*------------------------------------------------------
  Compare 0 interrupt control register
------------------------------------------------------*/
#define     cmp0ic      cmp0ic_addr.byte

#define     ilvl0_cmp0ic  cmp0ic_addr.bit.ilvl0
#define     ilvl1_cmp0ic  cmp0ic_addr.bit.ilvl1
#define     ilvl2_cmp0ic  cmp0ic_addr.bit.ilvl2
#define     ir_cmp0ic     cmp0ic_addr.bit.ir

/*------------------------------------------------------
  INT0 interrupt control register
------------------------------------------------------*/
#define     int0ic        int0ic_addr.byte

#define     ilvl0_int0ic  int0ic_addr.bit.ilvl0
#define     ilvl1_int0ic  int0ic_addr.bit.ilvl1
#define     ilvl2_int0ic  int0ic_addr.bit.ilvl2
#define     ir_int0ic     int0ic_addr.bit.ir
#define     pol_int0ic    int0ic_addr.bit.pol

/*------------------------------------------------------
  UARTi transmit/receive mode register
------------------------------------------------------*/
union{
  struct{
    char  smd0  :1;         /* Serial I/O mode select bit */
    char  smd1  :1;         /* Serial I/O mode select bit */
    char  smd2  :1;         /* Serial I/O mode select bit */
    char  ckdir :1;         /* Internal/external clock select bit */
    char  stps  :1;         /* Stop bit length select bit */
    char  pry   :1;         /* Odd/even parity select bit */
    char  prye  :1;         /* Parity enable bit */
    char  b7    :1;         
  }bit;
  char  byte;
}u0mr_addr,u1mr_addr;

/*------------------------------------------------------
  UART0 transmit/receive mode register
------------------------------------------------------*/
#define    u0mr         u0mr_addr.byte

#define    smd0_u0mr    u0mr_addr.bit.smd0    /* Serial I/O mode select bit */
#define    smd1_u0mr    u0mr_addr.bit.smd1    /* Serial I/O mode select bit */
#define    smd2_u0mr    u0mr_addr.bit.smd2    /* Serial I/O mode select bit */
#define    ckdir_u0mr   u0mr_addr.bit.ckdir   /* Internal/external clock select bit */
#define    stps_u0mr    u0mr_addr.bit.stps    /* Stop bit length select bit */
#define    pry_u0mr     u0mr_addr.bit.pry     /* Odd/even parity select bit */
#define    prye_u0mr    u0mr_addr.bit.prye    /* Parity enable bit */

/*------------------------------------------------------
  UART1 transmit/receive mode register
------------------------------------------------------*/
#define    u1mr         u1mr_addr.byte

#define    smd0_u1mr    u1mr_addr.bit.smd0    /* Serial I/O mode select bit */
#define    smd1_u1mr    u1mr_addr.bit.smd1    /* Serial I/O mode select bit */
#define    smd2_u1mr    u1mr_addr.bit.smd2    /* Serial I/O mode select bit */
#define    ckdir_u1mr   u1mr_addr.bit.ckdir   /* Internal/external clock select bit */
#define    stps_u1mr    u1mr_addr.bit.stps    /* Stop bit length select bit */
#define    pry_u1mr     u1mr_addr.bit.pry     /* Odd/even parity select bit */
#define    prye_u1mr    u1mr_addr.bit.prye    /* Parity enable bit */

/*------------------------------------------------------
  UARTi transmit/receive control register0
------------------------------------------------------*/
union{
  struct{
    char  clk0  :1;         /* BRG count source select bit */
    char  clk1  :1;         /* BRG count source select bit */
    char  b2    :1;         /*  */
    char  txept :1;         /* Transmit register empty flag */
    char  b4    :1;         /*  */
    char  nch   :1;         /* Data output select bit */
    char  ckpol :1;         /* CLK polarity select bit */
    char  uform :1;         /* Transfer format select bit */
  }bit;
  char  byte;
}u0c0_addr,u1c0_addr;

/*------------------------------------------------------
  UART0 transmit/receive control register0
------------------------------------------------------*/
#define    u0c0         u0c0_addr.byte

#define    clk0_u0c0    u0c0_addr.bit.clk0    /* BRG count source select bit */
#define    clk1_u0c0    u0c0_addr.bit.clk1    /* BRG count source select bit */
#define    txept_u0c0   u0c0_addr.bit.txept   /* Transmit register empty flag */
#define    nch_u0c0     u0c0_addr.bit.nch     /* Data output select bit */
#define    ckpol_u0c0   u0c0_addr.bit.ckpol   /* CLK polarity select bit */
#define    uform_u0c0   u0c0_addr.bit.uform   /* Transfer format select bit */

/*------------------------------------------------------
  UART1 transmit/receive control register0
------------------------------------------------------*/
#define    u1c0         u1c0_addr.byte

#define    clk0_u1c0    u1c0_addr.bit.clk0    /* BRG count source select bit */
#define    clk1_u1c0    u1c0_addr.bit.clk1    /* BRG count source select bit */
#define    txept_u1c0   u1c0_addr.bit.txept   /* Transmit register empty flag */
#define    nch_u1c0     u1c0_addr.bit.nch     /* Data output select bit */
#define    ckpol_u1c0   u1c0_addr.bit.ckpol   /* CLK polarity select bit */
#define    uform_u1c0   u1c0_addr.bit.uform   /* Transfer format select bit */

/*------------------------------------------------------
  UARTi transmit/receive control register1
------------------------------------------------------*/
union{
  struct{
    char  te:1;        /* Transmit enable bit */
    char  ti:1;        /* Transmit buffer empty flag */
    char  re:1;        /* Receive enable bit */
    char  ri:1;        /* Receive complete flag */
    char  b4:1;
    char  b5:1;
    char  b6:1;
    char  b7:1;
  }bit;
  char  byte;
}u0c1_addr,u1c1_addr;

/*------------------------------------------------------
  UART0 transmit/receive control register1
------------------------------------------------------*/
#define    u0c1       u0c1_addr.byte

#define    te_u0c1    u0c1_addr.bit.te    /* Transmit enable bit */
#define    ti_u0c1    u0c1_addr.bit.ti    /* Transmit buffer empty flag */
#define    re_u0c1    u0c1_addr.bit.re    /* Receive enable bit */
#define    ri_u0c1    u0c1_addr.bit.ri    /* Receive complete flag */

/*------------------------------------------------------
  UART1 transmit/receive control register1
------------------------------------------------------*/
#define    u1c1       u1c1_addr.byte

#define    te_u1c1    u1c1_addr.bit.te    /* Transmit enable bit */
#define    ti_u1c1    u1c1_addr.bit.ti    /* Transmit buffer empty flag */
#define    re_u1c1    u1c1_addr.bit.re    /* Receive enable bit */
#define    ri_u1c1    u1c1_addr.bit.ri    /* Receive complete flag */

/*------------------------------------------------------
  UARTi receive buffer register
------------------------------------------------------*/
union{
  struct{
    char  b0:1;
    char  b1:1;
    char  b2:1;
    char  b3:1;
    char  b4:1;
    char  b5:1;
    char  b6:1;
    char  b7:1;
    char  b8:1;
    char  b9:1;
    char  b10:1;
    char  b11:1;
    char  oer:1;        /* Overrun error flag */
    char  fer:1;        /* Framing error flag */
    char  per:1;        /* Parity error flag */
    char  sum:1;        /* Error sum flag */
  }bit;
   struct{
    char  low;          /* Low  8 bit */
    char  high;         /* High 8 bit */
  }byte;
  unsigned short  word;
}u0rb_addr,u1rb_addr;

/*------------------------------------------------------
  UART0 receive buffer register
------------------------------------------------------*/
#define    u0rb      u0rb_addr.word
#define    u0rbl     u0rb_addr.byte.low
#define    u0rbh     u0rb_addr.byte.high

#define    oer_u0rb  u0rb_addr.bit.oer    /* Overrun error flag */
#define    fer_u0rb  u0rb_addr.bit.fer    /* Framing error flag */
#define    per_u0rb  u0rb_addr.bit.per    /* Parity error flag */
#define    sum_u0rb  u0rb_addr.bit.sum    /* Error sum flag */

/*------------------------------------------------------
  UART1 receive buffer register
------------------------------------------------------*/
#define    u1rb      u1rb_addr.word
#define    u1rbl     u1rb_addr.byte.low
#define    u1rbh     u1rb_addr.byte.high

#define    oer_u1rb  u1rb_addr.bit.oer    /* Overrun error flag */
#define    fer_u1rb  u1rb_addr.bit.fer    /* Framing error flag */
#define    per_u1rb  u1rb_addr.bit.per    /* Parity error flag */
#define    sum_u1rb  u1rb_addr.bit.sum    /* Error sum flag */

/********************************************************
*  declare SFR union                                    *
********************************************************/

union{
  struct{
    char  b0:1;
    char  b1:1;
    char  b2:1;
    char  b3:1;
    char  b4:1;
    char  b5:1;
    char  b6:1;
    char  b7:1;
    char  b8:1;
    char  b9:1;
    char  b10:1;
    char  b11:1;
    char  b12:1;
    char  b13:1;
    char  b14:1;
    char  b15:1;
    char  b16:1;
    char  b17:1;
    char  b18:1;
    char  b19:1;
   }bit;
   struct{
    char  low;        /* low  8 bit */
    char  mid;        /* mid  8 bit */
    char  high;       /* high 8 bit */
    char  nc;         /* non use */
  }byte;

  unsigned long  dword;
}rmad0_addr,rmad1_addr;

#define    rmad0      rmad0_addr.dword      /* Address match interrupt register0 */
#define    rmad0l     rmad0_addr.byte.low   /* Address match interrupt register0 Low */
#define    rmad0m     rmad0_addr.byte.mid   /* Address match interrupt register0 Middle */
#define    rmad0h     rmad0_addr.byte.high  /* Address match interrupt register0 High */
#define    rmad1      rmad1_addr.dword      /* Address match interrupt register1 */
#define    rmad1l     rmad1_addr.byte.low   /* Address match interrupt register1 Low */
#define    rmad1m     rmad1_addr.byte.mid   /* Address match interrupt register1 Middle */
#define    rmad1h     rmad1_addr.byte.high  /* Address match interrupt register1 High */


union{
  struct{
    char  b0:1;
    char  b1:1;
    char  b2:1;
    char  b3:1;
    char  b4:1;
    char  b5:1;
    char  b6:1;
    char  b7:1;
    char  b8:1;
    char  b9:1;
    char  b10:1;
    char  b11:1;
    char  b12:1;
    char  b13:1;
    char  b14:1;
    char  b15:1;
   }bit;
  struct{
    char  low;         /* low  8 bit */
    char  high;        /* high 8 bit */
  }byte;
  unsigned int  word;
} tc_addr, tm0_addr, tm1_addr, u0tb_addr, u1tb_addr, ad_addr;

#define    tc     tc_addr.word            /* Timer C */
#define    tcl    tc_addr.byte.low        /* Timer C Low */
#define    tch    tc_addr.byte.high       /* Timer C High */
#define    tm0    tm0_addr.word           /* Capture, compare0 register */
#define    tm0l   tm0_addr.byte.low       /* Capture, compare0 register Low */
#define    tm0h   tm0_addr.byte.high      /* Capture, compare0 register High */
#define    tm1    tm1_addr.word           /* Compare1 register */
#define    tm1l   tm1_addr.byte.low       /* Compare1 register Low */
#define    tm1h   tm1_addr.byte.high      /* Compare1 register High */
#define    u0tb   u0tb_addr.word          /* UART0 transmit buffer register */
#define    u0tbl  u0tb_addr.byte.low      /* UART0 transmit buffer register Low */
#define    u0tbh  u0tb_addr.byte.high     /* UART0 transmit buffer register High */
#define    u1tb   u1tb_addr.word          /* UART1 transmit buffer register */
#define    u1tbl  u1tb_addr.byte.low      /* UART1 transmit buffer register Low */
#define    u1tbh  u1tb_addr.byte.high     /* UART1 transmit buffer register High */
#define    ad     ad_addr.word            /* A/D register  */
#define    adl    ad_addr.byte.low        /* A/D register Low */
#define    adh    ad_addr.byte.high       /* A/D register High */

#endif