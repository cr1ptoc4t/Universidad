/*
#include <s3c44b0x.h>
#include <s3cev40.h>
#include <rtc.h>

extern void isr_TICK_dummy( void );

void rtc_init( void )
{
    TICNT   = ...;
    RTCALM  = ...;    
    RTCRST  = ...; 
        
    RTCCON  = ...;
    
    BCDYEAR = ...;
    BCDMON  = ...;
    BCDDAY  = ...;
    BCDDATE = ...;
    BCDHOUR = ...;
    BCDMIN  = ...;
    BCDSEC  = ...;

    ALMYEAR = ...;
    ALMMON  = ...;
    ALMDAY  = ...;
    ALMHOUR = ...;
    ALMMIN  = ...;
    ALMSEC  = ...;

    RTCCON &= ...;
}

void rtc_puttime( rtc_time_t *rtc_time )
{
    RTCCON |= ...;
    
    BCDYEAR = ...;
    BCDMON  = ...;
    BCDDAY  = ...;
    BCDDATE = ...;
    BCDHOUR = ...;
    BCDMIN  = ...;
    BCDSEC  = ...;
        
    RTCCON &= ...;
}

void rtc_gettime( rtc_time_t *rtc_time )
{
    RTCCON |= ...;
    
    rtc_time->year = ...;
    rtc_time->mon  = ...;
    rtc_time->mday = ...;
    rtc_time->wday = ...;
    rtc_time->hour = ...;
    rtc_time->min  = ...;
    rtc_time->sec  = ...;
    if( ! rtc_time->sec ){
        rtc_time->year = ...;
        rtc_time->mon  = ...;
        rtc_time->mday = ...;
        rtc_time->wday = ...;
        rtc_time->hour = ...;
        rtc_time->min  = ...;
        rtc_time->sec  = ...;
    };

    RTCCON &= ...;
}


void rtc_open( void (*isr)(void), uint8 tick_count )
{
    pISR_TICK = ...;
    I_ISPC    = ...;
    INTMSK   &= ...;
    TICNT     = ...;
}

void rtc_close( void )
{
    TICNT     = ...;  
    INTMSK   |= ...;    
    pISR_TICK = ...;
}
*/