/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAL
 * SWC	  : TIMER
 * Version: 1.0
 * Created: JULY/2/2024
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/*OPTIONS FOR Copy_u8WGMode(TIMER0/TIMER2):*/
#define TIMER_u8NORMAL_MODE								0
#define TIMER_u8PWM_PHASE_CORRECET						1
#define TIMER_u8CTC_MODE								2
#define TIMER_u8FAST_PWM_MODE							3
/*OPTIONS FOR Copy_u8WGMode(TIMER1):*/
#define TIMER1_NORMAL									0
#define TIMER1_PWM_PHASE_CORRECET_8BIT					1
#define TIMER1_PWM_PHASE_CORRECET_9BIT					2
#define TIMER1_PWM_PHASE_CORRECET_10BIT					3
#define TIMER1_CTC_TOP_OCR1A							4
#define TIMER1_FAST_PWM_8BIT							5
#define TIMER1_FAST_PWM_9BIT							6
#define TIMER1_FAST_PWM_10BIT							7
#define TIMER1_PWM_PHASE_FREQ_CORRECT_TOP_ICR1			8
#define TIMER1_PWM_PHASE_FREQ_CORRECT_TOP_OCR1A			9
#define TIMER1_PWM_PHASE_CORRECT_TOP_ICR1				10
#define TIMER1_PWM_PHASE_CORRECT_TOP_OCR1A				11
#define TIMER1_CTC_TOP_ICR1								12
#define TIMER1_FAST_PWM_TOP_ICR1						14
#define TIMER1_FAST_PWM_TOP_OCR1A						15

/*ARGUMENTS OF INTERRUPT STATE FOR TIMERS*/
#define TIMER_INTERRUPT_ENABLED							0
#define TIMER_INTERRUPT_DISABLED						1

/*ARGUMENTS OF PRESCALER*/
#define	NO_CLOCK_SOURCE									0
#define	NO_PRESCALER									1
#define	DIVIDED_BY_8									2
#define	DIVIDED_BY_64									3
#define	DIVIDED_BY_256									4
#define	DIVIDED_BY_1024									5
#define	EX_CLOCK_SOURCE_FE								6
#define	EX_CLOCK_SOURCE_RE								7

/*OPTIONS FOR Copy_u8OutputMode(CTC MODE):*/
#define TIMER_OPM_NORMAL								0
#define TIMER_OPM_TGL_ON_COMP							1
#define TIMER_OPM_CLR_ON_COMP							2
#define TIMER_OPM_SET_ON_COMP							3
/*OPTIONS FOR Copy_u8OutputMode(FAST PWM MODE):*/
#define TIMER_OPM_NORMAL								0
#define TIMER_OPM_CLR_ON_COMP							2
#define TIMER_OPM_SET_ON_COMP							3
/*OPTIONS FOR Copy_u8OutputMode(PWM PHASE CORRECT):*/
#define TIMER_OPM_NORMAL								0
#define TIMER_OPM_CLR_ON_COMP_UP						2
#define TIMER_OPM_SET_ON_COMP_UP						3

/*ARGUMENTS OF CAPTURE TREGGER*/
#define	TIMER_CAPTURE_FE								0
#define	TIMER_CAPTURE_RE								1

/*OPTIONS FOR Copy_u8TimerID(TIMER CALLBACK FUNC):*/
#define TIMER0_u8TIMER									0
#define TIMER2_u8TIMER									1
#define TIMER1_u8TIMER									2
/*OPTIONS FOR Copy_u8TimerID(COMPARE CALLBACK FUNC):*/
#define TIMER0_u8COMPARE								0
#define TIMER2_u8COMPARE								1
#define TIMER1A_u8COMPARE								2
#define TIMER1B_u8COMPARE								3

/*INTIAIISATION FUNCTION TO TIMER0 (PRE-BUILD CONFIGURATION) */
void TIMER0_voidInit(void);
void TIMER2_voidInit(void);
void TIMER1_voidInit(void);

/*INITIALISATION FUNCTION TO TIMER0*/
u8 TIMER_u8SetTimerMode(u8 Copy_u8TimerID, u8 Copy_u8WGMode);

/*FUNCTION TO SET COMPARE MATCH VALUE TO TIMER0 COMPARE MATCH REGISTER*/
u8 TIMER_u8SetCompMatchValue(u8 Copy_u8TimerID, u8 Copy_u8OutputMode, u16 Copy_u8CompValue);

/*FUCNTIONS TO START TIMER COUNTING*/
u8 TIMER_u8Start(u8 Copy_u8TimerID, u8 Copy_u8ClockSource, u16 Copy_u8InitialValue);
	
/*FUNCTION TO SET TREGGER TO CAPTURE REGISTER IN CAPTURE MODE*/
void TIMER1_voidSetCaptureTrigger(u8 Copy_u8Trigger);

/*FUNCTION TO SET VALUE TO CAPTURE REGISTRE(ICR1) IN TIMER1*/
void TIMER1_voidSetCaptureValue(u16 Copy_u16Value);

/*SET NOTIFICTION FUNCTOIN TO TIMER INTERRUPT SERVES ROUTIN*/
u8 TIMER_u8SetTimerCallBack(u8 Copy_u8TimerID, void (*Copy_PvoidCallBackFunc)(void));
u8 TIMER_u8SetCompareCallBack(u8 Copy_u8TimerID, void (*Copy_PvoidCallBackFunc)(void));
u8 TIMER_u8SetCaptureCallBack(void (*Copy_PvoidCallBackFunc)(void));

#endif