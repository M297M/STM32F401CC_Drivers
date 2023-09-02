/*
 * Seven_Segment.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mayar
 */



#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "../../Common/STD_TYPE.h"
#include "../../Common/Util.h"
#include "../../common/BIT_MATH.h"

#include "../../Mcal/Gpio.h"
#include "../Mcal/Rcc.h"





typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;
typedef struct {
	u32 pins[7];
    u32 port;
    segment_type_t type;
}sevent_seg;



Std_ReturnType seven_seg_init(sevent_seg * sevent_segment );
Std_ReturnType seven_seg_write(sevent_seg * sevent_segment,u32 number);
Std_ReturnType seven_seg_stop(sevent_seg * sevent_segment);



#endif /* SEVEN_SEGMENT_H_ */
